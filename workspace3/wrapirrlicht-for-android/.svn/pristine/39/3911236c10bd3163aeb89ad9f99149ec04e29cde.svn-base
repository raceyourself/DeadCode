// glesloader.cpp : Defines the entry point for the application.
//

#include "windows.h"
#include "resource.h"
#include "vsopenapi.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING]="starglesloader";								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING]="StarGLESRenderWndClass";								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

VS_CORESIMPLECONTEXT Context;
HWND hMainWnd;
class ClassOfSRPInterface *SRPInterface;
class ClassOfSRPControlInterface *ControlInterface;
void *DeviceObject;

void SetWindowWidthHeight(HWND hWnd,int Width,int Height);
VS_INT32 SRPAPI SetDeviceFocus(VS_ULONG FunctionChoice,void *EventPara)
{
	return 0;
}
VS_INT32 SRPAPI KillDeviceFocus(VS_ULONG FunctionChoice,void *EventPara)
{
	return 0;
}

VS_INT32 GLESLoader_Init(void *Object,VS_INT32 Width,VS_INT32 Height);
void GLESLoader_Run(void *Object);

VS_INT32 GLESLoader_Init(void *Object,VS_INT32 Width,VS_INT32 Height)
{
	HINSTANCE hInstance;

	hInstance = hInst;
	ControlInterface = NULL;
	// Initialize global strings
	//LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//LoadString(hInstance, IDC_GLESLOADER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, SW_SHOW) )
	{
		return 0;
	}
	SetWindowWidthHeight(hMainWnd,Width,Height);
	return (VS_INT32)hMainWnd;
}

void GLESLoader_Run(void *Object)
{
	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;
	HINSTANCE hInstance;
	
	hInstance = hInst;
	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_GLESLOADER);

	class ClassOfBasicSRPInterface *BasicSRPInterface;
	BasicSRPInterface = SRPInterface ->GetBasicInterface();
	ControlInterface = BasicSRPInterface ->GetSRPControlInterface();
	BasicSRPInterface ->Release();

	// Main message loop:
	while(1)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if(!GetMessage(&msg, NULL, 0, 0))
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}else{
			while( ControlInterface -> SRPDispatch(VS_FALSE) == VS_TRUE );
		}
	}
	return;
}

VS_BOOL StarCoreService_Init(class ClassOfStarCore *starcore)
{
	void *AtomicClass,*Init_AtomicFunction,*Run_AtomicFunction;
	class ClassOfBasicSRPInterface *BasicSRPInterface;
	
	//--init star core
	BasicSRPInterface = starcore ->GetBasicInterface();	
	SRPInterface = BasicSRPInterface ->GetSRPInterface(BasicSRPInterface->QueryActiveService(NULL),"","");
	//---Create Atomic Class, for define function, no attribute 
	AtomicClass = SRPInterface ->CreateAtomicObjectSimple("GLESRenderWindowItem","GLESRenderWindowClass",NULL,NULL,NULL);
	Init_AtomicFunction = SRPInterface ->CreateAtomicFunctionSimple(AtomicClass,"Init","VS_INT32 Init(VS_INT32 Width,VS_INT32 Height);",NULL,NULL,VS_FALSE,VS_FALSE);
	Run_AtomicFunction = SRPInterface ->CreateAtomicFunctionSimple(AtomicClass,"Run","void Run(void);",NULL,NULL,VS_FALSE,VS_FALSE);
    //---Set Function Address
	SRPInterface -> SetAtomicFunction(Init_AtomicFunction,(void *)GLESLoader_Init);
	SRPInterface -> SetAtomicFunction(Run_AtomicFunction,(void *)GLESLoader_Run);
	return VS_TRUE;
}

void StarCoreService_Term(class ClassOfStarCore *starcore)
{
	SRPInterface ->Release();
	ControlInterface ->Release();
	return;
}

BOOL WINAPI DllMain(HINSTANCE hInstDll,DWORD fdwReason,LPVOID lpReserved)
{
	switch( fdwReason ){
	case DLL_PROCESS_ATTACH :
		hInst = hInstDll;
		break;
	case DLL_THREAD_ATTACH :
		break;
	case DLL_THREAD_DETACH :
		break;
	case DLL_PROCESS_DETACH :
		break;
	}
	return VS_TRUE;
}


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_GLESLOADER);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;//(LPCSTR)IDC_GLESLOADER;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//

