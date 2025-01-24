#include "Game/pelletMgr.h"
#include "VsOtakaraName.h"
#include "Game/VsGameSection.h"
#include "Game/gamePlayData.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Stickers.h"
#include "Iterator.h"
#include "PikiAI.h"
#include "Game/PikiState.h"
#include "Game/MapMgr.h"
#include "Game/Entities/ItemTreasure.h"
#include "sysMath.h"
#include "Game/Navi.h"
#include "Game/Entities/ItemTreasure.h"
#include "efx/THebi.h"
#include "PSSystem/PSSystemIF.h"
#include "Screen/Game2DMgr.h"

namespace Game {

float PelletBounceBuryState::mBounceHeight = 600.0f;
float PelletBounceBuryState::mBurryRadius  = 25.0f;

PelletBounceBuryState::PelletBounceBuryState()
    : PelletState(PELSTATE_BounceBury)
{
	mAirTime   = 0.0f;
	mIsFalling = false;
}

void PelletBounceBuryState::init(Pellet* pellet, StateArg* arg)
{
	BounceBuryStateArg* bounceArg    = (BounceBuryStateArg*)arg;
	Iterator<BaseItem> iTreasure     = ItemTreasure::mgr;
	ItemTreasure::Item* thisTreasure = nullptr;
	CI_LOOP(iTreasure)
	{
		BaseItem* item                   = *iTreasure;
		ItemTreasure::Item* currTreasure = static_cast<ItemTreasure::Item*>(item);
		if (currTreasure->mPellet == pellet) {
			thisTreasure = currTreasure;
			break;
		}
	}
	// const char* color = (pellet->m_pelletFlag == 4) ? "red" : "blue";
	// if (!thisTreasure) {
	//     JUT_PANIC("%s bedama's treasure could not be found", color);
	// }
	Vector3f launch = Vector3f(0.0f, mBounceHeight, 0.0f);
	if (thisTreasure) {
		thisTreasure->releasePellet();
		Sys::Sphere sphere(pellet->mPelletPosition, mBurryRadius);
		CellIteratorArg arg   = sphere;
		CellIterator cellIter = arg;
		CI_LOOP(cellIter)
		{
			CellObject* cell = *cellIter;
			if (cell->isPiki()) {
				Piki* piki = (Piki*)cell;
				if (piki->isAlive()) {
					BlowStateArg blowState(launch, 0.0f, false, 2, pellet);
					piki->mFsm->transit(piki, PIKISTATE_Blow, &blowState);
				}
			}
		}
	}
	pellet->endPick(false);
	if (bounceArg) {
		Iterator<Creature> iCreature = bounceArg->mHeldPikis;
		CI_LOOP(iCreature)
		{
			Creature* currCreature = *iCreature;
			if (currCreature->isPiki() && currCreature->isAlive()) {
				Piki* piki = static_cast<Piki*>(currCreature);
				piki->endStick();
				BlowStateArg blowState(launch, 0.0f, false, 2, pellet);
				piki->mFsm->transit(piki, PIKISTATE_Blow, &blowState);
			}
		}
	}
	PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_THROW, 0);
	pellet->setVelocity(launch);
}

void PelletBounceBuryState::exec(Pellet* pellet)
{
	mAirTime += sys->mDeltaTime;
	float pelHeight = pellet->mPelletPosition.y;
	float minY      = mapMgr->getMinY(pellet->mPelletPosition);
	if (mAirTime > 0.7f && FABS(pelHeight - minY) <= 30.0f) {
		bury(pellet);
		PelletBounceBuryState::doEfx(pellet);
		PSSystem::spSysIF->playSystemSe(PSSE_EN_ROCK_BREAK, 0);

		transit(pellet, PELSTATE_Bury, nullptr);
	} else {
		flickNearby(pellet);
		if (pellet->getVelocity().y < 0.0f && !mIsFalling) {
			mIsFalling = true;
			PSSystem::spSysIF->playSystemSe(PSSE_EN_ROCK_FALL, 0);
		}
	}
}

void PelletBounceBuryState::bury(Pellet* pellet)
{
	JUT_ASSERT(ItemTreasure::mgr, "Item treasure mgr missing!\n");

	pellet->mPelletPosition.y = mapMgr->getMinY(pellet->mPelletPosition);

	ItemTreasure::Item* burriedPellet = (ItemTreasure::Item*)ItemTreasure::mgr->birth();
	burriedPellet->init(nullptr);
	burriedPellet->setPosition(pellet->mPelletPosition, false);
	burriedPellet->setTreasure(pellet);

	Sys::Sphere sphere(pellet->mPelletPosition, mBurryRadius);
	CellIteratorArg arg   = sphere;
	CellIterator cellIter = arg;
	CI_LOOP(cellIter)
	{
		CellObject* cell = *cellIter;
		if (cell->isPiki()) {
			Piki* piki = (Piki*)cell;
			if (piki->isAlive()) {
				InteractFallMeck bury(pellet, 0.0f);
				piki->stimulate(bury);
			}
		} else if (cell->isNavi()) {
			Navi* navi = (Navi*)cell;
			if (navi->isAlive()) {
				InteractPress press(pellet, 10.0f, nullptr);
				navi->stimulate(press);
			}
		} else if (cell->getObjType() == OBJTYPE_Teki) {
			EnemyBase* teki = (EnemyBase*)cell;
			if (teki->isAlive()) {
				InteractBomb bomb(pellet, 500.0f, &Vector3f::zero);
				teki->stimulate(bomb);
			}
		}
	}
}

void PelletBounceBuryState::doEfx(Pellet* pellet)
{
	efx::Arg efxArg = pellet->mPelletPosition;
	efx::THebiAphd_dive hebiDive;
	hebiDive.create(&efxArg);
}

void PelletBounceBuryState::flickNearby(Pellet* pellet)
{
	Sys::Sphere sphere(pellet->mPelletPosition, mBurryRadius);
	CellIteratorArg arg   = sphere;
	CellIterator cellIter = arg;
	CI_LOOP(cellIter)
	{
		CellObject* cell = *cellIter;
		if (cell->isPiki()) {
			Piki* piki = (Piki*)cell;
			if (piki->isAlive()) {
				Vector3f distance = pellet->mPelletPosition - piki->mPosition3;
				InteractFlick(pellet, 1.0f, 0.0f, pikmin2_atan2f(distance.x, distance.y));
			}
		}
	}
}

void PelletBounceBuryState::cleanup(Pellet* pellet)
{
	mAirTime   = 0.0f;
	mIsFalling = false;
}

bool PelletBounceBuryState::isBuried() { return false; }
bool PelletBounceBuryState::appeared() { return true; }
bool PelletBounceBuryState::isPickable() { return false; }

void Pelletinit(PelletFSM* fsm, Pellet* pellet)
{
	fsm->create(PELLET_STATE_COUNT);
	fsm->registerState(new PelletNormalState);
	fsm->registerState(new PelletGoalState);
	fsm->registerState(new PelletBuryState);
	fsm->registerState(new PelletUpState);
	fsm->registerState(new PelletAppearState);
	fsm->registerState(new PelletScaleAppearState);
	fsm->registerState(new PelletZukanState);
	fsm->registerState(new PelletGoalWaitState);
	fsm->registerState(new PelletReturnState);
	fsm->registerState(new PelletBounceBuryState);
}
} // namespace Game