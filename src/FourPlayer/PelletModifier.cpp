#include "Game/pelletMgr.h"
#include "VsOtakaraName.h"
#include "Radar.h"
#include "Game/gameStat.h"
#include "Game/Entities/PelletOtakara.h"
#include "Game/Entities/PelletItem.h"
#include "PSM/Otakara.h"
#include "Game/Entities/ItemTreasure.h"
#include "VsOptions.h"
#include "efx/TOtakara.h"
#include "Dolphin/rand.h"
#include "PSM/WorkItem.h"

namespace Game {
void Pellet::onInit(CreatureInitArg* initArg)
{
	mMaxCarriers = -1;
	mMinCarriers = -1;

	mWallTimer = 0;
	_324       = 0;
	mIsInWater = false;

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

	PelletMgr::_makeVsCarryMinMax(*static_cast<PelletInitArg*>(initArg), static_cast<PelletInitArg*>(initArg)->mTextIdentifier);

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
	mPelletSizeType = (u16) static_cast<PelletInitArg*>(initArg)->mPelletIndex;

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

	if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cBedamaYellow) == 0 && gGameModeID == MAINGAME_BEDAMA) {
		// OSReport("FLAG_VS_BEDAMA_YELLOW\n");
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
	} else if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cBedamaMini) == 0 && gGameModeID == MAINGAME_BEDAMA) {
		mPelletFlag = FLAG_VS_BEDAMA_MINI;
	} else if (strcmp(mConfig->mParams.mName.mData, VsOtakaraName::cBingoRandom) == 0 && gGameModeID == MAINGAME_BINGO) {
		mPelletFlag = FLAG_VS_BINGO_ITEM;
	}

	if (static_cast<PelletInitArg*>(initArg)->mDoSkipCreateModel == 0) {
		mModel = mMgr->createShape(mPelletSizeType, mSlotIndex);
		onCreateShape();
	}

	if (mModel) {
		mCarryAnim.mAnimMgr = mMgr->mAnimMgr[mPelletSizeType];
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

	mMgr->setCollTree(this, mPelletSizeType);

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

void Pellet::onKill(CreatureKillArg* killArg)
{
	if (gameSystem->isVersusMode()) {
		mPelletSM->start(this, 0, nullptr);
	}

	setAlive(false);

	if (shadowMgr) {
		shadowMgr->delShadow(this);
	}

	if (gameSystem->isVersusMode()) {
		GameMessagePelletDead msg(this);
		gameSystem->mSection->sendMessage(msg);
	}

	Vector3f scale(1.0f);
	Vector3f rotation(0.0f);
	Vector3f translation(0.0f);
	mObjMatrix.makeSRT(scale, rotation, translation);

	if (mModel) {
		mLodSphere.mPosition = Vector3f(0.0f);
		mLodSphere.mRadius   = 128000.0f;
		mScale               = Vector3f(1.0f);
		PSMTXCopy(mObjMatrix.mMatrix.mtxView, mModel->mJ3dModel->mPosMtx);
		mScale.setTVec(mModel->mJ3dModel->mModelScale);
		mModel->clearAnimatorAll();
		mModel->mJ3dModel->calc();
	}

	releaseParticles();
	mCollTree->release();
	mMgr->kill(this);

	if (((killArg != nullptr) && (static_cast<PelletKillArg*>(killArg)->_08 != 0))
	    || ((gameSystem->isVersusMode()) && (mPelletFlag == FLAG_VS_CHERRY || mPelletFlag == FLAG_VS_BINGO_ITEM))) {
		mMgr->setRevival(this);
	}

	finishDisplayCarryInfo();

	if (mPelletView) {
		mPelletView->viewOnPelletKilled();
		mPelletView->mPellet = nullptr;
		mPelletView          = nullptr;
	}

	if (getKind() == PELTYPE_TREASURE || getKind() == PELTYPE_UPGRADE) {
		Radar::Mgr::exit(this);
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
	arg.mPelletIndex    = config->mParams.mIndex;
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
		} else if (strcmp(VsOtakaraName::cBedamaMini, name) == 0) {
			arg.mMinCarriers = 1;
			arg.mMaxCarriers = 8;
		}
	}
}

void PelletMgr::_makeVsCarryMinMax(PelletInitArg& arg, char* name)
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
		} else if (strcmp(VsOtakaraName::cBedamaMini, name) == 0) {
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
	arg.mPelletIndex    = itemCode.mValue & 0xFF;
	arg._18             = 0;
	makeVsCarryMinMax(arg, arg.mTextIdentifier);
	return true;
}

