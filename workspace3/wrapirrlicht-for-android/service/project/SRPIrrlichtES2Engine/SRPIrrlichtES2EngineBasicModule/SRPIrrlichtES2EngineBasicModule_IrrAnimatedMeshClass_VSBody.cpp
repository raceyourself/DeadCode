/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"
#include "SRPIrrlichtES2Engine_Irr.H"

using namespace irr;

//--------------------------------------------------------------------------------------------------------------------------------
VS_BOOL SRPAPI IrrAnimatedMeshClass_Load(void *Object,VS_INT8 * FileName)
{
	struct StructOfIrrAnimatedMeshClass *IrrAnimatedMeshClassPtr;
	VS_ULONG FileHandle;
	VS_ULONG FileDataSize;
	void *ChildObject;
	VS_INT8 *FileDataPtr;
	irr::scene::ISceneManager* smgr;
	irr::scene::IAnimatedMesh* mesh,*Oldmesh;

	if( pSRP -> IsActive(Object) == VS_FALSE )
		return VS_FALSE;
	if( FileName == NULL || strlen(FileName) == 0 )
		return VS_FALSE;
	smgr = (irr::scene::ISceneManager*)IrrSceneNodeClass_GetIrrSceneManager(Object);
	if( smgr == NULL )
		return VS_FALSE;
	IrrAnimatedMeshClassPtr = (struct StructOfIrrAnimatedMeshClass *)Object;
	IrrAnimatedMeshClassPtr -> LoadResult = VS_FALSE;
	if( strchr(FileName,':') == NULL || ( FileName[1] == ':' && FileName[2] == '\\' ) ){ 
		SRPCALLEX1(pSRP,IrrAnimatedMeshClass_OnBeforeCreate,Object);
		mesh = (irr::scene::IAnimatedMesh*)smgr -> getMesh(FileName);
		if( mesh != NULL ){
			IrrAnimatedMeshClassPtr -> LoadResult = VS_TRUE;
			mesh -> grab();
			mesh -> SetSRPObject(Object);
		}		
		Oldmesh = (irr::scene::IAnimatedMesh *)IrrObjectClass_GetIrrObject(Object);
		if( Oldmesh != NULL ){
			IrrObjectClass_SetIrrObject(Object,NULL);
			Oldmesh -> SetSRPObject(NULL);
			Oldmesh -> drop();
		}
		IrrObjectClass_SetIrrObject(Object,mesh);
		SRPCALLEX1(pSRP,IrrAnimatedMeshClass_OnAfterCreate,Object);
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMeshClass_OnChange,Object,NULL,NULL);
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
	SRPCALLEX1(pSRP,IrrAnimatedMeshClass_OnBeforeCreate,Object);
	mesh = (irr::scene::IAnimatedMesh*)smgr -> getMesh(FileName,FileDataPtr,FileDataSize);
	if( mesh != NULL ){
		IrrAnimatedMeshClassPtr -> LoadResult = VS_TRUE;
		mesh -> grab();
		mesh -> SetSRPObject(Object);
	}
	Oldmesh = (irr::scene::IAnimatedMesh *)IrrObjectClass_GetIrrObject(Object);
	if( Oldmesh != NULL ){
		IrrObjectClass_SetIrrObject(Object,NULL);
		Oldmesh -> SetSRPObject(NULL);
		Oldmesh -> drop();
	}
	IrrObjectClass_SetIrrObject(Object,mesh);
	SRPCALL2(pSRP,DriveClass_Close,ChildObject, FileHandle );
	SRPCALLEX1(pSRP,IrrAnimatedMeshClass_OnAfterCreate,Object);
	pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMeshClass_OnChange,Object,NULL,NULL);
	return VS_TRUE;
}

//--------------------------------------------------------------------------------------------------------------------------------
VS_INT32 SRPAPI IrrAnimatedMeshClass_OnFileChangeEvent(VS_ULONG FunctionChoice,void *EventPara)
{
	VS_EVENTPARAM *LocalEventParaPtr;
	struct StructOfIrrAnimatedMeshClass *IrrAnimatedMeshClassPtr;

    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrAnimatedMeshClassPtr = (struct StructOfIrrAnimatedMeshClass *)LocalEventParaPtr -> DesObject;
	if( pSRP -> IsActive(IrrAnimatedMeshClassPtr) == VS_TRUE ){
		if( IrrAnimatedMeshClassPtr->MeshFile.Buf != NULL )
			IrrAnimatedMeshClass_Load(IrrAnimatedMeshClassPtr,IrrAnimatedMeshClassPtr->MeshFile.Buf);
	}
	return VSEVENTMANAGER_DISPATCH;
}

