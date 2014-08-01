package com.raceyourself.batterytest;

import android.hardware.Camera;
import android.media.CamcorderProfile;
import android.media.MediaRecorder;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.io.IOException;

public class VideoActivity extends BaseTestActivity implements SurfaceHolder.Callback {

//    MediaRecorder recorder;
    SurfaceHolder holder;
    protected CamcorderProfile camcorderProfile;
    protected Camera camera;

    private boolean firstRun;

    private boolean isReleased;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.i(tag, "video activity onCreate entered");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_video);

        firstRun = true;
        isReleased = false;

        camcorderProfile = CamcorderProfile.get(CamcorderProfile.QUALITY_LOW);

        SurfaceView cameraView = (SurfaceView)findViewById(R.id.cameraView);
        holder = cameraView.getHolder();
        holder.addCallback(this);
    }

    protected void prepareRecorder() {
        camera.unlock();
    }

    @Override
    public void onPause() {
        if(!isReleased && camera != null) {
            camera.stopPreview();
            try {
                camera.reconnect();
            } catch (IOException e) {
                e.printStackTrace();
            }
            camera.release();
            isReleased = true;
        }

        camera = null;
        super.onPause();
    }

    @Override
    public void onResume() {
        if(!firstRun)
        camera = Camera.open();
        isReleased = false;
        super.onResume();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        Log.i(tag, "surface created entered");
        camera = Camera.open();
        try {
            camera.setPreviewDisplay(holder);
            camera.startPreview();
        } catch (IOException e) {
            e.printStackTrace();
        }
        firstRun = false;
        isReleased = false;
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        Log.i(tag, "surface changed entered");
        try {
            Camera.Parameters p = camera.getParameters();

            p.setPreviewSize(camcorderProfile.videoFrameWidth, camcorderProfile.videoFrameHeight);

            camera.setParameters(p);

            camera.setPreviewDisplay(holder);
            camera.startPreview();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        prepareRecorder();
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        if(!isReleased) {
            camera.stopPreview();
            try {
                camera.reconnect();
            } catch (IOException e) {
                e.printStackTrace();
            }
            camera.release();
            isReleased = true;
        }
        camera = null;
        Log.i(tag, "Camera released");
        finish();
    }
}
