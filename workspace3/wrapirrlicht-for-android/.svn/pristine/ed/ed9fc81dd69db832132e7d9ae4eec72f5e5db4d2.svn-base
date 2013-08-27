/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"
#include "irrlicht.h"

using namespace irr;

static VS_ULONG IrrlichtDeviceClass_ClassLayer;
#define IRRLICHTDEVICECLASS_LOCALVARINDEX   1

VS_UUID g_DeviceObjectID;
struct StructOfIrrlichtDeviceClassLocalBuf{
	class ClassOfSRPEventReceiver *SRPEventReceiver;
	irr::IrrlichtDevice* IrrlichtDevice;
	VS_UUID SceneManagerObjectID;
	VS_UUID VideoDriverObjectID;
	VS_UUID FileSystemObjectID;
};

class ClassOfSRPEventReceiver:public irr::IEventReceiver{
public :
	virtual bool OnEvent(const SEvent& event);
};

bool ClassOfSRPEventReceiver::OnEvent(const SEvent& event)
{
	bool processflag;
/*
	void *EventObject;
	VS_QUERYRECORD QueryRecord;
*/
	processflag = false;
	if( event.EventType == EET_LOG_TEXT_EVENT ){
		switch( event.LogEvent.Level ){
case ELL_INFORMATION :
case ELL_NONE :
	pSRP -> Print( (VS_CHAR *)event.LogEvent.Text );
	processflag = true;
	break;
case ELL_WARNING :
	pSRP -> ProcessError(VSFAULT_WARNING,"IrrlichtDeviceClass",0,(VS_CHAR *)event.LogEvent.Text);
	processflag = true;
	break;
case ELL_ERROR :
	pSRP -> ProcessError(VSFAULT_NORMALERROR,"IrrlichtDeviceClass",0,(VS_CHAR *)event.LogEvent.Text);
	processflag = true;
	break;
		}
	}else{
/*
		EventObject = pSRP -> QueryFirstInstEx(&QueryRecord,&VSOBJID_IrrEventClass);
		while( EventObject != NULL ){
			if( pSRP -> IsActive(EventObject) == VS_TRUE ){
				SRPCALL_RET2(pSRP,IrrEventClass_EventProcess,processflag,false,EventObject,(void *)&event);
				if( processflag == true ){
					pSRP -> QueryInstClose(&QueryRecord);
					return processflag;
				}
			}
			EventObject = pSRP -> QueryNextInstEx(&QueryRecord,&VSOBJID_IrrEventClass);
		}
		pSRP -> QueryInstClose(&QueryRecord);
*/
	}
	return processflag;
}

