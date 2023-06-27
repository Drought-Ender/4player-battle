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
#include "Game/Cave/RandMapMgr.h"
#include "Dolphin/rand.h"
#include "Game/Entities/PelletNumber.h"

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
	case TEAM_WHITE:
		pikiColor = White;
		break;
	case TEAM_PURPLE:
		pikiColor = Purple;
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
    return getTeamFromPiki((EPikiKind)gVsNaviIndexArray[idx]);
}

int getPikiFromTeam(int idx) {
	EPikiKind pikiColor = (EPikiKind)idx;
	switch (idx)
    {
    case TEAM_RED:
        pikiColor = Red;
        break;
    case TEAM_BLUE:
        pikiColor = Blue;
        break;
	case TEAM_WHITE:
		pikiColor = White;
		break;
	case TEAM_PURPLE:
		pikiColor = Purple;
		break;
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

Cave::RandMapScore::RandMapScore(MapUnitGenerator* generator)
{
	mGenerator       = generator;
	mVersusRedScore = 0;
	mVersusBlueScore  = 0;
	mFixObjNodes     = new MapNode*[FIXNODE_Count];
	mFixObjGens      = new BaseGen*[FIXNODE_Count];

	for (int i = 0; i < FIXNODE_Count; i++) {
		mFixObjNodes[i] = nullptr;
		mFixObjGens[i]  = nullptr;
	}
}

Cave::MapNode* Cave::RandMapScore::getRandRoomMapNode()
{
	int counter = 0;
	MapNode* mapList[16];
	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode)
	{
		if (currNode->mUnitInfo->getUnitKind() == UNITKIND_Room) {
			mapList[counter] = currNode;
			counter++;
		}
	}

	MapNode* targetNode;
	if (counter) {
		return mapList[(int)(counter * randFloat())];
	}

	return nullptr;
}

void Cave::RandMapScore::setVersusOnyon()
{

	if (!getFixObjNode(FIXNODE_VsRedOnyon) && !getFixObjNode(FIXNODE_VsBlueOnyon) && !getFixObjNode(FIXNODE_VsWhiteOnyon) && !getFixObjNode(FIXNODE_VsPurpleOnyon)) {
		MapNode* targetNode    = getRandRoomMapNode();
		MapNode* onyonNodes[4] = { nullptr, nullptr, nullptr, nullptr };
		BaseGen* onyonGens[4]  = { nullptr, nullptr, nullptr, nullptr };

		if (targetNode) {

			FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode) {
				currNode->mVsScore = 10000;
			}

			OSReport("Set versus onyon\n");
			calcNodeScore(targetNode);

			onyonNodes[0] = getMaxScoreRoomMapNode(targetNode, &onyonGens[0]);
			calcNodeScore(onyonNodes[0]);

			subNodeScore();


			onyonNodes[1] = getMaxScoreRoomMapNode(onyonNodes[0], &onyonGens[1]);
			calcNodeScore(onyonNodes[1]);

			subNodeScore();

            onyonNodes[2] = getMaxScoreRoomMapNode(2, onyonNodes, &onyonGens[2]);
			
			JUT_ASSERT(onyonNodes[2], "NO ROOM FOR WHITE ONYON");
			calcNodeScore(onyonNodes[2]);
			

			
			onyonNodes[3] = getMaxScoreRoomMapNode(3, onyonNodes, &onyonGens[3]);
			JUT_ASSERT(onyonNodes[3], "NO ROOM FOR PURPLE ONYON");
			calcNodeScore(onyonNodes[3]);
			subNodeScore();

			onyonNodes[2] = getMaxScoreRoomMapNode(2, onyonNodes, &onyonGens[2]);
			calcNodeScore(onyonNodes[2]);

			mFixObjNodes[FIXNODE_VsRedOnyon]  = onyonNodes[0];
			mFixObjNodes[FIXNODE_VsBlueOnyon] = onyonNodes[1];
            mFixObjNodes[FIXNODE_VsWhiteOnyon] = onyonNodes[2];
			mFixObjNodes[FIXNODE_VsPurpleOnyon] = onyonNodes[3];

			mFixObjGens[FIXNODE_VsRedOnyon]  = onyonGens[0];
			mFixObjGens[FIXNODE_VsBlueOnyon] = onyonGens[1];
            mFixObjGens[FIXNODE_VsWhiteOnyon] = onyonGens[2];
			mFixObjGens[FIXNODE_VsPurpleOnyon] = onyonGens[3];
			subNodeScore();
		}
	}
}

