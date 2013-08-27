// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Copyright (C) 2008 Redshift Software, Inc.
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "CIrrDeviceGLES2ForWin32.h"

#include "os.h"
	
namespace irr
{
	namespace video
	{
//		IVideoDriver* createOGLES1Driver(const SIrrlichtCreationParameters& params,
//			video::SExposedVideoData& data, io::IFileSystem* io);
		IVideoDriver* createOGLES2Driver(const SIrrlichtCreationParameters& params,
			video::SExposedVideoData& data, io::IFileSystem* io);
	}
}

namespace irr
{

//! constructor
 CIrrDeviceGLES2ForWin32:: CIrrDeviceGLES2ForWin32(const SIrrlichtCreationParameters& params)
	: CIrrDeviceStub(params)
{
//	__android_log_print(ANDROID_LOG_INFO, "Irrlicht", " CIrrDeviceGLES2ForWin32:: CIrrDeviceGLES2ForWin32");
	
	createDriver();

	if (VideoDriver)
		createGUIAndScene();
	
}

//! destructor
 CIrrDeviceGLES2ForWin32::~ CIrrDeviceGLES2ForWin32()
{
}

//! create the driver
void  CIrrDeviceGLES2ForWin32::createDriver()
{
	//__android_log_print(ANDROID_LOG_INFO, "Irrlicht", " CIrrDeviceGLES2ForWin32::createDriver");
	switch(CreationParams.DriverType)
	{
/*	case video::EDT_OGLES1:
		#ifdef _IRR_COMPILE_WITH_OGLES1_
			{
				video::SExposedVideoData data;
				VideoDriver = video::createOGLES1Driver(
					CreationParams, data, FileSystem);
			}
		#else
			//__android_log_print(ANDROID_LOG_INFO,"Irrlicht","No OpenGL-ES1 support compiled in.");
		#endif
			break;
*/
    case video::EDT_OGLES2:
        #ifdef _IRR_COMPILE_WITH_OGLES2_
            {
                video::SExposedVideoData data;
				data.OpenGLWin32.HWnd = CreationParams.WindowId;
                VideoDriver = video::createOGLES2Driver(
                    CreationParams, data, FileSystem);
            }
		#else
            //__android_log_print(ANDROID_LOG_INFO,"Irrlicht","No OpenGL-ES2 support compiled in.");
		#endif
			break;
	case video::EDT_NULL:
		// create null driver
		VideoDriver = video::createNullDriver(FileSystem, CreationParams.WindowSize);
		break;

	default:
		//__android_log_print(ANDROID_LOG_INFO,"Irrlicht","Unable to create video driver of unknown type.");
		break;
	}
}


bool  CIrrDeviceGLES2ForWin32::run()
{
    os::Timer::tick();
	return true;
}

//! Pause the current process for the minimum time allowed only to allow other processes to execute
void  CIrrDeviceGLES2ForWin32::yield()
{

}

//! Pause execution and let other processes to run for a specified amount of time.
void  CIrrDeviceGLES2ForWin32::sleep(u32 timeMs, bool pauseTimer=false)
{
}

//! sets the caption of the window
void  CIrrDeviceGLES2ForWin32::setWindowCaption(const wchar_t* text)
{
}

//! presents a surface in the client area
bool  CIrrDeviceGLES2ForWin32::present(video::IImage* surface, void* windowId, core::rect<s32>* srcClip)
{
	return true;
}

//! notifies the device that it should close itself
void  CIrrDeviceGLES2ForWin32::closeDevice()
{
}

//! \return Pointer to a list with all video modes supported
video::IVideoModeList*  CIrrDeviceGLES2ForWin32::getVideoModeList()
{
	return NULL;
}

//! returns if window is active. if not, nothing need to be drawn
bool  CIrrDeviceGLES2ForWin32::isWindowActive() const
{
	return true;
}


bool  CIrrDeviceGLES2ForWin32::isWindowFocused() const
{
	return isWindowActive();
}


bool  CIrrDeviceGLES2ForWin32::isWindowMinimized() const
{
	return !isWindowActive();
}

//! Set the current Gamma Value for the Display
bool  CIrrDeviceGLES2ForWin32::setGammaRamp( f32 red, f32 green, f32 blue, f32 brightness, f32 contrast )
{
	return false;
}

//! Get the current Gamma Value for the Display
bool  CIrrDeviceGLES2ForWin32::getGammaRamp( f32 &red, f32 &green, f32 &blue, f32 &brightness, f32 &contrast )
{
	return false;
}

//! returns color format of the window.
video::ECOLOR_FORMAT  CIrrDeviceGLES2ForWin32::getColorFormat() const
{
		return CIrrDeviceStub::getColorFormat();
}

//! Sets if the window should be resizeable in windowed mode.
void  CIrrDeviceGLES2ForWin32::setResizable(bool resize)
{
}


//! Minimizes the window
void  CIrrDeviceGLES2ForWin32::minimizeWindow()
{
}


//! Maximizes the window if possible.
void  CIrrDeviceGLES2ForWin32::maximizeWindow()
{
}


//! Restore the window to normal size if possible.
void  CIrrDeviceGLES2ForWin32::restoreWindow()
{
}

//! Activate any joysticks, and generate events for them.
bool  CIrrDeviceGLES2ForWin32::activateJoysticks(core::array<SJoystickInfo> & joystickInfo)
{
	return false;
}

}

