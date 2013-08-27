/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"

using namespace irr;

//--------------------------------------------------------------------------------------------------------------------------------
VS_BOOL SRPAPI IrrTextureClass_Load(void *Object,VS_INT8 * FileName)
{
	struct StructOfIrrTextureClass *IrrTextureClassPtr;
	VS_ULONG FileHandle;
	VS_ULONG FileDataSize;
	void *ChildObject;
	VS_INT8 *FileDataPtr;
	void *DeviceObject,*VideoDriver;
	video::IVideoDriver* driver;
	video::ITexture *Texture,*OldTexture;

	if( pSRP -> IsActive(Object) == VS_FALSE )
		return VS_FALSE;
	if( FileName == NULL || strlen(FileName) == 0 )
		return VS_FALSE;
	SRPCALL_RET1(pSRP,IrrDeviceClass_GetCurDevice,DeviceObject,NULL,NULL);
	if( DeviceObject == NULL )
		return VS_FALSE;
	VideoDriver = IrrDeviceClass_GetVideoDriver(DeviceObject);
	driver = (video::IVideoDriver*)IrrObjectClass_GetIrrObject(VideoDriver);
	if( driver == NULL )
		return VS_FALSE;
	IrrTextureClassPtr = (struct StructOfIrrTextureClass *)Object;
	IrrTextureClassPtr -> LoadResult = VS_FALSE;
	if( strchr(FileName,':') == NULL || ( FileName[1] == ':' && FileName[2] == '\\' ) ){ 
		//---Load from disk
		SRPCALLEX1(pSRP,IrrTextureClass_OnBeforeCreate,Object);
		Texture = driver -> getTexture(FileName);
		if( Texture != NULL ){
			IrrTextureClassPtr -> LoadResult = VS_TRUE;
			Texture -> grab();
			Texture -> SetSRPObject(Object);
		}
		//---Delete Old 
		OldTexture = (video::ITexture *)IrrObjectClass_GetIrrObject(Object);
		if( OldTexture != NULL ){
			IrrObjectClass_SetIrrObject(Object,NULL);
			OldTexture -> SetSRPObject(NULL);
			OldTexture -> drop();
		}
		IrrObjectClass_SetIrrObject(Object,Texture);
		SRPCALLEX1(pSRP,IrrTextureClass_OnAfterCreate,Object);
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrTextureClass_OnChange,Object,NULL,NULL);
		return VS_TRUE;
	}
	if( Object == NULL || FileName == NULL )
		return VS_FALSE;
	SRPCALL_RET2(pSRP,DriveClass_GetDrive,ChildObject,NULL,NULL,FileName);
	if( ChildObject == NULL )
		return VS_FALSE;
	SRPCALL_RET5(pSRP,DriveClass_Open,FileHandle,0,ChildObject,strchr(FileName,':'),VS_FALSE,NULL,NULL);
	if( FileHandle == 0 )
		return VS_FALSE;
	SRPCALL_RET3(pSRP,DriveClass_Read,FileDataPtr,NULL,ChildObject,FileHandle,&FileDataSize);
	if( FileDataPtr == NULL ){
		SRPCALL2(pSRP,DriveClass_Close,ChildObject, FileHandle );
		return VS_FALSE;
	}
	//---Load From Memory
	SRPCALLEX1(pSRP,IrrTextureClass_OnBeforeCreate,Object);
	Texture = driver -> getTexture(FileName,FileDataPtr,FileDataSize);
	if( Texture != NULL ){
		IrrTextureClassPtr -> LoadResult = VS_TRUE;
		Texture -> grab();
		Texture -> SetSRPObject(Object);
	}
	//---Delete Old 
	OldTexture = (video::ITexture *)IrrObjectClass_GetIrrObject(Object);
	if( OldTexture != NULL ){
		IrrObjectClass_SetIrrObject(Object,NULL);
		OldTexture -> SetSRPObject(NULL);
		OldTexture -> drop();
	}
	IrrObjectClass_SetIrrObject(Object,Texture);
	SRPCALL2(pSRP,DriveClass_Close,ChildObject, FileHandle );
	SRPCALLEX1(pSRP,IrrTextureClass_OnAfterCreate,Object);
	pSRP -> ProcessEvent(&VSOUTEVENTID_IrrTextureClass_OnChange,Object,NULL,NULL);
	return VS_TRUE;
}

//--------------------------------------------------------------------------------------------------------------------------------
//---Image file change
VS_INT32 SRPAPI IrrTextureClass_OnFileChangeEvent(VS_ULONG FunctionChoice,void *EventPara)
{
	VS_EVENTPARAM *LocalEventParaPtr;
	struct StructOfIrrTextureClass *IrrTextureClassPtr;

    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrTextureClassPtr = (struct StructOfIrrTextureClass *)LocalEventParaPtr -> DesObject;
	//----Static Data Change, Reload
	if( pSRP -> IsActive(IrrTextureClassPtr) == VS_TRUE ){
		if( IrrTextureClassPtr->TextureFile.Buf != NULL )
			IrrTextureClass_Load(IrrTextureClassPtr,IrrTextureClassPtr->TextureFile.Buf);
	}
	return VSEVENTMANAGER_DISPATCH;
}


