
#ifndef SAFE_HOOK
#define SAFE_HOOK(target, replace, backup) do { \
    if ((void *)(target) != nullptr) { \
        Tools::Hook((void *)(target), (void *)(replace), (void **)(backup)); \
    } \
} while (0)
#endif
#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <thread>
#include <pthread.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <jni.h>
#include <android/log.h>
#include <elf.h>
#include <dlfcn.h>
#include <sys/system_properties.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/native_window.h>

#include <cstdlib>
#include <cstdio>
#include <cstring>

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <dlfcn.h>

// internal module start here
#define IMGUI_DEFINE_MATH_OPERATORS

#include "imgui.h"
#include "imgui_additional.h"
#include "imgui_themes.h"
#include <android_native_app_glue.h>
#include "backends/imgui_impl_android.h"
#include "backends/imgui_impl_opengl3.h"
#include "fonts/GoogleSans.h"
#include "imgui/icon.h"

#include "KittyMemory/MemoryPatch.h"

#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "Includes/Macros.h"

#include "Tools/xDL/xdl.h"
#include "Tools/fake_dlfcn.h"
#include "Tools/Il2Cpp.h"
#include "Tools/Tools.h"

#include "XYZ/Unity/Struct/Vector3.hpp"
#include "XYZ/Unity/Struct/Vector2.h"
#include "XYZ/Unity/Struct/Rect.h"
#include "XYZ/Unity/Struct/Quaternion.h"
#include "XYZ/ConfigName.h"
#include "Config/setup.h"
#include "Config/JNIStuff.h"
#include "Config/TouchSystem.h"
#include "XYZ/IconMinimap/DrawIcon.h"
#include "Tools/Login/Login.h"
#include "XYZ/GameClass.h"
#include "XYZ/ToString.h"
#include "XYZ/SDK.h"
#include "XYZ/DrawMinimap.h"
#include "XYZ/Minimap.h"
#include "XYZ/DrawESP.h"
#include "XYZ/Bypass.h"
#include "DrawMenu.h"

#undef stderr
#undef stdout
#undef stdin

#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <thread> // Added for sleep

using std::chrono::seconds;
using std::this_thread::sleep_for;

#include "xHook/xhook.h"
#include "consolas.hpp"
#include "Render.h"

#define FindLib "libil2cpp.so"
#define FindLib "liblogic.so"
#define FindLib "libunity.so"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