// setBedamaColor__Q34Game13PelletOtakara6ObjectFv
bool PelletOtakara::Object::setBedamaColor()
{
	PSM::PelletItem* obj = (PSM::PelletItem*)mSoundMgr;
	if (mPelletFlag == FLAG_VS_BEDAMA_RED) {
		mBedamaColor = Red;
		obj->_70     = 4;
		return true;
	}
	if (mPelletFlag == FLAG_VS_BEDAMA_BLUE) {
		mBedamaColor = Blue;
		obj->_70     = 4;
		return true;
	}
	if (mPelletFlag == FLAG_VS_BEDAMA_WHITE) {
		mBedamaColor = White;
		obj->_70     = 4;
		return true;
	}
	if (mPelletFlag == FLAG_VS_BEDAMA_PURPLE) {
		mBedamaColor = Purple;
		obj->_70     = 4;
		return true;
	}
	if (mPelletFlag == FLAG_VS_BEDAMA_MINI) {
		mBedamaColor = 2;
		obj->_70     = 1;
		return true;
	}
	if (mPelletFlag == FLAG_VS_BINGO_ITEM) {
		mBedamaColor = 5;
		obj->_70     = 4;
		return true;
	}
	mBedamaColor = Yellow;
	obj->_70     = 4;
	return true;
}

void Pellet::setupGeneratorBedama()
{
	// if (gameSystem != nullptr && gameSystem->isVersusMode()) {
	// 	if (strcmp(VsOtakaraName::cBedamaYellow, getCreatureName()) == 0) {
	// 		mMinCarriers = 1;
	// 		mMaxCarriers = 8;
	// 	} else if (strcmp(VsOtakaraName::cBedamaRed, getCreatureName()) == 0) {
	// 		mMinCarriers = 1;
	// 		mMaxCarriers = 8;
	// 	} else if (strcmp(VsOtakaraName::cBedamaBlue, getCreatureName()) == 0) {
	// 		mMinCarriers = 1;
	// 		mMaxCarriers = 8;
	// 	} else if (strcmp(VsOtakaraName::cCoin, getCreatureName()) == 0) {
	// 		mMinCarriers = 1;
	// 		mMaxCarriers = 1;
	// 	} else if (strcmp(VsOtakaraName::cBedamaPurple, getCreatureName()) == 0) {
	// 		mMinCarriers = 1;
	// 		mMaxCarriers = 8;
	// 	} else if (strcmp(VsOtakaraName::cBedamaWhite, getCreatureName()) == 0) {
	// 		mMinCarriers = 1;
	// 		mMaxCarriers = 8;
	// 	}
	// }

	if (getBedamaColor() != -1) {
		((PelletOtakara::Object*)this)->setBedamaColor();
	}
}

float Pellet::getMoveMultiplier()
{
	if (mPelletFlag == FLAG_VS_BEDAMA_MINI) {
		return 2.0f;
	}
	return 1.0f;
}

void MultiplyPelletMove(Pellet* pellet, Vector3f& move) { move *= pellet->getMoveMultiplier(); }

void ItemTreasure::Item::releasePellet()
{
	if (mPellet) {
		mPellet->endCapture();
		TexCaster::Caster* caster = mPellet->mCaster;
		if (caster) {
			caster->fadein(0.5f);
		}

		f32 scale = mPellet->getPickRadius();

		efx::ArgScale arg(mPosition, scale);
		efx::TOtakaraAp efx;
		efx.create(&arg);

		mSoundObj->startSound(PSSE_EV_TREASURE_JUMP_OUT, 0);

		Vector3f velocity;
		velocity.x = 10.0f * (randFloat() - 0.5f);
		velocity.z = 10.0f * (randFloat() - 0.5f);
		velocity.y = 15.0f;

		mPellet->setVelocity(velocity);

		if (gameSystem->isVersusMode()) {
			s32 color            = mPellet->getBedamaColor();
			bool isColoredMarble = color >= Blue && color <= White && color != Yellow;

			GameMessageVsBirthTekiTreasure mesg;
			mesg.mPosition     = mPosition;
			mesg.mIsBaseMarble = isColoredMarble;
			mesg.mTobiCount    = randInt(3) + 1;
			gameSystem->mSection->sendMessage(mesg);
		}

		mSoundEvent.finish();

		P2ASSERTLINE(327, mSoundObj->getCastType() == PSM::CCT_WorkItem);
		static_cast<PSM::WorkItem*>(mSoundObj)->eventFinish();

		setAlive(false);
		mPellet = nullptr;
	}
}

void PelletReturnState::exec(Pellet* pelt)
{
	bool end = false;
	switch (mState) {
	case 0:
		int check = execPathfinding(pelt);
		pelt->endPick(false);
		if (check == 2) {
			end = true;
		}
		break;
	case 1:
		check = execMove(pelt);
		if (check == 2) {
			end = true;
		} else if (check == 1) {
			end = true;
		}
		break;
	case 2:
		check = execMoveGoal(pelt);
		if (check == 2) {
			end = true;
		}
		break;
	}

	if (end) {
		transit(pelt, (gConfig[MARBLE_BURY] == ConfigEnums::PLACE_BURY) ? PELSTATE_BounceBury : PELSTATE_Normal, nullptr);
	}
}

} // namespace Game
