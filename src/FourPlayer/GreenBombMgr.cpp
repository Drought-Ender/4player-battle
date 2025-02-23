#include "Game/Entities/GreenBomb.h"

namespace Game {
namespace GreenBomb {

/*
 * --INFO--
 * Address:	80349DD8
 * Size:	000050
 */
Mgr::Mgr(int objLimit, u8 modelType)
    : EnemyMgrBase(objLimit, modelType)
{
	mName = "���e�}�l�[�W��"; // bomb manager
}

/*
 * --INFO--
 * Address:	80349E28
 * Size:	000048
 */
void Mgr::doAlloc() { init(new Bomb::Parms); }

/*
 * --INFO--
 * Address:	80349FC0
 * Size:	000020
 */
EnemyBase* Mgr::birth(EnemyBirthArg& birthArg) { return EnemyMgrBase::birth(birthArg); }

void Mgr::loadModelData()
{
	EnemyMgrBase::loadModelData();
	J3DShape* shape;
	for (u16 j = 0; j < mModelData->getShapeNum(); j++) {
		shape         = mModelData->mShapeTable.mItems[j];
		shape->mFlags = (shape->mFlags & (~0xF000)) | 0x2000;
	}
}

} // namespace Bomb
} // namespace Game
