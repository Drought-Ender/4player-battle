#include "Game/Entities/Pelplant.h"
#include "Game/Farm.h"
#include "Game/gamePlayData.h"

#include "JSystem/J3D/J3DMtxBuffer.h"

namespace Game {
namespace Farm {
FarmMgr* farmMgr;
}

namespace Pelplant {
Obj* Obj::sCurrentObj;

static float sLODRadius[4] = { 45.0f, 60.0f, 103.0f, 133.0f };
} // namespace Pelplant
} // namespace Game

const char* unused[] = { __FILE__, "/enemy/data/pelplant", "/enemy/parm/pelplant" };

static f32 negSin(f32 x) { return -JMath::sincosTable_.mTable[((int)(x *= -325.9493f) & 0x7ffU)].first; }
static f32 posSin(f32 x) { return JMath::sincosTable_.mTable[((int)(x *= 325.9493f) & 0x7ffU)].first; }

// Custom version of pikmin2_sinf from trig.h
inline f32 pikmin2_sinf_(f32 x)
{
	if (x < 0.0f) {
		return negSin(x);
	} else {
		return posSin(x);
	}
}

namespace Game {
namespace Pelplant {
/*
 * --INFO--
 * Address:	80108300
 * Size:	0000B0
 */
f32 BlendAccelerationFunc::getValue(f32 t)
{
	f32 sinTheta = pikmin2_sinf_(TAU * (3.0f * -t));
	f32 value    = ((0.5f * (1.0f - t)) * sinTheta) + t;

	if (value > 1.0f) {
		return 1.0f;
	}

	if (value < 0.0f) {
		value = 0.0f;
	}
	return value;
}

/*
 * --INFO--
 * Address:	801083B0
 * Size:	0000B4
 */
void Obj::birth(Vector3f& position, float faceDir)
{
	EnemyBase::birth(position, faceDir);

	mFarmPow = 0;
	if (Farm::farmMgr) {
		Farm::farmMgr->addPlant(this);
	}

	if (gameSystem->isVersusMode()) {
		mFsm->start(this, PELPLANT_Grow2, nullptr);
	} else {
		mFsm->start(this, PELPLANT_WaitSmall, nullptr);
	}

	mRootJointMtx = mModel->getJoint("bodyjnt2")->getWorldMatrix();
}

/*
 * --INFO--
 * Address:	80108464
 * Size:	000280
 */
void Obj::setInitialSetting(EnemyInitialParamBase* initParms)
{
	PelplantInitialParam* plParms = static_cast<PelplantInitialParam*>(initParms);

	if (mFarmPow == 0) {
		SET_FLAG(mFlags, PELPLANT_FLAGS_GROW);
	} else {
		RESET_FLAG(mFlags, PELPLANT_FLAGS_GROW);
	}

	if (mFarmPow < 0) {
		plParms->mInitialState = PELPLANT_SIZE_SMALL;
	}

	mColor = plParms->mColor;
	setPelletColor(mColor, false);

	mSize = plParms->mAmount;
	switch (plParms->mInitialState) {
	case PELPLANT_SIZE_SMALL:
		mFsm->start(this, PELPLANT_WaitSmall, nullptr);
		break;
	case PELPLANT_SIZE_MIDDLE:
		mFsm->start(this, PELPLANT_WaitMiddle, nullptr);
		break;
	case PELPLANT_SIZE_BIG:
		mFsm->start(this, PELPLANT_WaitBig, nullptr);
		attachPellet();
		break;
	}

	if (plParms->mAmount == PELLET_NUMBER_FIVE) {
		sCurrentObj = this;

		SysShape::Joint* joint = mModel->getJoint("headjnt");
		P2ASSERTLINE(365, joint);
		joint->mJ3d->mFunction = Obj::headJointCallBack;

		sCurrentObj = nullptr;
	}

	if (plParms->mAmount == PELLET_NUMBER_TEN || plParms->mAmount == PELLET_NUMBER_TWENTY) {
		sCurrentObj = this;

		SysShape::Joint* joint = mModel->getJoint("headjnt");
		P2ASSERTLINE(376, joint);
		joint->mJ3d->mFunction = Obj::headJointCallBack;

		joint = mModel->getJoint("bodyjnt1");
		P2ASSERTLINE(381, joint);
		joint->mJ3d->mFunction = Obj::neckJointCallBack;

		sCurrentObj = nullptr;
	}

	CollPart* part = mCollTree->getCollPart('head');
	f32 scale      = getHeadScale();
	part->setScale(scale);
	part->mOffset.x *= scale;
	part->mOffset.y *= scale;
	part->mOffset.z *= scale;
}

/**
 * __ct__Q34Game8Pelplant3ObjFv
 * --INFO--
 * Address:	801086E4
 * Size:	000138
 */
Obj::Obj()
    : EnemyBase()
    , mFsm(nullptr)
    , mRootJointMtx(nullptr)
    , mFlags(PELPLANT_FLAGS_NONE)
    , mPellet(nullptr)
    , mColorChangeTimer(0.0f)
    , mColor(PELCOLOR_RANDOM)
    , mSize(PELPLANT_SIZE_MIDDLE)
    , mFarmPow(0)
{
	mAnimator = new ProperAnimator();
	setFSM(new FSM());
	mFlags = PELPLANT_FLAGS_NONE;
}

/*
 * --INFO--
 * Address:	801088C4
 * Size:	000034
 */
void Pelplant::Obj::doUpdate() { mFsm->exec(this); }

/*
 * --INFO--
 * Address:	801088F8
 * Size:	000088
 */
void Pelplant::Obj::updateLODSphereRadius(int size)
{
	if (size == PELPLANT_SIZE_BIG) {
		switch (mSize) {
		case PELLET_NUMBER_ONE:
			mCurLodSphere.mRadius = sLODRadius[0];
			return;
		case PELLET_NUMBER_FIVE:
			mCurLodSphere.mRadius = sLODRadius[1];
			return;
		case PELLET_NUMBER_TEN:
			mCurLodSphere.mRadius = sLODRadius[2];
			return;
		case PELLET_NUMBER_TWENTY:
			mCurLodSphere.mRadius = sLODRadius[3];
			return;
		}
	} else {
		mCurLodSphere.mRadius = sLODRadius[0];
	}
}

/*
 * --INFO--
 * Address:	80108980
 * Size:	000004
 */
void Obj::doDirectDraw(Graphics&) { }

/*
 * --INFO--
 * Address:	80108984
 * Size:	00018C
 */
void Obj::doDebugDraw(Graphics& gfx)
{
	EnemyBase::doDebugDraw(gfx);
	if (C_PARMS->mFlags[0].typeView & 1) {
		gfx.initPerspPrintf(gfx.mCurrentViewport);

		PerspPrintfInfo info;
		Vector3f pos(mPosition.x, 100.0f + mPosition.y, mPosition.z);

		info._14 = Color4(0xC8, 0xC8, 0xFF, 0xC8);
		info._18 = Color4(0x64, 0x64, 0xFF, 0xC8);
		gfx.perspPrintf(info, pos, "FARM_POW(%d) Grow%s", mFarmPow, (mFlags & PELPLANT_FLAGS_GROW) ? "on" : "off");

		pos.y += 16.0f;
		info._14 = Color4(0xFF, 0xC8, 0xFF, 0xC8);
		info._18 = Color4(0xC8, 0x64, 0xFF, 0xC8);
		gfx.perspPrintf(info, pos, "%s %4.2f", mFsm->getCurrName(this), _2C0);
	}
}

/*
 * --INFO--
 * Address:	80108B10
 * Size:	0000C0
 */
void Obj::getShadowParam(ShadowParam& param)
{
	param.mPosition = mPosition;
	param.mPosition.y += 2.0f;

	if (mBounceTriangle) {
		Plane* plane                      = &mBounceTriangle->mTrianglePlane;
		param.mBoundingSphere.mPosition.x = plane->a;
		param.mBoundingSphere.mPosition.y = plane->b;
		param.mBoundingSphere.mPosition.z = plane->c;
	} else {
		param.mBoundingSphere.mPosition = Vector3f(0.0f, 1.0f, 0.0f);
	}
	param.mBoundingSphere.mRadius = 50.0f;

	Vector3f newVec;
	mRootJointMtx->getRow(0, newVec);
	float sum = newVec.x;
	newVec.y *= newVec.y;
	newVec.z *= newVec.z;
	sum *= newVec.x;
	sum += newVec.y;
	sum += newVec.z;
	__sqrtf(sum, &sum);

	param.mSize = 8.0f * sum;
}

/*
 * --INFO--
 * Address:	80108BD0
 * Size:	000090
 */
void Obj::doAnimationUpdateAnimator()
{
	BlendAccelerationFunc func;
	static_cast<EnemyBlendAnimatorBase*>(mAnimator)->animate(&func, EnemyAnimatorBase::defaultAnimSpeed * sys->mDeltaTime,
	                                                         EnemyAnimatorBase::defaultAnimSpeed * sys->mDeltaTime,
	                                                         EnemyAnimatorBase::defaultAnimSpeed * sys->mDeltaTime);
	SysShape::Model* model = mModel;
	model->mJ3dModel->mModelData->mJointTree.mJoints[0]->mMtxCalc
	    = (J3DMtxCalcAnmBase*)(static_cast<EnemyBlendAnimatorBase*>(mAnimator)->mAnimator.getCalc());
}

/*
 * --INFO--
 * Address:	80108C60
 * Size:	000058
 */
f32 Obj::getHeadScale()
{
	f32 headScale;
	if (mPellet) {
		switch (mSize) {
		case PELLET_NUMBER_ONE:
			headScale = 1.0f;
			break;
		case PELLET_NUMBER_FIVE:
			headScale = 2.0f;
			break;
		case PELLET_NUMBER_TEN:
			headScale = 3.5f;
			break;
		case PELLET_NUMBER_TWENTY:
			headScale = 4.8f;
			break;
		}
	} else {
		headScale = 1.0f;
	}
	return headScale;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void Obj::getNeckScale(Vector3f* scale) { *scale = Vector3f(1.5f, 0.85f, 0.75f); }

/*
 * doAnimation__Q34Game8Pelplant3ObjFv
 * --INFO--
 * Address:	80108CB8
 * Size:	000198
 */
void Obj::doAnimation()
{
	sys->mTimers->_start("zama", true);

	f32 headScale = getHeadScale();

	Obj::sCurrentObj = this;
	EnemyBase::doAnimation();
	Obj::sCurrentObj = nullptr;

	if (mPellet) {
		float neckScale;
		switch (mSize) {
		case PELLET_NUMBER_ONE:
			neckScale = 12.0f;
			break;
		case PELLET_NUMBER_FIVE:
			neckScale = 12.0f;
			break;
		case PELLET_NUMBER_TEN:
			neckScale = 12.0f;
			break;
		case PELLET_NUMBER_TWENTY:
			neckScale = 12.0f;
			break;
		default:
			JUT_PANICLINE(663, "Unknown Pellet size. %d \n", mSize);
			break;
		}

		Vector3f translation = Vector3f(neckScale, 0.0f, 0.0f);
		Vector3f rotation(0.0f, HALF_PI, -HALF_PI);
		Vector3f scale(1.0f / headScale);

		Matrixf mat;
		mat.makeSRT(scale, rotation, translation);
		mPellet->updateCapture(mat);
	}

	sys->mTimers->_stop("zama");
}

/*
 * --INFO--
 * Address:	80108E50
 * Size:	000004
 */
void Obj::doSimulation(float) { }

/*
 * --INFO--
 * Address:	80108E54
 * Size:	0000F0
 */
void Obj::setPelletColor(u16 color, bool check)
{
	if (mPellet) {
		switch (color) {
		case PELCOLOR_BLUE:
		case PELCOLOR_RED:
		case PELCOLOR_YELLOW:
		case PELCOLOR_PURPLE:
		case PELCOLOR_WHITE:
			if (check) {
				if (playData->hasMetPikmin(color) && (color == PELCOLOR_YELLOW || isTeamActive(getTeamFromPiki(color)))) {
					mPellet->setValidColor(color);
					return;
				}

				mPellet->mPelletColor = PELCOLOR_RED;
				return;
			}

			mPellet->setValidColor(color);
			break;
		default:
			mPellet->mPelletColor = gScoreDelegations[0][0];
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	80108F44
 * Size:	000190
 */
void Obj::changePelletColor()
{
	if (mPellet && mColor == PELCOLOR_RANDOM) {
		if (mColorChangeTimer > C_PARMS->mPelplantParms.mColorChangeTime.mValue) {
			int pelColorArr[] = { PELCOLOR_RED, PELCOLOR_YELLOW, PELCOLOR_BLUE, PELCOLOR_WHITE, PELCOLOR_PURPLE, PELCOLOR_RANDOM };
			int pelColorIdx[] = { 2, 0, 1, 4, 3, 5 };
			u16 initialColor;
			if (mPellet) {
				initialColor = mPellet->mPelletColor;
			} else {
				initialColor = PELCOLOR_RED;
			}

			int colorIdx = pelColorIdx[initialColor] + 1;
			u16 nextColor = pelColorArr[colorIdx];
			u16 colorCap  = nextColor;

			WEIRD_JUMP:
			while (nextColor != PELCOLOR_YELLOW && !doesTeamHavePlayers(getTeamFromPelplant(nextColor))) {

				nextColor = pelColorArr[++colorIdx];
				if (nextColor > PELCOLOR_WHITE) {
					nextColor = pelColorArr[colorIdx = 0];
				}
			}

			if (colorIdx > 5) {
				nextColor = pelColorArr[colorIdx = 0];
				goto WEIRD_JUMP; // forgive me, c++ gods
			}

			setPelletColor(nextColor, true);

			if (mFlags & PELPLANT_FLAGS_GROW) {
				mColorChangeTimer = 0.0f;
				return;
			}

			mColorChangeTimer = 0.0f;
			return;
		}

		const float dt = sys->mDeltaTime;
		if (mFlags & PELPLANT_FLAGS_GROW) {
			mColorChangeTimer += dt;
		}
	}
}

/*
 * --INFO--
 * Address:	801090D4
 * Size:	000110
 */
void Obj::attachPellet()
{
	if (mPellet == nullptr) {
		Obj::sCurrentObj = this;

		PelletNumberInitArg numberArg(mSize, 0);
		Pellet* newPellet = pelletMgr->birth(&numberArg);
		if (newPellet) {
			Matrixf* mat = mModel->getJoint("headjnt")->getWorldMatrix();
			P2ASSERTLINE(777, mat != nullptr);
			newPellet->startCapture(mat);

			mPellet = (PelletNumber::Object*)newPellet;

			setPelletColor(mColor, false);
		}

		Obj::sCurrentObj = nullptr;
	}
}

/*
 * --INFO--
 * Address:	801091E4
 * Size:	000098
 */
bool Obj::damageCallBack(Creature* source, float damage, CollPart* part)
{
	if (isLivingThing()) {
		addDamage(damage, 1.0f);
		if (part && part->mSpecialID.getStrID()[3] == '0') {
			addDamage(mMaxHealth, 1.0f);
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	80109288
 * Size:	000078
 */
bool Obj::farmCallBack(Creature* c, float power)
{
	// If power > 0, round up + 1; else we round down -1
	mFarmPow = (s8)(power >= 0.0f ? power + 0.5f : power - 0.5f);

	if (mFarmPow < 0) {
		RESET_FLAG(mFlags, PELPLANT_FLAGS_GROW);
	} else {
		SET_FLAG(mFlags, PELPLANT_FLAGS_GROW);
	}

	disableEvent(0, EB_IsCullable);
	return true;
}

/*
 * --INFO--
 * Address:	80109300
 * Size:	000060
 */
void Obj::onStickStart(Creature* other)
{
	EnemyBase::onStickStart(other);
	if (other->mStuckCollPart && other->mStuckCollPart->mSpecialID.getStrID()[3] == '0') {
		addDamage(mMaxHealth, 1.0f);
	}
}

/*
 * --INFO--
 * Address:	80109360
 * Size:	0000F0
 */
bool Obj::headJointCallBack(J3DJoint* joint, int p2)
{
	if (sCurrentObj != nullptr && p2 == 1) {
		Mtx& mtx  = J3DMtxCalc::mMtxBuffer->mWorldMatrices[joint->getJntNo()];
		f32 scale = sCurrentObj->getHeadScale();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				mtx[i][j] *= scale;
			}
		}
	}

	return 0;
}

/*
 * --INFO--
 * Address:	80109450
 * Size:	000104
 */
bool Obj::neckJointCallBack(J3DJoint* joint, int p2)
{
	if (sCurrentObj != nullptr && p2 == 1) {
		Mtx& mtx = J3DMtxCalc::mMtxBuffer->mWorldMatrices[joint->getJntNo()];

		f32 neckLength;
		f32 neckThickness;
		if (sCurrentObj->mPellet) {
			switch (sCurrentObj->mSize) {
			case PELLET_NUMBER_ONE:
				neckThickness = 1.0f;
				neckLength    = neckThickness;
				break;
			case PELLET_NUMBER_FIVE:
				neckThickness = 1.0f;
				neckLength    = neckThickness;
				break;
			case PELLET_NUMBER_TEN:
				neckThickness = 1.5;
				neckLength    = 0.85;
				break;
			case PELLET_NUMBER_TWENTY:
				neckThickness = 2.0;
				neckLength    = 0.75;
				break;
			}

		} else {
			neckThickness = 1.0f;
			neckLength    = neckThickness;
		}

		Vector3f scale(neckThickness, neckLength, neckThickness);
		mtx[0][0] *= scale.x;
		mtx[0][1] *= scale.x;
		mtx[0][2] *= scale.x;

		mtx[1][0] *= scale.y;
		mtx[1][1] *= scale.y;
		mtx[1][2] *= scale.y;

		mtx[2][0] *= scale.z;
		mtx[2][1] *= scale.z;
		mtx[2][2] *= scale.z;
	}
	return 0;
}

/*
 * __ct__Q34Game8Pelplant3MgrFiUc
 * --INFO--
 * Address:	80109554
 * Size:	000050
 */
Mgr::Mgr(int p1, unsigned char p2)
    : EnemyMgrBase(p1, p2)
{
	mName = "�y���b�g���}�l�[�W��"; // pellet plant manager
}

/*
 * --INFO--
 * Address:	8010963C
 * Size:	000048
 */
void Mgr::doAlloc() { init(new Parms); }

/*
 * birth__Q34Game8Pelplant3MgrFRQ24Game13EnemyBirthArg
 * --INFO--
 * Address:	8010A460
 * Size:	000020
 */
EnemyBase* Mgr::birth(EnemyBirthArg& arg) { return EnemyMgrBase::birth(arg); }

/*
 * --INFO--
 * Address:	8010A480
 * Size:	0000D0
 */
void Obj::onInit(CreatureInitArg* arg)
{
	EnemyBase::onInit(arg);
	_2C0 = 0.0f;
	setEmotionNone();

	if (mFarmPow == 0) {
		SET_FLAG(mFlags, PELPLANT_FLAGS_GROW);
	} else {
		RESET_FLAG(mFlags, PELPLANT_FLAGS_GROW);
	}

	int stateID = getStateID();
	if (stateID == PELPLANT_Invalid) {
		stateID = PELPLANT_WaitSmall;
	}

	mFsm->start(this, stateID, nullptr);

	disableEvent(0, EB_IsDeathEffectEnabled);
	disableEvent(0, EB_ToLeaveCarcass);
	disableEvent(0, EB_IsPlatformCollsAllowed);
	enableEvent(0, EB_IsImmuneBitter);
	hardConstraintOn();
}

/*
 * --INFO--
 * Address:	8010A550
 * Size:	000048
 */
void Obj::doGetLifeGaugeParam(LifeGaugeParam& param)
{
	mRootJointMtx->getTranslation(param.mPosition);
	param.mPosition.y += 60.0f;
	param.mCurrHealthRatio = mHealth / mMaxHealth;
	param.mRadius              = 10.0f;
}

} // namespace Pelplant
} // namespace Game
