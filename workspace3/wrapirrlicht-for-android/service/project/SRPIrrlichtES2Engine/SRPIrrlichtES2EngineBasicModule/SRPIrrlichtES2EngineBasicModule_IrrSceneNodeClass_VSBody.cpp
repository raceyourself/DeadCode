/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"

using namespace irr;

static VS_ULONG IrrSceneNodeClass_ClassLayer;
#define IRRSCENENODECLASS_LOCALVARINDEX   1

struct StructOfIrrSceneNodeClassMaterialTexture{
	VS_UINT32 TextureLayer;
	VS_UUID TextureObjectID;
	struct StructOfIrrSceneNodeClassMaterialTexture *Up,*Down;
};

struct StructOfIrrSceneNodeClassMaterial{
	VS_UINT32 Num;
	VS_UUID MaterialObjectID;
	struct StructOfIrrSceneNodeClassMaterial *Up,*Down;
};

struct StructOfIrrSceneNodeClassLocalBuf{
	struct StructOfIrrSceneNodeClassMaterialTexture *MaterialTextureRoot;
	struct StructOfIrrSceneNodeClassMaterial *MaterialRoot;
	VS_UUID ShaderMaterialTypeObjectID;
};

VS_INT32 IrrSceneNodeClass_MaterialTextureEvent(VS_ULONG FunctionChoice,void *EventPara);
VS_INT32 IrrSceneNodeClass_MaterialEvent(VS_ULONG FunctionChoice,void *EventPara);

