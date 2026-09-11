//method

typedef unsigned long dword;

uintptr_t Screen_get_width() {
	return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Display", "get_systemWidth");
}

uintptr_t Screen_get_height() {
	return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Display", "get_systemHeight");
}

uintptr_t Screen_SetResolution() {
    return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", "SetResolution", 3);
}

uintptr_t Screen_get_dpi(){
	return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", "get_dpi");
}

class Screen {
    public:
    static void SetResolution(int width, int height, bool fullscreen) {
        auto _ = reinterpret_cast<void(*)(int , int , bool )>((uintptr_t)Screen_SetResolution());
        return _(width,height,fullscreen);
    }
    static int get_width() {
        auto _ = reinterpret_cast<int(*)()>((uintptr_t)Screen_get_width());
        return _();
    }
    static int get_height() {
        auto _ = reinterpret_cast<int(*)()>((uintptr_t)Screen_get_height());
        return _();
    }
	static int get_dpi() {
        auto _ = reinterpret_cast<float(*)()>((uintptr_t)Screen_get_dpi());
        return _();
    }
};

uintptr_t Camera_get_main() {
    return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "get_main");
}

// Function to replace Camera_WorldToScreenPoint
uintptr_t Camera_WorldToScreenPoint() {
    return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "WorldToScreenPoint", 1);
}

// Function to replace Camera_get_fieldOfView
uintptr_t Camera_get_fieldOfView() {
    return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "get_fieldOfView");
}

// Function to replace Camera_set_fieldOfView
uintptr_t Camera_set_fieldOfView() {
    return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Camera", "set_fieldOfView", 1);
}

//Class Transform
uintptr_t Transform_get_position(){
	return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Transform", "get_position");
}

uintptr_t Transform_get_localPosition(){
	return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Transform", "get_localPosition");
}

uintptr_t Transform_set_position(){
	return (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Transform", "set_position", 1);
}

//Class Bullet
uintptr_t Bullet_m_Id(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "Bullet", "m_Id");
}

uintptr_t Bullet_m_Target(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "Bullet", "m_Target");
}

uintptr_t Bullet_transform(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "Bullet", "transform");
}

//Class LogicPlayer
uintptr_t LogicPlayer_KillWildTimes(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicPlayer", "_KillWildTimes");
}
uintptr_t LogicPlayer_m_PlayerData(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicPlayer", "m_PlayerData");
}

#define LogicPlayer_LogicUpdate (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "LogicPlayer", "LogicUpdate", 1)
#define LogicPlayer__QuadraKillTimes (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicPlayer", "_QuadraKillTimes")

class Transform {
public:
    Vector3 get_position() {
        auto get_position = (Vector3 (*)(Transform *)) (Transform_get_position());
        return get_position(this);
    }
    Vector3 get_localPosition() {
        auto get_localPosition = (Vector3 (*)(Transform *)) (Transform_get_localPosition());
        return get_localPosition(this);
    }
	
	void set_position(Vector3 value){
		auto set_position = (void (*)(Transform *)) (Transform_set_position());
		return set_position(this);
	}
};

uintptr_t LogicBattleEndCtrl_get_logicBattleManager(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleEndCtrl","get_logicBattleManager");
}
uintptr_t LogicBattleManager_GetBattleState(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "GetBattleState");
}

uintptr_t LogicBattleManager_GetPlayerLogic() {
    return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "GetPlayerLogic", 1);
}

uintptr_t LogicBattleManager_Instan() {
    return (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "Instance");
}

uintptr_t LogicBattleManager_GetPlayerRealSelf(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "GetPlayerRealSelf");
}

uintptr_t LogicBattleManager_mState(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "m_iMemState");
}
uintptr_t BattleData_m_BattleBridge, BattleData_battleManager;
uintptr_t HookTryUseSkill2;
void loadBattleData(std::string bData) {
    if(bData == "true"){
		BattleData_m_BattleBridge = (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "BattleData", "m_BattleBridge");
        BattleData_battleManager = (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "Instance");
    }
}

uintptr_t VirtualButton_m_States(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "VirtualButton", "m_States");
}

