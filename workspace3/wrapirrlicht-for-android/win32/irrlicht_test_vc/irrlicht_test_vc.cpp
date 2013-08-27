// irrlicht_test_vc.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#include <irrlicht.h>
#include "vsopenapi.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

IrrlichtDevice *device = NULL;
IVideoDriver* driver = NULL;
ISceneManager* smgr = NULL;
IGUIEnvironment* guienv = NULL;
IAnimatedMesh* mesh = NULL;
ISceneNode* node = NULL;
IAnimatedMeshSceneNode *nodeSydney = NULL;

class ClassOfSRPInterface *pSRP = NULL;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_IRRLICHT_TEST_VC, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_IRRLICHT_TEST_VC);

	// Main message loop:
/*
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
*/
	while(1)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if(!GetMessage(&msg, NULL, 0, 0))
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}else{
			device->run();
			// SColor is the background color
			driver->beginScene(true, true, SColor(255,255,0,0));

			smgr->drawAll();
			guienv->drawAll();

			driver->endScene();
		}
	}
	return msg.wParam;
}


class ClassOfSRPEventReceiver:public irr::IEventReceiver{
public :
	virtual bool OnEvent(const SEvent& event);
};

bool ClassOfSRPEventReceiver::OnEvent(const SEvent& event)
{
	printf("%s\n",event.LogEvent.Text);
    return true;
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
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_IRRLICHT_TEST_VC);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_IRRLICHT_TEST_VC;
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

   //---create gles2 device
   RECT Rect;

   GetClientRect(hWnd,&Rect);

   //device = createDevice( video::EDT_OGLES2, dimension2d<u32>(Rect.right-Rect.left, Rect.bottom-Rect.top), 16, false, false, false, 0);
   irr::SIrrlichtCreationParameters param; 
   void *DeviceWnd;

   param.DriverType = video::EDT_OGLES2;
   param.WindowId = hWnd;
   param.WindowSize = core::dimension2d<s32>(Rect.right-Rect.left, Rect.bottom-Rect.top);
   param.Bits = 16;
   param.Fullscreen = false;
   param.Stencilbuffer = false;
   param.Vsync = false;
   param.AntiAlias = false;
   param.HighPrecisionFPU = false;
   param.EventReceiver = new class ClassOfSRPEventReceiver();
   device = irr::createDeviceEx(param);
   driver = device->getVideoDriver();

   _control87( _MCW_EM,0x801f );

   smgr = device->getSceneManager();
   guienv = device->getGUIEnvironment();

   char CurrentPath[512];
   GetCurrentDirectory(512,CurrentPath);
   device->getFileSystem()->changeWorkingDirectoryTo(CurrentPath);

   char MeshFile[512];
   sprintf(MeshFile,"%s/sydney.md2",CurrentPath);
   mesh = smgr->getMesh( MeshFile );
   if (!mesh)
   {
	   device->drop();
	   return FALSE;
   }
   nodeSydney = smgr->addAnimatedMeshSceneNode( mesh );

   if (nodeSydney)
   {
	   char TextureFile[512];

	   nodeSydney->setMaterialFlag(EMF_LIGHTING, false);
	   //--// no animation
	   //--nodeSydney->setMD2Animation(scene::EMAT_STAND);
	   // with animation
	   nodeSydney->setMD2Animation(scene::EMAT_RUN);
	   sprintf(TextureFile,"%s/sydney.bmp",CurrentPath);
	   nodeSydney->setMaterialTexture( 0, driver->getTexture(TextureFile) );
   }

   smgr->addCameraSceneNode(0, vector3df(0,10,-40), vector3df(0,5,0));

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

	switch (message) 
	{
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
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
/*			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
*/
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
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
