#include "Game/pelletMgr.h"
#include "VsOtakaraName.h"
#include "Game/VsGameSection.h"
#include "Game/gamePlayData.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Entities/ItemTreasure.h"
#include "Game/Stickers.h"
#include "Iterator.h"
#include "Game/Piki.h"
#include "Game/PikiState.h"
#include "PikiAI.h"
#include "Game/NaviState.h"
#include "VsOptions.h"
#include "Game/CPlate.h"

namespace Game {
    float Pellet::buryBedamaVs() {
        if (mPelletFlag == FLAG_VS_BEDAMA_YELLOW) {
            return VsOtakaraName::cBedamaYellowDepth;
        }
        if (mPelletFlag == FLAG_VS_BEDAMA_RED || mPelletFlag == FLAG_VS_BEDAMA_BLUE || mPelletFlag == FLAG_VS_BEDAMA_WHITE || mPelletFlag == FLAG_VS_BEDAMA_PURPLE) {
            return VsOtakaraName::cBedamaRedBlueDepth;
        }
        if (mPelletFlag == FLAG_VS_BEDAMA_MINI) {
            return VsOtakaraName::cBedamaMiniDepth;
        }
        return 0.0f;
    }

    int Pellet::getBedamaPikiColor() {
        switch (mPelletFlag)
        {
        case FLAG_VS_BEDAMA_RED:
            return Red;
        case FLAG_VS_BEDAMA_BLUE:
            return Blue;
        case FLAG_VS_BEDAMA_WHITE:
            return White;
        case FLAG_VS_BEDAMA_PURPLE:
            return Purple;
        default:
            return -1;
        }
    }


   bool canSuckBedama(Creature* creature, Pellet* pellet) {
        if (!creature) {
            return false;
        }
        Onyon* onyon = static_cast<Onyon*>(creature);
        return pellet->getBedamaPikiColor() != onyon->mOnyonType;
    }

    bool canAttackBedama(Piki* piki, Game::ItemTreasure::Item* treasure) {
        // int pelletColor = 1 - (treasure->m_pellet->m_pelletFlag - Pellet::FLAG_VS_BEDAMA_RED);
        // return pelletColor != piki->m_pikiKind;
        return gConfig[MARBLE_CARRY] || treasure->mPellet->getBedamaPikiColor() != piki->mPikiKind;
    } 

    bool canAttackBedamaIdle(Piki* piki, Game::ItemTreasure::Item* treasure) {
        return treasure->mPellet->getBedamaPikiColor() != piki->mPikiKind;
    }
    // canCarryBedama__4GameFPQ24Game4PikiPQ24Game6Pellet
    bool canCarryBedama(Piki* piki, Pellet* pellet) {
        if (!gameSystem->isVersusMode() || gConfig[MARBLE_CARRY]) {
            return true;
        }
        return piki->mPikiKind != pellet->getBedamaPikiColor();
        
    }

    void pikiFight(Game::Piki* attacker, Game::Piki* defender) {
        Game::DyingStateArg dargs;
        dargs.mAnimIdx = -1;
        dargs._04 = true;

        if (!defender->doped()) {
            defender->mFsm->transit(defender, Game::PIKISTATE_Dying, &dargs);
        }
        else {
            defender->clearDope();
        }

        if (!attacker->doped()) {
            attacker->mFsm->transit(attacker, Game::PIKISTATE_Dying, &dargs);
        }
        else {
            attacker->clearDope();
        }
        
    }

    // pikiFightEndDope__4GameFPQ24Game4Piki
    void pikiFightEndDope(Piki* attacker) {
        if (!gTournamentMode && attacker->doped() && gConfig[SPICY_TYPE] == ConfigEnums::SPICY_NERF) {
            attacker->clearDope();
        }
    }

    // pikiFightShouldKillTarget__4GameFPQ24Game4PikiPQ24Game4Piki
    bool pikiFightShouldKillTarget(Piki* attacker, Piki* defender) {
        if (gTournamentMode) {
            pikiFight(attacker, defender);
            return false;
        }
        return true;
    }
    
    

    void autopluck(NaviWalkState* walkstate, Navi* captain)
    // performs Pikmin 3-style autopluck of pikmin seeds
    {
        if (gConfig[AUTOPLUCK] == ConfigEnums::AUTOPLUCK_ON) {
            captain->procActionButton();
        }
        
        walkstate->execAI(captain);
    }

    void Navi::applyDopes(int sprayType, Vector3f& sprayOrigin)
    {
        if (sprayType == SPRAY_TYPE_BITTER) {
            Sys::Sphere searchCirc(sprayOrigin, 140.0f);
            Delegate1<Navi, CellObject*> funcCallback(this, applyDopeSmoke);

            cellMgr->mapSearch(searchCirc, &funcCallback);
            return;
        }

        if (ConfigEnums::isGlobalSpicy()) {
            ConfigEnums::SpicyGlobal(this);
            return;
        }

        Iterator<Creature> cellIt(mCPlateMgr);
        Creature* sprayTarget = nullptr;
        CI_LOOP(cellIt)
        {
            Creature* got = *cellIt;
            if (got->isPiki()) {
                InteractDope dope(this, sprayType);
                if (got->stimulate(dope) && sprayTarget == nullptr) {
                    sprayTarget = got;
                }
            }
        }
    }
}


// canAutopluck__Fv
bool canAutopluck() {
    return gConfig[AUTOPLUCK] == ConfigEnums::AUTOPLUCK_ON;
}



