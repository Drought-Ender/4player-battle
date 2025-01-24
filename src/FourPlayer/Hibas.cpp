#include "Game/Entities/Hibas.h"

namespace Game {
namespace WaterHiba {

static const char hibaMgrName[] = "246-HibaMgr";

/*
 * --INFO--
 * Address:	8026B8BC
 * Size:	000064
 */
Mgr::Mgr(int objLimit, u8 modelType)
    : EnemyMgrBaseAlwaysMovieActor(objLimit, modelType)
{
	mName = "ヒバマネージャ"; // hiba manager
}

/*
 * --INFO--
 * Address:	8026B9D0
 * Size:	000048
 */
void Mgr::doAlloc() { init(new Hiba::Parms); }

/*
 * --INFO--
 * Address:	8026BBA8
 * Size:	000060
 */
void Mgr::createObj(int count) { mObj = new Obj[count]; }

/*
 * --INFO--
 * Address:	8026BCC4
 * Size:	000010
 */
EnemyBase* Mgr::getEnemy(int index) { return &mObj[index]; }

Obj::Obj()
{
	OSReport("NEW HIBA WATER\n");
	mAnimator = new Hiba::ProperAnimator;
	setFSM(new Hiba::FSM);
	createEffect();
}

void Obj::createEffect() { mEfxFire = (efx::THibaFire*)new efx::THibaWater; }

} // namespace WaterHiba

namespace GasLineHiba {

static const char hibaMgrName[] = "246-HibaMgr";

/*
 * --INFO--
 * Address:	8026B8BC
 * Size:	000064
 */
Mgr::Mgr(int objLimit, u8 modelType)
    : EnemyMgrBaseAlwaysMovieActor(objLimit, modelType)
{
	mName = "ヒバマネージャ"; // hiba manager
}

/*
 * --INFO--
 * Address:	8026B9D0
 * Size:	000048
 */
void Mgr::doAlloc() { init(new Hiba::Parms); }

/*
 * --INFO--
 * Address:	8026BBA8
 * Size:	000060
 */
void Mgr::createObj(int count) { mObj = new Obj[count]; }

/*
 * --INFO--
 * Address:	8026BCC4
 * Size:	000010
 */
EnemyBase* Mgr::getEnemy(int index) { return &mObj[index]; }

Obj::Obj()
{
	mAnimator = new Hiba::ProperAnimator;
	setFSM(new Hiba::FSM);
	createEffect();
}

void Obj::createEffect() { mEfxFire = (efx::THibaFire*)new efx::THibaLineGas; }

} // namespace GasLineHiba

namespace SporeHiba {

static const char hibaMgrName[] = "246-HibaMgr";

/*
 * --INFO--
 * Address:	8026B8BC
 * Size:	000064
 */
Mgr::Mgr(int objLimit, u8 modelType)
    : EnemyMgrBaseAlwaysMovieActor(objLimit, modelType)
{
	mName = "ヒバマネージャ"; // hiba manager
}

/*
 * --INFO--
 * Address:	8026B9D0
 * Size:	000048
 */
void Mgr::doAlloc() { init(new Hiba::Parms); }

/*
 * --INFO--
 * Address:	8026BBA8
 * Size:	000060
 */
void Mgr::createObj(int count) { mObj = new Obj[count]; }

/*
 * --INFO--
 * Address:	8026BCC4
 * Size:	000010
 */
EnemyBase* Mgr::getEnemy(int index) { return &mObj[index]; }

Obj::Obj()
{
	OSReport("NEW HIBA SPORE\n");
	mAnimator = new Hiba::ProperAnimator;
	setFSM(new Hiba::FSM);
	createEffect();
}

void Obj::createEffect() { mEfxFire = (efx::THibaFire*)new efx::THibaSpore; }

} // namespace SporeHiba

} // namespace Game
