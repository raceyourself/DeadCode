Service = libstarcore._InitSimple("test","123",0,0,"..\\..\\..\\service\\win32\\SRPIrrlichtES2Engine");
Service:_CheckPassword(false);
Service:_DoFile("","..\\..\\irrloader.dll", "");
Win32Obj = Service:_GetObject("GLESRenderWindowClass");
RenderWnd = Win32Obj:Init(800,480);
    
VDisk = Service.DriveClass:_New()
VDisk._Name = "VDisk" 
VDisk:Lua_LoadWebFile( "sydney.bmp","sydney.bmp","../Media/sydney.bmp","","")
VDisk:Lua_LoadWebFile( "sydney.md2","sydney.md2","../Media/sydney.md2","","")
            
Device=Service.IrrDeviceClass:_New()
Device.RenderWnd = RenderWnd
Device:_Active()       
Device.Color = 8421440

function Device:TimerProc(TimerID,Arg1,Arg2)
    self:Lua_Render();
end
Device:_SetTimer(1,Device.TimerProc, 0, 0 );
    
SceneManager = Device:Lua_GetSceneManager()
VideoDriver = Device:Lua_GetVideoDriver()

Texture1 = Service.IrrTextureClass:_New()
Texture1.TextureFile = "VDisk:\\sydney.bmp"
Texture1:_Active()
    
Node = Service.IrrAnimatedMeshSceneNodeClass:_New(SceneManager)
Node.MeshFile = "VDisk:\\sydney.md2"
Node.MD2AnimationType = Service.IRREMAT_STAND
Node:_Active()
Node:Lua_SetMaterialFlag(Service.IRREMF_LIGHTING, false)
Node:Lua_SetMaterialTexture( 0, Texture1 )
    
Cam = Service.IrrCameraSceneNodeClass:_New(SceneManager)
Cam.Position = {0,30,-40}
Cam.Target = {0,15,0}
Cam:_Active()

Win32Obj:Run()

Service._ServiceGroup:_ClearService()
libstarcore._ModuleExit()