VS_INT32 SRPCALLBACK IrrDeviceClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrDeviceClass *IrrDeviceClassPtr;
    //VS_EVENTPARAM_RUNPARAM *ResponseParam,*RequestParam;
	void *ChildObject;
	struct StructOfIrrlichtDeviceClassLocalBuf *IrrlichtDeviceClassLocalBuf;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrDeviceClassPtr = (struct StructOfIrrDeviceClass *)LocalEventParaPtr -> DesObject;
    switch( pSRP -> GetSysEventID(LocalEventParaPtr) ){
    //...........................................................................
    //...........................................................................
    //...........................................................................
    //...........................................................................
    //...........................................................................
    //---------------------------------------------------------------------------
    //---module init
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONMODULEINIT:
		IrrlichtDeviceClass_ClassLayer = pSRP -> GetLayer(pSRP -> GetObject(&VSOBJID_IrrDeviceClass));
		INIT_UUID(g_DeviceObjectID);
        break;
    case VSEVENT_SYSTEMEVENT_ONBECOMESYNC:
        break;
    //---------------------------------------------------------------------------
    //---module term
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONMODULETERM:
        break;
    //---------------------------------------------------------------------------
    //---module may be unload
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONMODULECANBEUNLOAD:
        //ResponseParam = pSRP -> GetResponseBuf( );
        //INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //ResponseParam -> LParam = 0; // may  1 may not 
        //pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //...........................................................................
    //...........................................................................
    //...........................................................................
    //...........................................................................
    //...........................................................................
    //---------------------------------------------------------------------------
    //---create instance event
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONBEFOREFIRSTCREATE:
        //ResponseParam = pSRP -> GetResponseBuf( );
        //INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //ResponseParam -> LParam = 1;
        //pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
        
    //---------------------------------------------------------------------------
    //---fill defaule value for instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONFIRSTCREATE:
        //---may change instance attribute init value
        break;
    //---------------------------------------------------------------------------
    //---alloc instance memory, only create once for each instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONMALLOC:
        break;
    //---------------------------------------------------------------------------
    //---free instance memory, only create once for each instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONFREE:
        break;
    //---------------------------------------------------------------------------
    //---create instance, used to init instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONCREATE:
		IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> MallocPrivateBuf( IrrDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX,sizeof(struct StructOfIrrlichtDeviceClassLocalBuf) );
		memset( IrrlichtDeviceClassLocalBuf, 0, sizeof(struct StructOfIrrlichtDeviceClassLocalBuf) );
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
		IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> GetPrivateBuf( IrrDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX, NULL );
		if( IrrlichtDeviceClassLocalBuf ->IrrlichtDevice != NULL ){
			IrrlichtDeviceClassLocalBuf ->IrrlichtDevice -> drop();
			IrrlichtDeviceClassLocalBuf ->IrrlichtDevice = NULL;
		}
		if( IrrlichtDeviceClassLocalBuf -> SRPEventReceiver != NULL ){
			delete IrrlichtDeviceClassLocalBuf -> SRPEventReceiver;
			IrrlichtDeviceClassLocalBuf -> SRPEventReceiver = NULL;
		}
		ChildObject = pSRP -> GetObject( &IrrlichtDeviceClassLocalBuf -> SceneManagerObjectID );
		if( ChildObject != NULL )
			pSRP -> FreeObject(ChildObject);
		ChildObject = pSRP -> GetObject( &IrrlichtDeviceClassLocalBuf -> VideoDriverObjectID );
		if( ChildObject != NULL )
			pSRP -> FreeObject(ChildObject);
		ChildObject = pSRP -> GetObject( &IrrlichtDeviceClassLocalBuf -> FileSystemObjectID );
		if( ChildObject != NULL )
			pSRP -> FreeObject(ChildObject);
		pSRP -> FreePrivate( IrrDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX );
        break;
    //---------------------------------------------------------------------------
    //---create child instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONCREATECHILD:
        //ChildObject = (void *)LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    //---destory child instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORYCHILD:
        //ChildObject = (void *)LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    //---instance is activting
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONACTIVATING: 
        //---if the instance can not activate, use this code
        //TriggerForLoadFlag = LocalEventParaPtr -> RequestParam -> LParam;
        //ResponseParam = pSRP -> GetResponseBuf( );
        //INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //ResponseParam -> LParam = 1; 
        //pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    //---instance status change to activate
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONACTIVATE: 
        //TriggerForLoadFlag = LocalEventParaPtr -> RequestParam -> LParam;
		{
			IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> GetPrivateBuf( IrrDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX, NULL );
			if( IrrlichtDeviceClassLocalBuf -> SRPEventReceiver == NULL )
				IrrlichtDeviceClassLocalBuf -> SRPEventReceiver = new class ClassOfSRPEventReceiver();
			if( IrrlichtDeviceClassLocalBuf ->IrrlichtDevice == NULL ){
				irr::SIrrlichtCreationParameters param; 

				param.DriverType = video::EDT_OGLES2;
				param.WindowId = (void *)IrrDeviceClassPtr ->RenderWnd;
				param.WindowSize = core::dimension2d<s32>(IrrDeviceClassPtr->Width, IrrDeviceClassPtr->Height);
				param.Bits = 16;
				param.Fullscreen = false;
				param.Stencilbuffer = false;
				param.Vsync = false;
				param.AntiAlias = false;
				param.HighPrecisionFPU = false;
			    param.EventReceiver = IrrlichtDeviceClassLocalBuf -> SRPEventReceiver;
			    IrrlichtDeviceClassLocalBuf ->IrrlichtDevice = irr::createDeviceEx(param);
#if( VS_OS_TYPE == VS_OS_WINDOWS)
				_control87( _MCW_EM,0x801f );
#endif
			}			
		}
		pSRP ->GetID(IrrDeviceClassPtr,&g_DeviceObjectID);
		break;
    //---------------------------------------------------------------------------
    //---instance is deactivating
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDEACTIVATING: 
        //TriggerForLoadFlag = LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    //---instance status change to deactivate
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDEACTIVATE: 
        //TriggerForLoadFlag = LocalEventParaPtr -> RequestParam -> LParam;
		{
			IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> GetPrivateBuf( IrrDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX, NULL );
			if( IrrlichtDeviceClassLocalBuf ->IrrlichtDevice != NULL ){
				IrrlichtDeviceClassLocalBuf ->IrrlichtDevice -> drop();
				IrrlichtDeviceClassLocalBuf ->IrrlichtDevice = NULL;
			}
		}
		INIT_UUID(g_DeviceObjectID);
        break;
    //---------------------------------------------------------------------------
    //---activate child instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONACTIVATECHILD:
        //ChildObject = (void *)LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    //---deactivate child instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDEACTIVATECHILD:
        //ChildObject = (void *)LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    //---before instance attribute change
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONATTRIBUTEBEFORECHANGE:
        break;
    //---------------------------------------------------------------------------
    //---instance attribute change
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONATTRIBUTECHANGE:
        break;
    //---------------------------------------------------------------------------
    //---before instance parent change
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONPARENTBEFORECHANGE:
        //ChildObject = (void *)LocalEventParaPtr -> RequestParam -> LParam;
        //ResponseParam = pSRP -> GetResponseBuf( );
        //INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //ResponseParam -> LParam = 0; //---0 permit, else not
        //pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    //---instance parent change
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONPARENTCHANGE:
        break;
    //---------------------------------------------------------------------------
    //---instance sync group change
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONSYNCGROUPCHANGE:
        break;
    //---------------------------------------------------------------------------
    //---child object syncgroup change
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONCHILDSYNCGROUPCHANGE:
        break;
    //---------------------------------------------------------------------------
    //---activeset change
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONACTIVESETCHANGE:
        //SysRootItem = (void *)LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    //---change or create object script
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONSCRIPTCHANGE:
        //ScriptName = (VS_INT8 *)LocalEventParaPtr -> RequestParam -> LParam;
        //Operation = LocalEventParaPtr -> RequestParam -> SParam;  0 - Change 1 - Create
        break;
    //---------------------------------------------------------------------------
    //---save object data
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONSAVE:
        //ResponseParam = pSRP -> GetResponseBuf( );
        //ResponseParam -> LParam = 0; //---DataBuf
        //ResponseParam -> SParam = 0; //---DataSize
        //ResponseParam -> TParam = 0; //---Result
        //pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    //---load object data
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONLOAD:
        //Buf = LocalEventParaPtr -> RequestParam -> LParam;
        //BufSize = LocalEventParaPtr -> RequestParam -> SParam;
        break;
    //---------------------------------------------------------------------------
    //---objece load attribute mask
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONLOADMASK:
        //(VS_ATTRIBUTEINDEXMAP *) = LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    //---finish object data load
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONLOADFINISH:
        break;
    //---------------------------------------------------------------------------
    //---receive remote message
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONREMOTESEND:
        //(VS_PARAPKGPTR) = LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    //---local function call
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONCALL:
        //(ClassOfSRPFunctionParaInterface *) = LocalEventParaPtr -> RequestParam -> LParam;
        break;
    //---------------------------------------------------------------------------
    }
    //---------------------------------------------------------------------------
    return VSEVENTMANAGER_DISPATCH;
}