VS_INT32 SRPCALLBACK IrrSceneNodeClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrSceneNodeClass *IrrSceneNodeClassPtr;
    VS_EVENTPARAM_RUNPARAM *ResponseParam; //,*RequestParam;
    void *ChildObject;
	struct StructOfIrrSceneNodeClassLocalBuf *IrrSceneNodeClassLocalBuf;
	struct StructOfIrrSceneNodeClassMaterialTexture *IrrSceneNodeClassMaterialTexture;
	struct StructOfIrrSceneNodeClassMaterial *IrrSceneNodeClassMaterial;
	scene::ISceneNode* node;
	VS_ULONG DwordTemp;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrSceneNodeClassPtr = (struct StructOfIrrSceneNodeClass *)LocalEventParaPtr -> DesObject;
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
		IrrSceneNodeClass_ClassLayer = pSRP -> GetLayer(pSRP -> GetObject(&VSOBJID_IrrSceneNodeClass));
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
		IrrSceneNodeClassLocalBuf = (struct StructOfIrrSceneNodeClassLocalBuf *)pSRP -> MallocPrivateBuf( IrrSceneNodeClassPtr, IrrSceneNodeClass_ClassLayer,IRRSCENENODECLASS_LOCALVARINDEX,sizeof(struct StructOfIrrSceneNodeClassLocalBuf) );
		memset( IrrSceneNodeClassLocalBuf, 0, sizeof(struct StructOfIrrSceneNodeClassLocalBuf) );
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
		IrrSceneNodeClassLocalBuf = (struct StructOfIrrSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrSceneNodeClassPtr, IrrSceneNodeClass_ClassLayer,IRRSCENENODECLASS_LOCALVARINDEX, NULL );
		while( IrrSceneNodeClassLocalBuf -> MaterialTextureRoot != NULL ){
			IrrSceneNodeClassMaterialTexture = IrrSceneNodeClassLocalBuf -> MaterialTextureRoot;
			IrrSceneNodeClassLocalBuf -> MaterialTextureRoot  = IrrSceneNodeClassLocalBuf -> MaterialTextureRoot -> Down;
			pSRP -> Free(IrrSceneNodeClassMaterialTexture);
		}
		while( IrrSceneNodeClassLocalBuf -> MaterialRoot != NULL ){
			IrrSceneNodeClassMaterial = IrrSceneNodeClassLocalBuf -> MaterialRoot;
			IrrSceneNodeClassLocalBuf -> MaterialRoot  = IrrSceneNodeClassLocalBuf -> MaterialRoot -> Down;
			pSRP -> Free(IrrSceneNodeClassMaterial);
		}
		pSRP -> FreePrivate( IrrSceneNodeClassPtr, IrrSceneNodeClass_ClassLayer,IRRSCENENODECLASS_LOCALVARINDEX );
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
		if( IrrSceneNodeClassPtr -> WrapIrrFlag == VS_TRUE ){
			node = (scene::ISceneNode *)IrrObjectClass_GetIrrObject(IrrSceneNodeClassPtr);
			if( node == NULL ){
				ResponseParam = pSRP -> GetResponseBuf( );
				INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
				ResponseParam -> LParam = 1; 
				pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
				break;
			}
			core :: vector3df Temp;
			Temp = node -> getPosition();
			IrrSceneNodeClassPtr -> Position.X = Temp.X;
			IrrSceneNodeClassPtr -> Position.Y = Temp.Y;
			IrrSceneNodeClassPtr -> Position.Z = Temp.Z;

			Temp = node -> getScale();
			IrrSceneNodeClassPtr -> Scale.X = Temp.X;
			IrrSceneNodeClassPtr -> Scale.Y = Temp.Y;
			IrrSceneNodeClassPtr -> Scale.Z = Temp.Z;

			Temp = node -> getRotation();
			IrrSceneNodeClassPtr -> Rotation.X = Temp.X;
			IrrSceneNodeClassPtr -> Rotation.Y = Temp.Y;
			IrrSceneNodeClassPtr -> Rotation.Z = Temp.Z;
			
			IrrSceneNodeClassPtr ->AutomaticCullingState = node -> getAutomaticCulling();
			IrrSceneNodeClassPtr ->Visible = node ->isVisible();
			IrrSceneNodeClassPtr ->Id = node -> getID();
		}
        break;
    //---------------------------------------------------------------------------
    //---instance status change to deactivate
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDEACTIVATE: 
        //TriggerForLoadFlag = LocalEventParaPtr -> RequestParam -> LParam;
		IrrSceneNodeClassLocalBuf = (struct StructOfIrrSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrSceneNodeClassPtr, IrrSceneNodeClass_ClassLayer,IRRSCENENODECLASS_LOCALVARINDEX, NULL );
		IrrSceneNodeClassMaterialTexture = IrrSceneNodeClassLocalBuf -> MaterialTextureRoot;
		while( IrrSceneNodeClassMaterialTexture != NULL ){
			ChildObject = pSRP -> GetObject( &IrrSceneNodeClassMaterialTexture ->TextureObjectID );
			if( ChildObject != NULL )
				pSRP -> UnRegEventFunction(ChildObject,&VSOUTEVENTID_IrrTextureClass_OnChange,IrrSceneNodeClassPtr,(void *)IrrSceneNodeClass_MaterialTextureEvent,IrrSceneNodeClassMaterialTexture -> TextureLayer);
			IrrSceneNodeClassMaterialTexture = IrrSceneNodeClassMaterialTexture -> Down;
		}
		IrrSceneNodeClassMaterial = IrrSceneNodeClassLocalBuf -> MaterialRoot;
		while( IrrSceneNodeClassMaterial != NULL ){
			ChildObject = pSRP -> GetObject( &IrrSceneNodeClassMaterial ->MaterialObjectID );
			if( ChildObject != NULL )
				pSRP -> UnRegEventFunction(ChildObject,&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrSceneNodeClassPtr,(void *)IrrSceneNodeClass_MaterialEvent,IrrSceneNodeClassMaterial -> Num);
			IrrSceneNodeClassMaterial = IrrSceneNodeClassMaterial -> Down;
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
		node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(IrrSceneNodeClassPtr);
		if( node == NULL )
			break;
        switch( LocalEventParaPtr -> RequestParam -> LParam ){
        case VSATTRINDEX_IRRSCENENODECLASS_POSITION :
			node -> setPosition( core::vector3df(IrrSceneNodeClassPtr -> Position.X,IrrSceneNodeClassPtr -> Position.Y,IrrSceneNodeClassPtr -> Position.Z));
            break;
        case VSATTRINDEX_IRRSCENENODECLASS_ROTATION :
			node -> setRotation( core::vector3df(IrrSceneNodeClassPtr -> Rotation.X,IrrSceneNodeClassPtr -> Rotation.Y,IrrSceneNodeClassPtr -> Rotation.Z));
            break;
        case VSATTRINDEX_IRRSCENENODECLASS_SCALE :
			node -> setScale( core::vector3df(IrrSceneNodeClassPtr -> Scale.X,IrrSceneNodeClassPtr -> Scale.Y,IrrSceneNodeClassPtr -> Scale.Z));
            break;
        case VSATTRINDEX_IRRSCENENODECLASS_VISIBLE :
			node -> setVisible(IrrSceneNodeClassPtr -> Visible);
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
        case 0X8dc14514 :  //----event OnIrrInit
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
        case 0X8dc14514 :  //----event OnIrrInit
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
        case 0X8dc14514 :  //----event OnIrrInit
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
        case 0X8dc14514 :  //----event OnIrrInit
            break;
        }
        //---pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
        break;
    //---------------------------------------------------------------------------
    }
    //---------------------------------------------------------------------------
    return VSEVENTMANAGER_DISPATCH;
}

