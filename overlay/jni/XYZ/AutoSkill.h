#pragma once
#include <string>
#include <vector>
#include <cmath>
#include "Tools/Dobby/Dobby.hpp"

// Forward declarations
inline int GetLocalPlayerSpell();
inline int GetLocalPlayerHeroID();
inline bool IsPlayerInBattle();

inline std::string GetSpellName(int spellId) {
    if (spellId == 20020 || spellId / 10 == 2002) return "Retribution";
    if (spellId == 20010 || spellId / 10 == 2001) return "Execute";
    if (spellId == 20030 || spellId / 10 == 2003) return "Flicker";
    if (spellId == 20040 || spellId / 10 == 2004) return "Inspire";
    if (spellId == 20050 || spellId / 10 == 2005) return "Sprint";
    if (spellId == 20060 || spellId / 10 == 2006) return "Revitalize";
    if (spellId == 20070 || spellId / 10 == 2007) return "Aegis";
    if (spellId == 20080 || spellId / 10 == 2008) return "Petrify";
    if (spellId == 20090 || spellId / 10 == 2009) return "Purify";
    if (spellId == 20100 || spellId / 10 == 2010) return "Flameshot";
    if (spellId == 20110 || spellId / 10 == 2011) return "Vengeance";
    if (spellId == 20120 || spellId / 10 == 2012) return "Arrival";
    return "Spell (" + std::to_string(spellId) + ")";
}

inline bool IsPlayerInBattle() {
    void *BattleManager_Instance = nullptr;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
    if (!BattleManager_Instance) return false;
    auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
    if (!m_LocalPlayerShow) return false;
    return true;
}

inline int GetLocalPlayerSpell() {
    void *BattleManager_Instance = nullptr;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
    if (!BattleManager_Instance) return 0;
    auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
    if (!m_LocalPlayerShow) return 0;
    
    uintptr_t offset_spell = ShowPlayer_m_iSummonSkillId();
    if (offset_spell == 0 || offset_spell == (uintptr_t)-1) offset_spell = 0x964;
    return *(int *) (m_LocalPlayerShow + offset_spell);
}

inline int GetLocalPlayerHeroID() {
    void *BattleManager_Instance = nullptr;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
    if (!BattleManager_Instance) return 0;
    auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
    if (!m_LocalPlayerShow) return 0;
    
    uintptr_t offset_id = EntityBase_m_ID();
    if (offset_id == 0 || offset_id == (uintptr_t)-1) offset_id = 0x194;
    return *(int *) (m_LocalPlayerShow + offset_id);
}

// Updated New Patch Retribution damage formula: 750 + (150 * Hero Level)
// Level 1: 900 True Damage
// Level 15: 3,000 True Damage
inline int CalculateRetriDamage(int m_Level) {
    if (m_Level < 1) m_Level = 1;
    if (m_Level > 15) m_Level = 15;
    return 750 + (150 * m_Level);
}

