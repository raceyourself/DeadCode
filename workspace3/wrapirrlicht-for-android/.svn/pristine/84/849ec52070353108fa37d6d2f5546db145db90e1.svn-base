/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Class Body File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSClass.h"
ClassOfIrrDeviceClass::ClassOfIrrDeviceClass()
{
}

ClassOfIrrDeviceClass::ClassOfIrrDeviceClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrDeviceClass,0,NULL));
}

ClassOfIrrDeviceClass::ClassOfIrrDeviceClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrDeviceClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrDeviceClass" );
    return Buf;
}

class ClassOfIrrDeviceClass *ClassOfIrrDeviceClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrDeviceClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrDeviceClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrDeviceClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrDeviceClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_COLOR ClassOfIrrDeviceClass::Get_Color()
{
    return ((struct StructOfIrrDeviceClass *)ThisSRPObject) -> Color;
}
void ClassOfIrrDeviceClass::Put_Color(VS_COLOR In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRDEVICECLASS_COLOR,(VS_INT8 *)&In_Value);
}

VS_INT32 ClassOfIrrDeviceClass::Get_Width()
{
    return ((struct StructOfIrrDeviceClass *)ThisSRPObject) -> Width;
}
void ClassOfIrrDeviceClass::Put_Width(VS_INT32 In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRDEVICECLASS_WIDTH,(VS_INT8 *)&In_Value);
}

VS_INT32 ClassOfIrrDeviceClass::Get_Height()
{
    return ((struct StructOfIrrDeviceClass *)ThisSRPObject) -> Height;
}
void ClassOfIrrDeviceClass::Put_Height(VS_INT32 In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRDEVICECLASS_HEIGHT,(VS_INT8 *)&In_Value);
}

VS_ULONG ClassOfIrrDeviceClass::Get_RenderWnd()
{
    return ((struct StructOfIrrDeviceClass *)ThisSRPObject) -> RenderWnd;
}
void ClassOfIrrDeviceClass::Put_RenderWnd(VS_ULONG In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRDEVICECLASS_RENDERWND,(VS_INT8 *)&In_Value);
}


void *SRPAPI ClassOfIrrDeviceClass::GetCurDevice()
{
    IrrDeviceClass_GetCurDeviceProc LocalProc;

    LocalProc = (IrrDeviceClass_GetCurDeviceProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrDeviceClass_GetCurDevice);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void SRPAPI ClassOfIrrDeviceClass::Render()
{
    ThisSRPInterface -> Call(ThisSRPObject,"Render");
}
void SRPAPI ClassOfIrrDeviceClass::SetSize(VS_INT32 Width,VS_INT32 Height)
{
    ThisSRPInterface -> Call(ThisSRPObject,"SetSize",Width,Height);
}
void *SRPAPI ClassOfIrrDeviceClass::GetSceneManager()
{
    IrrDeviceClass_GetSceneManagerProc LocalProc;

    LocalProc = (IrrDeviceClass_GetSceneManagerProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrDeviceClass_GetSceneManager);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void *SRPAPI ClassOfIrrDeviceClass::GetVideoDriver()
{
    IrrDeviceClass_GetVideoDriverProc LocalProc;

    LocalProc = (IrrDeviceClass_GetVideoDriverProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrDeviceClass_GetVideoDriver);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void *SRPAPI ClassOfIrrDeviceClass::GetFileSystem()
{
    IrrDeviceClass_GetFileSystemProc LocalProc;

    LocalProc = (IrrDeviceClass_GetFileSystemProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrDeviceClass_GetFileSystem);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}

ClassOfIrrObjectClass::ClassOfIrrObjectClass()
{
}

ClassOfIrrObjectClass::ClassOfIrrObjectClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrObjectClass,0,NULL));
}

ClassOfIrrObjectClass::ClassOfIrrObjectClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrObjectClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrObjectClass" );
    return Buf;
}

class ClassOfIrrObjectClass *ClassOfIrrObjectClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrObjectClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrObjectClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrObjectClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrObjectClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_BOOL ClassOfIrrObjectClass::Get_WrapIrrFlag()
{
    return ((struct StructOfIrrObjectClass *)ThisSRPObject) -> WrapIrrFlag;
}
void ClassOfIrrObjectClass::Put_WrapIrrFlag(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRROBJECTCLASS_WRAPIRRFLAG,(VS_INT8 *)&In_Value);
}

