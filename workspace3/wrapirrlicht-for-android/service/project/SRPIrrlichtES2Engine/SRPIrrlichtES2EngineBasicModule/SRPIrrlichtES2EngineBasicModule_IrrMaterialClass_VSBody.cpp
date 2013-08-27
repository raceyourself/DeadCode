/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"

using namespace irr;

static VS_ULONG IrrMaterialClass_ClassLayer;
#define IRRMATERIALCLASS_LOCALVARINDEX   1

struct StructOfIrrMaterialClassTexture{
	VS_UINT32 TextureLayer;
	VS_UUID TextureObjectID;
	struct StructOfIrrMaterialClassTexture *Up,*Down;
};

struct StructOfIrrMaterialClassLocalBuf{
	struct StructOfIrrMaterialClassTexture *TextureRoot;
	VS_UUID ShaderMaterialTypeObjectID;
};

//---------------------------------------------------------------------------------------
void SRPAPI IrrMaterialClass_ChangeNotifyProc(void *Object,VS_ULONG Para,OBJECTATTRIBUTEINDEX AttributeIndex,VS_ATTRIBUTEINDEXMAP *AttributeIndexMap)
{
	struct StructOfIrrMaterialClass *IrrMaterialClassPtr;
	video::SMaterial* material;

	IrrMaterialClassPtr = (struct StructOfIrrMaterialClass *)Object;
	material = (video::SMaterial*)IrrObjectClass_GetIrrObject(IrrMaterialClassPtr);
	if( material == NULL )
		return;
	switch( AttributeIndex ){
    case VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPE :
		material -> MaterialType = (video::E_MATERIAL_TYPE)IrrMaterialClassPtr -> MaterialType;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_AMBIENTCOLOR :
		material -> AmbientColor = video::SColor(SRP_ARGB_ABGR(IrrMaterialClassPtr -> AmbientColor));
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_DIFFUSECOLOR :
		material -> DiffuseColor = video::SColor(SRP_ARGB_ABGR(IrrMaterialClassPtr -> DiffuseColor));
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_EMISSIVECOLOR :
		material -> EmissiveColor = video::SColor(SRP_ARGB_ABGR(IrrMaterialClassPtr -> EmissiveColor));
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_SPECULARCOLOR :
		material -> SpecularColor = video::SColor(SRP_ARGB_ABGR(IrrMaterialClassPtr -> SpecularColor));
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;

    case VSATTRINDEX_IRRMATERIALCLASS_SHININESS :
		material -> Shininess = IrrMaterialClassPtr -> Shininess;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPEPARAM :
		material -> MaterialTypeParam = IrrMaterialClassPtr -> MaterialTypeParam;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPEPARAM2 :
		material -> MaterialTypeParam2 = IrrMaterialClassPtr -> MaterialTypeParam2;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_THICKNESS :
		material -> Thickness = IrrMaterialClassPtr -> Thickness;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_WIREFRAME :
		material -> Wireframe = IrrMaterialClassPtr -> Wireframe;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_POINTCLOUD :
		material -> PointCloud = IrrMaterialClassPtr -> PointCloud;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_GOURAUDSHADING :
		material -> GouraudShading = IrrMaterialClassPtr -> GouraudShading;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;

    case VSATTRINDEX_IRRMATERIALCLASS_LIGHTING :
		material -> Lighting = IrrMaterialClassPtr -> Lighting;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_ZWRITEENABLE :
		material -> ZWriteEnable = IrrMaterialClassPtr -> ZWriteEnable;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_BACKFACECULLING :
		material -> BackfaceCulling = IrrMaterialClassPtr -> BackfaceCulling;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_FOGENABLE :
		material -> FogEnable = IrrMaterialClassPtr -> FogEnable;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_NORMALIZENORMALS :
		material -> NormalizeNormals = IrrMaterialClassPtr -> NormalizeNormals;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
    case VSATTRINDEX_IRRMATERIALCLASS_ZBUFFER :
		material -> ZBuffer = IrrMaterialClassPtr -> ZBuffer;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
        break;
	}
	return;
}

VS_INT32 IrrMaterialClass_TextureEvent(VS_ULONG FunctionChoice,void *EventPara);