void SRPAPI IrrSceneNodeClass_OVL_SetIrrParentSceneNode(void *Object,void *IrrParentObject)
{
	scene::ISceneNode* parentnode;
	scene::ISceneNode* node;

	if( pSRP -> IsInst(&VSOBJID_IrrSceneNodeClass,IrrParentObject) == VS_FALSE)
		return;
	parentnode = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(IrrParentObject);
	node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(Object);
	if( node == NULL || parentnode == NULL )
		return;
	parentnode -> addChild(node);
    return;
}

void SRPAPI IrrSceneNodeClass_SetMaterialTexture(void *Object,VS_UINT32 TextureLayer,void *IrrTexture)
{
    struct StructOfIrrSceneNodeClass *IrrSceneNodeClassPtr;
	struct StructOfIrrSceneNodeClassLocalBuf *IrrSceneNodeClassLocalBuf;
	struct StructOfIrrSceneNodeClassMaterialTexture *IrrSceneNodeClassMaterialTexture;
	scene::ISceneNode* node;
	video::ITexture *Texture;
	VS_UUID ObjectID;
	void *OldObject;

	IrrSceneNodeClassPtr = (struct StructOfIrrSceneNodeClass *)Object;
	IrrSceneNodeClassLocalBuf = (struct StructOfIrrSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrSceneNodeClassPtr, IrrSceneNodeClass_ClassLayer,IRRSCENENODECLASS_LOCALVARINDEX, NULL );
	node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(Object);
	if( node == NULL )
		return;
	pSRP -> GetID( IrrTexture, &ObjectID );
	IrrSceneNodeClassMaterialTexture = IrrSceneNodeClassLocalBuf ->MaterialTextureRoot;
	while( IrrSceneNodeClassMaterialTexture != NULL ){
		if( IrrSceneNodeClassMaterialTexture -> TextureLayer == TextureLayer )
			break;
		IrrSceneNodeClassMaterialTexture = IrrSceneNodeClassMaterialTexture -> Down;
	}
	if( IrrSceneNodeClassMaterialTexture == NULL ){
		IrrSceneNodeClassMaterialTexture = (struct StructOfIrrSceneNodeClassMaterialTexture *)pSRP -> Malloc(sizeof(struct StructOfIrrSceneNodeClassMaterialTexture));
		pSRP -> GetID( IrrTexture, &IrrSceneNodeClassMaterialTexture ->TextureObjectID);
		IrrSceneNodeClassMaterialTexture ->TextureLayer = TextureLayer;
		IrrSceneNodeClassMaterialTexture -> Up = NULL;
		IrrSceneNodeClassMaterialTexture -> Down = NULL;
		if( IrrSceneNodeClassLocalBuf ->MaterialTextureRoot == NULL )
			IrrSceneNodeClassLocalBuf ->MaterialTextureRoot = IrrSceneNodeClassMaterialTexture;
		else{
			IrrSceneNodeClassLocalBuf ->MaterialTextureRoot -> Up = IrrSceneNodeClassMaterialTexture;
			IrrSceneNodeClassMaterialTexture -> Down = IrrSceneNodeClassLocalBuf ->MaterialTextureRoot;
			IrrSceneNodeClassLocalBuf ->MaterialTextureRoot = IrrSceneNodeClassMaterialTexture;
		}
	}else{
		if( UUID_ISUNEQUAL(ObjectID,IrrSceneNodeClassMaterialTexture ->TextureObjectID)){
			OldObject = pSRP -> GetObject( &IrrSceneNodeClassMaterialTexture ->TextureObjectID );
			if( OldObject != NULL )
				pSRP -> UnRegEventFunction(OldObject,&VSOUTEVENTID_IrrTextureClass_OnChange,Object,(void *)IrrSceneNodeClass_MaterialTextureEvent,TextureLayer);
			pSRP -> GetID( IrrTexture, &IrrSceneNodeClassMaterialTexture ->TextureObjectID);
		}
	}
	//---
	Texture = (video::ITexture *)IrrObjectClass_GetIrrObject(IrrTexture) ;
	if( Texture != NULL )
		node -> setMaterialTexture(TextureLayer,Texture);
	pSRP -> RegEventFunction(IrrTexture,&VSOUTEVENTID_IrrTextureClass_OnChange,Object,(void *)IrrSceneNodeClass_MaterialTextureEvent,TextureLayer);
    return;
}

