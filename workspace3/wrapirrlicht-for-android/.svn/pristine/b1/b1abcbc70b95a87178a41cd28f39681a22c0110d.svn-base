/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrFileSystemClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRFILESYSTEMCLASS_OBJECT_DEPENDINDEX                                                        0x00000001
#define IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE_FUNCRETURN_DEPENDINDEX                                  0X00000002
#define IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE_FUNCPARAM_DEPENDINDEX                                   0X00000003
#define IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE_FUNCRETURN_DEPENDINDEX                              0X00000004
#define IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE_FUNCPARAM_DEPENDINDEX                               0X00000005

VS_INT32 SRPCALLBACK IrrFileSystemClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrFileSystemClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRFILESYSTEMCLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,IRRFILESYSTEMCLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrFileSystemClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRFILESYSTEMCLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrFileSystemClass_AddZipFileArchive,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrFileSystemClass_AddZipFileArchive,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrFileSystemClass_Lua_AddZipFileArchive,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrFileSystemClass_Lua_AddZipFileArchive,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRFILESYSTEMCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRFILESYSTEMCLASS_ADDZIPFILEARCHIVE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,VSFUNCID_IrrFileSystemClass_AddZipFileArchive,(void *)IrrFileSystemClass_AddZipFileArchive,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRFILESYSTEMCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRFILESYSTEMCLASS_LUA_ADDZIPFILEARCHIVE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,VSFUNCID_IrrFileSystemClass_Lua_AddZipFileArchive,(void *)IrrFileSystemClass_Lua_AddZipFileArchive,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRFILESYSTEMCLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,(void *)IrrFileSystemClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrFileSystemClass,(void *)IrrFileSystemClass_QueryObjectInfo);

    return 0;
}

