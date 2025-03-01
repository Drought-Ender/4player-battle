#include "PikiAI.h"
#include "Game/Piki.h"
#include "Game/PikiMgr.h"
#include "Game/PikiState.h"
#include "Game/Navi.h"
#include "Game/NaviParms.h"
#include "Game/NaviState.h"
#include "Game/gameStat.h"
#include "Game/CPlate.h"
#include "Game/GameSystem.h"
#include "Game/SingleGameSection.h"
#include "Game/gamePlayData.h"
#include "Game/MoviePlayer.h"
#include "Game/Footmark.h"
#include "Dolphin/rand.h"
#include "JSystem/JUtility/JUTException.h"
#include "Iterator.h"

#include "Game/Entities/ItemGate.h"
#include "Game/Entities/ItemBridge.h"
#include "Game/Entities/ItemRock.h"
#include "Game/Entities/ItemWeed.h"
#include "Game/Entities/ItemHoney.h"
#include "Game/Entities/ItemBigFountain.h"
#include "Game/Entities/ItemBarrel.h"
#include "Game/Entities/ItemTreasure.h"
#include "Game/Entities/ItemPlant.h"
#include "Game/Entities/ItemDengekiGate.h"
#include "Game/generalEnemyMgr.h"

#include "VsOptions.h"

namespace PikiAI {

void ActFormation::setFormed()
{
	mSortState = 1;

	// if Meet Red Pikmin cutscene hasn't played, play it.
	if (!Game::playData->isDemoFlag(Game::DEMO_Meet_Red_Pikmin)) {

		Iterator<Game::Piki> iterator(Game::pikiMgr);
		CI_LOOP(iterator)
		{
			Game::Piki* piki = (*iterator);
			piki->movie_begin(false);
		}

		Game::Navi* navi = Game::naviMgr->getActiveNavi();
		P2ASSERTLINE(438, navi);

		Game::playData->setDemoFlag(Game::DEMO_Meet_Red_Pikmin);

		Game::MoviePlayArg playArg("x02_watch_red_pikmin", nullptr, nullptr, 0);
		playArg.mOrigin                  = navi->getPosition();
		playArg.mAngle                   = navi->getFaceDir();
		Game::moviePlayer->mTargetObject = navi;

		Game::moviePlayer->play(playArg);

		Game::gameSystem->mSection->disableTimer(Game::DEMOTIMER_Meet_Red_Pikmin);
	}

	Game::Navi* navi = mParent->mNavi;
	int index        = 0;
	if (navi) {
		index = navi->mNaviIndex;
	}

	/* do more checks if:
	    a) we're above ground,
	    b) some flag is set,
	    c) reds-purples cutscene hasn't played, and
	    d) purples in ship cutscene HAS played
	*/
	if (!Game::gameSystem->mIsInCave && Game::gameSystem->mFlags & 0x20 && !Game::playData->isDemoFlag(Game::DEMO_Reds_Purples_Tutorial)
	    && Game::playData->isDemoFlag(Game::DEMO_Purples_In_Ship)) {
		Game::GameStat::checkNaviIndex(index); // check navi index is between 0 and 6 otherwise panic (?)
		Game::GameStat::PikiCounter* counter = &Game::GameStat::formationPikis.mCounter[index]; // get squad numbers

		int redCount = (*counter)(Game::Red);

		// if we have reds in squad...
		if (redCount > 0) {

			Game::GameStat::checkNaviIndex(index);
			int purpleCount = (*counter)(Game::Purple);

			// ... AND we have purples in squad...
			if (purpleCount > 0) {

				// ... AND the reds-purples timer isn't already going...
				if (Game::gameSystem->mSection->getTimerType() != Game::DEMOTIMER_Reds_Purples_Tutorial) {

					// set reds-purples cutscene timer to 10s.
					Game::gameSystem->mSection->enableTimer(10.0f, Game::DEMOTIMER_Reds_Purples_Tutorial);
				}
			}
		}
	}
}

} // namespace PikiAI

