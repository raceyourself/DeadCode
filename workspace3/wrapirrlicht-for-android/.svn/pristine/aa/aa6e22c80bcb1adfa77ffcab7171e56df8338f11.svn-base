/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"
#include "SRPIrrlichtES2Engine_Irr.H"

using namespace irr;

static VS_ULONG IrrSceneManagerClass_ClassLayer;
#define IRRSCENEMANAGERCLASS_LOCALVARINDEX   1

struct StructOfIrrSceneManagerClassLocalBuf{
	VS_UUID SceneCollisionManagerObjectID;
	VS_UUID MeshManipulatorObjectID;
};


VS_INT32 SRPCALLBACK IrrSceneManagerClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrSceneManagerClass *IrrSceneManagerClassPtr;
    //VS_EVENTPARAM_RUNPARAM *ResponseParam,*RequestParam;
    void *ChildObject;
	struct StructOfIrrSceneManagerClassLocalBuf *IrrSceneManagerClassLocalBuf;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrSceneManagerClassPtr = (struct StructOfIrrSceneManagerClass *)LocalEventParaPtr -> DesObject;
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
		IrrSceneManagerClass_ClassLayer = pSRP -> GetLayer(pSRP -> GetObject(&VSOBJID_IrrSceneManagerClass));
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
		IrrSceneManagerClassLocalBuf = (struct StructOfIrrSceneManagerClassLocalBuf *)pSRP -> MallocPrivateBuf( IrrSceneManagerClassPtr, IrrSceneManagerClass_ClassLayer,IRRSCENEMANAGERCLASS_LOCALVARINDEX,sizeof(struct StructOfIrrSceneManagerClassLocalBuf) );
		memset( IrrSceneManagerClassLocalBuf, 0, sizeof(struct StructOfIrrSceneManagerClassLocalBuf) );
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
		IrrSceneManagerClassLocalBuf = (struct StructOfIrrSceneManagerClassLocalBuf *)pSRP -> GetPrivateBuf( IrrSceneManagerClassPtr, IrrSceneManagerClass_ClassLayer,IRRSCENEMANAGERCLASS_LOCALVARINDEX, NULL );
		ChildObject = pSRP -> GetObject( &IrrSceneManagerClassLocalBuf -> SceneCollisionManagerObjectID );
		if( ChildObject != NULL )
			pSRP -> FreeObject(ChildObject);
		ChildObject = pSRP -> GetObject( &IrrSceneManagerClassLocalBuf -> MeshManipulatorObjectID );
		if( ChildObject != NULL )
			pSRP -> FreeObject(ChildObject);
		pSRP -> FreePrivate( IrrSceneManagerClassPtr, IrrSceneManagerClass_ClassLayer,IRRSCENEMANAGERCLASS_LOCALVARINDEX );
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
    }
    //---------------------------------------------------------------------------
    return VSEVENTMANAGER_DISPATCH;
}

