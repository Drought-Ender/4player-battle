#include "Game/pelletMgr.h"
#include "VsOtakaraName.h"
#include "Radar.h"
#include "Game/gameStat.h"
#include "Game/Entities/PelletOtakara.h"
#include "Game/Entities/PelletItem.h"
#include "PSM/Otakara.h"

namespace Game
{
void Pellet::onInit(CreatureInitArg* initArg)
{
	mMaxCarriers = -1;
	mMinCarriers = -1;
	mWallTimer   = 0;
	_324         = 0;
	mIsInWater   = false;

	clearDiscoverDisable();

	mClaim          = 0;
	_3E0            = 0.0f;
	mBounceTriangle = nullptr;
	_311            = 0;
	mFaceDir        = 0.0f;
	mAnimSpeed      = 0.0f;
	_3C4            = 0;
	_3D0            = 0;
	mCarryInfoMgr   = nullptr;

	clearCapture();

	mCarryPower = 0.0f;

	P2ASSERTLINE(1632, initArg != nullptr);

	u16 stateType = static_cast<PelletInitArg*>(initArg)->mState;
	if (stateType == 0) {
		mPelletSM->start(this, 0, nullptr);
		mScale = Vector3f(1.0f);
	} else if (stateType == 3) {
		mPelletSM->start(this, 6, nullptr);
	} else if (stateType == 1) {
		mPelletSM->start(this, 4, nullptr);
		mScale = Vector3f(0.01f);
	} else {
		mPelletSM->start(this, 5, nullptr);
		mScale = Vector3f(0.01f);
	}

	mPikminCount[0] = 0;
	mPikminCount[1] = 0;
	mPikminCount[2] = 0;
	mPikminCount[3] = 0;
	mPikminCount[4] = 0;
	mPikminCount[5] = 0;
	mPikminCount[6] = 0;
	_414            = 0;
	_43C            = (u16) static_cast<PelletInitArg*>(initArg)->_10;

	mConfig = mMgr->mConfigList->getPelletConfig(static_cast<PelletInitArg*>(initArg)->mTextIdentifier);

	if (!(mConfig->mParams.mCode.mData & 1)) {
		shadowOn();
	}

	if (static_cast<PelletInitArg*>(initArg)->mAdjustWeightForSquad) {
		mMinCarriers = GameStat::getMapPikmins(-1);
		int minPikis = mConfig->mParams.mMin.mData;
		if (mMinCarriers > minPikis) {
			mMinCarriers = minPikis;
		}
	} else {
		mMinCarriers = -1;
	}

	// temp_r3_6 = arg0->unk20;
	if ((static_cast<PelletInitArg*>(initArg)->mMinCarriers != -1) && (static_cast<PelletInitArg*>(initArg)->mMaxCarriers != -1)) {
		mMinCarriers = static_cast<PelletInitArg*>(initArg)->mMinCarriers;
		mMaxCarriers = static_cast<PelletInitArg*>(initArg)->mMaxCarriers;
	}

	mRigid._175 &= ~0x01;
	mRigid._175 &= ~0x80;
	mPelletColor = static_cast<PelletInitArg*>(initArg)->_0C;

	if (strcmp(mConfig->mParams.mName.mData, "loozy") == 0) {
		mPelletFlag = FLAG_LOOZY;
	} else if (strcmp(mConfig->mParams.mName.mData, "orima") == 0) {
		mPelletFlag = FLAG_NAVI_NAPSACK;
	} else {
		mPelletFlag = FLAG_NONE;
	}

	if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cBedamaYellow) == 0) {
		mPelletFlag = FLAG_VS_BEDAMA_YELLOW;
	} else if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cBedamaRed) == 0) {
		mPelletFlag = FLAG_VS_BEDAMA_RED;
	} else if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cBedamaBlue) == 0) {
		mPelletFlag = FLAG_VS_BEDAMA_BLUE;
	} else if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cCoin) == 0) {
		mPelletFlag = FLAG_VS_CHERRY;
	} else if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cBedamaWhite) == 0) {
        mPelletFlag = FLAG_VS_BEDAMA_WHITE;
    } else if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cBedamaPurple) == 0) {
        mPelletFlag = FLAG_VS_BEDAMA_PURPLE;
    }

	if (static_cast<PelletInitArg*>(initArg)->_1C == 0) {
		mModel = mMgr->createShape(_43C, mSlotIndex);
		onCreateShape();
	}

	if (mModel) {
		mCarryAnim.mAnimMgr = mMgr->mAnimMgr[_43C];
		mRadius             = 2.0f * mModel->getRoughBoundingRadius();
	} else {
		mRadius = mConfig->mParams.mRadius.mData;
	}

	if (mCarryAnim.mAnimMgr) {
		SysShape::MotionListener* listener = this;
		mCarryAnim.startAnim(0, listener);
		stop_carrymotion();
		init_pmotions();
		start_pmotions();
		if ((gameSystem->mMode == GSM_PIKLOPEDIA) && (mPelletFlag == FLAG_LOOZY)) {
			mAnimSpeed = 30.0f;
		}
	}

	mMgr->setCollTree(this, _43C);

	if (strcmp(mConfig->mParams.mDynamics.mData, "never") == 0) {
		_364                                 = 2;
		_39C                                 = 0;
		mConfig->mParams.mNumParticles.mData = 0;
	} else if (strcmp(mConfig->mParams.mDynamics.mData, "lod") == 0) {
		_364 = 1;
		_39C = 1;
	} else {
		_364 = 0;
		_39C = 1;
	}

	mSlots[0]  = 0;
	mSlots[1]  = 0;
	mSlots[2]  = 0;
	mSlots[3]  = 0;
	mSlots[4]  = 0;
	mSlots[5]  = 0;
	mSlots[6]  = 0;
	mSlots[7]  = 0;
	mSlots[8]  = 0;
	mSlots[9]  = 0;
	mSlots[10] = 0;
	mSlots[11] = 0;
	mSlots[12] = 0;
	mSlots[13] = 0;
	mSlots[14] = 0;
	mSlots[15] = 0;
	_3F6       = 0;

	mSlotCount = getPelletConfigMax();

	if (mSlotCount > 128) {
		mSlotCount = 128;
	}

	if (mConfig->mParams.mMin.mData == 128) {
		mMinCarriers = 1000;
		mMaxCarriers = 1000;
	}

	mDynParticle = nullptr;
	setupParticles();
	do_onInit(initArg);

	if (getKind() == PELTYPE_TREASURE) {
		Radar::Mgr::entry(this, Radar::MAP_TREASURE, 0);
	} else if (getKind() == PELTYPE_UPGRADE) {
		Radar::Mgr::entry(this, Radar::MAP_UPGRADE, 0);
	}

	setAlive(true);

	if (gameSystem->isVersusMode()) {
		GameMessagePelletBorn msg(this);
		gameSystem->mSection->sendMessage(msg);
	}
}


