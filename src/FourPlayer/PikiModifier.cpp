#include "Game/Piki.h"
#include "Game/NaviParms.h"
#include "Game/PikiMgr.h"
#include "Game/GameSystem.h"
#include "Game/Navi.h"
#include "Game/PikiState.h"

namespace Game {

f32 Piki::getAttackDamage()
{
	if (doped()) {
		return pikiMgr->mParms->mPikiParms.mDopeAttackDamage.mValue;
	}

	if (gameSystem && gameSystem->mMode == GSM_VERSUS_MODE) {
		return pikiMgr->mParms->mPikiParms.mRedAttackDamage.mValue;
	}

	switch ((int)mPikiKind) {
	case Red:
		return pikiMgr->mParms->mPikiParms.mRedAttackDamage.mValue;
	case Blue:
		return pikiMgr->mParms->mPikiParms.mBlueAttackDamage.mValue;
	case Yellow:
		return pikiMgr->mParms->mPikiParms.mYellowAttackDamage.mValue;
	case Purple:
		return pikiMgr->mParms->mPikiParms.mPurpleAttackDamage.mValue;
	case White:
		return pikiMgr->mParms->mPikiParms.mWhiteAttackDamage.mValue;
	}
	// Used for bulbmin + carrots
	return pikiMgr->mParms->mPikiParms.mBlueAttackDamage.mValue;
}

/*
 * --INFO--
 * Address:	801495E4
 * Size:	0000C0
 */
f32 Piki::getThrowHeight()
{
	if (!mNavi) {
		return 0.0f;
	}

	P2ASSERTLINE(1403, mNavi);
    if (!gameSystem->isVersusMode()) {
        switch ((int)mPikiKind) {
        case Yellow:
            return static_cast<NaviParms*>(mNavi->mParms)->mNaviParms.mP054.mValue;
        case Purple:
            return static_cast<NaviParms*>(mNavi->mParms)->mNaviParms.mQ000.mValue;
        case White:
            return static_cast<NaviParms*>(mNavi->mParms)->mNaviParms.mQ001.mValue;
        }
    }

	return static_cast<NaviParms*>(mNavi->mParms)->mNaviParms.mP025.mValue;
}

/*
 * --INFO--
 * Address:	801496A4
 * Size:	0000C4
 */
f32 Piki::getPelletCarryPower()
{
	f32 carryPower = 1.0f;

    if (!gameSystem->isVersusMode()) {

        switch ((int)mPikiKind) {
        case White:
            carryPower = pikiMgr->mParms->mPikiParms.mWhiteCarryPower.mValue;
            break;
        case Purple:
            carryPower = pikiMgr->mParms->mPikiParms.mPurpleCarryPower.mValue;
            break;
        }
    }

	if (doped() || (int)mHappaKind == Flower) {
		carryPower += pikiMgr->mParms->mPikiParms.mFlowerCarrySpeedBonus.mValue;
	} else if ((int)mHappaKind == Bud) {
		carryPower += pikiMgr->mParms->mPikiParms.mBudCarrySpeedBonus.mValue;
	}

	return carryPower;
}

f32 Piki::getBaseScale()
{
	f32 scale = 1.0f;
	return 1.0f;
    if (!gameSystem->isVersusMode()) {
        if (mPikiKind == Purple) {
            scale = 1.2f;
        } else if (mPikiKind == White) {
            scale = 0.8f;
        }
    }

	return scale;
}

f32 Piki::getSpeed(f32 multiplier)
{
	if (doped()) {
		return pikiMgr->mParms->mPikiParms.mDopeRunSpeed.mValue;
	}

	f32 baseSpeed = scaleValue(1.0f, pikiMgr->mParms->mPikiParms.mRunSpeed.mValue);

	if (mHappaKind == Flower) {
		baseSpeed = pikiMgr->mParms->mPikiParms.mFlowerRunSpeed.mValue;
	} else if (mHappaKind == Bud) {
		baseSpeed = pikiMgr->mParms->mPikiParms.mBudRunSpeed.mValue;
	}

	int pikiType = mPikiKind;
	f32 drag     = scaleValue(1.0f, pikiMgr->mParms->mPikiParms.mWalkSpeed.mValue);
	f32 speed    = multiplier * (baseSpeed - drag) + drag;

    if (!gameSystem->isVersusMode()) {
        if (pikiType == White) {
            speed *= pikiMgr->mParms->mPikiParms.mWhiteRunSpeedMultiplier.mValue;
        } else if (pikiType == Purple) {
            speed *= pikiMgr->mParms->mPikiParms.mPurpleRunSpeedMultiplier.mValue;
        }
    }

	return speed;
}

void Piki::setSpeed(f32 multiplier, Vector3f& vec)
{
	if (multiplier < 0.0f) {
		mVelocity = vec * -getSpeed(-multiplier);
	} else {
		mVelocity = vec * getSpeed(multiplier);
	}
}


f32 Piki::getSpeed(f32 multiplier, f32 max)
{
	f32 speed = getSpeed(multiplier);
	if (speed * sys->mDeltaTime < max) {
		return speed;
	} else {
		return max / sys->mDeltaTime;
	}
}

void Piki::setSpeed(f32 multiplier, Vector3f& vec, f32 max)
{
	if (multiplier < 0.0f) {
		mVelocity = vec * -getSpeed(-multiplier, max);
	} else {
		mVelocity = vec * getSpeed(multiplier, max);
	}
}

int PikiMgr::getColorTransportScale(int color)
{
	P2ASSERTBOUNDSLINE(857, 0, color, PikiColorCount);
	if (color == Purple && !gameSystem->isVersusMode()) {
		return 10;
	}

	return 1;
}

int Piki::getDownfloorMass()
{
	if (getStateID() == PIKISTATE_Hanged) {
		return 0;
	}

	return ((int)mPikiKind == Purple && !gameSystem->isVersusMode()) ? 10 : 1;
}

}