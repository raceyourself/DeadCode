cd ..
rm -rf obj
cd jni
ndk-build
cd ..

cd service/project/SRPIrrlichtES2Engine/android
rm -rf libs
rm -rf obj
cd jni
ndk-build
cd ..
#------------
cp libs/armeabi/libSRPIrrlichtES2EngineBasicModule.so ../../../win32/SRPIrrlichtES2Engine/SRPIrrlichtES2EngineBasicModule_android.so

cd ../../../../android
