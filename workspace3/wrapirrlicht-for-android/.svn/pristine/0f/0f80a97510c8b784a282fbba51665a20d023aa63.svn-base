/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrCameraSceneNodeClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRCAMERASCENENODECLASS_OBJECT_DEPENDINDEX                                                   0x00000001
#define IRRCAMERASCENENODECLASS_GETTARGET_FUNCRETURN_DEPENDINDEX                                     0X00000002
#define IRRCAMERASCENENODECLASS_GETTARGET_FUNCPARAM_DEPENDINDEX                                      0X00000003
#define IRRCAMERASCENENODECLASS_LUA_GETTARGET_FUNCRETURN_DEPENDINDEX                                 0X00000004
#define IRRCAMERASCENENODECLASS_LUA_GETTARGET_FUNCPARAM_DEPENDINDEX                                  0X00000005

VS_INT32 SRPCALLBACK IrrCameraSceneNodeClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrCameraSceneNodeClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRCAMERASCENENODECLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,IRRCAMERASCENENODECLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrCameraSceneNodeClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRCAMERASCENENODECLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRCAMERASCENENODECLASS_GETTARGET(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,IRRCAMERASCENENODECLASS_GETTARGET_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrCameraSceneNodeClass_GetTarget,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRCAMERASCENENODECLASS_GETTARGET,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRCAMERASCENENODECLASS_GETTARGET(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,IRRCAMERASCENENODECLASS_GETTARGET_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrCameraSceneNodeClass_GetTarget,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRCAMERASCENENODECLASS_GETTARGET,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRCAMERASCENENODECLASS_LUA_GETTARGET(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,IRRCAMERASCENENODECLASS_LUA_GETTARGET_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrCameraSceneNodeClass_Lua_GetTarget,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRCAMERASCENENODECLASS_LUA_GETTARGET,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRCAMERASCENENODECLASS_LUA_GETTARGET(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,IRRCAMERASCENENODECLASS_LUA_GETTARGET_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrCameraSceneNodeClass_Lua_GetTarget,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRCAMERASCENENODECLASS_LUA_GETTARGET,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRCAMERASCENENODECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRCAMERASCENENODECLASS_GETTARGET_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRCAMERASCENENODECLASS_GETTARGET_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,VSFUNCID_IrrCameraSceneNodeClass_GetTarget,(void *)IrrCameraSceneNodeClass_GetTarget,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRCAMERASCENENODECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRCAMERASCENENODECLASS_LUA_GETTARGET_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRCAMERASCENENODECLASS_LUA_GETTARGET_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,VSFUNCID_IrrCameraSceneNodeClass_Lua_GetTarget,(void *)IrrCameraSceneNodeClass_Lua_GetTarget,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRCAMERASCENENODECLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,(void *)IrrCameraSceneNodeClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrCameraSceneNodeClass,(void *)IrrCameraSceneNodeClass_QueryObjectInfo);

    return 0;
}

