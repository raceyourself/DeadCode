/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"

using namespace irr;

static VS_ULONG IrrFileSystemClass_ClassLayer;
#define IRRFILESYSTEMCLASS_LOCALVARINDEX   1

struct StructOfIrrFileSystemClass_ZipFileArchiveItem{
	struct StructOfIrrFileSystemClass_ZipFileArchiveItem *Up,*Down;
	VS_CHAR FileName[1];
};

struct StructOfIrrFileSystemClassLocalBuf{
	struct StructOfIrrFileSystemClass_ZipFileArchiveItem *ZipFileArchiveItemRoot;
};


//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
VS_BOOL SRPAPI IrrFileSystemClass_LoadZipFileArchiveItem(void *Object,VS_INT8 * FileName)
{
	VS_ULONG FileHandle;
	VS_ULONG FileDataSize;
	void *ChildObject;
	VS_INT8 *FileDataPtr;
	io :: IFileSystem* fs;

	if( pSRP -> IsActive(Object) == VS_FALSE )
		return VS_FALSE;
	if( FileName == NULL || strlen(FileName) == 0 )
		return VS_FALSE;
	fs = (io :: IFileSystem*)IrrObjectClass_GetIrrObject(Object);
	if( fs == NULL )
		return VS_FALSE;
	if( strchr(FileName,':') == NULL || ( FileName[1] == ':' && FileName[2] == '\\' ) ){ 
		if( fs -> addZipFileArchive(FileName) == true ){
			pSRP -> ProcessEvent(&VSOUTEVENTID_IrrFileSystemClass_OnFileSystemChange,Object,NULL,NULL);
			return VS_TRUE;
		}
		return VS_FALSE;
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
	if( fs -> addZipFileArchive((void*)FileDataPtr,(s32)FileDataSize,FileName) == true ){
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrFileSystemClass_OnFileSystemChange,Object,NULL,NULL);
		return VS_TRUE;
	}
	return VS_FALSE;
}

VS_INT32 SRPAPI IrrFileSystemClass_OnZipFileArchiveItemChangeEvent(VS_ULONG FunctionChoice,void *EventPara)
{
	VS_EVENTPARAM *LocalEventParaPtr;
	struct StructOfIrrFileSystemClass *IrrFileSystemClassPtr;
	struct StructOfIrrFileSystemClassLocalBuf *IrrFileSystemClassLocalBuf;
	struct StructOfIrrFileSystemClass_ZipFileArchiveItem *ZipFileArchiveItem;

    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrFileSystemClassPtr = (struct StructOfIrrFileSystemClass *)LocalEventParaPtr -> DesObject;
	if( pSRP -> IsActive(IrrFileSystemClassPtr) == VS_FALSE )
		return 0;
	IrrFileSystemClassLocalBuf = (struct StructOfIrrFileSystemClassLocalBuf *)pSRP -> GetPrivateBuf( IrrFileSystemClassPtr, IrrFileSystemClass_ClassLayer,IRRFILESYSTEMCLASS_LOCALVARINDEX, NULL );		
	ZipFileArchiveItem = IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot;
	while( ZipFileArchiveItem != NULL ){
		IrrFileSystemClass_LoadZipFileArchiveItem(IrrFileSystemClassPtr,ZipFileArchiveItem -> FileName);
		ZipFileArchiveItem = ZipFileArchiveItem -> Down;
	}
	return VSEVENTMANAGER_DISPATCH;
}

void IrrFileSystemClass_SetZipFileArchiveItemChangeEventCapture( void *Object,struct StructOfIrrFileSystemClass_ZipFileArchiveItem *ZipFileArchiveItem, VS_BOOL EnableFlag )
{
	DriveClass_GetDriveProc GetDriveProc;
	DriveClass_UnRegCallBackProc UnRegCallBackProc;
	DriveClass_RegCallBackProc RegCallBackProc;
	void *DriveObject;

	GetDriveProc = (DriveClass_GetDriveProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_GetDrive);
	if( GetDriveProc == NULL )
		return;
	DriveObject = GetDriveProc( NULL, ZipFileArchiveItem->FileName );			    
	if( DriveObject == NULL )
		return;
	if( EnableFlag == VS_FALSE ){
	    UnRegCallBackProc = (DriveClass_UnRegCallBackProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_UnRegCallBack);
	    if( UnRegCallBackProc != NULL )
		    UnRegCallBackProc(DriveObject,ZipFileArchiveItem->FileName,Object,(void *)IrrFileSystemClass_OnZipFileArchiveItemChangeEvent);
    }else{
	    RegCallBackProc = (DriveClass_RegCallBackProc)pSRP -> GetFunction(&VSFUNCID_DriveClass_RegCallBack);
	    if( RegCallBackProc != NULL )
		    RegCallBackProc(DriveObject,ZipFileArchiveItem->FileName,Object,(void *)IrrFileSystemClass_OnZipFileArchiveItemChangeEvent);
    }
	return;
}

