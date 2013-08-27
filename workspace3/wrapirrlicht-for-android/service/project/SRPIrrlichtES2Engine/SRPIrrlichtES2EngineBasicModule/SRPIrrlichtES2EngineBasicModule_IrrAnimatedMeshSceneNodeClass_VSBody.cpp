/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"
#include "SRPIrrlichtES2Engine_Irr.H"

using namespace irr;

static VS_ULONG IrrAnimatedMeshSceneNodeClass_ClassLayer;
#define IRRANIMATEDMESHSCENENODECLASS_LOCALVARINDEX   1

struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf{
	VS_UUID MeshObjectID;
	VS_UUID UsedMeshObjectID;
	VS_INT32 MeshNum;
};

VS_BOOL IrrAnimatedMeshSceneNodeClass_CreateMesh(struct StructOfIrrAnimatedMeshSceneNodeClass *IrrAnimatedMeshSceneNodeClassPtr)
{
	struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf *IrrAnimatedMeshSceneNodeClassLocalBuf;
	scene::IAnimatedMeshSceneNode* node;
	irr::scene::ISceneManager* smgr;
	void *ParentObject,*ParentSceneNode;
	irr::scene::IAnimatedMesh* mesh;
	void *ObjectTemp;

	smgr = (irr::scene::ISceneManager*)IrrSceneNodeClass_GetIrrSceneManager(IrrAnimatedMeshSceneNodeClassPtr);
	ParentObject = pSRP -> GetParent(IrrAnimatedMeshSceneNodeClassPtr);
	ParentSceneNode = IrrObjectClass_GetIrrObject(ParentObject);
	if( smgr == NULL || ParentObject == NULL || ParentSceneNode == NULL )
		return VS_FALSE;
	IrrAnimatedMeshSceneNodeClassLocalBuf = (struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrAnimatedMeshSceneNodeClassPtr, IrrAnimatedMeshSceneNodeClass_ClassLayer,IRRANIMATEDMESHSCENENODECLASS_LOCALVARINDEX, NULL );
	ObjectTemp = pSRP -> GetObject(&IrrAnimatedMeshSceneNodeClassLocalBuf -> UsedMeshObjectID);
	if( ObjectTemp == NULL )
		return VS_FALSE;
	mesh = (irr::scene::IAnimatedMesh*)IrrObjectClass_GetIrrObject( ObjectTemp );
	if( ParentSceneNode == smgr ){
		node = smgr -> addAnimatedMeshSceneNode(mesh,NULL,IrrAnimatedMeshSceneNodeClassPtr -> Id,
			                                    core::vector3df(IrrAnimatedMeshSceneNodeClassPtr -> Position.X,IrrAnimatedMeshSceneNodeClassPtr -> Position.Y,IrrAnimatedMeshSceneNodeClassPtr -> Position.Z),
												core::vector3df(IrrAnimatedMeshSceneNodeClassPtr -> Rotation.X,IrrAnimatedMeshSceneNodeClassPtr -> Rotation.Y,IrrAnimatedMeshSceneNodeClassPtr -> Rotation.Z),
												core::vector3df(IrrAnimatedMeshSceneNodeClassPtr -> Scale.X,IrrAnimatedMeshSceneNodeClassPtr -> Scale.Y,IrrAnimatedMeshSceneNodeClassPtr -> Scale.Z));
	}else{
		node = smgr -> addAnimatedMeshSceneNode(mesh,(scene::ISceneNode*)ParentSceneNode,IrrAnimatedMeshSceneNodeClassPtr -> Id,
			                                    core::vector3df(IrrAnimatedMeshSceneNodeClassPtr -> Position.X,IrrAnimatedMeshSceneNodeClassPtr -> Position.Y,IrrAnimatedMeshSceneNodeClassPtr -> Position.Z),
												core::vector3df(IrrAnimatedMeshSceneNodeClassPtr -> Rotation.X,IrrAnimatedMeshSceneNodeClassPtr -> Rotation.Y,IrrAnimatedMeshSceneNodeClassPtr -> Rotation.Z),
												core::vector3df(IrrAnimatedMeshSceneNodeClassPtr -> Scale.X,IrrAnimatedMeshSceneNodeClassPtr -> Scale.Y,IrrAnimatedMeshSceneNodeClassPtr -> Scale.Z));
	}
	if( node != NULL ){
		node->setMD2Animation ( (scene::EMD2_ANIMATION_TYPE)IrrAnimatedMeshSceneNodeClassPtr ->MD2AnimationType );
		node->setAnimationSpeed(IrrAnimatedMeshSceneNodeClassPtr ->FramesPerSecond);
		node -> grab();
		node -> SetSRPObject(IrrAnimatedMeshSceneNodeClassPtr);
		IrrObjectClass_SetIrrObject(IrrAnimatedMeshSceneNodeClassPtr,node);

		IrrSceneNodeClass_ChangeParent((struct StructOfIrrSceneNodeClass *)IrrAnimatedMeshSceneNodeClassPtr);

		//------
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrSceneNodeClass_OnIrrInit,IrrAnimatedMeshSceneNodeClassPtr,NULL,NULL);
	}else
		IrrObjectClass_SetIrrObject(IrrAnimatedMeshSceneNodeClassPtr,node);
	return VS_TRUE;
}

