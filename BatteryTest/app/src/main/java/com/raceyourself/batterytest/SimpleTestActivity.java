package com.raceyourself.batterytest;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.WindowManager;

import com.raceyourself.batterytest.R;

import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

public class SimpleTestActivity extends BaseTestActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTagAndName("SimpleTestActivity", "Simple");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_simple_test);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }
}
