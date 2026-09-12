/** xhasbi **/
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "IconList.h"
#include "base64.hpp"

void writeToFile(std::string dir, std::string buf) {
    std::ofstream os(dir.c_str(), std::ios::trunc);
    os.write(buf.c_str(), buf.length());
    os.close();
}

std::string CountryIDtoList(int Id) {
	std::string strICCountry;    
	switch(Id) {
    	default:
    	strICCountry +=  CountryList[Id];   
 	}
	return strICCountry;
}

std::string IconAssets(int Id) {
    std::string strICHero;
    switch(Id) {
		default:
		strICHero += iconHeroList[Id];
	}
	return strICHero;
}

std::string MonsterAssets(int Id) {
    std::string strICMonster;
    switch(Id) {
		default:
		strICMonster += MonsterList[Id];
	}
	return strICMonster;
}

std::string MonsterAlertIcon(int Id) {
    std::string strICMonsterAlert;
    switch(Id) {
		default:
		strICMonsterAlert += MonsterAlertList[Id];
	}
	return strICMonsterAlert;
}

std::string SpellAssets(int Id) {
    std::string strICHero;
    switch(Id) {
	default:
	strICHero += iconSpellList[Id];
	}
	return strICHero;
}

std::string RankAssets(const int uiRankLevel) {
    std::string strICHero;
    strICHero += iconRankList[uiRankLevel];
    return strICHero;
}

bool LoadTextureFromFile(const char* filename, Icon* Image) {
    int image_width = 0;
    int image_height = 0;
    int n;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    Image->texture = image_texture;
    Image->width = image_width;
    Image->height = image_height;

    return true;
}

bool LoadTextureFromMemory(const unsigned char* buffer, int len, Icon* Image) {
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load_from_memory(buffer, len, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    Image->texture = image_texture;
    Image->width = image_width;
    Image->height = image_height;
    Image->IsValid = true;

    return true;
}

// check iconlist
bool AttachCountryDone;
void AttachCountry() {
	std::string apkPkg = Tools::GetPackageName(Env(), Context());
	std::ifstream input_file("/data/data/" + apkPkg + "/.bak");
	int Ctry = sizeof(CountryList) / sizeof(CountryList[0]);
	for (int a = 0;a < Ctry;a++) {
		Icon Test;
		std::string packageName = "com.mobile.legends";
		std::string Path = std::string("/data/data/") + apkPkg.c_str() + std::string("/files/");
        Path += to_string(a);
		writeToFile(Path, base64::from_base64(CountryIDtoList(a)));
		Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
		std::remove(Path.c_str());
		CountryIcon.push_back(Test);
	}
}

bool AttachMonsterDone;
void AttachMonster() {
	std::string apkPkg = Tools::GetPackageName(Env(), Context());
	std::ifstream input_file("/data/data/" + apkPkg + "/.bak");
	int Ctry = sizeof(MonsterList) / sizeof(MonsterList[0]);
	for (int a = 0;a < Ctry;a++) {
		Icon Test;
		std::string packageName = "com.mobile.legends";        
		std::string Path = std::string("/data/data/") + apkPkg.c_str() + std::string("/files/");
        Path += to_string(a);        
		writeToFile(Path, base64::from_base64(MonsterAssets(a)));        
		Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);        
		std::remove(Path.c_str());        
		MonsterIcon.push_back(Test);   
	}
}

bool AttachMonsterAlertDone;
void AttachMonsterAlert() {
	std::string apkPkg = Tools::GetPackageName(Env(), Context());
	std::ifstream input_file("/data/data/" + apkPkg + "/.bak");
	int Ctry = sizeof(MonsterAlertList) / sizeof(MonsterAlertList[0]);    
	for (int a = 0;a < Ctry;a++) {
		Icon Test;        
		std::string packageName = "com.mobile.legends";        
		std::string Path = std::string("/data/data/") + apkPkg.c_str() + std::string("/files/");
        Path += to_string(a);        
		writeToFile(Path, base64::from_base64(MonsterAlertIcon(a)));        
		Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);        
		std::remove(Path.c_str());        
		MonsterAlert.push_back(Test);   
	}
}

