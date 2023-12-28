
#include "Game/Cave/RandMapMgr.h"
#include "Game/Entities/Item.h"
#include "Dolphin/rand.h"
#include "Game/gamePlayData.h"
#include "Game/generalEnemyMgr.h"
#include "Game/Cave/Info.h"
#include "FourPlayer.h"
#include "Game/Cave/Node.h"
#include "Game/Entities/Pelplant.h"


int gScoreDelegations[2][2] = { {ONYON_TYPE_RED, ONYON_TYPE_BLUE}, {ONYON_TYPE_WHITE, ONYON_TYPE_PURPLE} };
int gEffectiveTeamCount = 4;
bool gThreePlayer;

void initScoreDelegations() {
	gThreePlayer = false;
	if (Game::getTeamCount() > 2) {
		int skippedTeam = -1;
		int currentCount = 0;
		for (int i = 0; i < 4; i++) {
			if (!Game::doesTeamHavePlayers(i)) {
				skippedTeam = Game::getPikiFromTeamEnum(i);
			}
			else {
				reinterpret_cast<int*>(gScoreDelegations)[currentCount++] = Game::getPikiFromTeamEnum(i);
			}
		}
		gEffectiveTeamCount = 4;
		if (skippedTeam != -1) {
			gScoreDelegations[1][1] = skippedTeam;
			gThreePlayer = true;
		}
	}
	else {
		gEffectiveTeamCount = 2;
		int deleID = 0;
		for (int i = 0; i < 4; i++) {
			if (Game::isTeamActive(i)) {
				gScoreDelegations[0][deleID++] = (OnyonTypes)Game::getPikiFromTeamEnum(i);
			}
		}
		deleID = 0;
		for (int i = 0; i < 4; i++) {
			if (!Game::isTeamActive(i)) {
				gScoreDelegations[1][deleID++] = (OnyonTypes)Game::getPikiFromTeamEnum(i);
			}
		}
	}
}


enum ScoreDelegations {
    FIRST_SCORE,
    SECOND_SCORE
};

namespace Game
{

typedef EnemyTypeID::EEnemyTypeID EnemySet[4];

EnemySet TankSet = 
	{ EnemyTypeID::EnemyID_Tank, EnemyTypeID::EnemyID_Wtank, EnemyTypeID::EnemyID_Gtank, EnemyTypeID::EnemyID_Mtank };

EnemySet OtakaraSet = 
	{ EnemyTypeID::EnemyID_FireOtakara, EnemyTypeID::EnemyID_WaterOtakara, EnemyTypeID::EnemyID_GasOtakara, EnemyTypeID::EnemyID_SporeOtakara };

EnemySet HibaSet = 
	{ EnemyTypeID::EnemyID_Hiba, EnemyTypeID::EnemyID_WaterHiba, EnemyTypeID::EnemyID_GasLineHiba, EnemyTypeID::EnemyID_SporeHiba };

EnemyTypeID::EEnemyTypeID GetEnemyFromSet(EnemyTypeID::EEnemyTypeID enemyType, EnemySet enemySet) {
	int genericIdx = -1;
	for (int i = 0; i < 4; i++) {
		if (enemyType == enemySet[i]) {
			genericIdx = i;
			break;
		}
	}
	if (genericIdx == -1) {
		return enemyType;
	}

	int pikiColor = reinterpret_cast<int*>(gScoreDelegations)[genericIdx];


	return enemySet[getTeamFromPiki(pikiColor)];
}

EnemyTypeID::EEnemyTypeID MakeReplacementFromGenericEnemy(EnemyTypeID::EEnemyTypeID enemyType) {
	DebugReport("Enemy In %s\n", EnemyInfoFunc::getEnemyName(enemyType, 0xffff));
	enemyType = GetEnemyFromSet(enemyType, TankSet);
	enemyType = GetEnemyFromSet(enemyType, OtakaraSet);
	enemyType = GetEnemyFromSet(enemyType, HibaSet);
	DebugReport("Enemy Out %s\n", EnemyInfoFunc::getEnemyName(enemyType, 0xffff));
	return enemyType;
}


namespace Cave
{

EnemyUnit* gPelplantEnemyUnit;
int gPelplantsPerBunch;

RandMapScore::RandMapScore(MapUnitGenerator* generator)
{
	mGenerator       = generator;
	mVersusHighScore[0] = 0;
    mVersusHighScore[1] = 0;
	mVersusLowScore[0]  = 0;
    mVersusLowScore[1]  = 0;
	mFixObjNodes     = new MapNode*[FIXNODE_Count];
	mFixObjGens      = new BaseGen*[FIXNODE_Count];

	for (int i = 0; i < FIXNODE_Count; i++) {
		mFixObjNodes[i] = nullptr;
		mFixObjGens[i]  = nullptr;
	}
}

MapNode* RandMapScore::getRandRoomMapNode()
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

MapNode* RandMapScore::getVsCenterRoomMapNode()
{
	MapNode* closestZero = (MapNode*)mGenerator->mPlacedMapNodes->mChild;

	FOREACH_NODE(MapNode, closestZero->mNext, currNode)
	{
		if (absVal(currNode->getVersusScore(FIRST_SCORE)) < absVal(closestZero->getVersusScore(FIRST_SCORE))) {
			closestZero = currNode;
		}
	}
	return closestZero;
}


void RandMapScore::setVersusOnyon()
{
	initScoreDelegations();

	if (!getFixObjNode(FIXNODE_VsRedOnyon) && !getFixObjNode(FIXNODE_VsBlueOnyon) && !getFixObjNode(FIXNODE_VsWhiteOnyon) && !getFixObjNode(FIXNODE_VsPurpleOnyon)) {
		MapNode* targetNode    = getRandRoomMapNode();
		MapNode* onyonNodes[4] = { nullptr, nullptr, nullptr, nullptr };
		BaseGen* onyonGens[4]  = { nullptr, nullptr, nullptr, nullptr };

		if (targetNode) {

			calcNodeScore(targetNode);

			onyonNodes[0] = getMaxScoreRoomMapNode(targetNode, &onyonGens[0]);
			calcNodeScore(onyonNodes[0]);
			copyNodeScore(FIRST_SCORE);


			onyonNodes[1] = getMaxScoreRoomMapNode(onyonNodes[0], &onyonGens[1]);
			calcNodeScore(onyonNodes[1]);
			subNodeScore(FIRST_SCORE);

			if (gEffectiveTeamCount > 2) {
				MapNode* centerNode = getVsCenterRoomMapNode();
				calcNodeScore(centerNode);

				onyonNodes[2] = getMaxVsScoreRoomMapNode(2, onyonNodes, &onyonGens[2], false);
				JUT_ASSERT(onyonNodes[2], "NO ROOM FOR WHITE ONYON");
				JUT_ASSERT(onyonGens[2], "NO GEN FOR WHITE ONYON");
				calcNodeScore(onyonNodes[2]);
				copyNodeScore(SECOND_SCORE);

				calcNodeScore(centerNode);
				
				onyonNodes[3] = getMaxVsScoreRoomMapNode(3, onyonNodes, &onyonGens[3], true);
				JUT_ASSERT(onyonNodes[3], "NO ROOM FOR PURPLE ONYON");
				JUT_ASSERT(onyonGens[3], "NO GEN FOR WHITE ONYON");
				calcNodeScore(onyonNodes[3]);
				subNodeScore(SECOND_SCORE);
			}

			mFixObjNodes[FIXNODE_VsRedOnyon]  = onyonNodes[0];
			mFixObjNodes[FIXNODE_VsBlueOnyon] = onyonNodes[1];
            mFixObjNodes[FIXNODE_VsWhiteOnyon] = onyonNodes[2];
			mFixObjNodes[FIXNODE_VsPurpleOnyon] = onyonNodes[3];

			mFixObjGens[FIXNODE_VsRedOnyon]  = onyonGens[0];
			mFixObjGens[FIXNODE_VsBlueOnyon] = onyonGens[1];
            mFixObjGens[FIXNODE_VsWhiteOnyon] = onyonGens[2];
			mFixObjGens[FIXNODE_VsPurpleOnyon] = onyonGens[3];



			FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode)
			{
				if (currNode == getFixObjNode(FIXNODE_VsRedOnyon)) {
					mVersusHighScore[FIRST_SCORE] = currNode->getVersusScore(FIRST_SCORE);
				} else if (currNode == getFixObjNode(FIXNODE_VsBlueOnyon)) {
					mVersusLowScore[FIRST_SCORE] = currNode->getVersusScore(FIRST_SCORE);
				} else if (currNode == getFixObjNode(FIXNODE_VsWhiteOnyon)) {
					mVersusHighScore[SECOND_SCORE] = currNode->getVersusScore(SECOND_SCORE);
				} else if (currNode == getFixObjNode(FIXNODE_VsPurpleOnyon)) {
					mVersusLowScore[SECOND_SCORE] = currNode->getVersusScore(SECOND_SCORE);
				}
			}
		}
		else {
			JUT_PANIC("No random room node!\n");
		}
	}
	else {
		JUT_PANIC("Fixnodes already exist!\n");
	}
}

void RandMapScore::copyNodeScore(int color)
{
	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode) { currNode->copyNodeScoreToVersusScore(color); }
}