namespace Game {

#define PIKI_BATTLE_RANGE   (70.0f)
#define PIKI_RESCUE_RANGE   (140.0f)
#define GATE_GAS_PIPE_RANGE (128.0f)

/**
 * @note Address: 0x801B1360
 * @note Size: 0x1A04
 */
int Piki::graspSituation(Game::Creature** outTarget)
{
	if (moviePlayer && moviePlayer->mDemoState != 0) {
		*outTarget = nullptr;
		return PikiAI::ACT_NULL;
	}

	f32 minDist      = 100.0f;
	Creature* target = nullptr;
	int action       = PikiAI::ACT_NULL;

	// check if we can fight a piki.
	if (gameSystem->isVersusMode()) {
		Piki* targetPiki = nullptr;
		f32 minPikiDist  = PIKI_BATTLE_RANGE;
		Iterator<Piki> iter(pikiMgr);
		CI_LOOP(iter)
		{
			Piki* piki = *iter;
			if (piki->isAlive() && piki->canVsBattle() && !piki->getVsBattlePiki() && piki->getKind() != getKind()) {
				f32 sphereDist = piki->calcSphereDistance(this);
				if (sphereDist < minPikiDist) {
					targetPiki  = piki;
					minPikiDist = sphereDist;
				}
			}
		}

		if (targetPiki && minPikiDist < 100.0f) {
			*outTarget = targetPiki;
			return PikiAI::ACT_Battle;
		}
	}

	// check if we can rescue a piki.
	// if (getKind() == Blue) {
	// 	Piki* targetPiki = nullptr;
	// 	f32 minPikiDist  = PIKI_RESCUE_RANGE;
	// 	Iterator<Piki> iter(pikiMgr);
	// 	CI_LOOP(iter)
	// 	{
	// 		Piki* piki = *iter;
	// 		if (piki->isAlive() && piki->getStateID() == PIKISTATE_Drown) {
	// 			f32 sphereDist = piki->calcSphereDistance(this);
	// 			if (sphereDist < minPikiDist) {
	// 				targetPiki  = piki;
	// 				minPikiDist = sphereDist;
	// 			}
	// 		}
	// 	}

	// 	if (targetPiki && minPikiDist < 100.0f) {
	// 		minDist = minPikiDist;
	// 		target  = targetPiki;
	// 		action  = PikiAI::ACT_Rescue;
	// 	}
	// }

	// check for pellets to grab
	Pellet* targetPellet = nullptr;
	f32 minPelDist       = *pikiMgr->mParms->mPikiParms.mPelletSearchRange();

	PelletIterator pelIter;
	CI_LOOP(pelIter)
	{
		Pellet* pellet = *pelIter;
		if (pellet->isAlive() && !pellet->mCaptureMatrix && pellet->getFreeStickSlot() != -1 && !isZikatu()) {
			bool isGrabbable = true;
			if (pellet->getKind() == 4 && gameSystem->isStoryMode()) {
				int configIdx = pellet->getConfigIndex();
				if (!playData->isFindItemDemoFlag(configIdx)) {
					isGrabbable = false;
				}
			}

			if ((!gameSystem->isVersusMode() || canCarryBedama(this, pellet)) && !pellet->discoverDisabled() && isGrabbable) {
				f32 sphereDist = pellet->calcSphereDistance(this);
				if (sphereDist < minPelDist) {
					targetPellet = pellet;
					minPelDist   = sphereDist;
				}
			}
		}
	}

	if (targetPellet && minPelDist < minDist) {
		minDist = minPelDist;
		target  = targetPellet;
		action  = PikiAI::ACT_Transport;
	}

	// check for gates to attack (NB: no poison check?)
	if (itemGateMgr) {
		ItemGate* targetGate = nullptr;
		f32 minGateDist      = *pikiMgr->mParms->mPikiParms.mNectarRockRangeDuplicate();
		Iterator<ItemGate> gateIter(&itemGateMgr->mNodeObjectMgr);
		CI_LOOP(gateIter)
		{
			ItemGate* gate = *gateIter;
			if (gate->isAlive()) {
				f32 workDist = gate->getWorkDistance(mBoundingSphere);
				if (workDist < minGateDist) {
					targetGate  = gate;
					minGateDist = workDist;
				}
			}
		}

		if (targetGate && minGateDist < minDist) {
			minDist = minGateDist;
			target  = targetGate;
			action  = PikiAI::ACT_BreakGate;
		}
	}

	// check for electric gates to attack
	if (ItemDengekiGate::mgr) {
		ItemGate* targetGate = nullptr;
		f32 minGateDist      = *pikiMgr->mParms->mPikiParms.mNectarRockRangeDuplicate();
		Iterator<ItemGate> gateIter(ItemDengekiGate::mgr);
		CI_LOOP(gateIter)
		{
			ItemGate* gate = *gateIter;
			if (gate->isAlive()) {
				f32 workDist = gate->getWorkDistance(mBoundingSphere);
				if (workDist < minGateDist) {
					targetGate  = gate;
					minGateDist = workDist;
				}
			}
		}

		if (targetGate && minGateDist < minDist) {
			minDist = minGateDist;
			target  = targetGate;
			action  = PikiAI::ACT_BreakGate;
		}
	}

	// check for bridges to build
	if (ItemBridge::mgr) {
		ItemBridge::Item* targetBridge = nullptr;
		f32 minBridgeDist              = *pikiMgr->mParms->mPikiParms.mBridgeSearchRange();
		Iterator<BaseItem> bridgeIter(ItemBridge::mgr);
		CI_LOOP(bridgeIter)
		{
			ItemBridge::Item* bridge = static_cast<ItemBridge::Item*>(*bridgeIter);
			if (bridge->isAlive() && bridge->workable(mPosition3)) {
				f32 workDist = bridge->getWorkDistance(mBoundingSphere);
				if (workDist < minBridgeDist) {
					targetBridge  = bridge;
					minBridgeDist = workDist;
				}
			}
		}

		if (targetBridge && minBridgeDist < minDist) {
			minDist = minBridgeDist;
			target  = targetBridge;
			action  = PikiAI::ACT_Bridge;
		}
	}

	// check for mold to attack
	if (ItemRock::mgr) {
		ItemRock::Item* targetRock = nullptr;
		f32 minRockDist            = *pikiMgr->mParms->mPikiParms.mNectarRockSearchRange();
		Iterator<BaseItem> rockIter(ItemRock::mgr);
		CI_LOOP(rockIter)
		{
			ItemRock::Item* rock = static_cast<ItemRock::Item*>(*rockIter);
			if (rock->isAlive()) {
				f32 workDist = rock->getWorkDistance(mBoundingSphere);
				if (workDist < minRockDist) {
					targetRock  = rock;
					minRockDist = workDist;
				}
			}
		}

		if (targetRock && minRockDist < minDist) {
			minDist = minRockDist;
			target  = targetRock;
			action  = PikiAI::ACT_BreakRock;
		}
	}

	// check for geysers to break
	if (ItemBigFountain::mgr) {
		ItemBigFountain::Item* targetGeyser = nullptr;
		f32 minGeyserDist                   = *pikiMgr->mParms->mPikiParms.mNectarRockSearchRange();
		Iterator<BaseItem> geyserIter(ItemBigFountain::mgr);
		CI_LOOP(geyserIter)
		{
			ItemBigFountain::Item* geyser = static_cast<ItemBigFountain::Item*>(*geyserIter);
			if (geyser->isAlive()) {
				f32 workDist = geyser->getWorkDistance(mBoundingSphere);
				if (workDist < minGeyserDist) {
					targetGeyser  = geyser;
					minGeyserDist = workDist;
				}
			}
		}

		if (targetGeyser && minGeyserDist < minDist) {
			minDist = minGeyserDist;
			target  = targetGeyser;
			action  = PikiAI::ACT_BreakRock;
		}
	}

	// check for clogs to break
	if (ItemBarrel::mgr) {
		ItemBarrel::Item* targetClog = nullptr;
		f32 minClogDist              = *pikiMgr->mParms->mPikiParms.mClogSearchRange();
		Iterator<BaseItem> clogIter(ItemBarrel::mgr);
		CI_LOOP(clogIter)
		{
			ItemBarrel::Item* clog = static_cast<ItemBarrel::Item*>(*clogIter);
			if (clog->isAlive()) {
				f32 workDist = clog->getWorkDistance(mBoundingSphere);
				if (workDist < minClogDist) {
					targetClog  = clog;
					minClogDist = workDist;
				}
			}
		}

		if (targetClog && minClogDist < minDist) {
			minDist = minClogDist;
			target  = targetClog;
			action  = PikiAI::ACT_BreakRock;
		}
	}

	// check for buried treasures to dig
	if (ItemTreasure::mgr) {
		ItemTreasure::Item* targetTreasure = nullptr;
		f32 minTreasureDist                = *pikiMgr->mParms->mPikiParms.mBuriedTreasureSearchRange();
		Iterator<BaseItem> treasureIter(ItemTreasure::mgr);
		CI_LOOP(treasureIter)
		{
			ItemTreasure::Item* treasure = static_cast<ItemTreasure::Item*>(*treasureIter);
			if (treasure->isAlive() && canAttackBedamaIdle(this, treasure)) {
				f32 workDist = treasure->getWorkDistance(mBoundingSphere);
				if (workDist < minTreasureDist) {
					targetTreasure  = treasure;
					minTreasureDist = workDist;
				}
			}
		}

		if (targetTreasure && minTreasureDist < minDist) {
			minDist = minTreasureDist;
			target  = targetTreasure;
			action  = PikiAI::ACT_BreakRock;
		}
	}

	// check for spiderworts to harvest berries from
	if (ItemPlant::mgr) {
		ItemPlant::Item* targetPlant = nullptr;
		f32 minPlantDist             = *pikiMgr->mParms->mPikiParms.mSpiderWortSearchRange();
		Iterator<BaseItem> plantIter(ItemPlant::mgr);
		CI_LOOP(plantIter)
		{
			ItemPlant::Plant* plant = static_cast<ItemPlant::Plant*>(*plantIter);
			if (plant->isAlive()) {
				Vector3f plantPos = plant->getPosition();
				f32 dist          = plantPos.distance(mBoundingSphere.mPosition);
				if (dist < minPlantDist) {
					targetPlant  = plant;
					minPlantDist = dist;
				}
			}
		}

		if (targetPlant && minPlantDist < minDist) {
			minDist = minPlantDist;
			target  = targetPlant;
			action  = PikiAI::ACT_Crop;
		}
	}

	// check if we have an enemy to fight
	EnemyBase* targetTeki = nullptr;
	f32 minTekiDist       = *pikiMgr->mParms->mPikiParms.mEnemySearchRange();
	GeneralMgrIterator<EnemyBase> tekiIter(generalEnemyMgr);
	CI_LOOP(tekiIter)
	{
		EnemyBase* enemy = tekiIter.getObject();
		if (enemy->isAlive() && !enemy->isFlying() && enemy->isLivingThing()) {
			f32 sphereDist = enemy->calcSphereDistance(this);
			if (sphereDist < minTekiDist) {
				targetTeki  = enemy;
				minTekiDist = sphereDist;
			}
		}
	}

	if (targetTeki && minTekiDist < minDist) {
		target = targetTeki;
		action = PikiAI::ACT_Attack;
	}

	*outTarget = target;
	return action;
}

int Piki::graspSituation_Fast(Game::Creature** outTarget)
{
	if (moviePlayer && moviePlayer->mDemoState != 0) {
		*outTarget = nullptr;
		if (!isZikatu() || playData->isDemoFlag(DEMO_Reunite_Captains)) {
			return PikiAI::ACT_NULL;
		}
	}
	bool waterCheck;
	Creature* target = nullptr;
	f32 minDist      = 400.0f;
	int action       = PikiAI::ACT_NULL;
	bool isActionSet = false;
	waterCheck       = true;
	if (getKind() != Blue && getKind() != Bulbmin) {
		waterCheck = false;
	}

	Sys::Sphere sphere(mPosition3, 300.0f);
	CellIteratorArg iterArg(sphere);
	iterArg._1C = true;

	CellIterator iter(iterArg);
	CI_LOOP(iter)
	{
		Creature* creature = static_cast<Creature*>(*iter);
		switch (creature->mObjectTypeID) {
		case OBJTYPE_Piki: { // can we battle? can we rescue?
			Piki* otherPiki = static_cast<Piki*>(creature);

			// check if we can fight the piki.
			if (gameSystem->isVersusMode()) {          // need to be in vs mode to fight pikis
				if (creature->isAlive() &&             // is it alive
				    otherPiki->canVsBattle() &&        // is it battle-able
				    !otherPiki->getVsBattlePiki() &&   // is it not already fighting something else
				    otherPiki->getKind() != getKind()) // is it on the other team
				{
					f32 sphereDist = otherPiki->calcSphereDistance(this);
					if (sphereDist < PIKI_BATTLE_RANGE &&                          // needs to be close enough to target
					    ((isActionSet && (sphereDist < minDist)) || !isActionSet)) // have an action but piki is closer, OR no action yet
					{
						minDist     = sphereDist;
						target      = otherPiki;
						action      = PikiAI::ACT_Battle;
						isActionSet = true;
					}
				}

				break;
			}

			// if (getKind() == Blue &&                        // can we rescue
			//     creature->isAlive() &&                      // is piki alive
			//     otherPiki->getStateID() == PIKISTATE_Drown) // is piki drowning
			// {
			// 	f32 sphereDist = otherPiki->calcSphereDistance(this);
			// 	if (sphereDist < minDist
			// 	    && sphereDist < PIKI_RESCUE_RANGE) { // are we closer to this than other targets, and are we within range
			// 		minDist = sphereDist;
			// 		target  = otherPiki;
			// 		action  = PikiAI::ACT_Rescue;
			// 	}
			// }
		} break;

		case OBJTYPE_Pellet: { // can we pick up the pellet?
			Pellet* pellet   = static_cast<Pellet*>(creature);
			bool isGrabbable = true;
			if (pellet->getKind() == 4 && gameSystem->isStoryMode()) {
				int configIdx = pellet->getConfigIndex();
				if (!playData->isFindItemDemoFlag(configIdx)) {
					isGrabbable = false;
				}
			}

			if (creature->isAlive() && !creature->mCaptureMatrix && pellet->getFreeStickSlot() != -1 && !pellet->discoverDisabled()
			    && (waterCheck || !waterCheck && !creature->inWater())) {
				if (isGrabbable && !isZikatu() && (!gameSystem->isVersusMode() || canCarryBedama(this, pellet))) {
					f32 sphereDist = creature->calcSphereDistance(this);
					if (!isActionSet && sphereDist < minDist && sphereDist < *pikiMgr->mParms->mPikiParms.mPelletSearchRange()) {
						minDist = sphereDist;
						target  = creature;
						action  = PikiAI::ACT_Transport;
					}
				}
			}
		} break;

		case OBJTYPE_Gate: { // can we attack the gate?
			if (!gasInvicible()) {
				ItemGate* gate    = static_cast<ItemGate*>(creature);
				bool isAttackable = true;
				if (gameSystem->isStoryMode() && !playData->hasMetPikmin(White) && getKind() != White) {
					Vector3f gatePos = gate->getPosition();
					Sys::Sphere gateSearchSphere(gatePos, GATE_GAS_PIPE_RANGE);
					CellIteratorArg gateIterArg(gateSearchSphere);
					CellIterator gateIter(gateIterArg);
					CI_LOOP(gateIter)
					{
						Creature* target = static_cast<Creature*>(*gateIter);
						if (target->isTeki() && target->isAlive()
						    && static_cast<EnemyBase*>(target)->getEnemyTypeID() == EnemyTypeID::EnemyID_GasHiba) {
							isAttackable = false;
							break;
						}
					}
				}

				if (gate->isAlive() && isAttackable) {
					f32 workDist = gate->getWorkDistance(mBoundingSphere);
					if (!isActionSet && workDist < minDist && workDist < *pikiMgr->mParms->mPikiParms.mNectarRockRangeDuplicate()) {
						minDist = workDist;
						target  = gate;
						action  = PikiAI::ACT_BreakGate;
					}
				}
			}
		} break;

		case OBJTYPE_Bridge: { // can we attack the bridge?
			if (!gasInvicible()) {
				ItemBridge::Item* bridge = static_cast<ItemBridge::Item*>(creature);
				if (bridge->isAlive() && bridge->workable(mPosition3)) {
					f32 workDist = bridge->getWorkDistance(mBoundingSphere);
					if (workDist < minDist && workDist < *pikiMgr->mParms->mPikiParms.mBridgeSearchRange()) {
						minDist = workDist;
						target  = bridge;
						action  = PikiAI::ACT_Bridge;
					}
				}
			}
		} break;

		case OBJTYPE_Rock: { // can we attack the mold?
			ItemRock::Item* mold = static_cast<ItemRock::Item*>(creature);
			if (mold->isAlive()) {
				f32 workDist = mold->getWorkDistance(mBoundingSphere);
				if (workDist < minDist && workDist < *pikiMgr->mParms->mPikiParms.mNectarRockSearchRange()) {
					minDist = workDist;
					target  = mold;
					action  = PikiAI::ACT_BreakRock;
				}
			}
		} break;

		case OBJTYPE_BigFountain: { // can we dig up the geyser?
			ItemBigFountain::Item* geyser = static_cast<ItemBigFountain::Item*>(creature);
			if (geyser->isAlive()) {
				f32 workDist = geyser->getWorkDistance(mBoundingSphere);
				if (workDist < minDist && workDist < *pikiMgr->mParms->mPikiParms.mNectarRockSearchRange()) {
					minDist = workDist;
					target  = geyser;
					action  = PikiAI::ACT_BreakRock;
				}
			}
		} break;

		case OBJTYPE_Barrel: { // can we attack the clog?
			ItemBarrel::Item* clog = static_cast<ItemBarrel::Item*>(creature);
			if (clog->isAlive() && (waterCheck || (!waterCheck && !clog->inWater()))) {
				f32 workDist = clog->getWorkDistance(mBoundingSphere);
				if (workDist < minDist && workDist < *pikiMgr->mParms->mPikiParms.mClogSearchRange()) {
					minDist = workDist;
					target  = clog;
					action  = PikiAI::ACT_BreakRock;
				}
			}
		} break;

		case OBJTYPE_Treasure: { // can we dig up treasure?
			ItemTreasure::Item* treasure = static_cast<ItemTreasure::Item*>(creature);
			if (!isActionSet && treasure->isAlive() && canAttackBedamaIdle(this, treasure)) {
				f32 workDist = treasure->getWorkDistance(mBoundingSphere);
				if (workDist < minDist && workDist < *pikiMgr->mParms->mPikiParms.mBuriedTreasureSearchRange()) {
					minDist = workDist;
					target  = treasure;
					action  = PikiAI::ACT_BreakRock;
				}
			}
		} break;

		case OBJTYPE_Ujamushi:
		case OBJTYPE_Weed: { // can we pluck the grass/attack the ujadani?
			if (creature->isAlive() && creature->getFlockMgr() && creature->getFlockMgr()->isAttackable()) {
				f32 radius        = creature->getFlockMgr()->mActivationSpherePosition.mRadius;
				Vector3f flockPos = creature->getFlockMgr()->mActivationSpherePosition.mPosition;
				f32 dist          = flockPos.distance(mPosition3);
				if (dist < radius) {
					minDist = dist;
					target  = creature;
					action  = PikiAI::ACT_Weed;
				}
			}
		} break;

		case OBJTYPE_Plant: { // can we harvest berries?
			ItemPlant::Plant* plant = static_cast<ItemPlant::Plant*>(creature);
			if (plant->isAlive()) {
				Vector3f plantPos = plant->getPosition();
				f32 dist          = plantPos.distance(mBoundingSphere.mPosition);
				if (dist < minDist && dist < *pikiMgr->mParms->mPikiParms.mNectarRockSearchRange()) {
					minDist = dist;
					target  = plant;
					action  = PikiAI::ACT_Crop;
				}
			}
		} break;

		case OBJTYPE_Navi: { // can we attack the navi?
			if (gameSystem->isVersusMode()) {
				Navi* navi = static_cast<Navi*>(creature);
				if (navi->isAlive() && (int)navi->mNaviIndex == getKind()) {
					f32 sphereDist = navi->calcSphereDistance(this);
					Sys::Sphere naviSphere;
					navi->getBoundingSphere(naviSphere);
					f32 heightCheck = FABS(naviSphere.mPosition.y - mPosition3.y) - (naviSphere.mRadius + mBoundingSphere.mRadius);
					if (sphereDist < minDist && sphereDist < *pikiMgr->mParms->mPikiParms.mEnemySearchRange() && heightCheck < 30.0f) {
						minDist = sphereDist;
						target  = navi;
						action  = PikiAI::ACT_Attack;
					}
				}
			}
		} break;

		case OBJTYPE_Teki: { // can we attack the enemy?
			EnemyBase* enemy = static_cast<EnemyBase*>(creature);
			if (enemy->isAlive() && !enemy->isFlying() && enemy->isLivingThing() && (waterCheck || (!waterCheck && !enemy->inWater()))) {
				f32 sphereDist = enemy->calcSphereDistance(this);
				Sys::Sphere enemySphere;
				enemy->getBoundingSphere(enemySphere);
				f32 heightCheck = FABS(enemySphere.mPosition.y - mPosition3.y) - (enemySphere.mRadius + mBoundingSphere.mRadius);
				if (sphereDist < minDist && sphereDist < *pikiMgr->mParms->mPikiParms.mEnemySearchRange() && heightCheck < 30.0f) {
					minDist = sphereDist;
					target  = enemy;
					action  = PikiAI::ACT_Attack;
				}
			}
		} break;
		}
	}

	*outTarget = target;
	return action;
}


/**
 * @note Address: 0x801B2DB0
 * @note Size: 0x7D4
 */
bool Piki::invokeAI(Game::CollEvent* event, bool check)
{
	Creature* creature = event->mCollidingCreature;
	bool formCheck     = true;
	if (getCurrActionID() == PikiAI::ACT_Formation
	    && static_cast<PikiAI::ActFormation*>(getCurrAction())->mSortState != FORMATION_SORT_FORMED) {
		formCheck = false;
	}

	if (formCheck && creature->isAlive() && creature->getFlockMgr() && creature->getFlockMgr()->isAttackable()) {
		PikiAI::ActWeedArg weedArg;
		weedArg.mWeed = static_cast<ItemWeed::Item*>(creature);
		return mBrain->start(PikiAI::ACT_Weed, &weedArg);
	}

	switch (creature->mObjectTypeID) {
	case OBJTYPE_Navi: {
		if (check && gameSystem->isVersusMode() && creature->isAlive() && static_cast<Navi*>(creature)->mNaviIndex == mPikiKind) {
			PikiAI::ActAttackArg attackArg;
			attackArg.mCreature = creature;
			attackArg.mCollPart = nullptr;

			return mBrain->start(PikiAI::ACT_Attack, &attackArg);
		}
	} break;

	case OBJTYPE_Honey: {
		if (getHappa() != Flower && static_cast<ItemHoney::Item*>(creature)->mHoneyType == HONEY_Y
		    && static_cast<ItemHoney::Item*>(creature)->absorbable()) {
			AbsorbStateArg absorbArg;
			absorbArg.mCreature = creature;
			mFsm->transit(this, PIKISTATE_Absorb, &absorbArg);
			return true;
		}
	} break;

	case OBJTYPE_Piki: {
		if (gameSystem->isVersusMode() && creature->isAlive() && static_cast<Piki*>(creature)->canVsBattle()
		    && !static_cast<Piki*>(creature)->getVsBattlePiki() && static_cast<Piki*>(creature)->getKind() != getKind()) {
			PikiAI::ActBattleArg battleArg(static_cast<Piki*>(creature));
			return mBrain->start(PikiAI::ACT_Battle, &battleArg);
		}
	} break;

	case OBJTYPE_Pellet: {
		Pellet* pellet = static_cast<Pellet*>(creature);
		if (check && pellet->isAlive() && !isZikatu()) {
			if (!gameSystem->isVersusMode() || canCarryBedama(this, pellet)) {
				if (pellet->getTotalPikmins() < pellet->getPelletConfigMax() && !pellet->discoverDisabled()) {
					bool upgradeReady = true;
					if (pellet->getKind() == 4 && gameSystem->isStoryMode()) {
						int configIdx = pellet->getConfigIndex();
						if (!playData->isFindItemDemoFlag(configIdx)) {
							upgradeReady = false;
						}
					}

					if (upgradeReady) {
						PikiAI::ActTransportArg transportArg;
						setActTransportArg(transportArg);
						transportArg.mPellet = pellet;

						return mBrain->start(PikiAI::ACT_Transport, &transportArg);
					}
				}
			}
		}
	} break;

	case OBJTYPE_Teki: {
		if (check && creature->isLivingThing() && creature->isAlive()) {
			CollPart* part = event->mCollisionObj;
			PikiAI::ActAttackArg attackArg;
			attackArg.mCreature = creature;
			attackArg.mCollPart = part;
			return mBrain->start(PikiAI::ACT_Attack, &attackArg);
		}

		if (static_cast<EnemyBase*>(creature)->getEnemyTypeID() == EnemyTypeID::EnemyID_Bomb) {
			creature->isAlive(); // hm.
		}
	} break;

	case OBJTYPE_Gate: {
		ItemGate* gate = static_cast<ItemGate*>(creature);
		if (check) {
			bool isAttackable = true;
			if (gameSystem->isStoryMode() && !playData->hasMetPikmin(White) && getKind() != White) {
				Vector3f gatePos = gate->getPosition();
				Sys::Sphere searchSphere(gatePos, GATE_GAS_PIPE_RANGE);
				CellIteratorArg iterArg(searchSphere);
				CellIterator iter(iterArg);
				CI_LOOP(iter)
				{
					Creature* target = static_cast<Creature*>(*iter);
					if (target->isTeki() && target->isAlive()
					    && static_cast<EnemyBase*>(target)->getEnemyTypeID() == EnemyTypeID::EnemyID_GasHiba) {
						isAttackable = false;
						break;
					}
				}
			}

			if (isAttackable) {
				PikiAI::ActBreakGateArg breakGateArg;
				breakGateArg.mGate = gate;

				return mBrain->start(PikiAI::ACT_BreakGate, &breakGateArg);
			}
		}
	} break;

	case OBJTYPE_Rock:
	case OBJTYPE_Barrel:
	case OBJTYPE_Treasure: {
		if (check) {
			if (creature->mObjectTypeID == OBJTYPE_Treasure && !canAttackBedama(this, static_cast<ItemTreasure::Item*>(creature))) {
				return false;
			}

			PikiAI::ActBreakRockArg breakRockArg;
			breakRockArg.mRock = static_cast<BaseItem*>(creature);
			return mBrain->start(PikiAI::ACT_BreakRock, &breakRockArg);
		}

		if (creature->mObjectTypeID == OBJTYPE_Treasure && getKind() == White && formCheck) {
			PikiAI::ActBreakRockArg breakRockArg;
			breakRockArg.mRock = static_cast<BaseItem*>(creature);
			return mBrain->start(PikiAI::ACT_BreakRock, &breakRockArg);
		}
	} break;

	case OBJTYPE_BigFountain: {
		if (check && creature->isAlive()) {
			PikiAI::ActBreakRockArg breakRockArg;
			breakRockArg.mRock = static_cast<BaseItem*>(creature);
			return mBrain->start(PikiAI::ACT_BreakRock, &breakRockArg);
		}
	} break;

	case OBJTYPE_Plant: {
		if (check) {
			PikiAI::ActCropArg cropArg;
			cropArg.mCreature = creature;
			return mBrain->start(PikiAI::ACT_Crop, &cropArg);
		}
	} break;

	case OBJTYPE_Bridge: {
		ItemBridge::Item* bridge = static_cast<ItemBridge::Item*>(creature);
		if (bridge->isAlive() && bridge->workable(mPosition3)) {
			PikiAI::ActBreakRockArg bridgeArg;
			bridgeArg.mRock = bridge;
			return mBrain->start(PikiAI::ACT_BreakRock, &bridgeArg);
		}
	} break;
	}

	return false;
}


} // namespace Game
