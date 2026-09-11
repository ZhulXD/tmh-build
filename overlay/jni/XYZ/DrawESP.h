#pragma once

bool isOutsideScreen(ImVec2 pos, ImVec2 screen) {
    if (pos.y < 0) {
        return true;
    }
    if (pos.x > screen.x) {
        return true;
    }
    if (pos.y > screen.y) {
        return true;
    }
    return pos.x < 0;
}

ImVec2 pushToScreenBorder(ImVec2 Pos, ImVec2 screen, int offset) {
    int x = (int) Pos.x;
    int y = (int) Pos.y;
    if (Pos.y < 0) {
        // top
        y = -offset;
    }
    if (Pos.x > screen.x) {
        // right
        x = (int) screen.x + offset;
    }
    if (Pos.y > screen.y) {
        // bottom
        y = (int) screen.y + offset;
    }
    if (Pos.x < 0) {
        // left
        x = -offset;
    }
    return ImVec2(x, y);
}

void DrawCircleHealth(ImVec2 position, int health, int max_health, float radius) {
    float a_max = ((3.14159265359f * 2.0f));
    ImU32 healthColor = IM_COL32(45, 180, 45, 255);
    if (health <= (max_health * 0.6)) {
        healthColor = IM_COL32(180, 180, 45, 255);
    }
    if (health < (max_health * 0.3)) {
        healthColor = IM_COL32(180, 45, 45, 255);
    }
    ImGui::GetForegroundDrawList()->PathArcTo(position, radius, (-(a_max / 4.0f)) + (a_max / max_health) * (max_health - health), a_max - (a_max / 4.0f));
    ImGui::GetForegroundDrawList()->PathStroke(healthColor, ImDrawFlags_None, 4);
}

//TEST NEW DRONE VIEW
/*
uintptr_t Offsets_ResetCameraParm;
static void *ResetCameraParm() {
    return ((void *(*)(void *))(Offsets_ResetCameraParm))(NULL);  //void ResetCameraParm
}

void (*oSetCameraParam)(void *instance, Vector3 offsetPt, Quaternion qua, Transform tarObj, bool bLerp);
void SetCameraParam(void *ins, Vector3 offsetPt, Quaternion qua, Transform tarObj, bool bLerp) {
    Vector3 baruNich = offsetPt;
    if (sliderValue > 0) {   
        if (offsetPt.x <= 0.0)
            baruNich.x = offsetPt.x + (float) sliderValue * -0.234;
        else
            baruNich.x = offsetPt.x + (float) sliderValue * 0.234;
        baruNich.y = offsetPt.y + (float) sliderValue * -0.307;
        if (offsetPt.z <= 0.0)
            baruNich.z = offsetPt.z + (float) sliderValue * -0.235;
        else
            baruNich.z = offsetPt.z + (float) sliderValue * 0.235;
    }  
oSetCameraParam(ins, baruNich, qua, tarObj, bLerp);
}*/
void DroneView() {
    if (GetFieldOfView == 0) {
        GetFieldOfView = get_fieldOfView();
    }
    if (SetFieldOfView > 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView + SetFieldOfView);
    }
    if (SetFieldOfView == 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView);
    }
}

bool (*s_Emblem2)(void* _this);
bool s_Emblem(void* _this) {
    if (Config.Visual.UnlockEmblem) {
        return true;
    }
    return s_Emblem2(_this);
}

void (*s_Spell2)(void *instance, int Spelll);
void s_Spell(void *instance, int Spelll) {
    if (instance != nullptr) {
        if (Config.Visual.UnlockSpell) {
            return;
        }
    }
     s_Spell2(instance, Spelll);
}

#define DefineHook(RET, NAME, ARGS) \
    RET (*o ## NAME) ARGS; \
    RET NAME ARGS
    
class FPSCounter {
protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    long m_fpsinterval;

public:
    FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
    }

    void update() {
        m_fpscount++;

        if (m_fpsinterval < time(0)) {
            m_fps = m_fpscount;

            m_fpscount = 0;
            m_fpsinterval = time(0) + 0;
        }
    }

    unsigned int get() const {
        return m_fps;
    }
} fps;

void (*oIsCampGrassLayer)(void *, double);
void IsCampGrassLayer(void *instance, double dmgValue){
	if (instance != nullptr){
		if (Config.Visual.NoGrass){
			dmgValue = 1000;
			dmgValue == 9999;
		}
	}
	oIsCampGrassLayer(instance, dmgValue);
}

