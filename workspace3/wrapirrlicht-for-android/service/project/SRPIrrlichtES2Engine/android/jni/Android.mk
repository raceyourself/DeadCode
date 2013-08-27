LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# Here we give our module name and sourcefile(s)
LOCAL_CFLAGS += -Wno-write-strings -DENV_ANDROID
LOCAL_CPPFLAGS += -Wno-write-strings -fexceptions -DENV_ANDROID
LOCAL_LDFLAGS += -Wno-write-strings -DENV_ANDROID

#MY_PATH := ../..
LOCAL_C_INCLUDES += ../.. ../../../../../cle_files/include ../../../../../include

BASICMODULE_MODULE_CXXSRCS := ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrAnimatedMeshClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrAnimatedMeshClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrAnimatedMeshSceneNodeClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrAnimatedMeshSceneNodeClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrCameraSceneNodeClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrCameraSceneNodeClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrDeviceClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrDeviceClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrFileSystemClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrFileSystemClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrMaterialClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrMaterialClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrMeshClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrMeshClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrObjectClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrObjectClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrQ3LevelMeshClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrQ3LevelMeshClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrSceneManagerClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrSceneManagerClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrSceneNodeClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrSceneNodeClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrShaderMaterialTypeClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrShaderMaterialTypeClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrTextureClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrTextureClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrVideoDriverClass_VSBody.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_IrrVideoDriverClass_VSRegSkeleton.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2EngineBasicModule/SRPIrrlichtES2EngineBasicModule_VSMain.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPFSEngine_UUIDDef.cpp
BASICMODULE_MODULE_CXXSRCS += ../../SRPIrrlichtES2Engine_UUIDDef.cpp

LOCAL_SRC_FILES := ${BASICMODULE_MODULE_CXXSRCS}
LOCAL_LDLIBS := ../../../../../cle_files/libs/armeabi/libstarlib.a ../../../../../obj/local/armeabi/libirrlicht.a  -llog -lGLESv2 -lGLESv1_CM -ldl 

LOCAL_MODULE  := SRPIrrlichtES2EngineBasicModule

include $(BUILD_SHARED_LIBRARY) 
