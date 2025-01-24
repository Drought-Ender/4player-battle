#include "Game/Piki.h"
#include "Game/NaviParms.h"
#include "Game/PikiMgr.h"
#include "Game/GameSystem.h"
#include "Game/Navi.h"
#include "Game/NaviState.h"
#include "Game/PikiState.h"
#include "PSM/Navi.h"
#include "VsOptions.h"
#include "Game/BuffMgr.h"

namespace Game {

f32 Piki::getAttackDamage()
{
	P2ASSERT(this);
	if (doped()) {
		return pikiMgr->mParms->mPikiParms.mDopeAttackDamage.mValue * (sAttackPowers[gConfig[ATTACK_POWER]] / 1.5f);
	}

	if (gameSystem && gameSystem->isVersusMode()) {
		return pikiMgr->mParms->mPikiParms.mBlueAttackDamage.mValue * sAttackPowers[gConfig[ATTACK_POWER]];
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

	if (doped() || (int)mHappaKind == Flower) {
		carryPower += pikiMgr->mParms->mPikiParms.mFlowerCarrySpeedBonus.mValue;
	} else if ((int)mHappaKind == Bud) {
		carryPower += pikiMgr->mParms->mPikiParms.mBudCarrySpeedBonus.mValue;
	}

	return carryPower * sSpeeds[gConfig[CARRY_SPEED]];
}

f32 Piki::getBaseScale() { return 1.0f; }

f32 Piki::getSpeed(f32 multiplier)
{
	if (doped()) {
		return pikiMgr->mParms->mPikiParms.mDopeRunSpeed.mValue * sSpeeds[gConfig[PIKMIN_SPEED]];
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

	return speed * sSpeeds[gConfig[PIKMIN_SPEED]];
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
	return 1;
}

int Piki::getDownfloorMass()
{
	if (getStateID() == PIKISTATE_Hanged) {
		return 0;
	}

	return 1;
}

void endPluck(NaviNukuState* state, Navi* navi)
{
	if (navi && navi->mController1 && navi->mController1->isButtonDown(PAD_BUTTON_B)) {
		if (gConfig[AUTOPLUCK] == ConfigEnums::AUTOPLUCK_CANCEL) {
			navi->transit(NSID_Walk, nullptr);
			navi->mPluckingCounter = false;
		} else {
			state->mDidPressA       = false;
			state->mIsActive        = false;
			state->mIsStopAutopluck = true;
		}
	}
}

void NaviNukuState::init(Navi* navi, StateArg* stateArg)
{
	if (stateArg != nullptr) {
		mIsFollower = static_cast<NaviNukuArg*>(stateArg)->mIsFollowing;
	} else {
		mIsFollower = 0;
	}
	if (navi->mPluckingCounter != 0) {
		mAnimID = IPikiAnims::NUKU3;
	} else {
		mAnimID = IPikiAnims::NUKU;
	}

	mAnimSpeed = 30.0f;

	const PluckSpeedBuff* buff = static_cast<const PluckSpeedBuff*>(naviBuffMgr->mBuffData[navi->mNaviIndex].findBuff("PluckSpeedBuff"));
	if (buff) {
		// OSReport("pluck speed buff %f\n", buff->getSpeedBuff());
		mAnimSpeed       = 30.0f * buff->getSpeedBuff();
		navi->mAnimSpeed = mAnimSpeed;
		OSReport("Anim Speed Initial %f\n", navi->mAnimSpeed);
	}

	navi->startMotion(mAnimID, mAnimID, navi, nullptr);
	mCounter = static_cast<NaviParms*>(navi->mParms)->mNaviParms.mP042;
	navi->mSoundObj->startSound(PSSE_PL_PULLING_PIKI, 0);
	mDidPluckSE      = 0;
	mIsActive        = 0;
	mDidPressA       = 0;
	mIsStopAutopluck = false;
	_15              = 0;
	navi->mMass      = 0.0f;
}

/**
 * @note Address: 0x80181D70
 * @note Size: 0x18C
 */
void NaviNukuState::exec(Navi* navi)
{
	endPluck(this, navi);

	navi->mAnimSpeed = mAnimSpeed;

	if (moviePlayer && moviePlayer->mDemoState != 0) {
		if (mIsFollower) {
			NaviFollowArg followArg(false); // not new to party
			transit(navi, NSID_Follow, &followArg);
			return;
		}
		transit(navi, NSID_Walk, nullptr);
		return;
	}
	navi->mVelocity    = 0.0f;
	navi->mSimVelocity = 0.0f;
	if (!navi->assertMotion(mAnimID)) {
		if (mIsFollower != 0) {
			NaviFollowArg followArg(false); // not new to party
			transit(navi, NSID_Follow, &followArg);
		} else {
			transit(navi, NSID_Walk, nullptr);
		}
		navi->mPluckingCounter = 0;
	} else if (mIsFollower == 0) {
		if (mDidPressA == 0 && ((canAutopluck() && !mIsStopAutopluck) || navi->mController1->isButtonHeld(JUTGamePad::PRESS_A))) {
			mDidPressA = 1;
		}
		if (mDidPressA != 0 && !navi->mController1->isButtonHeld(JUTGamePad::PRESS_A)) {
			mIsActive = 1;
			navi->mPluckingCounter++;
		}
	}
}

void NaviNukuState::cleanup(Navi* navi)
{
	navi->mMass = 1.0f;
	navi->startThrowDisable();
}

} // namespace Game
