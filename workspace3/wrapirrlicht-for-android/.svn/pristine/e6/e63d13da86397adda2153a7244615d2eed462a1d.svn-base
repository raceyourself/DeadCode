/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrMeshClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRMESHCLASS_OBJECT_DEPENDINDEX                                                              0x00000001
#define IRRMESHCLASS_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX                                       0X00000002
#define IRRMESHCLASS_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX                                        0X00000003
#define IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX                                   0X00000004
#define IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX                                    0X00000005
#define IRRMESHCLASS_GETMESHBUFFERCOUNT_FUNCRETURN_DEPENDINDEX                                       0X00000006
#define IRRMESHCLASS_GETMESHBUFFERCOUNT_FUNCPARAM_DEPENDINDEX                                        0X00000007
#define IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT_FUNCRETURN_DEPENDINDEX                                   0X00000008
#define IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT_FUNCPARAM_DEPENDINDEX                                    0X00000009
#define IRRMESHCLASS_GETMESHBUFFER_FUNCRETURN_DEPENDINDEX                                            0X0000000A
#define IRRMESHCLASS_GETMESHBUFFER_FUNCPARAM_DEPENDINDEX                                             0X0000000B
#define IRRMESHCLASS_LUA_GETMESHBUFFER_FUNCRETURN_DEPENDINDEX                                        0X0000000C
#define IRRMESHCLASS_LUA_GETMESHBUFFER_FUNCPARAM_DEPENDINDEX                                         0X0000000D

VS_INT32 SRPCALLBACK IrrMeshClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
{
    VSObjectModuleInfo -> ObjectVersion = 0;
    VSObjectModuleInfo -> ObjectSubVersion = 0;
    VSObjectModuleInfo -> ObjcetBugFixVersion = 0;
    VSObjectModuleInfo -> VSVersion = 0;
    VSObjectModuleInfo -> VSSubVersion = 0;

    VSObjectModuleInfo -> CreateTime.wYear = 2012;
    VSObjectModuleInfo -> CreateTime.wMonth = 2;
    VSObjectModuleInfo -> CreateTime.wDay = 15;
    VSObjectModuleInfo -> UpdateTime.wYear = 2012;
    VSObjectModuleInfo -> UpdateTime.wMonth = 2;
    VSObjectModuleInfo -> UpdateTime.wDay = 15;

    strcpy( VSObjectModuleInfo -> AuthorityInfo, "" );
    strcpy( VSObjectModuleInfo -> LicenseInfo, "" );
    strcpy( VSObjectModuleInfo -> ExtendInfo, "" );

    return 0;
}

VS_INT32 SRPCALLBACK IrrMeshClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRMESHCLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrMeshClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRMESHCLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRMESHCLASS_TRIGGERCHANGEEVENT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMeshClass_TriggerChangeEvent,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_TRIGGERCHANGEEVENT,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMESHCLASS_TRIGGERCHANGEEVENT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMeshClass_TriggerChangeEvent,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_TRIGGERCHANGEEVENT,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMeshClass_Lua_TriggerChangeEvent,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMeshClass_Lua_TriggerChangeEvent,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRMESHCLASS_GETMESHBUFFERCOUNT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_GETMESHBUFFERCOUNT_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMeshClass_GetMeshBufferCount,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_GETMESHBUFFERCOUNT,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMESHCLASS_GETMESHBUFFERCOUNT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_GETMESHBUFFERCOUNT_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMeshClass_GetMeshBufferCount,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_GETMESHBUFFERCOUNT,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMeshClass_Lua_GetMeshBufferCount,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMeshClass_Lua_GetMeshBufferCount,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRMESHCLASS_GETMESHBUFFER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_GETMESHBUFFER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMeshClass_GetMeshBuffer,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_GETMESHBUFFER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMESHCLASS_GETMESHBUFFER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_GETMESHBUFFER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMeshClass_GetMeshBuffer,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_GETMESHBUFFER,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRMESHCLASS_LUA_GETMESHBUFFER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_LUA_GETMESHBUFFER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMeshClass_Lua_GetMeshBuffer,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMESHCLASS_LUA_GETMESHBUFFER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMESHCLASS_LUA_GETMESHBUFFER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,IRRMESHCLASS_LUA_GETMESHBUFFER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMeshClass_Lua_GetMeshBuffer,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMESHCLASS_LUA_GETMESHBUFFER,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMESHCLASS_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMESHCLASS_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,VSFUNCID_IrrMeshClass_TriggerChangeEvent,(void *)IrrMeshClass_TriggerChangeEvent,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMESHCLASS_LUA_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,VSFUNCID_IrrMeshClass_Lua_TriggerChangeEvent,(void *)IrrMeshClass_Lua_TriggerChangeEvent,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMESHCLASS_GETMESHBUFFERCOUNT_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMESHCLASS_GETMESHBUFFERCOUNT_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,VSFUNCID_IrrMeshClass_GetMeshBufferCount,(void *)IrrMeshClass_GetMeshBufferCount,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMESHCLASS_LUA_GETMESHBUFFERCOUNT_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,VSFUNCID_IrrMeshClass_Lua_GetMeshBufferCount,(void *)IrrMeshClass_Lua_GetMeshBufferCount,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMESHCLASS_GETMESHBUFFER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMESHCLASS_GETMESHBUFFER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,VSFUNCID_IrrMeshClass_GetMeshBuffer,(void *)IrrMeshClass_GetMeshBuffer,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMESHCLASS_LUA_GETMESHBUFFER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMESHCLASS_LUA_GETMESHBUFFER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,VSFUNCID_IrrMeshClass_Lua_GetMeshBuffer,(void *)IrrMeshClass_Lua_GetMeshBuffer,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRMESHCLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,(void *)IrrMeshClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMeshClass,(void *)IrrMeshClass_QueryObjectInfo);

    return 0;
}

