/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Class Header File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#ifndef SRPIRRLICHTES2ENGINE_CLASSHEADERFILE
#define SRPIRRLICHTES2ENGINE_CLASSHEADERFILE

#define _INCLUDE_STARLIB
#include "SRPIrrlichtES2Engine_VSHeader.h"
#include "SRPFSEngine_VSClass.h"

#if( VS_OS_TYPE == VS_OS_WINDOWS )
#pragma warning (disable:4819)
#pragma warning (disable:4244)
#pragma warning (disable:4996)
#pragma warning (disable:4800)
#endif

#pragma pack(4)

class ClassOfIrrDeviceClass:public ClassOfSRPObject{
public:
    ClassOfIrrDeviceClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrDeviceClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrDeviceClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrDeviceClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_COLOR Get_Color();
    void Put_Color(VS_COLOR In_Value);

    VS_INT32 Get_Width();
    void Put_Width(VS_INT32 In_Value);

    VS_INT32 Get_Height();
    void Put_Height(VS_INT32 In_Value);

    VS_ULONG Get_RenderWnd();
    void Put_RenderWnd(VS_ULONG In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_Color, put=Put_Color)) VS_COLOR Color;
    __declspec(property(get=Get_Width, put=Put_Width)) VS_INT32 Width;
    __declspec(property(get=Get_Height, put=Put_Height)) VS_INT32 Height;
    __declspec(property(get=Get_RenderWnd, put=Put_RenderWnd)) VS_ULONG RenderWnd;
#endif

public:
    //--Function Define
    void *SRPAPI GetCurDevice();
    void SRPAPI Render();
    void SRPAPI SetSize(VS_INT32 Width,VS_INT32 Height);
    void *SRPAPI GetSceneManager();
    void *SRPAPI GetVideoDriver();
    void *SRPAPI GetFileSystem();
};

class ClassOfIrrObjectClass:public ClassOfSRPObject{
public:
    ClassOfIrrObjectClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrObjectClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrObjectClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrObjectClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_BOOL Get_WrapIrrFlag();
    void Put_WrapIrrFlag(VS_BOOL In_Value);


public:
    //--PubFunction Get/Put Function Define
    void Put_F_SetIrrParentSceneNode(void * In_Value);
    void * Get_F_SetIrrParentSceneNode();


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_WrapIrrFlag, put=Put_WrapIrrFlag)) VS_BOOL WrapIrrFlag;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--PubFunction Property Define
    __declspec(property(get=Get_F_SetIrrParentSceneNode, put=Put_F_SetIrrParentSceneNode)) void * F_SetIrrParentSceneNode;
#endif

public:
    //--Function Define
    void SRPAPI SetIrrObject(void *IrrObject);
    void *SRPAPI GetIrrObject();
    void SRPAPI SetIrrParentSceneNode(void *IrrParentObject);
};

class ClassOfIrrMeshClass:public ClassOfIrrObjectClass{
public:
    ClassOfIrrMeshClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrMeshClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrMeshClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrMeshClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_CHAR * Get_MeshFile();
    void Put_MeshFile(VS_CHAR * In_Value);

    VS_BOOL Get_LoadResult();
    void Put_LoadResult(VS_BOOL In_Value);


public:
    //--OutEvent Get/Put Function Define
    VSSystemEvent_EventProc Get_E_OnChange();
    void Put_E_OnChange(VSSystemEvent_EventProc In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_MeshFile, put=Put_MeshFile)) VS_VSTRING MeshFile;
    __declspec(property(get=Get_LoadResult, put=Put_LoadResult)) VS_BOOL LoadResult;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--OutEvent Property Define
    __declspec(property(get=Get_E_OnChange, put=Put_E_OnChange)) VSSystemEvent_EventProc E_OnChange;
#endif

public:
    //--Function Define
    void SRPAPI TriggerChangeEvent();
    VS_INT32 SRPAPI GetMeshBufferCount();
    void *SRPAPI GetMeshBuffer(void *MeshBufferObject,VS_INT32 Index);
};

