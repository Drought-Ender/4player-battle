#ifndef _FOURPLAYER_H
#define _FOURPLAYER_H

namespace Game
{
    
extern int gNaviNum;
extern int gVsNaviIndexArray[4];
extern int gDopeCountArray[4][2];

int CalcNaviNum();
int getVSTeamID(int);

} // namespace Game



#endif