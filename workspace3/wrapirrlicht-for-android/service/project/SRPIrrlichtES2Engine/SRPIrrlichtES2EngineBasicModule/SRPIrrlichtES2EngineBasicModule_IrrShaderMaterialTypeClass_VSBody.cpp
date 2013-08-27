/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-11  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.H"
#include "irrlicht.h"
#include "SRPIrrlichtES2Engine_Irr.H"

using namespace irr;

static VS_ULONG IrrShaderMaterialTypeClass_ClassLayer;
#define IRRSHADERMATERIALTYPECLASS_LOCALVARINDEX   1

struct StructOfIrrShaderMaterialTypeClassLocalBuf{
	VS_INT32 Type;
};

VS_BOOL IrrShaderMaterialTypeClass_Create(struct StructOfIrrShaderMaterialTypeClass *IrrShaderMaterialTypeClassPtr)
{
	video::IGPUProgrammingServices* gpu;
	void *ParentObject;

	VS_CHAR *VertexProgramBuf;
	VS_BOOL VertexProgramFileFlag;
	VS_ULONG VertexProgramBufSize;

	VS_CHAR *PixelProgramBuf;
	VS_BOOL PixelProgramFileFlag;
	VS_ULONG PixelProgramBufSize;

	io::IReadFile* vertexShaderProgram;
	io::IReadFile* pixelShaderProgram;

	void *DeviceObject,*FileSystemObject;
    io :: IFileSystem* fs;

	VS_INT32 MaterialType;

	void *CallBackObject;
	video::IShaderConstantSetCallBack* callback;

	ParentObject = pSRP -> GetParent(IrrShaderMaterialTypeClassPtr);
	gpu = (video::IGPUProgrammingServices*)IrrObjectClass_GetIrrObject(ParentObject);
//	if( gpu == NULL || ParentObject == NULL || pSRP -> IsInst(&VSOBJID_IrrGPUProgrammingServicesClass,ParentObject) == VS_FALSE )
//		return VS_FALSE;
	if( gpu == NULL || ParentObject == NULL )
			return VS_FALSE;
	
	SRPCALL_RET1(pSRP,IrrDeviceClass_GetCurDevice,DeviceObject,NULL,NULL);
	if( DeviceObject == NULL )
		return VS_FALSE;
	FileSystemObject = IrrDeviceClass_GetFileSystem(DeviceObject);
	fs = (io :: IFileSystem*)IrrObjectClass_GetIrrObject(FileSystemObject);
	if( fs == NULL )
		return VS_FALSE;

	VertexProgramBuf = IrrObjectClass_Load(IrrShaderMaterialTypeClassPtr,IrrShaderMaterialTypeClassPtr ->VertexFileName.Buf,&VertexProgramFileFlag,&VertexProgramBufSize);
	if( VertexProgramBuf == NULL )
		return VS_FALSE;
	if( VertexProgramFileFlag == VS_TRUE )
		vertexShaderProgram = fs -> createAndOpenFile(IrrShaderMaterialTypeClassPtr ->VertexFileName.Buf);
	else
		vertexShaderProgram = fs -> createMemoryReadFile(VertexProgramBuf,VertexProgramBufSize,IrrShaderMaterialTypeClassPtr ->VertexFileName.Buf);

	if( IrrShaderMaterialTypeClassPtr ->PixelFileName.Buf != NULL ){
		PixelProgramBuf = IrrObjectClass_Load(IrrShaderMaterialTypeClassPtr,IrrShaderMaterialTypeClassPtr ->PixelFileName.Buf,&PixelProgramFileFlag,&PixelProgramBufSize);
		if( PixelProgramBuf == NULL ){
			vertexShaderProgram -> drop();
			return VS_FALSE;
		}
		if( PixelProgramFileFlag == VS_TRUE )
			pixelShaderProgram = fs -> createAndOpenFile(IrrShaderMaterialTypeClassPtr ->PixelFileName.Buf);
		else
			pixelShaderProgram = fs -> createMemoryReadFile(PixelProgramBuf,PixelProgramBufSize,IrrShaderMaterialTypeClassPtr ->PixelFileName.Buf);
	}else
		pixelShaderProgram = NULL;

	//--
	callback = NULL;
	if( IrrShaderMaterialTypeClassPtr ->CallBackName.Buf != NULL ){
		CallBackObject = IrrMaterialClass_GetObject(IrrShaderMaterialTypeClassPtr ->CallBackName.Buf,NULL);
		if( CallBackObject != NULL ){
			pSRP -> Active(CallBackObject);
			callback = (video::IShaderConstantSetCallBack* )IrrObjectClass_GetIrrObject(CallBackObject);
		}
	}
	MaterialType = gpu -> addShaderMaterialFromFiles(vertexShaderProgram,
		                                             pixelShaderProgram,
													 callback,
													 (video::E_MATERIAL_TYPE)IrrShaderMaterialTypeClassPtr -> BaseMaterial);
	IrrShaderMaterialTypeClass_SetMaterialType( IrrShaderMaterialTypeClassPtr, MaterialType );
	if( vertexShaderProgram != NULL )
		vertexShaderProgram -> drop();
	if( pixelShaderProgram != NULL )
		pixelShaderProgram -> drop();
	return VS_TRUE;
}

