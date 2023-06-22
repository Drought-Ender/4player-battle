#ifndef _FOURPLAYER_H
#define _FOURPLAYER_H

#include "Game/CameraMgr.h"

struct Controller;

extern int mRealWinCounts[4];

namespace Game
{

enum TeamID {
    TEAM_RED = 0,
    TEAM_BLUE = 1
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