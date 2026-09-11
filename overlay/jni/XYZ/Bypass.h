void (*oAntiCheatReporter_StartBattle)(void *);
void iAntiCheatReporter_StartBattle(void *thiz){
    while(true){
        return;
    }
    return oAntiCheatReporter_StartBattle(thiz);
}

void (*oAntiCheatReporter_OnReleaseUseSkill)(...);
void iAntiCheatReporter_OnReleaseUseSkill(void *thiz, int skillId){
    if (thiz != nullptr){
		//LOGI("Cheat Reports : %d", thiz);
		//LOGI("Cheat Reports : %d", skillId);
        return;
    }
    oAntiCheatReporter_OnReleaseUseSkill(thiz, skillId);
}

void (*oAntiCheatReporter_OnTryUseSkill)(void *, int, Vector3);
void *iAntiCheatReporter_OnTryUseSkill(void *thiz, int skillId, Vector3 dir){
    if (thiz != nullptr){
		return 0LL;
		//LOGI("Cheat Reports2 : %d", skillId);
		//LOGI("Cheat Reports2 : %d", dir);
    }
    oAntiCheatReporter_OnTryUseSkill(thiz, skillId, dir);
}

void (*oAntiCheatReporter_OnTryUseSkill2)(void *, int, int, Vector3);
void iAntiCheatReporter_OnTryUseSkill2(void *thiz, int initSkill, int skillId, Vector3 dir){
    if (thiz != nullptr){
		//LOGI("Cheat Reports Init3 : %d", initSkill);
		//LOGI("Cheat Reports3 : %d", skillId);
        return;
    }
    oAntiCheatReporter_OnTryUseSkill2(thiz, initSkill, skillId, dir);
}

void (*oTestCase_gp_start_anti_cheat)(void *);
void iTestCase_gp_start_anti_cheat(void *thiz){
    return;
}

float (*oDeviceUtil_GetRefreshRate)(void *);
float iDeviceUtil_GetRefreshRate(void* thiz){
    if (thiz != nullptr){
        return 120;
    }
    return iDeviceUtil_GetRefreshRate(thiz);
}

bool (*oDeviceUtil_GetIsRoot)(void *);
bool iDeviceUtil_GetIsRoot(void *thiz){
    while(true){
        return false;
    }
    return oDeviceUtil_GetIsRoot(thiz);
}

void (*oDeviceUtil_OpenURL)(void *thiz, string);
void iDeviceUtil_OpenURL(void *thiz, string url){
	if (thiz != NULL){
		if (OpenLinkURL){
        	oDeviceUtil_OpenURL(thiz, "https://xyourzone.my.id/datZ/");
    	}
	}
}

void (*oAntiCheatReporter_OnRequestSkillMsg)(void *, int, Vector3);
void iAntiCheatReporter_OnRequestSkillMsg(void *thiz, int skillId, Vector3 dir){
    if (thiz != nullptr){
		//lLOGI("Cheat Reports2 : %d", skillId);
        while(true){
            return;
		}
        
        return oAntiCheatReporter_OnRequestSkillMsg(thiz, skillId, dir);
    }
}

bool (*oAntiCheatReporter_HasSkillInfo)(void *);
bool iAntiCheatReporter_HasSkillInfo(void *thiz){
    return false;
}

bool (*oAPKSignature_IsSignatureSame)(void *);
bool iAPKSignature_IsSignatureSame(void *thiz, void* out){
    return true;
}

void (*oBattleBridge_OnSignReportData)(void *thiz, uint uGuid, Vector3 pos, bool bFloor, int orderType, uint uTargetGuid, float fTime, uint uFriendGuid, bool floorEffect);
void *iBattleBridge_OnSignReportData(void *thiz, uint uGuid, Vector3 pos, bool bFloor, int orderType, uint uTargetGuid, float fTime, uint uFriendGuid, bool floorEffect){
    if (thiz != nullptr){
        return 0;
    }
}

void (*oBattleBridge_SafeSendGameReportData)(void *thiz, string*);
void *iBattleBridge_SafeSendGameReportData(void* thiz, string* uy){
    if (thiz != nullptr){
        return 0;
    }
    return iBattleBridge_SafeSendGameReportData(thiz, uy);
}

