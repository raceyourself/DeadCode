package com.raceyourself.platform.gpstracker;

import android.content.Context;
import android.content.SharedPreferences.Editor;
import android.net.http.AndroidHttpClient;
import android.util.Log;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.annotation.JsonInclude.Include;
import com.fasterxml.jackson.annotation.JsonTypeInfo;
import com.fasterxml.jackson.annotation.JsonTypeName;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.raceyourself.platform.models.AccessToken;
import com.raceyourself.platform.models.Accumulator;
import com.raceyourself.platform.models.Action;
import com.raceyourself.platform.models.AutoMatches;
import com.raceyourself.platform.models.Challenge;
import com.raceyourself.platform.models.CrashReport;
import com.raceyourself.platform.models.Device;
import com.raceyourself.platform.models.EntityCollection;
import com.raceyourself.platform.models.EntityCollection.CollectionEntity;
import com.raceyourself.platform.models.Event;
import com.raceyourself.platform.models.Friendship;
import com.raceyourself.platform.models.Invite;
import com.raceyourself.platform.models.MatchedTrack;
import com.raceyourself.platform.models.Mission;
import com.raceyourself.platform.models.MissionClaim;
import com.raceyourself.platform.models.Notification;
import com.raceyourself.platform.models.Orientation;
import com.raceyourself.platform.models.Position;
import com.raceyourself.platform.models.Preference;
import com.raceyourself.platform.models.Track;
import com.raceyourself.platform.models.Transaction;
import com.raceyourself.platform.models.User;
import com.raceyourself.platform.utils.MessagingInterface;
import com.raceyourself.platform.utils.Utils;
import com.roscopeco.ormdroid.Entity;
import com.roscopeco.ormdroid.ORMDroidApplication;

import org.apache.commons.io.IOUtils;
import org.apache.http.Header;
import org.apache.http.HeaderElement;
import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.StatusLine;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.message.BasicHeader;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;
import org.apache.http.protocol.HTTP;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.SocketTimeoutException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Random;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import lombok.Getter;

import static com.roscopeco.ormdroid.Query.and;
import static com.roscopeco.ormdroid.Query.eql;
import static com.roscopeco.ormdroid.Query.gt;
import static com.roscopeco.ormdroid.Query.leq;

public final class SyncHelper  {
    private static final int SYNC_INTERVAL = 30000;
    public static final String SUCCESS = "success";
    public static final String FAILURE = "failure";
    public static final String UNAUTHORIZED = "unauthorized";
    public static final String MESSAGING_TARGET_PLATFORM = "Platform";
    public static final String MESSAGING_METHOD_ON_SYNCHRONIZATION = "OnSynchronization";
    public static final String MESSAGING_MESSAGE_SYNC_FAILURE = "failure";
    public static final String MESSAGING_MESSAGE_SYNC_SUCCESS_PARTIAL = "partial";
    public static final String MESSAGING_MESSAGE_SYNC_SUCCESS_FULL = "full";

    private static SyncHelper singleton = null;

    final Lock lock = new ReentrantLock();
    final Condition interSyncPause  = lock.newCondition();

    private volatile boolean syncRequested;
    private volatile long syncStallRequestedUntil = 0l;
    private boolean initialized;

    private final Object syncWaitLock = new Object();

    private SyncThread syncThread = new SyncThread();

    private static ConcurrentMap<String, Lock> cacheLocks = new ConcurrentHashMap<String, Lock>();
    private static Semaphore concurrencyLimit = new Semaphore(5);

    /// Testing flags
    private static final boolean NO_CACHE = false;
    private static final double DISCONNECT_MONKEY = 0/100.0; // Probability of network disconnects
    private static final Random random = new Random();

    public void requestSync() {
        // If sync is active when we call this method, we need another sync, as new data may not
        // have been taken into account (e.g. if the dirty data has already been serialized and
        // is being sent over the network). Setting this to true will cause the sync thread to
        // immediately resync on completion.
        syncRequested = true;

        syncThread.signal();
    }

    public void requestStallFor(long millis) {
        long stallUntil = System.currentTimeMillis() + millis;
        if (syncStallRequestedUntil < stallUntil) syncStallRequestedUntil = stallUntil;
    }

    public static synchronized SyncHelper getInstance(Context context) {
        if (singleton == null)
            singleton = new SyncHelper(context);
        return singleton;
    }

    public void init() {
        if (!initialized) {
            initialized = true;

            // Using an inner (anonymous) class to avoid multiple Thread.start()s.
            syncThread.start();
        }
    }

    private SyncHelper(Context context) {
        ORMDroidApplication.initialize(context);
    }

    private void syncDirtyData() {
        Long lastSyncTime = getLastSync(Utils.SYNC_GPS_DATA);
        Long syncTailTime = getLastSync(Utils.SYNC_TAIL_TIME);
        Long syncTailSkip = getLastSync(Utils.SYNC_TAIL_SKIP);
        if ((lastSyncTime == null || lastSyncTime == 0) && syncTailTime == null) { 
            // New full sync: today first, rest later
            lastSyncTime = -1l; //-24l * 60 * 60; // Sync forwards from yesterday 
            syncTailTime = -1l; //-24l * 60 * 60; // Sync backwards from yesterday
        } else if (syncTailTime == null) {
            // Old full sync done: no tail
            syncTailTime = 0l; // Sync backwards from genesis
        }
        if (syncTailSkip == null) syncTailSkip = 0l;
        String result = syncWithServer(lastSyncTime, syncTailTime, syncTailSkip);
        if (!SUCCESS.equals(result)) {
            MessagingInterface.sendMessage(MESSAGING_TARGET_PLATFORM,
                    MESSAGING_METHOD_ON_SYNCHRONIZATION, MESSAGING_MESSAGE_SYNC_FAILURE);
        }
        Log.i("SyncHelper", "Sync result: " + result);
    }

    public Long getLastSync(String storedVariableName) {
        return Preference.getLong(storedVariableName);
    }

    public boolean saveLastSync(String storedVariableName, long currentSyncTime) {
        return Preference.setLong(storedVariableName, Long.valueOf(currentSyncTime));
    }