void Cave::MapNode::copyNodeScoreToVersusScore() { mVsScore = mNodeScore; }


Cave::MapNode* Cave::RandMapScore::getMaxScoreRoomMapNode(MapNode* mapNode, BaseGen** maxScoreGen)
{
	MapNode* maxScoreNode = nullptr;
	int maxScore          = 0;
	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode)
	{
		if (currNode != mapNode && currNode->mUnitInfo->getUnitKind() == UNITKIND_Room) {
			int nodeScore = currNode->getNodeScore() + 10;
			BaseGen* gen  = currNode->mUnitInfo->getBaseGen();
			if (gen) {
				FOREACH_NODE(BaseGen, gen->mChild, currGen)
				{
					if (currGen->mSpawnType == BaseGen::Start) {
						if (nodeScore > maxScore || (nodeScore == maxScore && randWeightFloat(1.0f) < 0.5f)) {
							*maxScoreGen = currGen;
							maxScoreNode = currNode;
							maxScore     = nodeScore;
						}
					}
				}
			}
		}
	}
	return maxScoreNode;
}

Cave::MapNode* Cave::RandMapScore::getMaxScoreRoomMapNode(int count, MapNode** mapNode, BaseGen** maxScoreGen)
{
	MapNode* maxScoreNode = nullptr;
	int maxScore          = 0;
	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode)
	{
		bool doSkip = false;
        for (int i = 0; i < count; i++) {
            if (currNode == mapNode[i]) {
                doSkip = true;
            }
        }
		if (!doSkip && currNode->mUnitInfo->getUnitKind() == UNITKIND_Room) {
			int nodeScore = currNode->getNodeScore() + 10;
			BaseGen* gen  = currNode->mUnitInfo->getBaseGen();
			if (gen) {
				FOREACH_NODE(BaseGen, gen->mChild, currGen)
				{
					if (currGen->mSpawnType == BaseGen::Start) {
						if (nodeScore > maxScore || (nodeScore == maxScore && randWeightFloat(1.0f) < 0.5f)) {
							*maxScoreGen = currGen;
							maxScoreNode = currNode;
							maxScore     = nodeScore;
						}
					}
				}
			}
		}
	}
	return maxScoreNode;
}

void Cave::RandMapScore::clearRoomAndDoorScore()
{
	FOREACH_NODE(MapNode, mGenerator->getPlacedNodes()->mChild, currNode)
	{
		currNode->setEnemyScore();
		currNode->setNodeScore(-1);
		currNode->resetDoorScore();
	}

	if (mGenerator->mIsVersusMode) {
		// if in versus mode, start calculating map score from both red and blue onyons (if set)
		if (getFixObjNode(FIXNODE_VsRedOnyon)) {
			setStartMapNodeScore(getFixObjNode(FIXNODE_VsRedOnyon));
		}
		if (getFixObjNode(FIXNODE_VsBlueOnyon)) {
			setStartMapNodeScore(getFixObjNode(FIXNODE_VsBlueOnyon));
		}
        if (getFixObjNode(FIXNODE_VsWhiteOnyon)) {
			setStartMapNodeScore(getFixObjNode(FIXNODE_VsWhiteOnyon));
		}
		if (getFixObjNode(FIXNODE_VsPurpleOnyon)) {
			setStartMapNodeScore(getFixObjNode(FIXNODE_VsPurpleOnyon));
		}

	} else if (getFixObjNode(FIXNODE_Pod)) { // not versus mode, so start from pod/ship.
		setStartMapNodeScore(getFixObjNode(FIXNODE_Pod));
	}
}