void ClassOfIrrObjectClass::Put_F_SetIrrParentSceneNode(void * In_Value)
{
    ThisSRPInterface -> CreateOVLFunction(ThisSRPObject,&VSFUNCID_IrrObjectClass_SetIrrParentSceneNode,In_Value,NULL);
}
void * ClassOfIrrObjectClass::Get_F_SetIrrParentSceneNode()
{
    return NULL;
}


void SRPAPI ClassOfIrrObjectClass::SetIrrObject(void *IrrObject)
{
    IrrObjectClass_SetIrrObjectProc LocalProc;

    LocalProc = (IrrObjectClass_SetIrrObjectProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrObjectClass_SetIrrObject);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,IrrObject);
}
void *SRPAPI ClassOfIrrObjectClass::GetIrrObject()
{
    IrrObjectClass_GetIrrObjectProc LocalProc;

    LocalProc = (IrrObjectClass_GetIrrObjectProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrObjectClass_GetIrrObject);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void SRPAPI ClassOfIrrObjectClass::SetIrrParentSceneNode(void *IrrParentObject)
{
    IrrObjectClass_SetIrrParentSceneNodeProc LocalProc;

    LocalProc = (IrrObjectClass_SetIrrParentSceneNodeProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrObjectClass_SetIrrParentSceneNode);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,IrrParentObject);
}

ClassOfIrrMeshClass::ClassOfIrrMeshClass()
{
}

ClassOfIrrMeshClass::ClassOfIrrMeshClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrMeshClass,0,NULL));
}

ClassOfIrrMeshClass::ClassOfIrrMeshClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrMeshClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrMeshClass" );
    return Buf;
}

class ClassOfIrrMeshClass *ClassOfIrrMeshClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrMeshClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrMeshClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrMeshClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrMeshClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_CHAR * ClassOfIrrMeshClass::Get_MeshFile()
{
    return ((struct StructOfIrrMeshClass *)ThisSRPObject) -> MeshFile.Buf;
}
void ClassOfIrrMeshClass::Put_MeshFile(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMESHCLASS_MESHFILE,(VS_INT8 *)In_Value);
}

VS_BOOL ClassOfIrrMeshClass::Get_LoadResult()
{
    return ((struct StructOfIrrMeshClass *)ThisSRPObject) -> LoadResult;
}
void ClassOfIrrMeshClass::Put_LoadResult(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMESHCLASS_LOADRESULT,(VS_INT8 *)&In_Value);
}

VSSystemEvent_EventProc ClassOfIrrMeshClass::Get_E_OnChange()
{
    return NULL;
}
void ClassOfIrrMeshClass::Put_E_OnChange(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_IrrMeshClass_OnChange,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}


void SRPAPI ClassOfIrrMeshClass::TriggerChangeEvent()
{
    ThisSRPInterface -> Call(ThisSRPObject,"TriggerChangeEvent");
}
VS_INT32 SRPAPI ClassOfIrrMeshClass::GetMeshBufferCount()
{
    return (VS_INT32 )ThisSRPInterface -> Call(ThisSRPObject,"GetMeshBufferCount");
}
void *SRPAPI ClassOfIrrMeshClass::GetMeshBuffer(void *MeshBufferObject,VS_INT32 Index)
{
    IrrMeshClass_GetMeshBufferProc LocalProc;

    LocalProc = (IrrMeshClass_GetMeshBufferProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrMeshClass_GetMeshBuffer);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,MeshBufferObject,Index);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}

ClassOfIrrSceneManagerClass::ClassOfIrrSceneManagerClass()
{
}

ClassOfIrrSceneManagerClass::ClassOfIrrSceneManagerClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrSceneManagerClass,0,NULL));
}

ClassOfIrrSceneManagerClass::ClassOfIrrSceneManagerClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrSceneManagerClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrSceneManagerClass" );
    return Buf;
}

class ClassOfIrrSceneManagerClass *ClassOfIrrSceneManagerClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrSceneManagerClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrSceneManagerClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrSceneManagerClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrSceneManagerClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}


ClassOfIrrSceneNodeClass::ClassOfIrrSceneNodeClass()
{
}

ClassOfIrrSceneNodeClass::ClassOfIrrSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrSceneNodeClass,0,NULL));
}

ClassOfIrrSceneNodeClass::ClassOfIrrSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrSceneNodeClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrSceneNodeClass" );
    return Buf;
}