VS_INT32 SRPCALLBACK IrrMaterialClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrMaterialClass *IrrMaterialClassPtr;
    VS_EVENTPARAM_RUNPARAM *ResponseParam; //,*RequestParam;
    void *ChildObject;
    VS_ULONG DwordTemp;
	struct StructOfIrrMaterialClassLocalBuf *IrrMaterialClassLocalBuf;
	struct StructOfIrrMaterialClassTexture *IrrMaterialClassTexture;
	video::SMaterial *material;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrMaterialClassPtr = (struct StructOfIrrMaterialClass *)LocalEventParaPtr -> DesObject;
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
		IrrMaterialClass_ClassLayer = pSRP -> GetLayer(pSRP -> GetObject(&VSOBJID_IrrMaterialClass));
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
		IrrMaterialClassLocalBuf = (struct StructOfIrrMaterialClassLocalBuf *)pSRP -> MallocPrivateBuf( IrrMaterialClassPtr, IrrMaterialClass_ClassLayer,IRRMATERIALCLASS_LOCALVARINDEX,sizeof(struct StructOfIrrMaterialClassLocalBuf) );
		memset( IrrMaterialClassLocalBuf, 0, sizeof(struct StructOfIrrMaterialClassLocalBuf) );
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
		IrrMaterialClassLocalBuf = (struct StructOfIrrMaterialClassLocalBuf *)pSRP -> GetPrivateBuf( IrrMaterialClassPtr, IrrMaterialClass_ClassLayer,IRRMATERIALCLASS_LOCALVARINDEX, NULL );
		while( IrrMaterialClassLocalBuf -> TextureRoot != NULL ){
			IrrMaterialClassTexture = IrrMaterialClassLocalBuf -> TextureRoot;
			IrrMaterialClassLocalBuf -> TextureRoot  = IrrMaterialClassLocalBuf -> TextureRoot -> Down;
			pSRP -> Free(IrrMaterialClassTexture);
		}
		pSRP -> FreePrivate( IrrMaterialClassPtr, IrrMaterialClass_ClassLayer,IRRMATERIALCLASS_LOCALVARINDEX );
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
		if( IrrMaterialClassPtr -> WrapIrrFlag == VS_FALSE ){
			material = new video::SMaterial();
			material -> MaterialType = (video::E_MATERIAL_TYPE)IrrMaterialClassPtr -> MaterialType;
			material -> AmbientColor = video::SColor(SRP_ARGB_ABGR(IrrMaterialClassPtr -> AmbientColor));
			material -> DiffuseColor = video::SColor(SRP_ARGB_ABGR(IrrMaterialClassPtr -> DiffuseColor));
			material -> EmissiveColor = video::SColor(SRP_ARGB_ABGR(IrrMaterialClassPtr -> EmissiveColor));
			material -> SpecularColor = video::SColor(SRP_ARGB_ABGR(IrrMaterialClassPtr -> SpecularColor));
			material -> Shininess = IrrMaterialClassPtr -> Shininess;
			material -> MaterialTypeParam = IrrMaterialClassPtr -> MaterialTypeParam;
			material -> MaterialTypeParam2 = IrrMaterialClassPtr -> MaterialTypeParam2;
			material -> Thickness = IrrMaterialClassPtr -> Thickness;
			material -> Wireframe = IrrMaterialClassPtr -> Wireframe;
			material -> PointCloud = IrrMaterialClassPtr -> PointCloud;
			material -> GouraudShading = IrrMaterialClassPtr -> GouraudShading;
			material -> Lighting = IrrMaterialClassPtr -> Lighting;
			material -> ZWriteEnable = IrrMaterialClassPtr -> ZWriteEnable;
			material -> BackfaceCulling = IrrMaterialClassPtr -> BackfaceCulling;
			material -> FogEnable = IrrMaterialClassPtr -> FogEnable;
			material -> NormalizeNormals = IrrMaterialClassPtr -> NormalizeNormals;
			material -> ZBuffer = IrrMaterialClassPtr -> ZBuffer;
			IrrObjectClass_SetIrrObject(IrrMaterialClassPtr,material);
			pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnIrrInit,IrrMaterialClassPtr,NULL,NULL);
		}else{
			material = (video::SMaterial*)IrrObjectClass_GetIrrObject(IrrMaterialClassPtr);
			if( material == NULL ){
				ResponseParam = pSRP -> GetResponseBuf( );
				INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
				ResponseParam -> LParam = 1; 
				pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
				break;
			}
			IrrMaterialClassPtr -> MaterialType = material -> MaterialType;
			IrrMaterialClassPtr -> AmbientColor = SRP_ARGB_ABGR( material -> AmbientColor.color );
			IrrMaterialClassPtr -> DiffuseColor = SRP_ARGB_ABGR( material -> DiffuseColor.color );
			IrrMaterialClassPtr -> EmissiveColor = SRP_ARGB_ABGR( material -> EmissiveColor.color );
			IrrMaterialClassPtr -> SpecularColor = SRP_ARGB_ABGR( material -> SpecularColor.color );

			IrrMaterialClassPtr -> Shininess = material -> Shininess;
			IrrMaterialClassPtr -> MaterialTypeParam = material -> MaterialTypeParam;
			IrrMaterialClassPtr -> MaterialTypeParam2 = material -> MaterialTypeParam2;
			IrrMaterialClassPtr -> Thickness = material -> Thickness;
			IrrMaterialClassPtr -> Wireframe = material -> Wireframe;
			IrrMaterialClassPtr -> PointCloud = material -> PointCloud;
			IrrMaterialClassPtr -> GouraudShading = material -> GouraudShading;
			IrrMaterialClassPtr -> Lighting = material -> Lighting;
			IrrMaterialClassPtr -> ZWriteEnable = material -> ZWriteEnable;
			IrrMaterialClassPtr -> BackfaceCulling = material -> BackfaceCulling;
			IrrMaterialClassPtr -> FogEnable = material -> FogEnable;
			IrrMaterialClassPtr -> NormalizeNormals = material -> NormalizeNormals;
			IrrMaterialClassPtr -> ZBuffer = material -> ZBuffer;
		}
		pSRP -> RegChangeCallBack( IrrMaterialClassPtr, IrrMaterialClass_ChangeNotifyProc, 0 , VS_FALSE );
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
		material = (video::SMaterial*)IrrObjectClass_GetIrrObject(IrrMaterialClassPtr);
		if( material == NULL )
			break;
		pSRP -> UnRegChangeCallBack( IrrMaterialClassPtr, IrrMaterialClass_ChangeNotifyProc, 0 );
		if( IrrMaterialClassPtr -> WrapIrrFlag == VS_TRUE )
			break;

		IrrObjectClass_SetIrrObject(IrrMaterialClassPtr,NULL);
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
		delete material;

		IrrMaterialClassLocalBuf = (struct StructOfIrrMaterialClassLocalBuf *)pSRP -> GetPrivateBuf( IrrMaterialClassPtr, IrrMaterialClass_ClassLayer,IRRMATERIALCLASS_LOCALVARINDEX, NULL );
		IrrMaterialClassTexture = IrrMaterialClassLocalBuf -> TextureRoot;
		while( IrrMaterialClassTexture != NULL ){
			ChildObject = pSRP -> GetObject( &IrrMaterialClassTexture ->TextureObjectID );
			if( ChildObject != NULL )
				pSRP -> UnRegEventFunction(ChildObject,&VSOUTEVENTID_IrrTextureClass_OnChange,IrrMaterialClassPtr,(void *)IrrMaterialClass_TextureEvent,IrrMaterialClassTexture -> TextureLayer);
			IrrMaterialClassTexture = IrrMaterialClassTexture -> Down;
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
        case 0X8dc14514 :  //----event OnIrrInit
            break;
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
        case 0X8dc14514 :  //----event OnIrrInit
            break;
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
        case 0X8dc14514 :  //----event OnIrrInit
            break;
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

VS_INT32 IrrMaterialClass_TextureEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    struct StructOfIrrMaterialClass *IrrMaterialClassPtr;
	struct StructOfIrrMaterialClassLocalBuf *IrrMaterialClassLocalBuf;
	struct StructOfIrrMaterialClassTexture *IrrMaterialClassTexture;
	VS_EVENTPARAM *LocalEventParaPtr;
	VS_UUID SrcObjectID;
	video::SMaterial* material;
	video::ITexture *Texture;

    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
	pSRP -> GetID(LocalEventParaPtr -> SrcObject,&SrcObjectID);
	IrrMaterialClassPtr = (struct StructOfIrrMaterialClass *)LocalEventParaPtr -> DesObject;
	material = (video::SMaterial*)IrrObjectClass_GetIrrObject(IrrMaterialClassPtr);
	if( material == NULL )
		return 0;
	IrrMaterialClassLocalBuf = (struct StructOfIrrMaterialClassLocalBuf *)pSRP -> GetPrivateBuf( IrrMaterialClassPtr, IrrMaterialClass_ClassLayer,IRRMATERIALCLASS_LOCALVARINDEX, NULL );
	IrrMaterialClassTexture = IrrMaterialClassLocalBuf ->TextureRoot;
	while( IrrMaterialClassTexture != NULL ){
		if( IrrMaterialClassTexture -> TextureLayer == FunctionChoice )
			break;
		IrrMaterialClassTexture = IrrMaterialClassTexture -> Down;
	}
	if( IrrMaterialClassTexture != 0 ){
		Texture = (video::ITexture *)IrrObjectClass_GetIrrObject(LocalEventParaPtr -> SrcObject) ;
		if( Texture != NULL ){
			material -> setTexture(FunctionChoice,Texture);
			pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
		}
	}
	return 0;
}