//---------------------------------------------------------------------------------------------
VS_INT32 SRPCALLBACK IrrFileSystemClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrFileSystemClass *IrrFileSystemClassPtr;
    //VS_EVENTPARAM_RUNPARAM *ResponseParam,*RequestParam;
    //void *ChildObject;
    VS_ULONG DwordTemp;
	struct StructOfIrrFileSystemClassLocalBuf *IrrFileSystemClassLocalBuf;
	struct StructOfIrrFileSystemClass_ZipFileArchiveItem *ZipFileArchiveItem;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrFileSystemClassPtr = (struct StructOfIrrFileSystemClass *)LocalEventParaPtr -> DesObject;
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
		IrrFileSystemClass_ClassLayer = pSRP -> GetLayer(pSRP -> GetObject(&VSOBJID_IrrFileSystemClass));
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
		IrrFileSystemClassLocalBuf = (struct StructOfIrrFileSystemClassLocalBuf *)pSRP -> MallocPrivateBuf( IrrFileSystemClassPtr, IrrFileSystemClass_ClassLayer,IRRFILESYSTEMCLASS_LOCALVARINDEX,sizeof(struct StructOfIrrFileSystemClassLocalBuf) );
		memset( IrrFileSystemClassLocalBuf, 0, sizeof(struct StructOfIrrFileSystemClassLocalBuf) );
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
		IrrFileSystemClassLocalBuf = (struct StructOfIrrFileSystemClassLocalBuf *)pSRP -> GetPrivateBuf( IrrFileSystemClassPtr, IrrFileSystemClass_ClassLayer,IRRFILESYSTEMCLASS_LOCALVARINDEX, NULL );		
		while( IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot != NULL ){
			ZipFileArchiveItem = IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot;
			IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot = IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot -> Down;
			IrrFileSystemClass_SetZipFileArchiveItemChangeEventCapture(IrrFileSystemClassPtr,ZipFileArchiveItem,VS_FALSE);
			pSRP -> Free(ZipFileArchiveItem);
		}
		pSRP -> FreePrivate( IrrFileSystemClassPtr, IrrFileSystemClass_ClassLayer,IRRFILESYSTEMCLASS_LOCALVARINDEX );
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
    //---event input para to script para
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONVSTOSCRIPTINPUTPARA:
        //---LParam = (VS_ULONG)&EventUUID,SParam = (VS_ULONG)&EventParam
        //---ResponseParam = pSRP -> GetResponseBuf( );
        //---INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
        //---ResponseParam -> LParam = 0; //---0 not convert,==1 convert[is no response, default is convert]
        DwordTemp = pSRP -> EventNameToDWORD( (VS_UUID *)LocalEventParaPtr -> RequestParam -> LParam );
        switch( DwordTemp ){
        case 0X983b0f26 :  //----event OnFileSystemChange
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
        case 0X983b0f26 :  //----event OnFileSystemChange
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
        case 0X983b0f26 :  //----event OnFileSystemChange
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
        case 0X983b0f26 :  //----event OnFileSystemChange
            break;
        }
        //---pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    }
    //---------------------------------------------------------------------------
    return VSEVENTMANAGER_DISPATCH;
}

void SRPAPI IrrFileSystemClass_AddZipFileArchive(void *Object,VS_CHAR * FileName)
{
	struct StructOfIrrFileSystemClassLocalBuf *IrrFileSystemClassLocalBuf;
	struct StructOfIrrFileSystemClass_ZipFileArchiveItem *ZipFileArchiveItem;
	VS_INT32 Len;

	if( pSRP -> IsActive(Object) == VS_FALSE ){
		pSRP -> Print( "Object %s is not active",pSRP -> GetName(Object));
		return;
	}
	if( FileName == NULL )
		return;
	Len = strlen( FileName );
	if( Len == 0 )
		return;
	ZipFileArchiveItem = (struct StructOfIrrFileSystemClass_ZipFileArchiveItem *)pSRP -> Malloc( sizeof(struct StructOfIrrFileSystemClass_ZipFileArchiveItem) + Len );
	ZipFileArchiveItem -> Up = NULL;
	ZipFileArchiveItem -> Down = NULL;
	strcpy( ZipFileArchiveItem ->FileName, FileName );

	IrrFileSystemClassLocalBuf = (struct StructOfIrrFileSystemClassLocalBuf *)pSRP -> GetPrivateBuf( Object, IrrFileSystemClass_ClassLayer,IRRFILESYSTEMCLASS_LOCALVARINDEX, NULL );		
	if( IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot == NULL )
		IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot = ZipFileArchiveItem;
	else{
		IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot -> Up = ZipFileArchiveItem;
		ZipFileArchiveItem -> Down = IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot;
		IrrFileSystemClassLocalBuf -> ZipFileArchiveItemRoot = ZipFileArchiveItem;
	}
	IrrFileSystemClass_LoadZipFileArchiveItem(Object,FileName);
    IrrFileSystemClass_SetZipFileArchiveItemChangeEventCapture(Object,ZipFileArchiveItem,VS_TRUE);
    return;
}

VS_INT32 SRPAPI IrrFileSystemClass_Lua_AddZipFileArchive(void)
{
	void *Object;
	VS_CHAR *FileName;

	Object = pSRP -> LuaToObject(1);
	FileName = pSRP -> LuaToString(2);
    IrrFileSystemClass_AddZipFileArchive(Object,FileName);
    return 0;
}

