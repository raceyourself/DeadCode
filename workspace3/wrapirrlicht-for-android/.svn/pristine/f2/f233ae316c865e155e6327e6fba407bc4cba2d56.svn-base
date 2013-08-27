/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Class Body File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPFSEngine_VSClass.h"
ClassOfFileToolClass::ClassOfFileToolClass()
{
}

ClassOfFileToolClass::ClassOfFileToolClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_FileToolClass,0,NULL));
}

ClassOfFileToolClass::ClassOfFileToolClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfFileToolClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "FileToolClass" );
    return Buf;
}

class ClassOfFileToolClass *ClassOfFileToolClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfFileToolClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfFileToolClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "FileToolClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfFileToolClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

void SRPAPI ClassOfFileToolClass::Execute(VS_BOOL ShowMax)
{
    ThisSRPInterface -> Call(ThisSRPObject,"Execute",ShowMax);
}
VS_CHAR * SRPAPI ClassOfFileToolClass::GetLoadFile()
{
    return (VS_CHAR * )ThisSRPInterface -> Call(ThisSRPObject,"GetLoadFile");
}
VS_CHAR * SRPAPI ClassOfFileToolClass::GetSaveFile()
{
    return (VS_CHAR * )ThisSRPInterface -> Call(ThisSRPObject,"GetSaveFile");
}

ClassOfDirectoryClass::ClassOfDirectoryClass()
{
}

ClassOfDirectoryClass::ClassOfDirectoryClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_DirectoryClass,0,NULL));
}

ClassOfDirectoryClass::ClassOfDirectoryClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfDirectoryClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "DirectoryClass" );
    return Buf;
}

class ClassOfDirectoryClass *ClassOfDirectoryClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfDirectoryClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfDirectoryClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "DirectoryClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfDirectoryClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_CHAR * ClassOfDirectoryClass::Get_Name()
{
    return ((struct StructOfDirectoryClass *)ThisSRPObject) -> Name.Buf;
}
void ClassOfDirectoryClass::Put_Name(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_DIRECTORYCLASS_NAME,(VS_INT8 *)In_Value);
}

VS_TIME * ClassOfDirectoryClass::Get_FDate()
{
    return &((struct StructOfDirectoryClass *)ThisSRPObject) -> FDate;
}
void ClassOfDirectoryClass::Put_FDate(VS_TIME * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_DIRECTORYCLASS_FDATE,(VS_INT8 *)In_Value);
}



ClassOfDriveClass::ClassOfDriveClass()
{
}

ClassOfDriveClass::ClassOfDriveClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_DriveClass,0,NULL));
}

ClassOfDriveClass::ClassOfDriveClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfDriveClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "DriveClass" );
    return Buf;
}

class ClassOfDriveClass *ClassOfDriveClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfDriveClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfDriveClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "DriveClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfDriveClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

void * ClassOfDriveClass::Get_LocalBuf()
{
    return ((struct StructOfDriveClass *)ThisSRPObject) -> LocalBuf;
}
void ClassOfDriveClass::Put_LocalBuf(void * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_DRIVECLASS_LOCALBUF,(VS_INT8 *)In_Value);
}

VSSystemEvent_EventProc ClassOfDriveClass::Get_E_OnRead()
{
    return NULL;
}
void ClassOfDriveClass::Put_E_OnRead(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_DriveClass_OnRead,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}

VSSystemEvent_EventProc ClassOfDriveClass::Get_E_OnDownLoad()
{
    return NULL;
}
void ClassOfDriveClass::Put_E_OnDownLoad(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_DriveClass_OnDownLoad,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}

VSSystemEvent_EventProc ClassOfDriveClass::Get_E_OnFileChange()
{
    return NULL;
}
void ClassOfDriveClass::Put_E_OnFileChange(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_DriveClass_OnFileChange,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}

void ClassOfDriveClass::Put_F_SaveFObjectData(void * In_Value)
{
    ThisSRPInterface -> CreateOVLFunction(ThisSRPObject,&VSFUNCID_DriveClass_SaveFObjectData,In_Value,NULL);
}
void * ClassOfDriveClass::Get_F_SaveFObjectData()
{
    return NULL;
}

void ClassOfDriveClass::Put_F_LoadFObjectData(void * In_Value)
{
    ThisSRPInterface -> CreateOVLFunction(ThisSRPObject,&VSFUNCID_DriveClass_LoadFObjectData,In_Value,NULL);
}
void * ClassOfDriveClass::Get_F_LoadFObjectData()
{
    return NULL;
}


