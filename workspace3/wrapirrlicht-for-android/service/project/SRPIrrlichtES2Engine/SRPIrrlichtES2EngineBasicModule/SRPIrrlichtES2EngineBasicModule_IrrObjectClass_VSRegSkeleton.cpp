/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrObjectClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRROBJECTCLASS_OBJECT_DEPENDINDEX                                                            0x00000001
#define IRROBJECTCLASS_SETIRROBJECT_FUNCRETURN_DEPENDINDEX                                           0X00000002
#define IRROBJECTCLASS_SETIRROBJECT_FUNCPARAM_DEPENDINDEX                                            0X00000003
#define IRROBJECTCLASS_GETIRROBJECT_FUNCRETURN_DEPENDINDEX                                           0X00000004
#define IRROBJECTCLASS_GETIRROBJECT_FUNCPARAM_DEPENDINDEX                                            0X00000005
#define IRROBJECTCLASS_SETIRRPARENTSCENENODE_FUNCRETURN_DEPENDINDEX                                  0X00000006
#define IRROBJECTCLASS_SETIRRPARENTSCENENODE_FUNCPARAM_DEPENDINDEX                                   0X00000007
#define IRROBJECTCLASS_ONIRRACTIVATING_FUNCRETURN_DEPENDINDEX                                        0X00000008
#define IRROBJECTCLASS_ONIRRACTIVATING_FUNCPARAM_DEPENDINDEX                                         0X00000009

VS_INT32 SRPCALLBACK IrrObjectClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrObjectClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRROBJECTCLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrObjectClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRROBJECTCLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRROBJECTCLASS_SETIRROBJECT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_SETIRROBJECT_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrObjectClass_SetIrrObject,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRROBJECTCLASS_SETIRROBJECT,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRROBJECTCLASS_SETIRROBJECT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_SETIRROBJECT_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrObjectClass_SetIrrObject,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRROBJECTCLASS_SETIRROBJECT,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRROBJECTCLASS_GETIRROBJECT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_GETIRROBJECT_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrObjectClass_GetIrrObject,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRROBJECTCLASS_GETIRROBJECT,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRROBJECTCLASS_GETIRROBJECT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_GETIRROBJECT_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrObjectClass_GetIrrObject,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRROBJECTCLASS_GETIRROBJECT,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRROBJECTCLASS_SETIRRPARENTSCENENODE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_SETIRRPARENTSCENENODE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrObjectClass_SetIrrParentSceneNode,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRROBJECTCLASS_SETIRRPARENTSCENENODE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRROBJECTCLASS_SETIRRPARENTSCENENODE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_SETIRRPARENTSCENENODE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrObjectClass_SetIrrParentSceneNode,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRROBJECTCLASS_SETIRRPARENTSCENENODE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRROBJECTCLASS_ONIRRACTIVATING(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_ONIRRACTIVATING_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrObjectClass_OnIrrActivating,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRROBJECTCLASS_ONIRRACTIVATING,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRROBJECTCLASS_ONIRRACTIVATING(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,IRROBJECTCLASS_ONIRRACTIVATING_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrObjectClass_OnIrrActivating,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRROBJECTCLASS_ONIRRACTIVATING,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRROBJECTCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRROBJECTCLASS_SETIRROBJECT_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRROBJECTCLASS_SETIRROBJECT_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,VSFUNCID_IrrObjectClass_SetIrrObject,(void *)IrrObjectClass_SetIrrObject,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRROBJECTCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRROBJECTCLASS_GETIRROBJECT_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRROBJECTCLASS_GETIRROBJECT_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,VSFUNCID_IrrObjectClass_GetIrrObject,(void *)IrrObjectClass_GetIrrObject,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRROBJECTCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRROBJECTCLASS_SETIRRPARENTSCENENODE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRROBJECTCLASS_SETIRRPARENTSCENENODE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,VSFUNCID_IrrObjectClass_SetIrrParentSceneNode,(void *)IrrObjectClass_SetIrrParentSceneNode,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRROBJECTCLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRROBJECTCLASS_ONIRRACTIVATING_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRROBJECTCLASS_ONIRRACTIVATING_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,VSFUNCID_IrrObjectClass_OnIrrActivating,(void *)IrrObjectClass_OnIrrActivating,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRROBJECTCLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,(void *)IrrObjectClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrObjectClass,(void *)IrrObjectClass_QueryObjectInfo);

    return 0;
}