void (*orig_ShowEntity__OnUpdate)(ShowEntity *showEntity);
void _ShowEntity__OnUpdate(ShowEntity *showEntity) {
    if (showEntity != nullptr){
        if (Config.Visual.MapHackIcon2) {
			*(bool *) (showEntity + Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_bUnityMinimapVisible")) = Config.Visual.MapHackIcon2;
        }
    }
    orig_ShowEntity__OnUpdate(showEntity);
}

void (*orig_ShowPlayer_Unity_OnUpdate)(void* thisz);
void _ShowPlayer_Unity_OnUpdate(void* thisz){
	if (thisz != NULL){
		*(int *) ((uintptr_t) thisz + ShowPlayer_m_QuadraKillTimes) = 1234;
		*(int *) ((uintptr_t) thisz + ShowPlayer_m_PentaKillTimes) = 1234;
		*(int *) ((uintptr_t) thisz + ShowPlayer_m_TripleKillTimes) = 1234;
	}
	orig_ShowPlayer_Unity_OnUpdate(thisz);
}

void (*oLogicPlayer_Update)(void* thisz, int status);
void LogicPlayer_Update(void* thisz, int status){
	if (thisz != NULL){
		if(UpdateManiacStatus){
			*(int *) ((uintptr_t) thisz + LogicPlayer__QuadraKillTimes) = 1234;
		}
	}
	oLogicPlayer_Update(thisz, status);
}

void (*set_QuadraKillTimes)(void* thisz, int status);
void oset_QuadraKillTimes(void* thisz, int status){
	if (thisz != NULL){
		if (UpdateManiacStatus){
			oset_QuadraKillTimes(thisz, 1234);
		}
	}
	set_QuadraKillTimes(thisz, status);
}

double (*orig_get_m_AttkSpeed)(void* thiz);
double get_m_AttkSpeed(void* thiz){
	if (thiz != NULL){
		if (UpdateManiacStatus){
			return 123456;
		}
	}
}

DefineHook(void, UpdateMapHack, (void * pThis)) {
    //AimEnemy = GetEnemyPosAimPredict(pThis);
    if (pThis != NULL) {
        void *BattleBridge_Instance, *BattleManager_Instance;
        Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleData", "m_BattleBridge", &BattleBridge_Instance);
        if (!BattleBridge_Instance) {
            static auto get_ui = (void *(*)())(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleData", "get_m_TinyBattleUI", 0));
            if (get_ui) BattleBridge_Instance = get_ui();
        }
        if (BattleBridge_Instance) {
            Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
            if (BattleManager_Instance) {
                auto m_ShowPlayers = *(List<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers());
                if (m_ShowPlayers) {
                    for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
                        auto Pawn = m_ShowPlayers->getItems()[i];               
                        if (!Pawn) continue;
                        auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType());
                        if (m_bSameCampType) continue;
                        auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath());
                        if (m_bDeath) continue;
                        auto canSight = *(bool *) ((uintptr_t)Pawn + EntityBase_canSight());
                        if (canSight) continue;
                        auto m_uGuid = *(int *) ((uintptr_t)Pawn + EntityBase_m_uGuid());
                        auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position());
                        auto *m_HeadIcon = *(String **) ((uintptr_t) Pawn + ShowEntity_m_HeadIcon);
						auto bShowEntityLayer = *(bool *) ((uintptr_t)Pawn + ShowEntity_bShowEntityLayer);
						
						if (Config.Visual.MapHackIcon2){
							auto CanSightMapHack = (void (*)(void *, Vector3)) (ShowEntity_CanSight);
							CanSightMapHack(BattleBridge_Instance, _Position);
						}
						
                        if (Config.Visual.MaphackIcon) {
                            auto SetMapEntityIconPos = (void (*)(void *, Vector3, bool, bool)) (BattleBridge_SetMapEntityIconPos);
                            //auto SetMapInvisibility = (void (*)(void *, bool, bool, bool)) (BattleBridge_SetMapInvisibility);                            
                            //SetMapInvisibility(BattleBridge_Instance, bShowEntityLayer, true, m_bDeath);
                            SetMapEntityIconPos(BattleBridge_Instance, _Position,m_uGuid, true);
							
                        }
                        
                        if (Config.Visual.HealthBar) {
                            auto SetBloodInvisibility = (void (*)(void *, int, bool, bool, bool, int)) (BattleBridge_SetBloodInvisibility);
                            auto SynBloodAttr = (void (*)(void *, void *, bool)) (BattleBridge_SynBloodAttr());
                            auto UpdateBloodPos = (void (*)(void *, void *, bool)) (BattleBridge_UpdateBloodPos());
                            
                            SetBloodInvisibility(BattleBridge_Instance, m_uGuid, true, m_bDeath, true, 0);
                            SynBloodAttr(BattleBridge_Instance, Pawn, true);
                            UpdateBloodPos(BattleBridge_Instance, Pawn, true);
                        }
                        
                        if (Config.Visual.HeadIcon) {
                            auto BattleBridge__ShowHeadEquip = (void (*)(void *, int, String*)) (BattleBridge_ShowHeadEquip());
                            BattleBridge__ShowHeadEquip(BattleBridge_Instance, m_uGuid, m_HeadIcon);
                        }
						
						if (Config.Visual.MapHackIcon3){
                            auto ResetLayer = (void (*)(void *, bool)) (ShowEntity_ResetLayer);
                            auto EyeLayer = (void (*)(void *, bool, bool, bool)) (ShowEntityUpdateEyeLayer);
                            ResetLayer(Pawn, true);
                            EyeLayer(Pawn, true, true, true);
                        }
                    }
                }
                List<void **> *m_ShowMonster = *(List<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowMonsters());
                if (m_ShowMonster) {
                    for (int i = 0; i < m_ShowMonster->getSize(); i++) {
                        auto Pawn = m_ShowMonster->getItems()[i];
                        if (!Pawn) continue;
                        auto m_ID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID());
                        if (MonsterToString(m_ID) == "") continue;
                        auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType());
                        if (m_bSameCampType) continue;
                        auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath());
                        if (m_bDeath) continue;
                        auto canSight = *(bool *) ((uintptr_t)Pawn + EntityBase_canSight());
                        if (canSight) continue;
                        auto m_uGuid = *(int *) ((uintptr_t)Pawn + EntityBase_m_uGuid());
                        auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position());
                        auto *m_HeadIcon = *(String **) ((uintptr_t) Pawn + ShowEntity_m_HeadIcon);
                        
                        if (Config.Visual.MonsterIcon) {
                            auto SetMapEntityIconPos = (void (*)(void *, Vector3, int, bool)) (BattleBridge_SetMapEntityIconPos);
                            auto SetMapInvisibility = (void (*)(void *, int, bool, bool)) (BattleBridge_SetMapInvisibility);                            
                            SetMapInvisibility(BattleBridge_Instance, m_uGuid, true, m_bDeath);
                            SetMapEntityIconPos(BattleBridge_Instance, _Position, m_uGuid, true);
                        }
                        
                        if (Config.Visual.MonsterHealth) {
                            auto SetBloodInvisibility = (void (*)(void *, int, bool, bool, bool, int)) (BattleBridge_SetBloodInvisibility);
                            auto SynBloodAttr = (void (*)(void *, void *, bool)) (BattleBridge_SynBloodAttr());
                            auto UpdateBloodPos = (void (*)(void *, void *, bool)) (BattleBridge_UpdateBloodPos());
                            
                            SetBloodInvisibility(BattleBridge_Instance, m_uGuid, true, m_bDeath, true, 0);
                            SynBloodAttr(BattleBridge_Instance, Pawn, true);
                            UpdateBloodPos(BattleBridge_Instance, Pawn, true);
                        }
                        
                        if (Config.Visual.MonsterBody) {
                            auto ShowWildMonster__CanSight = (bool (*)(void*, bool)) (ShowEntity_CanSight);
                            ShowWildMonster__CanSight(Pawn, true);
                        }
                        
                        if (Config.Visual.ShowJungle){
                            auto ResetLayer = (void (*)(void *, bool)) (ShowEntity_ResetLayer);
                            auto EyeLayer = (void (*)(void *, bool, bool, bool)) (ShowEntityUpdateEyeLayer);
                            ResetLayer(Pawn, true);
                            EyeLayer(Pawn, true, true, true);
                        }
                        
                        if (Config.Visual.ShowMonsterTest){
                            auto InitSetEye = (void(*)(void*,bool, bool)) (ShowEntity_InitSetEye);
                            InitSetEye(Pawn, true, true);
                        }
                    }
                }
                
            }
        }
    }
    oUpdateMapHack(pThis);
}

