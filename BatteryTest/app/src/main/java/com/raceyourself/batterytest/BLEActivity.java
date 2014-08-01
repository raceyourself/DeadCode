package com.raceyourself.batterytest;

import android.bluetooth.BluetoothAdapter;
import android.content.Intent;
import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import com.estimote.sdk.Beacon;
import com.estimote.sdk.BeaconManager;
import com.estimote.sdk.Region;

import java.util.Date;
import java.util.List;

import lombok.extern.slf4j.Slf4j;

/**
 * Created by Amerigo on 01/08/2014.
 */
@Slf4j
public class BLEActivity extends BaseTestActivity {

    // beacon recognition
    private BeaconManager beaconManager;

    private static final Region ALL_ESTIMOTE_BEACONS_REGION = new Region("rid", null, null, null);
    private static final int REQUEST_ENABLE_BT = 1234;

    private TextView beaconStateTextview;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTagAndName("BLEActivity", "BLE");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ble);

        beaconStateTextview = (TextView)findViewById(R.id.beaconStateTextview);

        // Configure BeaconManager.
        beaconManager = new BeaconManager(this);
        beaconManager.setForegroundScanPeriod(100, 1000);
        beaconManager.setBackgroundScanPeriod(100, 1000);
        beaconManager.setRangingListener(new BeaconManager.RangingListener() {
            @Override
            public void onBeaconsDiscovered(Region region, final List<Beacon> newBeacons) {
                // Note that results are not delivered on UI thread.
                for (Beacon b : newBeacons) {
                    // want to check mac address but need real beacon for this
                    // try getProximityUUID! [tried it, no better]
                    //if (b.getMacAddress().equals("62:A4:6E:1B:9E:94") {
                    if (true) {
                        //Log.d(TAG, "Beacon RSSI is " + currentBeacon.getRssi());
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                beaconStateTextview.setText("Beacon found! Last update at " + new Date().toString());
                            }
                        });
                        return;
                    }
                }
            }
        });
    }

    public void onStart() {
        super.onStart();

        // Check if device supports Bluetooth Low Energy.
        if (!beaconManager.hasBluetooth()) {
            Toast.makeText(this, "Device does not have Bluetooth Low Energy", Toast.LENGTH_LONG).show();
            return;
        }

        // If Bluetooth is not enabled, let user enable it.
//        if (!beaconManager.isBluetoothEnabled()) {
//            Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
//            startActivityForResult(enableBtIntent, REQUEST_ENABLE_BT);
//        } else {
            connectToService();
//        }
    }

    public void onStop() {
        super.onStop();
        try {
            beaconManager.stopRanging(ALL_ESTIMOTE_BEACONS_REGION);
        } catch (RemoteException e) {
            Log.d(tag, "Error while stopping ranging", e);
        }
    }

    private void connectToService() {
        beaconManager.connect(new BeaconManager.ServiceReadyCallback() {
            @Override
            public void onServiceReady() {
                try {
                    beaconManager.startRanging(ALL_ESTIMOTE_BEACONS_REGION);
                } catch (RemoteException e) {
                    Toast.makeText(BLEActivity.this, "Cannot start ranging, something terrible happened",
                            Toast.LENGTH_LONG).show();
                    Log.e(tag, "Cannot start ranging", e);
                }
            }
        });
    }

    @Override
    public void onDestroy() {
        beaconManager.disconnect();
        super.onDestroy();
    }