bool AttachIconDone;
void AttachIcon() {
    HeroIcon.clear();
    int size = sizeof(iconHeroList) / sizeof(iconHeroList[0]);
    for (int i = 0; i < size; i++) {
        Icon Test{0, false, 0, 0};
        std::string raw = base64::from_base64(IconAssets(i));
        if (!raw.empty()) {
            LoadTextureFromMemory((const unsigned char*)raw.data(), (int)raw.size(), &Test);
        }
        HeroIcon.push_back(Test);
    }
}

bool AttachSpellDone;
void AttachSpell() {
	std::string apkPkg = Tools::GetPackageName(Env(), Context());
	std::ifstream input_file("/data/data/" + apkPkg + "/.bak");
	int size = sizeof(iconSpellList) / sizeof(iconSpellList[0]);
	for (int i = 0;i < size;i++) {
        Icon Test;
        std::string Path = std::string("/data/data/") + apkPkg.c_str() + std::string("/files/");
        Path += to_string(i);
        writeToFile(Path, base64::from_base64(SpellAssets(i)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        SpellIcon.push_back(Test);
    }
}

bool AttachRankDone;
void AttachRank() {
    std::string apkPkg = Tools::GetPackageName(Env(), Context());
	std::ifstream input_file("/data/data/" + apkPkg + "/.bak");
    int size = sizeof(iconRankList) / sizeof(iconRankList[0]);
    for (int i = 0;i < size;i++) {
        Icon Test;
        std::string Path = std::string("/data/data/") + apkPkg.c_str() + std::string("/files/");
        Path += to_string(i);
        writeToFile(Path, base64::from_base64(RankAssets(i)));
        Test.IsValid = LoadTextureFromFile(Path.c_str(), &Test);
        std::remove(Path.c_str());
        RankIcon.push_back(Test);
    }
}

static float ColorHealth[3] = {0.9f, 0.2f, 0.5f};
float IconAlpha = 1.0f;
// Variables for size and health bar thickness
static int heroSize = 64;
static int heroHealthThin = 3;
static int monsterSize = 64;
static int monsterHealthThin = 6;

namespace ICON {
    int ICSize = 38;
	int ICHealthThin = 3;
}
using namespace ICON;

void DrawIconHero(ImVec2 position, int HeroID, int Hp, int HpMax) {
    auto IconI = ICTexture(HeroID);
	float a_max = ((3.14159265359f * 2));
    float XDX = (ICSize / 2 + 0.121f), XDR = ICSize / 2;
    if (IconI.IsValid && IconI.texture != 0) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
		if (HpMax > 0) {
            ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
            ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
        }
    } else {
        // Safe vector fallback: red circle with border & health arc (zero GL crash risk)
        float r = (float)ICSize * 0.4f;
        ImGui::GetBackgroundDrawList()->AddCircleFilled(position, r, IM_COL32(255, 50, 50, 230));
        ImGui::GetBackgroundDrawList()->AddCircle(position, r, IM_COL32(255, 255, 255, 255), 0, 1.5f);
        if (HpMax > 0) {
            ImGui::GetBackgroundDrawList()->PathArcTo(position, r + 2.0f, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
            ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, 255), ImDrawFlags_None, (float)ICHealthThin);
        }
    }
}

void DrawHero(ImVec2 position, int HeroID, int Hp, int HpMax, int Size = 55, int HealthThin = 3) {
    auto IconI = ICTexture(HeroID);
	float a_max = ((3.14159265359f * 2));
    float XDX = (Size / 2 + 0.121f), XDR = Size / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
		ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
        ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, HealthThin);
    }
}

