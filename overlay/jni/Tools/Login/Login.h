#pragma once
#include "curl/curl.h"
#include "Tools.h"
#include "json.hpp"

using json = nlohmann::ordered_json;

std::string title, version;
std::string UUID;

static std::string slotZ = "VIP";
static std::string inVip = "100";
static std::string autoskillsZ = "1";
static std::string expired = "Permanent";
static std::string EXP = "PERMANENT";
static std::string name = "VIP User";
static std::string device = "Android";
static std::string status = "Active";
static std::string floating = "true";
static std::string battleData = "true";
static std::string clientManager = "VIP";

std::string g_Token, g_Auth;
bool bValid = false;

bool bInitDone;

namespace SignIN
{
    static bool user;
}

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;
    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

std::string Login(JavaVM *jvm, const char *user_key, bool *success) {
    if (success) *success = true;
    inVip = "100";
    autoskillsZ = "1";
    expired = "Permanent";
    EXP = "PERMANENT";
    name = "VIP User";
    status = "Active";
    battleData = "true";
    clientManager = "VIP";
    return "Login Success (Bypassed)";
    JNIEnv *env;
    jvm->AttachCurrentThread(&env, 0);
    
    auto looperClass = env->FindClass("android/os/Looper");
    auto prepareMethod = env->GetStaticMethodID(looperClass, "prepare", "()V");
    env->CallStaticVoidMethod(looperClass, prepareMethod);
    
    jclass activityThreadClass = env->FindClass("android/app/ActivityThread");
    jfieldID sCurrentActivityThreadField = env->GetStaticFieldID(activityThreadClass, "sCurrentActivityThread", "Landroid/app/ActivityThread;");
    jobject sCurrentActivityThread = env->GetStaticObjectField(activityThreadClass, sCurrentActivityThreadField);
    
    jfieldID mInitialApplicationField = env->GetFieldID(activityThreadClass, "mInitialApplication", "Landroid/app/Application;");
    jobject mInitialApplication = env->GetObjectField(sCurrentActivityThread, mInitialApplicationField);
    
    std::string hwid = user_key;
    hwid += GetAndroidID(env, mInitialApplication);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
	hwid += GetDeviceManufacturer(env);
	hwid += GetDeviceSerial(env);
	hwid += GetDeviceFingerPrint(env);
	hwid += GetSDKVersion(env);
	//hwid += GetDeviceVersionRelease(env);
	//hwid += GetDeviceVersionIncremental(env);
	hwid += GetDeviceID(env);
	
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
    jvm->DetachCurrentThread();
    std::string errMsg;
    
    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;
    
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    
    if (curl) {
        std::string bangrendi = "https://t0pgamemurah.xyz/freeKey/freeKey.php";
        //dtd::string bangrendi = bangrendi;      
        curl_easy_setopt(curl, CURLOPT_URL ,bangrendi.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        headers = curl_slist_append(headers, "Charset: UTF-8");
		headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Mobile Safari/537.36");
				
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        //char data[4096];
        
        //sprintf(data, "game=MLBB&user_key=%s&serial=%s", user_key, UUID.c_str());
		std::string data = "game=MLBB";
		data += "&user_key=" + std::string(user_key);
		data += "&serial=" + UUID;
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[std::string("status")] == true) {
                    std::string token = result[std::string("data")][std::string("token")].get<std::string>();
                    time_t rng = result[std::string("data")][std::string("rng")].get<time_t>();
					/*auto EXPIRED = std::string{"EXP"};
					auto iniVip = std::string{"isVip"};
					auto slot = std::string{"device"};
					*/
					//autoskillsZ = result[std::string("data")][std::string("AutoSkills")].get<std::string>();
					
					slotZ = result[std::string("data")][std::string("device")].get<std::string>();
					expired = result[std::string("data")][std::string("EXP_MOD")].get<std::string>();
					inVip = result[std::string("data")][std::string("iniVip")].get<std::string>();
					autoskillsZ = result[std::string("data")][std::string("AutoSkills")].get<std::string>();
					clientManager = result[std::string("data")][std::string("client")].get<std::string>();
					
                    battleData = "true";
                    if (rng + 30 > time(0)) {
                        std::string auth = "MLBB";
                        auth += std::string("-");
                        auth += user_key;
                        auth += std::string("-");
                        auth += UUID;
                        auth += std::string("-"); 
                        auth += std::string("Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E");
                        std::string outputAuth = Tools::CalcMD5(auth);
                        g_Token = token;
                        g_Auth = outputAuth;
                        
                        *success = g_Token == g_Auth;
                        if (success) {
                            pthread_t t;
                        }
                    }
                } else {
					*success = false;
                    errMsg = result[std::string("reason")].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = "{";
                errMsg += e.what();
                errMsg += "}\n{";
                errMsg += chunk.memory;
                errMsg += "}";
            }
        } else {
			*success = false;
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    return errMsg;
}

static size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *stream) {
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

bool download_file(std::string url,std::string path){
	curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    if (curl) {   
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    
    FILE *file = fopen(path.c_str(), "wb");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    
    CURLcode result = curl_easy_perform(curl);
    
    fclose(file);
    curl_easy_cleanup(curl);

    if (result == CURLE_OK) {
      return true;
    } else {
      
        return false;
    }
    
    return false;
  }

  return false;
  curl_global_cleanup();
}