#define ShowSelfPlayer_TryUseSkill2 (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowSelfPlayer", "TryUseSkill", 9)
#define ShowSelfPlayer_TryUseSkill (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowSelfPlayer", "TryUseSkill", 11)
#define ShowSelfPlayer_OnUpdate (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowSelfPlayer", "Unity_OnUpdate",0)

uintptr_t SystemData_GetBattlePlayerInfo() {
    return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData", "GetBattlePlayerInfo", 0);
}

uintptr_t SystemData_m_uiID() {
    return (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "SystemData", "m_uiID");
}

List<uintptr_t> *GetBattlePlayerInfo() {
    return reinterpret_cast<List<uintptr_t> *(__fastcall *)(void *)>(SystemData_GetBattlePlayerInfo())((void *)0);
}

uintptr_t RoomData_uiHeroIDChoose(){
	return (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll","", "SystemData/RoomData", "uiHeroIDChoose");
}

uintptr_t RoomData_iCertify(){
	return (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll","", "SystemData/RoomData", "iCertify");
}

uintptr_t RoomData_iCamp(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iCamp");
}

uintptr_t SystemData_RoomData_sThisLoginCountry(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll","", "SystemData/RoomData", "sThisLoginCountry");
}

uintptr_t SystemData_RoomData_country(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "country");
}

uintptr_t SystemData_RoomData_sCreateRoleCountry(){
	return (uintptr_t)Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "sThisLoginCountry");
}

uintptr_t SystemData_RoomData_sClientVersion(){
	return (uintptr_t)Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "sClientVersion");
}

uintptr_t SystemData_RoomData_uiSex(){
	return (uintptr_t)Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiSex");
}

uintptr_t SystemData_RoomData_sClientIp(){
	return (uintptr_t)Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "sClientIp");
}

uintptr_t SystemData_RoomData_iElo(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iElo");
}

uintptr_t RoomData_uiRankLevel(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiRankLevel");
}

uintptr_t RoomData_iMythPoint(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iMythPoint");
}

uintptr_t RoomData_iHistoryMaxBigRankId(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iHistoryMaxBigRankId");
}

uintptr_t RoomData_vWantSelectHero(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "vWantSelectHero");
}

uintptr_t RoomData_heroid(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "heroid");
}

uintptr_t RoomData_summonSkillId(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "summonSkillId");
}

uintptr_t RoomData_lUid(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "lUid");
}

uintptr_t RoomData_uiZoneId(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiZoneId");
}

uintptr_t RoomData_bRobot(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "bRobot");
}

uintptr_t RoomData__steamSimpleName(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_steamSimpleName");
}

uintptr_t RoomData__steamName(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_steamName");
}

uintptr_t RoomData_sName(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "_sName");
}

uintptr_t SystemData_RoomData_iMPLCertifyTime(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iMPLCertifyTime");
}

uintptr_t SystemData_RoomData_uiRoleLevel(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiRoleLevel");
}

uintptr_t SystemData_RoomData_uiBattleCount(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "uiBattleCount");
}

uintptr_t SystemData_RoomData_iRoomOrder(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "iRoomOrder");
}

uintptr_t RoomData_get_strName() {
    return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "get_strName");
}
uintptr_t RoadData_iRealRoad(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "RealRoadInfo", "iRealRoad");
}

uintptr_t RoadData_iTotalNum(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "RealRoadInfo", "iTotalNum");
}

uintptr_t RoadData_iWinNum(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "RealRoadInfo", "iWinNum");
}

uintptr_t RoadData_iRoad(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "RecentRoadInfo", "iRoad");
}
uintptr_t RoadData_vHeroIds(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "RecentRoadInfo", "vHeroIds");
}
uintptr_t RoadData_iBattleNum(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "RecentRoadInfo", "iBattleNum");
}

uintptr_t RoomData_RoadInfo(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "vCurSeasonRealRoadInfo");
}

uintptr_t RoomData_vRecentRoadInfo(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "vRecentRoadInfo");
}

uintptr_t FightPlayerData_sClientIp(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "BattlePlayerInfo", "sClientIp");
}

uintptr_t RecentRoadInfoSdp_vRecentRoadInfo(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "RecentRoadInfoSdp", "vRecentRoadInfo");
}

//-----> NEW DATA ROOM INFO <------\\

uintptr_t RoomData_vCultivateRoadShow(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", "vCultivateRoadShow");
}