void MapNode::copyNodeScoreToVersusScore(int color) { mVsScore[color] = (s16)mNodeScore; }

void MapNode::copyNodeScoreToVersusScore() { }



MapNode* RandMapScore::getMaxScoreRoomMapNode(MapNode* mapNode, BaseGen** maxScoreGen)
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

MapNode* RandMapScore::getMaxScoreRoomMapNode(int count, MapNode** mapNode, BaseGen** maxScoreGen)
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

MapNode* RandMapScore::getMaxVsScoreRoomMapNode(int count, MapNode** mapNode, BaseGen** maxScoreGen, bool second)
{
	MapNode* maxScoreNode = nullptr;
	int minScore          = 1000000;
	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode)
	{
		bool doSkip = false;
        for (int i = 0; i < count; i++) {
            if (currNode == mapNode[i]) {
                doSkip = true;
            }
        }
		if (!doSkip && currNode->mUnitInfo->getUnitKind() == UNITKIND_Room) {
			DebugReport("Second Score %i\n", currNode->getNodeScore());
			int secondScore = (second) ? absVal(currNode->getVersusScore(SECOND_SCORE)) : currNode->getNodeScore();
			int nodeScore = -(secondScore * secondScore) + absVal(currNode->getVersusScore(FIRST_SCORE)) + 10;
			BaseGen* gen  = currNode->mUnitInfo->getBaseGen();
			if (gen) {
				FOREACH_NODE(BaseGen, gen->mChild, currGen)
				{
					if (currGen->mSpawnType == BaseGen::Start) {
						if (nodeScore < minScore || (nodeScore == minScore && randWeightFloat(1.0f) < 0.5f)) {
							*maxScoreGen = currGen;
							maxScoreNode = currNode;
							minScore     = nodeScore;
						}
					}
				}
			}
		}
	}
	DebugReport("next\n");
	return maxScoreNode;
}