void Cave::RandMapScore::makeObjectLayout(MapNode* mapNode, ObjectLayout* layout)
{
	for (int i = 0; i < FIXNODE_Count; i++) {
		if (mapNode == mFixObjNodes[i]) {
            OSReport("Make Object Laytout %i\n", i);
			int layoutTypes[FIXNODE_Count]
			    = { OBJLAYOUT_Pod, OBJLAYOUT_Hole, OBJLAYOUT_Fountain, OBJLAYOUT_VsRedOnyon, OBJLAYOUT_VsBlueOnyon, OBJLAYOUT_VsWhiteOnyon, OBJLAYOUT_VsPurpleOnyon };
			FixObjNode* rootObjNode  = new FixObjNode(layoutTypes[i]);
			FixObjNode* childObjNode = new FixObjNode(layoutTypes[i]);

			Vector3f globalPos       = mFixObjNodes[i]->getBaseGenGlobalPosition(mFixObjGens[i]);
			f32 dir                  = mFixObjNodes[i]->getBaseGenGlobalDirection(mFixObjGens[i]);
			childObjNode->mPosition  = globalPos;
			childObjNode->mDirection = dir;

			rootObjNode->add(childObjNode);
			layout->setNode(layoutTypes[i], rootObjNode);
		}
	}
}

bool Cave::RandMapScore::isFixObjSet(MapNode* mapNode, BaseGen* baseGen)
{
	// test 0 (pod/ship) separately
	if (mapNode == getFixObjNode(FIXNODE_Pod) && baseGen && getFixObjGen(FIXNODE_Pod)) {
		Vector3f fixPos  = getFixObjGen(FIXNODE_Pod)->mPosition;
		Vector3f testPos = baseGen->mPosition;
		Vector3f sep     = Vector3f(fixPos.y - testPos.y, fixPos.z - testPos.z, fixPos.x - testPos.x);
		if (_length2(sep) < 150.0f) {
			return false;
		}
	}

	// test remaining fix obj nodes
	for (int i = 1; i < FIXNODE_Count; i++) {
		if (mapNode == getFixObjNode(i) && baseGen == getFixObjGen(i)) {
			return false;
		}
	}

	return true;
}

void Cave::RandMapScore::subNodeScore()
{
	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode)
	{
		currNode->subNodeScoreToVersusScore();
		if (getFixObjNode(FIXNODE_VsRedOnyon) && getFixObjNode(FIXNODE_VsBlueOnyon) && getFixObjNode(FIXNODE_VsWhiteOnyon) && getFixObjGen(FIXNODE_VsPurpleOnyon)) {
			if (currNode == getFixObjNode(FIXNODE_VsRedOnyon)) {
				mVersusRedScore = currNode->getVersusScore();
				OSReport("RedScore %i\n", mVersusRedScore);
			} else if (currNode == getFixObjNode(FIXNODE_VsBlueOnyon)) {
				mVersusBlueScore = currNode->getVersusScore();
				OSReport("BlueScore %i\n", mVersusBlueScore);
			}
			else if (currNode == getFixObjNode(FIXNODE_VsWhiteOnyon)) {
				mVersusWhiteScore = currNode->getVersusScore();
				OSReport("WhiteScore %i\n", mVersusWhiteScore);
			}
			else if (currNode == getFixObjNode(FIXNODE_VsPurpleOnyon)) {
				mVersusPurpleScore = currNode->getVersusScore();
				OSReport("PurpleScore %i\n", mVersusPurpleScore);
			}
		}
	}
}

ObjectLayoutInfo* Cave::RandMapMgr::makeObjectLayoutInfo(int idx)
{
	MapNode* node = static_cast<MapNode*>(mGenerator->mPlacedMapNodes->getChildAt(idx));
	if (node) {
		ObjectLayout* layout = new ObjectLayout(node);
		mRandMapScore->makeObjectLayout(node, layout);
		return layout;
	}
	return nullptr;
}

