
package com.raceyourself.platform.gpstracker;

import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Timer;
import java.util.TimerTask;

import org.apache.commons.math3.stat.descriptive.DescriptiveStatistics;
import org.json.JSONException;
import org.json.JSONObject;

import android.app.Service;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;

import com.raceyourself.platform.models.AccessToken;
import com.raceyourself.platform.models.Position;
import com.raceyourself.platform.sensors.SensorService;
import com.raceyourself.platform.models.EnhancedPosition;
import com.raceyourself.platform.models.Track;
import com.raceyourself.platform.utils.Stopwatch;
import com.raceyourself.platform.utils.MessagingInterface;
import com.roscopeco.ormdroid.ORMDroidApplication;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class GPSTracker implements LocationListener {

    private final Context mContext;
    
    // current state of device - stopped, accelerating etc
    private State state = State.STOPPED;
    
    // ordered list of recent positions, last = most recent
    private ArrayDeque<Position> recentPositions = new ArrayDeque<Position>(10);

    // position predictor (based on few last positions)
    private PositionPredictor positionPredictor = new PositionPredictor();
    private PositionPredictor  positionPredictor2D = new PositionPredictor();   
    // last known position
    Position gpsPosition = null;
    Position lastImportantPosition = null;

    // flag for whether we're actively tracking
    private boolean isTracking = false;

    private boolean indoorMode = false; // if true, we generate fake GPS updates

    private float minIndoorSpeed = 0.0f; // speed to fake with no user-stimulation
    private float maxIndoorSpeed = 4.16f; // speed to fake with continuous stimulation
    private float outdoorSpeed = 0.0f; // speed based on GPS & sensors, updated regularly

    private Track track; // The current track

    private double distanceTravelled = 0.0; // distance so far using speed/time in metres
    private double gpsDistance = 0.0; // distance so far between GPS points in metres

    private Stopwatch trackStopwatch = new Stopwatch(); // time so far in milliseconds
    private Stopwatch interpolationStopwatch = new Stopwatch(); // time so far in milliseconds

    // The minimum distance to change Updates in meters
    private static final long MIN_DISTANCE_CHANGE_FOR_UPDATES = 0; // 1 meters

    // The minimum time between updates in milliseconds
    private static final long MIN_TIME_BW_UPDATES = 1000; // 1 second

    private static final float MAX_TOLERATED_POSITION_ERROR = 21; // 21 metres
    private static final float EPE_SCALING = 0.5f; // if predicted positions lie within 0.5*EPE circle
                                                   // of reported GPS position, no need to store GPS pos.
    
    // time in milliseconds over which current position will converge with the
    // more accurate but non-continuous extrapolated GPS position
    private static final long DISTANCE_CORRECTION_MILLISECONDS = 1500; 
    
    // Save or not enhanced position. Used for collecting debug logs
    private static final boolean SAVE_ENHANCED_POSITION = false;

    // Declaring a Location Manager
    protected LocationManager locationManager;

    private Timer timer = new Timer();

    private GpsTask task;
    // Replay previously stored GPS track in file (for debugging purposes
    private ReplayGpsTask replayGpsTask;
    
    public Tick tick;
    
    private ServiceConnection sensorServiceConnection;
    private SensorService sensorService;

    // Auto-reset bearing as reported from UI
	private float autoBearing;
    

    /**
     * Creates a new GPSTracker object.
     * <p>
     * Initialises the database to store track logs and checks that the device has GPS enabled.
     * <p>
     */
    public GPSTracker(Context context) {
        this.mContext = context;

        // makes sure the database exists, if not - create it
        ORMDroidApplication.initialize(context);
        log.info("ORMDroid", "Initalized");
        
        // set elapsed time/distance to zero
        startNewTrack();
        
        // locationManager allows us to request/cancel GPS updates
        locationManager = (LocationManager)mContext.getSystemService(Service.LOCATION_SERVICE);
        
        // connect to the sensor service
        sensorServiceConnection = new ServiceConnection() {

            public void onServiceConnected(ComponentName className, IBinder binder) {
                sensorService = ((SensorService.SensorServiceBinder)binder).getService();
                log.debug("Bound to SensorService");
            }

            public void onServiceDisconnected(ComponentName className) {
                sensorService = null;
                log.debug("Unbound from SensorService");
            }
        };
        
        // Connect to sensorService (Needs doing each time the activity is resumed)
        onResume();
        
        // trigger either real (false) or fake (true) GPS updates
        setIndoorMode(false);
        
        tick = new Tick();

        positionPredictor2D.getBearingCalculator().setAlgorithm(BearingCalculator.Algorithm.GPS);
        if (SAVE_ENHANCED_POSITION) Helper.getInstance(mContext).exportDatabaseToCsv();

    }
    
    /**
     * Starts / re-starts the methods that poll GPS and sensors.
     * This is NOT an override - needs calling manually by containing Activity on app. resume
     * Safe to call repeatedly
     * 
     */
    public void onResume() {
        
        if (isIndoorMode()) {
            
            // stop listening for real GPS signals (doesn't matter if called repeatedly)
            locationManager.removeUpdates(this);
            
            // generate fake GPS updates if not already happening
            if (task == null) {
                log.info("Requesting fake GPS updates");
                task = new GpsTask();
                timer.scheduleAtFixedRate(task, 0, 1000);
            }
            // stop replaying
            if (replayGpsTask != null) {
            	replayGpsTask.cancel();
            	replayGpsTask = null;
            }
 
            // initialise speed to minIndoorSpeed
            outdoorSpeed = minIndoorSpeed;
            log.info("Indoor mode active");
            
        } else {

            // stop generating fake GPS updates
            if (task != null) {
                task.cancel();
                task = null;
            }
            
            if (replayGpsTask == null) {
            	replayGpsTask = new ReplayGpsTask(this);
            }

            // Replay previous GPS log
            if (replayGpsTask.isActive()) {
            	timer.scheduleAtFixedRate(replayGpsTask, 0, 1000);
                log.info("Replaying GPS log");
            } else {
                // request real GPS updates (doesn't matter if called repeatedly)

                String provider = getBestLocationProvider();  // should return 'gps' or 'remote_gps'
                if (provider != null) {
                    log.info("Requesting locations from provider " + provider);
                    locationManager.requestLocationUpdates(provider, MIN_TIME_BW_UPDATES,
                            MIN_DISTANCE_CHANGE_FOR_UPDATES, (LocationListener) this);
                    log.info("Outdoor mode active");
                } else {
                    log.info("Device doesn't have a GPS provider, cannot start outdoor mode.");
                }
            	
            }

        }
        
        // start polling the sensors
        mContext.bindService(new Intent(mContext, SensorService.class), sensorServiceConnection,
                        Context.BIND_AUTO_CREATE);
        if (tick == null) {
            tick = new Tick();
            timer.scheduleAtFixedRate(tick, 0, 30);
        }
    }


    private String getBestLocationProvider() {
        List<String> l = locationManager.getAllProviders();
        Criteria criteria = new Criteria();
        criteria.setAccuracy(Criteria.ACCURACY_FINE);
        String provider = locationManager.getBestProvider(criteria, true);
        if (provider.equals("gps") || provider.equals("remote_gps")) {
            return provider;
        } else {
            return null;
        }
    }

    private String getBestEnabledLocationProvider() {
        String provider = getBestLocationProvider();
        if (provider != null && locationManager.isProviderEnabled(provider)) {
            log.trace("Location provider " + provider + " is enabled");
            return provider;
        } else {
            log.debug("No GPS providers are enabled (network may be, but is not precise enough for the game)");
            return null;
        }
    }

    /**
     * Stops the methods that poll GPS and sensors
     * This is NOT an override - needs calling manually by containing Activity on app. resume
     * Safe to call repeatedly
     */
    public void onPause() {
        
        // stop requesting real GPS updates (doesn't matter if called repeatedly)
        locationManager.removeUpdates(this);
        
        // stop generating fake GPS updates
        if (task != null) {
            task.cancel();
            task = null;
        }

        if (replayGpsTask != null) {
        	replayGpsTask.cancel();
        	replayGpsTask = null;
        }

        
        // stop polling the sensors
        if (tick != null) {
            tick.cancel();
            tick = null;
        }
        mContext.unbindService(sensorServiceConnection);
        
    }

    // Clean up, stop listening for positions, unbind from sensor service
    // This instance won't be much use after close() has been called
    public void close() {

        // stop the task
        if (task != null) {
            task.cancel();
            task = null;
        }

        // stop requesting real GPS updates (doesn't matter if called repeatedly)
        locationManager.removeUpdates(this);

        // unbind from sensor service
        mContext.unbindService(sensorServiceConnection);

    }
    
    
    
    public void startNewTrack() {
        
        log.debug("GPS tracker reset");
        
        trackStopwatch.stop();
        trackStopwatch.reset();
        interpolationStopwatch.stop();
        interpolationStopwatch.reset();
        isTracking = false;
        distanceTravelled = 0.0;
        gpsDistance = 0.0;
        outdoorSpeed = 0.0f;
        state = State.STOPPED;
        recentPositions.clear();
        
        track = null;
    }
    

    /**
     * Returns the position of the device as a Position object, whether or not we are tracking.
     * 
     * @return position of the device
     */
    public Position getCurrentPosition() {
        return gpsPosition;
        //TODO: need to extrapolate based on sensors/bike-wheel/SLAM
    }

    public Position getPredictedPosition() {
        return positionPredictor2D.predictPosition(System.currentTimeMillis());
    }


    /**
     * Start recording distance and time covered by the device.
     * <p>
     * Ideally this should only be called once the device has a GPS fix, which can be checked using
     * hasPosition().
     */
    public void startTracking() {
        
        log.debug("startTracking() called, hasPosition() is " + hasPosition());
        
        if (track == null) {
            AccessToken me = AccessToken.get();
            track = new Track(me.getUserId(), "Test");
            log.debug("New track created with user id " + me.getUserId());
            track.save();
            log.debug("New track ID is " + track.getId());                
        }
        
        // Set track for temporary position
        if (gpsPosition != null) gpsPosition.setTrack(track);
        
        // if we already have a position, start the stopwatch, if not it'll
        // be triggered when we get our first decent GPS fix
        //if (hasPosition()) {
            trackStopwatch.start();
            interpolationStopwatch.start();
        //}
        if (replayGpsTask != null)
        	replayGpsTask.start();
        isTracking = true;

    }

    /**
     * Stop recording distance and time covered by the device.
     * <p>
     * This will not reset the cumulative distance/time values, so it can be used to pause (e.g.
     * when the user is stopped to do some stretches). Call startTracking() to continue from where
     * we left off, or create a new GPSTracker object if a full reset is required.
     */
    public void stopTracking() {
        log.debug("stopTracking() called");
        isTracking = false;
        trackStopwatch.stop();
        interpolationStopwatch.stop();
        positionPredictor.stopTracking();
        positionPredictor2D.stopTracking();
    }

    /**
     * Finalize track and reset tracker.
     *
     * @return completed track
     */
    public Track saveTrack() {
        Track t = track.complete(distanceTravelled, trackStopwatch.elapsedTimeMillis(), isIndoorMode());
        startNewTrack();
        return t;
    }
    
    /**
     * Is the GPSTracker in indoor mode? If so, it'll fake GPS positions. See also setIndoorMode().
     * 
     * @return true if in indoor mode, false otherwise. Default is false.
     */
    public boolean isIndoorMode() {
        return indoorMode;
    }

    /**
     * indoorMode == false => Listen for real GPS positions
     * indoorMode == true => Generate fake GPS positions
     * See also setIndoorSpeed().
     * 
     * @param indoorMode: true for indoor, false for outdoor.
     */
    public void setIndoorMode(boolean indoorMode) {
        
        // if we are changing mode, clear the position buffer so we don't record
        // a huge jump from a fake location to a real one or vice-versa
        if (indoorMode != this.indoorMode) {
            recentPositions.clear();
            this.indoorMode = indoorMode;
        }
        
        // start listening to relevant GPS/sensors for new mode
        onResume();
    }

    /**
     * Sets the speed for indoor mode from the TargetSpeed enum
     * of reference speeds. See also isIndoorMode().
     * 
     * @param indoorSpeed enum
     */
    public void setIndoorSpeed(FauxTargetTracker.TargetSpeed indoorSpeed) {
        this.maxIndoorSpeed = indoorSpeed.speed();
    }
    
    /**
     * Sets the speed for indoor mode to the supplied float value,
     * measured in m/s. See also isIndoorMode().
     * 
     * @param indoorSpeed in m/s
     */
    public void setIndoorSpeed(float indoorSpeed) {
        this.maxIndoorSpeed = indoorSpeed;
    }    
    
    /**
     * Call when the user wants to reset which way is forward. Useful when device is not moving (as
     * GPS bearing doesn't work in that case). Used to find the forward-backward axis in the
     * acceleration calc.
     */
    public void resetGyros() {
        // empty for now, until we introduce sensor code
    }
    
    /**
     * Task to regularly generate fake position data when in indoor mode.
     * startLogging() triggers starts the task, stopLogging() ends it.
     */
    private class GpsTask extends TimerTask {

        private double[] drift = { 0f, 0f }; // lat, long
        private double lastElapsedDistance = getElapsedDistance();
        private float bearing = -1;

        public void run() {

            // Fake movement in direction device is pointing at a speed
            // determined by how much the user is shaking it (uses same sensor
            // logic / state machine as outdoor mode)
            if (sensorService != null) {
                if (bearing == -1) {
                    // fix bearing at initial device yaw
                    bearing = -getYaw() % 360;
                }
                drift[0] += (getElapsedDistance() - lastElapsedDistance) * Math.cos(bearing) / 111229d;
                drift[1] += (getElapsedDistance() - lastElapsedDistance) * Math.sin(bearing) / 111229d;
            }

            // Fake location
            Location location = new Location("");
            location.setTime(System.currentTimeMillis());
            location.setLatitude(location.getLatitude() + drift[0]);
            location.setLongitude(location.getLongitude() + drift[1]);
            location.setSpeed(outdoorSpeed);
            location.setBearing(bearing);

            // Broadcast the fake location the local listener only (otherwise
            // risk confusing other apps!)
            onLocationChanged(location);
            
            lastElapsedDistance = getElapsedDistance();
        }
    }

    /**
     * Function to check GPS enabled
     * 
     * @return boolean
     * @deprecated
     */
    public boolean canGetPosition() {
        return recentPositions.size() > 0;
    }
    
    /**
     * Do we have a GPS fix yet? If false, wait until it is true before expecting some of the other
     * functions in this class to work - specifically startTracking() and getCurrentPosition()
     * 
     * @return true if we have a position fix
     */
    public boolean hasPosition() {
        // if the latest position is fresh, return true
        if (gpsPosition != null) {
            if (isIndoorMode() && gpsPosition.getEpe() == 0) {
                // we check EPE==0 to discard any real positions left from
                // before an indoorMode switch
                //log.debug("We have a fake position ready to use");
                return true;
            }
            if (!isIndoorMode() && isGpsEnabled() && gpsPosition.getEpe() > 0 && gpsPosition.getEpe() < MAX_TOLERATED_POSITION_ERROR) {
                // we check EPE>0 to discard any fake positions left from before
                // an indoorMode switch
                //log.debug("We have a real position ready to use with error " + gpsPosition.getEpe() + "m");
                return true;
            }
        }
        if (replayGpsTask != null && replayGpsTask.isActive()) {
            //log.debug("We have a pre-recorded position ready to use with error " + gpsPosition.getEpe() + "m");
            return true;
        }

        //log.debug("We don't currently have a valid position");
        return false;

    }

    public boolean hasPoorPosition() {
        // if the latest position is less than 1 minute old
        // TODO: test this
        return (gpsPosition != null && gpsPosition.getDeviceTimestamp() > System.currentTimeMillis() - 60000);
    }

    // Broadcast new state to unity3D and to the log
    //broadcastToUnity();
    
    
    public boolean isGpsEnabled() {
        return (getBestEnabledLocationProvider() != null);
    }

    
    /**
     * Is the GPS tracker currently recording the device's movement? See also startTracking() and
     * stopTracking().
     * 
     * @return true if the device is recording elapsed distance/time and position data. False
     *         otherwise.
     */
    public boolean isTracking() {
        return isTracking;
    }
    

    /**
     * Called by the android system when new GPS data arrives.
     * <p>
     * This method does all the clever processing of the raw GPS data to provide an accurate
     * location and bearing of the device. It also increments the elapsedDistance when isTracking is
     * true and the device is moving.
     */
    @Override
    public void onLocationChanged(Location location) {

        // ignore positions from 'bad' location providers
        if (getBestEnabledLocationProvider() == null) return;

        // get the latest GPS position
        Position tempPosition = new Position(track, location);
        log.debug("New position with error " + tempPosition.getEpe());
        
        // update current position
        // TODO: track error, and throw out positions with significantly worse error than the running average
        Position lastPosition = gpsPosition;
        gpsPosition = tempPosition;
        
        // stop here if we're not tracking
        if (!isTracking) {
            //broadcastToUnity();
            return;
        }
        
        // keep track of the pure GPS distance moved
        if (lastPosition != null && state != State.STOPPED) {
            // add dist between last and current position
            // don't add distance if we're stopped, it's probably just drift 
            gpsDistance += Position.distanceBetween(lastPosition, gpsPosition);
        }
        interpolationStopwatch.reset();

        // add position to the buffer for later use
//        log.debug("Using position as part of track");
        if (recentPositions.size() >= 10) {
            // if the buffer is full, discard the oldest element
            recentPositions.removeFirst();
        }
        recentPositions.addLast(gpsPosition); //recentPositions.getLast() now points at gpsPosition.
        
        EnhancedPosition enhancedGpsPosition = new EnhancedPosition(gpsPosition, sensorService.getAzimuth(), autoBearing);
        if (SAVE_ENHANCED_POSITION) enhancedGpsPosition.save();
        positionPredictor2D.updatePosition(enhancedGpsPosition);
        
        // calculate corrected bearing
        // this is more accurate than the raw GPS bearing as it averages several recent positions
        correctBearing(gpsPosition);
        
        // work out whether the position is important for recreating the track or
        // if it could have been predicted from previous positions
        // TODO: add checks for significant change in speed/bearing
        if (lastImportantPosition == null) {
            // important position - first in track
            gpsPosition.setStateId(state.ordinal());
            lastImportantPosition = gpsPosition;
        } else if (Math.abs(lastPosition.getStateId()) != state.ordinal()) {
            // change in state, positions either side of change are important
            if (lastPosition.getStateId() < 0) lastPosition.setStateId(-1*lastPosition.getStateId());
            gpsPosition.setStateId(state.ordinal());
            lastImportantPosition = gpsPosition;
        } else {
            // no change in state, see if we could have predicted current position
            Position predictedPosition = Position.predictPosition(lastImportantPosition, (gpsPosition.device_ts - lastImportantPosition.device_ts));
            if (predictedPosition == null || 
                    Position.distanceBetween(gpsPosition, predictedPosition) > ((gpsPosition.epe + 1) * EPE_SCALING)) {
                // we cannot predict current position from the last important one
                // mark the previous position as important (end of straight line) if not already
                if (lastPosition.getStateId() < 0) {
                    lastPosition.setStateId(-1*lastPosition.getStateId());
                    lastImportantPosition = gpsPosition;
                }
                // try to predict current position again (from the new lastImportantPosition)
                predictedPosition = Position.predictPosition(lastImportantPosition, (gpsPosition.device_ts - lastImportantPosition.device_ts));
                if (predictedPosition == null || 
                        Position.distanceBetween(gpsPosition, predictedPosition) > ((gpsPosition.epe + 1) * EPE_SCALING)) {
                    // error still too big (must be sharp corner, not gradual curve) so mark this one as important too
                    gpsPosition.setStateId(state.ordinal());
                    lastImportantPosition = gpsPosition;
                }
            } else {
                // not important, we could have predicted it
                gpsPosition.setStateId(-1*state.ordinal());
            }
        }
        
        gpsPosition.save(); // adds GUID
        log.debug("New GPS position saved");
        notifyPositionListeners();
        //sendToUnityAsJson(gpsPosition, "NewPosition");
        //logPosition();
        
    }
    
    // calculate corrected bearing
    // this is more accurate than the raw GPS bearing as it averages several recent positions
    private void correctBearing(Position gpsPosition) {
        
        // temporary workaround whilst we don't use the bearing
        // see JIRA ticket 
 //       gpsPosition.setCorrectedBearing(gpsPosition.bearing);
        if (sensorService == null) return; // can't correct if no sensors bound
        
        // interpolate last few positions 
        positionPredictor.updatePosition(new EnhancedPosition(gpsPosition, sensorService.getAzimuth(), autoBearing));
        Float correctedBearing = positionPredictor.predictBearing(gpsPosition.getDeviceTimestamp());
        if (correctedBearing != null) {
          gpsPosition.setCorrectedBearing(correctedBearing);
//          // TODO: remove these fields from Position class
//          gpsPosition.setCorrectedBearingR((float)1.0);
//          gpsPosition.setCorrectedBearingSignificance((float)1.0);
        }    
    }
    
    private void broadcastToUnity() {
        JSONObject data = new JSONObject();
        try {
            data.put("hasPosition", hasPosition());
            data.put("currentSpeed", getCurrentSpeed());  
            
            data.put("isTracking", isTracking());
            data.put("elapsedDistance", getElapsedDistance());
            data.put("elapsedTime", getElapsedTime());     
            
            data.put("hasBearing", hasBearing());     
            data.put("currentBearing", getCurrentBearing());            
        } catch (JSONException e) {
            log.error(e.getMessage());
        }
        MessagingInterface.sendMessage("script holder", "NewGPSPosition", data.toString());
    }
    
    private void logPosition() {
        log.debug("New elapsed distance is: " + getElapsedDistance());
        log.debug("Current speed estimate is: " + getCurrentSpeed());
        if (hasBearing()) log.debug("Current bearing estimate is: " + getCurrentBearing());
        log.debug("New elapsed time is: " + getElapsedTime());
        log.debug("\n");  
    }

    /**
     * Returns a boolean describing whether the device is moving on a known bearing. Use before getCurrentBearing() if you don't want to handle the -999.0f values returned by that method.
     * 
     * @return true/false - is the device moving on a known bearing?
     */
    public boolean hasBearing() {
        // TODO: is this function still needed? getCurrentBearing() may be used instead
        return (positionPredictor.predictBearing(System.currentTimeMillis()) != null);
    }
    
    /**
     * Calculates the device's current bearing based on the last few GPS positions. If unknown (e.g.
     * the device is not moving) returns -999.0f.
     * 
     * @return bearing in degrees
     */
    public float getCurrentBearing() {
        Float bearing = positionPredictor.predictBearing(System.currentTimeMillis());
        if (bearing != null) {
            return bearing;
        } else {
            return -999.0f;
        }
    }

    public void notifyAutoBearing(float autoBearing) {
    	this.autoBearing = autoBearing;
    }
    
    /**
     * Called internally by android. Not currently used.
     */
    @Override
    public void onProviderDisabled(String provider) {
        log.info("User disabled location provider " + provider);
        onResume();
    }

    /**
     * Called internally by android. Not currently used.
     */
    @Override
    public void onProviderEnabled(String provider) {
        log.info("User enabled location provider " + provider);
        onResume();
    }
    
    /**
     * Called internally by android. Not currently used.
     */
    @Override
    public void onStatusChanged(String provider, int status, Bundle extras) {
        log.info("onStatusChanged: " + status);
        onResume();
    }

    /**
     * Returns the current speed of the device in m/s, or zero if we think we're stopped.
     * 
     * @return speed in m/s
     */
    public float getCurrentSpeed() {
        return outdoorSpeed; // calculated regularly using GPS & sensors
    }
    
    /**
     * Computes forward-vector in real-world co-ordinates
     * Uses GPS bearing if available (needs device to be moving forward), otherwise magnetometer (assumes device is facing forward)
     * @return [x,y,x] forward vector
     */
    private float[] getForwardVector() {
        float[] forwardVector = {0f,1f,0f};
        if (sensorService == null) return forwardVector;
        float bearing;
        //if (hasBearing()) {
        //    bearing = getCurrentBearing(); // based on GPS points
        //} else {
            bearing = (float)(sensorService.getYprValues()[0]);  // based on device orientation/magnetometer, converted to degrees            
        //}
        forwardVector[0] = (float)Math.sin(bearing); //note bearing is in radians
        forwardVector[1] = (float)Math.cos(bearing);        
        return forwardVector;
    }
    
    public float getYaw() {
        if (sensorService == null) return 0.0f;
        return (float)(sensorService.getGyroDroidQuaternion().toYpr()[0] * 180/Math.PI) % 360;  // based on device orientation/magnetometer, converted to degrees
    }
    
    public float getForwardAcceleration() {
        if (sensorService == null) return 0.0f;
        return sensorService.getAccelerationAlongAxis(getForwardVector());
    }
    
    public float getTotalAcceleration() {
        if (sensorService == null) return 0.0f;
        return sensorService.getTotalAcceleration();
    }
    


    /**
     * Returns the distance covered by the device (in metres) since startTracking was called
     * 
     * @return Distance covered, in metres
     */
    public double getElapsedDistance() {
        return distanceTravelled;
    }
    
    public double getGpsDistance() {
        return gpsDistance;
    }
    
    public float getGpsSpeed() {
        if (gpsPosition != null) {
            return gpsPosition.getSpeed();
        }
        return 0.0f;
    }
    
    public State getState() {
        return state;
    }

    /**
     * Returns the cumulative time the isTracking() has been true. See also startTracking() and stopTracking(). 
     * 
     * @return cumulative time in milliseconds
     */
    public long getElapsedTime() {
        return trackStopwatch.elapsedTimeMillis();
    }
    
    private float meanDfa = 0.0f; // mean acceleration change in the forward-backward axis
    private float meanDta = 0.0f; // mean acceleration change (all axes combined)
    private float meanTa = 0.0f; // mean acceleration (all axes combined)
    private float sdTotalAcc = 0.0f; // std deviation of total acceleration (all axes)
    private float maxDta = 0.0f; // max change in total acceleration (all axes)
    private double extrapolatedGpsDistance = 0.0; // extraploated distance travelled (based on sensors) to add to GPS distance
    
    public float getMeanDfa() {
        return meanDfa;
    }
    
    public float getMeanDta() {
        return meanDta;
    }
    
    public float getSdTotalAcc() {
        return sdTotalAcc;
    }
    
    public float getMaxDta() {
        return maxDta;
    }
    
    public double getExtrapolatedGpsDistance() {
        return extrapolatedGpsDistance;
    }
    
    public Track getTrack() {
        return track;
    }
    
    public class Tick extends TimerTask {

        private long tickTime;
        private long lastTickTime;
        private float gpsSpeed = 0.0f;
        private float lastForwardAcc = 0.0f;
        private float lastTotalAcc = 0.0f;
        private DescriptiveStatistics dFaStats = new DescriptiveStatistics(10);
        private DescriptiveStatistics dTaStats = new DescriptiveStatistics(10);
        private DescriptiveStatistics taStats = new DescriptiveStatistics(10);

        public void run() {
            
            // need to wait for sensorService to bind
            if (sensorService == null) return;

            if (lastTickTime == 0) {
                lastTickTime = System.currentTimeMillis();
                return;
            }
            tickTime = System.currentTimeMillis();

            // update buffers with most recent sensor sample
            dFaStats.addValue(Math.abs(getForwardAcceleration()-lastForwardAcc));
//            rmsForwardAcc = (float)Math.sqrt(0.95*Math.pow(rmsForwardAcc,2) + 0.05*Math.pow(getForwardAcceleration(),2));
            taStats.addValue(sensorService.getTotalAcceleration());
            dTaStats.addValue(Math.abs(sensorService.getTotalAcceleration()-lastTotalAcc));
            
            // compute some stats on the buffers
            // TODO: frequency analysis
            meanDfa = (float)dFaStats.getMean();
            meanDta = (float)dTaStats.getMean();
            meanTa = (float)taStats.getMean();
            maxDta = (float)dTaStats.getMax();
            sdTotalAcc = (float)taStats.getStandardDeviation();
            gpsSpeed = getGpsSpeed();
            
            // update state
            // gpsSpeed = -1.0 for indoorMode to prevent entry into
            // STEADY_GPS_SPEED (just want sensor_acc/dec)
            State lastState = state;
            state = state.nextState(meanDta, (isIndoorMode() ? -1.0f : gpsSpeed));
            
            // save for next loop
            lastForwardAcc = getForwardAcceleration();
            lastTotalAcc = sensorService.getTotalAcceleration();
            
            // adjust speed
            switch (state) {
                case STOPPED:
                    // speed is zero!
                    outdoorSpeed = 0.0f;
                    break;
                case SENSOR_ACC:
                    // increase speed at 1.0m/s/s (typical walking acceleration)
                    float increment = 1.0f * (tickTime - lastTickTime) / 1000.0f;

                    // cap speed at some sensor-driven speed, and up to maxIndoorSpeed indoors
                    // TODO: freq analysis to more accurately identify speed
                    float sensorSpeedCap = meanTa;
                    //if (isIndoorMode() && sensorSpeedCap > maxIndoorSpeed)
                    sensorSpeedCap = maxIndoorSpeed;
                    
                    if (outdoorSpeed < sensorSpeedCap) {
                        // accelerate
                        outdoorSpeed += increment;
                    } else if (outdoorSpeed > 0) {
                        // decelerate
                        outdoorSpeed -= increment;
                    }
                    break;
                case STEADY_GPS_SPEED:
                    // smoothly adjust speed toward the GPS speed
                    // TODO: maybe use acceleration sensor here to make this more responsive?
                    if (!isIndoorMode()) {
                        outdoorSpeed = 0.9f * outdoorSpeed + 0.1f * gpsSpeed;
                    }
                    break;
                case COAST:
                    // maintain constant speed
                    break;
                case SENSOR_DEC:
                    // decrease speed at 2.0 m/s/s till we are stopped (or 
                    // minIndoorSpeed in indoorMode)
                    float decrement = 2.0f * (tickTime - lastTickTime) / 1000.0f;
                    if (outdoorSpeed -decrement > (isIndoorMode() ? minIndoorSpeed : 0.0f)) {
                        outdoorSpeed -= decrement;
                    } else {
                        outdoorSpeed = (isIndoorMode() ? minIndoorSpeed : 0.0f);
                    }
                    break;
            }

            // update distance travelled
            if (isTracking()) {
                
                // extrapolate distance based on last known fix + outdoor speed
                // accurate and responsive, but not continuous (i.e. avatar would 
                // jump backwards/forwards each time a new fix came in)
                float extrapolationTime = interpolationStopwatch.elapsedTimeMillis() / 1000.0f;
                if (extrapolationTime > 3.0f) extrapolationTime = 3.0f;  // cap at 3s
                extrapolatedGpsDistance = gpsDistance
                        + outdoorSpeed * extrapolationTime;
                
                // calculate the speed we need to move at to make
                // distanceTravelled converge with extrapolatedGpsDistance over
                // a period of DISTANCE_CORRECTION_MILLISECONDS
                double correctiveSpeed = outdoorSpeed + 
                        (extrapolatedGpsDistance - distanceTravelled) * 1000.0 / DISTANCE_CORRECTION_MILLISECONDS;
                
                // increment distance traveled by camera at this new speed
                distanceTravelled += correctiveSpeed * (tickTime - lastTickTime) / 1000.0;
                
                if (state != lastState) notifyPositionListeners();
                
            }
            
            lastTickTime = tickTime;
        }
    }
    
    public enum State {
        UNKNOWN {
            // error state, shouldn't really be here
            @Override
            public State nextState(float rmsForwardAcc, float gpsSpeed) {
                return this;
            }
        },
        
        STOPPED {
            @Override
            public State nextState(float rmsForwardAcc, float gpsSpeed) {
                if (rmsForwardAcc > ACCELERATE_THRESHOLD) {
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","SENSOR_ACC");
                    return State.SENSOR_ACC.setEntryTime(System.currentTimeMillis());
                } else {
                    return this;
                }
            }
        },
        
        SENSOR_ACC {
            @Override
            public State nextState(float rmsForwardAcc, float gpsSpeed) {
                if (gpsSpeed > 0.0f) {
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","STEADY_GPS_SPEED");
                    return State.STEADY_GPS_SPEED.setEntryTime(System.currentTimeMillis());
                } else if (rmsForwardAcc < DECELERATE_THRESHOLD) {
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","SENSOR_DEC");
                    return State.SENSOR_DEC.setEntryTime(System.currentTimeMillis());
                } else {
                    return this;
                }
            }
        },
        
        STEADY_GPS_SPEED {
            public State nextState(float rmsForwardAcc, float gpsSpeed) {
                if (rmsForwardAcc < DECELERATE_THRESHOLD) {
                    // if the sensors suggest the device has stopped moving, decelerate
                    // TODO: pick up when we're in a tunnel and need to coast
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","SENSOR_DEC");
                    return State.SENSOR_DEC.setEntryTime(System.currentTimeMillis());
                } else if (gpsSpeed == 0.0f) {
                    // if we've picked up a dodgy GPS position, maintain const speed
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","COAST");
                    return State.COAST.setEntryTime(System.currentTimeMillis());
                } else {
                    return this;
                }                
            }
        },
        
        COAST {
            public State nextState(float rmsForwardAcc, float gpsSpeed) {
                if (rmsForwardAcc < DECELERATE_THRESHOLD) {
                    // if sensors suggest the device has stopped moving, decelerate
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","SENSOR_DEC");
                    return State.SENSOR_DEC.setEntryTime(System.currentTimeMillis());
                } else if (gpsSpeed > 0.0f) {
                    // we've picked up GPS again
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","STEADY_GPS_SPEED");
                    return State.STEADY_GPS_SPEED.setEntryTime(System.currentTimeMillis());
                } else {
                    return this;
                }                
            }            
        },
        
        SENSOR_DEC {
            public State nextState(float rmsForwardAcc, float gpsSpeed) {
                if (gpsSpeed == 0.0f) {
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","STOPPED");
                    return State.STOPPED.setEntryTime(System.currentTimeMillis());
                } else if (getTimeInState() > 3000) {
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","STEADY_GPS_SPEED");
                    return State.STEADY_GPS_SPEED.setEntryTime(System.currentTimeMillis());
                } else if (rmsForwardAcc > ACCELERATE_THRESHOLD) {
                    //UnityInterface.unitySendMessage("Platform", "PlayerStateChange","SENSOR_ACC");
                    return State.SENSOR_ACC.setEntryTime(System.currentTimeMillis());
                } else {
                    return this;
                }
            }
        };
        
        private long entryTime;
        private final static float ACCELERATE_THRESHOLD = 0.45f;
        private final static float DECELERATE_THRESHOLD = 0.35f;
        
        public abstract State nextState(float rmsForwardAcc, float gpsSpeed);
        
        public State setEntryTime(long t) {
            this.entryTime = t;
            return this;
        }
        
        public long getTimeInState() {
            return System.currentTimeMillis() - entryTime;
        }
    }
    
    private Set<PositionListener> positionListeners = new HashSet<PositionListener>();
    public void registerPositionListener(PositionListener p) {
        if (!positionListeners.contains(p)) positionListeners.add(p);
    }
    
    public void deregisterPositionListener(PositionListener p) {
        if (positionListeners.contains(p)) positionListeners.remove(p);
    }
    
    private void notifyPositionListeners() {
        //log.debug("Notifying " + positionListeners.size() + " position listeners");
        for (PositionListener p : positionListeners) {
            p.newPosition();
        }
    }
    
    public interface PositionListener {
        public void newPosition();
    }

}