void IrrAnimatedMeshClass_SetFileChangeEventCapture( struct StructOfIrrAnimatedMeshClass *IrrAnimatedMeshClassPtr, VS_BOOL EnableFlag )
{
	DriveClass_GetDriveProc GetDriveProc;
	DriveClass_UnRegCallBackProc UnRegCallBackProc;
	DriveClass_RegCallBackProc RegCallBackProc;
	void *DriveObject;

	GetDriveProc = (DriveClass_GetDriveProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_GetDrive);
	if( GetDriveProc == NULL || IrrAnimatedMeshClassPtr->MeshFile.Buf == NULL )
		return;
	DriveObject = GetDriveProc( NULL, IrrAnimatedMeshClassPtr->MeshFile.Buf );			    
	if( DriveObject == NULL ){
		void *FileSystem,*DeviceObject;

		SRPCALL_RET1(pSRP,IrrDeviceClass_GetCurDevice,DeviceObject,NULL,NULL);
		if( DeviceObject == NULL )
			return;
		FileSystem = IrrDeviceClass_GetFileSystem(DeviceObject);
		if( FileSystem == NULL )
			return;
		if( EnableFlag == VS_FALSE ){
			pSRP -> UnRegEventFunction(FileSystem,&VSOUTEVENTID_IrrFileSystemClass_OnFileSystemChange,IrrAnimatedMeshClassPtr,(void *)IrrAnimatedMeshClass_OnFileChangeEvent,0);
	    }else{
			pSRP -> RegEventFunction(FileSystem,&VSOUTEVENTID_IrrFileSystemClass_OnFileSystemChange,IrrAnimatedMeshClassPtr,(void *)IrrAnimatedMeshClass_OnFileChangeEvent,0);
		}		
		return;
	}
	if( EnableFlag == VS_FALSE ){
	    UnRegCallBackProc = (DriveClass_UnRegCallBackProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_UnRegCallBack);
	    if( UnRegCallBackProc != NULL )
		    UnRegCallBackProc(DriveObject,IrrAnimatedMeshClassPtr->MeshFile.Buf,IrrAnimatedMeshClassPtr,(void *)IrrAnimatedMeshClass_OnFileChangeEvent);
    }else{
	    RegCallBackProc = (DriveClass_RegCallBackProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_RegCallBack);
	    if( RegCallBackProc != NULL )
		    RegCallBackProc(DriveObject,IrrAnimatedMeshClassPtr->MeshFile.Buf,IrrAnimatedMeshClassPtr,(void *)IrrAnimatedMeshClass_OnFileChangeEvent);
    }
	return;
}

//-----------------------------------------------------------------
VS_BOOL SRPAPI IrrAnimatedMeshClass_BeforeChangeNotifyProc(void *Object, VS_ULONG Para,OBJECTATTRIBUTEINDEX AttributeIndex, VS_INT8 *NewValue,VS_INT32 DebugEditFlag)
{
	struct StructOfIrrAnimatedMeshClass *IrrAnimatedMeshClassPtr;

	IrrAnimatedMeshClassPtr = (struct StructOfIrrAnimatedMeshClass *)Object;
	if( pSRP -> IsActive(IrrAnimatedMeshClassPtr) == VS_FALSE )
		return VS_TRUE;
	switch( AttributeIndex ){
    case VSATTRINDEX_IRRANIMATEDMESHCLASS_MESHFILE :
		IrrAnimatedMeshClass_SetFileChangeEventCapture(IrrAnimatedMeshClassPtr,VS_FALSE);		
		break;
	}
	return VS_TRUE;
}

