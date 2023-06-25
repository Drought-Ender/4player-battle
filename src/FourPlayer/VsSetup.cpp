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
#include "Game/mapParts.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/mapParts.h"
#include "types.h"
#include "Vector3.h"
#include "Game/Entities/Item.h"
#include "Game/EnemyBase.h"
#include "Game/CurrTriInfo.h"
#include "Game/gamePlayData.h"
#include "Game/generalEnemyMgr.h"
#include "Game/Cave/Node.h"

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


void MapRoom::placeObjects(Cave::FloorInfo* floorInfo, bool b) // basically matching
{
	if (!mObjectLayoutInfo) {
		return;
	}
	for (int nodeType = 0; nodeType < 8; nodeType++) {
		for (int nodeIdx = 0; nodeIdx < mObjectLayoutInfo->getCount(nodeType); nodeIdx++) {
			ObjectLayoutNode* node = static_cast<ObjectLayoutNode*>(mObjectLayoutInfo->getNode(nodeType, nodeIdx));
			for (int subIdx = 0; subIdx < node->getBirthCount(); subIdx++) {
				switch (nodeType)
				{
				case OBJLAYOUT_Hole: {
					ItemHole::Item* hole = static_cast<ItemHole::Item*>(ItemHole::mgr->birth());
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					CurrTriInfo triInfo;
					triInfo.mPosition = birthPos;
					f32 minY = 0.0f;
					if (mapMgr) {
						triInfo._0C = 0;
						mapMgr->getCurrTri(triInfo); 
						minY = triInfo.mMinY;
					}
					birthPos.y = minY;
					if (gameSystem->isChallengeMode()) {
						ItemHole::InitArg holeArg;
						holeArg.mInitialState = ItemHole::Hole_Close;
						hole->init(&holeArg);
					}
					else {
						hole->init(nullptr);
					}
					hole->mFaceDirection = node->getDirection();
					hole->setPosition(birthPos, false);
					if (floorInfo->useKaidanBarrel()) {
						ItemBarrel::Item* barrel = static_cast<ItemBarrel::Item*>(ItemBarrel::mgr->birth());
						barrel->init(nullptr);
						barrel->setPosition(birthPos, false);
					}
					break;
				}
				case OBJLAYOUT_Pod: {
					if (gameSystem->isVersusMode()) {
						break;
					}
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_POD, 0);
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = 0.0f;
					pod->init(nullptr);
					pod->mFaceDir = node->getDirection();
					pod->setPosition(birthPos, false);
					break;
				}
				case OBJLAYOUT_VsBlueOnyon: {
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_ONYON, ONYON_TYPE_BLUE);
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = 0.0f;
					pod->init(nullptr);
					pod->mFaceDir = node->getDirection();
					pod->setPosition(birthPos, false);
					break;
				}
				case OBJLAYOUT_VsRedOnyon: {
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_ONYON, ONYON_TYPE_RED);
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = 0.0f;
					pod->init(nullptr);
					pod->mFaceDir = node->getDirection();
					pod->setPosition(birthPos, false);
					break;
				}
				case OBJLAYOUT_Fountain: {
					ItemBigFountain::Item* fountain = static_cast<ItemBigFountain::Item*>(ItemBigFountain::mgr->birth());
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = 0.0f;
					if (gameSystem->isChallengeMode()) {
						ItemBigFountain::InitArg fountainArg;
						fountainArg.mInitState = 3; // Close state (lack of an enum)
						fountain->init(&fountainArg);
					}
					else {
						fountain->init(nullptr);
					}
					fountain->mFaceDir = node->getDirection();
					fountain->setPosition(birthPos, false);
					break;
				}
				case OBJLAYOUT_Enemy: {
					Vector3f birthPos;
					birthPos.y = 0.0f;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = mapMgr->getMinY(birthPos);
					EnemyBirthArg birthArg;
					birthArg.mFaceDir  = node->getDirection();
					birthArg.mPosition = birthPos;
					
					birthArg.mOtakaraItemCode = node->getExtraCode();
					birthArg.mTekiBirthType = (EnemyTypeID::EEnemyTypeID)node->getObjectType();
					node->isFixedBattery();

					bool canSpawnTeki  = true;
					bool isWaterwraith = false;
					EnemyTypeID::EEnemyTypeID enemyType = (EnemyTypeID::EEnemyTypeID)node->getObjectId();
					if (enemyType == EnemyTypeID::EnemyID_BlackMan) {
						if (playData->mCaveSaveData.mIsWaterwraithAlive) {
							isWaterwraith = true;
						}
						else {
							canSpawnTeki = false;
						}
					}

					if (canSpawnTeki) {
						EnemyBase* enemy = generalEnemyMgr->birth(node->getObjectId(), birthArg);
						if (enemy) {
							enemy->init(nullptr);
						}
						if (isWaterwraith) {
							BlackMan::Obj* waterwraith = static_cast<BlackMan::Obj*>(enemy);
							waterwraith->setTimer(floorInfo->mParms.mWaterwraithTimer);
							static_cast<RoomMapMgr*>(mapMgr)->mBlackMan = waterwraith;
						}
					}
					break;
				}
				case OBJLAYOUT_Item: {
					PelletIndexInitArg pelletIndex (node->getObjectId());
					Pellet* pellet = pelletMgr->birth(&pelletIndex);
					if (!pellet) {
						break;
					}
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					if (mapMgr) {
						birthPos.y = mapMgr->getMinY(birthPos);
						birthPos.y += pellet->getCylinderHeight() / 2;
					}
					else {
						birthPos.y = 0.0f;
					}
					pellet->setPosition(birthPos, false);
					Vector3f rotation;
					rotation.y = node->getDirection();
					rotation.x = 0.0f;
					rotation.z = 0.0f;
					Matrixf pelletRot;
					pelletRot.makeTR(Vector3f::zero, rotation);
					node->getDirection();
					pellet->setOrientation(pelletRot);
					pellet->allocateTexCaster();
					break;
				}
				case OBJLAYOUT_Gate: {
					int doorIdx = node->getBirthDoorIndex();
					if (doorIdx == -1) {
						break;
					}
					RoomDoorInfo* doorinfo = &mDoorInfos[doorIdx];
					Vector3f birthPos = doorinfo->mWaypoint->mPosition;
					f32 dir = JMath::atanTable_.atan2_(doorinfo->mLookAtPos.x, doorinfo->mLookAtPos.z);
					ItemGateInitArg gateArg;
					gateArg.mFaceDir = dir;

					ItemGate* gate = static_cast<ItemGate*>(itemGateMgr->birth());
					gate->init(&gateArg);
					f32 health = static_cast<Cave::GateNode*>(node)->mUnit->mInfo->mLife;
					gate->mMaxSegmentHealth     = health;
					gate->mCurrentSegmentHealth = health;
					gate->setPosition(birthPos, false);
					break;
				}
				}
			}

		}
	}
}


} // namespace Game