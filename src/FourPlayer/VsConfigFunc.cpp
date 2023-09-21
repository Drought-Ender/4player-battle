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

namespace Game {
    float Pellet::buryBedamaVs() {
        if (mPelletFlag == FLAG_VS_BEDAMA_YELLOW) {
            return VsOtakaraName::cBedamaYellowDepth;
        }
        if (mPelletFlag == FLAG_VS_BEDAMA_RED || mPelletFlag == FLAG_VS_BEDAMA_BLUE || mPelletFlag == FLAG_VS_BEDAMA_WHITE || mPelletFlag == FLAG_VS_BEDAMA_PURPLE) {
            return VsOtakaraName::cBedamaRedBlueDepth;
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
}


// canAutopluck__Fv
bool canAutopluck() {
    return gConfig[AUTOPLUCK] == ConfigEnums::AUTOPLUCK_ON;
}