class ClassOfIrrSceneNodeClass *ClassOfIrrSceneNodeClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrSceneNodeClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrSceneNodeClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrSceneNodeClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrSceneNodeClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

struct StructOfSRP3DVector * ClassOfIrrSceneNodeClass::Get_Position()
{
    return &((struct StructOfIrrSceneNodeClass *)ThisSRPObject) -> Position;
}
void ClassOfIrrSceneNodeClass::Put_Position(struct StructOfSRP3DVector * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSCENENODECLASS_POSITION,(VS_INT8 *)In_Value);
}

struct StructOfSRP3DVector * ClassOfIrrSceneNodeClass::Get_Rotation()
{
    return &((struct StructOfIrrSceneNodeClass *)ThisSRPObject) -> Rotation;
}
void ClassOfIrrSceneNodeClass::Put_Rotation(struct StructOfSRP3DVector * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSCENENODECLASS_ROTATION,(VS_INT8 *)In_Value);
}

struct StructOfSRP3DVector * ClassOfIrrSceneNodeClass::Get_Scale()
{
    return &((struct StructOfIrrSceneNodeClass *)ThisSRPObject) -> Scale;
}
void ClassOfIrrSceneNodeClass::Put_Scale(struct StructOfSRP3DVector * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSCENENODECLASS_SCALE,(VS_INT8 *)In_Value);
}

VS_BOOL ClassOfIrrSceneNodeClass::Get_Visible()
{
    return ((struct StructOfIrrSceneNodeClass *)ThisSRPObject) -> Visible;
}
void ClassOfIrrSceneNodeClass::Put_Visible(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSCENENODECLASS_VISIBLE,(VS_INT8 *)&In_Value);
}

VS_INT32 ClassOfIrrSceneNodeClass::Get_AutomaticCullingState()
{
    return ((struct StructOfIrrSceneNodeClass *)ThisSRPObject) -> AutomaticCullingState;
}
void ClassOfIrrSceneNodeClass::Put_AutomaticCullingState(VS_INT32 In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSCENENODECLASS_AUTOMATICCULLINGSTATE,(VS_INT8 *)&In_Value);
}

VS_INT32 ClassOfIrrSceneNodeClass::Get_Id()
{
    return ((struct StructOfIrrSceneNodeClass *)ThisSRPObject) -> Id;
}
void ClassOfIrrSceneNodeClass::Put_Id(VS_INT32 In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSCENENODECLASS_ID,(VS_INT8 *)&In_Value);
}

VSSystemEvent_EventProc ClassOfIrrSceneNodeClass::Get_E_OnIrrInit()
{
    return NULL;
}
void ClassOfIrrSceneNodeClass::Put_E_OnIrrInit(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_IrrSceneNodeClass_OnIrrInit,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}

void ClassOfIrrSceneNodeClass::Put_FOVL_SetIrrParentSceneNode(void * In_Value)
{
    ThisSRPInterface -> CreateOVLFunction(ThisSRPObject,&VSFUNCID_IrrSceneNodeClass_OVL_SetIrrParentSceneNode,In_Value,NULL);
}
void * ClassOfIrrSceneNodeClass::Get_FOVL_SetIrrParentSceneNode()
{
    return NULL;
}


void *SRPAPI ClassOfIrrSceneNodeClass::GetSceneManager()
{
    IrrSceneNodeClass_GetSceneManagerProc LocalProc;

    LocalProc = (IrrSceneNodeClass_GetSceneManagerProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrSceneNodeClass_GetSceneManager);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void SRPAPI ClassOfIrrSceneNodeClass::SetMaterialTexture(VS_UINT32 TextureLayer,void *IrrTexture)
{
    IrrSceneNodeClass_SetMaterialTextureProc LocalProc;

    LocalProc = (IrrSceneNodeClass_SetMaterialTextureProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrSceneNodeClass_SetMaterialTexture);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,TextureLayer,IrrTexture);
}
void SRPAPI ClassOfIrrSceneNodeClass::SetMaterialTextureEx(VS_UINT32 TextureLayer,VS_CHAR * TextureFile)
{
    ThisSRPInterface -> Call(ThisSRPObject,"SetMaterialTextureEx",TextureLayer,TextureFile);
}
void SRPAPI ClassOfIrrSceneNodeClass::SetMaterialFlag(VS_INT32 Flag,VS_BOOL NewValue)
{
    ThisSRPInterface -> Call(ThisSRPObject,"SetMaterialFlag",Flag,NewValue);
}
void SRPAPI ClassOfIrrSceneNodeClass::SetMaterialType(VS_INT32 NewType)
{
    ThisSRPInterface -> Call(ThisSRPObject,"SetMaterialType",NewType);
}