void IrrAnimatedMeshSceneNodeClass_DeleteMesh(struct StructOfIrrAnimatedMeshSceneNodeClass *IrrAnimatedMeshSceneNodeClassPtr)
{
	scene::IAnimatedMeshSceneNode* node;

	node = (scene::IAnimatedMeshSceneNode*)IrrObjectClass_GetIrrObject(IrrAnimatedMeshSceneNodeClassPtr);
	if( node == NULL )
		return;
	node -> remove();	
	IrrObjectClass_SetIrrObject(IrrAnimatedMeshSceneNodeClassPtr,NULL);
	node -> SetSRPObject(NULL);
	node -> drop();		
}

//---------------------------------------------------------------------------------------
void SRPAPI IrrAnimatedMeshSceneNodeClass_ChangeNotifyProc(void *Object,VS_ULONG Para,OBJECTATTRIBUTEINDEX AttributeIndex,VS_ATTRIBUTEINDEXMAP *AttributeIndexMap)
{
	struct StructOfIrrAnimatedMeshSceneNodeClass *IrrAnimatedMeshSceneNodeClassPtr;
	scene::IAnimatedMeshSceneNode* node;

	IrrAnimatedMeshSceneNodeClassPtr = (struct StructOfIrrAnimatedMeshSceneNodeClass *)Object;
	if( pSRP -> IsActive(IrrAnimatedMeshSceneNodeClassPtr) == VS_FALSE )
		return;
	node = (scene::IAnimatedMeshSceneNode*)IrrObjectClass_GetIrrObject(IrrAnimatedMeshSceneNodeClassPtr);
	if( node == NULL )
		return;
	switch( AttributeIndex ){
    case VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_MD2ANIMATIONTYPE :
		node -> setMD2Animation((scene::EMD2_ANIMATION_TYPE)IrrAnimatedMeshSceneNodeClassPtr ->MD2AnimationType);
        break;
	}
	return;
}

VS_INT32 IrrAnimatedMeshSceneNodeClass_MeshEvent(VS_ULONG FunctionChoice,void *EventPara)
{
	VS_EVENTPARAM *LocalEventParaPtr;
	struct StructOfIrrAnimatedMeshSceneNodeClass *IrrAnimatedMeshSceneNodeClassPtr;

	LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
	IrrAnimatedMeshSceneNodeClassPtr = (struct StructOfIrrAnimatedMeshSceneNodeClass *)LocalEventParaPtr -> DesObject;
	IrrAnimatedMeshSceneNodeClass_DeleteMesh(IrrAnimatedMeshSceneNodeClassPtr);
	IrrAnimatedMeshSceneNodeClass_CreateMesh(IrrAnimatedMeshSceneNodeClassPtr);
	return 0;
}

