#ifndef _FOURPLAYER_H
#define _FOURPLAYER_H

#include "Game/CameraMgr.h"

namespace Game
{
    
extern int gNaviNum;
extern int gVsNaviIndexArray[4];
extern int gDopeCountArray[4][2];

extern bool gFancyCamera;
extern PlayCamera* gCameraP3;
extern PlayCamera* gCameraP4;

int CalcNaviNum();
int getVSTeamID(int); // Gets the team idx of an index
int getVsPikiColor(int); // Gets the piki color of an index

} // namespace Game



#endif