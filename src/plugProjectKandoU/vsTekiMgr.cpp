#include "Game/enemyInfo.h"
#include "Game/generalEnemyMgr.h"
#include "Game/VsGame.h"
#include "Dolphin/rand.h"

namespace Game {
namespace VsGame {

/*
 * --INFO--
 * Address:	802352F0
 * Size:	000044
 */
TekiMgr::TekiMgr() { mNodeCount = 0; }

/*
 * --INFO--
 * Address:	80235394
 * Size:	0000A0
 */
void TekiMgr::entry(EnemyTypeID::EEnemyTypeID id, int a2)
{
	TekiNode* newNode = new TekiNode();
	newNode->mId      = id;
	newNode->_1C      = a2;
	newNode->mNodeID  = mNodeCount++;
	mNode.add(newNode);

	generalEnemyMgr->addEnemyNum(id, a2, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
TekiNode* TekiMgr::getNode(int idx) { return static_cast<TekiNode*>(mNode.getChildAt(idx)); }

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 * Speculation: possibly inlined into TekiMgr::birth
 * Unknown return type
 */
/*
bool TekiMgr::birthable(int)
{
    // UNUSED FUNCTION
}
*/

/*
 * --INFO--
 * Address:	80235434
 * Size:	0000D8
 */
EnemyBase* TekiMgr::birth(int idx, Vector3f& position, bool check)
{
	return birth(idx, position, check ? 50.0f : 0.0f);
}

EnemyBase* TekiMgr::birth(int idx, Vector3f& position, float timer)
{
	TekiNode* node = getNode(idx);
	if (node) {
		EnemyBirthArg birthArg;
		birthArg.mFaceDir  = TAU * randFloat();
		birthArg.mPosition = position;
		birthArg.mExistenceLength = timer;
		EnemyBase* teki = generalEnemyMgr->birth(node->mId, birthArg);
		if (teki) {
			teki->init(nullptr);
		}
		return teki;
	}
	return nullptr;
}

EnemyBase* TekiMgr::birthFromSky(int idx, Vector3f& position, float timer)
{
	TekiNode* node = getNode(idx);
	if (node) {
		EnemyBirthArg birthArg;
		birthArg.mFaceDir  = TAU * randFloat();
		birthArg.mPosition = position;
		birthArg.mExistenceLength = timer;
		birthArg.mTekiBirthType = 6;
		EnemyBase* teki = generalEnemyMgr->birth(node->mId, birthArg);
		if (teki) {
			teki->init(nullptr);
		}
		return teki;
	}
	return nullptr;
}


int TekiMgr::getEnemy(EnemyTypeID::EEnemyTypeID id) {
	for (int i = 0; i < mNodeCount; i++) {
		if (getNode(i)->mId == id) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 * Unknown return type. Likely int or EnemyTypeID::EEnemyTypeID
 */
/*
EnemyTypeID::EEnemyTypeID TekiMgr::getID(int)
{
    // UNUSED FUNCTION
}
*/

} // namespace VsGame
} // namespace Game