    public String syncWithServer(long head, long tail_time, long tail_skip) {
        AccessToken ud = AccessToken.get();
        if (ud == null || ud.getApiAccessToken() == null) {
            if (ud == null)
                Log.i("SyncHelper", "Null user");
            return UNAUTHORIZED;
        }

        Device self = Device.self();
        if (self == null) {
            Log.i("SyncHelper", "Registering new device");
            try {
                self = registerDevice();
                self.self = true;
                self.save();
            } catch (IOException exception) {
                exception.printStackTrace();
                return FAILURE;
            }
        }

        ObjectMapper om = new ObjectMapper();
        om.setSerializationInclusion(Include.NON_NULL);
        om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
        om.setVisibilityChecker(om.getSerializationConfig().getDefaultVisibilityChecker()
                .withFieldVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                .withGetterVisibility(JsonAutoDetect.Visibility.NONE)
                .withSetterVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                .withIsGetterVisibility(JsonAutoDetect.Visibility.NONE)
                .withCreatorVisibility(JsonAutoDetect.Visibility.NONE));

        Log.i("SyncHelper", "Syncing with server, head: " + new Date(head*1000).toString() + ", tail: " + new Date(tail_time*1000).toString() + "::" + tail_skip);

        // Receive data from:
        String url = Utils.POSITION_SYNC_URL + head;
        // Transmit data up to:
        long stopwatch = System.currentTimeMillis();
        Request request = new Request(head, tail_time, tail_skip);
        Log.i("SyncHelper", "Read from local database in "
                + (System.currentTimeMillis() - stopwatch) + "ms.");

        int connectionTimeoutMillis = 15000;
        int socketTimeoutMillis = 3*60000;

        HttpResponse response = null;
        AndroidHttpClient httpclient = AndroidHttpClient.newInstance("GlassfitPlatform/v"+Utils.PLATFORM_VERSION);
        boolean acquired = false;
        try {
            concurrencyLimit.acquire();
            acquired = true;
            Log.i("SyncHelper", "sems: " + concurrencyLimit.availablePermits());
            try {
                stopwatch = System.currentTimeMillis();
                HttpParams httpParams = httpclient.getParams();
                HttpConnectionParams.setConnectionTimeout(httpParams, connectionTimeoutMillis);
                HttpConnectionParams.setSoTimeout(httpParams, socketTimeoutMillis);
                HttpPost httppost = new HttpPost(url);
                StringEntity se = new StringEntity(om.writeValueAsString(request));
                Log.i("SyncHelper", "Uploading " + se.getContentLength() / 1000 + "kB");
                MessagingInterface.sendMessage("Platform", "OnSynchronizationProgress", "Uploading "
                        + se.getContentLength() / 1000 + "kB");
                // uncomment for debug, can be a very long string:
                // Log.d("SyncHelper","Pushing JSON to server: " +
                // om.writeValueAsString(data));
                se.setContentEncoding(new BasicHeader(HTTP.CONTENT_TYPE, "application/json"));
                httppost.setEntity(se);
                // Content-type is sent twice and defaults to text/plain, TODO: fix?
                httppost.setHeader(HTTP.CONTENT_TYPE, "application/json");
                httppost.setHeader("Authorization", "Bearer " + ud.getApiAccessToken());
                Log.i("SyncHelper", "Created HTTP request in "
                        + (System.currentTimeMillis() - stopwatch) + "ms.");
                stopwatch = System.currentTimeMillis();
                AndroidHttpClient.modifyRequestToAcceptGzipResponse(httppost);
                if (DISCONNECT_MONKEY > 0) {
                    if (random.nextInt() <= DISCONNECT_MONKEY*Integer.MAX_VALUE) {
                        Thread.sleep((long)(socketTimeoutMillis * random.nextFloat()));
                        throw new SocketTimeoutException("DISCONNECT MONKEY STRIKES!");
                    }
                }
                response = httpclient.execute(httppost);
                Log.i("SyncHelper", "Pushed data in " + (System.currentTimeMillis() - stopwatch)
                        + "ms.");
                Log.i("SyncHelper", "Pushed " + request.data.toString());
                MessagingInterface.sendMessage("Platform", "OnSynchronizationProgress", "Pushed data");
            } catch (IllegalStateException exception) {
                exception.printStackTrace();
                return FAILURE;
            } catch (IllegalArgumentException exception) {
                exception.printStackTrace();
                return FAILURE;
            } catch (UnsupportedEncodingException exception) {
                exception.printStackTrace();
                return FAILURE;
            } catch (ClientProtocolException exception) {
                exception.printStackTrace();
                return FAILURE;
            } catch (IOException exception) {
                exception.printStackTrace();
                return FAILURE;
            }
            if (response != null) {
                try {
                    StatusLine status = response.getStatusLine();
                    if (status.getStatusCode() == HttpStatus.SC_OK) {
                        stopwatch = System.currentTimeMillis();
                        if (response.getEntity().getContentLength() > 0) {
                            Log.i("SyncHelper", "Downloading "
                                    + response.getEntity().getContentLength() / 1000 + "kB");
                            MessagingInterface.sendMessage("Platform", "OnSynchronizationProgress",
                                    "Downloading " + response.getEntity().getContentLength() / 1000
                                            + "kB");
                        }
    
                        Response newdata = om.readValue(AndroidHttpClient.getUngzippedContent(response.getEntity()),
                                Response.class);
                        Log.i("SyncHelper", "Received " + newdata.toString());
                        Log.i("SyncHelper", "Received data in "
                                + (System.currentTimeMillis() - stopwatch) + "ms.");
                        MessagingInterface.sendMessage("Platform", "OnSynchronizationProgress",
                                "Received data");

                        // Flush transient data from db
                        stopwatch = System.currentTimeMillis();
                        request.data.flush();
                        Log.i("SyncHelper",
                                "Deleted transient data from local DB in "
                                        + (System.currentTimeMillis() - stopwatch) + "ms.");
    
                        // Save new data to local db
                        stopwatch = System.currentTimeMillis();
                        newdata.save();
                        Log.i("SyncHelper",
                                "Saved remote data to local DB in "
                                        + (System.currentTimeMillis() - stopwatch) + "ms.");
    
                        saveLastSync(Utils.SYNC_GPS_DATA, newdata.sync_timestamp);
                        if (newdata.tail_timestamp != null) {
                            saveLastSync(Utils.SYNC_TAIL_TIME, newdata.tail_timestamp);
                        }
                        if (newdata.tail_skip != null) {
                            saveLastSync(Utils.SYNC_TAIL_SKIP, newdata.tail_skip);
                        }
                        Log.i("SyncHelper", "Stored " + newdata.toString());
                        if (!newdata.errors.isEmpty()) {
                            Log.e("SyncHelper", "Sync returned " + newdata.errors.size() + " errors!");
                            for (String error : newdata.errors) Log.e("SyncHelper", " Sync returned error: " + error);
                        }
                        String type = MESSAGING_MESSAGE_SYNC_SUCCESS_FULL;
                        if (newdata.tail_skip != null && newdata.tail_skip > 0) type = MESSAGING_MESSAGE_SYNC_SUCCESS_PARTIAL;
                        MessagingInterface.sendMessage("Platform", MESSAGING_METHOD_ON_SYNCHRONIZATION, type);
                        return SUCCESS;
                    }
                    if (status.getStatusCode() == HttpStatus.SC_UNAUTHORIZED) {
                        // Invalidate access token
                        ud.setApiAccessToken(null);
                        ud.save();
                    }
                    return status.getStatusCode() + " " + status.getReasonPhrase();
                } catch (IllegalStateException e) {
                    e.printStackTrace();
                    return FAILURE;
                } catch (IOException e) {
                    e.printStackTrace();
                    return FAILURE;
                }
            } else {
                Log.w("SyncHelper", "No response from API during sync");
                return FAILURE;
            }
        } catch (InterruptedException e) {
            Log.e("SyncHelper", "Interrupted");
            return FAILURE;
        } finally {
            if (httpclient != null) httpclient.close();
            if (acquired) concurrencyLimit.release();

            // Populate auto-matches from network if necessary
            AutoMatches.update();
        }
    }

