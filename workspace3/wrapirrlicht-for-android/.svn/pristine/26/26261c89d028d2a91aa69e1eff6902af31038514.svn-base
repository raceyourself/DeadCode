/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"
#include "irrlicht.h"

using namespace irr;

static VS_ULONG IrrObjectClass_ClassLayer;
#define IRROBJECTCLASS_LOCALVARINDEX   1

struct StructOfIrrObjectClassLocalBuf{
	irr::IReferenceCounted* ReferenceCounted;
};

VS_INT32 SRPCALLBACK IrrObjectClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrObjectClass *IrrObjectClassPtr;
    VS_EVENTPARAM_RUNPARAM *ResponseParam;//,*RequestParam;
    //void *ChildObject;
	struct StructOfIrrObjectClassLocalBuf *IrrObjectClassLocalBuf;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrObjectClassPtr = (struct StructOfIrrObjectClass *)LocalEventParaPtr -> DesObject;
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
		IrrObjectClass_ClassLayer = pSRP -> GetLayer(pSRP -> GetObject(&VSOBJID_IrrObjectClass));
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
		IrrObjectClassLocalBuf = (struct StructOfIrrObjectClassLocalBuf *)pSRP -> MallocPrivateBuf( IrrObjectClassPtr, IrrObjectClass_ClassLayer,IRROBJECTCLASS_LOCALVARINDEX,sizeof(struct StructOfIrrObjectClassLocalBuf) );
		IrrObjectClassLocalBuf -> ReferenceCounted = NULL;
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
		IrrObjectClassLocalBuf = (struct StructOfIrrObjectClassLocalBuf *)pSRP -> GetPrivateBuf( IrrObjectClassPtr, IrrObjectClass_ClassLayer,IRROBJECTCLASS_LOCALVARINDEX, NULL );
		pSRP -> FreePrivate( IrrObjectClassPtr, IrrObjectClass_ClassLayer,IRROBJECTCLASS_LOCALVARINDEX );
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
		if( IrrObjectClass_OnIrrActivating(IrrObjectClassPtr) == VS_FALSE ){
			ResponseParam = pSRP -> GetResponseBuf( );
			INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
			ResponseParam -> LParam = 1; 
			pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
		}
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
    }
    //---------------------------------------------------------------------------
    return VSEVENTMANAGER_DISPATCH;
}

void SRPAPI IrrObjectClass_SetIrrObject(void *Object,void *IrrObject)
{
    struct StructOfIrrObjectClass *IrrObjectClassPtr;
	struct StructOfIrrObjectClassLocalBuf *IrrObjectClassLocalBuf;

	if( Object == NULL )
        return;
	IrrObjectClassPtr = (struct StructOfIrrObjectClass *)Object;
	IrrObjectClassLocalBuf = (struct StructOfIrrObjectClassLocalBuf *)pSRP -> GetPrivateBuf( IrrObjectClassPtr, IrrObjectClass_ClassLayer,IRROBJECTCLASS_LOCALVARINDEX, NULL );
	IrrObjectClassLocalBuf ->ReferenceCounted = (irr::IReferenceCounted*)IrrObject;
}

void *SRPAPI IrrObjectClass_GetIrrObject(void *Object)
{
    struct StructOfIrrObjectClass *IrrObjectClassPtr;
	struct StructOfIrrObjectClassLocalBuf *IrrObjectClassLocalBuf;

	if( Object == NULL )
		return NULL;
	IrrObjectClassPtr = (struct StructOfIrrObjectClass *)Object;
	IrrObjectClassLocalBuf = (struct StructOfIrrObjectClassLocalBuf *)pSRP -> GetPrivateBuf( IrrObjectClassPtr, IrrObjectClass_ClassLayer,IRROBJECTCLASS_LOCALVARINDEX, NULL );
	return IrrObjectClassLocalBuf ->ReferenceCounted;
}

void SRPAPI IrrObjectClass_SetIrrParentSceneNode(void *Object,void *IrrParentObject)
{
    return;
}

VS_BOOL SRPAPI IrrObjectClass_OnIrrActivating(void *Object)
{
	VS_BOOL Result;
	VS_INT32 n,m;

	Result = VS_TRUE;
	n = pSRP -> LuaGetTop();
	if( pSRP -> ExecNameScript(Object,"OnIrrActivating",0,-1) == VS_TRUE ){
		m = pSRP -> LuaGetTop();
		if( m > n && pSRP -> LuaIsBool(n+1) == VS_TRUE )
			Result = pSRP -> LuaToBool(n+1);
	}
	m = pSRP -> LuaGetTop();
	if( m > n )
		pSRP -> LuaPop(m-n);
    return Result;
}

void LuaToSRP3DVector(VS_INT32 Index,struct StructOfSRP3DVector * Position)
{
	if( pSRP -> LuaIsTable(Index) == VS_FALSE ){
		Position -> X = 0;
		Position -> Y = 0;
		Position -> Z = 0;
	}else{
		pSRP -> LuaPushInt(1);
		pSRP -> LuaGetTable(Index);
		Position -> X = pSRP -> LuaToNumber(-1);
		pSRP -> LuaPop(1);

		pSRP -> LuaPushInt(2);
		pSRP -> LuaGetTable(Index);
		Position -> Y = pSRP -> LuaToNumber(-1);
		pSRP -> LuaPop(1);

		pSRP -> LuaPushInt(3);
		pSRP -> LuaGetTable(Index);
		Position -> Z = pSRP -> LuaToNumber(-1);
		pSRP -> LuaPop(1);
	}
	return;
}

void LuaPushSRP3DVector(struct StructOfSRP3DVector * Position)
{
	pSRP -> LuaNewTable();

	pSRP -> LuaPushInt(1);
	pSRP -> LuaPushNumber(Position -> X);
	pSRP -> LuaSetTable(-3);
	pSRP -> LuaPushInt(2);
	pSRP -> LuaPushNumber(Position -> Y);
	pSRP -> LuaSetTable(-3);
	pSRP -> LuaPushInt(3);
	pSRP -> LuaPushNumber(Position -> Z);
	pSRP -> LuaSetTable(-3);
}


VS_CHAR *SRPAPI IrrObjectClass_Load(void *Object,VS_INT8 * FileName,VS_BOOL *FileFlag,VS_ULONG *MemorySize)
{
	VS_ULONG FileHandle;
	VS_ULONG FileDataSize;
	void *ChildObject;
	VS_INT8 *FileDataPtr;

	if( FileName == NULL || strlen(FileName) == 0 )
		return NULL;
	if( strchr(FileName,':') == NULL || ( FileName[1] == ':' && FileName[2] == '\\' ) ){ 
		(*FileFlag) = VS_TRUE;
		return FileName;
	}
	SRPCALL_RET2(pSRP,DriveClass_GetDrive,ChildObject,NULL,NULL,FileName);
	if( ChildObject == NULL )
		return NULL;
	SRPCALL_RET5(pSRP,DriveClass_Open,FileHandle,0,ChildObject,strchr(FileName,':'),VS_FALSE,NULL,NULL);
	if( FileHandle == 0 )
		return NULL;
	SRPCALL_RET3(pSRP,DriveClass_Read,FileDataPtr,NULL,ChildObject,FileHandle,&FileDataSize);
	if( FileDataPtr == NULL ){
		SRPCALL2(pSRP,DriveClass_Close,ChildObject, FileHandle );
		return NULL;
	}
	(*MemorySize) = FileDataSize;
	(*FileFlag) = VS_FALSE;
	return FileDataPtr;
}