void IrrTextureClass_SetFileChangeEventCapture( struct StructOfIrrTextureClass *IrrTextureClassPtr, VS_BOOL EnableFlag )
{
	DriveClass_GetDriveProc GetDriveProc;
	DriveClass_UnRegCallBackProc UnRegCallBackProc;
	DriveClass_RegCallBackProc RegCallBackProc;
	void *DriveObject;

	GetDriveProc = (DriveClass_GetDriveProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_GetDrive);
	if( GetDriveProc == NULL || IrrTextureClassPtr->TextureFile.Buf == NULL )
		return;
	DriveObject = GetDriveProc( NULL, IrrTextureClassPtr->TextureFile.Buf );			    
	if( DriveObject == NULL ){
		//---File Change
		void *FileSystem,*DeviceObject;

		SRPCALL_RET1(pSRP,IrrDeviceClass_GetCurDevice,DeviceObject,NULL,NULL);
		if( DeviceObject == NULL )
			return;
		FileSystem = IrrDeviceClass_GetFileSystem(DeviceObject);
		if( FileSystem == NULL )
			return;
		if( EnableFlag == VS_FALSE ){
			pSRP -> UnRegEventFunction(FileSystem,&VSOUTEVENTID_IrrFileSystemClass_OnFileSystemChange,IrrTextureClassPtr,(void *)IrrTextureClass_OnFileChangeEvent,0);
	    }else{
			pSRP -> RegEventFunction(FileSystem,&VSOUTEVENTID_IrrFileSystemClass_OnFileSystemChange,IrrTextureClassPtr,(void *)IrrTextureClass_OnFileChangeEvent,0);
		}		
		return;
	}
	if( EnableFlag == VS_FALSE ){
	    UnRegCallBackProc = (DriveClass_UnRegCallBackProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_UnRegCallBack);
	    if( UnRegCallBackProc != NULL )
		    UnRegCallBackProc(DriveObject,IrrTextureClassPtr->TextureFile.Buf,IrrTextureClassPtr,(void *)IrrTextureClass_OnFileChangeEvent);
    }else{
	    RegCallBackProc = (DriveClass_RegCallBackProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_RegCallBack);
	    if( RegCallBackProc != NULL )
		    RegCallBackProc(DriveObject,IrrTextureClassPtr->TextureFile.Buf,IrrTextureClassPtr,(void *)IrrTextureClass_OnFileChangeEvent);
    }
	return;
}