void SetWindowWidthHeight(HWND hWnd,int Width,int Height)
{
	VS_ULONG Style;
	RECT rc;
	int ScreenWidth,ScreenHeight,OffsetX,OffsetY,ClientWidth,ClientHeight;
	
	ClientWidth = Width;
	ClientHeight = Height;
	
	//----设置窗口的大小
	Style = GetWindowLong(hWnd,GWL_STYLE);
	rc.left = 0;
	rc.top = 0;
	rc.right = Width;
	rc.bottom = Height;
	AdjustWindowRect(&rc,Style,VS_FALSE);
	
	ScreenWidth = GetSystemMetrics( SM_CXSCREEN );
	ScreenHeight = GetSystemMetrics( SM_CYSCREEN );
	Width = rc.right - rc.left;
	Height = rc.bottom - rc.top;
	if( ScreenWidth > Width )
		OffsetX = ( ScreenWidth - Width) / 2;
	else
		OffsetX = 0;
	if( ScreenHeight > Height )
		OffsetY = ( ScreenHeight - Height) / 2;
	else
		OffsetY = 0;
	::MoveWindow( hWnd, OffsetX, OffsetY, Width, Height, VS_TRUE );
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   hMainWnd = hWnd;

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
//	VS_INT32 MouseX,MouseY;
//	static VS_BOOL MouseDownFlag = VS_FALSE;
//	POINT Point;

	switch (message) 
	{
		case WM_CREATE :
			::SetTimer(hWnd,0,100,NULL);
			break;
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
/*
		case WM_MOUSEMOVE :
			if( SRPInterface == NULL || DeviceObject == NULL || MouseDownFlag == VS_FALSE )
				break;
			MouseX = LOWORD(lParam);  
			MouseY = HIWORD(lParam);
			SRPCALL6(SRPInterface,DeviceClass_InjectMouse,DeviceObject,SRP3DMOUSE_MOVE,0,0,MouseX,MouseY);
			break;
		case WM_LBUTTONDOWN :
			if( SRPInterface == NULL || DeviceObject == NULL )
				break;
			MouseX = LOWORD(lParam);  
			MouseY = HIWORD(lParam);
			MouseDownFlag = VS_TRUE;
			SRPCALL6(SRPInterface,DeviceClass_InjectMouse,DeviceObject,SRP3DMOUSE_LBUTTONDOWN,0,0,MouseX,MouseY);
			break;
		case WM_LBUTTONUP :
			if( SRPInterface == NULL || DeviceObject == NULL )
				break;
			MouseX = LOWORD(lParam);  
			MouseY = HIWORD(lParam);
			MouseDownFlag = VS_FALSE;
			SRPCALL6(SRPInterface,DeviceClass_InjectMouse,DeviceObject,SRP3DMOUSE_LBUTTONUP,0,0,MouseX,MouseY);
			break;
		case WM_KEYDOWN :
			if( SRPInterface == NULL || DeviceObject == NULL )
				break;
			SRPCALL4(SRPInterface,DeviceClass_InjectKey,DeviceObject,SRP3DKEY_KEYDOWN,wParam,lParam);
			break;
		case WM_KEYUP :
			if( SRPInterface == NULL || DeviceObject == NULL )
				break;
			SRPCALL4(SRPInterface,DeviceClass_InjectKey,DeviceObject,SRP3DKEY_KEYUP,wParam,lParam);
			break;
		case WM_CHAR :
			if( SRPInterface == NULL || DeviceObject == NULL )
				break;
			SRPCALL4(SRPInterface,DeviceClass_InjectKey,DeviceObject,SRP3DKEY_CHAR,wParam,lParam);
			break;
*/
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			/*
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
			*/
			EndPaint(hWnd, &ps);
			break;
		case WM_TIMER :
/*			if( ControlInterface == NULL )
				break;
			while( ControlInterface -> SRPDispatch(VS_FALSE) == VS_TRUE );
*/
/*
			if( MouseDownFlag == VS_FALSE )
				break;
			GetCursorPos(&Point);
			ScreenToClient(hWnd,&Point);
			SRPCALL6(SRPInterface,DeviceClass_InjectMouse,DeviceObject,SRP3DMOUSE_MOVE,0,0,Point.x,Point.y);
*/
			break;
		case WM_ERASEBKGND :
			return 1;
		case WM_DESTROY:
			::KillTimer(hWnd,0);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
