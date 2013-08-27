/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrMaterialClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRMATERIALCLASS_OBJECT_DEPENDINDEX                                                          0x00000001
#define IRRMATERIALCLASS_SETTEXTURE_FUNCRETURN_DEPENDINDEX                                           0X00000002
#define IRRMATERIALCLASS_SETTEXTURE_FUNCPARAM_DEPENDINDEX                                            0X00000003
#define IRRMATERIALCLASS_LUA_SETTEXTURE_FUNCRETURN_DEPENDINDEX                                       0X00000004
#define IRRMATERIALCLASS_LUA_SETTEXTURE_FUNCPARAM_DEPENDINDEX                                        0X00000005
#define IRRMATERIALCLASS_SETSHADERMATERIALTYPE_FUNCRETURN_DEPENDINDEX                                0X00000006
#define IRRMATERIALCLASS_SETSHADERMATERIALTYPE_FUNCPARAM_DEPENDINDEX                                 0X00000007
#define IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE_FUNCRETURN_DEPENDINDEX                            0X00000008
#define IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE_FUNCPARAM_DEPENDINDEX                             0X00000009

VS_INT32 SRPCALLBACK IrrMaterialClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrMaterialClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRMATERIALCLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrMaterialClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRMATERIALCLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRMATERIALCLASS_SETTEXTURE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_SETTEXTURE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMaterialClass_SetTexture,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMATERIALCLASS_SETTEXTURE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMATERIALCLASS_SETTEXTURE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_SETTEXTURE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMaterialClass_SetTexture,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMATERIALCLASS_SETTEXTURE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRMATERIALCLASS_LUA_SETTEXTURE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_LUA_SETTEXTURE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMaterialClass_Lua_SetTexture,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMATERIALCLASS_LUA_SETTEXTURE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMATERIALCLASS_LUA_SETTEXTURE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_LUA_SETTEXTURE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMaterialClass_Lua_SetTexture,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMATERIALCLASS_LUA_SETTEXTURE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRMATERIALCLASS_SETSHADERMATERIALTYPE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_SETSHADERMATERIALTYPE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMaterialClass_SetShaderMaterialType,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMATERIALCLASS_SETSHADERMATERIALTYPE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMATERIALCLASS_SETSHADERMATERIALTYPE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_SETSHADERMATERIALTYPE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMaterialClass_SetShaderMaterialType,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMATERIALCLASS_SETSHADERMATERIALTYPE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrMaterialClass_Lua_SetShaderMaterialType,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrMaterialClass_Lua_SetShaderMaterialType,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRMATERIALCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMATERIALCLASS_SETTEXTURE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMATERIALCLASS_SETTEXTURE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,VSFUNCID_IrrMaterialClass_SetTexture,(void *)IrrMaterialClass_SetTexture,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRMATERIALCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMATERIALCLASS_LUA_SETTEXTURE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMATERIALCLASS_LUA_SETTEXTURE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,VSFUNCID_IrrMaterialClass_Lua_SetTexture,(void *)IrrMaterialClass_Lua_SetTexture,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRMATERIALCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMATERIALCLASS_SETSHADERMATERIALTYPE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMATERIALCLASS_SETSHADERMATERIALTYPE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,VSFUNCID_IrrMaterialClass_SetShaderMaterialType,(void *)IrrMaterialClass_SetShaderMaterialType,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRMATERIALCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRMATERIALCLASS_LUA_SETSHADERMATERIALTYPE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,VSFUNCID_IrrMaterialClass_Lua_SetShaderMaterialType,(void *)IrrMaterialClass_Lua_SetShaderMaterialType,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRMATERIALCLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,(void *)IrrMaterialClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrMaterialClass,(void *)IrrMaterialClass_QueryObjectInfo);

    return 0;
}

