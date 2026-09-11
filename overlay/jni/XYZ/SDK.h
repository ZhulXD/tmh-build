#pragma once 

class ShowEntityBase {
    public:
    
    bool m_bDeath() {
        auto (*get_death)(void *) = (bool (*)(void *))(Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "get_m_bDeath", 0));
        if (get_death) return get_death(this);
        return *(bool *) ((uintptr_t) this + 0x1d0);
    }

    bool m_bSameCampType() {
        return *(bool *) ((uintptr_t) this + Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_bSameCampType"));
    }
    
    int m_Hp() {
        return *(int *) ((uintptr_t) this + Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_Hp"));
    }
    
    int m_HpMax() {
        return *(int *) ((uintptr_t) this + Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", "EntityBase", "m_HpMax"));
    }
};

class ShowEntity : public ShowEntityBase {
    public:
    
    String *m_RoleName() {
        return *(String **) ((uintptr_t) this + Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "ShowEntity", "m_RoleName"));
    }
};

Vector3 AimEnemy,My;

std::map<std::string, uintptr_t> Fields;
std::map<std::string, uintptr_t> Methods;

static void *GetPlayerSelf(void *thiz){
    auto *(*LogicBattleManagerZ_GetPlayerRealSelf)(void *nul) = (void *(*)(void *))(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "GetPlayerRealSelf"));
    return LogicBattleManagerZ_GetPlayerRealSelf(thiz);
}

static Vector3 Player_position(void *thiz) {
    auto (*LogicFighter_get_Position)(void *players) = (Vector3 (*)(void *))(Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", "LogicFighter", "get_Position"));
    return LogicFighter_get_Position(thiz);
}

static int GetCampType(void *thiz,void *entity,bool benemy){
    auto (*LogicBattleManager_GetCampType)(void *,void*,bool) = (uintptr_t (*)(void *,void*,bool))(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", "GetCampType", 2));
    return LogicBattleManager_GetCampType(thiz,entity,benemy);
}

static int Player_GetTotalHP(void *thiz){
    auto (*LogicFighter_GetTotalHp)(void*_thiz)= (uintptr_t(*)(void*))(LogicFighter__GetTotalHp);
    return LogicFighter_GetTotalHp(thiz);
}