    /**
     * Object representation of the JSON data that comes back from the server.
     * 
     * @author Janne Husberg
     * 
     */
    @JsonTypeInfo(use = JsonTypeInfo.Id.NAME, include = JsonTypeInfo.As.WRAPPER_OBJECT)
    @JsonTypeName("response")
    public static class Response {
        public long sync_timestamp;
        public Long tail_timestamp;
        public Long tail_skip;
        public List<Device> devices;
        public List<Friendship> friends;
        public List<Track> tracks;
        public List<Position> positions;
        public List<Orientation> orientations;
        public List<Transaction> transactions;
        public List<Notification> notifications;
        public List<Challenge> challenges;
        public List<User> users;
        public List<Invite> invites;
        public List<Accumulator> counters;
        public List<Mission> missions;
        public List<MissionClaim> mission_claims;

        public List<String> errors;

        /**
         * For each record
         */
        public void save() {
            // NOTE: Race condition with objects dirtied after sync start
            // TODO: Assume dirtied take precedence or merge manually.

            int localDeviceId = Helper.getDevice().getId(); // can't query this
                                                           // within transaction
                                                           // below

            try {
                ORMDroidApplication.getInstance().beginTransaction();
                if (devices != null)
                    for (Device device : devices) {
                        if (device.getId() != localDeviceId)
                            device.save();
                    }
                if (friends != null)
                    for (Friendship friend : friends) {
                        friend.save();
                        friend.flush();
                    }
                if (positions != null)
                    for (Position position : positions) {
                        // Persist, then flush deleted if needed.
                        position.save();
                        position.flush();
                    }
                if (orientations != null)
                    for (Orientation orientation : orientations) {
                        // Persist, then flush deleted if needed.
                        orientation.save();
                        orientation.flush();
                    }
                if (tracks != null)
                    for (Track track : tracks) {
                        // Persist, then flush deleted if needed.
                        track.save();
                        track.flush();
                    }
                if (transactions != null)
                    for (Transaction transaction : transactions) {
                        // Persist
                        transaction.store();
                    }
                if (notifications != null)
                    for (Notification notification : notifications) {
                        // Persist, then flush dirty state.
                        notification.save();
                        notification.flush();
                    }
                if (challenges != null)
                    for (Challenge challenge : challenges) {
                        challenge.save();
                        challenge.flush();
                    }
                if (users != null)
                    for (User user : users) {
                        user.save();
                    }
                if (invites != null)
                    for (Invite invite : invites) {
                        invite.save();
                    }
                if (counters != null)
                    for (Accumulator acc : counters) {
                        acc.save();
                    }
                if (missions != null)
                    for (Mission mission : missions) {
                        mission.save();
                        mission.flush();
                    }
                if (mission_claims != null) {
                    for (MissionClaim claim : mission_claims) {
                        claim.save();
                        claim.flush();
                    }
                }
                ORMDroidApplication.getInstance().setTransactionSuccessful();
            } finally {
                ORMDroidApplication.getInstance().endTransaction();
            }
        }

        /**
         * String representation of all data held by this class, suitable for
         * log messages / debugging.
         */
        public String toString() {
            StringBuffer buff = new StringBuffer();
            if (devices != null)
                join(buff, devices.size() + " devices");
            if (friends != null)
                join(buff, friends.size() + " friends");
            if (tracks != null)
                join(buff, tracks.size() + " tracks");
            if (positions != null)
                join(buff, positions.size() + " positions");
            if (orientations != null)
                join(buff, orientations.size() + " orientations");
            if (transactions != null)
                join(buff, transactions.size() + " transactions");
            if (notifications != null)
                join(buff, notifications.size() + " notifications");
            if (challenges != null)
                join(buff, challenges.size() + " challenges");
            if (users != null)
                join(buff, users.size() + " users");
            if (invites != null)
                join(buff, invites.size() + " invites");
            if (counters != null)
                join(buff, counters.size() + " counters");
            if (missions != null)
                join(buff, missions.size() + " missions");
            if (mission_claims != null)
                join(buff, mission_claims.size() + " mission claims");
            return buff.toString();
        }

    }