VS_BOOL SRPAPI ClassOfDriveClass::SaveFObjectData(VS_UUID ObjectID,VS_ULONG DataSize,VS_CHAR * DataBuf)
{
    DriveClass_SaveFObjectDataProc LocalProc;

    LocalProc = (DriveClass_SaveFObjectDataProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_SaveFObjectData);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,ObjectID,DataSize,DataBuf);
    else{
        VS_BOOL LocalReturnValue = VS_FALSE;

        return LocalReturnValue;
    }
}
VS_CHAR * SRPAPI ClassOfDriveClass::LoadFObjectData(VS_UUID ObjectID,VS_ULONG * DataSize)
{
    DriveClass_LoadFObjectDataProc LocalProc;

    LocalProc = (DriveClass_LoadFObjectDataProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_LoadFObjectData);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,ObjectID,DataSize);
    else{
        VS_CHAR * LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void SRPAPI ClassOfDriveClass::Dir(VS_CHAR * PathName)
{
    ThisSRPInterface -> Call(ThisSRPObject,"Dir",PathName);
}
VS_BOOL SRPAPI ClassOfDriveClass::CHDir(VS_CHAR * PathName)
{
    return (VS_BOOL )ThisSRPInterface -> Call(ThisSRPObject,"CHDir",PathName);
}
void *SRPAPI ClassOfDriveClass::MKDir(VS_CHAR * PathName,VS_UUID * DirObjectID)
{
    DriveClass_MKDirProc LocalProc;

    LocalProc = (DriveClass_MKDirProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_MKDir);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,PathName,DirObjectID);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void SRPAPI ClassOfDriveClass::RMDir(VS_CHAR * PathName)
{
    ThisSRPInterface -> Call(ThisSRPObject,"RMDir",PathName);
}
VS_ULONG SRPAPI ClassOfDriveClass::Open(VS_CHAR * FileName,VS_BOOL CreateFlag,VS_UUID * FileObjectID,VS_UUID * RetFileObjectID)
{
    DriveClass_OpenProc LocalProc;

    LocalProc = (DriveClass_OpenProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_Open);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileName,CreateFlag,FileObjectID,RetFileObjectID);
    else{
        VS_ULONG LocalReturnValue = 0;

        return LocalReturnValue;
    }
}
void SRPAPI ClassOfDriveClass::Close(VS_ULONG FHandle)
{
    ThisSRPInterface -> Call(ThisSRPObject,"Close",FHandle);
}
VS_CHAR * SRPAPI ClassOfDriveClass::Read(VS_ULONG FHandle,VS_ULONG * Size)
{
    DriveClass_ReadProc LocalProc;

    LocalProc = (DriveClass_ReadProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_Read);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FHandle,Size);
    else{
        VS_CHAR * LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void SRPAPI ClassOfDriveClass::Write(VS_ULONG FHandle,VS_CHAR * FBuf,VS_ULONG Size)
{
    ThisSRPInterface -> Call(ThisSRPObject,"Write",FHandle,FBuf,Size);
}
void SRPAPI ClassOfDriveClass::Del(VS_CHAR * FileName)
{
    ThisSRPInterface -> Call(ThisSRPObject,"Del",FileName);
}
VS_CHAR * SRPAPI ClassOfDriveClass::QueryFirst(VS_CHAR * FileName,VS_ULONG * FFindContext)
{
    DriveClass_QueryFirstProc LocalProc;

    LocalProc = (DriveClass_QueryFirstProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_QueryFirst);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileName,FFindContext);
    else{
        VS_CHAR * LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
VS_CHAR * SRPAPI ClassOfDriveClass::QueryNext(VS_ULONG FFindContext)
{
    return (VS_CHAR * )ThisSRPInterface -> Call(ThisSRPObject,"QueryNext",FFindContext);
}
void SRPAPI ClassOfDriveClass::QueryClose(VS_ULONG FFindContext)
{
    ThisSRPInterface -> Call(ThisSRPObject,"QueryClose",FFindContext);
}
void SRPAPI ClassOfDriveClass::RegCallBack(VS_CHAR * FileName,void *DesObject,void *FuncAddr)
{
    DriveClass_RegCallBackProc LocalProc;

    LocalProc = (DriveClass_RegCallBackProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_RegCallBack);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,FileName,DesObject,FuncAddr);
}
void SRPAPI ClassOfDriveClass::UnRegCallBack(VS_CHAR * FileName,void *DesObject,void *FuncAddr)
{
    DriveClass_UnRegCallBackProc LocalProc;

    LocalProc = (DriveClass_UnRegCallBackProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_UnRegCallBack);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,FileName,DesObject,FuncAddr);
}
void *SRPAPI ClassOfDriveClass::LoadFile(VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_UUID * FileObjectID,VS_BOOL TxtFileFlag)
{
    DriveClass_LoadFileProc LocalProc;

    LocalProc = (DriveClass_LoadFileProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_LoadFile);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileName,DiskFileName,FileObjectID,TxtFileFlag);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void *SRPAPI ClassOfDriveClass::LoadFileEx(VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_UUID * FileObjectID)
{
    DriveClass_LoadFileExProc LocalProc;

    LocalProc = (DriveClass_LoadFileExProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_LoadFileEx);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileName,DiskFileName,FileObjectID);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void *SRPAPI ClassOfDriveClass::LoadBuf(VS_CHAR * FileName,VS_CHAR * Buf,VS_INT32 BufSize,VS_UUID * FileObjectID)
{
    DriveClass_LoadBufProc LocalProc;

    LocalProc = (DriveClass_LoadBufProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_LoadBuf);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileName,Buf,BufSize,FileObjectID);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void *SRPAPI ClassOfDriveClass::LoadWebFile(VS_CHAR * FileName,VS_CHAR * WebFileUrl,VS_CHAR * DiskFileName,VS_UUID * FileObjectID,VS_UUID * FileVersion)
{
    DriveClass_LoadWebFileProc LocalProc;

    LocalProc = (DriveClass_LoadWebFileProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_LoadWebFile);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileName,WebFileUrl,DiskFileName,FileObjectID,FileVersion);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void SRPAPI ClassOfDriveClass::SetWebFileInfo(VS_CHAR * FileName,VS_CHAR * WebFileUrl,VS_UUID * FileVersion)
{
    DriveClass_SetWebFileInfoProc LocalProc;

    LocalProc = (DriveClass_SetWebFileInfoProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_SetWebFileInfo);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,FileName,WebFileUrl,FileVersion);
}
VS_CHAR * SRPAPI ClassOfDriveClass::GetWebFileInfo(VS_CHAR * FileName,VS_UUID * FileVersion)
{
    DriveClass_GetWebFileInfoProc LocalProc;

    LocalProc = (DriveClass_GetWebFileInfoProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_GetWebFileInfo);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileName,FileVersion);
    else{
        VS_CHAR * LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
VS_BOOL SRPAPI ClassOfDriveClass::SaveFile(VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_BOOL TxtFileFlag)
{
    return (VS_BOOL )ThisSRPInterface -> Call(ThisSRPObject,"SaveFile",FileName,DiskFileName,TxtFileFlag);
}
void *SRPAPI ClassOfDriveClass::GetFileObject(VS_CHAR * FileName)
{
    DriveClass_GetFileObjectProc LocalProc;

    LocalProc = (DriveClass_GetFileObjectProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_GetFileObject);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileName);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
VS_BOOL SRPAPI ClassOfDriveClass::IsDir(VS_CHAR * FileName)
{
    return (VS_BOOL )ThisSRPInterface -> Call(ThisSRPObject,"IsDir",FileName);
}
VS_BOOL SRPAPI ClassOfDriveClass::IsFile(VS_CHAR * FileName)
{
    return (VS_BOOL )ThisSRPInterface -> Call(ThisSRPObject,"IsFile",FileName);
}
void *SRPAPI ClassOfDriveClass::GetDrive(VS_CHAR * FullPath)
{
    DriveClass_GetDriveProc LocalProc;

    LocalProc = (DriveClass_GetDriveProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_GetDrive);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FullPath);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
void *SRPAPI ClassOfDriveClass::GetDriveEx(void *FileObj)
{
    DriveClass_GetDriveExProc LocalProc;

    LocalProc = (DriveClass_GetDriveExProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_GetDriveEx);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileObj);
    else{
        void *LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
VS_ULONG SRPAPI ClassOfDriveClass::GetFileStatus(VS_CHAR * FileName)
{
    return (VS_ULONG )ThisSRPInterface -> Call(ThisSRPObject,"GetFileStatus",FileName);
}
void SRPAPI ClassOfDriveClass::DownLoad(VS_CHAR * FileName)
{
    ThisSRPInterface -> Call(ThisSRPObject,"DownLoad",FileName);
}
VS_CHAR * SRPAPI ClassOfDriveClass::GetFileName(void *FileDirObject)
{
    DriveClass_GetFileNameProc LocalProc;

    LocalProc = (DriveClass_GetFileNameProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_GetFileName);
    if( LocalProc != NULL )
        return LocalProc(ThisSRPObject,FileDirObject);
    else{
        VS_CHAR * LocalReturnValue = NULL;

        return LocalReturnValue;
    }
}
VS_BOOL SRPAPI ClassOfDriveClass::DoScript(VS_CHAR * FileName,VS_BOOL IsUTF8)
{
    return (VS_BOOL )ThisSRPInterface -> Call(ThisSRPObject,"DoScript",FileName,IsUTF8);
}
VS_BOOL SRPAPI ClassOfDriveClass::DoScriptEx(VS_CHAR * ScriptInterface,VS_CHAR * FileName,VS_BOOL IsUTF8)
{
    return (VS_BOOL )ThisSRPInterface -> Call(ThisSRPObject,"DoScriptEx",ScriptInterface,FileName,IsUTF8);
}
void SRPAPI ClassOfDriveClass::GetFileVersion(VS_CHAR * FileName,VS_UUID * FileVersion)
{
    DriveClass_GetFileVersionProc LocalProc;

    LocalProc = (DriveClass_GetFileVersionProc)ThisSRPInterface -> GetFunctionEx(ThisSRPObject,&VSFUNCID_DriveClass_GetFileVersion);
    if( LocalProc != NULL )
        LocalProc(ThisSRPObject,FileName,FileVersion);
}

ClassOfFileClass::ClassOfFileClass()
{
}

ClassOfFileClass::ClassOfFileClass(class ClassOfSRPInterface *In_SRPInterface)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_TRUE,VS_FALSE,In_SRPInterface -> MallocObjectL(&VSOBJID_FileClass,0,NULL));
}