VS_INT32 SRPCALLBACK IrrTextureClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrTextureClass *IrrTextureClassPtr;
    //VS_EVENTPARAM_RUNPARAM *ResponseParam,*RequestParam;
    //void *ChildObject;
    VS_ULONG DwordTemp;
	video::ITexture *Texture;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrTextureClassPtr = (struct StructOfIrrTextureClass *)LocalEventParaPtr -> DesObject;
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
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
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
		if( IrrTextureClassPtr->TextureFile.Buf != NULL ){
			IrrTextureClass_Load(IrrTextureClassPtr,IrrTextureClassPtr->TextureFile.Buf);
			IrrTextureClass_SetFileChangeEventCapture(IrrTextureClassPtr,VS_TRUE);		
		}
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
		Texture = (video::ITexture *)IrrObjectClass_GetIrrObject(IrrTextureClassPtr);
		if( Texture != NULL ){
			IrrObjectClass_SetIrrObject(IrrTextureClassPtr,NULL);
			Texture -> SetSRPObject(NULL);
			Texture ->drop();
		}
		IrrTextureClass_SetFileChangeEventCapture(IrrTextureClassPtr,VS_FALSE);		
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
        switch( LocalEventParaPtr -> RequestParam -> LParam ){
        case VSATTRINDEX_IRRTEXTURECLASS_TEXTUREFILE :
			if( pSRP -> IsActive(IrrTextureClassPtr) == VS_FALSE )
				break;
			IrrTextureClass_SetFileChangeEventCapture(IrrTextureClassPtr,VS_FALSE);		
            break;
        }
        break;
    //---------------------------------------------------------------------------
    //---instance attribute change
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONATTRIBUTECHANGE:
        switch( LocalEventParaPtr -> RequestParam -> LParam ){
        case VSATTRINDEX_IRRTEXTURECLASS_TEXTUREFILE :
			IrrTextureClass_Load(IrrTextureClassPtr,IrrTextureClassPtr->TextureFile.Buf);
			IrrTextureClass_SetFileChangeEventCapture(IrrTextureClassPtr,VS_TRUE);		
            break;
        }
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
    //---event input para to script para
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONVSTOSCRIPTINPUTPARA:
        //---LParam = (VS_ULONG)&EventUUID,SParam = (VS_ULONG)&EventParam
        //---ResponseParam = pSRP -> GetResponseBuf( );
        //---INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //---ResponseParam -> LParam = 0; //---0 not convert,==1 convert[is no response, default is convert]
        DwordTemp = pSRP -> EventNameToDWORD( (VS_UUID *)LocalEventParaPtr -> RequestParam -> LParam );
        switch( DwordTemp ){
        case 0X384f404a :  //----event OnChange
            break;
        }
        //---pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    //---script para to event input para
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONSCRIPTTOVSINPUTPARA:
        //---stack top is parameter number, arg0,arg1,...,arg number
        //---LParam = (VS_ULONG)&EventUUID,SParam = (VS_ULONG)&EventParam
        //---ResponseParam = pSRP -> GetResponseBuf( );
        //---INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //---ResponseParam -> LParam = 0; 
        DwordTemp = pSRP -> EventNameToDWORD( (VS_UUID *)LocalEventParaPtr -> RequestParam -> LParam );
        switch( DwordTemp ){
        case 0X384f404a :  //----event OnChange
            break;
        }
        //---pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    //---event output para to script para
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONVSTOSCRIPTOUTPUTPARA:
        //---LParam = (VS_ULONG)&EventUUID,SParam = (VS_ULONG)&EventParam
        //---ResponseParam = pSRP -> GetResponseBuf( );
        //---INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //---ResponseParam -> LParam = 0; //---0 not convert,==1 convert[is no response, default is convert]
        DwordTemp = pSRP -> EventNameToDWORD( (VS_UUID *)LocalEventParaPtr -> RequestParam -> LParam );
        switch( DwordTemp ){
        case 0X384f404a :  //----event OnChange
            break;
        }
        //---pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    //---script para to event output para
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONSCRIPTTOVSOUTPUTPARA:
        //---stack top is parameter number, arg0,arg1,...,arg number
        //---LParam = (VS_ULONG)&EventUUID,SParam = (VS_ULONG)&EventParam;
        //---ResponseParam = pSRP -> GetResponseBuf( );
        //---INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //---ResponseParam -> LParam = 0;
        DwordTemp = pSRP -> EventNameToDWORD( (VS_UUID *)LocalEventParaPtr -> RequestParam -> LParam );
        switch( DwordTemp ){
        case 0X384f404a :  //----event OnChange
            break;
        }
        //---pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    }
    //---------------------------------------------------------------------------
    return VSEVENTMANAGER_DISPATCH;
}

void SRPAPI IrrTextureClass_OnBeforeCreate(void *Object)
{
	pSRP -> ExecNameScript(Object,"OnBeforeCreate",0,0);
    return;
}

void SRPAPI IrrTextureClass_OnAfterCreate(void *Object)
{
	pSRP -> ExecNameScript(Object,"OnAfterCreate",0,0);
    return;
}

void SRPAPI IrrTextureClass_TriggerChangeEvent(void *Object)
{
	pSRP -> ProcessEvent(&VSOUTEVENTID_IrrTextureClass_OnChange,Object,NULL,NULL);
    return;
}

VS_INT32 SRPAPI IrrTextureClass_Lua_TriggerChangeEvent(void)
{
	void *Object;

	Object = pSRP -> LuaToObject(1);
	IrrTextureClass_TriggerChangeEvent(Object);
    return 0;
}

void SRPAPI IrrTextureClass_SetIrrTexture(void *Object,void *IrrTexturePtr)
{
	video::ITexture *OldTexture;

	OldTexture = (video::ITexture *)IrrObjectClass_GetIrrObject(Object);
	if( OldTexture != NULL ){
		IrrObjectClass_SetIrrObject(Object,NULL);
		OldTexture -> SetSRPObject(NULL);
		OldTexture -> drop();
	}
	IrrObjectClass_SetIrrObject(Object,IrrTexturePtr);
	pSRP -> ProcessEvent(&VSOUTEVENTID_IrrTextureClass_OnChange,Object,NULL,NULL);
}

void *IrrTextureClass_GetTexture(VS_CHAR *FileName,VS_UUID *DefaultObjectID)
{
	void *ObjectTemp;
	VS_UUID ObjectID;

	if( FileName == NULL || FileName[0] == 0 )
		return NULL;
	switch( FileName[0] ){
	case '$' : //Object Name
		ObjectTemp = pSRP -> GetObjectEx(NULL,&FileName[1] );
		if( ObjectTemp == NULL )
			return NULL;
		break;
	case '@' : //Object ID
		pSRP -> StringToUuid(&FileName[1],&ObjectID);
		ObjectTemp = pSRP -> GetObject(&ObjectID);
		if( ObjectTemp == NULL )
			return NULL;
		break;
	default:
		ObjectTemp = pSRP -> GetObject(DefaultObjectID);
		if( ObjectTemp != NULL )
			pSRP -> ChangeObject(ObjectTemp,VSATTRINDEX_IRRMESHCLASS_MESHFILE,FileName );
		else
			return NULL;
		break;
	}
	pSRP -> Active(ObjectTemp);
	return ObjectTemp;
}