uintptr_t CmdHeroCultivateRoadShow_iRoad(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "CmdHeroCultivateRoadShow", "iRoad");
}

//field

#define UiHeadInfo_LateUpdate (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "UIHeadInfo", "Update")
uintptr_t BattleBridge_ShowHeadEquip(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "ShowHeadEquip", 3);
}

// 2.1.95: bStartBattle converted to Getter method get_bStartBattle()
static inline bool BattleBridge_bStartBattle_Get(void *instance) {
    if (!instance) return false;
    static auto get_fn = (bool (*)(void *))(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "get_bStartBattle", 0));
    if (!get_fn) {
        get_fn = (bool (*)(void *))(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "Get_bStartBattle", 0));
    }
    if (get_fn) return get_fn(instance);
    return true; // Fail-open fallback
}

uintptr_t BattleBridge_bStartBattle(){
    uintptr_t offset = (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleBridge", "bStartBattle");
    return (offset != (uintptr_t)-1) ? offset : 0;
}

//--------------------------------> TEST NEW MAPHACK <--------------------------------
#define MapEntityContainer_SetMapEntityIconPos (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "MapEntityContainer", "SetMapEntityIconPos", 3)

#define BattleBridge_SetMapEntityIconPos (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SetMapEntityIconPos", 3)
#define BattleBridge_SetMapInvisibility (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SetMapInvisibility", 3)
#define BattleBridge_SetBloodInvisibility (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SetBloodInvisibility", 5)
uintptr_t BattleBridge_SynBloodAttr(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SynBloodAttr", 2);
}
uintptr_t BattleBridge_UpdateBloodPos(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "UpdateBloodPos", 2);
}

uintptr_t BattleManager_m_LocalPlayerShow(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_LocalPlayerShow");
}

#define BattleManager_m_dicPlayerShow2 (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "_dicPlayerShow")
uintptr_t BattleManager_m_ShowPlayers(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_ShowPlayers");
}

uintptr_t BattleManager_m_ShowMonsters(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_ShowMonsters");
}

uintptr_t BattleManager_m_dicPlayerShow() {
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_dicPlayerShow");
}

uintptr_t BattleManager_m_dicMonsterShow() {
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "BattleManager", "m_dicMonsterShow");
}

//Class PlayerData (retri req)
uintptr_t PlayerData__killNum(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "PlayerData", "_killNum");
}

uintptr_t PlayerData__assistNum(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "PlayerData", "_assistNum");
}

//Class ShowEntity
uintptr_t ShowEntity_m_States() {
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_States");
}

uintptr_t ShowEntity__Position(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_vCachePosition");
}

uintptr_t ShowEntity_getPosition(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", "get_Position", 0);
}

uintptr_t ShowEntity_MoveDir(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "_MoveDir");
}

uintptr_t ShowEntity_ResetLayer(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", "ResetLayer", 1);
}

uintptr_t ShowEntity_m_id(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_ID");
}

#define ShowEntity_OnUpdate (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity" , "Unity_OnUpdate", 0)
#define ShowEntity_get_InTransformation (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", "get_InTransformation")
#define ShowEntity_bShowEntityLayer (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "bShowEntityLayer")
#define ShowEntity_m_OwnSkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_OwnSkillComp")
#define ShowEntity_m_RoleName (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_RoleName")
#define ShowEntity_m_HeadIcon (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_HeadIconDefault")
// thanks for youtube.com/@cheatcode-revolution
#define ShowEntity_CanSight (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", "get_m_CanSight", 1)
//class LogicEntityBase
#define LogicEntityBase_get_m_Level (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicEntityBase", "m_Level")

uintptr_t ShowOwnSkillComp_m_SkillList(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "ShowOwnSkillComp", "m_SkillList");
}
uintptr_t ShowOwnSkillComp_skillUseTypeList(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "ShowOwnSkillComp", "skillUseTypeList");
}

uintptr_t ShowSkillData_m_TranID(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowSkillData", "m_TranID");
}

uintptr_t ShowPlayer_m_iSummonSkillId(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", "m_iSummonSkillId");
}