VS_INT32 SRPCALLBACK IrrAnimatedMeshSceneNodeClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrAnimatedMeshSceneNodeClass *IrrAnimatedMeshSceneNodeClassPtr;
    VS_EVENTPARAM_RUNPARAM *ResponseParam;//,*RequestParam;
    void *ChildObject;
	struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf *IrrAnimatedMeshSceneNodeClassLocalBuf;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrAnimatedMeshSceneNodeClassPtr = (struct StructOfIrrAnimatedMeshSceneNodeClass *)LocalEventParaPtr -> DesObject;
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
		IrrAnimatedMeshSceneNodeClass_ClassLayer = pSRP -> GetLayer(pSRP -> GetObject(&VSOBJID_IrrAnimatedMeshSceneNodeClass));
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
		IrrAnimatedMeshSceneNodeClassLocalBuf = (struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf *)pSRP -> MallocPrivateBuf( IrrAnimatedMeshSceneNodeClassPtr, IrrAnimatedMeshSceneNodeClass_ClassLayer,IRRANIMATEDMESHSCENENODECLASS_LOCALVARINDEX,sizeof(struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf) );
		memset( IrrAnimatedMeshSceneNodeClassLocalBuf, 0, sizeof(struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf) );
		ChildObject = pSRP -> MallocObject(IrrAnimatedMeshSceneNodeClassPtr,VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_MESHLIST,&VSOBJID_IrrAnimatedMeshClass,0,NULL);
		pSRP -> SetSaveFlag(ChildObject,VSSAVE_NONE);
		pSRP -> GetID(ChildObject,&IrrAnimatedMeshSceneNodeClassLocalBuf ->MeshObjectID);
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
		IrrAnimatedMeshSceneNodeClassLocalBuf = (struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrAnimatedMeshSceneNodeClassPtr, IrrAnimatedMeshSceneNodeClass_ClassLayer,IRRANIMATEDMESHSCENENODECLASS_LOCALVARINDEX, NULL );
		//------------
		ChildObject = pSRP -> GetObject( &IrrAnimatedMeshSceneNodeClassLocalBuf ->MeshObjectID );
		if( ChildObject != NULL )
			pSRP -> FreeObject(ChildObject);
		pSRP -> FreePrivate( IrrAnimatedMeshSceneNodeClassPtr, IrrAnimatedMeshSceneNodeClass_ClassLayer,IRRANIMATEDMESHSCENENODECLASS_LOCALVARINDEX );
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
		ChildObject = pSRP -> QueryFirst( IrrAnimatedMeshSceneNodeClassPtr -> TextureList );
		while( ChildObject != NULL ){
			if( IrrObjectClass_GetIrrObject(ChildObject) == NULL )
				break;
			ChildObject = pSRP -> QueryNext(ChildObject);
		}
		if( ChildObject != NULL ){
			ResponseParam = pSRP -> GetResponseBuf( );
			INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
			ResponseParam -> LParam = 1; 
			pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
			break;
		}
		IrrAnimatedMeshSceneNodeClassLocalBuf = (struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrAnimatedMeshSceneNodeClassPtr, IrrAnimatedMeshSceneNodeClass_ClassLayer,IRRANIMATEDMESHSCENENODECLASS_LOCALVARINDEX, NULL );
		ChildObject = IrrAnimatedMeshClass_GetMeshObject(IrrAnimatedMeshSceneNodeClassPtr -> MeshFile.Buf,&IrrAnimatedMeshSceneNodeClassLocalBuf -> MeshObjectID,&IrrAnimatedMeshSceneNodeClassLocalBuf -> MeshNum);
		if( ChildObject == NULL ){
			ResponseParam = pSRP -> GetResponseBuf( );
			INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
			ResponseParam -> LParam = 1; 
			pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
			break;
		}
		pSRP -> GetID(ChildObject,&IrrAnimatedMeshSceneNodeClassLocalBuf -> UsedMeshObjectID);
		if( IrrAnimatedMeshSceneNodeClass_CreateMesh( IrrAnimatedMeshSceneNodeClassPtr ) == VS_FALSE ){
			ResponseParam = pSRP -> GetResponseBuf( );
			INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
			ResponseParam -> LParam = 1; 
			pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
			break;
		}
		pSRP -> RegChangeCallBack( IrrAnimatedMeshSceneNodeClassPtr, IrrAnimatedMeshSceneNodeClass_ChangeNotifyProc, 0 , VS_FALSE );		
		pSRP -> RegEventFunction(ChildObject,&VSOUTEVENTID_IrrMeshClass_OnChange,IrrAnimatedMeshSceneNodeClassPtr,(void *)IrrAnimatedMeshSceneNodeClass_MeshEvent,0);
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
		pSRP -> UnRegChangeCallBack( IrrAnimatedMeshSceneNodeClassPtr, IrrAnimatedMeshSceneNodeClass_ChangeNotifyProc, 0 );
		IrrAnimatedMeshSceneNodeClass_DeleteMesh(IrrAnimatedMeshSceneNodeClassPtr);
		IrrAnimatedMeshSceneNodeClassLocalBuf = (struct StructOfIrrAnimatedMeshSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrAnimatedMeshSceneNodeClassPtr, IrrAnimatedMeshSceneNodeClass_ClassLayer,IRRANIMATEDMESHSCENENODECLASS_LOCALVARINDEX, NULL );
		ChildObject = pSRP -> GetObject( &IrrAnimatedMeshSceneNodeClassLocalBuf ->UsedMeshObjectID );
		if( ChildObject != NULL ){
			pSRP -> UnRegEventFunction(ChildObject,&VSOUTEVENTID_IrrMeshClass_OnChange,IrrAnimatedMeshSceneNodeClassPtr,(void *)IrrAnimatedMeshSceneNodeClass_MeshEvent,0);
			if( UUID_ISEQUAL(IrrAnimatedMeshSceneNodeClassLocalBuf ->UsedMeshObjectID,IrrAnimatedMeshSceneNodeClassLocalBuf ->MeshObjectID))
				pSRP -> Deactive(ChildObject);
		}
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