void *SRPAPI IrrDeviceClass_GetCurDevice(void *Object)
{
    return pSRP ->GetObject(&g_DeviceObjectID);
}

VS_INT32 SRPAPI IrrDeviceClass_Lua_GetCurDevice(void)
{
    return pSRP ->LuaPushObject(IrrDeviceClass_GetCurDevice(NULL));
}

void SRPAPI IrrDeviceClass_SetSize(void *Object,VS_INT32 Width,VS_INT32 Height)
{
	struct StructOfIrrlichtDeviceClassLocalBuf *IrrlichtDeviceClassLocalBuf;

	IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> GetPrivateBuf( Object, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX, NULL );
	irr::core::dimension2d<unsigned int> size;
	size.Width = Width;
	size.Height = Height; 
	IrrlichtDeviceClassLocalBuf ->IrrlichtDevice->getVideoDriver()->OnResize(size);
    return;
}

VS_INT32 SRPAPI IrrDeviceClass_Lua_SetSize(void)
{
	void *Object;
	VS_INT32 Width,Height;

	Object = pSRP ->LuaToObject(1);
	Width = pSRP ->LuaToInt(2);
	Height = pSRP ->LuaToInt(3);
	IrrDeviceClass_SetSize(Object,Width,Height);
    return 0;
}

