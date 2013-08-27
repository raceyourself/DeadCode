/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Header File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#ifndef SRPIRRLICHTES2ENGINE_HEADERFILE
#define SRPIRRLICHTES2ENGINE_HEADERFILE

#include "SRPIrrlichtES2Engine.h"
#include "SRPFSEngine_VSDHeader.h"
#if( VS_OS_TYPE == VS_OS_WINDOWS )

#pragma warning (disable:4819)
#pragma warning (disable:4244)
#pragma warning (disable:4996)
#pragma warning (disable:4800)
#endif

#pragma pack(4)

/*--------------------------------------------------*/
extern "C" SRPDLLEXPORT VS_ULONG VSModuleFunction_GetVersion();
extern "C" SRPDLLEXPORT void VSModuleFunction_GetModuleInfo(VS_INT8 *InfoBuf,VS_INT32 BufSize);
extern "C" SRPDLLEXPORT VS_INT32 VSModuleFunction_ModuleInit(VS_ULONG ServiceGroupID, VS_QueryServiceInterfaceProc QueryServiceInterface);
extern "C" SRPDLLEXPORT void VSModuleFunction_SetModuleHandle(VS_HANDLE hModuleHandle);
extern "C" SRPDLLEXPORT VS_INT32 VSModuleFunction_ModuleTerm();
extern "C" SRPDLLEXPORT VS_INT32 VSModuleFunction_RequestRegisterObject();

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
//----output sysrootitem name and ID
#define VSOBJNAME_BASICSERVICEITEM                                                         "BasicServiceItem"
extern VS_UUID VSOBJID_BasicServiceItem;

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSIMPORTMODULENAME_SRPIRRLICHTES2ENGINEBASICMODULE                                 "SRPIrrlichtES2EngineBasicModule"  
extern VS_UUID VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule;

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRANIMATEDMESHSCENENODECLASS                                                    "IrrAnimatedMeshSceneNodeClass"
extern VS_UUID VSOBJID_IrrAnimatedMeshSceneNodeClass;
#define VSATTRDEPEND_IRRANIMATEDMESHSCENENODECLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=16;X[1].Offset=4;}{X[2].Type=16;X[2].Offset=16;}{X[3].Type=16;X[3].Offset=28;}{X[4].Type=1;X[4].Offset=40;}{X[5].Type=6;X[5].Offset=44;}{X[6].Type=6;X[6].Offset=48;}{X[7].Type=14;X[7].Offset=52;}{X[8].Type=14;X[8].Offset=56;}{X[9].Type=14;X[9].Offset=60;}{X[10].Type=14;X[10].Offset=64;}{X[11].Type=14;X[11].Offset=68;}{X[12].Type=14;X[12].Offset=72;}{X[13].Type=51;X[13].Offset=76;}{X[14].Type=6;X[14].Offset=80;}{X[15].Type=8;X[15].Offset=84;}}
#define VSATTRDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS                                              16
extern VS_INT32 SRPCALLBACK IrrAnimatedMeshSceneNodeClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_WRAPIRRFLAG                                      0
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_POSITION                                         1
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_ROTATION                                         2
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_SCALE                                            3
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_VISIBLE                                          4
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_AUTOMATICCULLINGSTATE                            5
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_ID                                               6
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_SCENENODELIST                                    7
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_MATERIALLIST                                     8
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_TEXTURELIST                                      9
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_MESHLIST                                         10
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_ANIMATORLIST                                     11
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_SELECTORLIST                                     12
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_MESHFILE                                         13
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_MD2ANIMATIONTYPE                                 14
#define VSATTRINDEX_IRRANIMATEDMESHSCENENODECLASS_FRAMESPERSECOND                                  15
#define VSATTRNUMBER_IRRANIMATEDMESHSCENENODECLASS                                                 16

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrAnimatedMeshSceneNodeClass_SetFrameLoop;
#define VSFUNCRETURNDEPEND_IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP                           0
#define VSFUNCPARAMDEPEND_IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP(X)  {{X[0].Type=6;}{X[1].Type=6;}}
#define VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP                            2

extern void SRPAPI IrrAnimatedMeshSceneNodeClass_SetFrameLoop(void *Object,VS_INT32 Begin,VS_INT32 End);
typedef void (SRPAPI *IrrAnimatedMeshSceneNodeClass_SetFrameLoopProc)(void *Object,VS_INT32 Begin,VS_INT32 End);

/*[Private Function] : Lua_SetFrameLoop(Begin,End)    */
extern VS_UUID VSFUNCID_IrrAnimatedMeshSceneNodeClass_Lua_SetFrameLoop;
#define VSFUNCRETURNDEPEND_IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP                       0
#define VSFUNCPARAMDEPEND_IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP                        0