void SRPAPI IrrAnimatedMeshClass_ChangeNotifyProc(void *Object,VS_ULONG Para,OBJECTATTRIBUTEINDEX AttributeIndex,VS_ATTRIBUTEINDEXMAP *AttributeIndexMap)
{
	struct StructOfIrrAnimatedMeshClass *IrrAnimatedMeshClassPtr;

	IrrAnimatedMeshClassPtr = (struct StructOfIrrAnimatedMeshClass *)Object;
	if( pSRP -> IsActive(IrrAnimatedMeshClassPtr) == VS_FALSE )
		return;
	switch( AttributeIndex ){
    case VSATTRINDEX_IRRANIMATEDMESHCLASS_MESHFILE :
		IrrAnimatedMeshClass_Load(IrrAnimatedMeshClassPtr,IrrAnimatedMeshClassPtr->MeshFile.Buf);
		IrrAnimatedMeshClass_SetFileChangeEventCapture(IrrAnimatedMeshClassPtr,VS_TRUE);		
		break;
	}
	return;
}

VS_INT32 SRPCALLBACK IrrAnimatedMeshClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrAnimatedMeshClass *IrrAnimatedMeshClassPtr;
    //VS_EVENTPARAM_RUNPARAM *ResponseParam,*RequestParam;
    //void *ChildObject;
	irr::scene::IAnimatedMesh* mesh;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrAnimatedMeshClassPtr = (struct StructOfIrrAnimatedMeshClass *)LocalEventParaPtr -> DesObject;
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
		if( pSRP -> IsDirectInst(&VSOBJID_IrrAnimatedMeshClass,IrrAnimatedMeshClassPtr) == VS_FALSE &&
			pSRP -> IsInst(&VSOBJID_IrrQ3LevelMeshClass,IrrAnimatedMeshClassPtr) == VS_FALSE )
			break;
		if( IrrAnimatedMeshClassPtr->MeshFile.Buf != NULL ){
			IrrAnimatedMeshClass_Load(IrrAnimatedMeshClassPtr,IrrAnimatedMeshClassPtr->MeshFile.Buf);
			IrrAnimatedMeshClass_SetFileChangeEventCapture(IrrAnimatedMeshClassPtr,VS_TRUE);		
		}
		pSRP -> RegBeforeChangeCallBack( IrrAnimatedMeshClassPtr, IrrAnimatedMeshClass_BeforeChangeNotifyProc, 0 , VS_FALSE );
		pSRP -> RegChangeCallBack( IrrAnimatedMeshClassPtr, IrrAnimatedMeshClass_ChangeNotifyProc, 0 , VS_FALSE );
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
		if( pSRP -> IsDirectInst(&VSOBJID_IrrAnimatedMeshClass,IrrAnimatedMeshClassPtr) == VS_FALSE &&
			pSRP -> IsInst(&VSOBJID_IrrQ3LevelMeshClass,IrrAnimatedMeshClassPtr) == VS_FALSE)
			break;
		pSRP -> UnRegBeforeChangeCallBack( IrrAnimatedMeshClassPtr, IrrAnimatedMeshClass_BeforeChangeNotifyProc, 0 );
		pSRP -> UnRegChangeCallBack( IrrAnimatedMeshClassPtr, IrrAnimatedMeshClass_ChangeNotifyProc, 0 );
		mesh = (irr::scene::IAnimatedMesh*)IrrObjectClass_GetIrrObject(IrrAnimatedMeshClassPtr);
		if( mesh != NULL ){
			IrrObjectClass_SetIrrObject(IrrAnimatedMeshClassPtr,NULL);
			mesh -> SetSRPObject(NULL);
			mesh ->drop();
		}
		IrrAnimatedMeshClass_SetFileChangeEventCapture(IrrAnimatedMeshClassPtr,VS_FALSE);	
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

void SRPAPI IrrAnimatedMeshClass_OnBeforeCreate(void *Object)
{
	pSRP -> ExecNameScript(Object,"OnBeforeCreate",0,0);
    return;
}

void SRPAPI IrrAnimatedMeshClass_OnAfterCreate(void *Object)
{
	pSRP -> ExecNameScript(Object,"OnAfterCreate",0,0);
    return;
}

