package com.raceyourself.platform.models;

import android.util.Log;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.core.JsonToken;
import com.fasterxml.jackson.databind.DeserializationContext;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.JsonDeserializer;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
import com.raceyourself.platform.gpstracker.SyncHelper;
import com.roscopeco.ormdroid.Entity;
import com.roscopeco.ormdroid.ORMDroidApplication;

import java.io.IOException;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;
import java.util.concurrent.locks.ReentrantLock;

import lombok.SneakyThrows;

import static com.roscopeco.ormdroid.Query.query;

@JsonDeserialize(using = AutoMatches.AutoMatchesDeserializer.class)
public class AutoMatches {
    private static boolean validateDependencies = false;
    private static final ExecutorService executor = Executors.newSingleThreadExecutor();
    private static final ReentrantLock lock = new ReentrantLock();
    private static volatile FutureTask<Boolean> refreshFuture = null;

    private static final boolean DEMO = true;

    public AutoMatches() {
    }

    public static boolean requiresUpdate() {
        if (DEMO) return false;
        EntityCollection cache = EntityCollection.get("matches");
        if (cache.hasExpired()) {
            return true;
        } else {
            return false;
        }
    }

    public static boolean update() {
        if (!requiresUpdate()) return false;
        if (refreshFuture != null) return false;
        if (!lock.tryLock()) return false;
        try {
            if (refreshFuture != null) return false;
            Log.i("AutoMatches", "refreshing from network");
            refreshFuture = new FutureTask(new Callable<Boolean>() {
                @Override
                public Boolean call() throws Exception {
                    try {
                        // The streaming deserializer stores the tracks in the appropriate collections
                        AutoMatches matches = new ObjectMapper().readValue(SyncHelper.get("matches"), AutoMatches.class);
                        return true;
                    } catch (IOException e) {
                        e.printStackTrace();
                        return false;
                    } finally {
                        refreshFuture = null;
                    }
                }
            });
            executor.submit(refreshFuture);
        } finally {
            lock.unlock();
        }
        return true;
    }

    public static void ensureAvailability() {
        update();
        if (refreshFuture != null) {
            try {
                refreshFuture.get();
            } catch (Exception e) {
                throw new Error(e);
            }
        }
    }

    public static List<Track> getBucket(String fitnessLevel, int duration) {
        if (!validateDependencies) {
            query(EntityCollection.Association.class).where("id = 0").execute(); // Make sure the associations table is created
            query(MatchedTrack.class).where("id = 0").execute(); // Make sure the matched_tracks table is created
            validateDependencies = true;
        }
        if (refreshFuture != null) {
            try {
                refreshFuture.get();
            } catch (Exception e) {
                throw new Error(e);
            }
        }
        List<Track> tracks = query(Track.class).where(Track.inCollection("matches-" + fitnessLevel + "-" + duration) +
                                                      " AND NOT EXISTS (SELECT 1 FROM matched_tracks WHERE matched_tracks.device_id=device_id AND matched_tracks.track_id=track_id)")
                                               .executeMulti();

        if (tracks.isEmpty()) {
            Log.w("AutoMatches", "No tracks left in bucket: " + fitnessLevel + "," + duration  +"m, falling back to unfiltered bucket");
            // Fall back to the unfiltered bucket
            tracks = query(Track.class).where(Track.inCollection("matches-" + fitnessLevel + "-" + duration)).executeMulti();
            EntityCollection.get("matches").expireIn(0);
        }

//        if (tracks.isEmpty()) {
//            Log.e("AutoMatches", "No tracks in bucket: " + fitnessLevel + "," + duration  +"m, fetching matrix from network");
//            // Fetch from network
//            if (update()) return getBucket(fitnessLevel, duration);
//        }

        return tracks;
    }

    public static final class AutoMatchesDeserializer extends JsonDeserializer<AutoMatches> {
        @Override
        public AutoMatches deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
            ObjectMapper om = new ObjectMapper();
            om.setSerializationInclusion(JsonInclude.Include.NON_NULL);
            om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
            om.setVisibilityChecker(om.getSerializationConfig().getDefaultVisibilityChecker()
                    .withFieldVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                    .withGetterVisibility(JsonAutoDetect.Visibility.NONE)
                    .withSetterVisibility(JsonAutoDetect.Visibility.PUBLIC_ONLY)
                    .withIsGetterVisibility(JsonAutoDetect.Visibility.NONE)
                    .withCreatorVisibility(JsonAutoDetect.Visibility.NONE));

            Log.i("AutoMatches", "deserializing into database");
            ORMDroidApplication.getInstance().beginTransaction();
            try {
                if (jsonParser.getCurrentToken() != JsonToken.START_OBJECT) throw new IOException("Expected wrapper object start, not " + jsonParser.getCurrentToken().toString());
                if (jsonParser.nextToken() != JsonToken.FIELD_NAME) throw new IOException("Expected wrapper field name, not " + jsonParser.getCurrentToken().toString());
                if (jsonParser.nextToken() != JsonToken.START_OBJECT) throw new IOException("Expected root object start, not " + jsonParser.getCurrentToken().toString());
                while (jsonParser.nextToken() != JsonToken.END_OBJECT) {
                    if (jsonParser.getCurrentToken() != JsonToken.FIELD_NAME) throw new IOException("Expected fitness level field name, not " + jsonParser.getCurrentToken().toString());
                    String fitnessLevel = jsonParser.getCurrentName();
                    if (jsonParser.nextToken() != JsonToken.START_OBJECT) throw new IOException("Expected fitness bucket object start, not " + jsonParser.getCurrentToken().toString());
                    while (jsonParser.nextToken() != JsonToken.END_OBJECT) {
                        if (jsonParser.getCurrentToken() != JsonToken.FIELD_NAME) throw new IOException("Expected duration field name, not " + jsonParser.getCurrentToken().toString());
                        String duration = jsonParser.getCurrentName();
                        if (jsonParser.nextToken() != JsonToken.START_ARRAY) throw new IOException("Expected track array start, not " + jsonParser.getCurrentToken().toString());
                        EntityCollection.get("matches-" + fitnessLevel + "-" + duration).clear(Track.class);
                        if (jsonParser.nextToken() != JsonToken.END_ARRAY) { // om.readValues wants the first object token, so safe to check nextToken
                            int count = 0;
                            for (Iterator<Track> it = om.readValues(jsonParser, Track.class); it.hasNext(); ) {
                                it.next().storeIn("matches-" + fitnessLevel + "-" + duration);
                                count++;
                            }
                            Log.i("AutoMatches", "count for bucket named " + fitnessLevel + "-" + duration + " is " + count);
                        }
                    }
                }
                new EntityCollection("matches").expireIn(7*24*60*60);
                MatchedTrack.clearSynced();
                ORMDroidApplication.getInstance().setTransactionSuccessful();
            } finally {
                ORMDroidApplication.getInstance().endTransaction();
            }
            return new AutoMatches();
        }
    }
}