ClassOfIrrAnimatedMeshSceneNodeClass::ClassOfIrrAnimatedMeshSceneNodeClass()
{
}

ClassOfIrrAnimatedMeshSceneNodeClass::ClassOfIrrAnimatedMeshSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrAnimatedMeshSceneNodeClass,0,NULL));
}

ClassOfIrrAnimatedMeshSceneNodeClass::ClassOfIrrAnimatedMeshSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrAnimatedMeshSceneNodeClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrAnimatedMeshSceneNodeClass" );
    return Buf;
}

class ClassOfIrrAnimatedMeshSceneNodeClass *ClassOfIrrAnimatedMeshSceneNodeClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrAnimatedMeshSceneNodeClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrAnimatedMeshSceneNodeClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrAnimatedMeshSceneNodeClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrAnimatedMeshSceneNodeClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_CHAR * ClassOfIrrAnimatedMeshSceneNodeClass::Get_MeshFile()
{
    return ((struct StructOfIrrAnimatedMeshSceneNodeClass *)ThisSRPObject) -> MeshFile.Buf;
}
void ClassOfIrrAnimatedMeshSceneNodeClass::Put_MeshFile(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_MESHFILE,(VS_INT8 *)In_Value);
}

VS_INT32 ClassOfIrrAnimatedMeshSceneNodeClass::Get_MD2AnimationType()
{
    return ((struct StructOfIrrAnimatedMeshSceneNodeClass *)ThisSRPObject) -> MD2AnimationType;
}
void ClassOfIrrAnimatedMeshSceneNodeClass::Put_MD2AnimationType(VS_INT32 In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_MD2ANIMATIONTYPE,(VS_INT8 *)&In_Value);
}

VS_FLOAT ClassOfIrrAnimatedMeshSceneNodeClass::Get_FramesPerSecond()
{
    return ((struct StructOfIrrAnimatedMeshSceneNodeClass *)ThisSRPObject) -> FramesPerSecond;
}
void ClassOfIrrAnimatedMeshSceneNodeClass::Put_FramesPerSecond(VS_FLOAT In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_FRAMESPERSECOND,(VS_INT8 *)&In_Value);
}


void SRPAPI ClassOfIrrAnimatedMeshSceneNodeClass::SetFrameLoop(VS_INT32 Begin,VS_INT32 End)
{
    ThisSRPInterface -> Call(ThisSRPObject,"SetFrameLoop",Begin,End);
}
void SRPAPI ClassOfIrrAnimatedMeshSceneNodeClass::SetAnimationSpeed(VS_FLOAT FramesPerSecond)
{
    ThisSRPInterface -> Call(ThisSRPObject,"SetAnimationSpeed",FramesPerSecond);
}

ClassOfIrrShaderMaterialTypeClass::ClassOfIrrShaderMaterialTypeClass()
{
}

ClassOfIrrShaderMaterialTypeClass::ClassOfIrrShaderMaterialTypeClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrShaderMaterialTypeClass,0,NULL));
}

ClassOfIrrShaderMaterialTypeClass::ClassOfIrrShaderMaterialTypeClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrShaderMaterialTypeClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrShaderMaterialTypeClass" );
    return Buf;
}

class ClassOfIrrShaderMaterialTypeClass *ClassOfIrrShaderMaterialTypeClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrShaderMaterialTypeClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrShaderMaterialTypeClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrShaderMaterialTypeClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrShaderMaterialTypeClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_CHAR * ClassOfIrrShaderMaterialTypeClass::Get_VertexFileName()
{
    return ((struct StructOfIrrShaderMaterialTypeClass *)ThisSRPObject) -> VertexFileName.Buf;
}
void ClassOfIrrShaderMaterialTypeClass::Put_VertexFileName(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_VERTEXFILENAME,(VS_INT8 *)In_Value);
}

VS_CHAR * ClassOfIrrShaderMaterialTypeClass::Get_PixelFileName()
{
    return ((struct StructOfIrrShaderMaterialTypeClass *)ThisSRPObject) -> PixelFileName.Buf;
}
void ClassOfIrrShaderMaterialTypeClass::Put_PixelFileName(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_PIXELFILENAME,(VS_INT8 *)In_Value);
}

