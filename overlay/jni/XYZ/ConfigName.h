#pragma once

#define targetLib "liblogic.so"

enum EThemeTarget {
    None = 0,
    Transparent = 1,
    Blacki = 2,
    Blue = 3,
    Pink = 4
};
static float density = -1;

auto ButtonPositionDis = 1500;
auto ButtonPositionDis2 = 110;
bool OpenLinkURL;
bool ActiveESP;
bool ActiveVipSkill;
bool ButtonComboGusion;
bool SetGrassLayerHook;
bool EyeRangeHook;
bool KimmyAttackJungle;
//Button ImGui Combo
bool GusionButton;
bool PaquitoButton;
bool KimmyButton;

//End ImGui Combo

namespace Esp{
	bool SkillsId;
}
bool UpdateManiacStatus;
bool ToggleRetri;
int speedInt = 21;
bool customTrigger;

namespace Configs {
	int EglWidth = 0;
	int EglHeight = 0;
    int DisplayWidth = 0;
    int DisplayHeight = 0;
    bool LoginValid = false;
    bool Initialized = false;
	bool ClearMouse = true;
	bool ShowImGui = true;
};

float CostumLagging = 15;

namespace AutoSkills{
	bool SoYou;
	bool Lucas;
	bool KimmyTriggerOnNew;
	bool KimmyTrigger;
	bool GusionTriggerRecall;
	bool GusionTrigger;
	bool KimmyCreep;
	bool KimmyCreepTrigger;
	bool VisibleCheck;
	bool KimmyBasicAttack;
	bool KimmyBasicAttackTrigger;
	bool DyrothBugTest;
	bool DyrothBugTrigger;
	bool YssBugCall;
	bool AluBugCall;
	bool BeatrixBugTest;
	bool YinBrustDamage;
	bool BeatrixBugTrigger;
	bool YinBugTrigger;
	bool LaylaDamage;
	bool LaylaTrigger;
	bool AamonDamage;
	bool AamonTrigger;
	bool NovariaDamage;
	bool NovariaTrigger;
	bool HanabiDamage;
	bool ArgusDamage;
	bool FannyCable;
	bool HanabiTrigger;
	bool GusionDamage;
	bool GusionBugTrigger;
	bool JoyDoubleDamage;
	bool JoyTrigger;
	bool JoyDoubleDamage2;
	bool JoyTrigger2;
	bool JhonsonDmg;
	bool JhonsonTrigger;
	bool FredrinBug;
	bool FredrinTrigger;
	bool LesleyBug;
	bool LesleyTrigger;
	bool MinotaurBug;
	bool MinotaurTrigger;
	bool EsmeraldaBug;
	bool EsmeraldaBug2;
	bool EsmeraldaTrigger;
	bool PaquitoTrigger;
	bool CarmilaBug;
	bool AldousBug;
	bool KimmyFreeTrigger;
	bool PharsaTriggetUlti;
};

struct sAutoRetribution {
    bool RedandBlue;
    bool TurtleandLord;
    bool Crab;
    bool litho;
	float Custom = 7.0f;
};
sAutoRetribution AutoRetribution{0};

struct sColorPick {
    float *Line;
    float *Box;
    float *Name;
    float *Health;
    float *Distance;
    float *Second;
};
sColorPick ColorPick{0};

struct sAutoTrigger {
    bool Retribution;
};
sAutoTrigger AutoTrigger{0};

struct sAutoSkill {
    bool Lesley;
	bool Lucas;
};
sAutoSkill AutoSkill{0};

struct sAim {
    bool SelfPos;
    bool TargetPriority;
    bool AutoTakeSword;
    bool AutoTakeSword2;
    bool ActivePredict;
    struct sPredict {
        bool Skill1;
        bool Skill2;
        bool Skill3;
        bool Skill4;
        bool Basic;
    };
    sPredict Predict {0};
    struct sAutoSkills {
        bool Joy2;
        bool Joy;
        bool ExecuteV2;
        bool LingLung;
        bool Yve;
        bool AutoTakeSword;
        // SKILL 1 //
        bool Skill1Basic;
        bool Skill1Skill2;
        bool Skill1Skill3;
        bool Skill1Skill4;
        // SKILL 2 //
        bool Skill2Basic;
        bool Skill2Skill1;
        bool Skill2Skill3;
        bool Skill2Skill4;
        // SKILL 3 //
        bool Skill3Basic;
        bool Skill3Skill1;
        bool Skill3Skill2;
        bool Skill3Skill4;
        // SKILL 4 //
        bool Skill4Basic;
        bool Skill4Skill1;
        bool Skill4Skill2;
        bool Skill4Skill3;
        // SKILL COMBO //
        bool Yz;
        bool Lylia;
        bool LyliaV2;
        bool WanWan;
        bool KimmyV1;
        bool KimmyV2;
		bool KimmyNewAim;
        bool KimmyV3;
        bool XavierUlt;
        bool Gusion2;
		bool Karina;
		bool PharsaUlti;
		bool Lucas;
		bool SoYou;
    };
    sAutoSkills AutoSkills{0};
    struct sHelper {
        bool iCalculateDamage;
        
        struct sComboSkill {
            bool Balmond;
        };
        sComboSkill ComboSkill{0};
        