    public static void join(StringBuffer buff, String string) {
        if (buff.length() > 0)
            buff.append(", ");
        buff.append(string);
    }

    public static class Request {
        public long head_ts;
        public long tail_ts;
        public long tail_skip;
        public Data data;
        
        public Request(long head_timestamp, long tail_timestamp, long tail_skip) {
            this.head_ts = head_timestamp;
            this.tail_ts = tail_timestamp;
            this.tail_skip = tail_skip;            
            this.data = new Data();
        }
    }
    
    public static class Data {
        public List<Device> devices;
        public List<Friendship> friends;
        public List<Track> tracks;
        public List<Position> positions;
        public List<Orientation> orientations;
        public List<Transaction> transactions;
        public List<Notification> notifications;
        public List<Challenge> challenges;
        public List<MatchedTrack> matched_tracks;
        public List<MissionClaim> mission_claims;
        public List<Invite> invites;
        public List<Action> actions;
        public List<Event> events;
        public List<CrashReport> crash_reports;

        public Data() {
            // NOTE: We assume that any dirtied object is local/in the default
            // entity collection.
            // If this is not the case, we need to filter on entitycollection
            // too.

            devices = new ArrayList<Device>();
            Device self = Device.self();
            devices.add(self);
            // TODO: Send add/deletes where provider = glassfit
            friends = new ArrayList<Friendship>();
            // Add/delete
            tracks = Entity.query(Track.class).where(eql("dirty", true)).executeMulti();
            for (Track track : tracks) {
                if (track.device_id <= 0) track.device_id = self.getId();
            }
            // Add/delete
            positions = Entity.query(Position.class).where(eql("dirty", true)).executeMulti();
            for (Position position : positions) {
                if (position.device_id <= 0) position.device_id = self.getId();
            }
            // Add/delete
            orientations = Entity.query(Orientation.class).where(eql("dirty", true)).executeMulti();
            for (Orientation orientation : orientations) {
                if (orientation.device_id <= 0) orientation.device_id = self.getId();
            }
            // Add
            challenges = Entity.query(Challenge.class).where(eql("dirty", true)).executeMulti();
            for (Challenge challenge : challenges) {
                if (challenge.device_id <= 0) challenge.device_id = self.getId();
            }
            // Add
            matched_tracks = Entity.query(MatchedTrack.class).where(eql("dirty", true)).executeMulti();
            // Add
            mission_claims = Entity.query(MissionClaim.class).where(eql("dirty", true)).executeMulti();
            // Modify
            invites = Entity.query(Invite.class).where(eql("dirty", true)).executeMulti();
            // Add
            transactions = Entity.query(Transaction.class).where(eql("dirty", true)).executeMulti();
            for (Transaction transaction : transactions) {
                if (transaction.device_id <= 0) transaction.device_id = self.getId();
            }
            // Marked read (ignore synthetic)
            notifications = Entity.query(Notification.class).where(and(eql("dirty", true), gt("id", 0)))
                    .executeMulti();
            // Transmit all actions
            actions = Entity.query(Action.class).executeMulti();
            // Transmit all events
            events = Entity.query(Event.class).executeMulti();
            for (Event event : events) {
                if (event.device_id <= 0) event.device_id = self.getId();
            }
            // Transmit all crash reports
            crash_reports = Entity.query(CrashReport.class).executeMulti();
        }

        public void flush() {
            // wrapping this in a transaction would make it faster, but
            // potentially block the synchronous db calls from the game for a
            // while
            //
            // TODO: Friends, delete/replace?
            // Flush dirty objects
            for (Track track : tracks)
                track.flush();
            for (Position position : positions)
                position.flush();
            for (Orientation orientation : orientations)
                orientation.flush();
            for (Challenge challenge : challenges)
                challenge.flush();
            // Flush client-side transactions. Server will replace them with a verified transaction.
            for (Transaction transaction : transactions) {
                transaction.flush();
            }
            for (MatchedTrack match : matched_tracks) {
                match.flush();
            }
            for (MissionClaim claim : mission_claims) {
                claim.flush();
            }
            for (Invite invite : invites) {
                invite.flush();
            }
            for (Notification notification : notifications)
                notification.flush();
            List<Notification> synthetics = Entity.query(Notification.class)
                                            .where(and(eql("dirty", true), leq("id", 0))).executeMulti();
            for (Notification notification : synthetics)
                notification.flush();
            // Delete all synced actions
            for (Action action : actions)
                action.delete();
            // Delete all synced events
            for (Event event : events)
                event.delete();
            // Delete all synced crash reports
            for (CrashReport report : crash_reports)
                report.delete();
        }

        public String toString() {
            StringBuffer buff = new StringBuffer();
            if (devices != null)
                join(buff, devices.size() + " devices");
            if (friends != null)
                join(buff, friends.size() + " friends");
            if (tracks != null)
                join(buff, tracks.size() + " tracks");
            if (positions != null)
                join(buff, positions.size() + " positions");
            if (orientations != null)
                join(buff, orientations.size() + " orientations");
            if (challenges != null)
                join(buff, challenges.size() + " challenges");
            if (transactions != null)
                join(buff, transactions.size() + " transactions");
            if (matched_tracks != null)
                join(buff, matched_tracks.size() + " matched tracks");
            if (mission_claims != null)
                join(buff, mission_claims.size() + " mission claims");
            if (invites != null)
                join(buff, invites.size() + " invites");
            if (notifications != null)
                join(buff, notifications.size() + " notifications");
            if (actions != null)
                join(buff, actions.size() + " actions");
            if (events != null)
                join(buff, events.size() + " events");
            if (crash_reports != null)
                join(buff, crash_reports.size() + " crash reports");
            return buff.toString();
        }
    }