//    private enum State {
//        OUT (0, 0l) {
//            public State nextState(Beacon beacon, String newProduct) {
//                if (beacon != null && beacon.getRssi() > ENTRY_RSSI_THRESHOLD) {
//                    return State.ENTERING.enter(activity, newProduct);
//                } else {
//                    return this;
//                }
//            }
//        },
//        ENTERING (ENTRY_HYTERESIS, 0l) {
//            public State nextState(Beacon beacon, String newProduct) {
//                if (beacon == null || beacon.getRssi() <= EXIT_RSSI_THRESHOLD) {
//                    return State.OUT.enter(activity, newProduct);
//                } else if (transitionCountdown.decrementAndGet() <= 0) {
//                    return State.IN.enter(activity, newProduct);
//                } else {
//                    return this;
//                }
//            }
//        },
//        PRODUCT (0, MIN_PRODUCT_DISPLAY_TIME) {
//            public State nextState(Beacon beacon, String newProduct) {
//                if (newProduct != null && (lastProduct == null || !newProduct.equals(lastProduct))) {
//                    return State.PRODUCT.enter(activity, newProduct);  // immediately switch to new product
//                } else if (System.currentTimeMillis() < entryTimestamp + minTimeInState) {
//                    // keep question up for long enough
//                    return this;
//                } else if (beacon == null || beacon.getRssi() <= EXIT_RSSI_THRESHOLD) {
//                    return State.EXITING.enter(activity, newProduct);
//                } else if (newProduct == null) {
//                    return State.IN.enter(activity, newProduct);
//                } else {
//                    return State.QUESTION.enter(activity, newProduct);
//                }
//            }
//        },
//        QUESTION (0, MIN_QUESTION_DISPLAY_TIME) {
//            public State nextState(Beacon beacon, String newProduct) {
//                if (newProduct != null && (lastProduct == null || !newProduct.equals(lastProduct))) {
//                    return State.PRODUCT.enter(activity, newProduct);  // immediately switch to new product
//                } else if (System.currentTimeMillis() < entryTimestamp + minTimeInState) {
//                    // keep question up for long enough
//                    return this;
//                } else if (beacon == null || beacon.getRssi() <= EXIT_RSSI_THRESHOLD) {
//                    return State.EXITING.enter(activity, newProduct);
//                } else if (newProduct != null) {
//                    return State.PRODUCT.enter(activity, newProduct);
//                } else {
//                    return State.IN.enter(activity, newProduct);
//                }
//            }
//        },
//        IN (0, 0l) {
//            public State nextState(Beacon beacon, String newProduct) {
//                if (newProduct != null && (lastProduct == null || !newProduct.equals(lastProduct))) {
//                    return State.PRODUCT.enter(activity, newProduct);  // immediately switch to new product
//                } else if (System.currentTimeMillis() < entryTimestamp + minTimeInState) {
//                    // wait for user to take in beacon message, video background etc before allowing state change
//                    return this;
//                } else if (beacon == null || beacon.getRssi() <= EXIT_RSSI_THRESHOLD) {
//                    return State.EXITING.enter(activity, newProduct);
//                } else {
//                    return this;
//                }
//            }
//        },
//        EXITING (EXIT_HYSTERESIS, 0l) {
//            public State nextState(Beacon beacon, String newProduct) {
//                if (beacon != null && beacon.getRssi() > EXIT_RSSI_THRESHOLD) {
//                    return State.IN.nextState(beacon, newProduct);  // no enter, don't want to reset stuff. Call nextState so we don't pause responsiveness for a loop.
//                } else if (transitionCountdown.decrementAndGet() <= 0) {
//                    return State.OUT.enter(activity, newProduct);
//                } else {
//                    return this;
//                }
//            }
//        };
//
//        BLEActivity activity;  // so we can manipulate it's views
//        long entryTimestamp;  //ms
//        long minTimeInState;  //ms
//        int hysteresis;  // ticks
//        AtomicInteger transitionCountdown = new AtomicInteger(0);
//        static String lastProduct = null;
//
//        State(int hysteresis, long minTimeInState) {
//            this.hysteresis = hysteresis;
//            this.minTimeInState = minTimeInState;
//        }
//
//        public abstract State nextState(Beacon beacon, String newProduct);
//
//        private State enter(BLEActivity a, String newProduct) {
//            Log.i("RaceYourself", "State = " + this.name());
//            this.activity = a;
//            this.entryTimestamp = System.currentTimeMillis();
//            this.transitionCountdown.set(hysteresis);
//            switch (this) {
//                case IN : {
//                    activity.endQuestion();
//                    activity.displayBeacon();
//                    activity.startImageRecognition();
//                    break;
//                }
//                case PRODUCT : {
//                    activity.endQuestion();
//                    if (newProduct != null && (lastProduct == null || !newProduct.equals(lastProduct))) activity.displayProduct();  // don't need to redisplay when iterating Qs o the same product
//                    break;
//                }
//                case QUESTION : {
//                    activity.playQuestion();
//                    break;
//                }
//                case OUT : {
//                    activity.currentProduct = null;
//                    activity.stopImageRecognition();
//                    activity.clearScreen();
//                    break;
//                }
//                default : break;
//            }
//            lastProduct = newProduct;  // remember last one so we can detect a switch
//            return this;
//        }
//    }
}