uintptr_t ShowPlayer_m_HeroName(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", "m_HeroName");
}
#define ShowPlayer_m_bInBattle (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", "m_bInBattle")
#define ShowPlayer_Unity_OnUpdate (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowPlayer", "Unity_OnUpdate")
#define ShowPlayer_m_QuadraKillTimes (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", "m_QuadraKillTimes")
#define ShowPlayer_m_PentaKillTimes (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", "m_PentaKillTimes")
#define ShowPlayer_m_TripleKillTimes (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowPlayer", "m_TripleKillTimes")

#define ShowEntityBase_m_dMoveSpeed (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_dMoveSpeed")
#define EntityBase_m_iType (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_iType")
uintptr_t EntityBase_m_bSameCampType(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_bSameCampType");
}

uintptr_t EntityBase_m_EntityCampType(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_EntityCampType");
}

uintptr_t EntityBase_m_bDeath(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_bDeath");
}

uintptr_t EntityBase_canSight(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "canSight");
}

uintptr_t EntityBase_m_Hp(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_Hp");
}

uintptr_t EntityBase_m_HpMax(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_HpMax");
}

uintptr_t EntityBase_m_ID(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_ID");
}

int EntityBase_m_iTypez(uintptr_t _this) {
    return *(int *) ((dword) _this + Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_ID"));
}

uintptr_t EntityBase_m_uGuid(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_uGuid");
}

uintptr_t EntityBase_m_Level(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_Level");
}

uintptr_t EntityBase_get_m_Level(){
	return (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "_level");
}
#define ShowEntityBase_m_Mp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "<m_Mp>k__BackingField")
#define m_dRunSpeed (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_dRunSpeed")
#define get_m_dAtkSpeed (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "get_m_dAtkSpeed", 0)
#define ShowEntityBase_IsCampGrassLayer (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "set_m_dAtkSpeed",1)

#define LogicFighter_m_SkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicFighter", "m_SkillComp")
#define LogicSkillComp_m_CoolDownComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicSkillComp", "m_CoolDownComp")

#define CoolDownComp_m_DicCoolInfo (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "CoolDownComp", "m_DicCoolInfo")
#define CoolDownData_GetCoolTime (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "CoolDownData", "GetCoolTime")

#define ShowWildMonster_CanSight (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowWildMonster", "CanSight", 1)
#define ShowWildMonster_OnUpdate (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowWildMonster", "OnUpdate")

//Unlock Skin
#define LogicFighter_m_SkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicFighter", "m_SkillComp")
#define LogicSkillComp_m_CoolDownComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "LogicSkillComp", "m_CoolDownComp")
#define CoolDownComp_m_DicCoolInfo (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "CoolDownComp", "m_DicCoolInfo")
#define CoolDownData_GetCoolTime (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "CoolDownData", "GetCoolTime")

//Unlock Skin -> Mencoba
//Class//Unlock Skin -> Mencoba
#define LogicFighter__GetTotalHp (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", "GetTotalHp", 0)
#define ShowEntity_get__logicFighter (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", "get_logicFighter")

#define CData_Monster_Element_m_ID (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "CData_Monster_Element", "m_ID")


#define SkillComponent_m_OwnSkillDic (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SkillComponent", "m_OwnSkillDic")
#define SkillComponent__iSkillLearn (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SkillComponent", "_iSkillLearn")
#define SkillComponent_m_ComAtk (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SkillComponent", "m_ComAtk")

#define ShowSyncFighter_get_m_AttkSpeed (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "ShowEntity", "get_m_dAtkSpeed", 0)

void *get_main() {
    return reinterpret_cast<void *(__fastcall *)()>(Camera_get_main())();
}

float get_fieldOfView() {
    return reinterpret_cast<float(__fastcall *)(void *)>(Camera_get_fieldOfView())(get_main());
}

void *set_fieldOfView(float value) {
    return reinterpret_cast<void *(__fastcall *)(void *, float)>(Camera_set_fieldOfView())(get_main(), value);
}

Vector3 WorldToScreen(Vector3 position) {
    return reinterpret_cast<Vector3(__fastcall *)(void *, Vector3)>(Camera_WorldToScreenPoint())(get_main(), position);
}

int GetBattleState() {
	auto instance = *(uintptr_t *) ((uintptr_t)LogicBattleManager_Instan());
    if (!instance) return 0;
    return reinterpret_cast<int(__fastcall *)(void*)>(LogicBattleManager_GetBattleState())((void*)instance);
}

uintptr_t GetPlayerLogic(uint id) {
    auto instance = *(uintptr_t *) ((uintptr_t)LogicBattleManager_Instan());
    if (!instance) return 0;
    return reinterpret_cast<uintptr_t(__fastcall *)(void *, uint)>(LogicBattleManager_GetPlayerLogic())((void *)instance, id);
}

int GetCoolTime(void* instance) {
    return reinterpret_cast<int(__fastcall *)(void *)>(CoolDownData_GetCoolTime)(instance);
}

void *ShowEntity_get_logicFighter(void *instance) {
    return reinterpret_cast<void*(__fastcall *)(void *)>(ShowEntity_get__logicFighter)(instance);
}

bool get_InTransformation(void* instance) {
    return reinterpret_cast<bool(__fastcall *)(void *)>(ShowEntity_get_InTransformation)(instance);
}

uintptr_t GetPlayerRealSelf() {
    void* instance;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "LogicBattleManager", "Instance", &instance);
    if (instance == NULL) return 0;
    return reinterpret_cast<uintptr_t(__fastcall *)(void *)>(LogicBattleManager_GetPlayerRealSelf())((void *)instance);
}