void SRPAPI IrrMaterialClass_SetTexture(void *Object,VS_UINT32 TextureLayer,void *IrrTexture)
{
    struct StructOfIrrMaterialClass *IrrMaterialClassPtr;
	struct StructOfIrrMaterialClassLocalBuf *IrrMaterialClassLocalBuf;
	struct StructOfIrrMaterialClassTexture *IrrMaterialClassTexture;
	video::SMaterial* material;
	video::ITexture *Texture;
	VS_UUID ObjectID;
	void *OldObject;

	IrrMaterialClassPtr = (struct StructOfIrrMaterialClass *)Object;
	IrrMaterialClassLocalBuf = (struct StructOfIrrMaterialClassLocalBuf *)pSRP -> GetPrivateBuf( IrrMaterialClassPtr, IrrMaterialClass_ClassLayer,IRRMATERIALCLASS_LOCALVARINDEX, NULL );
	material = (video::SMaterial*)IrrObjectClass_GetIrrObject(Object);
	if( material == NULL )
		return;
	pSRP -> GetID( IrrTexture, &ObjectID );
	IrrMaterialClassTexture = IrrMaterialClassLocalBuf ->TextureRoot;
	while( IrrMaterialClassTexture != NULL ){
		if( IrrMaterialClassTexture -> TextureLayer == TextureLayer )
			break;
		IrrMaterialClassTexture = IrrMaterialClassTexture -> Down;
	}
	if( IrrMaterialClassTexture == NULL ){
		IrrMaterialClassTexture = (struct StructOfIrrMaterialClassTexture *)pSRP -> Malloc(sizeof(struct StructOfIrrMaterialClassTexture));
		pSRP -> GetID( IrrTexture, &IrrMaterialClassTexture ->TextureObjectID);
		IrrMaterialClassTexture ->TextureLayer = TextureLayer;
		IrrMaterialClassTexture -> Up = NULL;
		IrrMaterialClassTexture -> Down = NULL;
		if( IrrMaterialClassLocalBuf ->TextureRoot == NULL )
			IrrMaterialClassLocalBuf ->TextureRoot = IrrMaterialClassTexture;
		else{
			IrrMaterialClassLocalBuf ->TextureRoot -> Up = IrrMaterialClassTexture;
			IrrMaterialClassTexture -> Down = IrrMaterialClassLocalBuf ->TextureRoot;
			IrrMaterialClassLocalBuf ->TextureRoot = IrrMaterialClassTexture;
		}
	}else{
		if( UUID_ISEQUAL(ObjectID,IrrMaterialClassTexture ->TextureObjectID))
			return; 
		OldObject = pSRP -> GetObject( &IrrMaterialClassTexture ->TextureObjectID );
		if( OldObject != NULL )
			pSRP -> UnRegEventFunction(OldObject,&VSOUTEVENTID_IrrTextureClass_OnChange,Object,(void *)IrrMaterialClass_TextureEvent,TextureLayer);
		pSRP -> GetID( IrrTexture, &IrrMaterialClassTexture ->TextureObjectID);
	}
	//---
	Texture = (video::ITexture *)IrrObjectClass_GetIrrObject(IrrTexture) ;
	if( Texture != NULL ){
		material -> setTexture(TextureLayer,Texture);
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
	}
	pSRP -> RegEventFunction(IrrTexture,&VSOUTEVENTID_IrrTextureClass_OnChange,Object,(void *)IrrMaterialClass_TextureEvent,TextureLayer);
    return;
}