VS_CHAR * ClassOfIrrShaderMaterialTypeClass::Get_CallBackName()
{
    return ((struct StructOfIrrShaderMaterialTypeClass *)ThisSRPObject) -> CallBackName.Buf;
}
void ClassOfIrrShaderMaterialTypeClass::Put_CallBackName(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_CALLBACKNAME,(VS_INT8 *)In_Value);
}

VS_INT32 ClassOfIrrShaderMaterialTypeClass::Get_BaseMaterial()
{
    return ((struct StructOfIrrShaderMaterialTypeClass *)ThisSRPObject) -> BaseMaterial;
}
void ClassOfIrrShaderMaterialTypeClass::Put_BaseMaterial(VS_INT32 In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_BASEMATERIAL,(VS_INT8 *)&In_Value);
}

VSSystemEvent_EventProc ClassOfIrrShaderMaterialTypeClass::Get_E_OnChange()
{
    return NULL;
}
void ClassOfIrrShaderMaterialTypeClass::Put_E_OnChange(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_IrrShaderMaterialTypeClass_OnChange,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}


void SRPAPI ClassOfIrrShaderMaterialTypeClass::SetMaterialType(VS_INT32 Type)
{
    ThisSRPInterface -> Call(ThisSRPObject,"SetMaterialType",Type);
}
VS_INT32 SRPAPI ClassOfIrrShaderMaterialTypeClass::GetMaterialType()
{
    return (VS_INT32 )ThisSRPInterface -> Call(ThisSRPObject,"GetMaterialType");
}

ClassOfIrrCameraSceneNodeClass::ClassOfIrrCameraSceneNodeClass()
{
}

ClassOfIrrCameraSceneNodeClass::ClassOfIrrCameraSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrCameraSceneNodeClass,0,NULL));
}

ClassOfIrrCameraSceneNodeClass::ClassOfIrrCameraSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrCameraSceneNodeClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrCameraSceneNodeClass" );
    return Buf;
}

class ClassOfIrrCameraSceneNodeClass *ClassOfIrrCameraSceneNodeClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrCameraSceneNodeClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrCameraSceneNodeClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrCameraSceneNodeClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrCameraSceneNodeClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

struct StructOfSRP3DVector * ClassOfIrrCameraSceneNodeClass::Get_Target()
{
    return &((struct StructOfIrrCameraSceneNodeClass *)ThisSRPObject) -> Target;
}
void ClassOfIrrCameraSceneNodeClass::Put_Target(struct StructOfSRP3DVector * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRCAMERASCENENODECLASS_TARGET,(VS_INT8 *)In_Value);
}

VS_FLOAT ClassOfIrrCameraSceneNodeClass::Get_ZNear()
{
    return ((struct StructOfIrrCameraSceneNodeClass *)ThisSRPObject) -> ZNear;
}
void ClassOfIrrCameraSceneNodeClass::Put_ZNear(VS_FLOAT In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRCAMERASCENENODECLASS_ZNEAR,(VS_INT8 *)&In_Value);
}

VS_FLOAT ClassOfIrrCameraSceneNodeClass::Get_ZFar()
{
    return ((struct StructOfIrrCameraSceneNodeClass *)ThisSRPObject) -> ZFar;
}
void ClassOfIrrCameraSceneNodeClass::Put_ZFar(VS_FLOAT In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRCAMERASCENENODECLASS_ZFAR,(VS_INT8 *)&In_Value);
}


void SRPAPI ClassOfIrrCameraSceneNodeClass::GetTarget(struct StructOfSRP3DVector * Position)
{
    IrrCameraSceneNodeClass_GetTargetProc LocalProc;

    LocalProc = (IrrCameraSceneNodeClass_GetTargetProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrCameraSceneNodeClass_GetTarget);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,Position);
}

ClassOfIrrMaterialClass::ClassOfIrrMaterialClass()
{
}

ClassOfIrrMaterialClass::ClassOfIrrMaterialClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrMaterialClass,0,NULL));
}

ClassOfIrrMaterialClass::ClassOfIrrMaterialClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrMaterialClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrMaterialClass" );
    return Buf;
}

class ClassOfIrrMaterialClass *ClassOfIrrMaterialClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrMaterialClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrMaterialClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrMaterialClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrMaterialClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_INT32 ClassOfIrrMaterialClass::Get_MaterialType()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> MaterialType;
}
void ClassOfIrrMaterialClass::Put_MaterialType(VS_INT32 In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPE,(VS_INT8 *)&In_Value);
}

