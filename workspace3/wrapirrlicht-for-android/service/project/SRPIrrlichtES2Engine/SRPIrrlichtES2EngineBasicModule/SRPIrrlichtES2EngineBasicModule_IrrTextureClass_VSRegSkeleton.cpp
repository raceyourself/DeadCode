/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrTextureClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRTEXTURECLASS_OBJECT_DEPENDINDEX                                                           0x00000001
#define IRRTEXTURECLASS_ONBEFORECREATE_FUNCRETURN_DEPENDINDEX                                        0X00000002
#define IRRTEXTURECLASS_ONBEFORECREATE_FUNCPARAM_DEPENDINDEX                                         0X00000003
#define IRRTEXTURECLASS_ONAFTERCREATE_FUNCRETURN_DEPENDINDEX                                         0X00000004
#define IRRTEXTURECLASS_ONAFTERCREATE_FUNCPARAM_DEPENDINDEX                                          0X00000005
#define IRRTEXTURECLASS_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX                                    0X00000006
#define IRRTEXTURECLASS_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX                                     0X00000007
#define IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX                                0X00000008
#define IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX                                 0X00000009
#define IRRTEXTURECLASS_SETIRRTEXTURE_FUNCRETURN_DEPENDINDEX                                         0X0000000A
#define IRRTEXTURECLASS_SETIRRTEXTURE_FUNCPARAM_DEPENDINDEX                                          0X0000000B

VS_INT32 SRPCALLBACK IrrTextureClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
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

VS_INT32 SRPCALLBACK IrrTextureClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRTEXTURECLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrTextureClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRTEXTURECLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRTEXTURECLASS_ONBEFORECREATE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_ONBEFORECREATE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrTextureClass_OnBeforeCreate,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_ONBEFORECREATE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRTEXTURECLASS_ONBEFORECREATE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_ONBEFORECREATE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrTextureClass_OnBeforeCreate,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_ONBEFORECREATE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRTEXTURECLASS_ONAFTERCREATE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_ONAFTERCREATE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrTextureClass_OnAfterCreate,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_ONAFTERCREATE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRTEXTURECLASS_ONAFTERCREATE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_ONAFTERCREATE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrTextureClass_OnAfterCreate,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_ONAFTERCREATE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRTEXTURECLASS_TRIGGERCHANGEEVENT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrTextureClass_TriggerChangeEvent,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_TRIGGERCHANGEEVENT,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRTEXTURECLASS_TRIGGERCHANGEEVENT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrTextureClass_TriggerChangeEvent,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_TRIGGERCHANGEEVENT,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrTextureClass_Lua_TriggerChangeEvent,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrTextureClass_Lua_TriggerChangeEvent,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRTEXTURECLASS_SETIRRTEXTURE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_SETIRRTEXTURE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrTextureClass_SetIrrTexture,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRTEXTURECLASS_SETIRRTEXTURE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRTEXTURECLASS_SETIRRTEXTURE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,IRRTEXTURECLASS_SETIRRTEXTURE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrTextureClass_SetIrrTexture,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRTEXTURECLASS_SETIRRTEXTURE,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRTEXTURECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRTEXTURECLASS_ONBEFORECREATE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRTEXTURECLASS_ONBEFORECREATE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,VSFUNCID_IrrTextureClass_OnBeforeCreate,(void *)IrrTextureClass_OnBeforeCreate,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRTEXTURECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRTEXTURECLASS_ONAFTERCREATE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRTEXTURECLASS_ONAFTERCREATE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,VSFUNCID_IrrTextureClass_OnAfterCreate,(void *)IrrTextureClass_OnAfterCreate,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRTEXTURECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRTEXTURECLASS_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRTEXTURECLASS_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,VSFUNCID_IrrTextureClass_TriggerChangeEvent,(void *)IrrTextureClass_TriggerChangeEvent,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRTEXTURECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRTEXTURECLASS_LUA_TRIGGERCHANGEEVENT_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,VSFUNCID_IrrTextureClass_Lua_TriggerChangeEvent,(void *)IrrTextureClass_Lua_TriggerChangeEvent,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRTEXTURECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRTEXTURECLASS_SETIRRTEXTURE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRTEXTURECLASS_SETIRRTEXTURE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,VSFUNCID_IrrTextureClass_SetIrrTexture,(void *)IrrTextureClass_SetIrrTexture,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRTEXTURECLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,(void *)IrrTextureClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrTextureClass,(void *)IrrTextureClass_QueryObjectInfo);

    return 0;
}

