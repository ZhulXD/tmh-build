#pragma once
#include <string>
#include <vector>
#include <cmath>
#include "Tools/Dobby/Dobby.hpp"

// Forward declarations
inline int GetLocalPlayerSpell();
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

inline int CalculateRetriDamage(int m_Level, int _KillWildTimes = 5, int _killNum = 0, int _assistNum = 0) {
    if ((_KillWildTimes + _killNum + _assistNum) < 5) {
        return 520 + (80 * m_Level);
    } else {
        return (int)(1.521f * (float)(520 + (80 * m_Level)));
    }
}

inline void AutoRetributionUpdate(void *selfPlayer) {
    if (!selfPlayer || !Config.Auto.Retribution.Enable) return;

    void *BattleManager_Instance = nullptr;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
    if (!BattleManager_Instance) return;

    auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
    if (!m_LocalPlayerShow) return;

    uintptr_t offset_spell = ShowPlayer_m_iSummonSkillId();
    if (offset_spell == 0 || offset_spell == (uintptr_t)-1) offset_spell = 0x964;
    int mySpell = *(int *) (m_LocalPlayerShow + offset_spell);
    
    // Only execute if local player has Retribution equipped (20020 or 2002x)
    if (mySpell != 20020 && (mySpell / 10 != 2002)) return;

    uintptr_t offset_lvl = EntityBase_m_Level();
    if (offset_lvl == 0 || offset_lvl == (uintptr_t)-1) offset_lvl = 0x198;
    int m_Level = *(int *) (m_LocalPlayerShow + offset_lvl);
    if (m_Level <= 0) m_Level = 1;

    int maxRetriDamage = CalculateRetriDamage(m_Level, 5, 0, 0);

    uintptr_t offset_pos = ShowEntity__Position();
    if (offset_pos == 0 || offset_pos == (uintptr_t)-1) offset_pos = 0x294;
    auto selfPos = *(Vector3 *) (m_LocalPlayerShow + offset_pos);

    // Iterate monsters from dictionary
    auto m_dicMonsterShow = *(Dictionary<int, uintptr_t> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicMonsterShow());
    if (!m_dicMonsterShow) return;

    uintptr_t offset_death = EntityBase_m_bDeath();
    if (offset_death == 0 || offset_death == (uintptr_t)-1) offset_death = 0xcd;

    uintptr_t offset_camp = EntityBase_m_bSameCampType();
    if (offset_camp == 0 || offset_camp == (uintptr_t)-1) offset_camp = 0x2b1;

    uintptr_t offset_id = EntityBase_m_ID();
    if (offset_id == 0 || offset_id == (uintptr_t)-1) offset_id = 0x194;

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

        // Retribution cast distance range is ~7.5f units
        if (dist <= 7.5f) {
            auto m_Hp = *(int *) ((uintptr_t)values + offset_hp);
            if (m_Hp > 0 && m_Hp <= maxRetriDamage) {
                // Instantly cast retribution towards monster!
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
