package com.raceyourself.batterytest;

import android.os.Bundle;
import android.view.SurfaceHolder;

public class VideoStandbyActivity extends VideoActivity implements SurfaceHolder.Callback {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTagAndName("VideoStandbyActivity", "Video standby");
        super.onCreate(savedInstanceState);
    }
}