VS_COLOR ClassOfIrrMaterialClass::Get_AmbientColor()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> AmbientColor;
}
void ClassOfIrrMaterialClass::Put_AmbientColor(VS_COLOR In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_AMBIENTCOLOR,(VS_INT8 *)&In_Value);
}

VS_COLOR ClassOfIrrMaterialClass::Get_DiffuseColor()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> DiffuseColor;
}
void ClassOfIrrMaterialClass::Put_DiffuseColor(VS_COLOR In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_DIFFUSECOLOR,(VS_INT8 *)&In_Value);
}

VS_COLOR ClassOfIrrMaterialClass::Get_EmissiveColor()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> EmissiveColor;
}
void ClassOfIrrMaterialClass::Put_EmissiveColor(VS_COLOR In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_EMISSIVECOLOR,(VS_INT8 *)&In_Value);
}

VS_COLOR ClassOfIrrMaterialClass::Get_SpecularColor()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> SpecularColor;
}
void ClassOfIrrMaterialClass::Put_SpecularColor(VS_COLOR In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_SPECULARCOLOR,(VS_INT8 *)&In_Value);
}

VS_FLOAT ClassOfIrrMaterialClass::Get_Shininess()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> Shininess;
}
void ClassOfIrrMaterialClass::Put_Shininess(VS_FLOAT In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_SHININESS,(VS_INT8 *)&In_Value);
}

VS_FLOAT ClassOfIrrMaterialClass::Get_MaterialTypeParam()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> MaterialTypeParam;
}
void ClassOfIrrMaterialClass::Put_MaterialTypeParam(VS_FLOAT In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPEPARAM,(VS_INT8 *)&In_Value);
}

VS_FLOAT ClassOfIrrMaterialClass::Get_MaterialTypeParam2()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> MaterialTypeParam2;
}
void ClassOfIrrMaterialClass::Put_MaterialTypeParam2(VS_FLOAT In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPEPARAM2,(VS_INT8 *)&In_Value);
}

VS_FLOAT ClassOfIrrMaterialClass::Get_Thickness()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> Thickness;
}
void ClassOfIrrMaterialClass::Put_Thickness(VS_FLOAT In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_THICKNESS,(VS_INT8 *)&In_Value);
}

VS_BOOL ClassOfIrrMaterialClass::Get_Wireframe()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> Wireframe;
}
void ClassOfIrrMaterialClass::Put_Wireframe(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_WIREFRAME,(VS_INT8 *)&In_Value);
}

VS_BOOL ClassOfIrrMaterialClass::Get_PointCloud()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> PointCloud;
}
void ClassOfIrrMaterialClass::Put_PointCloud(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_POINTCLOUD,(VS_INT8 *)&In_Value);
}

VS_BOOL ClassOfIrrMaterialClass::Get_GouraudShading()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> GouraudShading;
}
void ClassOfIrrMaterialClass::Put_GouraudShading(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_GOURAUDSHADING,(VS_INT8 *)&In_Value);
}

VS_BOOL ClassOfIrrMaterialClass::Get_Lighting()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> Lighting;
}
void ClassOfIrrMaterialClass::Put_Lighting(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_LIGHTING,(VS_INT8 *)&In_Value);
}

VS_BOOL ClassOfIrrMaterialClass::Get_ZWriteEnable()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> ZWriteEnable;
}
void ClassOfIrrMaterialClass::Put_ZWriteEnable(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_ZWRITEENABLE,(VS_INT8 *)&In_Value);
}

VS_BOOL ClassOfIrrMaterialClass::Get_BackfaceCulling()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> BackfaceCulling;
}
void ClassOfIrrMaterialClass::Put_BackfaceCulling(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_BACKFACECULLING,(VS_INT8 *)&In_Value);
}

VS_BOOL ClassOfIrrMaterialClass::Get_FogEnable()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> FogEnable;
}
void ClassOfIrrMaterialClass::Put_FogEnable(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_FOGENABLE,(VS_INT8 *)&In_Value);
}

VS_BOOL ClassOfIrrMaterialClass::Get_NormalizeNormals()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> NormalizeNormals;
}
void ClassOfIrrMaterialClass::Put_NormalizeNormals(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_NORMALIZENORMALS,(VS_INT8 *)&In_Value);
}

