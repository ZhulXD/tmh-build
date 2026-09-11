#include "ICON.h"
#include "SPELL.h"
#include "RANK.h"
#include "Flagsicon.h"
#include "MonsterIcon.h"
#include "AlertIcon.h"

struct Icon {
    GLuint texture = 0;
    int width = 0;
    int height = 0;
    bool IsValid = false;
};

std::vector<Icon> CountryIcon;
std::vector<Icon> MonsterIcon;
std::vector<Icon> MonsterAlert;
std::vector<Icon> HeroIcon;
std::vector<Icon> SpellIcon;
std::vector<Icon> RankIcon;

Icon ICTexture(int Id) {
    if (HeroIcon.empty() || Id < 0 || Id >= (int)HeroIcon.size()) {
        Icon emptyIcon{0, false};
        return emptyIcon;
    }
    switch(Id) {
	case 9995:
		return (HeroIcon.size() > 18) ? HeroIcon[18] : HeroIcon[0];
	case 9996:
		return (HeroIcon.size() > 16) ? HeroIcon[16] : HeroIcon[0];
	case 9997:
		return (HeroIcon.size() > 6) ? HeroIcon[6] : HeroIcon[0];
	case 9998:
		return (HeroIcon.size() > 16) ? HeroIcon[16] : HeroIcon[0];
	case 9999:
		return (HeroIcon.size() > 18) ? HeroIcon[18] : HeroIcon[0];
	default:
	    return HeroIcon[Id];
	}
}

Icon MonsterTexture(int Id) {
    switch(Id) {
	case 2002:
		return MonsterIcon[1];
        break;
	case 2003:
		return MonsterIcon[2];
        break;
	case 2004:
		return MonsterIcon[3];
        break;
	case 2005:
		return MonsterIcon[4];
        break;
	case 2006:
		return MonsterIcon[5];
        break;
	case 2008:
		return MonsterIcon[6];
        break;
	case 2009:
		return MonsterIcon[7];
        break;    
	case 2011:
		return MonsterIcon[8];
        break;
	case 2012:
		return MonsterIcon[9];
        break;    
	case 2013:
		return MonsterIcon[10];
        break;
	case 2056:
		return MonsterIcon[11];
        break;
	case 2059:
		return MonsterIcon[12];
        break;
	default:
	return MonsterIcon[Id];
	}
	return MonsterIcon[Id];
}

Icon MonsterAlertTexture(int Id) {
    switch(Id) {
	case 2002:
		return MonsterAlert[1];
        break;
	case 2003:
		return MonsterAlert[2];
        break;
	default:
	return MonsterAlert[Id];
	}
	return MonsterAlert[Id];
}

Icon SpellTexture(int Id) {
    switch(Id) {
	case 20060:
		return SpellIcon[1];
        break;
	case 20160:
		return SpellIcon[2];
        break;
	case 20150:
		return SpellIcon[3];
        break;
	case 20140:
		return SpellIcon[4];
        break;
	case 20100:
		return SpellIcon[5];
        break;
	case 20030:
		return SpellIcon[6];
        break;
	case 20070:
		return SpellIcon[7];
        break;    
	case 20080:
		return SpellIcon[8];
        break;
	case 20020:
		return SpellIcon[9];
        break;    
	case 20050:
		return SpellIcon[10];
        break;
	case 20040:
		return SpellIcon[11];
        break;
	case 20190:
		return SpellIcon[12];
        break;
	default:
	return SpellIcon[Id];
	}
	return SpellIcon[Id];
}

Icon RankTexture(const int uiRankLevel) {
    if (uiRankLevel <= 136) {
        if (uiRankLevel <= 11) {
            return RankIcon[1];
        }
        if (uiRankLevel < 27) {
            return RankIcon[2];
        }
        if (uiRankLevel < 47) {
            return RankIcon[3];
        }
        if (uiRankLevel < 77) {
            return RankIcon[4];
        }
        if (uiRankLevel < 107) {
            return RankIcon[5];
        }
        return RankIcon[6];
    } else {
        int Star = uiRankLevel - 136;
        if (Star <= 24) {
            return RankIcon[7];
        }
        if (Star <= 49) {
            return RankIcon[8];
        }
        if (Star <= 99) {
            return RankIcon[9];
        }
        return RankIcon[10];
    }
      return RankIcon[0]; 
}
