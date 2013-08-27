/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Header File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#ifndef SRPFSENGINE_HEADERFILE
#define SRPFSENGINE_HEADERFILE

#include "SRPFSEngine.h"

#if( VS_OS_TYPE == VS_OS_WINDOWS )
#pragma warning (disable:4819)
#pragma warning (disable:4244)
#pragma warning (disable:4996)
#pragma warning (disable:4800)
#endif

#pragma pack(4)

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_FILETOOLCLASS                                                                    "FileToolClass"
extern VS_UUID VSOBJID_FileToolClass;
#define VSATTRDEPEND_FILETOOLCLASS(X)  {}
#define VSATTRDEPENDNUM_FILETOOLCLASS                                                              0
extern VS_INT32 SRPCALLBACK FileToolClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRNUMBER_FILETOOLCLASS                                                                 0

/*------Local Define Function */
/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_FileToolClass_Execute;
extern void SRPAPI FileToolClass_Execute(void *Object,VS_BOOL ShowMax);
typedef void (SRPAPI *FileToolClass_ExecuteProc)(void *Object,VS_BOOL ShowMax);

/*[Private Function] : Lua_Execute(true)    */
extern VS_UUID VSFUNCID_FileToolClass_Lua_Execute;
extern VS_INT32 SRPAPI FileToolClass_Lua_Execute(void);
typedef VS_INT32 (SRPAPI *FileToolClass_Lua_ExecuteProc)(void);

/*[Private Function] : 选择装载的文件名    */
extern VS_UUID VSFUNCID_FileToolClass_GetLoadFile;
extern VS_CHAR * SRPAPI FileToolClass_GetLoadFile(void *Object);
typedef VS_CHAR * (SRPAPI *FileToolClass_GetLoadFileProc)(void *Object);