class ClassOfIrrSceneManagerClass:public ClassOfIrrObjectClass{
public:
    ClassOfIrrSceneManagerClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrSceneManagerClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrSceneManagerClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrSceneManagerClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
};

class ClassOfIrrSceneNodeClass:public ClassOfIrrObjectClass{
public:
    ClassOfIrrSceneNodeClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrSceneNodeClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    struct StructOfSRP3DVector * Get_Position();
    void Put_Position(struct StructOfSRP3DVector * In_Value);

    struct StructOfSRP3DVector * Get_Rotation();
    void Put_Rotation(struct StructOfSRP3DVector * In_Value);

    struct StructOfSRP3DVector * Get_Scale();
    void Put_Scale(struct StructOfSRP3DVector * In_Value);

    VS_BOOL Get_Visible();
    void Put_Visible(VS_BOOL In_Value);

    VS_INT32 Get_AutomaticCullingState();
    void Put_AutomaticCullingState(VS_INT32 In_Value);

    VS_INT32 Get_Id();
    void Put_Id(VS_INT32 In_Value);


public:
    //--OutEvent Get/Put Function Define
    VSSystemEvent_EventProc Get_E_OnIrrInit();
    void Put_E_OnIrrInit(VSSystemEvent_EventProc In_Value);


public:
    //--PubFunction Get/Put Function Define
    void Put_FOVL_SetIrrParentSceneNode(void * In_Value);
    void * Get_FOVL_SetIrrParentSceneNode();


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_Position, put=Put_Position)) struct StructOfSRP3DVector Position;
    __declspec(property(get=Get_Rotation, put=Put_Rotation)) struct StructOfSRP3DVector Rotation;
    __declspec(property(get=Get_Scale, put=Put_Scale)) struct StructOfSRP3DVector Scale;
    __declspec(property(get=Get_Visible, put=Put_Visible)) VS_BOOL Visible;
    __declspec(property(get=Get_AutomaticCullingState, put=Put_AutomaticCullingState)) VS_INT32 AutomaticCullingState;
    __declspec(property(get=Get_Id, put=Put_Id)) VS_INT32 Id;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--OutEvent Property Define
    __declspec(property(get=Get_E_OnIrrInit, put=Put_E_OnIrrInit)) VSSystemEvent_EventProc E_OnIrrInit;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--PubFunction Property Define
    __declspec(property(get=Get_FOVL_SetIrrParentSceneNode, put=Put_FOVL_SetIrrParentSceneNode)) void * FOVL_SetIrrParentSceneNode;
#endif

public:
    //--Function Define
    void *SRPAPI GetSceneManager();
    void SRPAPI SetMaterialTexture(VS_UINT32 TextureLayer,void *IrrTexture);
    void SRPAPI SetMaterialTextureEx(VS_UINT32 TextureLayer,VS_CHAR * TextureFile);
    void SRPAPI SetMaterialFlag(VS_INT32 Flag,VS_BOOL NewValue);
    void SRPAPI SetMaterialType(VS_INT32 NewType);
};

class ClassOfIrrAnimatedMeshSceneNodeClass:public ClassOfIrrSceneNodeClass{
public:
    ClassOfIrrAnimatedMeshSceneNodeClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrAnimatedMeshSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrAnimatedMeshSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrAnimatedMeshSceneNodeClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_CHAR * Get_MeshFile();
    void Put_MeshFile(VS_CHAR * In_Value);

    VS_INT32 Get_MD2AnimationType();
    void Put_MD2AnimationType(VS_INT32 In_Value);

    VS_FLOAT Get_FramesPerSecond();
    void Put_FramesPerSecond(VS_FLOAT In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_MeshFile, put=Put_MeshFile)) VS_VSTRING MeshFile;
    __declspec(property(get=Get_MD2AnimationType, put=Put_MD2AnimationType)) VS_INT32 MD2AnimationType;
    __declspec(property(get=Get_FramesPerSecond, put=Put_FramesPerSecond)) VS_FLOAT FramesPerSecond;