Vector3 ShowEntity_get_Position(void *instance) {
    return reinterpret_cast<Vector3(__fastcall *)(void *)>(ShowEntity_getPosition())(instance);
}

Vector3 ShowEntity_GetPosition(void *uiy) {
	return reinterpret_cast<Vector3(__fastcall *)(void *)>(ShowEntity_getPosition())(uiy);
}

void *iLogicBattleManager(void *instance) {
    return reinterpret_cast<void * (__fastcall *)(void *)>(LogicBattleEndCtrl_get_logicBattleManager())(instance);
}

Dictionary<void*, void*> *get_Players(){
	return reinterpret_cast<Dictionary<void*, void*> *(*)()>(BattleManager_m_dicPlayerShow())();
}

Dictionary<void*, void*> *get_Monsters(){
	return reinterpret_cast<Dictionary<void*, void*> *(*)()>(BattleManager_m_dicMonsterShow())();
}

#define AntiCheatReporter_StartBattle (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", "StartBattle")
#define AntiCheatReporter_EndBattle (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", "EndBattle")
#define AntiCheatReporter_OnReleaseUseSkill (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", "OnReleaseUseSkill", 1)
#define AntiCheatReporter_OnTryUseSkill (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", "OnTryUseSkill", 2)
#define AntiCheatReporter_OnTryUseSkill2 (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", "OnTryUseSkill", 3)

#define AntiCheatReporter_OnRequestSkillMsg (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", "OnRequestSkillMsg", 2)
#define AntiCheatReporter_HasSkillInfo (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", "HasSkillInfo")
#define AntiCheatReporter_ReportSkillInfo (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", "ReportSkillInfo", 1)

#define AntiCheatReporter_ctor (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", ".ctor")
#define AntiCheatReporter_cctor (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "AntiCheatReporter", ".cctor")

#define TestCase_gp_start_anti_cheat (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "testinternal", "TestCase", "gp_start_anti_cheat")
#define DeviceUtil_GetRefreshRate (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "DeviceUtil", "GetRefreshRate")
#define DeviceUtil_GetIsRoot (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "DeviceUtil", "GetIsRoot")
#define DeviceUtil_OpenURL (uintptr_t) Il2CppGetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Application", "OpenURL", 1)
#define Cheat_Start (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "Cheat", "Start")
#define Cheat_Apply (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "Cheat", "Apply")

#define ShowEntity_ResetLayer (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity", "ResetLayer", 1)
#define ShowEntityUpdateEyeLayer (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity","UpdateEyeLayer", 3)
#define ShowEntity_InitSetEye (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowEntity","InitSetEye", 2)

#define BattleBridge_OnSignReport (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "OnSignReportData", 8)
#define BattleBridge_SafeSendGameReportData (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SafeSendGameReportData", 1)
#define BattleBridge_SendGameReportData (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SendGameReportData", 1)
#define BattleBridge_SendLargeGameReportData (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleBridge", "SendLargeGameReportData", 1)