void MapRoom::placeObjects(Cave::FloorInfo* floorInfo, bool b) // basically matching
{
	if (!mObjectLayoutInfo) {
		return;
	}
	for (int nodeType = 0; nodeType < OBJLAYOUT_COUNT; nodeType++) {
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
                case OBJLAYOUT_VsWhiteOnyon: {
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_ONYON, ONYON_TYPE_WHITE);
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = 0.0f;
					pod->init(nullptr);
					pod->mFaceDir = node->getDirection();
					pod->setPosition(birthPos, false);
					break;
				}
				case OBJLAYOUT_VsPurpleOnyon: {
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_ONYON, ONYON_TYPE_PURPLE);
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

Onyon* Pellet::getPelletGoal()
{
	Onyon* goalOnyon;

	if ((gameSystem->isVersusMode())
	    || ((getKind() != PELTYPE_TREASURE) && (getKind() != PELTYPE_BERRY) && (getKind() != PELTYPE_UPGRADE))) {
		int maxCount = -1;
		int counter  = 0;
		int i        = 0;

		for (int j = 0; j < ONYON_TYPE_MAX; j++) {
			if (maxCount < (int)mPikminCount[j]) {
				maxCount = mPikminCount[j];
			}
		}

		int onyonType[ONYON_TYPE_MAX];
		for (int j = 0; j < ONYON_TYPE_MAX; j++) {
			if (maxCount == (int)mPikminCount[j]) {
				onyonType[i++] = j;
				counter++;
			}
		}

		int idx = (int)((float)counter * randFloat());
		if (idx >= counter) {
			idx = ONYON_TYPE_BLUE;
		}

		int type  = onyonType[idx];
		goalOnyon = ItemOnyon::mgr->getOnyon(type);
		if ((gameSystem->mMode == GSM_STORY_MODE) && (!playData->hasBootContainer(type))) {
			goalOnyon = nullptr;
		}

		if (goalOnyon == nullptr) {
			goalOnyon = ItemOnyon::mgr->getOnyon(ONYON_TYPE_RED);
			if (goalOnyon == nullptr) {
				goalOnyon = ItemOnyon::mgr->mPod;
			}
		}
	} else {
		goalOnyon = ItemOnyon::mgr->mUfo;
		if (ItemOnyon::mgr->mUfo == nullptr) {
			goalOnyon = ItemOnyon::mgr->mPod;
		}
	}

	return goalOnyon;
}

void PelletGoalState::init(Pellet* pellet, StateArg* arg)
{
	pellet->clearClaim();

	// check if a new upgrade is acquired
	if (pellet->getKind() == PELTYPE_UPGRADE && gameSystem->mMode == GSM_STORY_MODE) {
		int id = pellet->getConfigIndex();
		if (id >= 0 && id < 12) {
			playData->mOlimarData->getItem(id);
		}
	}
	pellet->setAlive(false);
	bool flag                = false;
	PelletGoalStateArg* sarg = static_cast<PelletGoalStateArg*>(arg);
	mOnyon                   = sarg->mCreature;
	if (gameSystem->mMode == GSM_STORY_MODE || gameSystem->isChallengeMode()) {
		flag = checkMovie(pellet);

	} else if (gameSystem->mMode == GSM_VERSUS_MODE) {
		int type = pellet->mPelletFlag;
		int team = getTeamFromPiki((EPikiKind)static_cast<Onyon*>(mOnyon)->mOnyonType);
		if ((u32)type == Pellet::FLAG_VS_BEDAMA_RED) {
			pellet->movie_begin(false);
			mOnyon->movie_begin(false);
			GameMessageVsRedOrSuckStart mesg(team);
			mesg.mIsYellow = false;
			mesg.mBedamaColor = 0;
			gameSystem->mSection->sendMessage(mesg);

		} else if ((u32)type == Pellet::FLAG_VS_BEDAMA_BLUE) {
			pellet->movie_begin(false);
			mOnyon->movie_begin(false);
			GameMessageVsRedOrSuckStart mesg2(team);
			mesg2.mIsYellow = false;
			mesg2.mBedamaColor = 1;
			gameSystem->mSection->sendMessage(mesg2);

		} else if ((u32)type == Pellet::FLAG_VS_BEDAMA_WHITE) {
			pellet->movie_begin(false);
			mOnyon->movie_begin(false);
			GameMessageVsRedOrSuckStart mesg2(team);
			mesg2.mIsYellow = false;
			mesg2.mBedamaColor = 2;
			gameSystem->mSection->sendMessage(mesg2);

		} else if ((u32)type == Pellet::FLAG_VS_BEDAMA_PURPLE) {
			pellet->movie_begin(false);
			mOnyon->movie_begin(false);
			GameMessageVsRedOrSuckStart mesg2(team);
			mesg2.mIsYellow = false;
			mesg2.mBedamaColor = 3;
			gameSystem->mSection->sendMessage(mesg2);

		} else if ((u32)type == Pellet::FLAG_VS_BEDAMA_YELLOW) {
			if ((int)mOnyon->mObjectTypeID == OBJTYPE_Onyon) {
				pellet->movie_begin(false);
				mOnyon->movie_begin(false);
				GameMessageVsRedOrSuckStart mesg3(team);
				mesg3.mIsYellow = true;
				mesg3.mBedamaColor = 0;
				gameSystem->mSection->sendMessage(mesg3);

			} else {
				JUT_PANICLINE(512, "not onyon %d\n", mOnyon->mObjectTypeID);
			}
		}
	}

	if (flag) {
		mOnyon->movie_begin(false);
		pellet->movie_begin(false);
	}

	Vector3f sep = mOnyon->getSuckPos() - pellet->getPosition();
	mDistance    = _length(sep);
	_14          = 0.0f;
	mSuckDelay   = 1.5f;

	Vector3f vel = pellet->getVelocity();
	vel.y        = 0.0f;
	pellet->setVelocity(vel);
	mScale = 1.0f;

	if (pellet->mPelletView) {
		mScale = pellet->mPelletView->viewGetBaseScale();
	}

	if (((int)mOnyon->mObjectTypeID == OBJTYPE_Onyon || (int)mOnyon->mObjectTypeID == OBJTYPE_Ufo) && !flag) {
		static_cast<Onyon*>(mOnyon)->efxSuikomi();
	}
	mInDemo     = flag;
	mDidSuikomi = false;
	if (!mInDemo) {
		Iterator<Piki> it(pikiMgr);
		CI_LOOP(it)
		{
			Piki* piki = *it;
			piki->movie_end(false);
		}

		GeneralMgrIterator<EnemyBase> it2(generalEnemyMgr);
		for (it2.first(); it2.mContainer; it2.next()) {
			EnemyBase* enemy = it2.getObject();
			enemy->movie_end(false);
		}
	}

	pellet->sound_otakaraEventFinish();
	if (!(u8)mOnyon->isSuckArriveWait()) {
		InteractSuckArrive act(pellet);
		mOnyon->stimulate(act);
		mIsWaiting = 0;
	} else {
		mIsWaiting = 1;
	}
}

void PelletNumber::Object::changeMaterial() {
	J3DGXColorS10 color;
	switch (mPelletColor)
	{
	case Red:
		color.r = 0xfb;
		color.b = 0x11;
		color.g = 0x00;
		color.a = 0xff;
		break;
	case Blue:
		color.r = 0x00;
		color.b = 0xff;
		color.g = 0x33;
		color.a = 0xff;
		break;
	case Yellow:
		color.r = 0xff;
		color.g = 0xdc;
		color.b = 0x34;
		color.a = 0xff;
		break;
	case Purple:
		color.r = 50;
		color.g = 0;
		color.b = 100;
		color.a = 0xff;
		break;
	case White:
		color.r = 179;
		color.g = 230;
		color.b = 179;
		color.a = 0xff;
	default:
		color.r = 0xff;
		color.g = 0xff;
		color.b = 0xff;
		color.a = 0xff;
		break;
	}

	s32 matIdx = mModel->mJ3dModel->mModelData->mMaterialTable.mMaterialNames->getIndex("bpel1");
	mModel->mJ3dModel->mModelData->mMaterialTable.mMaterials[matIdx]->setTevColor(0, &color);


	mModel->mJ3dModel->calcMaterial();
	mModel->mJ3dModel->diff();
}

void Cave::RandItemUnit::getItemDropPosition(Vector3f& position, f32 weight, int floorIndex)
{
	weight = 0.5f;

	MapNode* nodes[2];
	MapNode* dropList[256];
	MapNode* dropNode;

	nodes[0] = mGenerator->mPlacedMapNodes;
	nodes[1] = mGenerator->mVisitedMapNodes;

	OSReport("Scores %u, %u, %u, %u\n", mMapScore->mVersusRedScore, mMapScore->mVersusBlueScore, mMapScore->mVersusWhiteScore, mMapScore->mVersusPurpleScore);

	int score = weight * (f32)mMapScore->mVersusRedScore + (1.0f - weight) * (f32)mMapScore->mVersusBlueScore
	+ weight * (f32)mMapScore->mVersusWhiteScore + (1.0f - weight) * (f32)mMapScore->mVersusPurpleScore;

	if (floorIndex < 0) {
		int dropIndex = 1280000;
		for (int i = 0; i < 2; i++) {
			FOREACH_NODE(MapNode, nodes[i]->mChild, mapNode) { getItemDropMapNode(mapNode, &dropNode, score, dropIndex); }
		}

		if (dropNode) {
			position = getItemBaseGenPosition(dropNode, score);
		} else {
			JUT_PANICLINE(375, "item slot none\n");
		}

	} else {
		int dropIndex = 0;
		BaseGen* basegen[256];
		for (int i = 0; i < 2; i++) {
			FOREACH_NODE(MapNode, nodes[i]->mChild, mapNode) { getItemDropList(mapNode, dropList, basegen, dropIndex); }
		}

		if (floorIndex < dropIndex) {
			position = getItemBaseGenPosition(dropList, basegen, dropIndex, score, floorIndex);
		} else {
			JUT_PANICLINE(398, "item slot not enough\n");
		}
	}
}

void Cave::RandItemUnit::getItemDropPosition(Vector3f& position, VsWeights weight, int floorIndex)
{
	MapNode* nodes[2];
	MapNode* dropList[256];
	MapNode* dropNode;

	nodes[0] = mGenerator->mPlacedMapNodes;
	nodes[1] = mGenerator->mVisitedMapNodes;

	OSReport("Scores %u, %u, %u, %u\n", mMapScore->mVersusRedScore, mMapScore->mVersusBlueScore, mMapScore->mVersusWhiteScore, mMapScore->mVersusPurpleScore);

	int score = weight[0] * (f32)mMapScore->mVersusRedScore + weight[1] * (f32)mMapScore->mVersusBlueScore
	+ weight[2] * (f32)mMapScore->mVersusWhiteScore + weight[3] * (f32)mMapScore->mVersusPurpleScore;

	if (floorIndex < 0) {
		int dropIndex = 1280000;
		for (int i = 0; i < 2; i++) {
			FOREACH_NODE(MapNode, nodes[i]->mChild, mapNode) { getItemDropMapNode(mapNode, &dropNode, score, dropIndex); }
		}

		if (dropNode) {
			position = getItemBaseGenPosition(dropNode, score);
		} else {
			JUT_PANICLINE(375, "item slot none\n");
		}

	} else {
		int dropIndex = 0;
		BaseGen* basegen[256];
		for (int i = 0; i < 2; i++) {
			FOREACH_NODE(MapNode, nodes[i]->mChild, mapNode) { getItemDropList(mapNode, dropList, basegen, dropIndex); }
		}

		if (floorIndex < dropIndex) {
			position = getItemBaseGenPosition(dropList, basegen, dropIndex, score, floorIndex);
		} else {
			JUT_PANICLINE(398, "item slot not enough\n");
		}
	}
}

void Cave::RandMapMgr::getItemDropPosition(Vector3f& position, VsWeights minDist, VsWeights maxDist)
{
	VsWeights dists;
	for (int i = 0; i < 4; i++) {
		dists[i] = minDist[i] + randWeightFloat(maxDist[i] - minDist[i]);
	}

	mRandItemUnit->getItemDropPosition(position, dists, -1);
}

void Cave::RandMapMgr::getItemDropPosition(Vector3f* positions, int count, VsWeights p1, VsWeights p2)
{
	VsWeights avg;
	VsWeights weight;
	for (int i = 0; i < 4; i++) {
		avg[i] = 0.5f * (p1[i] + p2[i]);
		weight[i] = (p2[i] - avg[i] > 0.0f) ? p2[i] - avg[i] : -(p2[i] - avg[i]);
	}

	MapNode* nodeList[16];
	BaseGen* genList[16];

	int randVal  = 2.0f * randFloat();
	int absCount = ((count < 0) ? -count : count) - 1; // ?? what even is this
	mRandItemUnit->setItemDropPositionList(nodeList, genList);

	for (int i = 0; i < count; i++) {
		VsWeights val;
		for (int j = 0; j < 4; j++) {
			val[j] = avg[j];
			if (((i < 0) ? -i : i) != absCount) { // ?? again, what
				if (i == randVal) {
					val[j] = avg[j] + randWeightFloat(weight[j]);
				} else {
					val[j] = avg[j] - randWeightFloat(weight[j]);
				}
			}
		}
		mRandItemUnit->getItemDropPosition(positions[i], val, i);
	}
}


} // namespace Game