VS_INT32 SRPCALLBACK IrrShaderMaterialTypeClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara)
{
    VS_EVENTPARAM *LocalEventParaPtr;
    struct StructOfIrrShaderMaterialTypeClass *IrrShaderMaterialTypeClassPtr;
    VS_EVENTPARAM_RUNPARAM *ResponseParam;//,*RequestParam;
    //void *ChildObject;
	struct StructOfIrrShaderMaterialTypeClassLocalBuf *IrrShaderMaterialTypeClassLocalBuf;
	VS_ULONG DwordTemp;
    
    //---------------------------------------------------------------------------
    LocalEventParaPtr = (VS_EVENTPARAM *)EventPara;
    IrrShaderMaterialTypeClassPtr = (struct StructOfIrrShaderMaterialTypeClass *)LocalEventParaPtr -> DesObject;
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
		IrrShaderMaterialTypeClass_ClassLayer = pSRP -> GetLayer(pSRP -> GetObject(&VSOBJID_IrrShaderMaterialTypeClass));
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
		IrrShaderMaterialTypeClassLocalBuf = (struct StructOfIrrShaderMaterialTypeClassLocalBuf *)pSRP -> MallocPrivateBuf( IrrShaderMaterialTypeClassPtr, IrrShaderMaterialTypeClass_ClassLayer,IRRSHADERMATERIALTYPECLASS_LOCALVARINDEX,sizeof(struct StructOfIrrShaderMaterialTypeClassLocalBuf) );
		IrrShaderMaterialTypeClassLocalBuf ->Type = -1;
        break;
    //---------------------------------------------------------------------------
    //---destory instance
    //---------------------------------------------------------------------------
    case VSEVENT_SYSTEMEVENT_ONDESTORY:
		IrrShaderMaterialTypeClassLocalBuf = (struct StructOfIrrShaderMaterialTypeClassLocalBuf *)pSRP -> GetPrivateBuf( IrrShaderMaterialTypeClassPtr, IrrShaderMaterialTypeClass_ClassLayer,IRRSHADERMATERIALTYPECLASS_LOCALVARINDEX, NULL );
		pSRP -> FreePrivate( IrrShaderMaterialTypeClassPtr, IrrShaderMaterialTypeClass_ClassLayer,IRRSHADERMATERIALTYPECLASS_LOCALVARINDEX );
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
		if( pSRP -> IsDirectInst(&VSOBJID_IrrShaderMaterialTypeClass,IrrShaderMaterialTypeClassPtr) == VS_FALSE )
			break;
		if( IrrShaderMaterialTypeClass_Create(IrrShaderMaterialTypeClassPtr) == VS_FALSE ){
			ResponseParam = pSRP -> GetResponseBuf( );
			INITVS_EVENTPARAM_RUNPARAM(ResponseParam);
			ResponseParam -> LParam = 1; 
			pSRP -> AttachResponseBuf(LocalEventParaPtr,ResponseParam);
			break;
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

void SRPAPI IrrShaderMaterialTypeClass_SetMaterialType(void *Object,VS_INT32 Type)
{
	struct StructOfIrrShaderMaterialTypeClassLocalBuf *IrrShaderMaterialTypeClassLocalBuf;

	IrrShaderMaterialTypeClassLocalBuf = (struct StructOfIrrShaderMaterialTypeClassLocalBuf *)pSRP -> GetPrivateBuf( Object, IrrShaderMaterialTypeClass_ClassLayer,IRRSHADERMATERIALTYPECLASS_LOCALVARINDEX, NULL );
	IrrShaderMaterialTypeClassLocalBuf -> Type = Type;
	if( Type != -1 )
		pSRP -> ProcessEvent_Dbg(&VSOUTEVENTID_IrrShaderMaterialTypeClass_OnChange,Object,NULL,NULL);
    return;
}

VS_INT32 SRPAPI IrrShaderMaterialTypeClass_GetMaterialType(void *Object)
{
	struct StructOfIrrShaderMaterialTypeClassLocalBuf *IrrShaderMaterialTypeClassLocalBuf;

	IrrShaderMaterialTypeClassLocalBuf = (struct StructOfIrrShaderMaterialTypeClassLocalBuf *)pSRP -> GetPrivateBuf( Object, IrrShaderMaterialTypeClass_ClassLayer,IRRSHADERMATERIALTYPECLASS_LOCALVARINDEX, NULL );
	return IrrShaderMaterialTypeClassLocalBuf -> Type;
}

