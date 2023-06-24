#include "FourPlayer.h"
#include "Game/Piki.h"
#include "Game/Navi.h"
#include "JSystem/JUtility/JUTGamePad.h"
#include "Game/NaviParms.h"
#include "Game/NaviState.h"
#include "Game/Entities/ItemPikihead.h"
#include "Game/PikiMgr.h"
#include "PikiAI.h"
#include "Game/cellPyramid.h"
#include "ebi/Screen/TTitleMenu.h"

namespace Game
{
    
int gVsNaviIndexArray[4] = { Red, Blue, Blue, Red };
int gDopeCountArray[4][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0} };

void SetVsTeam(int idx, TeamID teamID) {
    EPikiKind pikiColor = (EPikiKind)teamID;
    switch (teamID)
    {
    case TEAM_RED:
        pikiColor = Red;
        break;
    case TEAM_BLUE:
        pikiColor = Blue;
        break;
    }
    gVsNaviIndexArray[idx] = pikiColor;
}

int Navi::getVsPikiColor() {
    return gVsNaviIndexArray[mNaviIndex];
}

int Navi::getVsTeam() {
    return Game::getVsTeam(mNaviIndex);
}

int getVsPikiColor(int idx) {
    return gVsNaviIndexArray[idx];
}

int getVsTeam(int idx) {
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
    return getVsPikiColor() == color;
}

bool Navi::onVsTeam(int color) {
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
        return gDopeCountArray[getVsTeam()][dope];
    }
    else {
        return playData->getDopeCount(dope);
    }
}

bool Navi::hasDope(int dope) {
    if (gameSystem->isVersusMode()) {
        return gDopeCountArray[getVsTeam()][dope] > 0; 
    }
    else {
        return playData->hasDope(dope);
    }
}

void Navi::useDope(int dope) {
    if (gameSystem->isVersusMode()) {
        gDopeCountArray[getVsTeam()][dope]--; 
    }
    else {
        playData->useDope(dope);
    }
}

void Navi::incDopeCount(int dope) {
    if (gameSystem->isVersusMode()) {
        GameMessageVsGetDoping dopeMsg (mNaviIndex, dope);
        gameSystem->mSection->sendMessage(dopeMsg);
        gDopeCountArray[getVsTeam()][dope]++; 
    }
    else {
        playData->incDopeCount(dope);
    }
}

void PikiMgr::doEntry() {

    
    u8 flag = mFlags[1];
    if (gameSystem->isVersusMode()) {
        u8 vsFlags[4];
        for (int i = 0; i < 4; i++) {
            vsFlags[i] = 0x0;
            for (int j = 0; j < 4; j++) {
                if (getVsPikiColor(j) != i) {
                    vsFlags[i] |= 0x10 << j;
                }
            }
        }
        for (int i = 0; i < mMax; i++) {
            if (mOpenIds[i]) {
                continue;
            }

            Piki* piki = &mArray[i];
            if (flag & 1 && !piki->isMovieActor()) {
                piki->mLod.mFlags &= ~0xF4;
            }

            for (int i = 0; i < 4; i++) {
                if (piki->mPikiKind == i && mFlags[0] & (1 << i)) {
                    piki->mLod.mFlags &= ~vsFlags[i];
                }
            }
            piki->doEntry();
        }
    }
    else {
        for (int i = 0; i < mMax; i++) {
            if (mOpenIds[i]) {
                continue;
            }
            Piki* piki = &mArray[i];
            if (flag & 1 && !piki->isMovieActor()) {
                piki->mLod.mFlags &= ~0xF4;
            }
            piki->doEntry();
        }
    }
}

void NaviMgr::doEntry() {
    u8 vsFlags[4];
    for (int viewerNavi = 0; viewerNavi < 4; viewerNavi++) {
        vsFlags[viewerNavi] = 0x0;
        for (int viewNavi = 0; viewNavi < 4; viewNavi++) {
            if (getVsPikiColor(viewerNavi) != getVsPikiColor(viewNavi)) {
                vsFlags[viewerNavi] |= 0x10 << viewNavi;
            }
        }
    }
    u8 flag = _5C;
    for (int i = 0; i < mMax; i++) {
        if (mOpenIds[i]) {
            continue;
        }

        Navi* navi = &mArray[i];
        if (flag & 1 && !navi->isMovieActor()) {
            navi->mLod.mFlags &= ~0xF4;
        }
        else if (navi->isMovieActor()) {
            navi->mLod.mFlags |= 0xF4;
        }

        if (gameSystem->isVersusMode()) {
            for (int i = 0; i < 4; i++) {
                if (navi->mNaviIndex == i && pikiMgr->mFlags[0] & (1 << getVsPikiColor(i))) {
                    OSReport("Flagged\n");
                    navi->mLod.mFlags &= ~vsFlags[i];
                }
            }
        }
        navi->doEntry();
    }
}

} // namespace Game

// void ebi::Screen::TTitleMenu::doOpenScreen(ArgOpen* arg) {
//     P2ASSERT(arg);
//     ArgOpenTitleMenu* menuArg = static_cast<ArgOpenTitleMenu*>(arg);
    
// }


// Game::Navi* PikiAI::Brain::searchOrima() {
//     Vector3f pikiPos = mPiki->getPosition();
//     Sys::Sphere targetSphere (pikiPos, 300.0f);

//     Game::CellIteratorArg iCellArg = targetSphere;
//     Game::CellIterator iCell = iCellArg;
//     CI_LOOP(iCell) {
//         Game::CellObject* cell = *iCell;
//         if (cell->isNavi()) {
//             Game::Navi* navi = static_cast<Game::Navi*>(cell);
//             if (navi->isAlive()) {
//                 Vector3f naviPos = navi->getPosition();
//                 f32 distance = _distanceBetween(pikiPos, naviPos);
//                 if (distance < 300.0f && Game::gameSystem->isVersusMode()) {
//                     if (mPiki->mPikiKind != navi->getVsPikiColor()) {
//                         return navi;
//                     }
//                 }
//             }
//         }
//     }
// }



