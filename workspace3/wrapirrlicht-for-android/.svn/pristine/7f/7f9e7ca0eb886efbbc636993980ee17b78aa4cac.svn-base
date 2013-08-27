/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Class Header File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#ifndef SRPFSENGINE_CLASSHEADERFILE
#define SRPFSENGINE_CLASSHEADERFILE

#define _INCLUDE_STARLIB
#include "SRPFSEngine_VSDHeader.h"

#if( VS_OS_TYPE == VS_OS_WINDOWS )
#pragma warning (disable:4819)
#pragma warning (disable:4244)
#pragma warning (disable:4996)
#pragma warning (disable:4800)
#endif

#pragma pack(4)

class ClassOfFileToolClass:public ClassOfSRPObject{
public:
    ClassOfFileToolClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfFileToolClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfFileToolClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfFileToolClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Function Define
    void SRPAPI Execute(VS_BOOL ShowMax);
    VS_CHAR * SRPAPI GetLoadFile();
    VS_CHAR * SRPAPI GetSaveFile();
};

class ClassOfDirectoryClass:public ClassOfSRPObject{
public:
    ClassOfDirectoryClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfDirectoryClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfDirectoryClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfDirectoryClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_CHAR * Get_Name();
    void Put_Name(VS_CHAR * In_Value);

    VS_TIME * Get_FDate();
    void Put_FDate(VS_TIME * In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_Name, put=Put_Name)) VS_VSTRING Name;
    __declspec(property(get=Get_FDate, put=Put_FDate)) VS_TIME FDate;
#endif

};

class ClassOfDriveClass:public ClassOfSRPObject{
public:
    ClassOfDriveClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfDriveClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfDriveClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfDriveClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    void * Get_LocalBuf();
    void Put_LocalBuf(void * In_Value);


public:
    //--OutEvent Get/Put Function Define
    VSSystemEvent_EventProc Get_E_OnRead();
    void Put_E_OnRead(VSSystemEvent_EventProc In_Value);

    VSSystemEvent_EventProc Get_E_OnDownLoad();
    void Put_E_OnDownLoad(VSSystemEvent_EventProc In_Value);

    VSSystemEvent_EventProc Get_E_OnFileChange();
    void Put_E_OnFileChange(VSSystemEvent_EventProc In_Value);


public:
    //--PubFunction Get/Put Function Define
    void Put_F_SaveFObjectData(void * In_Value);
    void * Get_F_SaveFObjectData();

    void Put_F_LoadFObjectData(void * In_Value);
    void * Get_F_LoadFObjectData();


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_LocalBuf, put=Put_LocalBuf)) void * LocalBuf;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--OutEvent Property Define
    __declspec(property(get=Get_E_OnRead, put=Put_E_OnRead)) VSSystemEvent_EventProc E_OnRead;
    __declspec(property(get=Get_E_OnDownLoad, put=Put_E_OnDownLoad)) VSSystemEvent_EventProc E_OnDownLoad;
    __declspec(property(get=Get_E_OnFileChange, put=Put_E_OnFileChange)) VSSystemEvent_EventProc E_OnFileChange;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--PubFunction Property Define
    __declspec(property(get=Get_F_SaveFObjectData, put=Put_F_SaveFObjectData)) void * F_SaveFObjectData;
    __declspec(property(get=Get_F_LoadFObjectData, put=Put_F_LoadFObjectData)) void * F_LoadFObjectData;
#endif

