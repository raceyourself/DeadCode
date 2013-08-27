/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrAnimatedMeshSceneNodeClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRANIMATEDMESHSCENENODECLASS_OBJECT_DEPENDINDEX                                             0x00000001
#define IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP_FUNCRETURN_DEPENDINDEX                            0X00000002
#define IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP_FUNCPARAM_DEPENDINDEX                             0X00000003
#define IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP_FUNCRETURN_DEPENDINDEX                        0X00000004
#define IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP_FUNCPARAM_DEPENDINDEX                         0X00000005
#define IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED_FUNCRETURN_DEPENDINDEX                       0X00000006
#define IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED_FUNCPARAM_DEPENDINDEX                        0X00000007
#define IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED_FUNCRETURN_DEPENDINDEX                   0X00000008
#define IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED_FUNCPARAM_DEPENDINDEX                    0X00000009

VS_INT32 SRPCALLBACK IrrAnimatedMeshSceneNodeClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrAnimatedMeshSceneNodeClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRANIMATEDMESHSCENENODECLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrAnimatedMeshSceneNodeClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshSceneNodeClass_SetFrameLoop,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshSceneNodeClass_SetFrameLoop,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshSceneNodeClass_Lua_SetFrameLoop,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshSceneNodeClass_Lua_SetFrameLoop,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshSceneNodeClass_SetAnimationSpeed,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshSceneNodeClass_SetAnimationSpeed,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshSceneNodeClass_Lua_SetAnimationSpeed,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshSceneNodeClass_Lua_SetAnimationSpeed,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRANIMATEDMESHSCENENODECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRANIMATEDMESHSCENENODECLASS_SETFRAMELOOP_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,VSFUNCID_IrrAnimatedMeshSceneNodeClass_SetFrameLoop,(void *)IrrAnimatedMeshSceneNodeClass_SetFrameLoop,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRANIMATEDMESHSCENENODECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRANIMATEDMESHSCENENODECLASS_LUA_SETFRAMELOOP_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,VSFUNCID_IrrAnimatedMeshSceneNodeClass_Lua_SetFrameLoop,(void *)IrrAnimatedMeshSceneNodeClass_Lua_SetFrameLoop,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRANIMATEDMESHSCENENODECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRANIMATEDMESHSCENENODECLASS_SETANIMATIONSPEED_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,VSFUNCID_IrrAnimatedMeshSceneNodeClass_SetAnimationSpeed,(void *)IrrAnimatedMeshSceneNodeClass_SetAnimationSpeed,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRANIMATEDMESHSCENENODECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRANIMATEDMESHSCENENODECLASS_LUA_SETANIMATIONSPEED_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,VSFUNCID_IrrAnimatedMeshSceneNodeClass_Lua_SetAnimationSpeed,(void *)IrrAnimatedMeshSceneNodeClass_Lua_SetAnimationSpeed,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRANIMATEDMESHSCENENODECLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,(void *)IrrAnimatedMeshSceneNodeClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshSceneNodeClass,(void *)IrrAnimatedMeshSceneNodeClass_QueryObjectInfo);

    return 0;
}

