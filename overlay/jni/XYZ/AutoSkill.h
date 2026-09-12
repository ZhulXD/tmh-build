#pragma once
#include <string>
#include <vector>
#include <cmath>
#include "GameClass.h"
#include "ConfigName.h"

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

inline int GetLocalPlayerSpell() {
    void *BattleManager_Instance = nullptr;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
    if (!BattleManager_Instance) return 0;
    auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
    if (!m_LocalPlayerShow) return 0;
    return *(int *) (m_LocalPlayerShow + ShowPlayer_m_iSummonSkillId());
}

inline int CalculateRetriDamage(int m_Level, int _KillWildTimes = 5, int _killNum = 0, int _assistNum = 0) {
    if ((_KillWildTimes + _killNum + _assistNum) < 5) {
        return 520 + (80 * m_Level);
    } else {
        return (int)(1.521f * (float)(520 + (80 * m_Level)));
    }
}

// Global hook pointer
extern void (*oShowSelfPlayer_OnUpdate)(void *);

inline void AutoRetributionUpdate(void *selfPlayer) {
    if (!selfPlayer || !Config.Auto.Retribution.Enable) return;

    void *BattleManager_Instance = nullptr;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
    if (!BattleManager_Instance) return;

    auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
    if (!m_LocalPlayerShow) return;

    int mySpell = *(int *) (m_LocalPlayerShow + ShowPlayer_m_iSummonSkillId());
    // Only execute if local player has Retribution equipped (20020 or 2002x)
    if (mySpell != 20020 && (mySpell / 10 != 2002)) return;

    int m_Level = *(int *) (m_LocalPlayerShow + EntityBase_m_Level());
    if (m_Level <= 0) m_Level = 1;

    int killWild = 5; // Default to full upgrade if not directly read
    int maxRetriDamage = CalculateRetriDamage(m_Level, killWild, 0, 0);

    auto selfPos = *(Vector3 *) (m_LocalPlayerShow + ShowEntity__Position());

    // Iterate monsters from dictionary
    auto m_dicMonsterShow = *(Dictionary<int, uintptr_t> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicMonsterShow());
    if (!m_dicMonsterShow) return;

    for (int i = 0; i < m_dicMonsterShow->getNumKeys(); i++) {
        auto values = m_dicMonsterShow->getValues()[i];
        if (!values) continue;

        auto m_bDeath = *(bool *) ((uintptr_t)values + EntityBase_m_bDeath());
        if (m_bDeath) continue;

        auto m_bSameCampType = *(bool *) ((uintptr_t)values + EntityBase_m_bSameCampType());
        if (m_bSameCampType) continue;

        auto m_ID = *(int *) ((uintptr_t)values + EntityBase_m_ID());

        bool isTarget = false;
        if (Config.Auto.Retribution.Lord && (m_ID == 2002)) isTarget = true;
        else if (Config.Auto.Retribution.Turtle && (m_ID == 2003 || m_ID == 2110)) isTarget = true;
        else if (Config.Auto.Retribution.Buff && (m_ID == 2004 || m_ID == 2005)) isTarget = true;
        else if (Config.Auto.Retribution.Crab && (m_ID == 2011 || m_ID == 2013)) isTarget = true;
        else if (Config.Auto.Retribution.Litho && (m_ID == 2056 || m_ID == 2072)) isTarget = true;
        else if (Config.Auto.Retribution.Crammer && (m_ID == 2008 || m_ID == 2059)) isTarget = true;

        if (!isTarget) continue;

        auto _Position = *(Vector3 *) ((uintptr_t)values + ShowEntity__Position());
        float dist = Vector3::Distance(selfPos, _Position);

        // Retribution cast distance range is ~7.5f units
        if (dist <= 7.5f) {
            auto m_Hp = *(int *) ((uintptr_t)values + EntityBase_m_Hp());
            if (m_Hp > 0 && m_Hp <= maxRetriDamage) {
                // Instantly cast retribution towards monster!
                auto dir = Vector3::Normalized(_Position - selfPos);
                typedef int (__fastcall * t_TryUseSkill)(void *Base, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAttack, bool bAlong, bool isInFirstDragRange, bool bIgnoreQueue, uint dragTime);
                static t_TryUseSkill TryUseSkill_fn = (t_TryUseSkill)(ShowSelfPlayer_TryUseSkill2);
                if (TryUseSkill_fn) {
                    TryUseSkill_fn(selfPlayer, mySpell, dir, false, Vector3::zero(), true, false, false, false, 0);
                    break; // Cast once per tick
                }
            }
        }
    }
}

inline void iShowSelfPlayer_OnUpdate(void *self) {
    if (self != nullptr) {
        AutoRetributionUpdate(self);
    }
    if (oShowSelfPlayer_OnUpdate) {
        oShowSelfPlayer_OnUpdate(self);
    }
}