        struct sSkills {
            bool Basic;
            bool Spell;
            bool Skill1;
            bool Skill1Testing;
            bool Skill1Test;
            bool Skill2;
            bool Skill3;
            bool Skill4;
            bool BeatrixUlti;
            bool BeatrixSnipper;
            bool Selena;
            bool Kimmy2;
            bool Flameshot;
            bool HookFranco;;
            bool Gusion;
            bool Gusion2;
            bool Gusion3;
            bool KimmyAttack;
            bool FrancoUlt;
            bool Pharsa;
            bool Xavier;
            bool Paquito;
            bool Paquito2;
            bool Eudora;
            bool Yve;
            bool Martis;
            bool Chou;
            bool Badang;
            bool Argus;
            bool Change;
            bool Xavier2;
            bool Execute;
            bool Fanny;
            bool Tigreal;
            bool KimmyV2;
            bool Irithel;
            bool AutoFlameshot;
            bool AutoFlameshotV2;
        };
        sSkills Skills{0};

        struct sPriority {
            int Target = 0;
            bool AutoTakeSword;
        };
        sPriority Priority{0};
        
        struct sAutoSpell {
            bool Executed;
            bool FlameShoot;
            bool Vengeance;
            bool Flicker;
            bool Aegis;
        };
        sAutoSpell AutoSpell{0};
        
        struct sAutoRetribution {
            bool RedandBlue;
            bool Buff1;
            bool Buff2;
            bool TurtleLord;
            bool Turtle;
            bool Lord;
            bool Crab;
            bool BuffV3;
            bool litho;
            bool hasEnemyButton;
            int hasEnemyDistOnly;
            int iCalculateDamage;
            bool Test;
        };
        sAutoRetribution AutoRetribution{0};
        
        
        
    };
    sHelper Helper{0};
    
    Vector3 Dir = Vector3::zero();
    Vector3 Pos = Vector3::One();
    Vector3 NearestEnemyPos = Vector3::zero();
            int NearestEnemyGuid = 0;
            float NearestEnemyDist = 9999;
            bool RetriDistButton;
};
sAim Aim{0};

bool ActiveRetribution, ActiveAutoSkill;

//'''''MAPHACK INIT'''''//
struct sConfig {
   
    bool m_IDConf;
    bool MinimapIcon;
	bool MinimapIconEnable;
    bool HideLine;
    int MapSize = 341; //width & height
    ImVec2 StartPos = {(float)105, (float)0};
    bool ActiveSkill;
    bool DnsString = true;
    bool Bypass;
    float getFieldOfView;
    float setFieldOfView; 
    struct sInitImGui {
        bool g_Initialized;
        bool clearMousePos = true;
        bool bInitDone;
        uintptr_t thiz;
    };
    sInitImGui InitImGui{0};
    
    struct iThemes{
        bool Enable;
        bool AimBot;
        bool MagicBullet;;
        EThemeTarget Trigger;
        int Target = 0;
    };
    iThemes initThemes{0};
    
    struct sColorsESP {
        float *Line;
        float *Box;
        float *Name;
        float *Health;
        float *Distance;
    };
    sColorsESP ColorsESP{0};
    
    struct sESP {
        bool FPS;
        struct sPlayer {
            bool Line;
            bool RedDot;
            bool Box;
            bool Health;
            bool Name;
            bool Distance;
            bool Hero;
            bool CoolDown;
            bool CoolDown2;
            bool Circle;
            bool Alert;
            bool Damage;
            bool Defense;
            bool Magic;
            bool Nigga;
            bool Fps30;
            bool Fps60;
            bool Fps90;
            bool Fps100;
            bool Fps120;
            bool Visible;
            bool Antilag;
            bool CircleHealth;
            bool ShowPlayer;
            bool Health2;
            bool ShowMonster;
            bool ShowMonsterV2;
            bool ShowPlayerV2;
            bool SecondEsp;
            bool Round;
            bool HeroZ;
            bool Status;
			bool Locator2;
        };
        sPlayer Player{0};

        struct sMonster {
            bool Box;
            bool Health;
            bool Name;
            bool Alert;
            bool Locator;
            bool JungelAttack;
            bool ShowMonster;
            bool Minion;
            bool Rounded;
			bool Locator2;
        };
        sMonster Monster{0};
    };
    sESP ESP{0};

    struct sVisual {
		bool UnlockHero;
        bool UnlockSkin;
        bool UnlockEmblem;
        bool UnlockSkinV2;
        bool UnlockStarlight;
        bool MaphackIcon;
        bool MapHackIcon2;
		bool MapHackIcon3;
        bool HealthBar;
        bool ShowMonster;
        bool IconMap;
        bool FrameRate;
        bool UnlockSpell;
        bool Icon;
        bool RemoveGrass;
        bool ShowMonsterMap;
        bool HeadIcon;
        bool MonsterIcon;
        bool MonsterHealth;
        bool GrassEye;
        bool MonsterHeadIcon;
        bool MonsterBody;
        bool ShowJungle;
        bool ShowMonsterTest;
		bool NoGrass;
    };
    sVisual Visual{0};

    struct sAuto {
        struct sRetribution {
            bool Enable;
            bool Lord;
            bool Turtle;
            bool Buff;
            bool Crab;
            bool Litho;
            bool Crammer;
        };
        sRetribution Retribution{0};

        struct sHero {
            bool KimmyDoubleDamage;
        };
        sHero Hero{0};
    };
    sAuto Auto{0};

};
sConfig Config{0};

static float SetFieldOfView = 0, GetFieldOfView = 0;
static float sliderValue;
static float RangeCombo = 10.0;
static float RangePredict = 13.0;
static float TargetHP = 1750;
static float RangeFOV = 10.0;
static float speedAtt = 1.0f;
static float TargetHPPer = 40;
float SpeedPredict = 1;

enum ETargetPriority {
    Dist = 0,
    LowHP = 1,
    LowHPPercent = 2,
};

bool PerformanceInt;

static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 55.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

