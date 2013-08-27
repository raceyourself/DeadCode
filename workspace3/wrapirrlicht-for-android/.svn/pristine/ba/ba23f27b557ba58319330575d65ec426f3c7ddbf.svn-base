import com.srplab.www.starcore.*;
import java.util.Hashtable;

public class HelloWorld{
	static int RenderWnd;
	static WindowsRender _render;
	public static void main(String[] args){
	    RenderWnd = 0;
		HelloWorld renderobj;
		renderobj = new HelloWorld();
		renderobj.Init();		
    }    
    
    public void Init(){
		_render = new WindowsRender(RenderWnd);
		_render.onSurfaceCreated();
		_render.onSurfaceChanged(800,480);
		_render.Win32Run();
    }
        	
//--sub class
class WindowsRender{
	int RenderWnd; 	
	boolean        InitFlag;	
	boolean        AndroidVersion;
    
    public int GetRenderWnd(){
    	if( AndroidVersion == true || RenderWnd != 0 )
    	    return RenderWnd;
    	Service._CheckPassword(false);
      	Object[] Result = Service._DoFile("","..\\..\\irrloader.dll", "");
      	StarObjectClass Obj;
      	Obj = Service._GetObject("GLESRenderWindowClass");
      	return Obj._Toint(Obj._Call("Init",800,480));
    }
    
    public void Win32Run(){
    	if( AndroidVersion == true || RenderWnd != 0 )
    	    return;
      	StarObjectClass Obj;
      	Obj = Service._GetObject("GLESRenderWindowClass");
      	Obj._Call("Run");
      	return;
    }    
        	    	
	public void DispatchStarCoreMsg(){
		// for android
		if( AndroidVersion == true ){
		    while( starcore._SRPDispatch(false) == true );
		}
	}
	
    public void SetDeviceTimer(){    	
    	// for windows 
    	if( AndroidVersion == false ){
	    	Device._SetTimer(1,"TimerProc", 0, 0 );    	
	    }
	}
	
	public void onDrawFrame(Object Para) {
		if( Device == null )
			return;
		// Redraw background color    
		Device._Call("Lua_Render");
		DispatchStarCoreMsg();
	}        
	public void onSurfaceChanged(int width, int height) {        
    	Device._Call("Lua_SetSize",width,height);
	} 
	
	void onPause(){
		Device._Call("Pause");  // not implemented
	}

	void onResume(){
	}		
    //--------------------------------------------------------------------------------------------------------
    String ServicePath;    
    
    StarCoreFactory starcore;
    StarSrvGroupClass SrvGroup;
    StarServiceClass Service;
    
	StarObjectClass Device = null;
	    
    public void onSurfaceCreated() {
		if( InitFlag == true ){
			Device._Call("Resume");	  // not implemented		
			return;
		}
		InitFlag = true;
		starcore= StarCoreFactory.GetFactory();		
		if( AndroidVersion == false ){
        	Service=starcore._InitSimple("test","123",0,0,"..\\..\\..\\service\\win32\\SRPIrrlichtES2Engine");        
        }else{
            Service=starcore._InitSimple("test","123",0,0,ServicePath+"SRPFSEngine",ServicePath+"SRPGLESEngine");        
        }
        SrvGroup = (StarSrvGroupClass)Service._Get("_ServiceGroup");
    	Device=Service._GetObject("IrrDeviceClass")._New()._Assign(new StarObjectClass(){
            public void TimerProc(StarObjectClass self,int TimerID,int Arg1,int Arg2){
            	onDrawFrame(null);
            }
    	});
    	Device._Set("Width",800);
    	Device._Set("Height",480);
    	Device._Set("RenderWnd",GetRenderWnd());
    	Device._Set("Color",0x7F7F7F7F);
    	SetDeviceTimer();
    	Device._Active();
        //--------------------------------------------------------------------------------
        //--your code begin here
        InitGame();  
    }
	
    public WindowsRender(int In_RenderWnd){
    	InitFlag = false;
    	AndroidVersion = false;
    	if( AndroidVersion == false ){
		    ServicePath = "";
		    RenderWnd = In_RenderWnd;
		}else{
			if( StarCoreFactoryPath.StarCoreOperationPath != null ){
				ServicePath = StarCoreFactoryPath.StarCoreOperationPath + "/";
			}else{
				ServicePath = "";
			}
		}
    };  	
    
	//--------------------------------------------------------------------------------
	//--your code begin here
	StarObjectClass VDiskDrive;
	StarObjectClass SceneManager,VideoDriver;
	StarObjectClass Texture1,Node,Cam;
		
	private void InitGame() {
		VDiskDrive = Service._GetObject("DriveClass")._New("VDisk");
		VDiskDrive._Call("Lua_LoadWebFile","sydney.bmp","sydney.bmp","../Media/sydney.bmp","","");
		VDiskDrive._Call("Lua_LoadWebFile","sydney.md2","sydney.md2","../Media/sydney.md2","","");
                
        SceneManager = (StarObjectClass)Device._Call("Lua_GetSceneManager");
        VideoDriver = (StarObjectClass)Device._Call("Lua_GetVideoDriver");

        Texture1 = Service._GetObject("IrrTextureClass")._New();
        Texture1._Set("TextureFile","VDisk:\\sydney.bmp");
        Texture1._Active();
    
        Node = Service._GetObject("IrrAnimatedMeshSceneNodeClass")._New(SceneManager);
        Node._Set("MeshFile","VDisk:\\sydney.md2");
        Node._Set("MD2AnimationType",Service._Get("IRREMAT_STAND"));
        Node._Active();
        Node._Call("Lua_SetMaterialFlag",Service._Get("IRREMF_LIGHTING"), false);
        Node._Call("Lua_SetMaterialTexture", 0, Texture1 );
    
        Cam = Service._GetObject("IrrCameraSceneNodeClass")._New(SceneManager);
        Cam._Set("Position",new Object[]{0,30,-40});
        Cam._Set("Target",new Object[]{0,15,0});
        Cam._Active();
	}	    
} //end of subclass
}