ClassOfFileClass::ClassOfFileClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject)
{
    if( In_SRPInterface == NULL )
        return;
    WrapObject(In_SRPInterface,VS_FALSE,VS_FALSE,SRPObject);
}

VS_CHAR *ClassOfFileClass::GetSelfName()
{
    static VS_CHAR Buf[64];
    strcpy( Buf, "FileClass" );
    return Buf;
}

class ClassOfFileClass *ClassOfFileClass::GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer)
{
    class ClassOfFileClass *ClassObject;

    if( SRPObject == NULL || In_SRPInterface == NULL )
        return NULL;
    if( In_ClassLayer == 0xFFFFFFFF )
        In_ClassLayer = In_SRPInterface -> GetLayer( SRPObject );
    ClassObject = (class ClassOfFileClass *)In_SRPInterface -> GetAppClass( SRPObject, In_ClassLayer );
    if( ClassObject != NULL && strcmp( ((class ClassOfSRPObject *)ClassObject) -> GetSelfName(), "FileClass" ) == 0 )
        return ClassObject;
    ClassObject = new class ClassOfFileClass();
    ClassObject -> WrapObject(In_SRPInterface,VS_FALSE,VS_TRUE,SRPObject, In_ClassLayer);
    return ClassObject;
}

VS_STATICID * ClassOfFileClass::Get_FileDataID()
{
    return &((struct StructOfFileClass *)ThisSRPObject) -> FileDataID;
}
void ClassOfFileClass::Put_FileDataID(VS_STATICID * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_FILECLASS_FILEDATAID,(VS_INT8 *)In_Value);
}