VS_INT32 SRPAPI IrrSceneNodeClass_Lua_SetMaterialTexture(void)
{
	void *Object;
	VS_INT32 TextureLayer;
	void *IrrTexture;

	Object = pSRP -> LuaToObject(1);
	TextureLayer = pSRP -> LuaToInt(2);
	IrrTexture = pSRP -> LuaToObject(3);
	IrrSceneNodeClass_SetMaterialTexture(Object,TextureLayer,IrrTexture);
    return 0;
}

extern void *IrrTextureClass_GetTexture(VS_CHAR *FileName,VS_UUID *DefaultObjectID);
void SRPAPI IrrSceneNodeClass_SetMaterialTextureEx(void *Object,VS_UINT32 TextureLayer,VS_CHAR * TextureFile)
{
	void *TextureObject;
	VS_UUID TextureObjectID;

	TextureObject = pSRP -> MallocObject(Object,VSATTRINDEX_IRRSCENENODECLASS_TEXTURELIST,&VSOBJID_IrrTextureClass,0,NULL);
	pSRP -> SetSaveFlag(TextureObject,VSSAVE_NONE);
	pSRP -> GetID(TextureObject,&TextureObjectID);
	TextureObject = IrrTextureClass_GetTexture(TextureFile,&TextureObjectID);
	IrrSceneNodeClass_SetMaterialTexture(Object,TextureLayer,TextureObject);
    return;
}

VS_INT32 SRPAPI IrrSceneNodeClass_Lua_SetMaterialTextureEx(void)
{
	void *Object;
	VS_INT32 TextureLayer;
	VS_CHAR *TextureFile;

	Object = pSRP -> LuaToObject(1);
	TextureLayer = pSRP -> LuaToInt(2);
	TextureFile = pSRP -> LuaToString(3);
	IrrSceneNodeClass_SetMaterialTextureEx(Object,TextureLayer,TextureFile);
    return 0;
}

void SRPAPI IrrSceneNodeClass_SetMaterialFlag(void *Object,VS_INT32 Flag,VS_BOOL NewValue)
{
	scene::ISceneNode* node;

	node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(Object);
	if( node == NULL )
		return;
	node -> setMaterialFlag((video::E_MATERIAL_FLAG)Flag,NewValue);
    return;
}

VS_INT32 SRPAPI IrrSceneNodeClass_Lua_SetMaterialFlag(void)
{
	void *Object;
	VS_INT32 Flag;
	VS_BOOL NewValue;

	Object = pSRP -> LuaToObject(1);
	Flag = pSRP -> LuaToInt(2);
	NewValue = pSRP -> LuaToBool(3);
    IrrSceneNodeClass_SetMaterialFlag( Object, Flag, NewValue );
    return 0;
}

void SRPAPI IrrSceneNodeClass_SetMaterialType(void *Object,VS_INT32 NewType)
{
	scene::ISceneNode* node;

	node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(Object);
	if( node == NULL )
		return;
	node -> setMaterialType((video::E_MATERIAL_TYPE)NewType);
    return;
}

VS_INT32 SRPAPI IrrSceneNodeClass_Lua_SetMaterialType(void)
{
	void *Object;
	VS_INT32 NewType;

	Object = pSRP -> LuaToObject(1);
	NewType = pSRP -> LuaToInt(2);
	IrrSceneNodeClass_SetMaterialType(Object,NewType);
    return 0;
}