VS_INT32 SRPAPI IrrMaterialClass_Lua_SetTexture(void)
{
	void *Object;
	VS_INT32 TextureLayer;
	void *IrrTexture;

	Object = pSRP -> LuaToObject(1);
	TextureLayer = pSRP -> LuaToInt(2);
	IrrTexture = pSRP -> LuaToObject(3);
	IrrMaterialClass_SetTexture(Object,TextureLayer,IrrTexture);
    return 0;
}

void *IrrMaterialClass_GetObject(VS_CHAR *FileName,VS_UUID *DefaultObjectID)
{
	void *ObjectTemp;
	VS_UUID ObjectID;

	if( FileName == NULL || FileName[0] == 0 )
		return NULL;
	switch( FileName[0] ){ 
	case '$' : //对象名称
		ObjectTemp = pSRP -> GetObjectEx(NULL,&FileName[1] );
		if( ObjectTemp == NULL )
			return NULL;
		break;
	case '@' : //对象ID
		pSRP -> StringToUuid(&FileName[1],&ObjectID);
		ObjectTemp = pSRP -> GetObject(&ObjectID);
		if( ObjectTemp == NULL )
			return NULL;
		break;
	default:
		if( DefaultObjectID == NULL )
			return NULL;
		ObjectTemp = pSRP -> GetObject(DefaultObjectID);
		if( ObjectTemp == NULL )
			return NULL;
		break;
	}
	pSRP -> Active(ObjectTemp);
	return ObjectTemp;
}

