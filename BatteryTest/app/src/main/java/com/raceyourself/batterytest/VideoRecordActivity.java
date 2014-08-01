package com.raceyourself.batterytest;

import android.content.Context;
import android.media.AudioManager;
import android.media.MediaRecorder;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;

import com.google.android.glass.media.Sounds;
import com.google.android.glass.touchpad.Gesture;
import com.google.android.glass.touchpad.GestureDetector;

import java.io.File;
import java.io.IOException;
import java.util.Date;

public class VideoRecordActivity extends VideoActivity implements SurfaceHolder.Callback {

    MediaRecorder recorder;

    /** Audio manager used to play system sound effects. */
    private AudioManager mAudioManager;

    /** Gesture detector used to present the options menu. */
    private GestureDetector mGestureDetector;

    private boolean recording = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTagAndName("VideoRecordActivity", "Video record");
        super.onCreate(savedInstanceState);

        mAudioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);

        if(Build.MODEL.contains("Glass")) {
            mGestureDetector = new GestureDetector(this).setBaseListener(new GestureDetector.BaseListener() {
                @Override
                public boolean onGesture(Gesture gesture) {
                    if (gesture == Gesture.TAP) {
                        mAudioManager.playSoundEffect(Sounds.TAP);
                        if (!recording) {
                            recorder.start();
                            recording = true;
                            Log.i(tag, testName + " recording started at " + new Date().toString());
                        } else {
                            recording = false;
                            recorder.stop();
                        }
                        return true;
                    } else {
                        return false;
                    }
                }
            });
        } else {
            SurfaceView cameraView = (SurfaceView)findViewById(R.id.cameraView);
            cameraView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    if (!recording) {
                        recorder.start();
                        recording = true;
                        Log.i(tag, testName + " recording started at " + new Date().toString());
                    } else {
                        recording = false;
                        recorder.stop();
                        try {
                            camera.reconnect();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                }
            });
        }
    }

    @Override
    public boolean onGenericMotionEvent(MotionEvent event) {
        return mGestureDetector.onMotionEvent(event);
    }

    private void initRecorder() {
        recorder.setAudioSource(MediaRecorder.AudioSource.DEFAULT);
        recorder.setVideoSource(MediaRecorder.VideoSource.DEFAULT);
        recorder.setProfile(camcorderProfile);
        try {
            File newFile = File.createTempFile("video_capture", ".mp4", Environment.getExternalStorageDirectory());
            recorder.setOutputFile(newFile.getAbsolutePath());
        } catch(IOException e) {
            Log.e(tag, "Couldn't create file");
            e.printStackTrace();
        }
    }

    @Override
    protected void prepareRecorder() {
        Log.i(tag, "prepare recorder function entered");
        recorder = new MediaRecorder();
        recorder.setPreviewDisplay(holder.getSurface());
        super.prepareRecorder();

        recorder.setCamera(camera);
        initRecorder();
        try {
            recorder.prepare();
        } catch (IllegalStateException e) {
            e.printStackTrace();
            finish();
        } catch (IOException e) {
            e.printStackTrace();
            finish();
        }
    }

    @Override
    public void onPause() {
        recorder.release();
        super.onPause();
    }

    @Override
    public void onDestroy() {
        if(recording) {
            recorder.stop();
            recording = false;
        }
        recorder.release();
        super.onDestroy();
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        super.surfaceCreated(holder);

    }

}