void IrrSceneNodeClass_ChangeParent(struct StructOfIrrSceneNodeClass *IrrSceneNodeClassPtr)
{
	void *ObjectTemp;

	//----
	ObjectTemp = pSRP -> QueryFirst(IrrSceneNodeClassPtr ->SceneNodeList);
	while( ObjectTemp != NULL ){
		if( pSRP -> IsActive(ObjectTemp)== VS_TRUE ){
			SRPCALLEX2(pSRP,IrrObjectClass_SetIrrParentSceneNode,ObjectTemp,IrrSceneNodeClassPtr);
		}
		ObjectTemp = pSRP -> QueryNext(ObjectTemp);
	}
	ObjectTemp = pSRP -> QueryFirst(IrrSceneNodeClassPtr ->AnimatorList);
	while( ObjectTemp != NULL ){
		if( pSRP -> IsActive(ObjectTemp)== VS_TRUE ){
			SRPCALLEX2(pSRP,IrrObjectClass_SetIrrParentSceneNode,ObjectTemp,IrrSceneNodeClassPtr);
		}
		ObjectTemp = pSRP -> QueryNext(ObjectTemp);
	}
	ObjectTemp = pSRP -> QueryFirst(IrrSceneNodeClassPtr ->SelectorList);
	while( ObjectTemp != NULL ){
		if( pSRP -> IsActive(ObjectTemp)== VS_TRUE ){
			SRPCALLEX2(pSRP,IrrObjectClass_SetIrrParentSceneNode,ObjectTemp,IrrSceneNodeClassPtr);
		}
		ObjectTemp = pSRP -> QueryNext(ObjectTemp);
	}
	return;
}

//------------------------------------------------------------------------------------
VS_INT32 IrrSceneNodeClass_AnimatorBeforeChangeEvent(VS_ULONG FunctionChoice,void *EventPara)
{
	struct StructOfIrrSceneNodeClass *IrrSceneNodeClassPtr;
	VS_EVENTPARAM *LocalEventParaPtr;
	scene::ISceneNode* node;
	scene::ISceneNodeAnimator* anim;
	void *AnimatorObject;

	LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
	IrrSceneNodeClassPtr = (struct StructOfIrrSceneNodeClass *)LocalEventParaPtr -> DesObject;
	AnimatorObject = LocalEventParaPtr -> SrcObject;
	node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(IrrSceneNodeClassPtr);
	if( node == NULL )
		return 0;
	anim = (scene::ISceneNodeAnimator*)IrrObjectClass_GetIrrObject(AnimatorObject);
	if( anim == NULL )
		return 0;
	node -> removeAnimator(anim);		
	return 0;
}

VS_INT32 IrrSceneNodeClass_AnimatorChangeEvent(VS_ULONG FunctionChoice,void *EventPara)
{
	struct StructOfIrrSceneNodeClass *IrrSceneNodeClassPtr;
	VS_EVENTPARAM *LocalEventParaPtr;
	scene::ISceneNode* node;
	scene::ISceneNodeAnimator* anim;
	void *AnimatorObject;

	LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
	IrrSceneNodeClassPtr = (struct StructOfIrrSceneNodeClass *)LocalEventParaPtr -> DesObject;
	AnimatorObject = LocalEventParaPtr -> SrcObject;
	node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(IrrSceneNodeClassPtr);
	if( node == NULL )
		return 0;
	anim = (scene::ISceneNodeAnimator*)IrrObjectClass_GetIrrObject(AnimatorObject);
	if( anim == NULL )
		return 0;
	node -> addAnimator(anim);		
	return 0;
}

VS_INT32 IrrSceneNodeClass_MaterialEvent(VS_ULONG FunctionChoice,void *EventPara)
{
	struct StructOfIrrSceneNodeClass *IrrSceneNodeClassPtr;
	struct StructOfIrrSceneNodeClassLocalBuf *IrrSceneNodeClassLocalBuf;
	struct StructOfIrrSceneNodeClassMaterial *IrrSceneNodeClassMaterial;
	VS_EVENTPARAM *LocalEventParaPtr;
	VS_UUID SrcObjectID;
	scene::ISceneNode* node;
	video::SMaterial *Material,*SrcMaterial;

	LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
	pSRP -> GetID(LocalEventParaPtr -> SrcObject,&SrcObjectID);
	IrrSceneNodeClassPtr = (struct StructOfIrrSceneNodeClass *)LocalEventParaPtr -> DesObject;
	node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(IrrSceneNodeClassPtr);
	if( node == NULL )
		return 0;
	IrrSceneNodeClassLocalBuf = (struct StructOfIrrSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrSceneNodeClassPtr, IrrSceneNodeClass_ClassLayer,IRRSCENENODECLASS_LOCALVARINDEX, NULL );
	IrrSceneNodeClassMaterial = IrrSceneNodeClassLocalBuf ->MaterialRoot;
	while( IrrSceneNodeClassMaterial != NULL ){
		if( IrrSceneNodeClassMaterial -> Num == FunctionChoice )
			break;
		IrrSceneNodeClassMaterial = IrrSceneNodeClassMaterial -> Down;
	}
	if( IrrSceneNodeClassMaterial != 0 ){
		Material = (video::SMaterial *)IrrObjectClass_GetIrrObject(LocalEventParaPtr -> SrcObject) ;
		if( Material != NULL ){
			SrcMaterial = &node -> getMaterial(IrrSceneNodeClassMaterial -> Num);
			(*SrcMaterial) = (*Material);
		}
	}
	return 0;
}

