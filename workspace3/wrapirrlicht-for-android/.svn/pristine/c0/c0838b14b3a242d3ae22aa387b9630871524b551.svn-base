/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrQ3LevelMeshClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRQ3LEVELMESHCLASS_OBJECT_DEPENDINDEX                                                       0x00000001
#define IRRQ3LEVELMESHCLASS_GETSHADER_FUNCRETURN_DEPENDINDEX                                         0X00000002
#define IRRQ3LEVELMESHCLASS_GETSHADER_FUNCPARAM_DEPENDINDEX                                          0X00000003
#define IRRQ3LEVELMESHCLASS_LUA_GETSHADER_FUNCRETURN_DEPENDINDEX                                     0X00000004
#define IRRQ3LEVELMESHCLASS_LUA_GETSHADER_FUNCPARAM_DEPENDINDEX                                      0X00000005

VS_INT32 SRPCALLBACK IrrQ3LevelMeshClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrQ3LevelMeshClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRQ3LEVELMESHCLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,IRRQ3LEVELMESHCLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrQ3LevelMeshClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRQ3LEVELMESHCLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRQ3LEVELMESHCLASS_GETSHADER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,IRRQ3LEVELMESHCLASS_GETSHADER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrQ3LevelMeshClass_GetShader,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRQ3LEVELMESHCLASS_GETSHADER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRQ3LEVELMESHCLASS_GETSHADER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,IRRQ3LEVELMESHCLASS_GETSHADER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrQ3LevelMeshClass_GetShader,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRQ3LEVELMESHCLASS_GETSHADER,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRQ3LEVELMESHCLASS_LUA_GETSHADER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,IRRQ3LEVELMESHCLASS_LUA_GETSHADER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrQ3LevelMeshClass_Lua_GetShader,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRQ3LEVELMESHCLASS_LUA_GETSHADER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRQ3LEVELMESHCLASS_LUA_GETSHADER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,IRRQ3LEVELMESHCLASS_LUA_GETSHADER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrQ3LevelMeshClass_Lua_GetShader,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRQ3LEVELMESHCLASS_LUA_GETSHADER,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRQ3LEVELMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRQ3LEVELMESHCLASS_GETSHADER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRQ3LEVELMESHCLASS_GETSHADER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,VSFUNCID_IrrQ3LevelMeshClass_GetShader,(void *)IrrQ3LevelMeshClass_GetShader,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRQ3LEVELMESHCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRQ3LEVELMESHCLASS_LUA_GETSHADER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRQ3LEVELMESHCLASS_LUA_GETSHADER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,VSFUNCID_IrrQ3LevelMeshClass_Lua_GetShader,(void *)IrrQ3LevelMeshClass_Lua_GetShader,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRQ3LEVELMESHCLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,(void *)IrrQ3LevelMeshClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrQ3LevelMeshClass,(void *)IrrQ3LevelMeshClass_QueryObjectInfo);

    return 0;
}

