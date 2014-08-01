package com.raceyourself.batterytest;


import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;

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

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        if(timer != null) timer.cancel();

        Log.i(tag, testName + " test started at " + new Date().toString());

        timer = new Timer();
        timerTask = new TimerTask() {
            @Override
            public void run() {
                Log.i(tag, testName + " test update time at " + new Date().toString());
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