inline void AutoRetributionUpdate(void *selfPlayer) {
    if (!selfPlayer) return;

    void *BattleManager_Instance = nullptr;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
    if (!BattleManager_Instance) return;

    auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
    if (!m_LocalPlayerShow) return;

    uintptr_t offset_pos = ShowEntity__Position();
    if (offset_pos == 0 || offset_pos == (uintptr_t)-1) offset_pos = 0x294;
    auto selfPos = *(Vector3 *) (m_LocalPlayerShow + offset_pos);

    uintptr_t offset_death = EntityBase_m_bDeath();
    if (offset_death == 0 || offset_death == (uintptr_t)-1) offset_death = 0xcd;

    uintptr_t offset_camp = EntityBase_m_bSameCampType();
    if (offset_camp == 0 || offset_camp == (uintptr_t)-1) offset_camp = 0x2b1;

    // --- 1. KIMMY DOUBLE DAMAGE AUTOMATION ---
    uintptr_t offset_id = EntityBase_m_ID();
    if (offset_id == 0 || offset_id == (uintptr_t)-1) offset_id = 0x194;
    int myHeroID = *(int *) (m_LocalPlayerShow + offset_id);

    if (myHeroID == 71 && Config.Auto.Hero.KimmyDoubleDamage) {
        // Cooldown timer: prevents restarting attack animation every 16ms frame, allowing projectile to spawn
        static auto lastKimmyAttack = std::chrono::steady_clock::now();
        auto nowTime = std::chrono::steady_clock::now();
        auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - lastKimmyAttack).count();

        if (elapsedMs >= 150) {
            auto m_dicPlayerShow = *(Dictionary<int, uintptr_t> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicPlayerShow());
            if (m_dicPlayerShow) {
                uintptr_t offset_guid = EntityBase_m_uGuid();
                if (offset_guid == 0 || offset_guid == (uintptr_t)-1) offset_guid = 0x190;

                for (int i = 0; i < m_dicPlayerShow->getNumKeys(); i++) {
                    auto values = m_dicPlayerShow->getValues()[i];
                    if (!values) continue;
                    auto m_bDeath = *(bool *) ((uintptr_t)values + offset_death);
                    if (m_bDeath) continue;
                    auto m_bSameCampType = *(bool *) ((uintptr_t)values + offset_camp);
                    if (m_bSameCampType) continue; // Enemy player only

                    auto targetPos = *(Vector3 *) ((uintptr_t)values + offset_pos);
                    float dist = Vector3::Distance(selfPos, targetPos);
                    if (dist <= 7.5f && targetPos != Vector3::zero()) {
                        uint32_t targetGuid = *(uint32_t *) ((uintptr_t)values + offset_guid);
                        auto dir = Vector3::Normalized(targetPos - selfPos);

                        // 1. ShowSelfPlayer.TryCommonAtk(targetGuid) - double projectile invocation
                        typedef int (*t_TryCommonAtk)(void *Base, uint32_t targetId);
                        static t_TryCommonAtk TryCommonAtk_fn = (t_TryCommonAtk)(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowSelfPlayer", "TryCommonAtk", 1));
                        if (TryCommonAtk_fn && targetGuid != 0) {
                            TryCommonAtk_fn(selfPlayer, targetGuid);
                            TryCommonAtk_fn(selfPlayer, targetGuid);
                        }

                        // 2. Direct ShowUnitAIComp.TryCommonAtkWithoutCheck(aiComp, targetGuid)
                        uintptr_t offset_ai = 0xbb0; // f_ShowSelfPlayer_m_UnitAiComp
                        void *aiComp = *(void **) ((uintptr_t)selfPlayer + offset_ai);
                        if (aiComp && targetGuid != 0) {
                            typedef void (*t_TryCommonAtkWithoutCheck)(void *ai, uint32_t id);
                            static t_TryCommonAtkWithoutCheck TryAtkNoCheck = (t_TryCommonAtkWithoutCheck)(Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "ShowUnitAIComp", "TryCommonAtkWithoutCheck", 1));
                            if (TryAtkNoCheck) {
                                TryAtkNoCheck(aiComp, targetGuid);
                                TryAtkNoCheck(aiComp, targetGuid);
                            }
                        }

                        // 3. Directional TryUseSkill with basicAtkId
                        static auto GetCommonAtkData_fn = (void *(*)(void *, bool))(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowSelfPlayer", "GetCommonAtkData", 1));
                        static auto get_SkillID_fn = (int (*)(void *))(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowSkillData", "get_m_SkillID", 0));
                        int basicAtkId = 7100;
                        if (GetCommonAtkData_fn && get_SkillID_fn) {
                            void *atkData = GetCommonAtkData_fn(selfPlayer, false);
                            if (atkData) {
                                int id = get_SkillID_fn(atkData);
                                if (id > 0) basicAtkId = id;
                            }
                        }

                        typedef int (__fastcall * t_TryUseSkill)(void *Base, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAttack, bool bAlong, bool isInFirstDragRange, bool bIgnoreQueue, uint dragTime);
                        static t_TryUseSkill TryUseSkill_fn = (t_TryUseSkill)(ShowSelfPlayer_TryUseSkill2);
                        if (TryUseSkill_fn) {
                            TryUseSkill_fn(selfPlayer, basicAtkId, dir, false, targetPos, true, false, true, true, 100);
                            TryUseSkill_fn(selfPlayer, basicAtkId, dir, false, targetPos, true, false, true, true, 100);
                        }

                        lastKimmyAttack = nowTime;
                        break;
                    }
                }
            }
        }
    }

    // --- 2. AUTO RETRIBUTION ---
    if (Config.Auto.Retribution.Enable) {
        uintptr_t offset_spell = ShowPlayer_m_iSummonSkillId();
        if (offset_spell == 0 || offset_spell == (uintptr_t)-1) offset_spell = 0x964;
        int mySpell = *(int *) (m_LocalPlayerShow + offset_spell);

        if (mySpell == 20020 || (mySpell / 10 == 2002)) {
            uintptr_t offset_lvl = EntityBase_m_Level();
            if (offset_lvl == 0 || offset_lvl == (uintptr_t)-1) offset_lvl = 0x198;
            int m_Level = *(int *) (m_LocalPlayerShow + offset_lvl);
            if (m_Level <= 0) m_Level = 1;

            int maxRetriDamage = CalculateRetriDamage(m_Level);

            auto m_dicMonsterShow = *(Dictionary<int, uintptr_t> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicMonsterShow());
            if (m_dicMonsterShow) {
                uintptr_t offset_hp = EntityBase_m_Hp();
                if (offset_hp == 0 || offset_hp == (uintptr_t)-1) offset_hp = 0x1ac;

                for (int i = 0; i < m_dicMonsterShow->getNumKeys(); i++) {
                    auto values = m_dicMonsterShow->getValues()[i];
                    if (!values) continue;

                    auto m_bDeath = *(bool *) ((uintptr_t)values + offset_death);
                    if (m_bDeath) continue;

                    auto m_bSameCampType = *(bool *) ((uintptr_t)values + offset_camp);
                    if (m_bSameCampType) continue;

                    auto m_ID = *(int *) ((uintptr_t)values + offset_id);

                    bool isTarget = false;
                    if (Config.Auto.Retribution.Lord && (m_ID == 2002)) isTarget = true;
                    else if (Config.Auto.Retribution.Turtle && (m_ID == 2003 || m_ID == 2110)) isTarget = true;
                    else if (Config.Auto.Retribution.Buff && (m_ID == 2004 || m_ID == 2005)) isTarget = true;
                    else if (Config.Auto.Retribution.Crab && (m_ID == 2011 || m_ID == 2013)) isTarget = true;
                    else if (Config.Auto.Retribution.Litho && (m_ID == 2056 || m_ID == 2072)) isTarget = true;
                    else if (Config.Auto.Retribution.Crammer && (m_ID == 2008 || m_ID == 2059)) isTarget = true;

                    if (!isTarget) continue;

                    auto _Position = *(Vector3 *) ((uintptr_t)values + offset_pos);
                    float dist = Vector3::Distance(selfPos, _Position);

                    if (dist <= 7.5f) {
                        auto m_Hp = *(int *) ((uintptr_t)values + offset_hp);
                        if (m_Hp > 0 && m_Hp <= maxRetriDamage) {
                            auto dir = Vector3::Normalized(_Position - selfPos);
                            typedef int (__fastcall * t_TryUseSkill)(void *Base, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAttack, bool bAlong, bool isInFirstDragRange, bool bIgnoreQueue, uint dragTime);
                            static t_TryUseSkill TryUseSkill_fn = (t_TryUseSkill)(ShowSelfPlayer_TryUseSkill2);
                            if (TryUseSkill_fn) {
                                TryUseSkill_fn(selfPlayer, mySpell, dir, false, Vector3::zero(), true, false, false, false, 0);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

inline void ShowSelfPlayer_OnUpdate_Handler(RegisterContext *ctx, const HookEntryInfo *info) {
#if defined(__arm__)
    void *SelfPlayer = (void *)(ctx->general.r[0]);
#elif defined(__arm64__) || defined(__aarch64__)
    void *SelfPlayer = (void *)(ctx->general.x[0]);
#endif
    if (SelfPlayer != nullptr) {
        AutoRetributionUpdate(SelfPlayer);
    }
}
