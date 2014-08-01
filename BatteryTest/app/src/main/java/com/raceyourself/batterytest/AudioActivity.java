package com.raceyourself.batterytest;

import android.os.Bundle;

public class AudioActivity extends BaseTestActivity {

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