void *SRPAPI IrrDeviceClass_GetSceneManager(void *Object)
{
	struct StructOfIrrDeviceClass *IrrlichtDeviceClassPtr;
	struct StructOfIrrlichtDeviceClassLocalBuf *IrrlichtDeviceClassLocalBuf;
	void *SceneManagerObject;
	irr::scene::ISceneManager* smgr;

	IrrlichtDeviceClassPtr = (struct StructOfIrrDeviceClass *)Object;
	IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> GetPrivateBuf( IrrlichtDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX, NULL );
	if( IrrlichtDeviceClassLocalBuf ->IrrlichtDevice == NULL )
		return NULL;
	SceneManagerObject = pSRP -> GetObject( &IrrlichtDeviceClassLocalBuf -> SceneManagerObjectID );
	if( SceneManagerObject != NULL )
		return SceneManagerObject;
	SceneManagerObject = pSRP -> MallocObjectL(&VSOBJID_IrrSceneManagerClass,0,NULL);
	smgr = IrrlichtDeviceClassLocalBuf ->IrrlichtDevice -> getSceneManager();
	smgr -> grab();
	IrrObjectClass_SetIrrObject(SceneManagerObject,smgr);
	pSRP -> Active(SceneManagerObject);
	pSRP -> GetID(SceneManagerObject,&IrrlichtDeviceClassLocalBuf -> SceneManagerObjectID);
	return SceneManagerObject;
}

VS_INT32 SRPAPI IrrDeviceClass_Lua_GetSceneManager(void)
{
	void *Object,*SceneManagerObject;

	Object = pSRP -> LuaToObject(1);
	SceneManagerObject = IrrDeviceClass_GetSceneManager(Object);
	if( SceneManagerObject == NULL ){
		pSRP -> LuaPushNil();
		return 1;
	}
	pSRP -> LuaPushObject(SceneManagerObject);
	return 1;
}

void *SRPAPI IrrDeviceClass_GetVideoDriver(void *Object)
{
	struct StructOfIrrDeviceClass *IrrlichtDeviceClassPtr;
	struct StructOfIrrlichtDeviceClassLocalBuf *IrrlichtDeviceClassLocalBuf;
	void *VideoDriverObject;
	video::IVideoDriver* driver;

	IrrlichtDeviceClassPtr = (struct StructOfIrrDeviceClass *)Object;
	IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> GetPrivateBuf( IrrlichtDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX, NULL );
	if( IrrlichtDeviceClassLocalBuf ->IrrlichtDevice == NULL )
		return NULL;
	VideoDriverObject = pSRP -> GetObject( &IrrlichtDeviceClassLocalBuf -> VideoDriverObjectID );
	if( VideoDriverObject != NULL )
		return VideoDriverObject;
	VideoDriverObject = pSRP -> MallocObjectL(&VSOBJID_IrrVideoDriverClass,0,NULL);
	driver = IrrlichtDeviceClassLocalBuf ->IrrlichtDevice -> getVideoDriver();
	driver -> grab();
	IrrObjectClass_SetIrrObject(VideoDriverObject,driver);
	pSRP -> Active(VideoDriverObject);
	pSRP -> GetID(VideoDriverObject,&IrrlichtDeviceClassLocalBuf -> VideoDriverObjectID);
	return VideoDriverObject;
}