int32_t ToColor(float *col) {
    return ImGui::ColorConvertFloat4ToU32(*(ImVec4 *) (col));
}

bool bMonster(int iValue) {
    return std::find(std::begin(ListMonsterId), std::end(ListMonsterId), iValue) != std::end(ListMonsterId);
}

static float lineThickness = 1.0f;
static ImVec4 lineColor = ImVec4(0.9f, 0.9f, 0.98f, 1.0f); // RGBA normalized (0.0 - 1.0)
static ImVec4 textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // RGBA normalized (0.0 - 1.0)
static ImVec4 healthBarColor = ImVec4(0.88f, 0.0f, 0.0f, 1.0f);  // RGBA normalized (0.0 - 1.0)
static ImVec4 borderColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);      // Border color

ImVec2 getPosVec2(Vector3 _Position, int screenWidth, int screenHeight) {
    auto RootPosW2S = WorldToScreen(_Position);
    if (RootPosW2S.z > 0) {
        return ImVec2(RootPosW2S.x, screenHeight - RootPosW2S.y);
    }
    return ImVec2(screenWidth - RootPosW2S.x, RootPosW2S.y);
}

struct CooldownValues {
    int skillCount;
    int skill1;
    int skill2;
    int skill3;
    int skill4;
    int spell;
};

CooldownValues getPlayerCoolDown(int keys, uintptr_t values) {
    auto logicFighter = GetPlayerLogic((uint)keys);
    if (!logicFighter) return {0, 0, 0, 0, 0, 0};
    auto m_SkillComp = *(uintptr_t *) ((uintptr_t)logicFighter + LogicFighter_m_SkillComp);
    if (!m_SkillComp) return {0, 0, 0, 0, 0, 0};
    auto m_CoolDownComp = *(uintptr_t *) ((uintptr_t)m_SkillComp + LogicSkillComp_m_CoolDownComp);
    if (!m_CoolDownComp) return {0, 0, 0, 0, 0, 0};
    auto m_OwnSkillComp = *(uintptr_t *) ((uintptr_t)values + ShowEntity_m_OwnSkillComp);
    if (!m_OwnSkillComp) return {0, 0, 0, 0, 0, 0};
    int skillCount = 0, skill1 = 0, skill2 = 0, skill3 = 0, skill4 = 0, spell = 0;

    Dictionary<int, List<int> *> *skillUseTypeList = *(Dictionary<int, List<int> *> **) ((uintptr_t)m_OwnSkillComp + ShowOwnSkillComp_skillUseTypeList());
    if (!skillUseTypeList) return {0, 0, 0, 0, 0, 0};
    for (int v = 0; v < skillUseTypeList->getNumKeys(); v++) {
        auto keysskillUseType = skillUseTypeList->getKeys()[v];
        auto valuesskillUseType = skillUseTypeList->getValues()[v];
        if (!keysskillUseType) continue;
        if (keysskillUseType != 1) continue;
        skillCount = valuesskillUseType->getSize();
        List<uintptr_t> *m_SkillList = *(List<uintptr_t> **) ((uintptr_t)m_OwnSkillComp + ShowOwnSkillComp_m_SkillList());
        if (!m_SkillList) return {0, 0, 0, 0, 0, 0};
        for (int i = 0; i < 5; i++) {
            auto p_SkillList = m_SkillList->getItems()[i];
            if (!p_SkillList) continue;
            auto m_TranID = *(int *) ((uintptr_t)p_SkillList + ShowSkillData_m_TranID());
            auto m_DicCoolInfo = *(Dictionary<int, uintptr_t> **) ((uintptr_t)m_CoolDownComp + CoolDownComp_m_DicCoolInfo);
            if (!m_DicCoolInfo) continue;
            for (int l = 0; l < m_DicCoolInfo->getNumKeys(); l++) {
                auto keysCool = m_DicCoolInfo->getKeys()[l];
                auto valuesCool = m_DicCoolInfo->getValues()[l];
                if (!keysCool || !valuesCool) continue;
                auto m_iSummonSkillId = *(int *) ((uintptr_t)values + ShowPlayer_m_iSummonSkillId());
                int coolTime = GetCoolTime((void*)valuesCool) / 1000;
                if (keysCool == m_iSummonSkillId) spell = coolTime;
                if ((int)m_TranID != keysCool) continue;
                if (i == 1) skill1 = coolTime;
                if (i == 2) skill2 = coolTime;
                if (i == 3) skill3 = coolTime;
                if (i == 4) skill4 = coolTime;
            }
        }
    }
    return {skillCount, skill1, skill2, skill3, skill4, spell};
}

