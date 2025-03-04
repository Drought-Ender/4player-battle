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
#include "Game/Entities/ItemPikihead.h"
#include "efx/TEnemyDive.h"
#include "JSystem/J3D/J3DModelLoader.h"
#include "JSystem/J3D/J3DTransform.h"

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

void NaviNukuState::onKeyEvent(Navi* navi, SysShape::KeyEvent const& key)
{
	switch (key.mType) {
	case KEYEVENT_2:
		_15 = true;
		mCounter--;
		if (mCounter == 0) {
			navi->mSoundObj->startSound(PSSE_PL_PULLOUT_PIKI, 0);
			mDidPluckSE = true;
		}
		break;
	case KEYEVENT_END:
		if (mIsActive) {
			if (mIsFollower || !navi->procActionButton()) {
				mIsActive = false;
				if (mIsFollower) {
					NaviFollowArg arg(false); // not new to party
					transit(navi, NSID_Follow, &arg);
				} else {
					transit(navi, NSID_Walk, nullptr);
				}
				navi->mPluckingCounter = 0;
			}
		} else {
			if (mIsFollower) {
				NaviFollowArg arg(false); // not new to party
				transit(navi, NSID_Follow, &arg);
			} else {
				transit(navi, NSID_Walk, nullptr);
			}
			navi->mPluckingCounter = 0;
		}
		break;
	}
}

bool PikiFallMeckState::becomePikihead(Piki* piki)
{
	PikiMgr::mBirthMode        = PikiMgr::PSM_Force;
	ItemPikihead::Item* sprout = static_cast<ItemPikihead::Item*>(ItemPikihead::mgr->birth());
	PikiMgr::mBirthMode        = PikiMgr::PSM_Normal;

	Vector3f pikiPos = piki->getPosition();
	pikiPos.y        = mapMgr->getMinY(pikiPos);
	if (sprout) {
		if (piki->inWater()) {
			efx::TEnemyDive fxDive;
			efx::ArgScale fxArg(pikiPos, 1.2f);

			fxDive.create(&fxArg);
		} else {
			efx::createSimplePkAp(pikiPos);
			piki->startSound(PSSE_PK_SE_ONY_SEED_GROUND, true);
		}

		ItemPikihead::InitArg initArg((EPikiKind)piki->mPikiKind, Vector3f::zero, true, Leaf, piki->mBulbminAffiliation);

		if (mDoAutoPluck) {
			initArg.mAutopluckTimer = 10.0f + 3.0f * sys->mDeltaTime;
		}
		sprout->init(&initArg);
		sprout->setPosition(pikiPos, false);

		CreatureKillArg killArg(CKILL_DontCountAsDeath);

		piki->kill(&killArg);

		return true;
	}

	return false;
}

void PikiFallMeckState::bounceCallback(Piki* piki, Sys::Triangle* triangle)
{
	bool check;
	if (mDoAutoPluck && triangle && ItemPikihead::mgr) {
		if (becomePikihead(piki)) {
			return;
		}
	} else if (triangle && !triangle->mCode.isBald() && piki->might_bury() && ItemPikihead::mgr) {
		if (becomePikihead(piki)) {
			return;
		}
	}

	transit(piki, PIKISTATE_Walk, nullptr);
}

void PikiMgr::createModelCallback(SysShape::Model* model)
{
	if (model->mJ3dModel->mModelData == mBlbPikiModel) {
		OSReport("Created bulbedmin\n");
		for (u16 i = 0; i < model->mJ3dModel->mModelData->getMaterialNum(); i++) {
			const char* name = model->mJ3dModel->mModelData->mMaterialTable.mMaterialNames->getName(i);
			if (!strcmp(name, "body1")) {
				model->mJ3dModel->mMatPackets[i].mShapePacket->newDifferedDisplayList(J3DMDF_DiffColorReg);
			}
		}

		Piki::updateBulbminModel(model, 0xff);
	}

	model->mJ3dModel->calcMaterial();
	model->mJ3dModel->makeDL();

	

	model->mJ3dModel->lock();

	

	
}

void PikiMgr::loadBmd(int id, char* name)
{
	char pathbuf[255];
	sprintf(pathbuf, "piki_model/%s.bmd", name);
	J3DModelData* data
	    = J3DModelLoaderDataBase::load(mModelArchive->getResource(pathbuf), J3DMLF_UseSingleSharedDL | J3DMLF_18 | J3DMLF_UseImmediateMtx);

	{
		const u32 lightObjNum = 0;
		const u32 texGenNum   = 0;
		const u32 texCoordNum = 4;
		const u32 tevStageNum = 0;
		u32 dlFlags           = CREATE_DIFF_FLAG(lightObjNum, texGenNum, texCoordNum, tevStageNum);
		data->newSharedDisplayList(dlFlags);
		data->makeSharedDL();
	}

	(&mBluPikiModel)[id] = data;
}