    protected static long getMaxAge(final Header[] headers) {
        long maxage = -1;
        for (Header hdr : headers) {
            for (HeaderElement elt : hdr.getElements()) {
                if ("max-age".equals(elt.getName()) || "s-maxage".equals(elt.getName())) {
                    try {
                        long currMaxAge = Long.parseLong(elt.getValue());
                        if (maxage == -1 || currMaxAge < maxage) {
                            maxage = currMaxAge;
                        }
                    } catch (NumberFormatException nfe) {
                        // be conservative if can't parse
                        maxage = 0;
                    }
                }
            }
        }
        return maxage;
    }

    public static Challenge getChallenge(int deviceId, int challengeId) throws UnauthorizedException, CouldNotFetchException {
        Challenge challenge = Challenge.get(deviceId, challengeId);
        if (challenge != null && challenge.isInCollection("default")) return challenge;

        return get("challenges/" + deviceId + "-" + challengeId, Challenge.class);
    }

    public static User getUser(int userId) throws UnauthorizedException, CouldNotFetchException {
        User user = User.get(userId);
        if (user != null && user.isInCollection("default")) return user;

        return get("users/" + userId, User.class);
    }

    public static Track getTrack(int deviceId, int trackId) throws UnauthorizedException, CouldNotFetchException {
        Track track = Track.get(deviceId, trackId);
        if (track != null && track.isInCollection("default")) return track;

        return get("tracks/" + deviceId + "-" + trackId, Track.class);
    }

    public static <T extends CollectionEntity> T get(String route, Class<T> clz) throws UnauthorizedException, CouldNotFetchException {
        ObjectMapper om = new ObjectMapper();
        om.setSerializationInclusion(Include.NON_NULL);
        om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
        om.setVisibilityChecker(om.getSerializationConfig().getDefaultVisibilityChecker()
                .withFieldVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                .withGetterVisibility(JsonAutoDetect.Visibility.NONE)
                .withSetterVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                .withIsGetterVisibility(JsonAutoDetect.Visibility.NONE)
                .withCreatorVisibility(JsonAutoDetect.Visibility.NONE));

        int connectionTimeoutMillis = 15000;
        int socketTimeoutMillis = 30000;

        EntityCollection cache = EntityCollection.get(route);
        if (NO_CACHE) {
            cache.clear(clz);
            cache.ttl = 0;
            cache.lastModified = null;
            if (!cache.isTransient()) cache.save();
        }
        if (!cache.hasExpired()) {
            Log.i("SyncHelper", "Returning " + clz.getSimpleName() + " from /" + route
                    + " from cache (ttl: " + (cache.ttl - System.currentTimeMillis()) / 1000 + "s)");
            return cache.getItem(clz);
        }

        // Lock section so that we don't trigger the same fetch multiple times concurrently
        Lock alock = new ReentrantLock();
        Lock lock = cacheLocks.putIfAbsent(route, alock);
        if (lock == null) lock = alock;

        lock.lock();
        try {
            cache = EntityCollection.get(route);
            if (NO_CACHE) {
                cache.clear(clz);
                cache.ttl = 0;
                cache.lastModified = null;
                if (!cache.isTransient()) cache.save();
            }
            if (!cache.hasExpired()) {
                Log.i("SyncHelper", "Returning " + clz.getSimpleName() + " from /" + route
                        + " from cache (ttl: " + (cache.ttl - System.currentTimeMillis()) / 1000 + "s) after lock wait");
                return cache.getItem(clz);
            }

            if (singleton != null) singleton.requestStallFor(5000);

            HttpResponse response = null;
            AccessToken ud = AccessToken.get();
            AndroidHttpClient httpclient = AndroidHttpClient.newInstance("GlassfitPlatform/v" + Utils.PLATFORM_VERSION);
            boolean acquired = false;
            try {
                concurrencyLimit.acquire();
                acquired = true;
                Log.i("SyncHelper", "Fetching " + clz.getSimpleName() + " from /" + route + " sems: " + concurrencyLimit.availablePermits());
                String url = Utils.API_URL + route;
                try {
                    HttpParams httpParams = httpclient.getParams();
                    HttpConnectionParams.setConnectionTimeout(httpParams, connectionTimeoutMillis);
                    HttpConnectionParams.setSoTimeout(httpParams, socketTimeoutMillis);
                    HttpGet httpget = new HttpGet(url);
                    if (ud != null && ud.getApiAccessToken() != null) {
                        httpget.setHeader("Authorization", "Bearer " + ud.getApiAccessToken());
                    }
                    if (cache.lastModified != null) {
                        httpget.setHeader("If-Modified-Since", cache.lastModified);
                    }
                    if (DISCONNECT_MONKEY > 0) {
                        if (random.nextInt() <= DISCONNECT_MONKEY*Integer.MAX_VALUE) {
                            Thread.sleep((long)(socketTimeoutMillis * random.nextFloat()));
                            throw new SocketTimeoutException("DISCONNECT MONKEY STRIKES!");
                        }
                    }
                    response = httpclient.execute(httpget);
                } catch (IOException exception) {
                    exception.printStackTrace();
                    Log.e("SyncHelper", "GET /" + route + " threw " + exception.getClass().toString() + "/"
                            + exception.getMessage());
                    // Return stale value
                    try {
                        return cache.getItem(clz);
                    } catch (EntityCollection.CacheMissingException e) {
                        throw new CouldNotFetchException(null, route, e);
                    }
                }
                if (response != null) {
                    try {
                        StatusLine status = response.getStatusLine();
                        if (status.getStatusCode() == HttpStatus.SC_OK) {
                            if (singleton != null) singleton.requestStallFor(5000);
                            SingleResponse<T> data = om.readValue(response.getEntity().getContent(), om
                                    .getTypeFactory().constructParametricType(SingleResponse.class, clz));
                            long maxAge = getMaxAge(response.getHeaders("Cache-Control"));
                            if (maxAge < 60)
                                maxAge = 60; // TODO: remove?
                            cache.lastModified = response.getFirstHeader("Last-Modified").getValue();
                            cache.expireIn((int) maxAge);
                            cache.replace(data.response, clz);
                            Log.i("SyncHelper", "Cached /" + route + " for " + maxAge + "s, last modified: " + cache.lastModified);
                            return data.response;
                        } else if (status.getStatusCode() == HttpStatus.SC_NOT_MODIFIED) {
                            // Cache is still valid
                            long maxAge = getMaxAge(response.getHeaders("Cache-Control"));
                            if (maxAge < 60)
                                maxAge = 60; // TODO: remove?
                            cache.expireIn((int) maxAge);
                            Log.i("SyncHelper", "Cached /" + route + " for another " + maxAge + "s, last modified: " + cache.lastModified);
                            return cache.getItem(clz);
                        } else if (status.getStatusCode() == HttpStatus.SC_NOT_FOUND) {
                            Log.e("SyncHelper", "GET /" + route + " returned " + status.getStatusCode()
                                    + "/" + status.getReasonPhrase());
                            cache.lastModified = null;
                            cache.clear(clz);
                            cache.expireIn(0);
                            return null;
                        } else {
                            Log.e("SyncHelper", "GET /" + route + " returned " + status.getStatusCode()
                                    + "/" + status.getReasonPhrase());
                            if (status.getStatusCode() == HttpStatus.SC_UNAUTHORIZED) {
                                // Invalidate access token
                                ud.setApiAccessToken(null);
                                ud.save();
                                throw new UnauthorizedException(status, route);
                            }
                            // Return stale value
                            try {
                                return cache.getItem(clz);
                            } catch (EntityCollection.CacheMissingException e) {
                                throw new CouldNotFetchException(status, route, e);
                            }
                        }
                    } catch (IOException exception) {
                        exception.printStackTrace();
                        Log.e("SyncHelper", "GET /" + route + " threw " + exception.getClass().toString()
                                + "/" + exception.getMessage());
                        // Return stale value
                        try {
                            return cache.getItem(clz);
                        } catch (EntityCollection.CacheMissingException e) {
                            throw new CouldNotFetchException(null, route, e);
                        }
                    }
                } else {
                    Log.e("SyncHelper", "No response from API route " + route);
                    // Return stale value
                    try {
                        return cache.getItem(clz);
                    } catch (EntityCollection.CacheMissingException e) {
                        throw new CouldNotFetchException(null, route, e);
                    }
                }
            } catch (InterruptedException e) {
                Log.e("SyncHelper", "Interrupted, route: " + route);
                // Return stale value
                try {
                    return cache.getItem(clz);
                } catch (EntityCollection.CacheMissingException ex) {
                    throw new CouldNotFetchException(null, route, ex);
                }
            } finally {
                if (httpclient != null) httpclient.close();
                if (acquired) concurrencyLimit.release();
            }
        } finally {
            lock.unlock();
        }
    }

