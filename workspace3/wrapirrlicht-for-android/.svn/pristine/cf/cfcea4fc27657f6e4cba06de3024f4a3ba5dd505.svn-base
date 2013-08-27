/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrAnimatedMeshClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRANIMATEDMESHCLASS_OBJECT_DEPENDINDEX                                                      0x00000001
#define IRRANIMATEDMESHCLASS_ONBEFORECREATE_FUNCRETURN_DEPENDINDEX                                   0X00000002
#define IRRANIMATEDMESHCLASS_ONBEFORECREATE_FUNCPARAM_DEPENDINDEX                                    0X00000003
#define IRRANIMATEDMESHCLASS_ONAFTERCREATE_FUNCRETURN_DEPENDINDEX                                    0X00000004
#define IRRANIMATEDMESHCLASS_ONAFTERCREATE_FUNCPARAM_DEPENDINDEX                                     0X00000005
#define IRRANIMATEDMESHCLASS_GETMESH_FUNCRETURN_DEPENDINDEX                                          0X00000006
#define IRRANIMATEDMESHCLASS_GETMESH_FUNCPARAM_DEPENDINDEX                                           0X00000007
#define IRRANIMATEDMESHCLASS_LUA_GETMESH_FUNCRETURN_DEPENDINDEX                                      0X00000008
#define IRRANIMATEDMESHCLASS_LUA_GETMESH_FUNCPARAM_DEPENDINDEX                                       0X00000009

VS_INT32 SRPCALLBACK IrrAnimatedMeshClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrAnimatedMeshClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRANIMATEDMESHCLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrAnimatedMeshClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRANIMATEDMESHCLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRANIMATEDMESHCLASS_ONBEFORECREATE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_ONBEFORECREATE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshClass_OnBeforeCreate,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHCLASS_ONBEFORECREATE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRANIMATEDMESHCLASS_ONBEFORECREATE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_ONBEFORECREATE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshClass_OnBeforeCreate,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHCLASS_ONBEFORECREATE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRANIMATEDMESHCLASS_ONAFTERCREATE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_ONAFTERCREATE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshClass_OnAfterCreate,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHCLASS_ONAFTERCREATE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRANIMATEDMESHCLASS_ONAFTERCREATE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_ONAFTERCREATE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshClass_OnAfterCreate,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHCLASS_ONAFTERCREATE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRANIMATEDMESHCLASS_GETMESH(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_GETMESH_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshClass_GetMesh,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHCLASS_GETMESH,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRANIMATEDMESHCLASS_GETMESH(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_GETMESH_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshClass_GetMesh,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHCLASS_GETMESH,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRANIMATEDMESHCLASS_LUA_GETMESH(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_LUA_GETMESH_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshClass_Lua_GetMesh,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRANIMATEDMESHCLASS_LUA_GETMESH,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRANIMATEDMESHCLASS_LUA_GETMESH(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,IRRANIMATEDMESHCLASS_LUA_GETMESH_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrAnimatedMeshClass_Lua_GetMesh,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRANIMATEDMESHCLASS_LUA_GETMESH,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRANIMATEDMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRANIMATEDMESHCLASS_ONBEFORECREATE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRANIMATEDMESHCLASS_ONBEFORECREATE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,VSFUNCID_IrrAnimatedMeshClass_OnBeforeCreate,(void *)IrrAnimatedMeshClass_OnBeforeCreate,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRANIMATEDMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRANIMATEDMESHCLASS_ONAFTERCREATE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRANIMATEDMESHCLASS_ONAFTERCREATE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,VSFUNCID_IrrAnimatedMeshClass_OnAfterCreate,(void *)IrrAnimatedMeshClass_OnAfterCreate,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRANIMATEDMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRANIMATEDMESHCLASS_GETMESH_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRANIMATEDMESHCLASS_GETMESH_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,VSFUNCID_IrrAnimatedMeshClass_GetMesh,(void *)IrrAnimatedMeshClass_GetMesh,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRANIMATEDMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRANIMATEDMESHCLASS_LUA_GETMESH_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRANIMATEDMESHCLASS_LUA_GETMESH_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,VSFUNCID_IrrAnimatedMeshClass_Lua_GetMesh,(void *)IrrAnimatedMeshClass_Lua_GetMesh,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRANIMATEDMESHCLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,(void *)IrrAnimatedMeshClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrAnimatedMeshClass,(void *)IrrAnimatedMeshClass_QueryObjectInfo);

    return 0;
}

