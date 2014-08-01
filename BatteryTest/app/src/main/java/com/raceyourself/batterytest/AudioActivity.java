package com.raceyourself.batterytest;

import android.os.Bundle;
import android.widget.TextView;

public class AudioActivity extends BaseTestActivity {

    TextView audioResults;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTagAndName("AudioActivity", "Audio");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_audio);

        audioResults = (TextView)findViewById(R.id.audioResults);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }
}
