/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrShaderMaterialTypeClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRSHADERMATERIALTYPECLASS_OBJECT_DEPENDINDEX                                                0x00000001
#define IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE_FUNCRETURN_DEPENDINDEX                            0X00000002
#define IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE_FUNCPARAM_DEPENDINDEX                             0X00000003
#define IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE_FUNCRETURN_DEPENDINDEX                            0X00000004
#define IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE_FUNCPARAM_DEPENDINDEX                             0X00000005

VS_INT32 SRPCALLBACK IrrShaderMaterialTypeClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrShaderMaterialTypeClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRSHADERMATERIALTYPECLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,IRRSHADERMATERIALTYPECLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrShaderMaterialTypeClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRSHADERMATERIALTYPECLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrShaderMaterialTypeClass_SetMaterialType,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrShaderMaterialTypeClass_SetMaterialType,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrShaderMaterialTypeClass_GetMaterialType,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrShaderMaterialTypeClass_GetMaterialType,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRSHADERMATERIALTYPECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRSHADERMATERIALTYPECLASS_SETMATERIALTYPE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,VSFUNCID_IrrShaderMaterialTypeClass_SetMaterialType,(void *)IrrShaderMaterialTypeClass_SetMaterialType,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRSHADERMATERIALTYPECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRSHADERMATERIALTYPECLASS_GETMATERIALTYPE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,VSFUNCID_IrrShaderMaterialTypeClass_GetMaterialType,(void *)IrrShaderMaterialTypeClass_GetMaterialType,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRSHADERMATERIALTYPECLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,(void *)IrrShaderMaterialTypeClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrShaderMaterialTypeClass,(void *)IrrShaderMaterialTypeClass_QueryObjectInfo);

    return 0;
}

