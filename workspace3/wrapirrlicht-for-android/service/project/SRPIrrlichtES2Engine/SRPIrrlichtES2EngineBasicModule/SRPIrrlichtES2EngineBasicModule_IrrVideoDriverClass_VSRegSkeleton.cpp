/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrVideoDriverClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRVIDEODRIVERCLASS_OBJECT_DEPENDINDEX                                                       0x00000001

VS_INT32 SRPCALLBACK IrrVideoDriverClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrVideoDriverClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRVIDEODRIVERCLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrVideoDriverClass,IRRVIDEODRIVERCLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrVideoDriverClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRVIDEODRIVERCLASS,LocalDependAttribute);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRVIDEODRIVERCLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrVideoDriverClass,(void *)IrrVideoDriverClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrVideoDriverClass,(void *)IrrVideoDriverClass_QueryObjectInfo);

    return 0;
}