VS_UINT32 ClassOfIrrMaterialClass::Get_ZBuffer()
{
    return ((struct StructOfIrrMaterialClass *)ThisSRPObject) -> ZBuffer;
}
void ClassOfIrrMaterialClass::Put_ZBuffer(VS_UINT32 In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRMATERIALCLASS_ZBUFFER,(VS_INT8 *)&In_Value);
}

VSSystemEvent_EventProc ClassOfIrrMaterialClass::Get_E_OnIrrInit()
{
    return NULL;
}
void ClassOfIrrMaterialClass::Put_E_OnIrrInit(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_IrrMaterialClass_OnIrrInit,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}

VSSystemEvent_EventProc ClassOfIrrMaterialClass::Get_E_OnChange()
{
    return NULL;
}
void ClassOfIrrMaterialClass::Put_E_OnChange(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_IrrMaterialClass_OnChange,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}


void SRPAPI ClassOfIrrMaterialClass::SetTexture(VS_UINT32 TextureLayer,void *IrrTexture)
{
    IrrMaterialClass_SetTextureProc LocalProc;

    LocalProc = (IrrMaterialClass_SetTextureProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrMaterialClass_SetTexture);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,TextureLayer,IrrTexture);
}
void SRPAPI ClassOfIrrMaterialClass::SetShaderMaterialType(void *ShaderMaterialTypeObject)
{
    IrrMaterialClass_SetShaderMaterialTypeProc LocalProc;

    LocalProc = (IrrMaterialClass_SetShaderMaterialTypeProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrMaterialClass_SetShaderMaterialType);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,ShaderMaterialTypeObject);
}

ClassOfIrrAnimatedMeshClass::ClassOfIrrAnimatedMeshClass()
{
}

ClassOfIrrAnimatedMeshClass::ClassOfIrrAnimatedMeshClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrAnimatedMeshClass,0,NULL));
}

ClassOfIrrAnimatedMeshClass::ClassOfIrrAnimatedMeshClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrAnimatedMeshClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrAnimatedMeshClass" );
    return Buf;
}

class ClassOfIrrAnimatedMeshClass *ClassOfIrrAnimatedMeshClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrAnimatedMeshClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrAnimatedMeshClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrAnimatedMeshClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrAnimatedMeshClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

void ClassOfIrrAnimatedMeshClass::Put_F_OnBeforeCreate(void * In_Value)
{
    ThisSRPInterface -> CreateOVLFunction(ThisSRPObject,&VSFUNCID_IrrAnimatedMeshClass_OnBeforeCreate,In_Value,NULL);
}
void * ClassOfIrrAnimatedMeshClass::Get_F_OnBeforeCreate()
{
    return NULL;
}


void SRPAPI ClassOfIrrAnimatedMeshClass::OnBeforeCreate()
{
    ThisSRPInterface -> Call(ThisSRPObject,"OnBeforeCreate");
}
void SRPAPI ClassOfIrrAnimatedMeshClass::OnAfterCreate()
{
    ThisSRPInterface -> Call(ThisSRPObject,"OnAfterCreate");
}
void *SRPAPI ClassOfIrrAnimatedMeshClass::GetMesh(void *MeshObject,VS_INT32 Frame,VS_INT32 DetailLevel,VS_INT32 StartFrameLoop,VS_INT32 EndFrameLoop)
{
    IrrAnimatedMeshClass_GetMeshProc LocalProc;

    LocalProc = (IrrAnimatedMeshClass_GetMeshProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrAnimatedMeshClass_GetMesh);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,MeshObject,Frame,DetailLevel,StartFrameLoop,EndFrameLoop);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}

ClassOfIrrQ3LevelMeshClass::ClassOfIrrQ3LevelMeshClass()
{
}

ClassOfIrrQ3LevelMeshClass::ClassOfIrrQ3LevelMeshClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrQ3LevelMeshClass,0,NULL));
}

ClassOfIrrQ3LevelMeshClass::ClassOfIrrQ3LevelMeshClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrQ3LevelMeshClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrQ3LevelMeshClass" );
    return Buf;
}

class ClassOfIrrQ3LevelMeshClass *ClassOfIrrQ3LevelMeshClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrQ3LevelMeshClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrQ3LevelMeshClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrQ3LevelMeshClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrQ3LevelMeshClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

void *SRPAPI ClassOfIrrQ3LevelMeshClass::GetShader(VS_UINT32 Index)
{
    IrrQ3LevelMeshClass_GetShaderProc LocalProc;

    LocalProc = (IrrQ3LevelMeshClass_GetShaderProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrQ3LevelMeshClass_GetShader);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,Index);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}