    public static byte[] get(String route) throws IOException {
        int connectionTimeoutMillis = 15000;
        int socketTimeoutMillis = 30000;

        HttpResponse response = null;
        AccessToken ud = AccessToken.get();
        AndroidHttpClient httpclient = AndroidHttpClient.newInstance("GlassfitPlatform/v"+Utils.PLATFORM_VERSION);
        boolean acquired = true;
        try {
            concurrencyLimit.acquire();
            acquired = true;
            Log.i("SyncHelper", "Fetching route /" + route + " sems:" + concurrencyLimit.availablePermits());
            String url = Utils.API_URL + route;
            try {
                HttpParams httpParams = httpclient.getParams();
                HttpConnectionParams.setConnectionTimeout(httpParams, connectionTimeoutMillis);
                HttpConnectionParams.setSoTimeout(httpParams, socketTimeoutMillis);
                HttpGet httpget = new HttpGet(url);
                if (ud != null && ud.getApiAccessToken() != null) {
                    httpget.setHeader("Authorization", "Bearer " + ud.getApiAccessToken());
                }
                if (DISCONNECT_MONKEY > 0) {
                    if (random.nextInt() <= DISCONNECT_MONKEY*Integer.MAX_VALUE) {
                        Thread.sleep((long)(socketTimeoutMillis * random.nextFloat()));
                        throw new SocketTimeoutException("DISCONNECT MONKEY STRIKES!");
                    }
                }
                response = httpclient.execute(httpget);
            } catch (IOException exception) {
                throw new IOException("GET /" + route + " threw exception", exception);
            }
            if (response != null) {
                StatusLine status = response.getStatusLine();
                if (status.getStatusCode() == HttpStatus.SC_OK) {
                    Log.i("SyncHelper", "GET /" + route + " returned " + status.getStatusCode()
                            + "/" + status.getReasonPhrase());
                    long length = response.getEntity().getContentLength();
                    if (length > Integer.MAX_VALUE)
                        throw new IOException("Content-length: " + length + " does not fit inside a byte array");
                    byte[] bytes = new byte[(int) length];
                    IOUtils.readFully(response.getEntity().getContent(), bytes);
                    return bytes;
                } else {
                    Log.e("SyncHelper", "GET /" + route + " returned " + status.getStatusCode()
                            + "/" + status.getReasonPhrase());
                    if (status.getStatusCode() == HttpStatus.SC_UNAUTHORIZED) {
                        // Invalidate access token
                        ud.setApiAccessToken(null);
                        ud.save();
                    }

                    throw new IOException("GET /" + route + " returned " + status.getStatusCode()
                            + "/" + status.getReasonPhrase());
                }
            } else {
                return new byte[0];
            }
        } catch (InterruptedException e) {
            throw new IOException("GET /" + route + " interrupted", e);
        } finally {
            if (httpclient != null) httpclient.close();
            if (acquired) concurrencyLimit.release();
        }
    }

    public static class SingleResponse<T> {
        public T response;
    }