#endif

public:
    //--Function Define
    void SRPAPI SetFrameLoop(VS_INT32 Begin,VS_INT32 End);
    void SRPAPI SetAnimationSpeed(VS_FLOAT FramesPerSecond);
};

class ClassOfIrrShaderMaterialTypeClass:public ClassOfIrrObjectClass{
public:
    ClassOfIrrShaderMaterialTypeClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrShaderMaterialTypeClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrShaderMaterialTypeClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrShaderMaterialTypeClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_CHAR * Get_VertexFileName();
    void Put_VertexFileName(VS_CHAR * In_Value);

    VS_CHAR * Get_PixelFileName();
    void Put_PixelFileName(VS_CHAR * In_Value);

    VS_CHAR * Get_CallBackName();
    void Put_CallBackName(VS_CHAR * In_Value);

    VS_INT32 Get_BaseMaterial();
    void Put_BaseMaterial(VS_INT32 In_Value);


public:
    //--OutEvent Get/Put Function Define
    VSSystemEvent_EventProc Get_E_OnChange();
    void Put_E_OnChange(VSSystemEvent_EventProc In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_VertexFileName, put=Put_VertexFileName)) VS_VSTRING VertexFileName;
    __declspec(property(get=Get_PixelFileName, put=Put_PixelFileName)) VS_VSTRING PixelFileName;
    __declspec(property(get=Get_CallBackName, put=Put_CallBackName)) VS_VSTRING CallBackName;
    __declspec(property(get=Get_BaseMaterial, put=Put_BaseMaterial)) VS_INT32 BaseMaterial;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--OutEvent Property Define
    __declspec(property(get=Get_E_OnChange, put=Put_E_OnChange)) VSSystemEvent_EventProc E_OnChange;
#endif

public:
    //--Function Define
    void SRPAPI SetMaterialType(VS_INT32 Type);
    VS_INT32 SRPAPI GetMaterialType();
};

class ClassOfIrrCameraSceneNodeClass:public ClassOfIrrSceneNodeClass{
public:
    ClassOfIrrCameraSceneNodeClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrCameraSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrCameraSceneNodeClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrCameraSceneNodeClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    struct StructOfSRP3DVector * Get_Target();
    void Put_Target(struct StructOfSRP3DVector * In_Value);

    VS_FLOAT Get_ZNear();
    void Put_ZNear(VS_FLOAT In_Value);

    VS_FLOAT Get_ZFar();
    void Put_ZFar(VS_FLOAT In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_Target, put=Put_Target)) struct StructOfSRP3DVector Target;
    __declspec(property(get=Get_ZNear, put=Put_ZNear)) VS_FLOAT ZNear;
    __declspec(property(get=Get_ZFar, put=Put_ZFar)) VS_FLOAT ZFar;
#endif

public:
    //--Function Define
    void SRPAPI GetTarget(struct StructOfSRP3DVector * Position);
};

class ClassOfIrrMaterialClass:public ClassOfIrrObjectClass{
public:
    ClassOfIrrMaterialClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrMaterialClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrMaterialClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrMaterialClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_INT32 Get_MaterialType();
    void Put_MaterialType(VS_INT32 In_Value);

    VS_COLOR Get_AmbientColor();
    void Put_AmbientColor(VS_COLOR In_Value);

    VS_COLOR Get_DiffuseColor();
    void Put_DiffuseColor(VS_COLOR In_Value);

    VS_COLOR Get_EmissiveColor();
    void Put_EmissiveColor(VS_COLOR In_Value);

    VS_COLOR Get_SpecularColor();
    void Put_SpecularColor(VS_COLOR In_Value);

    VS_FLOAT Get_Shininess();
    void Put_Shininess(VS_FLOAT In_Value);

    VS_FLOAT Get_MaterialTypeParam();
    void Put_MaterialTypeParam(VS_FLOAT In_Value);

    VS_FLOAT Get_MaterialTypeParam2();
    void Put_MaterialTypeParam2(VS_FLOAT In_Value);

