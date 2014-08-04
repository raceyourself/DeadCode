package com.raceyourself.batterytest;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;
import android.widget.TextView;

import com.raceyourself.platform.sensors.Quaternion;
import com.raceyourself.platform.sensors.SensorService;

public class SensorActivity extends BaseTestActivity {

    SensorService sensorService;

    TextView xRotation;
    TextView yRotation;
    TextView zRotation;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTagAndName("SensorActivity", "Sensor");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sensors);

        xRotation = (TextView)findViewById(R.id.x_rotation);
        yRotation = (TextView)findViewById(R.id.y_rotation);
        zRotation = (TextView)findViewById(R.id.z_rotation);

        bindService(new Intent(this, SensorService.class), sensorServiceConnection,
                Context.BIND_AUTO_CREATE);

    }

    @Override
    public void onDestroy() {
        unbindService(sensorServiceConnection);
        super.onDestroy();
    }

    private ServiceConnection sensorServiceConnection = new ServiceConnection() {

        public void onServiceConnected(ComponentName className, IBinder binder) {
            sensorService = ((SensorService.SensorServiceBinder)binder).getService();
            Log.d("Helper", "Helper has bound to SensorService");
            Thread updateThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        while(true) {
                            Thread.sleep(250);
                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    Quaternion rotation = sensorService.getGyroDroidQuaternion().flipX().flipY().multiply(sensorService.getScreenRotation());
                                    xRotation.setText("x - " + rotation.getX());
                                    yRotation.setText("y - " + rotation.getY());
                                    zRotation.setText("z - " + rotation.getZ());
                                }
                            });
                        }
                    } catch(InterruptedException e) {
                        e.printStackTrace();
                    }

                }
            });
            updateThread.start();
        }

        public void onServiceDisconnected(ComponentName className) {
            sensorService = null;
            Log.d("Helper", "Helper has unbound from SensorService");
        }
    };
}
