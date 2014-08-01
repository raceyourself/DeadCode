package com.raceyourself.batterytest;

import android.content.Context;
import android.hardware.Camera;
import android.media.AudioManager;
import android.media.MediaRecorder;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.FrameLayout;

import com.google.android.glass.media.Sounds;
import com.google.android.glass.touchpad.Gesture;
import com.google.android.glass.touchpad.GestureDetector;

import java.io.File;
import java.io.IOException;
import java.util.Date;

public class VideoRecordActivity extends BaseTestActivity implements SurfaceHolder.Callback {

    private Camera camera;
    private SurfaceView cameraPreview;
    private MediaRecorder mediaRecorder;
    private FrameLayout frame;

    private final static int maximumWaitTimeForCamera = 5000;
    private final static String outputFile = "/sdcard/media.mp4";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTagAndName("VideoRecordActivity", "Video record");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_video_record);
        cameraPreview = new SurfaceView(this);
        android.widget.FrameLayout.LayoutParams params = new android.widget.FrameLayout.LayoutParams(640, 350);
        cameraPreview.setLayoutParams(params);
        cameraPreview.getHolder().addCallback(this);
        frame = (FrameLayout) super.findViewById(R.id.camera_preview);
        frame.addView(this.cameraPreview);
    }

    public void stopRecording() {
        mediaRecorder.stop();
        releaseMediaRecorder();
        releaseCamera();
    }

    private void releaseMediaRecorder() {
        if (mediaRecorder != null) {
            mediaRecorder.reset();
            mediaRecorder.release();
            mediaRecorder = null;
        }
    }

    private void releaseCamera() {
        if (this.camera != null) {
            this.camera.stopPreview();
            this.camera.release();
            this.camera = null;
            this.frame.removeView(this.cameraPreview);
        }
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {

        if (camera == null) {
            camera = getCameraInstanceRetry();
        }

        try {
            camera.stopPreview();
            camera.setPreviewDisplay(null);
        } catch (IOException e) {
            Log.d(tag, "IOException setting preview display: " + e.getMessage());

        }
        camera.unlock();
        mediaRecorder = new MediaRecorder();
        mediaRecorder.setCamera(camera);
        mediaRecorder.setAudioSource(MediaRecorder.AudioSource.CAMCORDER);
        mediaRecorder.setVideoSource(MediaRecorder.VideoSource.CAMERA);
        mediaRecorder.setOutputFormat(MediaRecorder.OutputFormat.MPEG_4);
        mediaRecorder.setAudioEncoder(MediaRecorder.AudioEncoder.AAC);
        mediaRecorder.setVideoEncoder(MediaRecorder.VideoEncoder.H264);
        mediaRecorder.setOutputFile(outputFile);
        mediaRecorder.setPreviewDisplay(cameraPreview.getHolder().getSurface());

        try {
            mediaRecorder.prepare();
        } catch (IllegalStateException e) {
            Log.d(tag, "IllegalStateException preparing MediaRecorder: " + e.getMessage());
            releaseMediaRecorder();
        } catch (IOException e) {
            Log.d(tag, "IOException preparing MediaRecorder: " + e.getMessage());
            releaseMediaRecorder();
        }

        mediaRecorder.start();

//        Handler mHandler = new Handler();
//        mHandler.postDelayed(new Runnable() {
//            @Override
//            public void run() {
//                stopRecording();
//                finish();
//            }
//        }, 5000);
    }

    @Override
    public void onDestroy() {
        stopRecording();
        super.onDestroy();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        //Do nothing
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        //Do nothing
    }

    private Camera getCameraInstanceRetry() {
        Camera c = null;
        boolean acquiredCam = false;
        int timePassed = 0;
        while (!acquiredCam && timePassed < maximumWaitTimeForCamera) {
            try {
                c = Camera.open();
                acquiredCam = true;
                return c;
            } catch (Exception e) {
                Log.e(tag, "Exception encountered opening camera:" + e.getLocalizedMessage());
            }
            try {
                Thread.sleep(200);
            } catch (InterruptedException ee) {
                Log.e(tag, "Exception encountered sleeping:" + ee.getLocalizedMessage());
            }
            timePassed += 200;
        }
        return c;
    }

}