    VS_FLOAT Get_Thickness();
    void Put_Thickness(VS_FLOAT In_Value);

    VS_BOOL Get_Wireframe();
    void Put_Wireframe(VS_BOOL In_Value);

    VS_BOOL Get_PointCloud();
    void Put_PointCloud(VS_BOOL In_Value);

    VS_BOOL Get_GouraudShading();
    void Put_GouraudShading(VS_BOOL In_Value);

    VS_BOOL Get_Lighting();
    void Put_Lighting(VS_BOOL In_Value);

    VS_BOOL Get_ZWriteEnable();
    void Put_ZWriteEnable(VS_BOOL In_Value);

    VS_BOOL Get_BackfaceCulling();
    void Put_BackfaceCulling(VS_BOOL In_Value);

    VS_BOOL Get_FogEnable();
    void Put_FogEnable(VS_BOOL In_Value);

    VS_BOOL Get_NormalizeNormals();
    void Put_NormalizeNormals(VS_BOOL In_Value);

    VS_UINT32 Get_ZBuffer();
    void Put_ZBuffer(VS_UINT32 In_Value);


public:
    //--OutEvent Get/Put Function Define
    VSSystemEvent_EventProc Get_E_OnIrrInit();
    void Put_E_OnIrrInit(VSSystemEvent_EventProc In_Value);

    VSSystemEvent_EventProc Get_E_OnChange();
    void Put_E_OnChange(VSSystemEvent_EventProc In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_MaterialType, put=Put_MaterialType)) VS_INT32 MaterialType;
    __declspec(property(get=Get_AmbientColor, put=Put_AmbientColor)) VS_COLOR AmbientColor;
    __declspec(property(get=Get_DiffuseColor, put=Put_DiffuseColor)) VS_COLOR DiffuseColor;
    __declspec(property(get=Get_EmissiveColor, put=Put_EmissiveColor)) VS_COLOR EmissiveColor;
    __declspec(property(get=Get_SpecularColor, put=Put_SpecularColor)) VS_COLOR SpecularColor;
    __declspec(property(get=Get_Shininess, put=Put_Shininess)) VS_FLOAT Shininess;
    __declspec(property(get=Get_MaterialTypeParam, put=Put_MaterialTypeParam)) VS_FLOAT MaterialTypeParam;
    __declspec(property(get=Get_MaterialTypeParam2, put=Put_MaterialTypeParam2)) VS_FLOAT MaterialTypeParam2;
    __declspec(property(get=Get_Thickness, put=Put_Thickness)) VS_FLOAT Thickness;
    __declspec(property(get=Get_Wireframe, put=Put_Wireframe)) VS_BOOL Wireframe;
    __declspec(property(get=Get_PointCloud, put=Put_PointCloud)) VS_BOOL PointCloud;
    __declspec(property(get=Get_GouraudShading, put=Put_GouraudShading)) VS_BOOL GouraudShading;
    __declspec(property(get=Get_Lighting, put=Put_Lighting)) VS_BOOL Lighting;
    __declspec(property(get=Get_ZWriteEnable, put=Put_ZWriteEnable)) VS_BOOL ZWriteEnable;
    __declspec(property(get=Get_BackfaceCulling, put=Put_BackfaceCulling)) VS_BOOL BackfaceCulling;
    __declspec(property(get=Get_FogEnable, put=Put_FogEnable)) VS_BOOL FogEnable;
    __declspec(property(get=Get_NormalizeNormals, put=Put_NormalizeNormals)) VS_BOOL NormalizeNormals;
    __declspec(property(get=Get_ZBuffer, put=Put_ZBuffer)) VS_UINT32 ZBuffer;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--OutEvent Property Define
    __declspec(property(get=Get_E_OnIrrInit, put=Put_E_OnIrrInit)) VSSystemEvent_EventProc E_OnIrrInit;
    __declspec(property(get=Get_E_OnChange, put=Put_E_OnChange)) VSSystemEvent_EventProc E_OnChange;
#endif