public:
    //--Function Define
    VS_BOOL SRPAPI SaveFObjectData(VS_UUID ObjectID,VS_ULONG DataSize,VS_CHAR * DataBuf);
    VS_CHAR * SRPAPI LoadFObjectData(VS_UUID ObjectID,VS_ULONG * DataSize);
    void SRPAPI Dir(VS_CHAR * PathName);
    VS_BOOL SRPAPI CHDir(VS_CHAR * PathName);
    void *SRPAPI MKDir(VS_CHAR * PathName,VS_UUID * DirObjectID);
    void SRPAPI RMDir(VS_CHAR * PathName);
    VS_ULONG SRPAPI Open(VS_CHAR * FileName,VS_BOOL CreateFlag,VS_UUID * FileObjectID,VS_UUID * RetFileObjectID);
    void SRPAPI Close(VS_ULONG FHandle);
    VS_CHAR * SRPAPI Read(VS_ULONG FHandle,VS_ULONG * Size);
    void SRPAPI Write(VS_ULONG FHandle,VS_CHAR * FBuf,VS_ULONG Size);
    void SRPAPI Del(VS_CHAR * FileName);
    VS_CHAR * SRPAPI QueryFirst(VS_CHAR * FileName,VS_ULONG * FFindContext);
    VS_CHAR * SRPAPI QueryNext(VS_ULONG FFindContext);
    void SRPAPI QueryClose(VS_ULONG FFindContext);
    void SRPAPI RegCallBack(VS_CHAR * FileName,void *DesObject,void *FuncAddr);
    void SRPAPI UnRegCallBack(VS_CHAR * FileName,void *DesObject,void *FuncAddr);
    void *SRPAPI LoadFile(VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_UUID * FileObjectID,VS_BOOL TxtFileFlag);
    void *SRPAPI LoadFileEx(VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_UUID * FileObjectID);
    void *SRPAPI LoadBuf(VS_CHAR * FileName,VS_CHAR * Buf,VS_INT32 BufSize,VS_UUID * FileObjectID);
    void *SRPAPI LoadWebFile(VS_CHAR * FileName,VS_CHAR * WebFileUrl,VS_CHAR * DiskFileName,VS_UUID * FileObjectID,VS_UUID * FileVersion);
    void SRPAPI SetWebFileInfo(VS_CHAR * FileName,VS_CHAR * WebFileUrl,VS_UUID * FileVersion);
    VS_CHAR * SRPAPI GetWebFileInfo(VS_CHAR * FileName,VS_UUID * FileVersion);
    VS_BOOL SRPAPI SaveFile(VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_BOOL TxtFileFlag);
    void *SRPAPI GetFileObject(VS_CHAR * FileName);
    VS_BOOL SRPAPI IsDir(VS_CHAR * FileName);
    VS_BOOL SRPAPI IsFile(VS_CHAR * FileName);
    void *SRPAPI GetDrive(VS_CHAR * FullPath);
    void *SRPAPI GetDriveEx(void *FileObj);
    VS_ULONG SRPAPI GetFileStatus(VS_CHAR * FileName);
    void SRPAPI DownLoad(VS_CHAR * FileName);
    VS_CHAR * SRPAPI GetFileName(void *FileDirObject);
    VS_BOOL SRPAPI DoScript(VS_CHAR * FileName,VS_BOOL IsUTF8);
    VS_BOOL SRPAPI DoScriptEx(VS_CHAR * ScriptInterface,VS_CHAR * FileName,VS_BOOL IsUTF8);
    void SRPAPI GetFileVersion(VS_CHAR * FileName,VS_UUID * FileVersion);
};

class ClassOfFileClass:public ClassOfSRPObject{
public:
    ClassOfFileClass();  //--Not Create a Class Object, Use WrapObject() to attach 
    ClassOfFileClass(class ClassOfSRPInterface *In_SRPInterface);  //--Create a Class Object
    ClassOfFileClass(class ClassOfSRPInterface *In_SRPInterface,void *SRPObject);  //--Create a Class Object and wrap SRPObject
    virtual VS_CHAR *SRPAPI GetSelfName();
    static class ClassOfFileClass *SRPAPI GetSRPWrap( class ClassOfSRPInterface *In_SRPInterface,void *SRPObject,VS_ULONG In_ClassLayer = 0xFFFFFFFF);
public:
    //--Attribute Get/Put Function Define
    VS_STATICID * Get_FileDataID();
    void Put_FileDataID(VS_STATICID * In_Value);

    VS_CHAR * Get_Name();
    void Put_Name(VS_CHAR * In_Value);

    VS_ULONG Get_FSize();
    void Put_FSize(VS_ULONG In_Value);

    VS_TIME * Get_FDate();
    void Put_FDate(VS_TIME * In_Value);

    VS_CHAR * Get_Url();
    void Put_Url(VS_CHAR * In_Value);


public:
    //--OutEvent Get/Put Function Define
    VSSystemEvent_EventProc Get_E_OnChange();
    void Put_E_OnChange(VSSystemEvent_EventProc In_Value);


#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--Attribute Property Define
    __declspec(property(get=Get_FileDataID, put=Put_FileDataID)) VS_STATICID FileDataID;
    __declspec(property(get=Get_Name, put=Put_Name)) VS_VSTRING Name;
    __declspec(property(get=Get_FSize, put=Put_FSize)) VS_ULONG FSize;
    __declspec(property(get=Get_FDate, put=Put_FDate)) VS_TIME FDate;
    __declspec(property(get=Get_Url, put=Put_Url)) VS_VSTRING Url;
#endif

#if( VS_OS_TYPE == VS_OS_WINDOW )
public:
    //--OutEvent Property Define
    __declspec(property(get=Get_E_OnChange, put=Put_E_OnChange)) VSSystemEvent_EventProc E_OnChange;
#endif

};


#pragma pack()

#endif