void RandMapScore::clearRoomAndDoorScore()
{
	DebugReport("RandMapScore::clearRoomAndDoorScore()\n");
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


void RandMapScore::makeObjectLayout(MapNode* mapNode, ObjectLayout* layout)
{
	for (int i = 0; i < FIXNODE_Count; i++) {
		if (mapNode == mFixObjNodes[i]) {
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

bool RandMapScore::isFixObjSet(MapNode* mapNode, BaseGen* baseGen)
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
	for (int i = 1; i < FIXNODE_VsRedOnyon + gEffectiveTeamCount; i++) {
		if (mapNode == getFixObjNode(i) && baseGen == getFixObjGen(i)) {
			return false;
		}
	}

	return true;
}

int MapNode::getVersusScore() {
    return mVsScore[0] + mVsScore[1];
}

int MapNode::getVersusNetScore() {
    return MAX(FABS(mVsScore[0]), FABS(mVsScore[1]));
}

int MapNode::getVersusScore(int color) {
    return mVsScore[color];
}

void MapNode::subNodeScoreToVersusScore(int color) { mVsScore[color] -= (s16)mNodeScore; }


void RandMapScore::subNodeScore(int color)
{
	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode)
	{
		currNode->subNodeScoreToVersusScore(color);
	}
}

ObjectLayoutInfo* RandMapMgr::makeObjectLayoutInfo(int idx)
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
	DebugReport("MapRoom::placeObjects(Cave::FloorInfo*, bool )\n");
	if (!mObjectLayoutInfo) {
		return;
	}

	const int pelplantColors[4] = { PELCOLOR_RED, PELCOLOR_BLUE, PELCOLOR_WHITE, PELCOLOR_PURPLE };

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
					if (ItemOnyon::mgr->getOnyon(gScoreDelegations[0][1])) {
						break;
					}
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_ONYON, gScoreDelegations[0][1]);
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = 0.0f;
					pod->init(nullptr);
					pod->mFaceDir = node->getDirection();
					pod->setPosition(birthPos, false);
					break;
				}
				case OBJLAYOUT_VsRedOnyon: {
					if (ItemOnyon::mgr->getOnyon(gScoreDelegations[0][0])) {
						break;
					}
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_ONYON, gScoreDelegations[0][0]);
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = 0.0f;
					pod->init(nullptr);
					pod->mFaceDir = node->getDirection();
					pod->setPosition(birthPos, false);
					break;
				}
                case OBJLAYOUT_VsWhiteOnyon: {
					if (ItemOnyon::mgr->getOnyon(gScoreDelegations[1][0])) {
						break;
					}
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_ONYON, gScoreDelegations[1][0]);
					Vector3f birthPos;
					node->getBirthPosition(birthPos.x, birthPos.z);
					birthPos.y = 0.0f;
					pod->init(nullptr);
					pod->mFaceDir = node->getDirection();
					pod->setPosition(birthPos, false);
					break;
				}
				case OBJLAYOUT_VsPurpleOnyon: {
					if (ItemOnyon::mgr->getOnyon(gScoreDelegations[1][1])) {
						break;
					}
					Onyon* pod = ItemOnyon::mgr->birth(ONYON_OBJECT_ONYON, gScoreDelegations[1][1]);
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

					Cave::EnemyNode* enemyNode = static_cast<Cave::EnemyNode*>(node);

					bool canSpawnTeki  = true;
					bool isWaterwraith = false;
					bool isPelplant = false;
					int blowhogIdx = 0;
					EnemyTypeID::EEnemyTypeID enemyType = (EnemyTypeID::EEnemyTypeID)node->getObjectId();
					if (enemyType == EnemyTypeID::EnemyID_BlackMan) {
						if (playData->mCaveSaveData.mIsWaterwraithAlive) {
							isWaterwraith = true;
						}
						else {
							canSpawnTeki = false;
						}
					}
					else if (enemyType == EnemyTypeID::EnemyID_Pelplant) {
						isPelplant = true;
					}

					if (canSpawnTeki) {
						DebugReport("Enemy in generate objects\n");
						EnemyBase* enemy = generalEnemyMgr->birth(enemyType, birthArg);
						if (enemy) {
							DebugReport("pre-init\n");
							enemy->init(nullptr);
							DebugReport("post-init\n");
						}
						if (isWaterwraith) {
							BlackMan::Obj* waterwraith = static_cast<BlackMan::Obj*>(enemy);
							waterwraith->setTimer(floorInfo->mParms.mWaterwraithTimer);
							static_cast<RoomMapMgr*>(mapMgr)->mBlackMan = waterwraith;
						}
						else if (isPelplant && gConfig[PELLET_POSY] == ConfigEnums::PELMATCH_ON) {
							if (enemyNode->mEnemyUnit == Cave::gPelplantEnemyUnit) {
								int pelPlantTeam = PELCOLOR_RANDOM;
								for (int objLayout = OBJLAYOUT_VsRedOnyon; objLayout <= OBJLAYOUT_VsPurpleOnyon; objLayout++) {
									if (mObjectLayoutInfo->getNode(objLayout, 0)) {
										pelPlantTeam = reinterpret_cast<int*>(gScoreDelegations)[objLayout - OBJLAYOUT_VsRedOnyon];
									}
								}
								
								DebugReport("PelplantTeam %i\n", pelPlantTeam);
								if (pelPlantTeam != PELCOLOR_RANDOM) {
									Pelplant::Obj* pelplant = static_cast<Pelplant::Obj*>(enemy);
									pelplant->mColor = pelPlantTeam;
									pelplant->setPelletColor(pelPlantTeam, false);
								}
							}
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


void RandItemUnit::getItemDropPosition(Vector3f& position, f32 weight, int floorIndex)
{
	
	weight = 0.5f;

	MapNode* nodes[2];
	MapNode* dropList[256];
	MapNode* dropNode;

	nodes[0] = mGenerator->mPlacedMapNodes;
	nodes[1] = mGenerator->mVisitedMapNodes;


	int score = 0;
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


void RandMapMgr::getItemDropPosition(Vector3f& position, VsWeights minDists, VsWeights maxDists)
{
    VsWeights weight;
    weight[FIRST_SCORE] = minDists[FIRST_SCORE] + randFloat() * (maxDists[FIRST_SCORE] - minDists[FIRST_SCORE]);
    weight[SECOND_SCORE] = minDists[SECOND_SCORE] + randFloat() * (maxDists[SECOND_SCORE] - minDists[SECOND_SCORE]);
	mRandItemUnit->getItemDropPosition(position, weight, -1);
}

void RandItemUnit::getItemDropPosition(Vector3f& position, VsWeights weight, int floorIndex)
{
	MapNode* nodes[2];
	MapNode* dropList[256];
	MapNode* dropNode;

	nodes[0] = mGenerator->mPlacedMapNodes;
	nodes[1] = mGenerator->mVisitedMapNodes;

    int score[2];

	score[FIRST_SCORE] = ((f32)mMapScore->mVersusHighScore[FIRST_SCORE]) * weight[FIRST_SCORE] + (f32)mMapScore->mVersusLowScore[FIRST_SCORE] * (1 - weight[FIRST_SCORE]);
    score[SECOND_SCORE] = ((f32)mMapScore->mVersusHighScore[SECOND_SCORE]) * weight[SECOND_SCORE] + (f32)mMapScore->mVersusLowScore[SECOND_SCORE] * (1 - weight[SECOND_SCORE]);


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

Vector3f RandItemUnit::getItemBaseGenPosition(MapNode* node, int scores[2])
{
	BaseGen* genList[64];
	int counter        = 0;
	Vector3f globalPos = node->getBaseGenGlobalPosition(nullptr);
	BaseGen* gen       = node->mUnitInfo->getBaseGen();
	if (gen) {
		FOREACH_NODE(BaseGen, gen->mChild, currGen)
		{
			if (currGen->mSpawnType == BaseGen::Treasure__Item) {
				genList[counter] = currGen;
				counter++;
			} else if (currGen->mSpawnType == BaseGen::TekiA__Easy) {
				genList[counter] = currGen;
				counter++;
			} else if (currGen->mSpawnType == BaseGen::TekiB__Hard) {
				genList[counter] = currGen;
				counter++;
			}
		}
	}

	if (counter > 0) {
		Vector3f positions[32];
		Vector3f onyonPos;
        int firstScoreDiff = node->getVersusScore(FIRST_SCORE) - scores[FIRST_SCORE];
        int secondScoreDiff = node->getVersusScore(SECOND_SCORE) - scores[SECOND_SCORE];
        if (absVal(firstScoreDiff) > absVal(secondScoreDiff) || gEffectiveTeamCount == 2) {
            if (firstScoreDiff > 0) {
                onyonPos = mMapScore->getFixObjNode(FIXNODE_VsRedOnyon)->getBaseGenGlobalPosition(mMapScore->getFixObjGen(FIXNODE_VsRedOnyon));
            } else {
                onyonPos
                    = mMapScore->getFixObjNode(FIXNODE_VsBlueOnyon)->getBaseGenGlobalPosition(mMapScore->getFixObjGen(FIXNODE_VsBlueOnyon));
            }
        }
        else  {
            if (secondScoreDiff > 0) {
                onyonPos = mMapScore->getFixObjNode(FIXNODE_VsWhiteOnyon)->getBaseGenGlobalPosition(mMapScore->getFixObjGen(FIXNODE_VsWhiteOnyon));
            } else {
                onyonPos
                    = mMapScore->getFixObjNode(FIXNODE_VsPurpleOnyon)->getBaseGenGlobalPosition(mMapScore->getFixObjGen(FIXNODE_VsPurpleOnyon));
            }
        }

		int counter2 = 0;
		f32 sqrDist  = sqrDistanceXZ(onyonPos, globalPos);
		for (int i = 0; i < counter; i++) {
			Vector3f genPos = node->getBaseGenGlobalPosition(genList[i]);
			if (sqrDistanceXZ(onyonPos, genPos) < sqrDist) {
				positions[counter2] = genPos;
				counter2++;
			}
		}

		if (counter2) {
			int randIdx      = counter2 * randFloat();
			Vector3f* outVec = &positions[randIdx];
			return *outVec;
		} else {
			int randIdx = counter * randFloat();
			return node->getBaseGenGlobalPosition(genList[randIdx]);
		}
	} else {
		return globalPos;
	}
}

int newScore[2]; 

static f32 gScoreBias;

void RandMapMgr::getItemDropPosition(Vector3f* positions, int count, VsWeights p1, VsWeights p2)
{
    VsWeights avg;
    VsWeights weight;
	avg[FIRST_SCORE]    = 0.5f * (p1[FIRST_SCORE] + p2[FIRST_SCORE]);
    avg[SECOND_SCORE]   = 0.5f * (p1[SECOND_SCORE] + p2[SECOND_SCORE]);
	weight[FIRST_SCORE] = (p2[FIRST_SCORE] - avg[FIRST_SCORE] > 0.0f) ? p2[FIRST_SCORE] - avg[FIRST_SCORE] : -(p2[FIRST_SCORE] - avg[FIRST_SCORE]);
    weight[SECOND_SCORE] = (p2[SECOND_SCORE] - avg[SECOND_SCORE] > 0.0f) ? p2[SECOND_SCORE] - avg[SECOND_SCORE] : -(p2[SECOND_SCORE] - avg[SECOND_SCORE]);

	newScore[FIRST_SCORE]  = 0;
	newScore[SECOND_SCORE] = 0;

	gScoreBias = 0.5f;

	DebugReport("Score Bias %f\n", gScoreBias);

	MapNode* nodeList[16];
	BaseGen* genList[16];

	int randVal  = 2.0f * randFloat();
	int absCount = ((count < 0) ? -count : count) - 1; // ?? what even is this
	mRandItemUnit->setItemDropPositionList(nodeList, genList);
	
	for (int i = 0; i < count; i++) {
		VsWeights val = { avg[0], avg[1] };
		DebugReport("FIRST SCORE %f\n", val[FIRST_SCORE]);
		
		// if (i == 0) val[FIRST_SCORE] += weight[FIRST_SCORE];
		// if (i == 1) val[FIRST_SCORE] -= weight[FIRST_SCORE];
		

		// if (gEffectiveTeamCount > 2) {
		// 	if (i == 2) val[SECOND_SCORE] += weight[SECOND_SCORE];
		// 	if (i == 3) val[SECOND_SCORE] -= weight[SECOND_SCORE];
		// }
		mRandItemUnit->getItemDropPosition(positions[i], val, i);

		f32 newFirstAvg = (newScore[FIRST_SCORE] - (f32)mRandItemUnit->mMapScore->mVersusLowScore[FIRST_SCORE]) / 
		((f32)mRandItemUnit->mMapScore->mVersusHighScore[FIRST_SCORE] - (f32)mRandItemUnit->mMapScore->mVersusLowScore[FIRST_SCORE]);

		f32 newSecondAvg = (newScore[SECOND_SCORE] - (f32)mRandItemUnit->mMapScore->mVersusLowScore[SECOND_SCORE]) / 
		((f32)mRandItemUnit->mMapScore->mVersusHighScore[SECOND_SCORE] - (f32)mRandItemUnit->mMapScore->mVersusLowScore[SECOND_SCORE]);

		avg[FIRST_SCORE]  = newFirstAvg;
		avg[SECOND_SCORE] = newSecondAvg;
	}
}

int skew[2] = {0, 0};

MapNode* RandItemUnit::getItemNormalSetMapNode(BaseGen** outGens)
{
	MapNode* bestMapNode;
	BaseGen* bestMapGen;
	int counter    = 0;
	int minScore = 100000;

	int finalScores[2];


	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currMapNode)
	{
		int unitKind = currMapNode->mUnitInfo->getUnitKind();

		if (currMapNode->mUnitInfo->getUnitKind() == UNITKIND_Room) {
			int firstScore = absVal(currMapNode->getVersusScore(FIRST_SCORE) - skew[FIRST_SCORE] + mMapScore->mVersusHighScore[FIRST_SCORE] + mMapScore->mVersusLowScore[FIRST_SCORE]);
			DebugReport("First score %i\n", firstScore);
			int secondScore = absVal(currMapNode->getVersusScore(SECOND_SCORE) - skew[SECOND_SCORE]);
			
			int currScore = MAX(firstScore, secondScore);
			BaseGen* baseGen  = currMapNode->mUnitInfo->getBaseGen();
			if (baseGen) {
				FOREACH_NODE(BaseGen, baseGen->mChild, currBaseGen)
				{
					if (currBaseGen->mSpawnType == BaseGen::Treasure__Item) {
						if (!isItemSetDone(currMapNode, currBaseGen)) {
							if (currScore < minScore) {
								bestMapNode = currMapNode;
								bestMapGen = currBaseGen;
								minScore = currScore;
								finalScores[FIRST_SCORE] = currMapNode->getVersusScore(FIRST_SCORE);
								finalScores[SECOND_SCORE] = currMapNode->getVersusScore(SECOND_SCORE);
							}
						}
					}
				}
			}

		} else if ((unitKind == UNITKIND_Cap && !strncmp(currMapNode->getUnitName(), "item", 4)) || unitKind == UNITKIND_Corridor) {
			int firstScore = absVal(currMapNode->getVersusScore(FIRST_SCORE) - skew[FIRST_SCORE] + mMapScore->mVersusHighScore[FIRST_SCORE] + mMapScore->mVersusLowScore[FIRST_SCORE]);
			int secondScore = absVal(currMapNode->getVersusScore(SECOND_SCORE) - skew[SECOND_SCORE]);
			
			int currScore = MAX(firstScore, secondScore);
			if (!isItemSetDone(currMapNode, nullptr)) {
				if (currScore < minScore) {
					bestMapNode = currMapNode;
					bestMapGen = nullptr;
					minScore = currScore;
					finalScores[FIRST_SCORE] = currMapNode->getVersusScore(FIRST_SCORE);
					finalScores[SECOND_SCORE] = currMapNode->getVersusScore(SECOND_SCORE);
				}
			}
		} 
	}

	int skewUp = (finalScores[0] > 1) ? -10 : 10;

	skew[0] = skewUp;

	*outGens = bestMapGen;

	return bestMapNode;
}

Vector3f RandItemUnit::getItemBaseGenPosition(MapNode** nodes, BaseGen** gens, int count, int scores[2], int idx)
{
	MapNode* redOnyonNode  = mMapScore->getFixObjNode(FIXNODE_VsRedOnyon);  // r27
	MapNode* blueOnyonNode = mMapScore->getFixObjNode(FIXNODE_VsBlueOnyon); // r28
    MapNode* whiteOnyonNode  = mMapScore->getFixObjNode(FIXNODE_VsWhiteOnyon);  // r27
	MapNode* purpleOnyonNode = mMapScore->getFixObjNode(FIXNODE_VsPurpleOnyon); // r28

	BaseGen* redOnyonGen  = mMapScore->getFixObjGen(FIXNODE_VsRedOnyon);  // r29
	BaseGen* blueOnyonGen = mMapScore->getFixObjGen(FIXNODE_VsBlueOnyon); // r30
    BaseGen* whiteOnyonGen  = mMapScore->getFixObjGen(FIXNODE_VsWhiteOnyon);  // r29
	BaseGen* purpleOnyonGen = mMapScore->getFixObjGen(FIXNODE_VsPurpleOnyon); // r30

	f32 maxDist = 400.0f;
	int distScores[128];

	for (int i = 0; i < count; i++) {
		MapNode* currNode = nodes[i];
		f32 len           = maxDist;
		bool isFirstDiff = true;
		if (redOnyonNode == currNode) {
			Vector3f onyonPos = redOnyonGen->mPosition;
			Vector3f genPos   = gens[i]->mPosition;
			Vector3f sep      = Vector3f(onyonPos.y - genPos.y, onyonPos.z - genPos.z, onyonPos.x - genPos.x);
			len               = _length2(sep);
		} else if (blueOnyonNode == currNode) {
			Vector3f onyonPos = blueOnyonGen->mPosition;
			Vector3f genPos   = gens[i]->mPosition;
			Vector3f sep      = Vector3f(onyonPos.y - genPos.y, onyonPos.z - genPos.z, onyonPos.x - genPos.x);
			len               = _length2(sep);
		}  else if (whiteOnyonNode == currNode) {
            Vector3f onyonPos = whiteOnyonGen->mPosition;
			Vector3f genPos   = gens[i]->mPosition;
			Vector3f sep      = Vector3f(onyonPos.y - genPos.y, onyonPos.z - genPos.z, onyonPos.x - genPos.x);
			len               = _length2(sep);
			isFirstDiff = false;
        } else if (purpleOnyonNode == currNode) {
            Vector3f onyonPos = purpleOnyonGen->mPosition;
			Vector3f genPos   = gens[i]->mPosition;
			Vector3f sep      = Vector3f(onyonPos.y - genPos.y, onyonPos.z - genPos.z, onyonPos.x - genPos.x);
			len               = _length2(sep);
			isFirstDiff = false;
        }

		int firstDiff = absVal(currNode->getVersusScore(FIRST_SCORE) - scores[FIRST_SCORE]);
		int secondDiff = absVal(currNode->getVersusScore(SECOND_SCORE) - scores[SECOND_SCORE]);

		if (len < maxDist) {
			int add = (gEffectiveTeamCount > 2) ? (isFirstDiff) ? secondDiff : firstDiff : 0;
			distScores[i] = 12800 - (int)len + add;
		} else {
			if (gEffectiveTeamCount < 3) {
				distScores[i] = firstDiff;
			}
			else {
				distScores[i] = MAX(firstDiff, secondDiff);
			}
		}
	}

	getItemDropSortingList(nodes, gens, distScores, count);

	for (int i = 0; i < count; i++) {
		bool check = true;
		for (int j = 0; j < idx; j++) {
			if (nodes[i] == mMapTileList[j] && gens[i] == mSpawnList[j]) {
				check = false;
			}
		}

		if (check) {
			mMapTileList[idx] = nodes[i];
			mSpawnList[idx]   = gens[i];

			DebugReport("PLACED AT %i, %i\n", mMapTileList[idx]->getVersusScore(FIRST_SCORE), mMapTileList[idx]->getVersusScore(SECOND_SCORE));

			f32 firstScore = (f32)mMapTileList[idx]->getVersusScore(FIRST_SCORE);
			f32 secondScore = (f32)mMapTileList[idx]->getVersusScore(SECOND_SCORE);

			if (firstScore == 0.0f && secondScore == 0.0f) {
				return mMapTileList[idx]->getBaseGenGlobalPosition(mSpawnList[idx]);
			}

			DebugReport("Scores %f %f\n", firstScore, secondScore);

			f32 firstPercentage  = FABS(firstScore) / (FABS(firstScore) + FABS(secondScore));
			f32 secondPercentage = 1.0f - firstPercentage;

			DebugReport("Percentages %f\n", firstPercentage);
			
			newScore[FIRST_SCORE]  -= firstScore;
			newScore[SECOND_SCORE] -= secondScore;

			// gScoreBias = (firstPercentage * 0.1f) + (gScoreBias * 0.9f);

			DebugReport("NEW SCORE %i, %i\n", newScore[FIRST_SCORE], newScore[SECOND_SCORE]);
			DebugReport("Score Bias %f\n", gScoreBias);

			return mMapTileList[idx]->getBaseGenGlobalPosition(mSpawnList[idx]);
		}
	}

	JUT_PANICLINE(928, "not search item slot\n");
	return Vector3f::zero;
}


void RandItemUnit::getItemDropMapNode(MapNode* testNode, MapNode** outNode, int scores[2], int& outScore)
{
	bool check   = false;
	int unitKind = testNode->mUnitInfo->getUnitKind();
	if (unitKind == UNITKIND_Room) {
		check = true;
	} else if (unitKind == UNITKIND_Cap) {
		if (strncmp(testNode->getUnitName(), "item", 4) == 0) {
			check = true;
		}
	} else if (unitKind == UNITKIND_Corridor) {
		if (testNode->getNumDoors() == 2) {
			// something funky going on here
			int sum = (testNode->getDoorDirect(0) + testNode->getDoorDirect(1)) & 1;
			if (absVal(sum) == 0) {
				check = true;
			}
		} else {
			check = true;
		}
	}

	if (check) {
		int absScore = absVal(testNode->getVersusScore(FIRST_SCORE) - scores[FIRST_SCORE]) 
        + absVal(testNode->getVersusScore(SECOND_SCORE) - scores[SECOND_SCORE]);
		if (gEffectiveTeamCount == 2) {
			absScore = absVal(testNode->getVersusScore(FIRST_SCORE) - scores[FIRST_SCORE]);
		} 
		if (absScore < outScore || (absScore == outScore && randWeightFloat(1.0f) < 0.5f)) {
			*outNode = testNode;
			outScore = absScore;
		}
	}
}

int RandMapScore::getVersusLowScore(int color) {
    return mVersusLowScore[color];
}

int RandMapScore::getVersusHighScore(int color) {
    return mVersusHighScore[color];
}

void RandEnemyUnit::setEnemySlot()
{	
	DebugReport("RandEnemyUnit::setEnemySlot()\n");
	if (mTotalCount < mMaxEnemies) {
		DebugReport("RandEnemyUnit::setEnemyTypeC()\n");
		setEnemyTypeC();
		DebugReport("RandEnemyUnit::setEnemyTypeF()\n");
		setEnemyTypeF();
		DebugReport("RandEnemyUnit::setEnemyTypeB()\n");
		setEnemyTypeB();
		DebugReport("RandEnemyUnit::setEnemyTypeA()\n");
		setEnemyTypeA();
	}
}

void RandMapMgr::getStartPosition(Vector3f& position, int idx)
{
	if (mGenerator->mIsVersusMode) {
		switch (idx)
		{
		case TEAM_RED:
			mRandMapScore->getGlobalPosition(FIXNODE_VsRedOnyon, position);
			break;
		case TEAM_BLUE:
			mRandMapScore->getGlobalPosition(FIXNODE_VsBlueOnyon, position);
			break;
		case TEAM_WHITE:
			mRandMapScore->getGlobalPosition(FIXNODE_VsWhiteOnyon, position);
			break;
		case TEAM_PURPLE:
			mRandMapScore->getGlobalPosition(FIXNODE_VsWhiteOnyon, position);
		default:
			break;
		}
	} else {
		mRandMapScore->getGlobalPosition(FIXNODE_Pod, position);
	}

	position.y += 50.0f;
}

struct ColorGen {
	BaseGen* gen;
	int color;
};

void RandEnemyUnit::setVersusEasyEnemy()
{
	MapNode* onyonNodes[] = { nullptr, nullptr, nullptr, nullptr };
	BaseGen* onyonGens[] = { nullptr, nullptr, nullptr, nullptr };

	for (int i = 0; i < 4; i++) {
		onyonNodes[i] = mMapScore->getFixObjNode(FIXNODE_VsRedOnyon + i);
		onyonGens[i] = mMapScore->getFixObjGen(FIXNODE_VsRedOnyon + i);
	}
	
	EnemyTypeID::EEnemyTypeID vsEasyIDs[] = { EnemyTypeID::EnemyID_Pelplant, EnemyTypeID::EnemyID_UjiA };

	int enemyCounts[ARRAY_SIZE(vsEasyIDs)][4] = { {0, 0, 0, 0}, {0, 0, 0, 0} };

	EnemyNode* mainNode = mGenerator->mMainEnemies;

	EnemyUnit* enemyUnits[] = { nullptr, nullptr };
	
	for (EnemyNode* currNode = (EnemyNode*)(mainNode->mChild); currNode;) {
		EnemyUnit* unit = currNode->mEnemyUnit;
		TekiInfo* currInfo = currNode->getTekiInfo();
		EnemyNode* nextNode = (EnemyNode*)currNode->mNext;

		if (currInfo) {

			currInfo->mEnemyID = MakeReplacementFromGenericEnemy(currInfo->mEnemyID);


			if (currInfo->mEnemyID == vsEasyIDs[0]) {
				enemyCounts[0][0] += currInfo->mWeight / 10;
				enemyUnits[0] = unit;
				currNode->del();
				mainNode->addHead(currNode);
			}
			else if (currInfo->mEnemyID == vsEasyIDs[1]) {
				enemyCounts[1][0] += currInfo->mWeight / 10;
				DebugReport("Enemy Count 2 %i\n", enemyCounts[1][0]);
				enemyUnits[1] = unit;
				currNode->del();
				mainNode->addHead(currNode);
			}
		}
		currNode = nextNode;
	}

	
	for (int i = 0; i < 2; i++) {
		DebugReport("enemyCounts[%i][0] %i\n", i, enemyCounts[i][0]);
		if (enemyCounts[i][0] == 0) continue;


		for (int j = gEffectiveTeamCount - 1; j >= 0; j--) {
			enemyCounts[i][j] = enemyCounts[i][0] / gEffectiveTeamCount;
		}
		
		if (enemyUnits[i]) {
			for (int j = 0; j < gEffectiveTeamCount; j++) {
				if (enemyCounts[i][j] != 0) {
					BaseGen* spawnBaseGen = getVersusEasyEnemyBaseGen(onyonNodes[j], onyonGens[j]);
					DebugReport("Pelplant spawn basegen %p\n", spawnBaseGen);
					if (spawnBaseGen) {
						makeSetEnemyTypeA(onyonNodes[j], spawnBaseGen, enemyUnits[i], enemyCounts[i][j]);
					}
				}
			}

		}
	}
	gPelplantEnemyUnit = enemyUnits[0];
	gPelplantsPerBunch = enemyCounts[0][0];
}

void RandEnemyUnit::setSlotEnemyTypeA(int& first, int& second, int third) {
	int maxGenScore;
	int maxGenTeam;
	Vector3f positions[4];
	for (int i = 0; i < 4; i++) {
		MapNode* onyonNode = mMapScore->getFixObjNode(FIXNODE_VsRedOnyon + i);
		BaseGen* onyonGen = mMapScore->getFixObjGen(FIXNODE_VsRedOnyon + i);
		if (onyonNode) {
			positions[i] = onyonNode->getBaseGenGlobalPosition(onyonGen);
		}
		if (i == 0 && third == 0) {
			maxGenScore = onyonNode->getVersusScore();
			maxGenTeam = -1;
		}
		if (i == 1 && third == 1) {
			maxGenScore = onyonNode->getVersusScore();
			maxGenTeam = 1;
		}
	}

	BaseGen* validGens[128];
	MapNode* validNodes[128];
	int scores[128];
	int currScore = 0;
	int count = 0;

	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode) {
		if (currNode->mUnitInfo->getUnitKind() != UNITKIND_Room) continue;
		BaseGen* firstGen = currNode->mUnitInfo->getBaseGen();
		if (!firstGen) continue;
		
		FOREACH_NODE(BaseGen, firstGen->mChild, currGen) {
			if (currGen->mSpawnType != BaseGen::TekiA__Easy || isEnemySetGen(currNode, currGen)) continue;
			bool genLegal = true;

			for (int i = 0; i < 4; i++) {
				Vector3f genPos = currNode->getBaseGenGlobalPosition(currGen);
				if (_distanceBetween(positions[i], genPos) < 400.0f) {
					genLegal = false;
					break;
				}
			}

			if (genLegal) {
				validGens[count]  = currGen;
				validNodes[count] = currNode;
				int score = maxGenTeam * (currNode->getVersusScore() + maxGenScore);
				if (score < 1) {
					score = 1;
				}
				currScore += score;
				scores[count] = score;
				count++;
			}
		}

		
	}

	mMapTile = nullptr;
	mSpawn   = nullptr;
	if (count == 0) return;

	int randScore = randFloat() * currScore;
	int newCurrScore = 0;
	for (int i = 0; i < count; i++) {
		newCurrScore += scores[i];
		if (newCurrScore > randScore) {
			mMapTile = validNodes[i];
			mSpawn   = validGens[i];
			first = validGens[i]->mMaximum;
			second = validGens[i]->mMinimum;
			return;
		}
	}
}

void RandEnemyUnit::setSlotEnemyTypeB(int third) {
	int maxGenScore;
	int maxGenTeam;
	Vector3f positions[4];
	for (int i = 0; i < 4; i++) {
		MapNode* onyonNode = mMapScore->getFixObjNode(FIXNODE_VsRedOnyon + i);
		BaseGen* onyonGen = mMapScore->getFixObjGen(FIXNODE_VsRedOnyon + i);
		if (onyonNode) {
			positions[i] = onyonNode->getBaseGenGlobalPosition(onyonGen);
		}
		if (i == 0 && third == 0) {
			maxGenScore = onyonNode->getVersusScore();
			maxGenTeam = -1;
		}
		if (i == 1 && third == 1) {
			maxGenScore = onyonNode->getVersusScore();
			maxGenTeam = 1;
		}
	}

	BaseGen* validGens[128];
	MapNode* validNodes[128];
	int scores[128];
	int currScore = 0;
	int count = 0;

	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode) {
		if (currNode->mUnitInfo->getUnitKind() != UNITKIND_Room) continue;
		BaseGen* firstGen = currNode->mUnitInfo->getBaseGen();
		if (!firstGen) continue;
		
		FOREACH_NODE(BaseGen, firstGen->mChild, currGen) {
			if (currGen->mSpawnType != BaseGen::TekiB__Hard || isEnemySetGen(currNode, currGen)) continue;
			bool genLegal = true;

			for (int i = 0; i < 4; i++) {
				Vector3f genPos = currNode->getBaseGenGlobalPosition(currGen);
				if (_distanceBetween(positions[i], genPos) < 400.0f) {
					genLegal = false;
					break;
				}
			}

			if (genLegal) {
				validGens[count]  = currGen;
				validNodes[count] = currNode;
				int score = maxGenTeam * (currNode->getVersusScore() + maxGenScore);
				if (score < 1) {
					score = 1;
				}
				currScore += score;
				scores[count] = score;
				count++;
			}
		}

		
	}

	mMapTile = nullptr;
	mSpawn   = nullptr;
	if (count == 0) return;

	int randScore = randFloat() * currScore;
	int newCurrScore = 0;
	for (int i = 0; i < count; i++) {
		newCurrScore += scores[i];
		if (newCurrScore > randScore) {
			mMapTile = validNodes[i];
			mSpawn   = validGens[i];
			return;
		}
	}
}

void RandEnemyUnit::setSlotEnemyTypeF(int third) {
	int maxGenScore;
	int maxGenTeam;
	Vector3f positions[4];
	for (int i = 0; i < 4; i++) {
		MapNode* onyonNode = mMapScore->getFixObjNode(FIXNODE_VsRedOnyon + i);
		BaseGen* onyonGen = mMapScore->getFixObjGen(FIXNODE_VsRedOnyon + i);
		
		if (onyonNode) {
			positions[i] = onyonNode->getBaseGenGlobalPosition(onyonGen);
		}
		if (i == 0 && third == 0) {
			maxGenScore = onyonNode->getVersusScore();
			maxGenTeam = -1;
		}
		if (i == 1 && third == 1) {
			maxGenScore = onyonNode->getVersusScore();
			maxGenTeam = 1;
		}
	}

	BaseGen* validGens[128];
	MapNode* validNodes[128];
	int scores[128];
	int currScore = 0;
	int count = 0;

	FOREACH_NODE(MapNode, mGenerator->mPlacedMapNodes->mChild, currNode) {
		if (currNode->mUnitInfo->getUnitKind() != UNITKIND_Room) continue;
		BaseGen* firstGen = currNode->mUnitInfo->getBaseGen();
		if (!firstGen) continue;
		
		FOREACH_NODE(BaseGen, firstGen->mChild, currGen) {
			if (currGen->mSpawnType != BaseGen::TekiF__Special || isEnemySetGen(currNode, currGen)) continue;
			bool genLegal = true;

			for (int i = 0; i < 4; i++) {
				Vector3f genPos = currNode->getBaseGenGlobalPosition(currGen);
				if (_distanceBetween(positions[i], genPos) < 400.0f) {
					genLegal = false;
					break;
				}
			}

			if (genLegal) {
				validGens[count]  = currGen;
				validNodes[count] = currNode;
				int score = maxGenTeam * (currNode->getVersusScore() + maxGenScore);
				if (score < 1) {
					score = 1;
				}
				currScore += score;
				scores[count] = score;
				count++;
			}
		}

		
	}

	mMapTile = nullptr;
	mSpawn   = nullptr;
	if (count == 0) return;

	int randScore = randFloat() * currScore;
	int newCurrScore = 0;
	for (int i = 0; i < count; i++) {
		newCurrScore += scores[i];
		if (newCurrScore > randScore) {
			mMapTile = validNodes[i];
			mSpawn   = validGens[i];
			return;
		}
	}
}

void RandMapScore::setMapUnitScore()
{
	DebugReport("RandMapScore::setMapUnitScore()\n");
	clearRoomAndDoorScore();
	if (!isScoreSetDone()) {
		for (int i = 0; i < 500; i++) {
			setUnitAndDoorScore();
			if (isScoreSetDone()) {
				return;
			}
		}
	}
}

void RandMapMgr::create()
{
	DebugReport("RandMapMgr::create()\n");
	// The CaveGen Function (tm)

	// Round 1: place map tiles + set ship spawn
	mRandMapUnit->setMapUnit();
	mRandMapScore->setStartSlot();
	// Calculate score after round 1 (just distance score based on map tile layout)
	mRandMapScore->setMapUnitScore();

	// Round 2: place hole (and geyser), then place enemies
	mRandMapScore->setGoalSlot();
	mRandEnemyUnit->setEnemySlot();
	// Calculate score after round 2 (now includes enemies as well as distance score)
	mRandMapScore->setMapUnitScore();

	// Round 3: place plants, then treasures, then cap enemies
	mRandPlantUnit->setPlantSlot();
	mRandItemUnit->setItemSlot();
	mRandCapEnemyUnit->setCapEnemySlot();
	// Calculate score after round 3 (doesn't get used again though)
	mRandMapScore->setMapUnitScore();

	// Round 4: place gates
	mRandGateUnit->setGateDoor();

	// With all units placed, determine radar texture size + allocate
	int x;
	int y;
	mRandMapUnit->getTextureSize(x, y);

	x *= 8;
	y *= 8;

	sys->heapStatusStart("Radar Map Texture", nullptr);
	mRadarMapTexture                          = new JUTTexture(x, y, GX_TF_I4);
	mRadarMapTexture->mTexInfo->mTransparency = Transparency_2;
	sys->heapStatusEnd("Radar Map Texture");
}


} // namespace Cave

} // namespace Game