public:
    //--Function Define
    void SRPAPI SetTexture(VS_UINT32 TextureLayer,void *IrrTexture);
    void SRPAPI SetShaderMaterialType(void *ShaderMaterialTypeObject);
};

class ClassOfIrrAnimatedMeshClass:public ClassOfIrrMeshClass{
public:
    ClassOfIrrAnimatedMeshClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrAnimatedMeshClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrAnimatedMeshClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrAnimatedMeshClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--PubFunction Get/Put Function Define
    void Put_F_OnBeforeCreate(void * In_Value);
    void * Get_F_OnBeforeCreate();


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--PubFunction Property Define
    __declspec(property(get=Get_F_OnBeforeCreate, put=Put_F_OnBeforeCreate)) void * F_OnBeforeCreate;
#endif

public:
    //--Function Define
    void SRPAPI OnBeforeCreate();
    void SRPAPI OnAfterCreate();
    void *SRPAPI GetMesh(void *MeshObject,VS_INT32 Frame,VS_INT32 DetailLevel,VS_INT32 StartFrameLoop,VS_INT32 EndFrameLoop);
};

class ClassOfIrrQ3LevelMeshClass:public ClassOfIrrAnimatedMeshClass{
public:
    ClassOfIrrQ3LevelMeshClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrQ3LevelMeshClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrQ3LevelMeshClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrQ3LevelMeshClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Function Define
    void *SRPAPI GetShader(VS_UINT32 Index);
};

class ClassOfIrrTextureClass:public ClassOfIrrObjectClass{
public:
    ClassOfIrrTextureClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrTextureClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrTextureClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrTextureClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_CHAR * Get_TextureFile();
    void Put_TextureFile(VS_CHAR * In_Value);

    VS_BOOL Get_LoadResult();
    void Put_LoadResult(VS_BOOL In_Value);


public:
    //--OutEvent Get/Put Function Define
    VSSystemEvent_EventProc Get_E_OnChange();
    void Put_E_OnChange(VSSystemEvent_EventProc In_Value);


public:
    //--PubFunction Get/Put Function Define
    void Put_F_OnBeforeCreate(void * In_Value);
    void * Get_F_OnBeforeCreate();


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_TextureFile, put=Put_TextureFile)) VS_VSTRING TextureFile;
    __declspec(property(get=Get_LoadResult, put=Put_LoadResult)) VS_BOOL LoadResult;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--OutEvent Property Define
    __declspec(property(get=Get_E_OnChange, put=Put_E_OnChange)) VSSystemEvent_EventProc E_OnChange;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--PubFunction Property Define
    __declspec(property(get=Get_F_OnBeforeCreate, put=Put_F_OnBeforeCreate)) void * F_OnBeforeCreate;
#endif

public:
    //--Function Define
    void SRPAPI OnBeforeCreate();
    void SRPAPI OnAfterCreate();
    void SRPAPI TriggerChangeEvent();
    void SRPAPI SetIrrTexture(void *IrrTexturePtr);
};

class ClassOfIrrFileSystemClass:public ClassOfIrrObjectClass{
public:
    ClassOfIrrFileSystemClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrFileSystemClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrFileSystemClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrFileSystemClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--OutEvent Get/Put Function Define
    VSSystemEvent_EventProc Get_E_OnFileSystemChange();
    void Put_E_OnFileSystemChange(VSSystemEvent_EventProc In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--OutEvent Property Define
    __declspec(property(get=Get_E_OnFileSystemChange, put=Put_E_OnFileSystemChange)) VSSystemEvent_EventProc E_OnFileSystemChange;
#endif

public:
    //--Function Define
    void SRPAPI AddZipFileArchive(VS_CHAR * FileName);
};

class ClassOfIrrVideoDriverClass:public ClassOfIrrObjectClass{
public:
    ClassOfIrrVideoDriverClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfIrrVideoDriverClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfIrrVideoDriverClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfIrrVideoDriverClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
};

/*--------------------------------------------------*/

#pragma pack()

#endif