void PikiMgr::load(int viewNum)
{

	JKRHeap* heap = JKRGetCurrentHeap();
	heap->getFreeSize();
	JKRArchive* arc = JKRMountArchive("/user/Kando/piki/pikis.szs", JKRArchive::EMM_Mem, sys->mSysHeap, JKRArchive::EMD_Head);
	mModelArchive   = arc;
	heap->getFreeSize();

	JUT_ASSERTLINE(450, arc, "pikis.szs not found !\n");

	loadBmd(Blue, "piki_p2_blue");
	loadBmd(Red, "piki_p2_red");
	loadBmd(Yellow, "piki_p2_yellow");
	loadBmd(White, "piki_p2_white");
	loadBmd(Purple, "piki_p2_black");
	loadBmd(Bulbmin, "piki_kochappy");
	loadBmd(Carrot, "piki_ninjin");

	(&mLeafModel)[Leaf] = J3DModelLoaderDataBase::load(arc->getResource("happa_model/leaf.bmd"), J3DMLF_Material_PE_FogOff);
	(&mLeafModel)[Bud]
	    = J3DModelLoaderDataBase::load(arc->getResource("happa_model/bud.bmd"), J3DMLF_UseUniqueMaterials | J3DMLF_UseSingleSharedDL);
	(&mLeafModel)[Flower]
	    = J3DModelLoaderDataBase::load(arc->getResource("happa_model/flower.bmd"), J3DMLF_UseUniqueMaterials | J3DMLF_UseSingleSharedDL);
	(&mLeafModel)[Bud_Red]
	    = J3DModelLoaderDataBase::load(arc->getResource("happa_model/bud_red.bmd"), J3DMLF_UseUniqueMaterials | J3DMLF_UseSingleSharedDL);
	(&mLeafModel)[Flower_Red] = J3DModelLoaderDataBase::load(arc->getResource("happa_model/flower_red.bmd"),
	                                                         J3DMLF_UseUniqueMaterials | J3DMLF_UseSingleSharedDL);

	sys->heapStatusStart("pikmin-ModelMgr", nullptr);
	mModelMgr = new SysShape::ModelMgr(PikiColorCount, &mBluPikiModel, 250, J3DMODEL_ShareDL, viewNum,
	                                   new Delegate1<PikiMgr, SysShape::Model*>(this, createModelCallback));
	sys->heapStatusEnd("pikmin-ModelMgr");

	for (int i = 0; i < PikiHappaCount; i++) {
		J3DModelData* model = (&mLeafModel)[i];

		const u32 lightObjNum = 0;
		const u32 texGenNum   = 0;
		const u32 texCoordNum = 4;
		const u32 tevStageNum = 0;
		u32 dlFlags           = CREATE_DIFF_FLAG(lightObjNum, texGenNum, texCoordNum, tevStageNum);
		model->newSharedDisplayList(dlFlags);
		model->simpleCalcMaterial(0, *(Mtx*)j3dDefaultMtx);
		model->makeSharedDL();
	}
}

void Piki::updateBulbminModel(SysShape::Model* model, u16 bulbminAffil)
{
	J3DModel* j3dModel      = model->mJ3dModel;
	J3DModelData* modelData = j3dModel->getModelData();

	u16 idx = modelData->getMaterialName()->getIndex("body1");
	JUT_ASSERT(idx != -1, "body1 bulbmin GONE");
	J3DMaterial* bulbminMat = model->mJ3dModel->mMatPackets[idx].getMaterial();

	const J3DGXColorS10 defaultRed((u16)0xff, 0x00, 0x00, 0xff);
	const J3DGXColorS10 defaultSpot((u16)0xff, 0xff, 0xff, 0xff);

	J3DGXColorS10 colorBody = defaultRed;
	J3DGXColorS10 colorSpot = defaultSpot;

	switch (bulbminAffil) {
	case Blue:
		colorBody = J3DGXColorS10((u16)0x00, 0x00, 0xff, 0xff);
		colorSpot = J3DGXColorS10((u16)0xa0, 0xa0, 0xff, 0xff);
		break;
	case Red:
		colorBody = J3DGXColorS10((u16)0xa0, 0x00, 0x00, 0xff);
		colorSpot = J3DGXColorS10((u16)0xff, 0x00, 0x00, 0xff);
		break;
	case Purple:
		colorBody = J3DGXColorS10((u16)0x36, 0x1b, 0x5c, 0xff);
		colorSpot = J3DGXColorS10((u16)0x6a, 0x00, 0xff, 0xff);
		break;
	case White:
		colorBody = J3DGXColorS10((u16)0xff, 0xff, 0xff, 0xff);
		colorSpot = J3DGXColorS10((u16)0xff, 0xb8, 0xea, 0xff);
		break;
	}

	// OSReport("bulberto body %i %i %i %i\b", colorBody.r, colorBody.g, colorBody.b, colorBody.a);
	// OSReport("bulberto spot %i %i %i %i\b", colorSpot.r, colorSpot.g, colorSpot.b, colorSpot.a);

	bulbminMat->getTevBlock()->setTevColor(0, colorBody); // tev 0 is body
	bulbminMat->getTevBlock()->setTevColor(1, colorSpot); // tev 1 is spot

	j3dModel->calcMaterial();

	for (u16 i = 0; i < modelData->getMaterialNum(); i++) {
		J3DMatPacket* packet = j3dModel->getMatPacket(i);
		j3dSys.setMatPacket(packet);
		J3DMaterial* material = modelData->getMaterialNodePointer(i);
		material->diff(packet->getShapePacket()->mDiffFlag);
	}
}

// updateBulbminMaterial__Q24Game4PikiFv
void Piki::updateBulbminMaterial()
{
	if (mPikiKind != Bulbmin) {
		return;
	}

	updateBulbminModel(mModel, mBulbminAffiliation);

	// OSReport("updateBulbminMaterial() | bulbmin type: %i\n", mBulbminAffiliation);

	// for (u16 i = 0; i < modelData->getMaterialNum(); i++) {
	// 	J3DMatPacket* packet = j3dModel->getMatPacket(i);
	// 	j3dSys.setMatPacket(packet);
	// 	J3DMaterial* material = modelData->getMaterialNodePointer(i);
	// 	material->diff(packet->getShapePacket()->mDiffFlag);
	// }
}

} // namespace Game