void (*oBattleBridge_SendGameReportData)(...);
void *iBattleBridge_SendGameReportData(void* thiz, string* uy){
    if (thiz != nullptr){
        return 0;
    }
    return iBattleBridge_SendGameReportData(thiz, uy);
}

void (*oBattleBridge_SendLargeGameReportData)(...);
void *iBattleBridge_SendLargeGameReportData(void* thiz, string* uy){
    if (thiz != nullptr){
        return 0;
    }
    return iBattleBridge_SendLargeGameReportData(thiz, uy);
}

void (*oAntiCheatReporter_ctor)(...);
void *iAntiCheatReporter_ctor(void *thiz){
	return 0;
}

void (*oAntiCheatReporter_cctor)(...);
void *iAntiCheatReporter_cctor(void *thiz){
	return 0;
}

void (*oCheat_Start)(...);
void *iCheat_Start(void *thiz){
	return 0;
}

void (*oCheat_Apply)(...);
void *iCheat_Apply(void *thiz){
	return 0;
}

void (*oLuaHelper_SaveActivityClientInfo)(...);
void *iLuaHelper_SaveActivityClientInfo(void *thiz, uint actvityType, uint activityId, string strData){
	return 0;
}

void (*oACInterface_GetTimeOfDay)(...);
void *iACInterface_GetTimeOfDay(string so_name, string image_name, int start_addr, int data_size){
	return 0;
}

void (*oACInterface_GetSystemTime)(...);
void *iACInterface_GetSystemTime(string so_name, string image_name){
	return 0;
}

void (*oACInterface_LoadCert)(...);
void *iACInterface_LoadCert(string streamPath, string val){
	return 0;
}

void (*oACInterface_SignErrorVerify)(...);
void *iACInterface_SignErrorVerify(...){
	return 0;
}

void (*oACInterface_GetSign)(...);
void *iACInterface_GetSign(...){
	return 0;
}

void (*oACInterface_CheckHook)(void *instance);
void *iACInterface_CheckHook(void*instance){
	return 0;
}

void (*oGameReportMgr_Report_client_match_box)(...);
void *iGameReportMgr_Report_client_match_box(...){
	while(true){
		return 0LL;
	}
}

void (*oGameReportMgr_Report_MemoryHack)(...);
void *iGameReportMgr_Report_MemoryHack(...){
	while(true){
		return 0;
	}
}

void (*oSleepingFunctionHook)(...);
void *iSleepingFunctionHook(...){
	return 0;
}

bool BypassDNS = true;

bool (*oDns_cctor)(void *unk);
bool Dns_cctor(void *unk)
{
    if (BypassDNS) {
        return true;
    }
    return oDns_cctor(unk);
}

bool (*oDns_GetHostByName_internal)(void *unk, string host, string h_name, string h_aliases, string h_addr_list);
bool Dns_GetHostByName_internal(void *unk, string host, string h_name, string h_aliases, string h_addr_list) {
    if (BypassDNS) {
    return oDns_GetHostByName_internal(unk, "ip.ml.youngjoygame.com:30220", "ip.ml.youngjoygame.com", "ip.ml.youngjoygame.com", "ip.ml.youngjoygame.com");
    }
    return oDns_GetHostByName_internal(unk, host, h_name, h_aliases, h_addr_list);
}    

bool (*oDns_GetHostByAddr_internal)(void * unk, string host, string h_name, string h_aliases, string h_addr_list);
bool Dns_GetHostByAddr_internal(void * unk, string host, string h_name, string h_aliases, string h_addr_list) {
    if (BypassDNS) {
    return oDns_GetHostByAddr_internal(unk, "ip.ml.youngjoygame.com:30220", "ip.ml.youngjoygame.com", "ip.ml.youngjoygame.com", "ip.ml.youngjoygame.com");
    }
    return oDns_GetHostByAddr_internal(unk, host, h_name, h_aliases, h_addr_list);
}    