void SRPAPI IrrAnimatedMeshSceneNodeClass_SetFrameLoop(void *Object,VS_INT32 Begin,VS_INT32 End)
{
	scene::IAnimatedMeshSceneNode* node;

	node = (scene::IAnimatedMeshSceneNode*)IrrObjectClass_GetIrrObject(Object);
	if( node == NULL )
		return;
	node -> setFrameLoop(Begin,End);
    return;
}

VS_INT32 SRPAPI IrrAnimatedMeshSceneNodeClass_Lua_SetFrameLoop(void)
{
	void *Object;
	VS_INT32 Begin,End;
	
	Object = pSRP -> LuaToObject(1);
	Begin = pSRP -> LuaToInt(2);
	End = pSRP -> LuaToInt(3);
    IrrAnimatedMeshSceneNodeClass_SetFrameLoop(Object,Begin,End);
    return 0;
}

void SRPAPI IrrAnimatedMeshSceneNodeClass_SetAnimationSpeed(void *Object,VS_FLOAT FramesPerSecond)
{
	scene::IAnimatedMeshSceneNode* node;

	node = (scene::IAnimatedMeshSceneNode*)IrrObjectClass_GetIrrObject(Object);
	if( node == NULL )
		return;
	node -> setAnimationSpeed(FramesPerSecond);
    return;
}

VS_INT32 SRPAPI IrrAnimatedMeshSceneNodeClass_Lua_SetAnimationSpeed(void)
{
	void *Object;
	VS_FLOAT FramesPerSecond;
	
	Object = pSRP -> LuaToObject(1);
	FramesPerSecond = pSRP -> LuaToNumber(2);
    IrrAnimatedMeshSceneNodeClass_SetAnimationSpeed(Object,FramesPerSecond);
    return 0;
}