    public static <T extends CollectionEntity> List<T> getCollection(String route, Class<T> clz) throws UnauthorizedException, CouldNotFetchException {
        ObjectMapper om = new ObjectMapper();
        om.setSerializationInclusion(Include.NON_NULL);
        om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
        om.setVisibilityChecker(om.getSerializationConfig().getDefaultVisibilityChecker()
                .withFieldVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                .withGetterVisibility(JsonAutoDetect.Visibility.NONE)
                .withSetterVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                .withIsGetterVisibility(JsonAutoDetect.Visibility.NONE)
                .withCreatorVisibility(JsonAutoDetect.Visibility.NONE));

        int connectionTimeoutMillis = 15000;
        int socketTimeoutMillis = 30000;

        EntityCollection cache = EntityCollection.get(route);
        if (NO_CACHE) {
            cache.clear(clz);
            cache.ttl = 0;
            cache.lastModified = null;
            if (!cache.isTransient()) cache.save();
        }
        if (!cache.hasExpired()) {
            Log.i("SyncHelper", "Fetching " + clz.getSimpleName() + "s from /" + route
                    + " from cache (ttl: " + (cache.ttl - System.currentTimeMillis()) / 1000 + "s)");
            return cache.getItems(clz);
        }

        // Lock section so that we don't trigger the same fetch multiple times concurrently
        Lock alock = new ReentrantLock();
        Lock lock = cacheLocks.putIfAbsent(route, alock);
        if (lock == null) lock = alock;

        lock.lock();
        try {
            cache = EntityCollection.get(route);
            if (NO_CACHE) {
                cache.clear(clz);
                cache.ttl = 0;
                cache.lastModified = null;
                if (!cache.isTransient()) cache.save();
            }
            if (!cache.hasExpired()) {
                Log.i("SyncHelper", "Fetching " + clz.getSimpleName() + "s from /" + route
                        + " from cache (ttl: " + (cache.ttl - System.currentTimeMillis()) / 1000 + "s) after lock wait");
                return cache.getItems(clz);
            }

            if (singleton != null) singleton.requestStallFor(5000);

            HttpResponse response = null;
            AccessToken ud = AccessToken.get();
            AndroidHttpClient httpclient = AndroidHttpClient.newInstance("GlassfitPlatform/v" + Utils.PLATFORM_VERSION);
            boolean acquired = false;
            try {
                concurrencyLimit.acquire();
                acquired = true;
                Log.i("SyncHelper", "Fetching " + clz.getSimpleName() + "s from /" + route + " sems:" + concurrencyLimit.availablePermits());
                String url = Utils.API_URL + route;
                try {
                    HttpParams httpParams = httpclient.getParams();
                    HttpConnectionParams.setConnectionTimeout(httpParams, connectionTimeoutMillis);
                    HttpConnectionParams.setSoTimeout(httpParams, socketTimeoutMillis);
                    HttpGet httpget = new HttpGet(url);
                    if (ud != null && ud.getApiAccessToken() != null) {
                        httpget.setHeader("Authorization", "Bearer " + ud.getApiAccessToken());
                    }
                    if (cache.lastModified != null) {
                        httpget.setHeader("If-Modified-Since", cache.lastModified);
                    }
                    if (DISCONNECT_MONKEY > 0) {
                        if (random.nextInt() <= DISCONNECT_MONKEY*Integer.MAX_VALUE) {
                            Thread.sleep((long)(socketTimeoutMillis * random.nextFloat()));
                            throw new SocketTimeoutException("DISCONNECT MONKEY STRIKES!");
                        }
                    }
                    response = httpclient.execute(httpget);
                } catch (IOException exception) {
                    exception.printStackTrace();
                    Log.e("SyncHelper", "GET /" + route + " threw " + exception.getClass().toString() + "/"
                            + exception.getMessage());
                    // Return stale value
                    try {
                        return cache.getItems(clz);
                    } catch (EntityCollection.CacheMissingException e) {
                        throw new CouldNotFetchException(null, route, e);
                    }
                }
                if (response != null) {
                    try {
                        StatusLine status = response.getStatusLine();
                        if (status.getStatusCode() == HttpStatus.SC_OK) {
                            if (singleton != null) singleton.requestStallFor(5000);
                            ListResponse<T> data = om.readValue(response.getEntity().getContent(), om
                                    .getTypeFactory().constructParametricType(ListResponse.class, clz));
                            long maxAge = getMaxAge(response.getHeaders("Cache-Control"));
                            if (maxAge < 60)
                                maxAge = 60; // TODO: remove?
                            cache.lastModified = response.getFirstHeader("Last-Modified").getValue();
                            cache.expireIn((int) maxAge);
                            cache.replace(data.response, clz);
                            Log.i("SyncHelper", "Cached " + data.response.size() + " " + clz.getSimpleName() + "s from /" + route + " for " + maxAge + "s, last modified: " + cache.lastModified);
                            return data.response;
                        } else if (status.getStatusCode() == HttpStatus.SC_NOT_MODIFIED) {
                            // Cache is still valid
                            long maxAge = getMaxAge(response.getHeaders("Cache-Control"));
                            if (maxAge < 60)
                                maxAge = 60; // TODO: remove?
                            cache.expireIn((int) maxAge);
                            List<T> data = cache.getItems(clz);
                            Log.i("SyncHelper", "Cached " + data.size() + " " + clz.getSimpleName() + "s from /" + route + " for another " + maxAge + "s, last modified: " + cache.lastModified);
                            return data;
                        } else if (status.getStatusCode() == HttpStatus.SC_NOT_FOUND) {
                            Log.e("SyncHelper", "GET /" + route + " returned " + status.getStatusCode()
                                    + "/" + status.getReasonPhrase());
                            cache.lastModified = null;
                            cache.clear(clz);
                            cache.expireIn(0);
                            return null;
                        } else {
                            Log.e("SyncHelper", "GET /" + route + " returned " + status.getStatusCode()
                                    + "/" + status.getReasonPhrase());
                            if (status.getStatusCode() == HttpStatus.SC_UNAUTHORIZED) {
                                // Invalidate access token
                                ud.setApiAccessToken(null);
                                ud.save();
                                throw new UnauthorizedException(status, route);
                            }
                            // Return stale value
                            try {
                                return cache.getItems(clz);
                            } catch (EntityCollection.CacheMissingException e) {
                                throw new CouldNotFetchException(status, route, e);
                            }
                        }
                    } catch (IOException exception) {
                        exception.printStackTrace();
                        Log.e("SyncHelper", "GET /" + route + " threw " + exception.getClass().toString()
                                + "/" + exception.getMessage());
                        // Return stale value
                        try {
                            return cache.getItems(clz);
                        } catch (EntityCollection.CacheMissingException e) {
                            throw new CouldNotFetchException(null, route, e);
                        }
                    }
                } else {
                    Log.e("SyncHelper", "No response from API route " + route);
                    // Return stale value
                    try {
                        return cache.getItems(clz);
                    } catch (EntityCollection.CacheMissingException e) {
                        throw new CouldNotFetchException(null, route, e);
                    }
                }
            } catch (InterruptedException e) {
                Log.e("SyncHelper", "Interrupted, route: " + route);
                // Return stale value
                try {
                    return cache.getItems(clz);
                } catch (EntityCollection.CacheMissingException ex) {
                    throw new CouldNotFetchException(null, route, ex);
                }
            } finally {
                if (httpclient != null) httpclient.close();
                if (acquired) concurrencyLimit.release();
            }
        } finally {
            lock.unlock();
        }
    }

