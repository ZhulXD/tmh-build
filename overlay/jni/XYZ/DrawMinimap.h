// Define variables for minimap settings
static float minimapPosX = 82.337;
static float minimapPosY = 0.0f;
static float minimapWidth = 310.20f;
static float minimapHeight = 300.45f;
static float circleSize2 = 30.0f; // Ukuran lingkaran default
static bool isMinimapEnabled = false;
static bool IconMinimap = true; // Atur menjadi true secara default
static float rotationAngle = 0.0f; // Dah Gerak kearah yg benar
static float zoomFactor = -1.0f; // belum dicoba
static float scaleXFloat = 2.9f;
static float scaleYFloat = 2.9f;
static float centerMapX = 2.0f;
static float centerMapY = 2.0f;

ImVec2 CoordinateMap(Vector3 Position, float x, float y, float w, float h)
{
    ImVec2 centerMap(w / centerMapX, h / centerMapY);
    float scaleX = ((Position.x * w) - (Position.z * h)) / w;
    float ScaleY = -((Position.x * w) + (Position.z * h)) / h;

    float PosX = (x + (scaleX * scaleXFloat) + centerMap.x + 2.5);
    float PosY = (y + (ScaleY * scaleYFloat) + centerMap.y + 2.5);

    ImVec2 Result(std::max(x, std::min(PosX, x + w)), std::max(y, std::min(PosY, y + h)));

    return Result;
}

std::string CekBattle(bool state){
    if(state){
        return "In Battle";
    }else{
        return "Free Move";
    }
}

void RenderESP(ImDrawList *draw, int screenWidth, int screenHeight) {
    ImVec2 minimapSize(minimapWidth, minimapHeight);
    void *BattleBridge_Instance, *BattleManager_Instance, *LogicBattleManager_Instance;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleData", "m_BattleBridge", &BattleBridge_Instance);
    if (!BattleBridge_Instance) {
        static auto get_ui = (void *(*)())(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "BattleData", "get_m_TinyBattleUI", 0));
        if (get_ui) BattleBridge_Instance = get_ui();
    }
    if (BattleBridge_Instance) {
        auto _bStartBattle = BattleBridge_bStartBattle_Get(BattleBridge_Instance);
        if (_bStartBattle) {
            ImVec2 minimapPosition(minimapPosX, minimapPosY);
            //ImVec2 minimapSize(Config.Map.Size.minimapWidth, Config.Map.Size.minimapHeight);
            if(isMinimapEnabled){
                draw->AddRect(minimapPosition, ImVec2(minimapPosition.x + minimapSize.x, minimapPosition.y + minimapSize.y), IM_COL32(255, 255, 255, 255));
            }
            Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
            if (BattleManager_Instance) {
                auto m_LocalPlayerShow = *(uintptr_t *)((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
                if (m_LocalPlayerShow) {
                    auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position());
                    if (selfPos != Vector3::zero()) {
                        auto SelfPosW2S = WorldToScreen(selfPos);
                        auto SelfPosVec2 = ImVec2(screenWidth - SelfPosW2S.x, SelfPosW2S.y);
                        if (SelfPosW2S.z > 0) {
                            SelfPosVec2 = ImVec2(SelfPosW2S.x, screenHeight - SelfPosW2S.y);
                        }
                        auto m_ShowPlayers = *(Dictionary<int, uintptr_t> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicPlayerShow());
            			if (m_ShowPlayers) {
            				for (int i = 0; i < m_ShowPlayers->getNumKeys(); i++) {
         						auto keys = m_ShowPlayers->getKeys()[i];
            					auto Pawn = m_ShowPlayers->getValues()[i];
            					if (!keys || !Pawn) continue;
                                auto m_bSameCampType = *(bool *)((uintptr_t)Pawn + EntityBase_m_bSameCampType());
                                if (m_bSameCampType) continue;
                                auto m_bDeath = *(bool *)((uintptr_t)Pawn + EntityBase_m_bDeath());
                                if (m_bDeath) continue;
                                auto CurHP = *(int *)((uintptr_t)Pawn + EntityBase_m_Hp());
                                auto MaxHP = *(int *)((uintptr_t)Pawn + EntityBase_m_HpMax());
								//Vector3 _Position = ShowEntity_GetPosition(Pawn);
								auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position());
                                auto _Position2 = Vector3::Normalized(_Position);
                                auto *m_RoleName = *(String **)((uintptr_t)Pawn + ShowEntity_m_RoleName);
                                auto *m_HeroName = *(String **)((uintptr_t)Pawn + ShowPlayer_m_HeroName());
                                auto HeroID = *(int *)((uintptr_t)Pawn + EntityBase_m_ID());
                                int Distance = (int)Vector3::Distance(selfPos, _Position);
                                if (isMinimapEnabled) {
                                    DrawHero(CoordinateMap(_Position,minimapPosition.x, minimapPosition.y, minimapSize.x, minimapSize.y), HeroID, CurHP, MaxHP, ICSize, ICHealthThin );
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