VS_INT32 IrrSceneNodeClass_MaterialTextureEvent(VS_ULONG FunctionChoice,void *EventPara)
{
	struct StructOfIrrSceneNodeClass *IrrSceneNodeClassPtr;
	struct StructOfIrrSceneNodeClassLocalBuf *IrrSceneNodeClassLocalBuf;
	struct StructOfIrrSceneNodeClassMaterialTexture *IrrSceneNodeClassMaterialTexture;
	VS_EVENTPARAM *LocalEventParaPtr;
	VS_UUID SrcObjectID;
	scene::ISceneNode* node;
	video::ITexture *Texture;

	LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
	pSRP -> GetID(LocalEventParaPtr -> SrcObject,&SrcObjectID);
	IrrSceneNodeClassPtr = (struct StructOfIrrSceneNodeClass *)LocalEventParaPtr -> DesObject;
	node = (scene::ISceneNode*)IrrObjectClass_GetIrrObject(IrrSceneNodeClassPtr);
	if( node == NULL )
		return 0;
	IrrSceneNodeClassLocalBuf = (struct StructOfIrrSceneNodeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrSceneNodeClassPtr, IrrSceneNodeClass_ClassLayer,IRRSCENENODECLASS_LOCALVARINDEX, NULL );
	IrrSceneNodeClassMaterialTexture = IrrSceneNodeClassLocalBuf ->MaterialTextureRoot;
	while( IrrSceneNodeClassMaterialTexture != NULL ){
		if( IrrSceneNodeClassMaterialTexture -> TextureLayer == FunctionChoice )
			break;
		IrrSceneNodeClassMaterialTexture = IrrSceneNodeClassMaterialTexture -> Down;
	}
	if( IrrSceneNodeClassMaterialTexture != 0 ){
		Texture = (video::ITexture *)IrrObjectClass_GetIrrObject(LocalEventParaPtr -> SrcObject) ;
		if( Texture != NULL )
			node -> setMaterialTexture(FunctionChoice,Texture);
	}
	return 0;
}

void *SRPAPI IrrSceneNodeClass_GetIrrSceneManager(void *Object)
{
	void *Parent;

	if(Object == NULL )
		return NULL;
	Parent = pSRP -> GetParent(Object);
	if( Parent == NULL || pSRP -> IsObject(Parent) == VS_FALSE )
		return NULL;
	if( pSRP -> IsInst( &VSOBJID_IrrSceneManagerClass, Parent) == VS_TRUE)
		return IrrObjectClass_GetIrrObject(Parent);
	return IrrSceneNodeClass_GetIrrSceneManager( Parent );
}

void *SRPAPI IrrSceneNodeClass_GetSceneManager(void *Object)
{
	void *Parent;

	if( Object == NULL )
		return NULL;
	Parent = pSRP -> GetParent(Object);
	if( Parent == NULL || pSRP -> IsObject(Parent) == VS_FALSE )
		return NULL;
	if( pSRP -> IsInst( &VSOBJID_IrrSceneManagerClass, Parent) == VS_TRUE)
		return Parent;
	return IrrSceneNodeClass_GetSceneManager( Parent );
}

VS_INT32 SRPAPI IrrSceneNodeClass_Lua_GetSceneManager(void)
{
	void *Object;

	Object = pSRP -> LuaToObject(1);
	Object = IrrSceneNodeClass_GetSceneManager(Object);
	if( Object == NULL)
		pSRP -> LuaPushNil();
	else
		pSRP -> LuaPushObject(Object);
	return 1;
}