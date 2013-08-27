package com.srpirrlicht.helloworld;

import com.srpirrlicht.helloworld.GLESRenderView;
import com.srplab.www.starcore.*;

import android.app.Activity;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class HelloWorldActivity extends Activity {
	private GLSurfaceView mGLView;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        StarCoreFactoryPath.InitDefault(Runtime.getRuntime(),"/data/data/com.srpirrlicht.helloworld");
        AssetManager assetManager = getAssets();       
        mGLView = new GLESRenderView(this,getApplication(),assetManager);
        setContentView(mGLView); 
    }
    @Override    protected void onPause() {
    	System.exit(0);
/*
    	super.onPause();        
    	// The following call pauses the rendering thread.        
    	// If your OpenGL application is memory intensive,        
    	// you should consider de-allocating objects that        
    	// consume significant memory here.        
    	mGLView.onPause();
*/
    }        
    @Override    protected void onResume() {
    	super.onResume();        
    	// The following call resumes a paused rendering thread.        
    	// If you de-allocated graphic objects for onPause()        
    	// this is a good place to re-allocate them.       
    	mGLView.onResume();  
    }
}