bool PatchOffset(uintptr_t address, const void *buffer, size_t length) {
	unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    return mprotect((void *)(address - (address % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy((void *)address, (void *)buffer, length) != 0;
}

void detectDump() {
    std::ifstream mapsFile("/proc/self/maps");
    std::string line;

    while (std::getline(mapsFile, line)) {
        if (line.find("liblua") != std::string::npos || line.find(".lua") != std::string::npos) {
            std::cerr << "[dump detected everything is stored ." << std::endl;
            kill(getpid(), SIGKILL);
        }
    }
}


int yaserClose() {
    JavaVM* java_vm = i_App->activity->vm;
    JNIEnv* java_env = NULL;
    jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;
    jni_return = java_vm->AttachCurrentThread(&java_env, NULL);
    if (jni_return != JNI_OK)
        return -2;
    jclass native_activity_clazz = java_env->GetObjectClass(i_App->activity->clazz);
    if (native_activity_clazz == NULL)
        return -3;
    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, "AndroidThunkJava_RestartGame","()V");
    if (method_id == NULL)
        return -4;
    java_env->CallVoidMethod(i_App->activity->clazz, method_id);
    jni_return = java_vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;
    return 0;
}
bool isyaserFolderHere(const std::string& folderPath) {
    return (access(folderPath.c_str(), F_OK) == 0);
}

void YaserAntiCrack1() {
    std::string folderPath = "/storage/emulated/0/Android/data/com.guoshi.httpcanary"
    "/storage/emulated/0/Android/data/com.sniffer"
    "/storage/emulated/0/Android/data/com.guoshi.httpcanary.premium"
    "/storage/emulated/0/Android/data/com.httpcanary.pro"
    "/storage/emulated/0/Android/data/com.minhui.networkcapture"
    "/storage/emulated/0/Android/data/app.greyshirts.sslcapture"
    "/storage/emulated/0/Android/data/com.emanuelef.remote_capture"
    "/storage/emulated/0/Android/data/com.minhui.networkcapture.pro";
    if (isyaserFolderHere(folderPath)) {
        yaserClose();
    } else {
        
    }
}

bool IsVPNEnabled() {
    JNIEnv *env;
    g_vm->AttachCurrentThread(&env, 0);
    jclass ctx = env->FindClass("android/content/Context");
    jobject context = getJNIContext(env);
    jmethodID service = env->GetMethodID(ctx, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");
    jstring str = env->NewStringUTF("connectivity");
    jobject conn_service = env->CallObjectMethod(context, service, str);
    env->DeleteLocalRef(str);
    jclass connectivity = env->FindClass("android/net/ConnectivityManager");
    jclass capabils = env->FindClass("android/net/NetworkCapabilities");
    jmethodID has1 = env->GetMethodID(capabils, "hasCapability", "(I)Z");
    jmethodID has = env->GetMethodID(capabils, "hasTransport", "(I)Z");
    jmethodID getCapabil = env->GetMethodID(connectivity, "getNetworkCapabilities", "(Landroid/net/Network;)Landroid/net/NetworkCapabilities;");
    jmethodID getActive = env->GetMethodID(connectivity, "getActiveNetwork", "()Landroid/net/Network;");
    jobject activenetwork = env->CallObjectMethod(conn_service, getActive);
    jobject activecapabilities = env->CallObjectMethod(conn_service, getCapabil, activenetwork);
    jboolean hasvpn1 = env->CallBooleanMethod(activecapabilities, has, 4);
    jboolean hasvpn2 = env->CallBooleanMethod(activecapabilities, has1, 4);
    if (hasvpn1 || hasvpn2) {
        env->DeleteLocalRef(activenetwork);
        env->DeleteLocalRef(activecapabilities);
        env->DeleteLocalRef(conn_service);
        env->DeleteLocalRef(ctx);
        env->DeleteLocalRef(context);
        env->DeleteLocalRef(capabils);
        env->DeleteLocalRef(connectivity);
        return true;
    } else {
        env->DeleteLocalRef(activenetwork);
        env->DeleteLocalRef(activecapabilities);
        env->DeleteLocalRef(conn_service);
        env->DeleteLocalRef(ctx);
        env->DeleteLocalRef(context);
        env->DeleteLocalRef(capabils);
        env->DeleteLocalRef(connectivity);
        return false;
    }
}


bool FileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

void eglSwapBuffers_handler(RegisterContext * ctx, const HookEntryInfo * info)
{
    static int count = 0;
    if(count < 10){
        count++;
    }else{
        Render();
    }
}

void *bypassMemcmp(void *arg) {
    void *handle = dlopen("libc.so", RTLD_LAZY);
    if (!handle) return NULL;

    void *memcmpAddr = dlsym(handle, "memcmp");
    if (!memcmpAddr) return NULL;

    uint8_t patch[] = { 0x01, 0x00, 0xA0, 0xE3 }; // MOV R0, #1 (Always return success)
    mprotect((void *)((uintptr_t)memcmpAddr & ~0xFFF), 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC);
    memcpy(memcmpAddr, patch, sizeof(patch));
    return NULL;
}

void hideLibrary() {
    //unlink("/proc/self/maps");
    char path[64];
    sprintf(path, "/proc/%d/maps", getpid());
    unlink(path);
}

void *main_thread(void *) {
    while (!m_IL2CPP) {
        m_IL2CPP = Tools::GetBaseAddress("liblogic.so");
        sleep(1);
    }
    LOGI("Initialized Logic");
    Il2CppAttach("liblogic.so");
    sleep(5);

	hideLibrary();
	
	DobbyInstrument(dlsym(RTLD_NEXT, "eglSwapBuffers"), eglSwapBuffers_handler);
	
	Tools::Hook((void *) AntiCheatReporter_StartBattle, (void *) iAntiCheatReporter_StartBattle, (void **) &oAntiCheatReporter_StartBattle);
    SAFE_HOOK((void *) AntiCheatReporter_EndBattle, (void *) iAntiCheatReporter_EndBattle, (void **) &oAntiCheatReporter_EndBattle);
    Tools::Hook((void *) AntiCheatReporter_OnReleaseUseSkill, (void *) iAntiCheatReporter_OnReleaseUseSkill, (void **) &oAntiCheatReporter_OnReleaseUseSkill);
    Tools::Hook((void *) AntiCheatReporter_OnTryUseSkill, (void *) iAntiCheatReporter_OnTryUseSkill, (void **) &oAntiCheatReporter_OnTryUseSkill);
    Tools::Hook((void *) AntiCheatReporter_OnTryUseSkill2, (void *) iAntiCheatReporter_OnTryUseSkill2, (void **) &oAntiCheatReporter_OnTryUseSkill2);
    Tools::Hook((void *) AntiCheatReporter_OnRequestSkillMsg, (void *) iAntiCheatReporter_OnRequestSkillMsg, (void **) &oAntiCheatReporter_OnRequestSkillMsg);
    Tools::Hook((void *) AntiCheatReporter_HasSkillInfo, (void *) iAntiCheatReporter_HasSkillInfo, (void **) &oAntiCheatReporter_HasSkillInfo);
    
	Tools::Hook((void *) ShowBattleControl_SetAntiCheatReport, (void *) iSetAntiCheatReport, (void **) &oSetAntiCheatReport);
	
    pthread_t t;
    return 0;
}

void *g_Il2CppInitFunc, *g_Il2CppSymFunc;

jint (JNICALL *Real_JNI_OnLoad)(JavaVM *vm, void *reserved);
JNIEXPORT jint JNICALL Call_JNI_OnLoad(JavaVM *vm, void *reserved) {
    std::string apkPkg = getPackageName(GetJNIEnv(g_vm));
    std::string fromPath = std::string("/sdcard/Android/data/") + apkPkg.c_str() + std::string("/files/dragon2017/assets/comlibs/") + std::string(ARCH) + std::string("/libTMH.bytes");
    std::string toPath = std::string("/data/user/0/") + apkPkg.c_str() + std::string("/app_libs/libTMH.bytes");
 
    CopyFile(fromPath.c_str(), toPath.c_str());
    if (!g_Il2CppInitFunc)g_Il2CppInitFunc = dlopen(toPath.c_str(), RTLD_LAZY);
    if (!g_Il2CppInitFunc)g_Il2CppInitFunc = dlopen(fromPath.c_str(), RTLD_LAZY);
        
    if (!g_Il2CppSymFunc)g_Il2CppSymFunc = dlsym(g_Il2CppInitFunc, "JNI_OnLoad");
    
    auto AkLoad = (jint(*)(JavaVM *, void *))g_Il2CppSymFunc;
    AkLoad(vm, nullptr);
    
    return JNI_VERSION_1_6;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    g_vm = vm;
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    pthread_t t;
    pthread_create(&t, NULL, main_thread, nullptr);
	//pthread_create(&t, NULL, bypassMemcmp, NULL);
	//pthread_create(&t, nullptr, libentec, nullptr);
    return Call_JNI_OnLoad(vm, reserved);
}