void NewDrawESP(ImDrawList *draw, float screenWidth, float screenHeight) {
	/*
	if (g_Token.empty())
    	return;
		
	if (g_Auth.empty())
        return;
		
	if (g_Token != g_Auth)
        return;
	*/
    if (Config.ESP.FPS) {
        std::string sFPS = "FPS: ";
        sFPS += std::to_string(fps.get());
        auto textSize = ImGui::CalcTextSize(sFPS.c_str(), 0, ((float) screenHeight / 39.0f));
        draw->AddText(NULL, ((float) screenHeight / 39.0f), {(float)(screenWidth / 4.0f) - (textSize.x / 2), (float)(screenHeight - screenHeight) + (float)(screenHeight / 8.7f)}, IM_COL32(255, 255, 255, 255), sFPS.c_str());
        draw->AddText(NULL, ((float) screenHeight / 39.0f), {(float)(screenWidth / 4.0f) - (textSize.x / 2), (float)(screenHeight - screenHeight) + (float)(screenHeight / 8.7f)}, IM_COL32(10, 255, 202, 255), sFPS.c_str());
    }
    fps.update();
    
    auto m_BattleBridge = *(uintptr_t *) ((uintptr_t)BattleData_m_BattleBridge);
    if (!m_BattleBridge) {
        static auto get_ui = (void *(*)())(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleData", "get_m_TinyBattleUI", 0));
        if (get_ui) m_BattleBridge = (uintptr_t)get_ui();
    }
    if (!m_BattleBridge) return;
    auto bStartBattle = BattleBridge_bStartBattle_Get((void *)m_BattleBridge);
    if (!bStartBattle) return;
    DroneView();
    
    if (Config.MinimapIcon) {
        if (!Config.HideLine)
            draw->AddRect(ImVec2(StartPos.x, StartPos.y), ImVec2(StartPos.x + MapSize, StartPos.y + MapSize), IM_COL32(255, 255, 255, 255));
    }
    
    auto battleManager = *(uintptr_t *) ((uintptr_t)BattleData_battleManager);
    if (!battleManager) return;
    /*self*/
    auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)battleManager + BattleManager_m_LocalPlayerShow());
    if (!m_LocalPlayerShow) return;
    auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position());
    auto selfPosVec2 = getPosVec2(selfPos, screenWidth, screenHeight);
    /*monster*/
    auto m_dicMonsterShow = *(Dictionary<int, uintptr_t> **) ((uintptr_t)battleManager + BattleManager_m_dicMonsterShow());
    if (!m_dicMonsterShow) return;
    for (int i = 0; i < m_dicMonsterShow->getNumKeys(); i++) {
        auto keys = m_dicMonsterShow->getKeys()[i];
        auto values = m_dicMonsterShow->getValues()[i];
        if (!keys || !values) continue;
        auto m_ID = *(int *) ((uintptr_t)values + EntityBase_m_ID());
		auto new_mID = *(int *) ((uintptr_t)values + ShowEntity_m_id());
        if (!bMonster(new_mID)) continue;
        if (MonsterToString(new_mID) == "") continue;
        auto m_bDeath = *(bool *) ((uintptr_t)values + EntityBase_m_bDeath());
        if (m_bDeath) continue;
        auto m_bSameCampType = *(bool *) ((uintptr_t)values + EntityBase_m_bSameCampType());
        if (m_bSameCampType) continue;
        auto bShowEntityLayer = *(bool *) ((uintptr_t)values + ShowEntity_bShowEntityLayer);
        auto m_Hp = *(int *) ((uintptr_t)values + EntityBase_m_Hp());
        auto m_HpMax = *(int *) ((uintptr_t)values + EntityBase_m_HpMax());
        //if (bShowEntityLayer && m_Hp != m_HpMax) continue;
        auto _Position = *(Vector3 *) ((uintptr_t)values + ShowEntity__Position());
        auto rootPosVec2 = getPosVec2(_Position, screenWidth, screenHeight);
        float fDistance = Vector3::Distance(selfPos, _Position);
		float PerHP = m_Hp * 100 / m_HpMax;
		
        if (!m_bDeath && Config.ESP.Monster.Rounded) {
            draw->AddCircleFilled(rootPosVec2, 10, IM_COL32(255, 255, 255, 255));
        }
		/*
		if (Config.m_IDConf) {
            std::string mConfigi = to_string(new_mID);
            auto textSize = ImGui::CalcTextSize(mConfigi.c_str(), 0, 20);
            draw->AddText(NULL, 22, {rootPosVec2.x - (textSize.x / 2), rootPosVec2.y + 40}, IM_COL32(255, 255, 255, 255), mConfigi.c_str());
        }
        */
        if (!m_bDeath && Config.ESP.Monster.Name) {
            std::string strName = MonsterToString(m_ID);
            auto textSize = ImGui::CalcTextSize(strName.c_str(), 0, ((float) screenHeight / 39.0f));
            draw->AddText(NULL, ((float) screenHeight / 39.0f), {rootPosVec2.x - (textSize.x / 2), rootPosVec2.y + 25}, IM_COL32(255, 255, 255, 255), strName.c_str());
        }
        
        if (Config.ESP.Monster.Health) {
            auto LineHealthStart = ImVec2(rootPosVec2.x + 40, rootPosVec2.y - 30);
            auto LineHealthEnd = ImVec2(LineHealthStart.x + 160, LineHealthStart.y);
            auto HealthStart = ImVec2(LineHealthStart.x, LineHealthStart.y - 20);
            auto HealthEnd = ImVec2(LineHealthEnd.x, LineHealthEnd.y - 5);
            float healthWidth = abs(HealthEnd.x - HealthStart.x);
            float PercentHP = ((float)m_Hp * healthWidth) / (float)m_HpMax;
            draw->AddLine(rootPosVec2, LineHealthStart, IM_COL32(255, 255, 255, 255));
            draw->AddLine(LineHealthStart, LineHealthEnd, IM_COL32(255, 255, 255, 155));
            draw->AddRectFilled(HealthStart, ImVec2(HealthStart.x + PercentHP, HealthEnd.y), IM_COL32(225, 0, 0, 255), 10);
            draw->AddRect(HealthStart, HealthEnd, IM_COL32(0, 0, 0, 255), 10);

            std::string strHealth = to_string(m_Hp);
            auto textSize = ImGui::CalcTextSize(strHealth.c_str(), 0, 20);
            draw->AddText(NULL, 20, {HealthEnd.x - (textSize.x / 2), HealthStart.y - 20}, IM_COL32(255, 255, 255, 255), strHealth.c_str());
        }
        
		if (Config.ESP.Monster.Locator) {
            DrawMonster2(rootPosVec2, m_ID, m_Hp, m_HpMax);
        }
		
		if (Config.ESP.Monster.Alert) {
            if (m_ID == 2002 && m_Hp < m_HpMax) {
    	    float iconWidth = 200.0f;
        	float iconHeight = 105.0f;
        	DrawAlert(m_ID, std::max(iconWidth, iconHeight), {(float)(screenWidth / 2), (float)(screenHeight - screenHeight) + (float)(screenHeight / 8.7f)});
            auto LineHealthStart = ImVec2((float)((screenWidth / 2) - 100.0f), (float)(screenHeight / 6.1f));
            auto LineHealthEnd = ImVec2(LineHealthStart.x + 260, LineHealthStart.y);
            auto HealthStart = ImVec2(LineHealthStart.x, LineHealthStart.y - 40);
            auto HealthEnd = ImVec2(LineHealthEnd.x, LineHealthEnd.y - 10);
            float healthWidth = abs(HealthEnd.x - HealthStart.x);
            float PercentHP = ((float)m_Hp * healthWidth) / (float)m_HpMax;
            draw->AddRectFilled(HealthStart, ImVec2(HealthStart.x + PercentHP, HealthEnd.y), IM_COL32(225, 0, 0, 255), 20);
            draw->AddRect(HealthStart, HealthEnd, IM_COL32(0, 0, 0, 255), 20);
            std::string strHealth = to_string(m_Hp);
            auto textSize = ImGui::CalcTextSize(strHealth.c_str(), 0, 20);
            draw->AddText(NULL, 20, {HealthEnd.x - (textSize.x / 2), HealthStart.y - 20}, IM_COL32(255, 255, 255, 255), strHealth.c_str());        
            }    		
            
            if (m_ID == 2003 && m_Hp < m_HpMax) {
    		float iconWidth = 200.0f;
        	float iconHeight = 105.0f;
        	DrawAlert(m_ID, std::max(iconWidth, iconHeight), {(float)(screenWidth / 2), (float)(screenHeight - screenHeight) + (float)(screenHeight / 8.7f)});
            auto LineHealthStart = ImVec2((float)((screenWidth / 2) - 100.0f), (float)(screenHeight / 6.1f));
            auto LineHealthEnd = ImVec2(LineHealthStart.x + 260, LineHealthStart.y);
            auto HealthStart = ImVec2(LineHealthStart.x, LineHealthStart.y - 40);
            auto HealthEnd = ImVec2(LineHealthEnd.x, LineHealthEnd.y - 10);
            float healthWidth = abs(HealthEnd.x - HealthStart.x);
            float PercentHP = ((float)m_Hp * healthWidth) / (float)m_HpMax;
            draw->AddRectFilled(HealthStart, ImVec2(HealthStart.x + PercentHP, HealthEnd.y), IM_COL32(225, 0, 0, 255), 20);
            draw->AddRect(HealthStart, HealthEnd, IM_COL32(0, 0, 0, 255), 20);
            std::string strHealth = to_string(m_Hp);
            auto textSize = ImGui::CalcTextSize(strHealth.c_str(), 0, 20);
            draw->AddText(NULL, 20, {HealthEnd.x - (textSize.x / 2), HealthStart.y - 20}, IM_COL32(255, 255, 255, 255), strHealth.c_str());    
    		}
        }
		
		if (Config.ESP.Monster.Locator2) {
        	draw->AddText(NULL, ((float) screenHeight / 31.0f), {rootPosVec2.x, rootPosVec2.y - 115.0f}, IM_COL32(255, 255, 255, 255), ICON_FA_ARROW_DOWN);
            if (PerHP < m_HpMax) {
            	draw->AddText(NULL, ((float) screenHeight / 31.0f), {rootPosVec2.x, rootPosVec2.y - 115.0f}, IM_COL32(255, 3, 3, 255), ICON_FA_ARROW_DOWN);
            }
        }
		
        if (Config.ESP.Monster.JungelAttack) {
            if (m_ID == 2004 && m_Hp < m_HpMax) {
                std::string strAlert = "[ALERT] Red Buff is under Attack!";
                auto textSize = ImGui::CalcTextSize(strAlert.c_str(), 0, ((float) glHeight / 31.0f));
                draw->AddText(NULL, ((float) glHeight / 31.0f), {(float)(glWidth / 2) - (textSize.x / 2), (float)(glHeight - glHeight) + (float)(glHeight / 8.7f)}, IM_COL32(255, 255, 255, 255), strAlert.c_str());
            }
            if (m_ID == 2005 && m_Hp < m_HpMax) {
                std::string strAlert = "[ALERT] Blue Buff is under Attack!";
                auto textSize = ImGui::CalcTextSize(strAlert.c_str(), 0, ((float) glHeight / 31.0f));
                draw->AddText(NULL, ((float) glHeight / 31.0f), {(float)(glWidth / 2) - (textSize.x / 2), (float)(glHeight - glHeight) + (float)(glHeight / 8.7f)}, IM_COL32(255, 255, 255, 255), strAlert.c_str());
            }
        }
    }
    /*enemy*/
	
	
	
    auto m_dicPlayerShow = *(Dictionary<int, uintptr_t> **) ((uintptr_t)battleManager + BattleManager_m_dicPlayerShow());
    if (!m_dicPlayerShow) return;
    for (int i = 0; i < m_dicPlayerShow->getNumKeys(); i++) {
        auto keys = m_dicPlayerShow->getKeys()[i];
        auto values = m_dicPlayerShow->getValues()[i];
        if (!keys || !values) continue;
        auto m_ID = *(int *) ((uintptr_t)values + EntityBase_m_ID());
        auto m_bDeath = *(bool *) ((uintptr_t)values + EntityBase_m_bDeath());
        if (m_bDeath) continue;
        auto m_bSameCampType = *(bool *) ((uintptr_t)values + EntityBase_m_bSameCampType());
        if (m_bSameCampType) continue;
        auto m_Hp = *(int *) ((uintptr_t)values + EntityBase_m_Hp());
        auto m_HpMax = *(int *) ((uintptr_t)values + EntityBase_m_HpMax());
        auto sPell = *(int *) ((uintptr_t)values + ShowPlayer_m_iSummonSkillId());
        auto _Position = *(Vector3 *) ((uintptr_t)values + ShowEntity__Position());
        auto rootPosVec2 = getPosVec2(_Position, screenWidth, screenHeight);
        auto spellDrawing = ImVec2(rootPosVec2.x + 55, rootPosVec2.y - 15);
        auto *m_HeroName = *(String **) ((uintptr_t)values + ShowPlayer_m_HeroName());
        int Distance = (int) Vector3::Distance(selfPos, _Position);
        auto inBattle = *(bool **) ((uintptr_t)values + ShowPlayer_m_bInBattle);
        auto canSight = *(bool *) ((uintptr_t)values + EntityBase_canSight());
		
        float PerHP = m_Hp * 100 / m_HpMax;
        auto AimDor = Vector3::Normalized(Distance - selfPos);
        auto HeadPosVec2 = Vector2(rootPosVec2.x, rootPosVec2.y - (screenHeight / 6.35));
		//auto skillIdData = *(int *) ((uintptr_t)values + SkillComponent_m_iComAtkId);
		
        if (Config.ESP.Player.Alert && get_InTransformation((void *)values)) {
            if (m_ID == 32 && m_ID == 69) {
                draw->AddText(NULL, 30.0f, {screenWidth / 2.3f, screenHeight / 12.0f}, IM_COL32(255, 255, 0, 255), "Johnson and Hanzo Transformed!");
            } else if (m_ID == 32) {
                draw->AddText(NULL, 30.0f, {screenWidth / 2.3f, screenHeight / 12.0f}, IM_COL32(255, 255, 0, 255), "Johnson Becomes A Car!");
            } else if (m_ID == 69) {
                draw->AddText(NULL, 30.0f, {screenWidth / 2.3f, screenHeight / 12.0f}, IM_COL32(255, 255, 0, 255), "Hanzo Becomes A Kuyang!");
            } else if (m_ID == 101) {
                draw->AddText(NULL, 30.0f, {screenWidth / 2.3f, screenHeight / 12.0f}, IM_COL32(255, 255, 0, 255), "Yve in A Ultimate!");
            }
        }
		
		auto skillLearn = *(Dictionary<int, uintptr_t> **) ((uintptr_t)battleManager + SkillComponent_m_OwnSkillDic);
	
        auto bShowEntityLayer = *(bool *) ((uintptr_t)values + ShowEntity_bShowEntityLayer);
        
        if (Config.ESP.Player.Visible) {
            if (canSight && !isOutsideScreen(ImVec2(rootPosVec2.x, rootPosVec2.y), ImVec2(screenWidth, screenHeight)))
                continue;
        }
        /*
        //if (Config.m_IDConf) {
            std::string mConfigi = to_string(iSkillLearn);
            auto textSize = ImGui::CalcTextSize(mConfigi.c_str(), 0, 20);
            draw->AddText(NULL, 22, {rootPosVec2.x - (textSize.x / 2), rootPosVec2.y + 40}, IM_COL32(255, 255, 255, 255), mConfigi.c_str());
        */
        
        if (Config.MinimapIcon && m_ID == 53 && AttachIconDone) {
            auto m_EntityCampType = *(int *) ((uintptr_t)values + EntityBase_m_EntityCampType());
            auto minimapPos = WorldToMinimap(m_EntityCampType, _Position);
            DrawIconHero(ImVec2(minimapPos.x, minimapPos.y), m_ID, m_Hp, m_HpMax);
        } else if (Config.MinimapIcon && !bShowEntityLayer && AttachIconDone) {
            auto m_EntityCampType = *(int *) ((uintptr_t)values + EntityBase_m_EntityCampType());
            auto minimapPos = WorldToMinimap(m_EntityCampType, _Position);
            DrawIconHero(ImVec2(minimapPos.x, minimapPos.y), m_ID, m_Hp, m_HpMax);
        }
		
		if (Config.ESP.Player.Locator2) {
        	draw->AddText(NULL, ((float) screenHeight / 31.0f), {rootPosVec2.x, rootPosVec2.y - 115.0f}, IM_COL32(255, 255, 255, 255), ICON_FA_ARROW_DOWN);
            if (PerHP < m_HpMax) {
            	draw->AddText(NULL, ((float) screenHeight / 31.0f), {rootPosVec2.x, rootPosVec2.y - 115.0f}, IM_COL32(255, 3, 3, 255), ICON_FA_ARROW_DOWN);
            }
        }
		
        //if (!bShowEntityLayer) {
		if (Config.ESP.Player.Line) {
			ImU32 col = IM_COL32((int)(lineColor.x * 255), (int)(lineColor.y * 255), (int)(lineColor.z * 255), (int)(lineColor.w * 255));
			draw->AddLine(selfPosVec2, ImVec2(rootPosVec2.x, rootPosVec2.y), col, 2.0f);
            draw->AddCircleFilled(ImVec2(selfPosVec2.x, selfPosVec2.y), 5, IM_COL32(255, 0, 0, 255), 0);
            draw->AddCircleFilled(ImVec2(rootPosVec2.x, rootPosVec2.y), 7, IM_COL32(255, 0, 0, 255), 0);
            //draw->AddLine(selfPosVec2, rootPosVec2, IM_COL32(230, 230, 250, 255));
		}
            
        auto *m_RoleName = *(String **) ((uintptr_t)values + ShowEntity_m_RoleName);
        if (Config.ESP.Player.Name && m_RoleName) {
			ImU32 col = IM_COL32((int)(textColor.x * 255), (int)(textColor.y * 255), (int)(textColor.z * 255), (int)(textColor.w * 255));
        	std::string strName = m_RoleName->toString();
            auto textSize = ImGui::CalcTextSize(strName.c_str(), 0, 20);
            draw->AddText(NULL, 22, {rootPosVec2.x - (textSize.x / 2), rootPosVec2.y + 40}, col, strName.c_str());
		}
			
		if (Config.ESP.Player.Health) {
			ImU32 healthCol = IM_COL32((int)(healthBarColor.x * 255), (int)(healthBarColor.y * 255), (int)(healthBarColor.z * 255), (int)(healthBarColor.w * 255));
            ImU32 borderCol = IM_COL32((int)(borderColor.x * 255), (int)(borderColor.y * 255), (int)(borderColor.z * 255), (int)(borderColor.w * 255));
            ImU32 textCol = IM_COL32((int)(textColor.x * 255), (int)(textColor.y * 255), (int)(textColor.z * 255), (int)(textColor.w * 255));
				
            auto LineHealthStart = ImVec2(rootPosVec2.x + 40, rootPosVec2.y - 30);
            auto LineHealthEnd = ImVec2(LineHealthStart.x + 160, LineHealthStart.y);
            auto HealthStart = ImVec2(LineHealthStart.x, LineHealthStart.y - 20);
            auto HealthEnd = ImVec2(LineHealthEnd.x, LineHealthEnd.y - 5);
            float healthWidth = abs(HealthEnd.x - HealthStart.x);
            float PercentHP = ((float)m_Hp * healthWidth) / (float)m_HpMax;
            draw->AddLine(rootPosVec2, LineHealthStart, IM_COL32(255, 255, 255, 255));
            draw->AddLine(LineHealthStart, LineHealthEnd, IM_COL32(255, 255, 255, 155));
            draw->AddRectFilled(HealthStart, ImVec2(HealthStart.x + PercentHP, HealthEnd.y), healthCol, 7);
            draw->AddRect(HealthStart, HealthEnd, IM_COL32(0, 0, 0, 255), 7);
		}
	
        if (Config.ESP.Player.Box) {
            float boxHeight = abs(HeadPosVec2.y - rootPosVec2.y);
            float boxWidth = boxHeight * 0.50f;
            ImVec2 vStart = {HeadPosVec2.x - (boxWidth / 2), HeadPosVec2.y};
            ImVec2 vEnd = {vStart.x + boxWidth, vStart.y + boxHeight};
            draw->AddRect(vStart, vEnd, IM_COL32(255, 255, 255, 255), 0, 235, 1.0f);
        }
        
        if (Config.ESP.Player.Round) {
            draw->AddCircleFilled(rootPosVec2, 10, IM_COL32(255, 255, 255, 255));
        }
		// default: rootPosVec2.y + 5
		if (Config.ESP.Player.Distance) {
        	std::string strDistance = to_string(Distance) + " M";
            auto textSize = ImGui::CalcTextSize(strDistance.c_str(), 0, ((float) screenHeight / 39.0f));
            draw->AddText(NULL, ((float) screenHeight / 39.0f), {rootPosVec2.x - (textSize.x / 2), rootPosVec2.y + 15}, IM_COL32(10, 255, 202, 255), strDistance.c_str());
        }

        if (Config.ESP.Player.CoolDown || Config.ESP.Player.CoolDown2) {
            auto coolDownData = getPlayerCoolDown(keys, values);
            if (Config.ESP.Player.CoolDown) {
                if (coolDownData.skill1) {
                    std::string strCoolDown = to_string(coolDownData.skill1);
                    auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                    draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(255, 255, 0, 255), strCoolDown.c_str());
                } else {
                    draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55, rootPosVec2.y - 15), 10, IM_COL32(255, 255, 0, 255));
                }
                if (coolDownData.skill2) {
                    std::string strCoolDown = to_string(coolDownData.skill2);
                    auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                    draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 + (40 * 1) - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(255, 255, 0, 255), strCoolDown.c_str());
                } else {
                    draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55 + (40 * 1), rootPosVec2.y - 15), 10, IM_COL32(255, 255, 0, 255));
                }
                if (coolDownData.skill3) {
                    std::string strCoolDown = to_string(coolDownData.skill3);
                    auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                    draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 + (40 * 2) - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(255, 255, 0, 255), strCoolDown.c_str());
                } else {
                    draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55 + (40 * 2), rootPosVec2.y - 15), 10, IM_COL32(255, 255, 0, 255));
                }
            }
            if (coolDownData.skillCount >= 4) {
                if (Config.ESP.Player.CoolDown && Config.ESP.Player.CoolDown2) {
                    if (coolDownData.skill4) {
                        std::string strCoolDown = to_string(coolDownData.skill4);
                        auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                        draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 + (40 * 3) - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(255, 255, 0, 255), strCoolDown.c_str());
                    } else {
                        draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55 + (40 * 3), rootPosVec2.y - 15), 10, IM_COL32(255, 255, 0, 255));
                    }
                    if (coolDownData.spell) {
                        std::string strCoolDown = to_string(coolDownData.spell);
                        auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                        draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 + (40 * 4) - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(30, 144, 255, 255), strCoolDown.c_str());
                        //DrawSpell(ImVec2(rootPosVec2.x + 55 + (40 * 4), rootPosVec2.y - 15) ,sPell);
                    } else {
                        DrawSpell(ImVec2(rootPosVec2.x + 55 + (40 * 4), rootPosVec2.y - 15) ,sPell);
                        //draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55 + (40 * 4), rootPosVec2.y - 15), 10, IM_COL32(30, 144, 255, 255));
                    }
                    draw->AddLine(rootPosVec2, ImVec2(rootPosVec2.x + 225, rootPosVec2.y), IM_COL32(255, 255, 255, 255));
                } else if (Config.ESP.Player.CoolDown) {
                    if (coolDownData.skill4) {
                        std::string strCoolDown = to_string(coolDownData.skill4);
                        auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                        draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 + (40 * 3) - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(255, 255, 0, 255), strCoolDown.c_str());
                    } else {
                        draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55 + (40 * 3), rootPosVec2.y - 15), 10, IM_COL32(255, 255, 0, 255));
                    }
                    draw->AddLine(rootPosVec2, ImVec2(rootPosVec2.x + 185, rootPosVec2.y), IM_COL32(255, 255, 255, 255));
                } else if (Config.ESP.Player.CoolDown2) {
                    if (coolDownData.spell) {
                        std::string strCoolDown = to_string(coolDownData.spell);
                        auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                        draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(30, 144, 255, 255), strCoolDown.c_str());
                        //DrawSpell(ImVec2(rootPosVec2.x + 55, rootPosVec2.y - 15),sPell);
                    } else {
                        DrawSpell(ImVec2(rootPosVec2.x + 55, rootPosVec2.y - 15),sPell);
                       // draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55, rootPosVec2.y - 15), 10, IM_COL32(30, 144, 255, 255));
                    }
                    draw->AddLine(rootPosVec2, ImVec2(rootPosVec2.x + 65, rootPosVec2.y), IM_COL32(255, 255, 255, 255));
                }
            } else if (coolDownData.skillCount == 3) {
                if (Config.ESP.Player.CoolDown && Config.ESP.Player.CoolDown2) {
                    if (coolDownData.spell) {
                        std::string strCoolDown = to_string(coolDownData.spell);
                        auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                        draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 + (40 * 3) - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(30, 144, 255, 255), strCoolDown.c_str());
                        //DrawSpell(ImVec2(rootPosVec2.x + 55 + (40 * 3), rootPosVec2.y - 15),sPell);
                    } else {
                        DrawSpell(ImVec2(rootPosVec2.x + 55 + (40 * 3), rootPosVec2.y - 15),sPell);
                      //  draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55 + (40 * 3), rootPosVec2.y - 15), 10, IM_COL32(30, 144, 255, 255));
                    }
                    draw->AddLine(rootPosVec2, ImVec2(rootPosVec2.x + 185, rootPosVec2.y), IM_COL32(255, 255, 255, 255));
                } else if (Config.ESP.Player.CoolDown) {
                    draw->AddLine(rootPosVec2, ImVec2(rootPosVec2.x + 145, rootPosVec2.y), IM_COL32(255, 255, 255, 255));
                } else if (Config.ESP.Player.CoolDown2) {
                    if (coolDownData.spell) {
                        std::string strCoolDown = to_string(coolDownData.spell);
                        auto textSize = ImGui::CalcTextSize(strCoolDown.c_str(), 0, 30);
                        draw->AddText(NULL, 30, ImVec2(rootPosVec2.x + 55 - (textSize.x / 2), rootPosVec2.y - 30), IM_COL32(30, 144, 255, 255), strCoolDown.c_str());
                    } else {
                        DrawSpell(ImVec2(rootPosVec2.x + 55, rootPosVec2.y - 15),sPell);
                        draw->AddCircleFilled(ImVec2(rootPosVec2.x + 55, rootPosVec2.y - 15), 10, IM_COL32(30, 144, 255, 255));
                    }
                    draw->AddLine(rootPosVec2, ImVec2(rootPosVec2.x + 65, rootPosVec2.y), IM_COL32(255, 255, 255, 255));
                }
            }
        }
        
        if (Config.ESP.Player.Alert && isOutsideScreen(ImVec2(rootPosVec2.x, rootPosVec2.y), ImVec2(screenWidth, screenHeight))) {
            ImVec2 hintDotRenderPos = pushToScreenBorder(ImVec2(rootPosVec2.x, rootPosVec2.y), ImVec2(screenWidth, screenHeight), - 50);
            ImVec2 hintTextRenderPos = pushToScreenBorder(ImVec2(rootPosVec2.x, rootPosVec2.y), ImVec2(screenWidth, screenHeight), - 50);
            //DrawCircleHealth(hintDotRenderPos, CurHP, MaxHP, 25);
            DrawLogo(ImGui::GetForegroundDrawList(), hintDotRenderPos, m_ID, m_Hp, m_HpMax);
            if(Config.ESP.Player.Distance){
                std::string strDistance = to_string(Distance) + " M";
                auto textSize = ImGui::CalcTextSize(strDistance.c_str(), 0, ((float) screenHeight / 45.0f));
                draw->AddText(NULL, ((float) screenHeight / 45.0f), {hintTextRenderPos.x - (textSize.x / 2), hintTextRenderPos.y + 7}, IM_COL32(255, 255, 255, 255), strDistance.c_str());
            }
            if (m_HeroName) {
                std::string strName = m_HeroName->toString();
                if(Config.ESP.Player.Status) {
                    strName += strName + "[" + CekBattle(inBattle).c_str() + "]";
                }
                auto textSize = ImGui::CalcTextSize(strName.c_str(), 0, ((float) screenHeight / 39.0f));
                draw->AddText(NULL, ((float) screenHeight / 39.0f), {hintTextRenderPos.x - (textSize.x / 2), hintTextRenderPos.y + 30}, IM_COL32(255, 255, 255, 255), strName.c_str());
            }
        }
        
        if (Config.ESP.Player.HeroZ) {
            DrawHero(rootPosVec2, m_ID, m_Hp, m_HpMax);
        }
        

    }
}