void RoomInfoHero(int HeroID, float Size = 38) {
    auto IconI = ICTexture(HeroID);
    if (IconI.IsValid) {
		ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(Size, Size));
	}
}

void RoomInfoRank(const int uiRankLevel, float Size = 40) {
    auto IconI = RankTexture(uiRankLevel);
    if (IconI.IsValid) {
        ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(Size, Size));
    }
}

void RoomInfoSpell(int HeroID, float Size = 38) {
    auto IconI = SpellTexture(HeroID);
    if (IconI.IsValid) {
		ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(Size, Size));
	}
}

void DrawSpell(ImVec2 position, int HeroID, int Size = 30) {
    auto IconI = SpellTexture(HeroID);
    float a_max = ((3.14159265359f * 2));
    float XDX = (Size / 2 + 0.121f), XDR = Size / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
        //ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
        //ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, HealthThin);
    }
}

void DrawLogo(ImDrawList *draw, ImVec2 position, int ID, int Hp, int HpMax, int ICSize = 60, int ICHealthThin = 3, float round = 25.0f, bool health = true) {
    auto IconI = ICTexture(ID);
    float a_max = ((3.14159265359f * 2));
    float XDX = (ICSize / 2 + 0.121f), XDR = ICSize / 2;
    if (IconI.IsValid) {
        draw->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), round);
        if(health){
            draw->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
            draw->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
        }
        //draw->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
        //draw->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
    }
}

void DrawIconMonster(ImVec2 position, int HeroID, int Hp, int HpMax) {
    auto IconI = MonsterTexture(HeroID);
	float a_max = ((3.14159265359f * 2));
    float XDX = (ICSize / 2 + 0.121f), XDR = ICSize / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - ICSize + XDX, position.y - ICSize + XDX), ImVec2(position.x + ICSize - XDX, position.y + ICSize - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
		ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
        ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, ICHealthThin);
    }
}

void DrawMonsters(ImVec2 position, int HeroID, int Size = 64) {
    auto IconI = MonsterTexture(HeroID);
    float a_max = ((3.14159265359f * 2));
    float XDX = (Size / 2 + 0.121f), XDR = Size / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
    }
}

void DrawAlert(int HeroID, float Size, ImVec2 position) {
    auto IconI = MonsterAlertTexture(HeroID);
    if (IconI.IsValid) {
        ImVec2 screenCenter((float)(screenWidth / 2), (float)(screenHeight / 8.7f));
        float XDX = 0.0f; // Kamu perlu mendefinisikan XDX
        float IconAlpha = 1.0f; // Kamu perlu mendefinisikan IconAlpha
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
    }
}

void DrawMonster2(ImVec2 position, int HeroID, int Hp, int HpMax, int Size = 64, int HealthThin = 6) {
    auto IconI = MonsterTexture(HeroID);
	float a_max = ((3.14159265359f * 2));
    float XDX = (Size / 2 + 0.121f), XDR = Size / 2;
    if (IconI.IsValid) {
        ImGui::GetBackgroundDrawList()->AddImageRounded((void*)(uintptr_t)IconI.texture, ImVec2(position.x - Size + XDX, position.y - Size + XDX), ImVec2(position.x + Size - XDX, position.y + Size - XDX), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255,255,255, IconAlpha * 255), 25.0f);
		ImGui::GetBackgroundDrawList()->PathArcTo(position, XDR, (-(a_max / 4.0f)) + (a_max / HpMax) * (HpMax - Hp), a_max - (a_max / 4.0f));
        ImGui::GetBackgroundDrawList()->PathStroke(IM_COL32(ColorHealth[0] * 255, ColorHealth[1] * 255, ColorHealth[2] * 255, IconAlpha * 255), ImDrawFlags_None, HealthThin);
    }
}

void RoomInfoCountry2(int id, float Size=38) {
auto IconI = CountryIcon[id];    
 if (IconI.IsValid) {
        ImGui::Image((void*)(uintptr_t)IconI.texture, ImVec2(Size, Size));    }
}
