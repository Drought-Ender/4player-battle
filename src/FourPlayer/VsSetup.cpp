#include "FourPlayer.h"
#include "Game/Piki.h"
#include "Game/Navi.h"
#include "JSystem/JUtility/JUTGamePad.h"
#include "Game/NaviParms.h"
#include "Game/NaviState.h"
#include "Game/Entities/ItemPikihead.h"


namespace Game
{
    
int gVsNaviIndexArray[4] = { Red, Blue, Red, Blue };
int gDopeCountArray[4][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0} };

int Navi::getVsTeam() {
    return gVsNaviIndexArray[mNaviIndex];
}

int getVSTeamID(int idx) {
    EPikiKind pikiColor = (EPikiKind)gVsNaviIndexArray[idx];
    switch (pikiColor)
    {
    case Red:
        return 0;
    case Blue:
        return 1;
    }
    return pikiColor;
}

// onTeam__Q24Game4NaviFi
bool Navi::onTeam(int color) {
    return getVsTeam() == color;
}

int CalcNaviNum() {
    if (JUTGamePad::mPadStatus[2].err <= PAD_ERR_NO_CONTROLLER) {
        return 2;
    }
    if (JUTGamePad::mPadStatus[3].err <= PAD_ERR_NO_CONTROLLER) {
        return 3;
    }
    return 4;
}

int Navi::getDopeCount(int dope) {
    if (gameSystem->isVersusMode()) {
        return gDopeCountArray[getVSTeamID(getVsTeam())][dope]; // what a mouthfull
    }
    else {
        return playData->getDopeCount(dope);
    }
}

bool Navi::hasDope(int dope) {
    if (gameSystem->isVersusMode()) {
        return gDopeCountArray[getVSTeamID(getVsTeam())][dope] > 0; 
    }
    else {
        return playData->hasDope(dope);
    }
}

void Navi::useDope(int dope) {
    if (gameSystem->isVersusMode()) {
        gDopeCountArray[getVSTeamID(getVsTeam())][dope]--; 
    }
    else {
        playData->useDope(dope);
    }
}

void Navi::incDopeCount(int dope) {
    if (gameSystem->isVersusMode()) {
        GameMessageVsGetDoping dopeMsg (mNaviIndex, dope);
        gameSystem->mSection->sendMessage(dopeMsg);
        gDopeCountArray[getVSTeamID(getVsTeam())][dope]++; 
    }
    else {
        playData->incDopeCount(dope);
    }
}

} // namespace Game