//CLASS APK SIGNATURE
#define APKSignature_GetAPKSignature (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "APKSignature", "GetAPKSignature", 0)
#define APKSignature_IsSignatureSame (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "APKSignature", "IsSignatureSame", 1)
#define APKSignature_SetAPKSignature (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "APKSignature", "SetAPKSignature", 1)
#define APKSignature_GetSignature (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "APKSignature", "GetSignature", 1)
#define APKSignature_GetApplicationClassName (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "APKSignature", "GetApplicationClassName", 0)

#define LuaHelper_SaveActivityClientInfo (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LuaHelper", "SaveActivityClientInfo", 3)
#define GameReportMgr_Report_client_match_box (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "GameReportMgr", "Report_client_match_box", 10)

//Class UIRankHero.ChangeShow
#define RunSpeedTest (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowSyncFighter", "<m_RunSpeed>k__BackingField")
//--------------------------------> TEST NEW ANTICHEATS <--------------------------------
//--------------------------------> TEST NEW ANTICHEATS <--------------------------------
//--------------------------------> TEST NEW ANTICHEATS <--------------------------------
#define ACInterface_GetTimeOfDay (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "GetTimeOfDay", 4)
#define ACInterface_GetSystemTime (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "GetSystemTime", 2)
#define ACInterface_EstimateGetTimeOfDay (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "EstimateGetTimeOfDay", 1)
#define ACInterface_EstimateGetSystemTime (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "EstimateGetSystemTime", 1)
#define ACInterface_LoadCert (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "LoadCert", 2)
#define ACInterface_GetSign (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "GetSign")
#define ACInterface_ValidateCer (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "ValidateCer", 1)
#define ACInterface_GetSignMapData (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "GetSignMapData")
#define ACInterface_SignErrorVerify (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "SignErrorVerify", 2)
#define ACInterface_CheckHook (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "CheckHook")
#define ACInterface_GetHeroDefaultSkinMd5 (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "GetHeroDefaultSkinMd5")

uintptr_t ShowBattleControl_SetAntiCheatReport(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowBattleControl", "SetAntiCheatReport",1);
}

uintptr_t BattleEndReport_ReportCheatAfkReportData(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleEndReport", "ReportCheatAfkReportData",0);
}
uintptr_t BattleEndReport_ReportDamageValidationData(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleEndReport", "ReportDamageValidationData",0);
}
uintptr_t BattleEndReport_ReportShowEntityReportData(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleEndReport", "ReportShowEntityReportData",0);
}
uintptr_t BattleEndReport_SendMiniMapSignReport(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleEndReport", "SendMiniMapSignReport",0);
}
uintptr_t BattleEndReport_SendReportWhenBattleEnd(){
	return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleEndReport", "SendReportWhenBattleEnd",0);
}

// Fungsi untuk mendapatkan offset dari field GameMain
uintptr_t GameMain_m_isBattleConnected() {
    return Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData", "m_isBattleConnected");
}

uintptr_t GameMain_m_bStartReconnectSwitch() {
    return Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "GameMain", "m_bStartReconnectSwitch");
}

uintptr_t GameMain_m_bStartReconnect() {
    return Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "GameMain", "m_bStartReconnect");
}

uintptr_t GameMain_m_bUdpUseEchoReSend() {
    return Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "GameMain", "m_bUdpUseEchoReSend");
}

// --- Updated 2.1.95.12053 Anti-Cheat and Getters ---
#define NetworkInterface_GetAllNetworkInterfaces (uintptr_t) Il2CppGetMethodOffset("mscorlib.dll", "System.Net.NetworkInformation", "NetworkInterface", "GetAllNetworkInterfaces", 0)
#define ACInterface_MalApp (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "MalApp", 1)
#define ACInterface_CheckLib (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "CheckLib", 3)
#define ACInterface_OpenLib (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "OpenLib", 2)
#define ACInterface_MDLib (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ACInterface", "MDLib", 2)

// Battle.EntityBase Getters
#define EntityBase_get_m_bDeath (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "get_m_bDeath", 0)
#define EntityBase_get_m_Mp (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "get_m_Mp", 0)
#define EntityBase_get_m_Level (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "get_m_Level", 0)