ClassOfIrrTextureClass::ClassOfIrrTextureClass()
{
}

ClassOfIrrTextureClass::ClassOfIrrTextureClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrTextureClass,0,NULL));
}

ClassOfIrrTextureClass::ClassOfIrrTextureClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrTextureClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrTextureClass" );
    return Buf;
}

class ClassOfIrrTextureClass *ClassOfIrrTextureClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrTextureClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrTextureClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrTextureClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrTextureClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_CHAR * ClassOfIrrTextureClass::Get_TextureFile()
{
    return ((struct StructOfIrrTextureClass *)ThisSRPObject) -> TextureFile.Buf;
}
void ClassOfIrrTextureClass::Put_TextureFile(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRTEXTURECLASS_TEXTUREFILE,(VS_INT8 *)In_Value);
}

VS_BOOL ClassOfIrrTextureClass::Get_LoadResult()
{
    return ((struct StructOfIrrTextureClass *)ThisSRPObject) -> LoadResult;
}
void ClassOfIrrTextureClass::Put_LoadResult(VS_BOOL In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_IRRTEXTURECLASS_LOADRESULT,(VS_INT8 *)&In_Value);
}

VSSystemEvent_EventProc ClassOfIrrTextureClass::Get_E_OnChange()
{
    return NULL;
}
void ClassOfIrrTextureClass::Put_E_OnChange(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_IrrTextureClass_OnChange,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}

void ClassOfIrrTextureClass::Put_F_OnBeforeCreate(void * In_Value)
{
    ThisSRPInterface -> CreateOVLFunction(ThisSRPObject,&VSFUNCID_IrrTextureClass_OnBeforeCreate,In_Value,NULL);
}
void * ClassOfIrrTextureClass::Get_F_OnBeforeCreate()
{
    return NULL;
}


void SRPAPI ClassOfIrrTextureClass::OnBeforeCreate()
{
    ThisSRPInterface -> Call(ThisSRPObject,"OnBeforeCreate");
}
void SRPAPI ClassOfIrrTextureClass::OnAfterCreate()
{
    ThisSRPInterface -> Call(ThisSRPObject,"OnAfterCreate");
}
void SRPAPI ClassOfIrrTextureClass::TriggerChangeEvent()
{
    ThisSRPInterface -> Call(ThisSRPObject,"TriggerChangeEvent");
}
void SRPAPI ClassOfIrrTextureClass::SetIrrTexture(void *IrrTexturePtr)
{
    IrrTextureClass_SetIrrTextureProc LocalProc;

    LocalProc = (IrrTextureClass_SetIrrTextureProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_IrrTextureClass_SetIrrTexture);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,IrrTexturePtr);
}

ClassOfIrrFileSystemClass::ClassOfIrrFileSystemClass()
{
}

ClassOfIrrFileSystemClass::ClassOfIrrFileSystemClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrFileSystemClass,0,NULL));
}

ClassOfIrrFileSystemClass::ClassOfIrrFileSystemClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrFileSystemClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrFileSystemClass" );
    return Buf;
}

class ClassOfIrrFileSystemClass *ClassOfIrrFileSystemClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrFileSystemClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrFileSystemClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrFileSystemClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrFileSystemClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VSSystemEvent_EventProc ClassOfIrrFileSystemClass::Get_E_OnFileSystemChange()
{
    return NULL;
}
void ClassOfIrrFileSystemClass::Put_E_OnFileSystemChange(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_IrrFileSystemClass_OnFileSystemChange,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}


void SRPAPI ClassOfIrrFileSystemClass::AddZipFileArchive(VS_CHAR * FileName)
{
    ThisSRPInterface -> Call(ThisSRPObject,"AddZipFileArchive",FileName);
}

ClassOfIrrVideoDriverClass::ClassOfIrrVideoDriverClass()
{
}

ClassOfIrrVideoDriverClass::ClassOfIrrVideoDriverClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_IrrVideoDriverClass,0,NULL));
}

ClassOfIrrVideoDriverClass::ClassOfIrrVideoDriverClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfIrrVideoDriverClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "IrrVideoDriverClass" );
    return Buf;
}

class ClassOfIrrVideoDriverClass *ClassOfIrrVideoDriverClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfIrrVideoDriverClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfIrrVideoDriverClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "IrrVideoDriverClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfIrrVideoDriverClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}


/*--------------------------------------------------*/