/*[Private Function] : FileName=Lua_GetLoadFile()    */
extern VS_UUID VSFUNCID_FileToolClass_Lua_GetLoadFile;
extern VS_INT32 SRPAPI FileToolClass_Lua_GetLoadFile(void);
typedef VS_INT32 (SRPAPI *FileToolClass_Lua_GetLoadFileProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_FileToolClass_GetSaveFile;
extern VS_CHAR * SRPAPI FileToolClass_GetSaveFile(void *Object);
typedef VS_CHAR * (SRPAPI *FileToolClass_GetSaveFileProc)(void *Object);

/*[Private Function] : FileName=Lua_GetSaveFile()    */
extern VS_UUID VSFUNCID_FileToolClass_Lua_GetSaveFile;
extern VS_INT32 SRPAPI FileToolClass_Lua_GetSaveFile(void);
typedef VS_INT32 (SRPAPI *FileToolClass_Lua_GetSaveFileProc)(void);

struct StructOfAttachFileToolClass{
};
struct StructOfFileToolClass{
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_DIRECTORYCLASS                                                                   "DirectoryClass"
extern VS_UUID VSOBJID_DirectoryClass;
#define VSATTRDEPEND_DIRECTORYCLASS(X)  {{X[0].Type=14;X[0].Offset=0;}{X[1].Type=14;X[1].Offset=4;}{X[2].Type=51;X[2].Offset=8;}{X[3].Type=49;X[3].Offset=12;}}
#define VSATTRDEPENDNUM_DIRECTORYCLASS                                                             4
extern VS_INT32 SRPCALLBACK DirectoryClass_RequestRegisterObject( );

/*------Variable Index Define */
#define VSATTRINDEX_DIRECTORYCLASS_FILELIST                                                        0
#define VSATTRINDEX_DIRECTORYCLASS_DIRLIST                                                         1
#define VSATTRINDEX_DIRECTORYCLASS_NAME                                                            2
#define VSATTRINDEX_DIRECTORYCLASS_FDATE                                                           3
#define VSATTRNUMBER_DIRECTORYCLASS                                                                4

extern VS_INT32 SRPCALLBACK DirectoryClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK DirectoryClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachDirectoryClass{
    //----local attribute
    VS_CHAR         Name[128];                    //
    VS_TIME         FDate;                        //
};
struct StructOfDirectoryClass{
    //----local attribute
    void            *FileList;                    //
    void            *DirList;                     //
    VS_VSTRING      Name;                         //
    VS_TIME         FDate;                        //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_DRIVECLASS                                                                       "DriveClass"
extern VS_UUID VSOBJID_DriveClass;
#define VSATTRDEPEND_DRIVECLASS(X)  {{X[0].Type=14;X[0].Offset=0;}{X[1].Type=14;X[1].Offset=4;}{X[2].Type=14;X[2].Offset=8;}}
#define VSATTRDEPENDNUM_DRIVECLASS                                                                 3
extern VS_INT32 SRPCALLBACK DriveClass_RequestRegisterObject( );

/*----output event: OnRead[LParam=FileName,SParam=BinBuf;Script:(Event,FileName,BinBuf)]  Static Event */
extern VS_UUID VSOUTEVENTID_DriveClass_OnRead;
/*----output event: OnDownLoad[LParam=0/1/2/3 S=Object T = Size F = DownSize 脚本(Event,0/1/2/3,Object,Size,DownSize)]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_DriveClass_OnDownLoad;
/*----output event: OnFileChange[任何一个文件的内容发生变化，LParam=FileObject 脚本 (Event,FileName)]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_DriveClass_OnFileChange;

/*------Variable Index Define */
#define VSATTRINDEX_DRIVECLASS_LOCALBUF                                                            0
#define VSATTRINDEX_DRIVECLASS_FILELIST                                                            1
#define VSATTRINDEX_DRIVECLASS_DIRLIST                                                             2
#define VSATTRNUMBER_DRIVECLASS                                                                    3

/*------Local Define Function */
/*[Public Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_SaveFObjectData;
extern VS_BOOL SRPAPI DriveClass_SaveFObjectData(void *Object,VS_UUID ObjectID,VS_ULONG DataSize,VS_CHAR * DataBuf);
typedef VS_BOOL (SRPAPI *DriveClass_SaveFObjectDataProc)(void *Object,VS_UUID ObjectID,VS_ULONG DataSize,VS_CHAR * DataBuf);

/*[Public Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_LoadFObjectData;
extern VS_CHAR * SRPAPI DriveClass_LoadFObjectData(void *Object,VS_UUID ObjectID,VS_ULONG * DataSize);
typedef VS_CHAR * (SRPAPI *DriveClass_LoadFObjectDataProc)(void *Object,VS_UUID ObjectID,VS_ULONG * DataSize);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_Dir;
extern void SRPAPI DriveClass_Dir(void *Object,VS_CHAR * PathName);
typedef void (SRPAPI *DriveClass_DirProc)(void *Object,VS_CHAR * PathName);

/*[Private Function] : LuaC函数    */
extern VS_UUID VSFUNCID_DriveClass_Lua_Dir;
extern VS_INT32 SRPAPI DriveClass_Lua_Dir(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_DirProc)(void);

/*[Private Function] : 改变当前路径，如果没有参数，则显示当前路径    */
extern VS_UUID VSFUNCID_DriveClass_CHDir;
extern VS_BOOL SRPAPI DriveClass_CHDir(void *Object,VS_CHAR * PathName);
typedef VS_BOOL (SRPAPI *DriveClass_CHDirProc)(void *Object,VS_CHAR * PathName);

/*[Private Function] :  Lua_CD(Path)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_CD;
extern VS_INT32 SRPAPI DriveClass_Lua_CD(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_CDProc)(void);

/*[Private Function] : 当前路径下，创建目录    */
extern VS_UUID VSFUNCID_DriveClass_MKDir;
extern void *SRPAPI DriveClass_MKDir(void *Object,VS_CHAR * PathName,VS_UUID * DirObjectID);
typedef void *(SRPAPI *DriveClass_MKDirProc)(void *Object,VS_CHAR * PathName,VS_UUID * DirObjectID);

/*[Private Function] : Object=Lua_MD(DirName,DirObjectID)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_MD;
extern VS_INT32 SRPAPI DriveClass_Lua_MD(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_MDProc)(void);

/*[Private Function] : 删除目录    */
extern VS_UUID VSFUNCID_DriveClass_RMDir;
extern void SRPAPI DriveClass_RMDir(void *Object,VS_CHAR * PathName);
typedef void (SRPAPI *DriveClass_RMDirProc)(void *Object,VS_CHAR * PathName);

/*[Private Function] : LuaC函数    */
extern VS_UUID VSFUNCID_DriveClass_Lua_RD;
extern VS_INT32 SRPAPI DriveClass_Lua_RD(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_RDProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_Open;
extern VS_ULONG SRPAPI DriveClass_Open(void *Object,VS_CHAR * FileName,VS_BOOL CreateFlag,VS_UUID * FileObjectID,VS_UUID * RetFileObjectID);
typedef VS_ULONG (SRPAPI *DriveClass_OpenProc)(void *Object,VS_CHAR * FileName,VS_BOOL CreateFlag,VS_UUID * FileObjectID,VS_UUID * RetFileObjectID);

/*[Private Function] : LuaC函数    */
extern VS_UUID VSFUNCID_DriveClass_Lua_Open;
extern VS_INT32 SRPAPI DriveClass_Lua_Open(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_OpenProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_Close;
extern void SRPAPI DriveClass_Close(void *Object,VS_ULONG FHandle);
typedef void (SRPAPI *DriveClass_CloseProc)(void *Object,VS_ULONG FHandle);

/*[Private Function] : LuaC函数    */
extern VS_UUID VSFUNCID_DriveClass_Lua_Close;
extern VS_INT32 SRPAPI DriveClass_Lua_Close(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_CloseProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_Read;
extern VS_CHAR * SRPAPI DriveClass_Read(void *Object,VS_ULONG FHandle,VS_ULONG * Size);
typedef VS_CHAR * (SRPAPI *DriveClass_ReadProc)(void *Object,VS_ULONG FHandle,VS_ULONG * Size);

/*[Private Function] : size=Lua_Read(FHandle,BinBuf)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_Read;
extern VS_INT32 SRPAPI DriveClass_Lua_Read(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_ReadProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_Write;
extern void SRPAPI DriveClass_Write(void *Object,VS_ULONG FHandle,VS_CHAR * FBuf,VS_ULONG Size);
typedef void (SRPAPI *DriveClass_WriteProc)(void *Object,VS_ULONG FHandle,VS_CHAR * FBuf,VS_ULONG Size);

/*[Private Function] : Lua_Write(FHandle,BinBuf)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_Write;
extern VS_INT32 SRPAPI DriveClass_Lua_Write(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_WriteProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_Del;
extern void SRPAPI DriveClass_Del(void *Object,VS_CHAR * FileName);
typedef void (SRPAPI *DriveClass_DelProc)(void *Object,VS_CHAR * FileName);

/*[Private Function] : LuaC函数    */
extern VS_UUID VSFUNCID_DriveClass_Lua_Del;
extern VS_INT32 SRPAPI DriveClass_Lua_Del(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_DelProc)(void);

/*[Private Function] : FileName,Context = QueryFirst(Path)    */
extern VS_UUID VSFUNCID_DriveClass_QueryFirst;
extern VS_CHAR * SRPAPI DriveClass_QueryFirst(void *Object,VS_CHAR * FileName,VS_ULONG * FFindContext);
typedef VS_CHAR * (SRPAPI *DriveClass_QueryFirstProc)(void *Object,VS_CHAR * FileName,VS_ULONG * FFindContext);

/*[Private Function] : LuaC函数    */
extern VS_UUID VSFUNCID_DriveClass_Lua_QueryFirst;
extern VS_INT32 SRPAPI DriveClass_Lua_QueryFirst(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_QueryFirstProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_QueryNext;
extern VS_CHAR * SRPAPI DriveClass_QueryNext(void *Object,VS_ULONG FFindContext);
typedef VS_CHAR * (SRPAPI *DriveClass_QueryNextProc)(void *Object,VS_ULONG FFindContext);

/*[Private Function] : FileName = QueryNext(Context)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_QueryNext;
extern VS_INT32 SRPAPI DriveClass_Lua_QueryNext(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_QueryNextProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_QueryClose;
extern void SRPAPI DriveClass_QueryClose(void *Object,VS_ULONG FFindContext);
typedef void (SRPAPI *DriveClass_QueryCloseProc)(void *Object,VS_ULONG FFindContext);

/*[Private Function] : QueryClose(Context)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_QueryClose;
extern VS_INT32 SRPAPI DriveClass_Lua_QueryClose(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_QueryCloseProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_RegCallBack;
extern void SRPAPI DriveClass_RegCallBack(void *Object,VS_CHAR * FileName,void *DesObject,void *FuncAddr);
typedef void (SRPAPI *DriveClass_RegCallBackProc)(void *Object,VS_CHAR * FileName,void *DesObject,void *FuncAddr);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_UnRegCallBack;
extern void SRPAPI DriveClass_UnRegCallBack(void *Object,VS_CHAR * FileName,void *DesObject,void *FuncAddr);
typedef void (SRPAPI *DriveClass_UnRegCallBackProc)(void *Object,VS_CHAR * FileName,void *DesObject,void *FuncAddr);

/*[Private Function] : 装载磁盘文件    */
extern VS_UUID VSFUNCID_DriveClass_LoadFile;
extern void *SRPAPI DriveClass_LoadFile(void *Object,VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_UUID * FileObjectID,VS_BOOL TxtFileFlag);
typedef void *(SRPAPI *DriveClass_LoadFileProc)(void *Object,VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_UUID * FileObjectID,VS_BOOL TxtFileFlag);

/*[Private Function] : Object = Lua_LoadFile( "\\asd\\asd","c:\\XXX\\XXX.XXX","UUID",TxtFileFlag)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_LoadFile;
extern VS_INT32 SRPAPI DriveClass_Lua_LoadFile(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_LoadFileProc)(void);

/*[Private Function] : 装载磁盘文件    */
extern VS_UUID VSFUNCID_DriveClass_LoadFileEx;
extern void *SRPAPI DriveClass_LoadFileEx(void *Object,VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_UUID * FileObjectID);
typedef void *(SRPAPI *DriveClass_LoadFileExProc)(void *Object,VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_UUID * FileObjectID);

/*[Private Function] : Object = Lua_LoadFileEx( "\\asd\\asd","c:\\XXX\\XXX.XXX","UUID")    */
extern VS_UUID VSFUNCID_DriveClass_Lua_LoadFileEx;
extern VS_INT32 SRPAPI DriveClass_Lua_LoadFileEx(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_LoadFileExProc)(void);

/*[Private Function] : 从缓冲区中装载    */
extern VS_UUID VSFUNCID_DriveClass_LoadBuf;
extern void *SRPAPI DriveClass_LoadBuf(void *Object,VS_CHAR * FileName,VS_CHAR * Buf,VS_INT32 BufSize,VS_UUID * FileObjectID);
typedef void *(SRPAPI *DriveClass_LoadBufProc)(void *Object,VS_CHAR * FileName,VS_CHAR * Buf,VS_INT32 BufSize,VS_UUID * FileObjectID);

/*[Private Function] : Object=Lua_LoadBuf(FileName,BinBuf,"UUID")    */
extern VS_UUID VSFUNCID_DriveClass_Lua_LoadBuf;
extern VS_INT32 SRPAPI DriveClass_Lua_LoadBuf(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_LoadBufProc)(void);

/*[Private Function] : bool = Lua_SaveToBuf(FileName,BinBuf)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_SaveToBuf;
extern VS_INT32 SRPAPI DriveClass_Lua_SaveToBuf(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_SaveToBufProc)(void);

/*[Private Function] : 装载网络文件    */
extern VS_UUID VSFUNCID_DriveClass_LoadWebFile;
extern void *SRPAPI DriveClass_LoadWebFile(void *Object,VS_CHAR * FileName,VS_CHAR * WebFileUrl,VS_CHAR * DiskFileName,VS_UUID * FileObjectID,VS_UUID * FileVersion);
typedef void *(SRPAPI *DriveClass_LoadWebFileProc)(void *Object,VS_CHAR * FileName,VS_CHAR * WebFileUrl,VS_CHAR * DiskFileName,VS_UUID * FileObjectID,VS_UUID * FileVersion);

/*[Private Function] : Object=Lua_LoadWebFile(FileName,FileUrl,DiskFileName,FileObjectID,FileVersion)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_LoadWebFile;
extern VS_INT32 SRPAPI DriveClass_Lua_LoadWebFile(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_LoadWebFileProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_SetWebFileInfo;
extern void SRPAPI DriveClass_SetWebFileInfo(void *Object,VS_CHAR * FileName,VS_CHAR * WebFileUrl,VS_UUID * FileVersion);
typedef void (SRPAPI *DriveClass_SetWebFileInfoProc)(void *Object,VS_CHAR * FileName,VS_CHAR * WebFileUrl,VS_UUID * FileVersion);

/*[Private Function] : Lua_SetWebFileInfo(FileName,FileUrl,Version)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_SetWebFileInfo;
extern VS_INT32 SRPAPI DriveClass_Lua_SetWebFileInfo(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_SetWebFileInfoProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_GetWebFileInfo;
extern VS_CHAR * SRPAPI DriveClass_GetWebFileInfo(void *Object,VS_CHAR * FileName,VS_UUID * FileVersion);
typedef VS_CHAR * (SRPAPI *DriveClass_GetWebFileInfoProc)(void *Object,VS_CHAR * FileName,VS_UUID * FileVersion);

/*[Private Function] : FileUrl,Version=Lua_GetWebFileInfo(FileName)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_GetWebFileInfo;
extern VS_INT32 SRPAPI DriveClass_Lua_GetWebFileInfo(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_GetWebFileInfoProc)(void);

/*[Private Function] : 存储磁盘文件    */
extern VS_UUID VSFUNCID_DriveClass_SaveFile;
extern VS_BOOL SRPAPI DriveClass_SaveFile(void *Object,VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_BOOL TxtFileFlag);
typedef VS_BOOL (SRPAPI *DriveClass_SaveFileProc)(void *Object,VS_CHAR * FileName,VS_CHAR * DiskFileName,VS_BOOL TxtFileFlag);

/*[Private Function] : Lua_SaveFile(FileName,DiskFileName,TxtFileFlag)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_SaveFile;
extern VS_INT32 SRPAPI DriveClass_Lua_SaveFile(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_SaveFileProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_GetFileObject;
extern void *SRPAPI DriveClass_GetFileObject(void *Object,VS_CHAR * FileName);
typedef void *(SRPAPI *DriveClass_GetFileObjectProc)(void *Object,VS_CHAR * FileName);

/*[Private Function] : File = Lua_GetFileObject("\\adsfads\\asdfasfd")    */
extern VS_UUID VSFUNCID_DriveClass_Lua_GetFileObject;
extern VS_INT32 SRPAPI DriveClass_Lua_GetFileObject(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_GetFileObjectProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_IsDir;
extern VS_BOOL SRPAPI DriveClass_IsDir(void *Object,VS_CHAR * FileName);
typedef VS_BOOL (SRPAPI *DriveClass_IsDirProc)(void *Object,VS_CHAR * FileName);

/*[Private Function] : bool=Lua_IsDir("\\sadfsadf\\asdf")    */
extern VS_UUID VSFUNCID_DriveClass_Lua_IsDir;
extern VS_INT32 SRPAPI DriveClass_Lua_IsDir(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_IsDirProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_IsFile;
extern VS_BOOL SRPAPI DriveClass_IsFile(void *Object,VS_CHAR * FileName);
typedef VS_BOOL (SRPAPI *DriveClass_IsFileProc)(void *Object,VS_CHAR * FileName);

/*[Private Function] : bool = Lua_IsFile("safdasd\\sdfasf"}    */
extern VS_UUID VSFUNCID_DriveClass_Lua_IsFile;
extern VS_INT32 SRPAPI DriveClass_Lua_IsFile(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_IsFileProc)(void);

/*[Private Function] : 解析输入路径中的:前面的字符串,据此查找DriveClass对象    */
extern VS_UUID VSFUNCID_DriveClass_GetDrive;
extern void *SRPAPI DriveClass_GetDrive(void *Object,VS_CHAR * FullPath);
typedef void *(SRPAPI *DriveClass_GetDriveProc)(void *Object,VS_CHAR * FullPath);

/*[Private Function] : LuaC函数,Object = Lua_GetDrive(Path)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_GetDrive;
extern VS_INT32 SRPAPI DriveClass_Lua_GetDrive(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_GetDriveProc)(void);

/*[Private Function] : 输入文件对象，获取虚拟盘对象    */
extern VS_UUID VSFUNCID_DriveClass_GetDriveEx;
extern void *SRPAPI DriveClass_GetDriveEx(void *Object,void *FileObj);
typedef void *(SRPAPI *DriveClass_GetDriveExProc)(void *Object,void *FileObj);

/*[Private Function] : Object = Lua_GetDriveEx(FileObj)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_GetDriveEx;
extern VS_INT32 SRPAPI DriveClass_Lua_GetDriveEx(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_GetDriveExProc)(void);

/*[Private Function] : 函数描述    */
extern VS_UUID VSFUNCID_DriveClass_GetFileStatus;
extern VS_ULONG SRPAPI DriveClass_GetFileStatus(void *Object,VS_CHAR * FileName);
typedef VS_ULONG (SRPAPI *DriveClass_GetFileStatusProc)(void *Object,VS_CHAR * FileName);

/*[Private Function] : LuaC函数    */
extern VS_UUID VSFUNCID_DriveClass_Lua_GetFileStatus;
extern VS_INT32 SRPAPI DriveClass_Lua_GetFileStatus(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_GetFileStatusProc)(void);

/*[Private Function] : 如果文件不一致，则从服务器下载文件；若一致，该函数不操作    */
extern VS_UUID VSFUNCID_DriveClass_DownLoad;
extern void SRPAPI DriveClass_DownLoad(void *Object,VS_CHAR * FileName);
typedef void (SRPAPI *DriveClass_DownLoadProc)(void *Object,VS_CHAR * FileName);

/*[Private Function] : Lua_DownLoad(FileName)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_DownLoad;
extern VS_INT32 SRPAPI DriveClass_Lua_DownLoad(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_DownLoadProc)(void);

/*[Private Function] : 取得文件对象或者目录的全路径名称    */
extern VS_UUID VSFUNCID_DriveClass_GetFileName;
extern VS_CHAR * SRPAPI DriveClass_GetFileName(void *Object,void *FileDirObject);
typedef VS_CHAR * (SRPAPI *DriveClass_GetFileNameProc)(void *Object,void *FileDirObject);

/*[Private Function] : LuaC函数    */
extern VS_UUID VSFUNCID_DriveClass_Lua_GetFileName;
extern VS_INT32 SRPAPI DriveClass_Lua_GetFileName(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_GetFileNameProc)(void);

/*[Private Function] : 运行Lua脚本文件，可以是磁盘文件，也可以是虚拟盘文件    */
extern VS_UUID VSFUNCID_DriveClass_DoScript;
extern VS_BOOL SRPAPI DriveClass_DoScript(void *Object,VS_CHAR * FileName,VS_BOOL IsUTF8);
typedef VS_BOOL (SRPAPI *DriveClass_DoScriptProc)(void *Object,VS_CHAR * FileName,VS_BOOL IsUTF8);

/*[Private Function] : bool=Lua_DoScript(FileName,IsUTF8)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_DoScript;
extern VS_INT32 SRPAPI DriveClass_Lua_DoScript(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_DoScriptProc)(void);

/*[Private Function] : 运行脚本文件，可以是磁盘文件，也可以是虚拟盘文件    */
extern VS_UUID VSFUNCID_DriveClass_DoScriptEx;
extern VS_BOOL SRPAPI DriveClass_DoScriptEx(void *Object,VS_CHAR * ScriptInterface,VS_CHAR * FileName,VS_BOOL IsUTF8);
typedef VS_BOOL (SRPAPI *DriveClass_DoScriptExProc)(void *Object,VS_CHAR * ScriptInterface,VS_CHAR * FileName,VS_BOOL IsUTF8);

/*[Private Function] : bool=Lua_DoScriptEx(ScriptInterface,FileName,IsUTF8)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_DoScriptEx;
extern VS_INT32 SRPAPI DriveClass_Lua_DoScriptEx(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_DoScriptExProc)(void);

/*[Private Function] :     */
extern VS_UUID VSFUNCID_DriveClass_GetFileVersion;
extern void SRPAPI DriveClass_GetFileVersion(void *Object,VS_CHAR * FileName,VS_UUID * FileVersion);
typedef void (SRPAPI *DriveClass_GetFileVersionProc)(void *Object,VS_CHAR * FileName,VS_UUID * FileVersion);

/*[Private Function] : Version=Lua_GetFileVersion(FileName)    */
extern VS_UUID VSFUNCID_DriveClass_Lua_GetFileVersion;
extern VS_INT32 SRPAPI DriveClass_Lua_GetFileVersion(void);
typedef VS_INT32 (SRPAPI *DriveClass_Lua_GetFileVersionProc)(void);

extern VS_INT32 SRPCALLBACK DriveClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK DriveClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachDriveClass{
};
struct StructOfDriveClass{
    //----local attribute
    void            *LocalBuf;                    //
    void            *FileList;                    //
    void            *DirList;                     //
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_SRPFSENGINE                                                                      "SRPFSEngine"
extern VS_UUID VSOBJID_SRPFSEngine;

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define VSOBJNAME_FILECLASS                                                                        "FileClass"
extern VS_UUID VSOBJID_FileClass;
#define VSATTRDEPEND_FILECLASS(X)  {{X[0].Type=29;X[0].Offset=0;}{X[1].Type=51;X[1].Offset=16;}{X[2].Type=10;X[2].Offset=20;}{X[3].Type=49;X[3].Offset=24;}{X[4].Type=51;X[4].Offset=40;}}
#define VSATTRDEPENDNUM_FILECLASS                                                                  5
extern VS_INT32 SRPCALLBACK FileClass_RequestRegisterObject( );

/*----output event: OnChange[事件描述]  Dynamic Event*/
extern VS_UUID VSOUTEVENTID_FileClass_OnChange;

/*------Variable Index Define */
#define VSATTRINDEX_FILECLASS_FILEDATAID                                                           0
#define VSATTRINDEX_FILECLASS_NAME                                                                 1
#define VSATTRINDEX_FILECLASS_FSIZE                                                                2
#define VSATTRINDEX_FILECLASS_FDATE                                                                3
#define VSATTRINDEX_FILECLASS_URL                                                                  4
#define VSATTRNUMBER_FILECLASS                                                                     5

extern VS_INT32 SRPCALLBACK FileClass_OnSystemEvent(VS_ULONG FunctionChoice,void *EventPara);
extern VS_INT32 SRPCALLBACK FileClass_OnSystemEditEvent(VS_ULONG FunctionChoice,void *EventPara);

struct StructOfAttachFileClass{
    //----local attribute
    VS_CHAR         Name[128];                    //
    VS_ULONG        FSize;                        //
    VS_TIME         FDate;                        //
};
struct StructOfFileClass{
    //----local attribute
    VS_STATICID     FileDataID;                   //
    VS_VSTRING      Name;                         //
    VS_ULONG        FSize;                        //
    VS_TIME         FDate;                        //
    VS_VSTRING      Url;                          //变长字符串
};

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
//#define VSOBJNAME_BASICSERVICEITEM                                                                 "BasicServiceItem"
//UUID VSOBJID_BasicServiceItem;

#pragma pack()

#endif