/*
 * --INFO--
 * Address:	8016D9E4
 * Size:	0000C8
 */
bool PelletMgr::makePelletInitArg(PelletInitArg& arg, char* identifier)
{
	BasePelletMgr* mgr          = PelletOtakara::mgr;
	PelletConfig* otakaraConfig = mgr->mConfigList->getPelletConfig(identifier);
	PelletConfig* config        = otakaraConfig;

	if (otakaraConfig == nullptr) {
		mgr    = PelletItem::mgr;
		config = mgr->mConfigList->getPelletConfig(identifier);
	}

	if (config == nullptr) {
		JUT_PANICLINE(5614, "no config found(%s)\n", identifier);
	}

	arg.mTextIdentifier = identifier;
	arg.mPelletType     = mgr->getMgrID();
	arg._10             = config->mParams.mIndex;
	arg._18             = 0;

	makeVsCarryMinMax(arg, identifier);
	return true;
}

/*
 * --INFO--
 * Address:	8016DAAC
 * Size:	0000E4
 */
void PelletMgr::makeVsCarryMinMax(PelletInitArg& arg, char* name)
{
	if (gameSystem != nullptr && gameSystem->isVersusMode()) {
		if (strcmp(VsOtakaraName::cBedamaYellow, name) == 0) {
			arg.mMinCarriers = 1;
			arg.mMaxCarriers = 8;
		} else if (strcmp(VsOtakaraName::cBedamaRed, name) == 0) {
			arg.mMinCarriers = 1;
			arg.mMaxCarriers = 8;
		} else if (strcmp(VsOtakaraName::cBedamaBlue, name) == 0) {
			arg.mMinCarriers = 1;
			arg.mMaxCarriers = 8;
		} else if (strcmp(VsOtakaraName::cCoin, name) == 0) {
			arg.mMinCarriers = 1;
			arg.mMaxCarriers = 1;
		} else if (strcmp(VsOtakaraName::cBedamaPurple, name) == 0) {
			arg.mMinCarriers = 1;
			arg.mMaxCarriers = 8;
		} else if (strcmp(VsOtakaraName::cBedamaWhite, name) == 0) {
			arg.mMinCarriers = 1;
			arg.mMaxCarriers = 8;
		}
	}
}

/*
 * --INFO--
 * Address:	8016DB90
 * Size:	0002EC
 */
bool PelletMgr::makePelletInitArg(PelletInitArg& arg, PelletMgr::OtakaraItemCode& itemCode)
{
	if (itemCode.isNull()) {
		return false;
	}

	BasePelletMgr* mgr;
	PelletConfig* config;

	u8 code = itemCode.mValue >> 8;
	mgr     = nullptr;
	if (code == 3) {
		mgr = PelletOtakara::mgr;
	} else if (code == 4) {
		mgr = PelletItem::mgr;
	}
	if (mgr == nullptr) {
		JUT_PANICLINE(5672, "illegal code (%x)\n", itemCode.mValue);
	}

	code = itemCode.mValue;
	if ((itemCode.mValue & 0xFF) < 0 || code >= mgr->mConfigList->mConfigCnt) {
		config = nullptr;
	} else {
		config = mgr->mConfigList->mConfigs + code;
	}

	if (config == nullptr) {
		JUT_PANICLINE(5676, "illegal code no config found (%x) index %d\n", itemCode.mValue, code);
	}

	arg.mTextIdentifier = config->mParams.mName.mData;
	arg.mPelletType     = itemCode.mValue >> 8;
	arg._10             = itemCode.mValue & 0xFF;
	arg._18             = 0;
	makeVsCarryMinMax(arg, arg.mTextIdentifier);
	return true;
}

// setBedamaColor__Q34Game13PelletOtakara6ObjectFv
bool PelletOtakara::Object::setBedamaColor() {
    PSM::PelletItem* obj = (PSM::PelletItem*)mSoundMgr;
    if (mPelletFlag == FLAG_VS_BEDAMA_WHITE) {
        mBedamaColor = 3;
        obj->_70 = 4;
        return true;
    }
    if (mPelletFlag == FLAG_VS_BEDAMA_PURPLE) {
        mBedamaColor = 3;
        obj->_70 = 4;
        return true;
    }
    return false;
}

} // namespace Game