bool (*oDns_hostent_to_IPHostEntry)(void * unk, string h_name, string h_aliases, string h_addrlist);
bool Dns_hostent_to_IPHostEntry(void * unk, string h_name, string h_aliases, string h_addrlist) {
    if (BypassDNS) {
    return oDns_hostent_to_IPHostEntry(unk, "ip.ml.youngjoygame.com", "ip.ml.youngjoygame.com", "ip.ml.youngjoygame.com");
    }
    return oDns_hostent_to_IPHostEntry(unk, h_name, h_aliases, h_addrlist);
}    

bool (*oDns_GetHostByAddressFromString)(void * unk, string address);
bool Dns_GetHostByAddressFromString(void * unk, string address) {
    if (BypassDNS) {
    return oDns_GetHostByAddressFromString(unk, "127.0.0.1");
    }
    return oDns_GetHostByAddressFromString(unk, address);
}    
   
bool (*oDns_GetHostEntry)(void * unk, string hostNameOrAddress);
bool Dns_GetHostEntry(void * unk, string hostNameOrAddress) {
    if (BypassDNS) {
    return oDns_GetHostEntry(unk, "ip.ml.youngjoygame.com:30220");
    }
    return oDns_GetHostEntry(unk, hostNameOrAddress);
}    

bool (*oDns_GetHostAddresses)(void * unk, string hostNameOrAddress);
bool Dns_GetHostAddresses(void * unk, string hostNameOrAddress) {
	LOGI("Hostname or Address: %s", &hostNameOrAddress);
    if (BypassDNS) {
    return oDns_GetHostAddresses(unk, "ip.ml.youngjoygame.com:30220");
    }
    return oDns_GetHostAddresses(unk, hostNameOrAddress);
}    
        
bool (*oDns_GetHostByName)(void * unk, string hostName);
bool Dns_GetHostByName(void * unk, string hostName) {
	if (unk != nullptr){
		LOGI("Hostname: %s", &hostName);
		oDns_GetHostByName(unk, "ip.ml.youngjoygame.com:30220");
	}
    return oDns_GetHostByName(unk, hostName);
}

void (*oDisposeServerObject)() = 0;
void DisposeServerObject(void* unk) {
    return;
}

// Hook for BattleEndReport::ReportShowEntityReportData
void (*old_ReportShowEntityReportData)(void *instance);
void ReportShowEntityReportData(void *instance) {
    if (instance != NULL) {
        // Modify some data in the instance if needed
        *(int *)((uint64_t)instance + 0x48) = 0;
    }
    return old_ReportShowEntityReportData(instance);
}

// Hook for XmlTextReaderImpl::set_DisableUndeclaredEntityCheck
void (*old_set_DisableUndeclaredEntityCheck)(void *instance, bool value);
void set_DisableUndeclaredEntityCheck(void *instance, bool value) {
    // Example: Force the check to always be enabled
    value = false;

    return old_set_DisableUndeclaredEntityCheck(instance, value);
}


void (*oSetAntiCheatReport)(void *instance, string r);
void iSetAntiCheatReport(void *instance, string r){
	if (instance != NULL){
		r = "";
	}
	return oSetAntiCheatReport(instance, r);
}

void (*oAntiCheatReporter_EndBattle)(void *);
void iAntiCheatReporter_EndBattle(void *thiz){
    return;
}

// 2.1.95 new bypass handlers
void *(*oNetworkInterface_GetAllNetworkInterfaces)();
void *iNetworkInterface_GetAllNetworkInterfaces(){
    return 0; // Return null array so VPN / network interface check stays clean
}

void *(*oACInterface_MalApp)(void *);
void *iACInterface_MalApp(void *appInfo){
    return 0;
}

void *(*oACInterface_CheckLib)(void *, uint32_t, uint32_t);
void *iACInterface_CheckLib(void *so, uint32_t offset, uint32_t size){
    return 0;
}

void *(*oACInterface_OpenLib)(int32_t, void *);
void *iACInterface_OpenLib(int32_t index, void *info){
    return 0;
}

void *(*oACInterface_MDLib)(uint32_t, void *);
void *iACInterface_MDLib(uint32_t index, void *info){
    return 0;
}