    public static class ListResponse<T> {
        public List<T> response;
    }

    public synchronized static Device registerDevice() throws IOException {
        ObjectMapper om = new ObjectMapper();
        om.setSerializationInclusion(Include.NON_NULL);
        om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
        om.setVisibilityChecker(om.getSerializationConfig().getDefaultVisibilityChecker()
                .withFieldVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                .withGetterVisibility(JsonAutoDetect.Visibility.NONE)
                .withSetterVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                .withIsGetterVisibility(JsonAutoDetect.Visibility.NONE)
                .withCreatorVisibility(JsonAutoDetect.Visibility.NONE));

        int connectionTimeoutMillis = 15000;
        int socketTimeoutMillis = 30000;

        Log.i("SyncHelper", "Posting device details to /devices");
        String url = Utils.API_URL + "devices";

        AndroidHttpClient httpclient = AndroidHttpClient.newInstance("GlassfitPlatform/v"+Utils.PLATFORM_VERSION);
        try {
            HttpParams httpParams = httpclient.getParams();
            HttpConnectionParams.setConnectionTimeout(httpParams, connectionTimeoutMillis);
            HttpConnectionParams.setSoTimeout(httpParams, socketTimeoutMillis);
            HttpPost httppost = new HttpPost(url);
            // POST device details
            StringEntity se = new StringEntity(om.writeValueAsString(new Device()));
            httppost.setEntity(se);
            // Content-type is sent twice and defaults to text/plain, TODO: fix?
            httppost.setHeader(HTTP.CONTENT_TYPE, "application/json");
            if (DISCONNECT_MONKEY > 0) {
                if (random.nextInt() <= DISCONNECT_MONKEY*Integer.MAX_VALUE) {
                    Thread.sleep((long)(socketTimeoutMillis * random.nextFloat()));
                    throw new SocketTimeoutException("DISCONNECT MONKEY STRIKES!");
                }
            }
            HttpResponse response = httpclient.execute(httppost);
    
            if (response == null)
                throw new IOException("Null response");
            StatusLine status = response.getStatusLine();
            if (status.getStatusCode() != 200)
                throw new IOException(status.getStatusCode() + "/" + status.getReasonPhrase());
    
            // Get registered device with guid
            SingleResponse<Device> data = om.readValue(response.getEntity().getContent(), om
                    .getTypeFactory().constructParametricType(SingleResponse.class, Device.class));
    
            if (data == null || data.response == null)
                throw new IOException("Bad response");
    
            return data.response;
        } catch (InterruptedException e) {
            throw new IOException(e);
        } finally {
            if (httpclient != null) httpclient.close();
        }
    }

    public static synchronized void reset() {
        Log.i("SyncHelper", "Resetting database!");
        Device self = Device.self();
        Context context = ORMDroidApplication.getInstance().getApplicationContext();

        if (singleton != null) {
            // TODO this is untested!
            SyncHelper syncHelper = getInstance(context);
            syncHelper.initialized = false;
            synchronized (syncHelper) {
                syncHelper.notify();
            }
        }

        ORMDroidApplication.getInstance().resetDatabase();
        ORMDroidApplication.initialize(context);
        Editor editor = context.getSharedPreferences(Utils.SYNC_PREFERENCES, Context.MODE_PRIVATE)
                .edit();
        editor.putLong(Utils.SYNC_GPS_DATA, 0);
        editor.commit();
        if (self != null)
            self.save();
    }

    private class SyncThread extends Thread {
        public void signal() {
            synchronized (this) {
                notify();
            }
        }

        @Override
        public void run() {
            while (true) {
                // Skip sync if nothing urgent and a stall is requested
                if (syncRequested || System.currentTimeMillis() > syncStallRequestedUntil) {
                    syncRequested = false;

                    syncDirtyData();
                }

                // Skip wait if a sync was requested mid-sync - urgent dirty data may remain.
                if (!syncRequested) {
                    synchronized (this) {
                        try {
                            long toWait = SYNC_INTERVAL;
                            while (toWait > 0) {
                                long t = System.currentTimeMillis();
                                wait(toWait);
                                toWait -= (System.currentTimeMillis() - t);
                            }
                        } catch (Exception e) {
                            Log.w("SyncHelper", "?! Sync thread interrupted. Shouldn't happen");
                        }
                    }
                }
            }
        }
    }

    public static class UnauthorizedException extends RuntimeException {
        @Getter
        private final StatusLine status;
        @Getter
        private final String route;

        public UnauthorizedException(StatusLine status, String route) {
            super("You are not authorized to access route: " + route);
            this.status = status;
            this.route = route;
        }
    }

    public static class CouldNotFetchException extends Exception {
        @Getter
        private final StatusLine status;
        @Getter
        private final String route;

        public CouldNotFetchException(StatusLine status, String route) {
            super("Could not fetch entity from route: " + route);
            this.status = status;
            this.route = route;
        }

        public CouldNotFetchException(StatusLine status, String route, Throwable t) {
            super("Could not fetch entity from route: " + route, t);
            this.status = status;
            this.route = route;
        }
    }
}
