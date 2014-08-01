package com.raceyourself.batterytest;

import com.google.android.glass.media.Sounds;
import com.google.android.glass.widget.CardScrollView;
import com.google.android.glass.touchpad.GestureDetector;
import com.google.android.glass.touchpad.Gesture;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.WindowManager;

/**
 * An {@link Activity} showing a tuggable "Hello World!" card.
 * <p>
 * The main content view is composed of a one-card {@link CardScrollView} that provides tugging
 * feedback to the user when swipe gestures are detected.
 * If your Glassware intends to intercept swipe gestures, you should set the content view directly
 * and use a {@link com.google.android.glass.touchpad.GestureDetector}.
 * @see <a href="https://developers.google.com/glass/develop/gdk/touch">GDK Developer Guide</a>
 */
public class BatteryMenuActivity extends Activity {

    /**
     * Handler used to post requests to start new activities so that the menu closing animation
     * works properly.
     */

    /** Audio manager used to play system sound effects. */
    private AudioManager mAudioManager;

    /** Gesture detector used to present the options menu. */
    private GestureDetector mGestureDetector;

    private final GestureDetector.BaseListener mBaseListener = new GestureDetector.BaseListener() {
        @Override
        public boolean onGesture(Gesture gesture) {
            if(gesture == Gesture.TAP) {
                mAudioManager.playSoundEffect(Sounds.TAP);
                openOptionsMenu();
                return true;
            } else {
                return false;
            }

        }
    };

    @Override
    protected void onCreate(Bundle bundle) {
        super.onCreate(bundle);

        setContentView(R.layout.activity_battery_menu);

        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        Log.i("BatteryMenuActivity", "Activity created");

        mAudioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
        mGestureDetector = new GestureDetector(this).setBaseListener(mBaseListener);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.battery_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch(item.getItemId()) {
            case R.id.simple_test:
                Intent simpleIntent = new Intent(this, SimpleTestActivity.class);
                startActivity(simpleIntent);
                break;
            case R.id.video_standby:
                Intent videoStandbyIntent = new Intent(this, VideoStandbyActivity.class);
                startActivity(videoStandbyIntent);
                break;
            case R.id.video_record:
                Intent videoRecordIntent = new Intent(this, VideoRecordActivity.class);
                startActivity(videoRecordIntent);
                break;
            case R.id.sensors:
                Intent sensorIntent = new Intent(this, SensorActivity.class);
                startActivity(sensorIntent);
                break;
            case R.id.ble:
                Intent bleIntent = new Intent(this, BLEActivity.class);
                startActivity(bleIntent);
                break;
            case R.id.audio:
                Intent audioIntent = new Intent(this, AudioActivity.class);
                startActivity(audioIntent);
                break;
        }
        return true;
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    public boolean onGenericMotionEvent(MotionEvent event) {
        return mGestureDetector.onMotionEvent(event);
    }

}