namespace ConfigEnums
{
    void SpicyGlobal(Game::Navi* navi) {
        int pikiKind = navi->getVsPikiColor();
        Iterator<Game::Piki> iPiki = Game::pikiMgr;
        CI_LOOP(iPiki) {
            Game::Piki* piki = *iPiki;
            if (piki->isAlive() && piki->mPikiKind == pikiKind) {
                bool tried = piki->startDope(piki->doped());
                if (!tried) {
                    piki->extendDopeTime();
                }
            }
        } 
    }
    
} // namespace ConfigEnums

namespace Game
{

bool canPickup(Navi* user, Creature* obj) {
    if (gConfig[CARRY_MISC] == ConfigEnums::MISCCARRY_ALL) {
        return true;
    }

    if (obj->isPellet()) {
        Pellet* pelt = static_cast<Pellet*>(obj);
        if (pelt->mPelletFlag == Pellet::FLAG_VS_CHERRY && gConfig[CARRY_MISC] == ConfigEnums::MISCCARRY_CHERRY) {
            return true;
        }
        if (pelt->mMinCarriers < 5 && gConfig[CARRY_MISC] == ConfigEnums::MISCCARRY_LIGHT && pelt->mPelletFlag <= Pellet::FLAG_VS_CHERRY) {
            return true;
        }
    }

    if (obj->isTeki()) {

        EnemyBase* teki = static_cast<EnemyBase*>(obj);

        if (teki->getEnemyTypeID() == EnemyTypeID::EnemyID_Bomb) {
            return gConfig[CARRY_BOMB] == ConfigEnums::BOMBCARRY_BOMBS || gConfig[CARRY_BOMB] == ConfigEnums::BOMBCARRY_BOTH;
        }
        if (teki->getEnemyTypeID() == EnemyTypeID::EnemyID_Egg) {
            return gConfig[CARRY_BOMB] == ConfigEnums::BOMBCARRY_EGGS || gConfig[CARRY_BOMB] == ConfigEnums::BOMBCARRY_BOMBS;
        }

        if (gConfig[CARRY_BLOWHOG] == ConfigEnums::BLOWHOGCARRY_ON) {
            switch (teki->getEnemyTypeID())
            {
            case EnemyTypeID::EnemyID_Tank:
                if (user->onTeam(Red)) {
                    return true;
                }
                break;
            case EnemyTypeID::EnemyID_Wtank:
                if (user->onTeam(Blue)) {
                    return true;
                }
                break;
            case EnemyTypeID::EnemyID_Gtank:
                if (user->onTeam(White)) {
                    return true;
                }
                break;
            case EnemyTypeID::EnemyID_Mtank:
                if (user->onTeam(Purple)) {
                    return true;
                }
                break;
            }
        }

        if (gConfig[CARRY_MISC] == ConfigEnums::MISCCARRY_LIGHT) {
            switch (teki->getEnemyTypeID())
            {
            case EnemyTypeID::EnemyID_Kochappy:
            case EnemyTypeID::EnemyID_BlueKochappy:
            case EnemyTypeID::EnemyID_YellowKochappy:
            case EnemyTypeID::EnemyID_KumaKochappy:
            case EnemyTypeID::EnemyID_Catfish:
            case EnemyTypeID::EnemyID_ElecBug:
            case EnemyTypeID::EnemyID_Fuefuki:
            case EnemyTypeID::EnemyID_PanModoki:
            case EnemyTypeID::EnemyID_Sarai:
            case EnemyTypeID::EnemyID_BombSarai:
            case EnemyTypeID::EnemyID_Demon:
            case EnemyTypeID::EnemyID_FireOtakara:
            case EnemyTypeID::EnemyID_WaterOtakara:
            case EnemyTypeID::EnemyID_GasOtakara:
            case EnemyTypeID::EnemyID_SporeOtakara:
            case EnemyTypeID::EnemyID_ElecOtakara:
            case EnemyTypeID::EnemyID_Fart:
            case EnemyTypeID::EnemyID_Kogane:
            case EnemyTypeID::EnemyID_Wealthy:
            case EnemyTypeID::EnemyID_UjiA:
            case EnemyTypeID::EnemyID_UjiB:
            case EnemyTypeID::EnemyID_Tobi:
            case EnemyTypeID::EnemyID_TechnoBug:
            case EnemyTypeID::EnemyID_Jigumo:
            case EnemyTypeID::EnemyID_Qurione:
            case EnemyTypeID::EnemyID_TamagoMushi:
            case EnemyTypeID::EnemyID_Imomushi:
            case EnemyTypeID::EnemyID_Sokkuri:
            case EnemyTypeID::EnemyID_ShijimiChou:
            case EnemyTypeID::EnemyID_Tadpole:
                return true;
            }
        }

    }
    return false;
}

void NaviWalkState::collisionCallback(Navi* navi, CollEvent& event)
{
	Creature* collider = event.mCollidingCreature;
	if (moviePlayer->mDemoState == 0 && collider->mObjectTypeID == OBJTYPE_Honey) {
		ItemHoney::Item* drop = static_cast<ItemHoney::Item*>(collider);
		if (drop->mHoneyType != HONEY_Y && drop->absorbable()) {
			NaviAbsorbArg absorbArg(drop);
			navi->mFsm->transit(navi, NSID_Absorb, &absorbArg);
		}
	}

	if (moviePlayer->mDemoState == 0 && gameSystem->isVersusMode() && canPickup(navi, collider) && !collider->mCaptureMatrix && collider->isAlive()
	    && navi->mController1) {

		f32 x = -navi->mController1->getMainStickX(); // idk why this is negative lol.
		f32 y = navi->mController1->getMainStickY();
		if (x * x + y * y > 0.5f) {
			if (mCollisionTimer < 100) {
				mCollisionTimer += 3;
			}

			if (mCollisionTimer > 60) {
				NaviCarryBombArg bombArg(collider);
				transit(navi, NSID_CarryBomb, &bombArg);
			}
		}
	}
}


} // namespace Game


