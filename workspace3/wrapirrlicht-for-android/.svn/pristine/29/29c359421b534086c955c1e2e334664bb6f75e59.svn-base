/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"
#include "SRPIrrlichtES2Engine_Irr.H"

using namespace irr;

VS_INT32 SRPCALLBACK IrrCameraSceneNodeClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrCameraSceneNodeClass *IrrCameraSceneNodeClassPtr;
    VS_EVENTPARAM_RUNPARAM *ResponseParam;//,*RequestParam;
    //void *ChildObject;
	scene::ICameraSceneNode* cam;
	irr::scene::ISceneManager* smgr;
	void *ParentObject,*ParentSceneNode;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrCameraSceneNodeClassPtr = (struct StructOfIrrCameraSceneNodeClass *)LocalEventParaPtr -> DesObject;
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
		if( IrrCameraSceneNodeClassPtr -> WrapIrrFlag == VS_FALSE ){
			if( pSRP -> IsDirectInst(&VSOBJID_IrrCameraSceneNodeClass,IrrCameraSceneNodeClassPtr) == VS_FALSE )
				break;
			smgr = (irr::scene::ISceneManager*)IrrSceneNodeClass_GetIrrSceneManager(IrrCameraSceneNodeClassPtr);
			ParentObject = pSRP -> GetParent(IrrCameraSceneNodeClassPtr);
			ParentSceneNode = IrrObjectClass_GetIrrObject(ParentObject);
			if( smgr == NULL || ParentObject == NULL || ParentSceneNode == NULL ){
				ResponseParam = pSRP -> GetResponseBuf( );
				INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
				ResponseParam -> LParam = 1; 
				pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
				break;
			}
			if( ParentSceneNode == smgr )
				cam = smgr -> addCameraSceneNode(NULL,
										core::vector3df(IrrCameraSceneNodeClassPtr->Position.X,IrrCameraSceneNodeClassPtr ->Position.Y,IrrCameraSceneNodeClassPtr ->Position.Z),
										core::vector3df(IrrCameraSceneNodeClassPtr->Target.X,IrrCameraSceneNodeClassPtr->Target.Y,IrrCameraSceneNodeClassPtr->Target.Z),
										IrrCameraSceneNodeClassPtr -> Id);
			else
				cam = smgr -> addCameraSceneNode((scene::ISceneNode*)ParentSceneNode,
										core::vector3df(IrrCameraSceneNodeClassPtr->Position.X,IrrCameraSceneNodeClassPtr ->Position.Y,IrrCameraSceneNodeClassPtr ->Position.Z),
										core::vector3df(IrrCameraSceneNodeClassPtr->Target.X,IrrCameraSceneNodeClassPtr->Target.Y,IrrCameraSceneNodeClassPtr->Target.Z),
										IrrCameraSceneNodeClassPtr -> Id);
			cam -> setFarValue(IrrCameraSceneNodeClassPtr -> ZFar);
			cam -> setNearValue(IrrCameraSceneNodeClassPtr -> ZNear);
			cam -> grab();
			cam -> SetSRPObject(IrrCameraSceneNodeClassPtr);
			IrrObjectClass_SetIrrObject(IrrCameraSceneNodeClassPtr,cam);
			pSRP -> ProcessEvent(&VSOUTEVENTID_IrrSceneNodeClass_OnIrrInit,IrrCameraSceneNodeClassPtr,NULL,NULL);
		}else{
			cam = (scene::ICameraSceneNode *)IrrObjectClass_GetIrrObject(IrrCameraSceneNodeClassPtr);
			if( cam == NULL ){
				ResponseParam = pSRP -> GetResponseBuf( );
				INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
				ResponseParam -> LParam = 1; 
				pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
				break;
			}
			core :: vector3df Temp;
			Temp = cam -> getTarget();
			IrrCameraSceneNodeClassPtr -> Target.X = Temp.X;
			IrrCameraSceneNodeClassPtr -> Target.Y = Temp.Y;
			IrrCameraSceneNodeClassPtr -> Target.Z = Temp.Z;
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
		if( IrrCameraSceneNodeClassPtr -> WrapIrrFlag == VS_TRUE )
			break;
		if( pSRP -> IsDirectInst(&VSOBJID_IrrCameraSceneNodeClass,IrrCameraSceneNodeClassPtr) == VS_FALSE )
			break;
		cam = (scene::ICameraSceneNode*)IrrObjectClass_GetIrrObject(IrrCameraSceneNodeClassPtr);
		if( cam == NULL )
			break;
		//---从父队列中移出
		cam -> remove();		
		IrrObjectClass_SetIrrObject(IrrCameraSceneNodeClassPtr,NULL);
		cam -> SetSRPObject(NULL);
		cam -> drop();
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
		if( pSRP -> IsActive(IrrCameraSceneNodeClassPtr) == VS_FALSE )
			break;
		cam = (scene::ICameraSceneNode*)IrrObjectClass_GetIrrObject(IrrCameraSceneNodeClassPtr);
		if( cam == NULL )
			break;
        switch( LocalEventParaPtr -> RequestParam -> LParam ){
        case VSATTRINDEX_IRRCAMERASCENENODECLASS_TARGET :
			cam -> setTarget(core::vector3df(IrrCameraSceneNodeClassPtr->Target.X,IrrCameraSceneNodeClassPtr->Target.Y,IrrCameraSceneNodeClassPtr->Target.Z));
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
    }
    //---------------------------------------------------------------------------
    return VSEVENTMANAGER_DISPATCH;
}

void SRPAPI IrrCameraSceneNodeClass_GetTarget(void *Object,struct StructOfSRP3DVector * Position)
{
	scene::ICameraSceneNode* cam;
	core::vector3df Temp;

	Position -> X = 0;
	Position -> Y = 0;
	Position -> Z = 0;
	cam = (scene::ICameraSceneNode*)IrrObjectClass_GetIrrObject(Object);
	if( cam == NULL )
		return;
	Temp = cam -> getTarget();
	Position -> X = Temp.X;
	Position -> Y = Temp.Y;
	Position -> Z = Temp.Z;
    return;
}

extern void LuaPushSRP3DVector(struct StructOfSRP3DVector * Position);

VS_INT32 SRPAPI IrrCameraSceneNodeClass_Lua_GetTarget(void)
{
	struct StructOfSRP3DVector Temp;
	void *Object;

	Object = pSRP -> LuaToObject(1);
	IrrCameraSceneNodeClass_GetTarget(Object,&Temp);
	LuaPushSRP3DVector( &Temp );
    return 1;
}