VS_INT32 SRPAPI IrrDeviceClass_Lua_GetVideoDriver(void)
{
	void *Object,*SceneManagerObject;

	Object = pSRP -> LuaToObject(1);
	SceneManagerObject = IrrDeviceClass_GetVideoDriver(Object);
	if( SceneManagerObject == NULL ){
		pSRP -> LuaPushNil();
		return 1;
	}
	pSRP -> LuaPushObject(SceneManagerObject);
	return 1;
}

void *SRPAPI IrrDeviceClass_GetFileSystem(void *Object)
{
	struct StructOfIrrDeviceClass *IrrlichtDeviceClassPtr;
	struct StructOfIrrlichtDeviceClassLocalBuf *IrrlichtDeviceClassLocalBuf;
	void *FileSystemObject;
	io :: IFileSystem* fs;

	IrrlichtDeviceClassPtr = (struct StructOfIrrDeviceClass *)Object;
	IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> GetPrivateBuf( IrrlichtDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX, NULL );
	if( IrrlichtDeviceClassLocalBuf ->IrrlichtDevice == NULL )
		return NULL;
	FileSystemObject = pSRP -> GetObject( &IrrlichtDeviceClassLocalBuf -> FileSystemObjectID );
	if( FileSystemObject != NULL )
		return FileSystemObject;
	FileSystemObject = pSRP -> MallocObjectL(&VSOBJID_IrrFileSystemClass,0,NULL);
	fs = IrrlichtDeviceClassLocalBuf ->IrrlichtDevice -> getFileSystem();
	fs -> grab();
	IrrObjectClass_SetIrrObject(FileSystemObject,fs);
	pSRP -> Active(FileSystemObject);
	pSRP -> GetID(FileSystemObject,&IrrlichtDeviceClassLocalBuf -> FileSystemObjectID);
	return FileSystemObject;
}

VS_INT32 SRPAPI IrrDeviceClass_Lua_GetFileSystem(void)
{
	void *Object,*SceneManagerObject;

	Object = pSRP -> LuaToObject(1);
	SceneManagerObject = IrrDeviceClass_GetFileSystem(Object);
	if( SceneManagerObject == NULL ){
		pSRP -> LuaPushNil();
		return 1;
	}
	pSRP -> LuaPushObject(SceneManagerObject);
	return 1;
}

void SRPAPI IrrDeviceClass_Render(void *Object)
{
	struct StructOfIrrDeviceClass *IrrlichtDeviceClassPtr;
	struct StructOfIrrlichtDeviceClassLocalBuf *IrrlichtDeviceClassLocalBuf;
	video::SMaterial material,*materialptr;

	IrrlichtDeviceClassPtr = (struct StructOfIrrDeviceClass *)Object;
	IrrlichtDeviceClassLocalBuf = (struct StructOfIrrlichtDeviceClassLocalBuf *)pSRP -> GetPrivateBuf( IrrlichtDeviceClassPtr, IrrlichtDeviceClass_ClassLayer,IRRLICHTDEVICECLASS_LOCALVARINDEX, NULL );
	if( IrrlichtDeviceClassLocalBuf ->IrrlichtDevice != NULL ){
		irr::video::IVideoDriver* driver = IrrlichtDeviceClassLocalBuf ->IrrlichtDevice->getVideoDriver();
		irr::scene::ISceneManager* smgr = IrrlichtDeviceClassLocalBuf ->IrrlichtDevice->getSceneManager();
		irr::gui::IGUIEnvironment* guienv = IrrlichtDeviceClassLocalBuf ->IrrlichtDevice->getGUIEnvironment();

		IrrlichtDeviceClassLocalBuf ->IrrlichtDevice -> run();

		materialptr = driver -> getMaterial();
		if( materialptr != NULL )
			material = (*materialptr);

		driver->beginScene(true, true, irr::video::SColor(SRP_ARGB_ABGR(IrrlichtDeviceClassPtr ->Color)));

		smgr->drawAll();
		guienv->drawAll();

		if( materialptr != NULL )
			driver -> setMaterial(material);

		driver->endScene();
	}
}

VS_INT32 SRPAPI IrrDeviceClass_Lua_Render(void)
{
	void *Object;

	Object = pSRP ->LuaToObject(1);
    IrrDeviceClass_Render(Object);
	return 0;
}
