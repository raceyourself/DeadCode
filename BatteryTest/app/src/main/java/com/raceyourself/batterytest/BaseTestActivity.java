package com.raceyourself.batterytest;


import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;

import com.raceyourself.platform.utils.FileUtils;

import java.io.File;
import java.io.IOException;
import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

/**
 * Created by Amerigo on 31/07/2014.
 */
public class BaseTestActivity extends Activity {
    Timer timer;
    TimerTask timerTask;

    String tag = "";
    String testName = "";

    File temperature1;
    File temperature2;
    File temperature3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        temperature1 = new File("/sys/devices/platform/notle_pcb_sensor.0/temperature");
        temperature2 = new File("/sys/devices/platform/omap_i2c.1/i2c-1/1-0055/power_supply/bq27520-0/temp");
        temperature3 = new File("/sys/devices/platform/omap_i2c.4/i2c-4/4-0068/iio:device0/temperature");

        if(timer != null) timer.cancel();

        Log.i(tag, testName + " test started at " + new Date().toString());

        try {
            Log.i(tag, testName + " temperature 1 test is " + org.apache.commons.io.FileUtils.readFileToString(temperature1));
            Log.i(tag, testName + " temperature 2 test is " + org.apache.commons.io.FileUtils.readFileToString(temperature2));
            Log.i(tag, testName + " temperature 3 test is " + org.apache.commons.io.FileUtils.readFileToString(temperature3));
        } catch(IOException e) {
            e.printStackTrace();
        }

        timer = new Timer();
        timerTask = new TimerTask() {
            @Override
            public void run() {
                Log.i(tag, testName + " test update time at " + new Date().toString());
                try {
                    Log.i(tag, testName + " temperature 1 test is " + org.apache.commons.io.FileUtils.readFileToString(temperature1));
                    Log.i(tag, testName + " temperature 2 test is " + org.apache.commons.io.FileUtils.readFileToString(temperature2));
                    Log.i(tag, testName + " temperature 3 test is " + org.apache.commons.io.FileUtils.readFileToString(temperature3));
                } catch(IOException e) {
                    e.printStackTrace();
                }
            }
        };
        timer.schedule(timerTask, 60000, 60000);
    }

    protected void setTagAndName(String tag, String testName) {
        this.tag = tag;
        this.testName = testName;
    }

    @Override
    public void onDestroy() {
        Log.i(tag, testName + " test ended at " + new Date().toString());
        timer.cancel();
        super.onDestroy();
    }
}