//-------------------------------------------------------------------------------------
VS_INT32 IrrMaterialClass_MaterialTypeEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    struct StructOfIrrMaterialClass *IrrMaterialClassPtr;
	struct StructOfIrrMaterialClassLocalBuf *IrrMaterialClassLocalBuf;
	VS_EVENTPARAM *LocalEventParaPtr;
	video::SMaterial* material;

    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
	IrrMaterialClassPtr = (struct StructOfIrrMaterialClass *)LocalEventParaPtr -> DesObject;
	material = (video::SMaterial*)IrrObjectClass_GetIrrObject(IrrMaterialClassPtr);
	if( material == NULL )
		return 0;
	IrrMaterialClassLocalBuf = (struct StructOfIrrMaterialClassLocalBuf *)pSRP -> GetPrivateBuf( IrrMaterialClassPtr, IrrMaterialClass_ClassLayer,IRRMATERIALCLASS_LOCALVARINDEX, NULL );
	if( IrrShaderMaterialTypeClass_GetMaterialType(LocalEventParaPtr -> SrcObject) != -1 ){
		IrrMaterialClassPtr -> MaterialType = IrrShaderMaterialTypeClass_GetMaterialType(LocalEventParaPtr -> SrcObject);
		material->MaterialType = (video::E_MATERIAL_TYPE)IrrMaterialClassPtr -> MaterialType;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
	}
    return 0;
}

void SRPAPI IrrMaterialClass_SetShaderMaterialType(void *Object,void *ShaderMaterialTypeObject)
{
    struct StructOfIrrMaterialClass *IrrMaterialClassPtr;
	struct StructOfIrrMaterialClassLocalBuf *IrrMaterialClassLocalBuf;
	video::SMaterial* material;
	VS_UUID ObjectID;
	void *OldObject;

	IrrMaterialClassPtr = (struct StructOfIrrMaterialClass *)Object;
	IrrMaterialClassLocalBuf = (struct StructOfIrrMaterialClassLocalBuf *)pSRP -> GetPrivateBuf( IrrMaterialClassPtr, IrrMaterialClass_ClassLayer,IRRMATERIALCLASS_LOCALVARINDEX, NULL );
	material = (video::SMaterial*)IrrObjectClass_GetIrrObject(Object);
	if( material == NULL || ShaderMaterialTypeObject == NULL )
		return;
	pSRP -> GetID(ShaderMaterialTypeObject,&ObjectID);
	if( UUID_ISEQUAL(ObjectID,IrrMaterialClassLocalBuf ->ShaderMaterialTypeObjectID))
		return;
	OldObject = pSRP -> GetObject( &IrrMaterialClassLocalBuf ->ShaderMaterialTypeObjectID );
	if( OldObject != NULL )
		pSRP -> UnRegEventFunction(OldObject,&VSOUTEVENTID_IrrShaderMaterialTypeClass_OnChange,Object,(void *)IrrMaterialClass_MaterialTypeEvent,0);
	pSRP -> GetID( ShaderMaterialTypeObject, &IrrMaterialClassLocalBuf ->ShaderMaterialTypeObjectID);
	//------------------
	if( IrrShaderMaterialTypeClass_GetMaterialType(ShaderMaterialTypeObject) != -1 ){
		IrrMaterialClassPtr -> MaterialType = IrrShaderMaterialTypeClass_GetMaterialType(ShaderMaterialTypeObject);
		material->MaterialType = (video::E_MATERIAL_TYPE)IrrMaterialClassPtr -> MaterialType;
		pSRP -> ProcessEvent(&VSOUTEVENTID_IrrMaterialClass_OnChange,IrrMaterialClassPtr,NULL,NULL);
	}
	pSRP -> RegEventFunction(ShaderMaterialTypeObject,&VSOUTEVENTID_IrrShaderMaterialTypeClass_OnChange,Object,(void *)IrrMaterialClass_MaterialTypeEvent,0);
    return;
}

VS_INT32 SRPAPI IrrMaterialClass_Lua_SetShaderMaterialType(void)
{
    return 0;
}

