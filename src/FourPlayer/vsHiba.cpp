#include "Game/Entities/ElecHiba.h"

namespace Game
{

namespace ElecHiba
{

s16& Obj::getVsHibaHighest() {
    s16& max1 = MAX(mAttrAttackCount[0], mAttrAttackCount[1]);
    s16& max2 = MAX(max1, mAttrAttackCount[2]);
    return MAX(max2, mAttrAttackCount[3]);
}

EVersusHibaType Obj::getVsHibaHighestColor() {
    return (EVersusHibaType)(((int)&getVsHibaHighest() - (int)mAttrAttackCount) / sizeof(s16) + 1);
}

bool Obj::isVsHibaDraw() {
    s16& highest = getVsHibaHighest();
    for (int i = 0; i < 4; i++) {
        if (highest == mAttrAttackCount[i] && &highest != &mAttrAttackCount[i]) {
            return true;
        }
    }
    return false;
}

bool Obj::isVsHibaDraw(EVersusHibaType color) {
    s16& highest = mAttrAttackCount[color - 1];
    for (int i = 0; i < 4; i++) {
        if (highest == mAttrAttackCount[i] && &highest != &mAttrAttackCount[i]) {
            return true;
        }
    }
    return false;
}

bool Obj::isVsHibaWinning(EVersusHibaType color) {
    s16& highest = mAttrAttackCount[color - 1];
    for (int i = 0; i < 4; i++) {
        if (highest < mAttrAttackCount[i] && &highest != &mAttrAttackCount[i]) {
            return false;
        }
    }
    return true;
}

void Obj::setVersusHibaType()
{
	if (!isVsHibaDraw()) {
		mVersusHibaType = getVsHibaHighestColor();
        OSReport("mVersusHibaType %i\n", mVersusHibaType);
	}
}

void Obj::resetAttrHitCount()
{
	mAttrAttackCount[0] = 0;
	mAttrAttackCount[1] = 0;
    mAttrAttackCount[2] = 0;
    mAttrAttackCount[3] = 0;
}

void Obj::addAttrAttackCount(Piki* piki)
{
	int type = piki->mPikiKind;
	if (type == Red) {
		mAttrAttackCount[0]++;
	} else if (type == Blue) {
		mAttrAttackCount[1]++;
	} else if (type == White) {
        mAttrAttackCount[2]++;
    } else if (type == Purple) {
        mAttrAttackCount[3]++;
    }
	if (getStateID() == ELECHIBA_Attack) {
		mWaitTimer = 0.0f;
	}
}

bool Obj::isWaitFinish()
{
	if ((mWaitTimer > C_PROPERPARMS.mActiveTime.mValue) && (mVersusHibaType || !isVsHibaDraw())) {
		return true;
	}
	return false;
}

bool Obj::isAttackFinish()
{
	if (mWaitTimer > C_PROPERPARMS.mActiveTime.mValue || !isVsHibaWinning(mVersusHibaType)) {
		return true;
	}
	return false;
}

void Obj::startDisChargeEffect()
{
	efx::TDenkiHibaMgr* efxMgr = mEfxDenkiHibaMgr;
	if (efxMgr) {
        efxMgr->createHiba(mVersusHibaType);
	}
}

void Obj::doDenkiEffect(Creature* parent, f32 force, Vector3f direction, Creature* afflicted) {
    Vector3f launch = direction;
    f32 dmg = force;
    Creature* owner = parent;
    Creature* victim = afflicted;
    JUT_ASSERT(afflicted, "no elechiba target!\n");
    P2ASSERT(victim);
    P2ASSERT(owner);

    if (mVersusHibaType == VHT_Neutral) {
        InteractDenki denki (owner, dmg, &launch);
        victim->stimulate(denki);
    }
    else if (mVersusHibaType == VHT_Red) {
        InteractFire fire (owner, dmg);
        victim->stimulate(fire);
    }
    else if (mVersusHibaType == VHT_Blue) {
        InteractBubble water (owner, dmg);
        victim->stimulate(water);
    }
    else if (mVersusHibaType == VHT_White) {
        InteractGas gas (owner, dmg);
        victim->stimulate(gas);
    }
    else if (mVersusHibaType == VHT_Purple) {
        InteractSpore spore (owner, dmg);
        victim->stimulate(spore);
    }

}




} // namespace ElecHiba


} // namespace Game