void *SRPAPI IrrAnimatedMeshClass_GetMesh(void *Object,void *MeshObject,VS_INT32 Frame,VS_INT32 DetailLevel,VS_INT32 StartFrameLoop,VS_INT32 EndFrameLoop)
{
	irr::scene::IAnimatedMesh* AnimatedMesh;
	irr::scene::IMesh* Mesh;

	AnimatedMesh = (irr::scene::IAnimatedMesh*)IrrObjectClass_GetIrrObject(Object);
	if( AnimatedMesh == NULL )
		return NULL;
	if( MeshObject == NULL )
		return NULL;
	pSRP -> Deactive(MeshObject);
	((struct StructOfIrrObjectClass *)MeshObject) -> WrapIrrFlag = VS_TRUE;
	Mesh = AnimatedMesh -> getMesh(Frame,DetailLevel,StartFrameLoop,EndFrameLoop);
	IrrObjectClass_SetIrrObject(MeshObject,Mesh);
	pSRP -> Active(MeshObject);
	return MeshObject;
}

VS_INT32 SRPAPI IrrAnimatedMeshClass_Lua_GetMesh(void)
{
	void *Object,*MeshObject;
	VS_INT32 Frame,DetailLevel,StartFrameLoop,EndFrameLoop;

	Object = pSRP -> LuaToObject(1);
	MeshObject = pSRP -> LuaToObject(2);
	Frame = pSRP -> LuaToInt(3);
	DetailLevel = pSRP -> LuaToInt(4);
	StartFrameLoop = pSRP -> LuaToInt(5);
	EndFrameLoop = pSRP -> LuaToInt(6);
	MeshObject=IrrAnimatedMeshClass_GetMesh(Object,MeshObject,Frame,DetailLevel,StartFrameLoop,EndFrameLoop);
	if( MeshObject == NULL )
		pSRP -> LuaPushNil();
	else
		pSRP -> LuaPushObject(MeshObject);
    return 1;
}

void *IrrAnimatedMeshClass_GetMeshObject(VS_CHAR *FileName,VS_UUID *CreateObjectID,VS_INT32 *MeshNum)
{
	void *ObjectTemp;
	VS_UUID ObjectID;
	VS_INT8 *token;
	static VS_CHAR LocalFileName[256];

	if( FileName == NULL || FileName[0] == 0 )
		return NULL;
	strncpy(LocalFileName,FileName,255);
	LocalFileName[255] = 0;
	token = strtok(LocalFileName,",");
	if( token == NULL )
		return NULL;	
	switch( token[0] ){ 
	case '$' : //Object Name
		ObjectTemp = pSRP -> GetObjectEx(NULL,&token[1] );
		if( ObjectTemp == NULL )
			return NULL;
		break;
	case '@' : //Object ID
		pSRP -> StringToUuid(&token[1],&ObjectID);
		ObjectTemp = pSRP -> GetObject(&ObjectID);
		if( ObjectTemp == NULL )
			return NULL;
		break;
	default:
		if( CreateObjectID == NULL )
			return NULL;
		ObjectTemp = pSRP -> GetObject(CreateObjectID);
		if( ObjectTemp != NULL ){
			pSRP -> ChangeObject(ObjectTemp,VSATTRINDEX_IRRMESHCLASS_MESHFILE,token );			
		}else
			return NULL;
		break;
	}
	pSRP -> Active(ObjectTemp);

	(*MeshNum) = 0;
	token = strtok(NULL,",");
	if( token == NULL )
		return ObjectTemp;	
	(*MeshNum) = atoi(token);

	return ObjectTemp;
}

scene::IMesh* IrrMeshClass_GetIrrMesh(void *MeshObject,VS_INT32 MeshNum)
{
	scene::IAnimatedMesh *AnimatedMesh;

	if( pSRP -> IsInst(&VSOBJID_IrrAnimatedMeshClass,MeshObject) == VS_TRUE ||
		pSRP -> IsInst(&VSOBJID_IrrQ3LevelMeshClass,MeshObject) == VS_TRUE ){
		AnimatedMesh = (scene::IAnimatedMesh *)IrrObjectClass_GetIrrObject(MeshObject);
		if( AnimatedMesh == NULL )
			return NULL;
		return AnimatedMesh -> getMesh(MeshNum);
	}
	return NULL;
}