extern VS_INT32 SRPAPI IrrAnimatedMeshSceneNodeClass_Lua_SetFrameLoop(void);
typedef VS_INT32 (SRPAPI *IrrAnimatedMeshSceneNodeClass_Lua_SetFrameLoopProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrAnimatedMeshSceneNodeClass_SetAnimationSpeed;
#define VSFUNCRETURNDEPEND_IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED                      0
#define VSFUNCPARAMDEPEND_IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED(X)  {{X[0].Type=8;}}
#define VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED                       1

extern void SRPAPI IrrAnimatedMeshSceneNodeClass_SetAnimationSpeed(void *Object,VS_FLOAT FramesPerSecond);
typedef void (SRPAPI *IrrAnimatedMeshSceneNodeClass_SetAnimationSpeedProc)(void *Object,VS_FLOAT FramesPerSecond);

/*[Private Function] : Lua_SetAnimationSpeed(FramesPerSecond)    */
extern VS_UUID VSFUNCID_IrrAnimatedMeshSceneNodeClass_Lua_SetAnimationSpeed;
#define VSFUNCRETURNDEPEND_IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED                  0
#define VSFUNCPARAMDEPEND_IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED                   0

extern VS_INT32 SRPAPI IrrAnimatedMeshSceneNodeClass_Lua_SetAnimationSpeed(void);
typedef VS_INT32 (SRPAPI *IrrAnimatedMeshSceneNodeClass_Lua_SetAnimationSpeedProc)(void);

extern VS_INT32 SRPCALLBACK IrrAnimatedMeshSceneNodeClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrAnimatedMeshSceneNodeClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrAnimatedMeshSceneNodeClass{
};
struct StructOfIrrAnimatedMeshSceneNodeClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----class[IrrSceneNodeClass] attribute
    VS_INT8         Reserve1[3];                  
    struct StructOfSRP3DVector Position;          //
    struct StructOfSRP3DVector Rotation;          //
    struct StructOfSRP3DVector Scale;             //
    VS_BOOL         Visible;                      //
    VS_INT8         Reserve5[3];                  
    VS_INT32        AutomaticCullingState;        //
    VS_INT32        Id;                           //
    void            *SceneNodeList;               //
    void            *MaterialList;                //
    void            *TextureList;                 //
    void            *MeshList;                    //
    void            *AnimatorList;                //
    void            *SelectorList;                //
    //----local attribute
    VS_VSTRING      MeshFile;                     //
    VS_INT32        MD2AnimationType;             //
    VS_FLOAT        FramesPerSecond;              //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_SRPIRRLICHTES2ENGINE                                                             "SRPIrrlichtES2Engine"
extern VS_UUID VSOBJID_SRPIrrlichtES2Engine;

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRMESHCLASS                                                                     "IrrMeshClass"
extern VS_UUID VSOBJID_IrrMeshClass;
#define VSATTRDEPEND_IRRMESHCLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=51;X[1].Offset=4;}{X[2].Type=1;X[2].Offset=8;}}
#define VSATTRDEPENDNUM_IRRMESHCLASS                                                               3
extern VS_INT32 SRPCALLBACK IrrMeshClass_RequestRegisterObject( );

/*----output event: OnChange[]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_IrrMeshClass_OnChange;

/*------Variable Index Define */
#define VSATTRINDEX_IRRMESHCLASS_WRAPIRRFLAG                                                       0
#define VSATTRINDEX_IRRMESHCLASS_MESHFILE                                                          1
#define VSATTRINDEX_IRRMESHCLASS_LOADRESULT                                                        2
#define VSATTRNUMBER_IRRMESHCLASS                                                                  3

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrMeshClass_TriggerChangeEvent;
#define VSFUNCRETURNDEPEND_IRRMESHCLASS_TRIGGERCHANGEEVENT(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_TRIGGERCHANGEEVENT                                      0
#define VSFUNCPARAMDEPEND_IRRMESHCLASS_TRIGGERCHANGEEVENT(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_TRIGGERCHANGEEVENT                                       0

extern void SRPAPI IrrMeshClass_TriggerChangeEvent(void *Object);
typedef void (SRPAPI *IrrMeshClass_TriggerChangeEventProc)(void *Object);

/*[Private Function] : Lua_TriggerChangeEvent()    */
extern VS_UUID VSFUNCID_IrrMeshClass_Lua_TriggerChangeEvent;
#define VSFUNCRETURNDEPEND_IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT                                  0
#define VSFUNCPARAMDEPEND_IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT                                   0

extern VS_INT32 SRPAPI IrrMeshClass_Lua_TriggerChangeEvent(void);
typedef VS_INT32 (SRPAPI *IrrMeshClass_Lua_TriggerChangeEventProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrMeshClass_GetMeshBufferCount;
#define VSFUNCRETURNDEPEND_IRRMESHCLASS_GETMESHBUFFERCOUNT(X)  {{X[0].Type=6;}}
#define VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_GETMESHBUFFERCOUNT                                      1
#define VSFUNCPARAMDEPEND_IRRMESHCLASS_GETMESHBUFFERCOUNT(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_GETMESHBUFFERCOUNT                                       0

extern VS_INT32 SRPAPI IrrMeshClass_GetMeshBufferCount(void *Object);
typedef VS_INT32 (SRPAPI *IrrMeshClass_GetMeshBufferCountProc)(void *Object);

/*[Private Function] : Count=Lua_GetMeshBufferCount()    */
extern VS_UUID VSFUNCID_IrrMeshClass_Lua_GetMeshBufferCount;
#define VSFUNCRETURNDEPEND_IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT                                  0
#define VSFUNCPARAMDEPEND_IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT                                   0

extern VS_INT32 SRPAPI IrrMeshClass_Lua_GetMeshBufferCount(void);
typedef VS_INT32 (SRPAPI *IrrMeshClass_Lua_GetMeshBufferCountProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrMeshClass_GetMeshBuffer;
#define VSFUNCRETURNDEPEND_IRRMESHCLASS_GETMESHBUFFER(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_GETMESHBUFFER                                           1
#define VSFUNCPARAMDEPEND_IRRMESHCLASS_GETMESHBUFFER(X)  {{X[0].Type=14;}{X[1].Type=6;}}
#define VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_GETMESHBUFFER                                            2

extern void *SRPAPI IrrMeshClass_GetMeshBuffer(void *Object,void *MeshBufferObject,VS_INT32 Index);
typedef void *(SRPAPI *IrrMeshClass_GetMeshBufferProc)(void *Object,void *MeshBufferObject,VS_INT32 Index);

/*[Private Function] : MeshBufferObject=Lua_GetMeshBuffer(MeshBufferObject,Index)    */
extern VS_UUID VSFUNCID_IrrMeshClass_Lua_GetMeshBuffer;
#define VSFUNCRETURNDEPEND_IRRMESHCLASS_LUA_GETMESHBUFFER(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_LUA_GETMESHBUFFER                                       0
#define VSFUNCPARAMDEPEND_IRRMESHCLASS_LUA_GETMESHBUFFER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_LUA_GETMESHBUFFER                                        0

extern VS_INT32 SRPAPI IrrMeshClass_Lua_GetMeshBuffer(void);
typedef VS_INT32 (SRPAPI *IrrMeshClass_Lua_GetMeshBufferProc)(void);

extern VS_INT32 SRPCALLBACK IrrMeshClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrMeshClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrMeshClass{
};
struct StructOfIrrMeshClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----local attribute
    VS_INT8         Reserve1[3];                  
    VS_VSTRING      MeshFile;                     //
    VS_BOOL         LoadResult;                   //
    VS_INT8         Reserve3[3];                  
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRQ3LEVELMESHCLASS                                                              "IrrQ3LevelMeshClass"
extern VS_UUID VSOBJID_IrrQ3LevelMeshClass;
#define VSATTRDEPEND_IRRQ3LEVELMESHCLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=51;X[1].Offset=4;}{X[2].Type=1;X[2].Offset=8;}}
#define VSATTRDEPENDNUM_IRRQ3LEVELMESHCLASS                                                        3
extern VS_INT32 SRPCALLBACK IrrQ3LevelMeshClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_IRRQ3LEVELMESHCLASS_WRAPIRRFLAG                                                0
#define VSATTRINDEX_IRRQ3LEVELMESHCLASS_MESHFILE                                                   1
#define VSATTRINDEX_IRRQ3LEVELMESHCLASS_LOADRESULT                                                 2
#define VSATTRNUMBER_IRRQ3LEVELMESHCLASS                                                           3

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrQ3LevelMeshClass_GetShader;
#define VSFUNCRETURNDEPEND_IRRQ3LEVELMESHCLASS_GETSHADER(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRRQ3LEVELMESHCLASS_GETSHADER                                        1
#define VSFUNCPARAMDEPEND_IRRQ3LEVELMESHCLASS_GETSHADER(X)  {{X[0].Type=7;}}
#define VSFUNCPARAMDEPENDNUM_IRRQ3LEVELMESHCLASS_GETSHADER                                         1

extern void *SRPAPI IrrQ3LevelMeshClass_GetShader(void *Object,VS_UINT32 Index);
typedef void *(SRPAPI *IrrQ3LevelMeshClass_GetShaderProc)(void *Object,VS_UINT32 Index);

/*[Private Function] : Shader=Lua_GetShader(Index) ;    */
extern VS_UUID VSFUNCID_IrrQ3LevelMeshClass_Lua_GetShader;
#define VSFUNCRETURNDEPEND_IRRQ3LEVELMESHCLASS_LUA_GETSHADER(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRQ3LEVELMESHCLASS_LUA_GETSHADER                                    0
#define VSFUNCPARAMDEPEND_IRRQ3LEVELMESHCLASS_LUA_GETSHADER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRQ3LEVELMESHCLASS_LUA_GETSHADER                                     0

extern VS_INT32 SRPAPI IrrQ3LevelMeshClass_Lua_GetShader(void);
typedef VS_INT32 (SRPAPI *IrrQ3LevelMeshClass_Lua_GetShaderProc)(void);

extern VS_INT32 SRPCALLBACK IrrQ3LevelMeshClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrQ3LevelMeshClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrQ3LevelMeshClass{
};
struct StructOfIrrQ3LevelMeshClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----class[IrrMeshClass] attribute
    VS_INT8         Reserve1[3];                  
    VS_VSTRING      MeshFile;                     //
    VS_BOOL         LoadResult;                   //
    VS_INT8         Reserve3[3];                  
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRSCENEMANAGERCLASS                                                             "IrrSceneManagerClass"
extern VS_UUID VSOBJID_IrrSceneManagerClass;
#define VSATTRDEPEND_IRRSCENEMANAGERCLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=14;X[1].Offset=4;}{X[2].Type=14;X[2].Offset=8;}{X[3].Type=14;X[3].Offset=12;}{X[4].Type=14;X[4].Offset=16;}{X[5].Type=14;X[5].Offset=20;}}
#define VSATTRDEPENDNUM_IRRSCENEMANAGERCLASS                                                       6
extern VS_INT32 SRPCALLBACK IrrSceneManagerClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_IRRSCENEMANAGERCLASS_WRAPIRRFLAG                                               0
#define VSATTRINDEX_IRRSCENEMANAGERCLASS_SCENENODELIST                                             1
#define VSATTRINDEX_IRRSCENEMANAGERCLASS_TEXTURELIST                                               2
#define VSATTRINDEX_IRRSCENEMANAGERCLASS_MESHLIST                                                  3
#define VSATTRINDEX_IRRSCENEMANAGERCLASS_MATERIALLIST                                              4
#define VSATTRINDEX_IRRSCENEMANAGERCLASS_ANIMATORLLIST                                             5
#define VSATTRNUMBER_IRRSCENEMANAGERCLASS                                                          6

extern VS_INT32 SRPCALLBACK IrrSceneManagerClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrSceneManagerClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrSceneManagerClass{
};
struct StructOfIrrSceneManagerClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----local attribute
    VS_INT8         Reserve1[3];                  
    void            *SceneNodeList;               //
    void            *TextureList;                 //
    void            *MeshList;                    //
    void            *MaterialList;                //
    void            *AnimatorlList;               //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRSCENENODECLASS                                                                "IrrSceneNodeClass"
extern VS_UUID VSOBJID_IrrSceneNodeClass;
#define VSATTRDEPEND_IRRSCENENODECLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=16;X[1].Offset=4;}{X[2].Type=16;X[2].Offset=16;}{X[3].Type=16;X[3].Offset=28;}{X[4].Type=1;X[4].Offset=40;}{X[5].Type=6;X[5].Offset=44;}{X[6].Type=6;X[6].Offset=48;}{X[7].Type=14;X[7].Offset=52;}{X[8].Type=14;X[8].Offset=56;}{X[9].Type=14;X[9].Offset=60;}{X[10].Type=14;X[10].Offset=64;}{X[11].Type=14;X[11].Offset=68;}{X[12].Type=14;X[12].Offset=72;}}
#define VSATTRDEPENDNUM_IRRSCENENODECLASS                                                          13
extern VS_INT32 SRPCALLBACK IrrSceneNodeClass_RequestRegisterObject( );

/*----output event: OnIrrInit[]  Static Event */
extern VS_UUID VSOUTEVENTID_IrrSceneNodeClass_OnIrrInit;

/*------Variable Index Define */
#define VSATTRINDEX_IRRSCENENODECLASS_WRAPIRRFLAG                                                  0
#define VSATTRINDEX_IRRSCENENODECLASS_POSITION                                                     1
#define VSATTRINDEX_IRRSCENENODECLASS_ROTATION                                                     2
#define VSATTRINDEX_IRRSCENENODECLASS_SCALE                                                        3
#define VSATTRINDEX_IRRSCENENODECLASS_VISIBLE                                                      4
#define VSATTRINDEX_IRRSCENENODECLASS_AUTOMATICCULLINGSTATE                                        5
#define VSATTRINDEX_IRRSCENENODECLASS_ID                                                           6
#define VSATTRINDEX_IRRSCENENODECLASS_SCENENODELIST                                                7
#define VSATTRINDEX_IRRSCENENODECLASS_MATERIALLIST                                                 8
#define VSATTRINDEX_IRRSCENENODECLASS_TEXTURELIST                                                  9
#define VSATTRINDEX_IRRSCENENODECLASS_MESHLIST                                                     10
#define VSATTRINDEX_IRRSCENENODECLASS_ANIMATORLIST                                                 11
#define VSATTRINDEX_IRRSCENENODECLASS_SELECTORLIST                                                 12
#define VSATTRNUMBER_IRRSCENENODECLASS                                                             13

/*------Local Define Function */
/*[Public Function] :     */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_OVL_SetIrrParentSceneNode;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_OVL_SETIRRPARENTSCENENODE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_OVL_SETIRRPARENTSCENENODE                          0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_OVL_SETIRRPARENTSCENENODE(X)  {{X[0].Type=14;}}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_OVL_SETIRRPARENTSCENENODE                           1

extern void SRPAPI IrrSceneNodeClass_OVL_SetIrrParentSceneNode(void *Object,void *IrrParentObject);
typedef void (SRPAPI *IrrSceneNodeClass_OVL_SetIrrParentSceneNodeProc)(void *Object,void *IrrParentObject);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_GetSceneManager;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_GETSCENEMANAGER(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_GETSCENEMANAGER                                    1
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_GETSCENEMANAGER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_GETSCENEMANAGER                                     0

extern void *SRPAPI IrrSceneNodeClass_GetSceneManager(void *Object);
typedef void *(SRPAPI *IrrSceneNodeClass_GetSceneManagerProc)(void *Object);

/*[Private Function] : Manager = Lua_GetSceneManager()    */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_Lua_GetSceneManager;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_LUA_GETSCENEMANAGER(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_LUA_GETSCENEMANAGER                                0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_LUA_GETSCENEMANAGER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_LUA_GETSCENEMANAGER                                 0

extern VS_INT32 SRPAPI IrrSceneNodeClass_Lua_GetSceneManager(void);
typedef VS_INT32 (SRPAPI *IrrSceneNodeClass_Lua_GetSceneManagerProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_SetMaterialTexture;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_SETMATERIALTEXTURE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_SETMATERIALTEXTURE                                 0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_SETMATERIALTEXTURE(X)  {{X[0].Type=7;}{X[1].Type=14;}}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_SETMATERIALTEXTURE                                  2

extern void SRPAPI IrrSceneNodeClass_SetMaterialTexture(void *Object,VS_UINT32 TextureLayer,void *IrrTexture);
typedef void (SRPAPI *IrrSceneNodeClass_SetMaterialTextureProc)(void *Object,VS_UINT32 TextureLayer,void *IrrTexture);

/*[Private Function] : Lua_SetMaterialTexture(TextuerLayer,IrrTextuer)    */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_Lua_SetMaterialTexture;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_LUA_SETMATERIALTEXTURE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_LUA_SETMATERIALTEXTURE                             0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_LUA_SETMATERIALTEXTURE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_LUA_SETMATERIALTEXTURE                              0

extern VS_INT32 SRPAPI IrrSceneNodeClass_Lua_SetMaterialTexture(void);
typedef VS_INT32 (SRPAPI *IrrSceneNodeClass_Lua_SetMaterialTextureProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_SetMaterialTextureEx;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_SETMATERIALTEXTUREEX(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_SETMATERIALTEXTUREEX                               0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_SETMATERIALTEXTUREEX(X)  {{X[0].Type=7;}{X[1].Type=30;}}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_SETMATERIALTEXTUREEX                                2

extern void SRPAPI IrrSceneNodeClass_SetMaterialTextureEx(void *Object,VS_UINT32 TextureLayer,VS_CHAR * TextureFile);
typedef void (SRPAPI *IrrSceneNodeClass_SetMaterialTextureExProc)(void *Object,VS_UINT32 TextureLayer,VS_CHAR * TextureFile);

/*[Private Function] : Lua_SetMaterialTextureEx(TextureLayer,TextureFile)    */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_Lua_SetMaterialTextureEx;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_LUA_SETMATERIALTEXTUREEX(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_LUA_SETMATERIALTEXTUREEX                           0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_LUA_SETMATERIALTEXTUREEX(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_LUA_SETMATERIALTEXTUREEX                            0

extern VS_INT32 SRPAPI IrrSceneNodeClass_Lua_SetMaterialTextureEx(void);
typedef VS_INT32 (SRPAPI *IrrSceneNodeClass_Lua_SetMaterialTextureExProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_SetMaterialFlag;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_SETMATERIALFLAG(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_SETMATERIALFLAG                                    0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_SETMATERIALFLAG(X)  {{X[0].Type=6;}{X[1].Type=1;}}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_SETMATERIALFLAG                                     2

extern void SRPAPI IrrSceneNodeClass_SetMaterialFlag(void *Object,VS_INT32 Flag,VS_BOOL NewValue);
typedef void (SRPAPI *IrrSceneNodeClass_SetMaterialFlagProc)(void *Object,VS_INT32 Flag,VS_BOOL NewValue);

/*[Private Function] : Lua_SetMaterialFlag(Flag,Bool NewValue)    */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_Lua_SetMaterialFlag;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_LUA_SETMATERIALFLAG(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_LUA_SETMATERIALFLAG                                0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_LUA_SETMATERIALFLAG(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_LUA_SETMATERIALFLAG                                 0

extern VS_INT32 SRPAPI IrrSceneNodeClass_Lua_SetMaterialFlag(void);
typedef VS_INT32 (SRPAPI *IrrSceneNodeClass_Lua_SetMaterialFlagProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_SetMaterialType;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_SETMATERIALTYPE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_SETMATERIALTYPE                                    0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_SETMATERIALTYPE(X)  {{X[0].Type=6;}}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_SETMATERIALTYPE                                     1

extern void SRPAPI IrrSceneNodeClass_SetMaterialType(void *Object,VS_INT32 NewType);
typedef void (SRPAPI *IrrSceneNodeClass_SetMaterialTypeProc)(void *Object,VS_INT32 NewType);

/*[Private Function] : Lua_SetMaterialType(NewType)    */
extern VS_UUID VSFUNCID_IrrSceneNodeClass_Lua_SetMaterialType;
#define VSFUNCRETURNDEPEND_IRRSCENENODECLASS_LUA_SETMATERIALTYPE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSCENENODECLASS_LUA_SETMATERIALTYPE                                0
#define VSFUNCPARAMDEPEND_IRRSCENENODECLASS_LUA_SETMATERIALTYPE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRSCENENODECLASS_LUA_SETMATERIALTYPE                                 0

extern VS_INT32 SRPAPI IrrSceneNodeClass_Lua_SetMaterialType(void);
typedef VS_INT32 (SRPAPI *IrrSceneNodeClass_Lua_SetMaterialTypeProc)(void);

extern VS_INT32 SRPCALLBACK IrrSceneNodeClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrSceneNodeClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrSceneNodeClass{
};
struct StructOfIrrSceneNodeClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----local attribute
    VS_INT8         Reserve1[3];                  
    struct StructOfSRP3DVector Position;          //
    struct StructOfSRP3DVector Rotation;          //
    struct StructOfSRP3DVector Scale;             //
    VS_BOOL         Visible;                      //
    VS_INT8         Reserve5[3];                  
    VS_INT32        AutomaticCullingState;        //
    VS_INT32        Id;                           //
    void            *SceneNodeList;               //
    void            *MaterialList;                //
    void            *TextureList;                 //
    void            *MeshList;                    //
    void            *AnimatorList;                //
    void            *SelectorList;                //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRSHADERMATERIALTYPECLASS                                                       "IrrShaderMaterialTypeClass"
extern VS_UUID VSOBJID_IrrShaderMaterialTypeClass;
#define VSATTRDEPEND_IRRSHADERMATERIALTYPECLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=51;X[1].Offset=4;}{X[2].Type=51;X[2].Offset=8;}{X[3].Type=51;X[3].Offset=12;}{X[4].Type=6;X[4].Offset=16;}}
#define VSATTRDEPENDNUM_IRRSHADERMATERIALTYPECLASS                                                 5
extern VS_INT32 SRPCALLBACK IrrShaderMaterialTypeClass_RequestRegisterObject( );

/*----output event: OnChange[]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_IrrShaderMaterialTypeClass_OnChange;

/*------Variable Index Define */
#define VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_WRAPIRRFLAG                                         0
#define VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_VERTEXFILENAME                                      1
#define VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_PIXELFILENAME                                       2
#define VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_CALLBACKNAME                                        3
#define VSATTRINDEX_IRRSHADERMATERIALTYPECLASS_BASEMATERIAL                                        4
#define VSATTRNUMBER_IRRSHADERMATERIALTYPECLASS                                                    5

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrShaderMaterialTypeClass_SetMaterialType;
#define VSFUNCRETURNDEPEND_IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE                           0
#define VSFUNCPARAMDEPEND_IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE(X)  {{X[0].Type=6;}}
#define VSFUNCPARAMDEPENDNUM_IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE                            1

extern void SRPAPI IrrShaderMaterialTypeClass_SetMaterialType(void *Object,VS_INT32 Type);
typedef void (SRPAPI *IrrShaderMaterialTypeClass_SetMaterialTypeProc)(void *Object,VS_INT32 Type);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrShaderMaterialTypeClass_GetMaterialType;
#define VSFUNCRETURNDEPEND_IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE(X)  {{X[0].Type=6;}}
#define VSFUNCRETURNDEPENDNUM_IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE                           1
#define VSFUNCPARAMDEPEND_IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE                            0

extern VS_INT32 SRPAPI IrrShaderMaterialTypeClass_GetMaterialType(void *Object);
typedef VS_INT32 (SRPAPI *IrrShaderMaterialTypeClass_GetMaterialTypeProc)(void *Object);

extern VS_INT32 SRPCALLBACK IrrShaderMaterialTypeClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrShaderMaterialTypeClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrShaderMaterialTypeClass{
};
struct StructOfIrrShaderMaterialTypeClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----local attribute
    VS_INT8         Reserve1[3];                  
    VS_VSTRING      VertexFileName;               //
    VS_VSTRING      PixelFileName;                //
    VS_VSTRING      CallBackName;                 //$..ObjectName @..ObjectID
    VS_INT32        BaseMaterial;                 //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRCAMERASCENENODECLASS                                                          "IrrCameraSceneNodeClass"
extern VS_UUID VSOBJID_IrrCameraSceneNodeClass;
#define VSATTRDEPEND_IRRCAMERASCENENODECLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=16;X[1].Offset=4;}{X[2].Type=16;X[2].Offset=16;}{X[3].Type=16;X[3].Offset=28;}{X[4].Type=1;X[4].Offset=40;}{X[5].Type=6;X[5].Offset=44;}{X[6].Type=6;X[6].Offset=48;}{X[7].Type=14;X[7].Offset=52;}{X[8].Type=14;X[8].Offset=56;}{X[9].Type=14;X[9].Offset=60;}{X[10].Type=14;X[10].Offset=64;}{X[11].Type=14;X[11].Offset=68;}{X[12].Type=14;X[12].Offset=72;}{X[13].Type=16;X[13].Offset=76;}{X[14].Type=8;X[14].Offset=88;}{X[15].Type=8;X[15].Offset=92;}}
#define VSATTRDEPENDNUM_IRRCAMERASCENENODECLASS                                                    16
extern VS_INT32 SRPCALLBACK IrrCameraSceneNodeClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_WRAPIRRFLAG                                            0
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_POSITION                                               1
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_ROTATION                                               2
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_SCALE                                                  3
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_VISIBLE                                                4
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_AUTOMATICCULLINGSTATE                                  5
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_ID                                                     6
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_SCENENODELIST                                          7
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_MATERIALLIST                                           8
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_TEXTURELIST                                            9
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_MESHLIST                                               10
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_ANIMATORLIST                                           11
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_SELECTORLIST                                           12
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_TARGET                                                 13
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_ZNEAR                                                  14
#define VSATTRINDEX_IRRCAMERASCENENODECLASS_ZFAR                                                   15
#define VSATTRNUMBER_IRRCAMERASCENENODECLASS                                                       16

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrCameraSceneNodeClass_GetTarget;
#define VSFUNCRETURNDEPEND_IRRCAMERASCENENODECLASS_GETTARGET(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRCAMERASCENENODECLASS_GETTARGET                                    0
#define VSFUNCPARAMDEPEND_IRRCAMERASCENENODECLASS_GETTARGET(X)  {{X[0].Type=35;}}
#define VSFUNCPARAMDEPENDNUM_IRRCAMERASCENENODECLASS_GETTARGET                                     1

extern void SRPAPI IrrCameraSceneNodeClass_GetTarget(void *Object,struct StructOfSRP3DVector * Position);
typedef void (SRPAPI *IrrCameraSceneNodeClass_GetTargetProc)(void *Object,struct StructOfSRP3DVector * Position);

/*[Private Function] : Target=Lua_GetTarget()    */
extern VS_UUID VSFUNCID_IrrCameraSceneNodeClass_Lua_GetTarget;
#define VSFUNCRETURNDEPEND_IRRCAMERASCENENODECLASS_LUA_GETTARGET(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRCAMERASCENENODECLASS_LUA_GETTARGET                                0
#define VSFUNCPARAMDEPEND_IRRCAMERASCENENODECLASS_LUA_GETTARGET(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRCAMERASCENENODECLASS_LUA_GETTARGET                                 0

extern VS_INT32 SRPAPI IrrCameraSceneNodeClass_Lua_GetTarget(void);
typedef VS_INT32 (SRPAPI *IrrCameraSceneNodeClass_Lua_GetTargetProc)(void);

extern VS_INT32 SRPCALLBACK IrrCameraSceneNodeClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrCameraSceneNodeClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrCameraSceneNodeClass{
};
struct StructOfIrrCameraSceneNodeClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----class[IrrSceneNodeClass] attribute
    VS_INT8         Reserve1[3];                  
    struct StructOfSRP3DVector Position;          //
    struct StructOfSRP3DVector Rotation;          //
    struct StructOfSRP3DVector Scale;             //
    VS_BOOL         Visible;                      //
    VS_INT8         Reserve5[3];                  
    VS_INT32        AutomaticCullingState;        //
    VS_INT32        Id;                           //
    void            *SceneNodeList;               //
    void            *MaterialList;                //
    void            *TextureList;                 //
    void            *MeshList;                    //
    void            *AnimatorList;                //
    void            *SelectorList;                //
    //----local attribute
    struct StructOfSRP3DVector Target;            //
    VS_FLOAT        ZNear;                        //
    VS_FLOAT        ZFar;                         //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRDEVICECLASS                                                                   "IrrDeviceClass"
extern VS_UUID VSOBJID_IrrDeviceClass;
#define VSATTRDEPEND_IRRDEVICECLASS(X)  {{X[0].Type=19;X[0].Offset=0;}{X[1].Type=6;X[1].Offset=4;}{X[2].Type=6;X[2].Offset=8;}{X[3].Type=10;X[3].Offset=12;}}
#define VSATTRDEPENDNUM_IRRDEVICECLASS                                                             4
extern VS_INT32 SRPCALLBACK IrrDeviceClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_IRRDEVICECLASS_COLOR                                                           0
#define VSATTRINDEX_IRRDEVICECLASS_WIDTH                                                           1
#define VSATTRINDEX_IRRDEVICECLASS_HEIGHT                                                          2
#define VSATTRINDEX_IRRDEVICECLASS_RENDERWND                                                       3
#define VSATTRNUMBER_IRRDEVICECLASS                                                                4

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrDeviceClass_GetCurDevice;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_GETCURDEVICE(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_GETCURDEVICE                                          1
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_GETCURDEVICE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_GETCURDEVICE                                           0

extern void *SRPAPI IrrDeviceClass_GetCurDevice(void *Object);
typedef void *(SRPAPI *IrrDeviceClass_GetCurDeviceProc)(void *Object);

/*[Private Function] : Driver=Lua_GetCurDevice()    */
extern VS_UUID VSFUNCID_IrrDeviceClass_Lua_GetCurDevice;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_GETCURDEVICE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_GETCURDEVICE                                      0
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_GETCURDEVICE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_GETCURDEVICE                                       0

extern VS_INT32 SRPAPI IrrDeviceClass_Lua_GetCurDevice(void);
typedef VS_INT32 (SRPAPI *IrrDeviceClass_Lua_GetCurDeviceProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrDeviceClass_Render;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_RENDER(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_RENDER                                                0
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_RENDER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_RENDER                                                 0

extern void SRPAPI IrrDeviceClass_Render(void *Object);
typedef void (SRPAPI *IrrDeviceClass_RenderProc)(void *Object);

/*[Private Function] : Driver=Lua_Render()    */
extern VS_UUID VSFUNCID_IrrDeviceClass_Lua_Render;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_RENDER(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_RENDER                                            0
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_RENDER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_RENDER                                             0

extern VS_INT32 SRPAPI IrrDeviceClass_Lua_Render(void);
typedef VS_INT32 (SRPAPI *IrrDeviceClass_Lua_RenderProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrDeviceClass_SetSize;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_SETSIZE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_SETSIZE                                               0
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_SETSIZE(X)  {{X[0].Type=6;}{X[1].Type=6;}}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_SETSIZE                                                2

extern void SRPAPI IrrDeviceClass_SetSize(void *Object,VS_INT32 Width,VS_INT32 Height);
typedef void (SRPAPI *IrrDeviceClass_SetSizeProc)(void *Object,VS_INT32 Width,VS_INT32 Height);

/*[Private Function] : Lua_SetSize(Width,Height)    */
extern VS_UUID VSFUNCID_IrrDeviceClass_Lua_SetSize;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_SETSIZE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_SETSIZE                                           0
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_SETSIZE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_SETSIZE                                            0

extern VS_INT32 SRPAPI IrrDeviceClass_Lua_SetSize(void);
typedef VS_INT32 (SRPAPI *IrrDeviceClass_Lua_SetSizeProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrDeviceClass_GetSceneManager;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_GETSCENEMANAGER(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_GETSCENEMANAGER                                       1
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_GETSCENEMANAGER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_GETSCENEMANAGER                                        0

extern void *SRPAPI IrrDeviceClass_GetSceneManager(void *Object);
typedef void *(SRPAPI *IrrDeviceClass_GetSceneManagerProc)(void *Object);

/*[Private Function] : SceneManager=Lua_GetSceneManager()    */
extern VS_UUID VSFUNCID_IrrDeviceClass_Lua_GetSceneManager;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_GETSCENEMANAGER(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_GETSCENEMANAGER                                   0
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_GETSCENEMANAGER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_GETSCENEMANAGER                                    0

extern VS_INT32 SRPAPI IrrDeviceClass_Lua_GetSceneManager(void);
typedef VS_INT32 (SRPAPI *IrrDeviceClass_Lua_GetSceneManagerProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrDeviceClass_GetVideoDriver;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_GETVIDEODRIVER(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_GETVIDEODRIVER                                        1
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_GETVIDEODRIVER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_GETVIDEODRIVER                                         0

extern void *SRPAPI IrrDeviceClass_GetVideoDriver(void *Object);
typedef void *(SRPAPI *IrrDeviceClass_GetVideoDriverProc)(void *Object);

/*[Private Function] : Driver=Lua_GetVideoDriver()    */
extern VS_UUID VSFUNCID_IrrDeviceClass_Lua_GetVideoDriver;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_GETVIDEODRIVER(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_GETVIDEODRIVER                                    0
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_GETVIDEODRIVER(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_GETVIDEODRIVER                                     0

extern VS_INT32 SRPAPI IrrDeviceClass_Lua_GetVideoDriver(void);
typedef VS_INT32 (SRPAPI *IrrDeviceClass_Lua_GetVideoDriverProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrDeviceClass_GetFileSystem;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_GETFILESYSTEM(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_GETFILESYSTEM                                         1
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_GETFILESYSTEM(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_GETFILESYSTEM                                          0

extern void *SRPAPI IrrDeviceClass_GetFileSystem(void *Object);
typedef void *(SRPAPI *IrrDeviceClass_GetFileSystemProc)(void *Object);

/*[Private Function] : FileSystem=Lua_GetFileSystem()    */
extern VS_UUID VSFUNCID_IrrDeviceClass_Lua_GetFileSystem;
#define VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_GETFILESYSTEM(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_GETFILESYSTEM                                     0
#define VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_GETFILESYSTEM(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_GETFILESYSTEM                                      0

extern VS_INT32 SRPAPI IrrDeviceClass_Lua_GetFileSystem(void);
typedef VS_INT32 (SRPAPI *IrrDeviceClass_Lua_GetFileSystemProc)(void);

extern VS_INT32 SRPCALLBACK IrrDeviceClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrDeviceClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrDeviceClass{
};
struct StructOfIrrDeviceClass{
    //----local attribute
    VS_COLOR        Color;                        //
    VS_INT32        Width;                        //
    VS_INT32        Height;                       //
    VS_ULONG        RenderWnd;                    //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRMATERIALCLASS                                                                 "IrrMaterialClass"
extern VS_UUID VSOBJID_IrrMaterialClass;
#define VSATTRDEPEND_IRRMATERIALCLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=6;X[1].Offset=4;}{X[2].Type=19;X[2].Offset=8;}{X[3].Type=19;X[3].Offset=12;}{X[4].Type=19;X[4].Offset=16;}{X[5].Type=19;X[5].Offset=20;}{X[6].Type=8;X[6].Offset=24;}{X[7].Type=8;X[7].Offset=28;}{X[8].Type=8;X[8].Offset=32;}{X[9].Type=8;X[9].Offset=36;}{X[10].Type=1;X[10].Offset=40;}{X[11].Type=1;X[11].Offset=41;}{X[12].Type=1;X[12].Offset=42;}{X[13].Type=1;X[13].Offset=43;}{X[14].Type=1;X[14].Offset=44;}{X[15].Type=1;X[15].Offset=45;}{X[16].Type=1;X[16].Offset=46;}{X[17].Type=1;X[17].Offset=47;}{X[18].Type=7;X[18].Offset=48;}}
#define VSATTRDEPENDNUM_IRRMATERIALCLASS                                                           19
extern VS_INT32 SRPCALLBACK IrrMaterialClass_RequestRegisterObject( );

/*----output event: OnIrrInit[]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_IrrMaterialClass_OnIrrInit;
/*----output event: OnChange[]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_IrrMaterialClass_OnChange;

/*------Variable Index Define */
#define VSATTRINDEX_IRRMATERIALCLASS_WRAPIRRFLAG                                                   0
#define VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPE                                                  1
#define VSATTRINDEX_IRRMATERIALCLASS_AMBIENTCOLOR                                                  2
#define VSATTRINDEX_IRRMATERIALCLASS_DIFFUSECOLOR                                                  3
#define VSATTRINDEX_IRRMATERIALCLASS_EMISSIVECOLOR                                                 4
#define VSATTRINDEX_IRRMATERIALCLASS_SPECULARCOLOR                                                 5
#define VSATTRINDEX_IRRMATERIALCLASS_SHININESS                                                     6
#define VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPEPARAM                                             7
#define VSATTRINDEX_IRRMATERIALCLASS_MATERIALTYPEPARAM2                                            8
#define VSATTRINDEX_IRRMATERIALCLASS_THICKNESS                                                     9
#define VSATTRINDEX_IRRMATERIALCLASS_WIREFRAME                                                     10
#define VSATTRINDEX_IRRMATERIALCLASS_POINTCLOUD                                                    11
#define VSATTRINDEX_IRRMATERIALCLASS_GOURAUDSHADING                                                12
#define VSATTRINDEX_IRRMATERIALCLASS_LIGHTING                                                      13
#define VSATTRINDEX_IRRMATERIALCLASS_ZWRITEENABLE                                                  14
#define VSATTRINDEX_IRRMATERIALCLASS_BACKFACECULLING                                               15
#define VSATTRINDEX_IRRMATERIALCLASS_FOGENABLE                                                     16
#define VSATTRINDEX_IRRMATERIALCLASS_NORMALIZENORMALS                                              17
#define VSATTRINDEX_IRRMATERIALCLASS_ZBUFFER                                                       18
#define VSATTRNUMBER_IRRMATERIALCLASS                                                              19

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrMaterialClass_SetTexture;
#define VSFUNCRETURNDEPEND_IRRMATERIALCLASS_SETTEXTURE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRMATERIALCLASS_SETTEXTURE                                          0
#define VSFUNCPARAMDEPEND_IRRMATERIALCLASS_SETTEXTURE(X)  {{X[0].Type=7;}{X[1].Type=14;}}
#define VSFUNCPARAMDEPENDNUM_IRRMATERIALCLASS_SETTEXTURE                                           2

extern void SRPAPI IrrMaterialClass_SetTexture(void *Object,VS_UINT32 TextureLayer,void *IrrTexture);
typedef void (SRPAPI *IrrMaterialClass_SetTextureProc)(void *Object,VS_UINT32 TextureLayer,void *IrrTexture);

/*[Private Function] : Lua_SetTexture(TextuerLayer,IrrTextuer)    */
extern VS_UUID VSFUNCID_IrrMaterialClass_Lua_SetTexture;
#define VSFUNCRETURNDEPEND_IRRMATERIALCLASS_LUA_SETTEXTURE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRMATERIALCLASS_LUA_SETTEXTURE                                      0
#define VSFUNCPARAMDEPEND_IRRMATERIALCLASS_LUA_SETTEXTURE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRMATERIALCLASS_LUA_SETTEXTURE                                       0

extern VS_INT32 SRPAPI IrrMaterialClass_Lua_SetTexture(void);
typedef VS_INT32 (SRPAPI *IrrMaterialClass_Lua_SetTextureProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrMaterialClass_SetShaderMaterialType;
#define VSFUNCRETURNDEPEND_IRRMATERIALCLASS_SETSHADERMATERIALTYPE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRMATERIALCLASS_SETSHADERMATERIALTYPE                               0
#define VSFUNCPARAMDEPEND_IRRMATERIALCLASS_SETSHADERMATERIALTYPE(X)  {{X[0].Type=14;}}
#define VSFUNCPARAMDEPENDNUM_IRRMATERIALCLASS_SETSHADERMATERIALTYPE                                1

extern void SRPAPI IrrMaterialClass_SetShaderMaterialType(void *Object,void *ShaderMaterialTypeObject);
typedef void (SRPAPI *IrrMaterialClass_SetShaderMaterialTypeProc)(void *Object,void *ShaderMaterialTypeObject);

/*[Private Function] : Lua_SetShaderMaterialType(ShaderMaterialTypeObject)    */
extern VS_UUID VSFUNCID_IrrMaterialClass_Lua_SetShaderMaterialType;
#define VSFUNCRETURNDEPEND_IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE                           0
#define VSFUNCPARAMDEPEND_IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE                            0

extern VS_INT32 SRPAPI IrrMaterialClass_Lua_SetShaderMaterialType(void);
typedef VS_INT32 (SRPAPI *IrrMaterialClass_Lua_SetShaderMaterialTypeProc)(void);

extern VS_INT32 SRPCALLBACK IrrMaterialClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrMaterialClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrMaterialClass{
};
struct StructOfIrrMaterialClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----local attribute
    VS_INT8         Reserve1[3];                  
    VS_INT32        MaterialType;                 //
    VS_COLOR        AmbientColor;                 //
    VS_COLOR        DiffuseColor;                 //
    VS_COLOR        EmissiveColor;                //
    VS_COLOR        SpecularColor;                //
    VS_FLOAT        Shininess;                    //
    VS_FLOAT        MaterialTypeParam;            //
    VS_FLOAT        MaterialTypeParam2;           //
    VS_FLOAT        Thickness;                    //
    VS_BOOL         Wireframe;                    //
    VS_BOOL         PointCloud;                   //
    VS_BOOL         GouraudShading;               //
    VS_BOOL         Lighting;                     //
    VS_BOOL         ZWriteEnable;                 //
    VS_BOOL         BackfaceCulling;              //
    VS_BOOL         FogEnable;                    //
    VS_BOOL         NormalizeNormals;             //
    VS_UINT32       ZBuffer;                      //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRANIMATEDMESHCLASS                                                             "IrrAnimatedMeshClass"
extern VS_UUID VSOBJID_IrrAnimatedMeshClass;
#define VSATTRDEPEND_IRRANIMATEDMESHCLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=51;X[1].Offset=4;}{X[2].Type=1;X[2].Offset=8;}}
#define VSATTRDEPENDNUM_IRRANIMATEDMESHCLASS                                                       3
extern VS_INT32 SRPCALLBACK IrrAnimatedMeshClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_IRRANIMATEDMESHCLASS_WRAPIRRFLAG                                               0
#define VSATTRINDEX_IRRANIMATEDMESHCLASS_MESHFILE                                                  1
#define VSATTRINDEX_IRRANIMATEDMESHCLASS_LOADRESULT                                                2
#define VSATTRNUMBER_IRRANIMATEDMESHCLASS                                                          3

/*------Local Define Function */
/*[Public Function] :     */
extern VS_UUID VSFUNCID_IrrAnimatedMeshClass_OnBeforeCreate;
#define VSFUNCRETURNDEPEND_IRRANIMATEDMESHCLASS_ONBEFORECREATE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHCLASS_ONBEFORECREATE                                  0
#define VSFUNCPARAMDEPEND_IRRANIMATEDMESHCLASS_ONBEFORECREATE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHCLASS_ONBEFORECREATE                                   0

extern void SRPAPI IrrAnimatedMeshClass_OnBeforeCreate(void *Object);
typedef void (SRPAPI *IrrAnimatedMeshClass_OnBeforeCreateProc)(void *Object);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrAnimatedMeshClass_OnAfterCreate;
#define VSFUNCRETURNDEPEND_IRRANIMATEDMESHCLASS_ONAFTERCREATE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHCLASS_ONAFTERCREATE                                   0
#define VSFUNCPARAMDEPEND_IRRANIMATEDMESHCLASS_ONAFTERCREATE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHCLASS_ONAFTERCREATE                                    0

extern void SRPAPI IrrAnimatedMeshClass_OnAfterCreate(void *Object);
typedef void (SRPAPI *IrrAnimatedMeshClass_OnAfterCreateProc)(void *Object);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrAnimatedMeshClass_GetMesh;
#define VSFUNCRETURNDEPEND_IRRANIMATEDMESHCLASS_GETMESH(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHCLASS_GETMESH                                         1
#define VSFUNCPARAMDEPEND_IRRANIMATEDMESHCLASS_GETMESH(X)  {{X[0].Type=14;}{X[1].Type=6;}{X[2].Type=6;}{X[3].Type=6;}{X[4].Type=6;}}
#define VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHCLASS_GETMESH                                          5

extern void *SRPAPI IrrAnimatedMeshClass_GetMesh(void *Object,void *MeshObject,VS_INT32 Frame,VS_INT32 DetailLevel,VS_INT32 StartFrameLoop,VS_INT32 EndFrameLoop);
typedef void *(SRPAPI *IrrAnimatedMeshClass_GetMeshProc)(void *Object,void *MeshObject,VS_INT32 Frame,VS_INT32 DetailLevel,VS_INT32 StartFrameLoop,VS_INT32 EndFrameLoop);

/*[Private Function] : MeshObject = Lua_GetMesh(MeshObject,Frame,DetailLevel,StartFrameLoop,EndFrameLoop)    */
extern VS_UUID VSFUNCID_IrrAnimatedMeshClass_Lua_GetMesh;
#define VSFUNCRETURNDEPEND_IRRANIMATEDMESHCLASS_LUA_GETMESH(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHCLASS_LUA_GETMESH                                     0
#define VSFUNCPARAMDEPEND_IRRANIMATEDMESHCLASS_LUA_GETMESH(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHCLASS_LUA_GETMESH                                      0

extern VS_INT32 SRPAPI IrrAnimatedMeshClass_Lua_GetMesh(void);
typedef VS_INT32 (SRPAPI *IrrAnimatedMeshClass_Lua_GetMeshProc)(void);

extern VS_INT32 SRPCALLBACK IrrAnimatedMeshClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrAnimatedMeshClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrAnimatedMeshClass{
};
struct StructOfIrrAnimatedMeshClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----class[IrrMeshClass] attribute
    VS_INT8         Reserve1[3];                  
    VS_VSTRING      MeshFile;                     //
    VS_BOOL         LoadResult;                   //
    VS_INT8         Reserve3[3];                  
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRROBJECTCLASS                                                                   "IrrObjectClass"
extern VS_UUID VSOBJID_IrrObjectClass;
#define VSATTRDEPEND_IRROBJECTCLASS(X)  {{X[0].Type=1;X[0].Offset=0;}}
#define VSATTRDEPENDNUM_IRROBJECTCLASS                                                             1
extern VS_INT32 SRPCALLBACK IrrObjectClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_IRROBJECTCLASS_WRAPIRRFLAG                                                     0
#define VSATTRNUMBER_IRROBJECTCLASS                                                                1

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrObjectClass_SetIrrObject;
#define VSFUNCRETURNDEPEND_IRROBJECTCLASS_SETIRROBJECT(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRROBJECTCLASS_SETIRROBJECT                                          0
#define VSFUNCPARAMDEPEND_IRROBJECTCLASS_SETIRROBJECT(X)  {{X[0].Type=14;}}
#define VSFUNCPARAMDEPENDNUM_IRROBJECTCLASS_SETIRROBJECT                                           1

extern void SRPAPI IrrObjectClass_SetIrrObject(void *Object,void *IrrObject);
typedef void (SRPAPI *IrrObjectClass_SetIrrObjectProc)(void *Object,void *IrrObject);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrObjectClass_GetIrrObject;
#define VSFUNCRETURNDEPEND_IRROBJECTCLASS_GETIRROBJECT(X)  {{X[0].Type=14;}}
#define VSFUNCRETURNDEPENDNUM_IRROBJECTCLASS_GETIRROBJECT                                          1
#define VSFUNCPARAMDEPEND_IRROBJECTCLASS_GETIRROBJECT(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRROBJECTCLASS_GETIRROBJECT                                           0

extern void *SRPAPI IrrObjectClass_GetIrrObject(void *Object);
typedef void *(SRPAPI *IrrObjectClass_GetIrrObjectProc)(void *Object);

/*[Public Function] :     */
extern VS_UUID VSFUNCID_IrrObjectClass_SetIrrParentSceneNode;
#define VSFUNCRETURNDEPEND_IRROBJECTCLASS_SETIRRPARENTSCENENODE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRROBJECTCLASS_SETIRRPARENTSCENENODE                                 0
#define VSFUNCPARAMDEPEND_IRROBJECTCLASS_SETIRRPARENTSCENENODE(X)  {{X[0].Type=14;}}
#define VSFUNCPARAMDEPENDNUM_IRROBJECTCLASS_SETIRRPARENTSCENENODE                                  1

extern void SRPAPI IrrObjectClass_SetIrrParentSceneNode(void *Object,void *IrrParentObject);
typedef void (SRPAPI *IrrObjectClass_SetIrrParentSceneNodeProc)(void *Object,void *IrrParentObject);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrObjectClass_OnIrrActivating;
#define VSFUNCRETURNDEPEND_IRROBJECTCLASS_ONIRRACTIVATING(X)  {{X[0].Type=1;}}
#define VSFUNCRETURNDEPENDNUM_IRROBJECTCLASS_ONIRRACTIVATING                                       1
#define VSFUNCPARAMDEPEND_IRROBJECTCLASS_ONIRRACTIVATING(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRROBJECTCLASS_ONIRRACTIVATING                                        0

extern VS_BOOL SRPAPI IrrObjectClass_OnIrrActivating(void *Object);
typedef VS_BOOL (SRPAPI *IrrObjectClass_OnIrrActivatingProc)(void *Object);

extern VS_INT32 SRPCALLBACK IrrObjectClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrObjectClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrObjectClass{
};
struct StructOfIrrObjectClass{
    //----local attribute
    VS_BOOL         WrapIrrFlag;                  //
    VS_INT8         Reserve1[3];                  
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRTEXTURECLASS                                                                  "IrrTextureClass"
extern VS_UUID VSOBJID_IrrTextureClass;
#define VSATTRDEPEND_IRRTEXTURECLASS(X)  {{X[0].Type=1;X[0].Offset=0;}{X[1].Type=51;X[1].Offset=4;}{X[2].Type=1;X[2].Offset=8;}}
#define VSATTRDEPENDNUM_IRRTEXTURECLASS                                                            3
extern VS_INT32 SRPCALLBACK IrrTextureClass_RequestRegisterObject( );

/*----output event: OnChange[]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_IrrTextureClass_OnChange;

/*------Variable Index Define */
#define VSATTRINDEX_IRRTEXTURECLASS_WRAPIRRFLAG                                                    0
#define VSATTRINDEX_IRRTEXTURECLASS_TEXTUREFILE                                                    1
#define VSATTRINDEX_IRRTEXTURECLASS_LOADRESULT                                                     2
#define VSATTRNUMBER_IRRTEXTURECLASS                                                               3

/*------Local Define Function */
/*[Public Function] :     */
extern VS_UUID VSFUNCID_IrrTextureClass_OnBeforeCreate;
#define VSFUNCRETURNDEPEND_IRRTEXTURECLASS_ONBEFORECREATE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_ONBEFORECREATE                                       0
#define VSFUNCPARAMDEPEND_IRRTEXTURECLASS_ONBEFORECREATE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_ONBEFORECREATE                                        0

extern void SRPAPI IrrTextureClass_OnBeforeCreate(void *Object);
typedef void (SRPAPI *IrrTextureClass_OnBeforeCreateProc)(void *Object);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrTextureClass_OnAfterCreate;
#define VSFUNCRETURNDEPEND_IRRTEXTURECLASS_ONAFTERCREATE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_ONAFTERCREATE                                        0
#define VSFUNCPARAMDEPEND_IRRTEXTURECLASS_ONAFTERCREATE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_ONAFTERCREATE                                         0

extern void SRPAPI IrrTextureClass_OnAfterCreate(void *Object);
typedef void (SRPAPI *IrrTextureClass_OnAfterCreateProc)(void *Object);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrTextureClass_TriggerChangeEvent;
#define VSFUNCRETURNDEPEND_IRRTEXTURECLASS_TRIGGERCHANGEEVENT(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_TRIGGERCHANGEEVENT                                   0
#define VSFUNCPARAMDEPEND_IRRTEXTURECLASS_TRIGGERCHANGEEVENT(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_TRIGGERCHANGEEVENT                                    0

extern void SRPAPI IrrTextureClass_TriggerChangeEvent(void *Object);
typedef void (SRPAPI *IrrTextureClass_TriggerChangeEventProc)(void *Object);

/*[Private Function] : Lua_TriggerChangeEvent()    */
extern VS_UUID VSFUNCID_IrrTextureClass_Lua_TriggerChangeEvent;
#define VSFUNCRETURNDEPEND_IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT                               0
#define VSFUNCPARAMDEPEND_IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT                                0

extern VS_INT32 SRPAPI IrrTextureClass_Lua_TriggerChangeEvent(void);
typedef VS_INT32 (SRPAPI *IrrTextureClass_Lua_TriggerChangeEventProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrTextureClass_SetIrrTexture;
#define VSFUNCRETURNDEPEND_IRRTEXTURECLASS_SETIRRTEXTURE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_SETIRRTEXTURE                                        0
#define VSFUNCPARAMDEPEND_IRRTEXTURECLASS_SETIRRTEXTURE(X)  {{X[0].Type=14;}}
#define VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_SETIRRTEXTURE                                         1

extern void SRPAPI IrrTextureClass_SetIrrTexture(void *Object,void *IrrTexturePtr);
typedef void (SRPAPI *IrrTextureClass_SetIrrTextureProc)(void *Object,void *IrrTexturePtr);

extern VS_INT32 SRPCALLBACK IrrTextureClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrTextureClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrTextureClass{
};
struct StructOfIrrTextureClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    //----local attribute
    VS_INT8         Reserve1[3];                  
    VS_VSTRING      TextureFile;                  //
    VS_BOOL         LoadResult;                   //
    VS_INT8         Reserve3[3];                  
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRFILESYSTEMCLASS                                                               "IrrFileSystemClass"
extern VS_UUID VSOBJID_IrrFileSystemClass;
#define VSATTRDEPEND_IRRFILESYSTEMCLASS(X)  {{X[0].Type=1;X[0].Offset=0;}}
#define VSATTRDEPENDNUM_IRRFILESYSTEMCLASS                                                         1
extern VS_INT32 SRPCALLBACK IrrFileSystemClass_RequestRegisterObject( );

/*----output event: OnFileSystemChange[]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_IrrFileSystemClass_OnFileSystemChange;

/*------Variable Index Define */
#define VSATTRINDEX_IRRFILESYSTEMCLASS_WRAPIRRFLAG                                                 0
#define VSATTRNUMBER_IRRFILESYSTEMCLASS                                                            1

/*------Local Define Function */
/*[Private Function] :     */
extern VS_UUID VSFUNCID_IrrFileSystemClass_AddZipFileArchive;
#define VSFUNCRETURNDEPEND_IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE                                 0
#define VSFUNCPARAMDEPEND_IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE(X)  {{X[0].Type=30;}}
#define VSFUNCPARAMDEPENDNUM_IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE                                  1

extern void SRPAPI IrrFileSystemClass_AddZipFileArchive(void *Object,VS_CHAR * FileName);
typedef void (SRPAPI *IrrFileSystemClass_AddZipFileArchiveProc)(void *Object,VS_CHAR * FileName);

/*[Private Function] : Lua_AddZipFileArchive(FileName)    */
extern VS_UUID VSFUNCID_IrrFileSystemClass_Lua_AddZipFileArchive;
#define VSFUNCRETURNDEPEND_IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE(X)  {}
#define VSFUNCRETURNDEPENDNUM_IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE                             0
#define VSFUNCPARAMDEPEND_IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE(X)  {}
#define VSFUNCPARAMDEPENDNUM_IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE                              0

extern VS_INT32 SRPAPI IrrFileSystemClass_Lua_AddZipFileArchive(void);
typedef VS_INT32 (SRPAPI *IrrFileSystemClass_Lua_AddZipFileArchiveProc)(void);

extern VS_INT32 SRPCALLBACK IrrFileSystemClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrFileSystemClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrFileSystemClass{
};
struct StructOfIrrFileSystemClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    VS_INT8         Reserve1[3];                  
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_IRRVIDEODRIVERCLASS                                                              "IrrVideoDriverClass"
extern VS_UUID VSOBJID_IrrVideoDriverClass;
#define VSATTRDEPEND_IRRVIDEODRIVERCLASS(X)  {{X[0].Type=1;X[0].Offset=0;}}
#define VSATTRDEPENDNUM_IRRVIDEODRIVERCLASS                                                        1
extern VS_INT32 SRPCALLBACK IrrVideoDriverClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_IRRVIDEODRIVERCLASS_WRAPIRRFLAG                                                0
#define VSATTRNUMBER_IRRVIDEODRIVERCLASS                                                           1

extern VS_INT32 SRPCALLBACK IrrVideoDriverClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK IrrVideoDriverClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachIrrVideoDriverClass{
};
struct StructOfIrrVideoDriverClass{
    //----class[IrrObjectClass] attribute
    VS_BOOL         WrapIrrFlag;                  //
    VS_INT8         Reserve1[3];                  
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
//#define VSOBJNAME_BASICSERVICEITEM                                                                 "BasicServiceItem"
//UUID VSOBJID_BasicServiceItem;
/*--------------------------------------------------*/
extern class ClassOfSRPInterface *pSRP;
extern VS_INT32 SRPProgramType;
extern VS_HANDLE SRPModuleHandle;

#pragma pack()

#endif