VS_CHAR * ClassOfFileClass::Get_Name()
{
    return ((struct StructOfFileClass *)ThisSRPObject) -> Name.Buf;
}
void ClassOfFileClass::Put_Name(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_FILECLASS_NAME,(VS_INT8 *)In_Value);
}

VS_ULONG ClassOfFileClass::Get_FSize()
{
    return ((struct StructOfFileClass *)ThisSRPObject) -> FSize;
}
void ClassOfFileClass::Put_FSize(VS_ULONG In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_FILECLASS_FSIZE,(VS_INT8 *)&In_Value);
}

VS_TIME * ClassOfFileClass::Get_FDate()
{
    return &((struct StructOfFileClass *)ThisSRPObject) -> FDate;
}
void ClassOfFileClass::Put_FDate(VS_TIME * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_FILECLASS_FDATE,(VS_INT8 *)In_Value);
}

VS_CHAR * ClassOfFileClass::Get_Url()
{
    return ((struct StructOfFileClass *)ThisSRPObject) -> Url.Buf;
}
void ClassOfFileClass::Put_Url(VS_CHAR * In_Value)
{
    ThisSRPInterface -> ChangeObject(ThisSRPObject,VSATTRINDEX_FILECLASS_URL,(VS_INT8 *)In_Value);
}

VSSystemEvent_EventProc ClassOfFileClass::Get_E_OnChange()
{
    return NULL;
}
void ClassOfFileClass::Put_E_OnChange(VSSystemEvent_EventProc In_Value)
{
    ThisSRPInterface -> RegEventFunction(ThisSRPObject,&VSOUTEVENTID_FileClass_OnChange,ThisSRPObject,(void *)In_Value,(VS_ULONG)this);
}



