#include "efx/TPk.h"
#include "Game/PikiState.h"
#include "Game/PikiParms.h"
#include "Dolphin/rand.h"
#include "Game/Piki.h"
#include "PikiAI.h"
#include "System.h"

namespace efx
{

    
    void TPkEffect::createSpore_(Vector3f* pos) {
        P2ASSERT(pos);
        mOeSpore.create(pos);
    }

    void TPkEffect::killSpore_() {
        mOeSpore.kill();
    }

} // namespace efx

namespace Game
{

inline void PikiPanicState::startSound(Piki* piki)
{
	u32 panicSound = PSSE_PK_VC_PANIC;
	switch (mPanicType) {
	case PIKIPANIC_Water:
		panicSound = PSSE_PK_VC_WATER_PANIC;
		break;
	case PIKIPANIC_Fire:
		panicSound = PSSE_PK_VC_FIRED;
		break;
	case PIKIPANIC_Gas:
    case PIKIPANIC_Spore:
	case PIKIPANIC_Panic:
	case PIKIPANIC_Other:
		break;
	}

	piki->mSoundObj->startFreePikiSetSound(panicSound, PSGame::SeMgr::SETSE_PikiPanicRun, 90, 0);
}


void PikiPanicState::init(Piki* piki, StateArg* stateArg)
{
	PanicStateArg* panicArg = static_cast<PanicStateArg*>(stateArg);
	P2ASSERTLINE(1399, panicArg != nullptr);
	mPanicType = panicArg->mPanicType;
	_20        = false;
	_21        = true;
	piki->setMoveRotation(true);
	mDeathTimer = piki->getParms()->mPikiParms.mPanicMaxTime.mValue;
	mDeathTimer *= (0.1f * randFloat() + 1.0f);
	mDramaTimer = 0.1f;
	mAngle      = piki->mFaceDir;
	mSpeed      = 1.0f;
	piki->endStick();

	switch (mPanicType) {
	case PIKIPANIC_Water:
		efx::TPkEffect* effectsObjWat = piki->mEffectsObj;
		effectsObjWat->setFlag(PKEFF_Water);
		effectsObjWat->createWater_(effectsObjWat->_14);
		piki->startMotion(IPikiAnims::WALK, IPikiAnims::WALK, nullptr, nullptr);
		break;

	case PIKIPANIC_Gas:
		efx::TPkEffect* effectsObjGas = piki->mEffectsObj;
		effectsObjGas->setFlag(PKEFF_Gas);
		effectsObjGas->createChudoku_(effectsObjGas->_0C);
		piki->startMotion(IPikiAnims::GASDEAD, IPikiAnims::GASDEAD, nullptr, nullptr);
		piki->setMoveRotation(false);
		break;

	case PIKIPANIC_Fire:
		piki->startMotion(IPikiAnims::WALK, IPikiAnims::WALK, nullptr, nullptr);
		efx::TPkEffect* effectsObjFire = piki->mEffectsObj;
		effectsObjFire->setFlag(PKEFF_Fire);
		effectsObjFire->createMoe_(effectsObjFire->_0C);
		break;

	case PIKIPANIC_Panic:
	case PIKIPANIC_Other:
		_22         = 0;
		mDramaTimer = 0.3f * randFloat();
		break;
    case PIKIPANIC_Spore:
        efx::TPkEffect* effectsObj = piki->mEffectsObj;
		effectsObj->setFlag(PKEFF_Spore);
		effectsObj->createSpore_(effectsObj->_0C);
		piki->startMotion(IPikiAnims::WALK, IPikiAnims::WALK, nullptr, nullptr);
        break;
	}

	startSound(piki);
	_28 = 2.0f;
}

void PikiPanicState::cleanup(Piki* piki)
{
	piki->setMoveRotation(true);
	if (piki->mFsm->mStateID != PIKISTATE_Dying) {
		efx::TPkEffect* effectsObjFire = piki->mEffectsObj;
		effectsObjFire->killMoe_();
		if (effectsObjFire->isFlag(PKEFF_Fire)) {
			effectsObjFire->resetFlag(PKEFF_Fire);
			effectsObjFire->createMoeSmoke_(effectsObjFire->_0C);
			effectsObjFire->mMoeSmokeTimer = 60;
			efx::createSimpleChinka(*effectsObjFire->_0C);
		}

		efx::TPkEffect* effectsObjWater = piki->mEffectsObj;
		effectsObjWater->killWater_();
		if (effectsObjWater->isFlag(PKEFF_Water)) {
			effectsObjWater->resetFlag(PKEFF_Water);
			efx::createSimpleWaterOff(*effectsObjWater->_14);
		}

		efx::TPkEffect* effectsObjGas = piki->mEffectsObj;
		effectsObjGas->killChudoku_();
		if (effectsObjGas->isFlag(PKEFF_Gas)) {
			effectsObjGas->resetFlag(PKEFF_Gas);
			efx::createSimpleGedoku(*effectsObjGas->_0C);
		}

        efx::TPkEffect* effectsObjSpore = piki->mEffectsObj;
        effectsObjSpore->killSpore_();
        if (effectsObjSpore->isFlag(PKEFF_Spore)) {
            effectsObjSpore->resetFlag(PKEFF_Spore);
            pkEffectMgr->createS_SporeOff(*effectsObjSpore->_0C);
        }
	}
}

} // namespace Game

