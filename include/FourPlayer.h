#ifndef _FOURPLAYER_H
#define _FOURPLAYER_H

#include "Game/CameraMgr.h"
#include "JSystem/J2D/J2DPrint.h"
#include "ConfigEnums.h"

struct Controller;

extern int mRealWinCounts[4];

extern bool gDrawVsMenu;

struct VsOptionsMenu {
    VsOptionsMenu();
    void init();
    bool update();
    void draw(Graphics&);

    Controller* mController;
    int mPageNumber;
    int mSelectedOption;
    int mCursorOptionIndex;
    const char* mTooltipMessage;
};

struct Option {
    const char* name;
    const char* valueStrings[10];
    const char* toolTipStrings[10];
    const int valueNum;
    int value; // doubles as default value

    void print(J2DPrint& printer, J2DPrint& printer2, int idx);

    int getValue() {
        return value;
    }

    void incOption() {
        value++;
        if (value == valueNum) {
            value = 0;
        }
    }

    void decOption() {
        if (value == 0) {
            value = valueNum;
        }
        value--;
    }

    const char* getTooltipString() {
        return toolTipStrings[value];
    }
};

int GetConfigSize();

extern Option gOptions[];
extern int gConfig[];



enum OptionsEnum {
    MAP_TYPE,
    MARBLE_BURY,
    MARBLE_CARRY,
    CHERRY_RATE,
    SPICY_TYPE,
    BITTER_TYPE,
    SPAWN_SHEARWIG,
    EGG_DROPS,
    AUTOPLUCK,
    MARBLE_RETURN,
    VS_Y,
    VS_HIBA,
    PIKI_DIE,
    SPRAY_CARD
};

namespace ConfigEnums {
    bool EggCanSpray() {
        return gConfig[EGG_DROPS] == EGG_ALL || gConfig[EGG_DROPS] == EGG_NOMITE;
    }
    bool EggCanMites() {
        return gConfig[EGG_DROPS] == EGG_ALL || gConfig[EGG_DROPS] == EGG_NOSPRAY;
    }
    bool EggCanDoubleNectar() {
        return gConfig[EGG_DROPS] != EGG_SINGLE;
    }
};

extern VsOptionsMenu* gOptionMenu;

namespace Game
{

enum TeamID {
    TEAM_RED = 0,
    TEAM_BLUE = 1,
    TEAM_WHITE,
    TEAM_PURPLE
};

    
extern int gNaviNum;
extern int gVsNaviIndexArray[4];
extern int gDopeCountArray[4][2];

extern bool gFancyCamera;
extern PlayCamera* gCameraP3;
extern PlayCamera* gCameraP4;
extern Controller* gControllerP3;
extern Controller* gControllerP4;



int CalcNaviNum();
int getVsTeam(int);
int getVsPikiColor(int); // Gets the piki color of an index
void SetVsTeam(int idx, TeamID team);
int getTeamFromPiki(int pikiColor) {
	switch (pikiColor)
    {
    case 1: // red
        return TEAM_RED;
    case 0: // blue
        return TEAM_BLUE;
	case 4: // white
		return TEAM_WHITE;
	case 3: // purple
		return TEAM_PURPLE; 
    }
    JUT_PANIC("GET PIKI %i\n", pikiColor);
}
int getPikiFromTeam(int);



} // namespace Game

// a sqrt function suited to all domains
f32 domainSqrt(f32 x) { 
    if (x > 0.0f) {
        return sqrtf(x);
    }
    else {
        x = -x;
        return -sqrtf(x);
    }
}


#endif