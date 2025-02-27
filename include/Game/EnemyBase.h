#ifndef _GAME_ENEMYBASE_H
#define _GAME_ENEMYBASE_H

#include "Game/Creature.h"
#include "Game/CollEvent.h"
#include "Game/EnemyStateMachine.h"
#include "Game/MoveInfo.h"
#include "Game/EnemyEffectNode.h"
#include "Game/PelletView.h"
#include "Game/EnemyPelletInfo.h"
#include "Game/pelletMgr.h"

#include "SysShape/MotionListener.h"

#include "PSM/EnemyBase.h"
#include "efx/TEnemyPiyo.h"

#include "trig.h"

#define EMOTE_None       (0)
#define EMOTE_Caution    (1)
#define EMOTE_Excitement (2)

#define OBJ(enemy) (static_cast<Obj*>(enemy))

struct MouthSlots;

namespace PSM {
struct EnemyBase;
} // namespace PSM

namespace Game {
struct EnemyBase;

namespace EnemyBaseFSM {
struct StateMachine;
} // namespace EnemyBaseFSM

namespace EnemyStone {
struct Obj;
} // namespace EnemyStone

namespace WalkSmokeEffect {
struct Mgr;
} // namespace WalkSmokeEffect

struct EnemyAnimatorBase;
struct EnemyAnimKeyEvent;
struct EnemyMgrBase;
struct WaterBox;
struct LifeGaugeParam;
struct Interaction;

enum EnemyEvent {
	EB_IsVulnerable            = 0x1,        // can take damage or not
	EB_IsTakingDamage          = 0x2,        // currently taking damage
	EB_IsFlying                = 0x4,        // is enemy flying (guessed name)
	EB_IsDamageAnimAllowed     = 0x8,        //
	EB_HasCollisionOccurred    = 0x10,       //
	EB_IsFlickEnabled          = 0x20,       //
	EB_IsCullable              = 0x40,       // can be culled/deloaded
	EB_ToLeaveCarcass          = 0x80,       // leave carcass upon death
	EB_IsDeathEffectEnabled    = 0x100,      //
	EB_IsBittered              = 0x200,      //
	EB_Constraint              = 0x400,      //
	EB_LifegaugeVisible        = 0x800,      //
	EB_IsPlatformCollsAllowed  = 0x1000,     //
	EB_14                      = 0x2000,     //
	EB_HasEatenWhitePikmin     = 0x4000,     //
	EB_IsAnimating             = 0x8000,     // should we animate?
	EB_IsNavi0Attacked         = 0x10000,    // is attacking the player's main character?
	EB_IsNavi1Attacked         = 0x20000,    // is attacking an ai player?
	EB_IsHardConstraint        = 0x40000,    // AKA: is kinematic, disables physics completely (locks position)
	EB_SquashOnDamageAnimation = 0x80000,    // set on at finishDropping, and HipDropCallback
	EB_ToEnableBitter          = 0x100000,   //
	EB_IsEnemyNotBitter        = 0x200000,   //
	EB_IsImmuneBitter          = 0x400000,   //
	EB_24                      = 0x800000,   //
	EB_PS1                     = 0x1000000,  // sound-related
	EB_PS2                     = 0x2000000,  // sound-related
	EB_PS3                     = 0x4000000,  // sound-related
	EB_PS4                     = 0x8000000,  // sound-related
	EB_IsAlive                 = 0x10000000, //
	EB_ShouldCheckCollision    = 0x20000000, //
	EB_IsModelHidden           = 0x40000000, //
	EB_32                      = 0x80000000  //
};

enum EnemyEvent2 {
	EB2_IsEarthquake       = 0x1,  //
	EB2_IsStunned          = 0x2,  //
	EB2_3                  = 0x4,  //
	EB2_4                  = 0x8,  //
	EB2_IsDropping         = 0x10, //
	EB2_IsDroppingMassZero = 0x20  //
};

enum DropGroup {
	EDG_None       = 0, //
	EDG_Normal     = 1, //
	EDG_Pikmin     = 2, // Is the dropping object a Pikmin?
	EDG_Navi       = 3, // Is the dropping object a Player?
	EDG_Treasure   = 4, // Is the dropping object a Treasure?
	EDG_Earthquake = 5, // Is the dropping object an Earthquake?
	EDG_AUTO       = 6
};

// Interface for specific overrides (e.g. PelplantInitialParams)
struct EnemyInitialParamBase {
};

struct EnemyKillArg : public CreatureKillArg {
	inline EnemyKillArg(int p1)
	    : CreatureKillArg(p1)
	{
	}

	/**
	 * @reifiedAddress{80107C38}
	 * @reifiedFile{plugProjectYamashitaU/enemyBase.cpp}
	 */
	virtual const char* getName() // _08 (weak)
	{
		return "EnemyKillArg";
	}
};

struct EnemyBase : public Creature, public SysShape::MotionListener, virtual public Game::PelletView {
	EnemyBase();

	// vtable 1 (Creature)
	virtual Vector3f getPosition() // _08 (weak)
	{
		return mPosition;
	}
	virtual void getBoundingSphere(Sys::Sphere& sphere) // _10 (weak)
	{
		sphere = mBoundingSphere;
	}
	virtual void constructor();                         // _2C
	virtual void onInit(CreatureInitArg* settings);     // _30
	virtual void onKill(CreatureKillArg* settings);     // _34
	virtual void onInitPost(CreatureInitArg* settings); // _38
	virtual void doAnimation();                         // _3C
	virtual void doEntry();                             // _40
	virtual void doSetView(int viewportNumber);         // _44
	virtual void doViewCalc();                          // _48
	virtual void doSimulation(f32 simSpeed);            // _4C
	virtual void onSetPosition(Vector3f& position)      // _70 (weak)
	{
		mPosition = position;
	}
	virtual void onSetPositionPost(Vector3f& position) // _74 (weak)
	{
		updateSpheres();
	}
	virtual void updateTrMatrix();                      // _78
	virtual void inWaterCallback(WaterBox* wbInsideOf); // _84
	virtual void outWaterCallback();                    // _88
	virtual bool isFlying()                             // _CC (weak)
	{
		return (mEvents.mFlags[0].typeView >> 2) & 1;
	}
	virtual void collisionCallback(CollEvent& coll);          // _EC
	virtual JAInter::Object* getJAIObject();                  // _F4
	virtual PSM::Creature* getPSCreature();                   // _F8
	virtual bool needShadow();                                // _138
	virtual void getLifeGaugeParam(LifeGaugeParam& settings); // _13C
	virtual void onStickStart(Creature* sticker);             // _158
	virtual void onStickEnd(Creature* sticker);               // _15C
	virtual bool stimulate(Interaction& interaction);         // _1A4
	virtual char* getCreatureName()                           // _1A8 (weak)
	{
		return EnemyInfoFunc::getEnemyName(getEnemyTypeID(), 0xFFFF);
	}
	virtual s32 getCreatureID() // _1AC (weak)
	{
		return mCreatureID;
	}
	// vtable 2 (MotionListener+self)
	// virtual void onKeyEvent(const SysShape::KeyEvent& event); - thunk _1B8
	virtual ~EnemyBase() { }                                             // _1BC (weak)
	virtual void birth(Vector3f& position, f32 faceDirection);           // _1C0
	virtual void setInitialSetting(EnemyInitialParamBase* settings) = 0; // _1C4
	virtual void update();                                               // _1C8
	virtual void doUpdate() = 0;                                         // _1CC
	virtual void doUpdateCommon();                                       // _1D0
	virtual void doUpdateCarcass();                                      // _1D4
	virtual void doAnimationUpdateAnimator();                            // _1D8
	virtual void doAnimationCullingOff();                                // _1DC
	virtual void doAnimationCullingOn();                                 // _1E0
	virtual void doAnimationStick();                                     // _1E4
	virtual void doSimulationCarcass(f32);                               // _1E8
	virtual void doDebugDraw(Graphics& gfx);                             // _1EC
	virtual void doSimpleDraw(Viewport* vp) { }                          // _1F0 (weak)
	virtual void doSimulationGround(f32 simSpeed);                       // _1F4
	virtual void doSimulationFlying(f32 simSpeed);                       // _1F8
	virtual void doSimulationStick(f32 simSpeed);                        // _1FC
	virtual void changeMaterial();                                       // _200
	virtual void getCommonEffectPos(Vector3f& effectPos);                // _204
	virtual Vector3f* getFitEffectPos();                                 // _208
	virtual SysShape::Model* viewGetShape();                             // _20C
	virtual void view_start_carrymotion();                               // _210
	virtual void view_finish_carrymotion();                              // _214
	virtual void viewStartPreCarryMotion();                              // _218
	virtual void viewStartCarryMotion();                                 // _21C
	virtual void viewOnPelletKilled();                                   // _220
	virtual f32 getCellRadius()                                          // _58 (weak)
	{
		return *static_cast<EnemyParmsBase*>(mParms)->mGeneral.mCellRadius();
	}
	virtual f32 getBodyRadius() // _54 (weak)
	{
		return *static_cast<EnemyParmsBase*>(mParms)->mGeneral.mPikminDamageRadius();
	}
	virtual f32 getFaceDir() // _64 (weak)
	{
		return mFaceDir;
	}
	virtual void setVelocity(Vector3f& velocity) // _68 (weak)
	{
		mCurrentVelocity = velocity;
	}
	virtual Vector3f getVelocity() // _6C (weak)
	{
		return mCurrentVelocity;
	}
	virtual void getVelocityAt(Vector3f& velSrc, Vector3f& velDest) // _184 (weak)
	{
		velSrc  = mCurrentVelocity;
		velDest = mCurrentVelocity;
	}
	virtual bool isTeki() // _7C (weak)
	{
		return true;
	}
	virtual Vector3f* getSound_PosPtr() // _100 (weak)
	{
		return &mPosition;
	}
	virtual Vector3f getOffsetForMapCollision() // _224 (weak)
	{
		return Vector3f(0.0f);
	}
	virtual void setParameters();          // _228
	virtual void initMouthSlots() { }      // _22C (weak)
	virtual void initWalkSmokeEffect() { } // _230 (weak)
	virtual bool inWater()                 // _8C (weak)
	{
		return (mWaterBox != nullptr);
	}
	virtual WalkSmokeEffect::Mgr* getWalkSmokeEffectMgr() // _234 (weak)
	{
		return nullptr;
	}
	virtual void onKeyEvent(const SysShape::KeyEvent& event); // _238 (weak)
	virtual bool injure();                                    // _23C
	virtual void setCollEvent(CollEvent& newEvent);           // _240
	virtual void getEfxHamonPos(Vector3f* pos)                // _244 (weak)
	{
		*pos = mPosition;
	}
	virtual void createInstanceEfxHamon();                  // _248
	virtual void updateEfxHamon();                          // _24C
	virtual void createEfxHamon();                          // _250
	virtual void fadeEfxHamon();                            // _254
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() = 0; // _258
	virtual MouthSlots* getMouthSlots()                     // _25C (weak)
	{
		return nullptr;
	}
	virtual void doGetLifeGaugeParam(LifeGaugeParam& settings);     // _260
	virtual void throwupItem();                                     // _264
	virtual void getThrowupItemPosition(Vector3f* throwupPosition); // _268
	virtual void getThrowupItemVelocity(Vector3f* throwupVelocity); // _26C
	virtual void throwupItemInDeathProcedure() { throwupItem(); }   // _270 (weak)
	virtual void setLODSphere(Sys::Sphere& sphere)                  // _274 (weak)
	{
		mCurLodSphere = sphere;
	}
	virtual void getLODSphere(Sys::Sphere& lodSphere) // _140 (weak)
	{
		lodSphere = mCurLodSphere;
	}
	virtual bool damageCallBack(Creature* source, f32 damage, CollPart* part);       // _278
	virtual bool pressCallBack(Creature* source, f32 damage, CollPart* part);        // _27C
	virtual bool flyCollisionCallBack(Creature* source, f32 damage, CollPart* part); // _280
	virtual bool hipdropCallBack(Creature* source, f32 damage, CollPart* part);      // _284
	virtual bool dropCallBack(Creature* source);                                     // _288
	virtual bool earthquakeCallBack(Creature* source, f32 bounceFactor);             // _28C
	virtual bool farmCallBack(Creature* source, f32 power);                          // _290
	virtual bool bombCallBack(Creature* source, Vector3f& direction, f32 damage);    // _294
	virtual bool eatWhitePikminCallBack(Creature* source, f32 damage);               // _298
	virtual bool dopeCallBack(Creature* source, int sprayType);                      // _29C
	virtual bool doDopeCallBack(Creature* source, int sprayType) { return true; }    // _2A0 (weak)
	virtual void doStartStoneState();                                                // _2A4
	virtual void doFinishStoneState();                                               // _2A8
	virtual f32 getDamageCoeStoneState()                                             // _2AC (weak)
	{
		return 1.5f;
	}
	virtual f32 getSound_CurrAnimFrame() // _108 (weak)
	{
		return mAnimator->getAnimator().mTimer;
	}
	virtual f32 getSound_CurrAnimSpeed() // _10C (weak)
	{
		return mAnimator->mSpeed;
	}
	virtual bool sound_culling() // _104 (weak)
	{
		bool culling = false;
		if (mEvents.mFlags[0].typeView & 0x2000) {
			if (!(mLod.mFlags & AILOD_FLAG_NEED_SHADOW) && !(mLod.mFlags & AILOD_FLAG_UNKNOWN4)) {
				culling = true;
			}
		}
		return culling;
	}
	virtual void doStartEarthquakeState(f32 yVelocityScale); // _2B0
	virtual void doFinishEarthquakeState();                  // _2B4
	virtual void doStartEarthquakeFitState();                // _2B8
	virtual void doFinishEarthquakeFitState();               // _2BC
	virtual void lifeRecover();                              // _2C0
	virtual void startCarcassMotion()                        // _2C4 (weak)
	{
		SysShape::MotionListener* listener = this;

		EnemyAnimatorBase* animator = mAnimator;
		animator->mFlags.typeView &= ~0x3;
		animator->mNormalizedTime = 1.0f;
		animator->getAnimator(0).startAnim(0, listener);

		disableEvent(0, EB_PS1 + EB_PS2 + EB_PS3 + EB_PS4);
		enableEvent(0, EB_PS1);

		if (isEvent(0, EB_PS1)) {
			int idx = getCurrAnimIndex();
			// SysShape::Animator anim      = mAnimator->getAnimator(0);
			SysShape::AnimInfo* info
			    = static_cast<SysShape::AnimInfo*>(mAnimator->getAnimator(0).mAnimMgr->mAnimInfo.mChild)->getInfoByID(idx);
			JAIAnimeFrameSoundData* file = info->mBasFile;

			if (file) {
				SysShape::KeyEvent* event1 = info->getAnimKeyByType(0);
				SysShape::KeyEvent* event2 = info->getAnimKeyByType(1);

				if (event1 != nullptr && event2) {
					f32 val1 = (f32)event1->mFrame;
					f32 val2 = (f32)event2->mFrame;
					mSoundObj->setAnime((JAIAnimeSoundData*)file, 1, val1, val2);
					return;
				}

				mSoundObj->setAnime((JAIAnimeSoundData*)file, 1, 0.0f, 0.0f);
				return;
			}

			mSoundObj->setAnime(nullptr, 1, 0.0f, 0.0f);
			return;
		}

		if (isEvent(0, EB_PS2)) {
			mSoundObj->setAnime((JAIAnimeSoundData*)-1, 1, 0.0f, 0.0f);
			return;
		}

		if (isEvent(0, EB_PS3)) {
			mSoundObj->setAnime((JAIAnimeSoundData*)-1, 1, 0.0f, 0.0f);
			return;
		}

		mSoundObj->setAnime(nullptr, 1, 0.0f, 0.0f);
	}
	virtual void setCarcassArg(PelletViewArg& settings); // _2C8
	virtual f32 getCarcassArgHeight()                    // _2CC (weak)
	{
		return mBoundingSphere.mRadius;
	}
	virtual bool doBecomeCarcass();                     // _2D0
	virtual void startWaitingBirthTypeDrop();           // _2D4
	virtual void finishWaitingBirthTypeDrop();          // _2D8
	virtual bool isFinishableWaitingBirthTypeDrop();    // _2DC
	virtual void doStartWaitingBirthTypeDrop();         // _2E0
	virtual void doFinishWaitingBirthTypeDrop();        // _2E4
	virtual void wallCallback(const MoveInfo& info) { } // _2E8 (weak)
	virtual f32 getDownSmokeScale();                    // _2EC
	virtual void doStartMovie() { }                     // _2F0 (weak)
	virtual void doEndMovie() { }                       // _2F4 (weak)

	// vtable 3 (PelletView)

	void addDamage(f32 damageAmt, f32 flickSpeed);

	void bounceProcedure(Sys::Triangle* triangle);

	// Collision with the map and platforms
	void collisionMapAndPlat(f32 timeStep);

	PSM::EnemyBase* createPSEnemyBase();
	void createEffects();
	void createBounceEffect(const Vector3f& position, f32 scale);
	void createDeadBombEffect();
	void createDropEffect(const Vector3f& position, f32 scale);
	void createSplashDownEffect(const Vector3f& position, f32 scale);
	void fadeEffects();

	void doEntryCarcass();
	void doEntryLiving();
	void doSimulationConstraint(f32 timeStep);
	void hardConstraintOn();
	void hardConstraintOff();
	void constraintOff();

	void finishDropping(bool lockToFloor);

	void deathProcedure();
	void gotoHell();

	bool isCullingOff();

	void startMotion();
	void startMotion(int animIdx, SysShape::MotionListener* mListener);
	void finishMotion();
	void stopMotion();
	bool isFinishMotion();
	bool isStopMotion();
	f32 getFirstKeyFrame();
	f32 getMotionFrame();
	f32 getMotionFrameMax();
	void setMotionFrame(f32 frame);

	int getCurrAnimIndex();
	void setAnimSpeed(f32 speed);
	void resetAnimSpeed();

	void setEmotionCaution();
	void setEmotionExcitement();
	void setEmotionNone();

	void setAnimMgr(SysShape::AnimMgr* animMgr);
	void setOtakaraCode(PelletMgr::OtakaraItemCode& code);
	void setPSEnemyBaseAnime();
	void setZukanVisible(bool updateTekiDeathInfo);

	void startBlend(int srcAnimIdx, int destAnimIdx, SysShape::BlendFunction* blendFunc, f32 frameRate, SysShape::MotionListener* listener);
	void endBlend();

	void show();
	void hide();

	void forceKillEffects();
	void deathMethod();

	int getStateID();
	bool isBeforeAppearState();
	void startStoneState();

	void scaleDamageAnim();
	void finishScaleDamageAnim();

	void updateSpheres();
	void getWaterSphere(Sys::Sphere* waterSphere);
	void updateWaterBox();

	void startMovie();
	void endMovie();

	bool isBirthTypeDropGroup();
	bool checkBirthTypeDropEarthquake();
	void setDroppingMassZero();
	void resetDroppingMassZero();

	void resetCollEvent();
	void becomeCarcass();
	void updateEffects();

	inline void setCreatureID(u8 idx) { mCreatureID = idx; }

	inline void enableEvent(int i, u32 flag) { mEvents.mFlags[i].typeView |= flag; }

	inline void disableEvent(int i, u32 flag) { mEvents.mFlags[i].typeView &= ~flag; }

	inline bool isEvent(int i, u32 flag) { return mEvents.mFlags[i].typeView & flag; }

	inline bool isDead() { return mHealth <= 0.0f; }

	inline void getPosition2D(Vector3f& pos) { pos = Vector3f(mPosition.x, 0.0f, mPosition.z); }

	inline bool isDropping()
	{ // needs a better name eventually, used in doSimulationGround
		return (isEvent(1, EB2_IsEarthquake) || isEvent(1, EB2_IsDropping));
	}

	inline f32 getAccelerationScale(f32 constraint)
	{
		return constraint / static_cast<EnemyParmsBase*>(mParms)->mCreatureProps.mProps.mAccel.mValue;
	}

	inline void getDistance2D(Vector3f& point, Vector2f& sep)
	{
		sep.x = mPosition.x - point.x;
		sep.y = mPosition.z - point.z;
	}

	inline f32 changeFaceDir(Vector3f& XYZ)
	{
		f32 approxSpeed;
		f32 rotSpeed;
		f32 rotAccel;
		f32 x;
		f32 z;

		EnemyParmsBase* parms = static_cast<EnemyParmsBase*>(mParms);
		rotSpeed              = parms->mGeneral.mMaxTurnAngle.mValue;
		rotAccel              = parms->mGeneral.mTurnSpeed.mValue;

		Vector3f pos = getPosition();
		x            = XYZ.x;
		z            = XYZ.z;

		f32 angleDist = angDist(_angXZ(x, z, pos.x, pos.z), getFaceDir());

		f32 limit   = (DEG2RAD * rotSpeed) * PI;
		approxSpeed = angleDist * rotAccel;
		if (FABS(approxSpeed) > limit) {
			approxSpeed = (approxSpeed > 0.0f) ? limit : -limit;
		}

		mFaceDir    = roundAng(approxSpeed + getFaceDir());
		mRotation.y = mFaceDir;
		return angleDist;
	}

	inline f32 changeFaceDir(Vector2f& XZ)
	{
		f32 approxSpeed;
		f32 rotSpeed;
		f32 rotAccel;
		f32 x;
		f32 z;

		EnemyParmsBase* parms = static_cast<EnemyParmsBase*>(mParms);
		rotSpeed              = parms->mGeneral.mMaxTurnAngle.mValue;
		rotAccel              = parms->mGeneral.mTurnSpeed.mValue;

		Vector3f pos = getPosition();
		x            = XZ.x;
		z            = XZ.y;

		f32 angleDist = angDist(_angXZ(x, z, pos.x, pos.z), getFaceDir());

		f32 limit   = (DEG2RAD * rotSpeed) * PI;
		approxSpeed = angleDist * rotAccel;
		if (FABS(approxSpeed) > limit) {
			approxSpeed = (approxSpeed > 0.0f) ? limit : -limit;
		}

		mFaceDir    = roundAng(approxSpeed + getFaceDir());
		mRotation.y = mFaceDir;
		return angleDist;
	}

	inline f32 changeFaceDir(Creature* target)
	{
		f32 approxSpeed;
		f32 rotSpeed;
		f32 rotAccel;

		EnemyParmsBase* parms = static_cast<EnemyParmsBase*>(mParms);
		rotSpeed              = parms->mGeneral.mMaxTurnAngle.mValue;
		rotAccel              = parms->mGeneral.mTurnSpeed.mValue;

		Vector3f targetPos = target->getPosition();
		Vector3f pos       = getPosition();

		f32 angleDist = angDist(angXZ(targetPos, pos), getFaceDir());

		f32 limit   = (DEG2RAD * rotSpeed) * PI;
		approxSpeed = angleDist * rotAccel;
		if (FABS(approxSpeed) > limit) {
			approxSpeed = (approxSpeed > 0.0f) ? limit : -limit;
		}

		mFaceDir    = roundAng(approxSpeed + getFaceDir());
		mRotation.y = mFaceDir;
		return angleDist;
	}

	inline f32 turnToTarget(Vector3f& XZ, f32 angLimit, f32 scale)
	{
		Vector3f pos       = getPosition();
		Vector3f targetPos = XZ;

		f32 angleDist = angDist(_angXZ(targetPos.x, targetPos.z, pos.x, pos.z), getFaceDir());
		angleDist *= scale;
		f32 limit = angLimit;
		if (FABS(angleDist) > limit) {
			angleDist = (angleDist > 0.0f) ? limit : -limit;
		}
		return angleDist;
	}

	inline f32 turnToTarget2(Vector3f& XZ, f32 scale, f32 angLimit)
	{
		Vector3f pos       = getPosition();
		Vector3f targetPos = XZ;

		f32 angleDist   = angDist(angXZ(targetPos.x, targetPos.z, pos), getFaceDir());
		f32 approxSpeed = angleDist * scale;
		f32 limit       = (DEG2RAD * angLimit) * PI;
		if (FABS(approxSpeed) > limit) {
			approxSpeed = boundVal(approxSpeed, limit);
		}

		mFaceDir    = roundAng(approxSpeed + getFaceDir());
		mRotation.y = mFaceDir;

		return angleDist;
	}

	inline f32 turnToTarget2_tamago(Vector3f& targetPos, f32 turnSpeed, f32 maxTurnAngle)
	{
		f32 angleDist = getAngDist2(targetPos);
		f32 angle     = clamp(angleDist * turnSpeed, PI * (DEG2RAD * maxTurnAngle));
		updateFaceDir(angle);

		return angleDist;
	}


	inline void updateFaceDir(f32 angle)
	{
		mFaceDir    = roundAng(angle + getFaceDir());
		mRotation.y = mFaceDir;
	}

	inline void updateFaceDir_tamago(f32 angle)
	{
		mFaceDir    = angle;
		mRotation.y = mFaceDir;
	}

	inline f32 turnToTargetNishi(Creature* target, f32 turnFactor, f32 maxTurnSpeed)
	{
		Vector3f targetPos = target->getPosition();
		Vector3f pos       = getPosition();

		f32 angleDist = angDist(_angXZ(targetPos.x, targetPos.z, pos.x, pos.z), getFaceDir());
		f32 turnSpeed = angleDist * turnFactor;
		f32 limit     = PI * (DEG2RAD * maxTurnSpeed);
		if (FABS(turnSpeed) > limit) {
			turnSpeed = (turnSpeed > 0.0f) ? limit : -limit;
		}

		updateFaceDir(turnSpeed);

		return angleDist;
	}

	inline void forceMovePosition(Vector3f offset) { mPosition += offset; }

	inline f32 turnToTargetMori(Vector3f& targetPos, f32 turnFactor, f32 maxTurnSpeed)
	{
		Vector3f pos = getPosition();

		f32 angleDist = angDist(angXZ(targetPos.x, targetPos.z, pos), getFaceDir());
		f32 turnSpeed = angleDist * turnFactor;
		f32 limit     = PI * (DEG2RAD * maxTurnSpeed);
		if (FABS(turnSpeed) > limit) {
			turnSpeed = (turnSpeed > 0.0f) ? limit : -limit;
		}

		updateFaceDir(turnSpeed);

		return angleDist;
	}

	inline bool checkDistAndAngle(Creature* target, f32 angle, f32 distRange, f32 angRange)
	{
		bool result = false;
		Vector3f sep;
		sep.x = target->getPosition().x - getPosition().x;
		sep.y = target->getPosition().y - getPosition().y;
		sep.z = target->getPosition().z - getPosition().z;
		if ((sep.x * sep.x + sep.y * sep.y + sep.z * sep.z < distRange * distRange) && FABS(angle) <= PI * (DEG2RAD * angRange)) {
			result = true;
		}
		return result;
	}

	inline f32 getDamageAnimFrac(f32 scale) { return (mDamageAnimTimer / scale); }

	inline f32 getSqrHomeRadius() const
	{
		f32 homeRad = static_cast<EnemyParmsBase*>(mParms)->mGeneral.mHomeRadius.mValue;
		return homeRad * homeRad;
	}

	inline efx::Arg createFXArg() { return efx::Arg(mPosition); }

	inline EnemyParmsBase::Parms& getParms() { return static_cast<EnemyParmsBase*>(mParms)->mGeneral; }

	inline bool isWithinHomeRadius() { return sqrDistanceXZ(mPosition, mHomePosition) < getSqrHomeRadius(); }

	inline f32 getSubmergedDepth() const { return *mWaterBox->getSeaHeightPtr() - mPosition.y; }

	inline Vector3f getTargetVelocity() { return mTargetVelocity; }
	inline void setTargetVelocity(const Vector3f& ref) { mTargetVelocity = ref; }

#pragma region Events
	inline void resetEvents()
	{
		mEvents.mFlags[0].clear();
		mEvents.mFlags[1].clear();
		mEventBuffer.mFlags[0].clear();
		mEventBuffer.mFlags[1].clear();
	}

	inline void restoreEvents()
	{
		mEvents.mFlags[0] = mEventBuffer.mFlags[0];
		mEvents.mFlags[1] = mEventBuffer.mFlags[1];
	}

	inline void backupEvents()
	{
		mEventBuffer.mFlags[0].typeView = mEvents.mFlags[0].typeView;
		mEventBuffer.mFlags[1].typeView = mEvents.mFlags[1].typeView;
	}

#pragma endregion

	inline bool isConstrained() { return (isEvent(0, EB_Constraint) || isEvent(0, EB_IsHardConstraint)); }

	// Creature: _000 - _178
	// MotionListener: _178 - _17C
	// ptr to PelletView: _17C
	EnemyMgrBase* mMgr;                         // _180
	EnemyAnimatorBase* mAnimator;               // _184
	EnemyAnimKeyEvent* mCurAnim;                // _188
	Vector3f mPosition;                         // _18C
	Vector3f mHomePosition;                     // _198
	Vector3f mRotation;                         // _1A4, mainly used for face dir on Y axis
	Vector3f mDamageAnimRotation;               // _1B0
	Vector3f mStunAnimRotation;                 // _1BC
	Vector3f mCurrentVelocity;                  // _1C8, impulse velocity
	Vector3f mTargetVelocity;                   // _1D4, simulation velocity (only used on simulation)
	BitFlagArray<u32, 2> mEvents;               // _1E0
	BitFlagArray<u32, 2> mEventBuffer;          // _1E8
	u8 mSfxEmotion;                             // _1F0, the 'emotion' used for bg music
	u8 mCreatureID;                             // _1F1
	u8 _1F2;                                    // _1F2
	bool mInPiklopedia;                         // _1F3
	int mStuckPikminCount;                      // _1F4
	f32 mScaleModifier;                         // _1F8
	f32 mFaceDir;                               // _1FC
	f32 mHealth;                                // _200
	f32 mMaxHealth;                             // _204
	f32 mInstantDamage;                         // _208
	f32 mToFlick;                               // _20C,
	f32 mDamageAnimTimer;                       // _210, timer of the damage animation
	f32 mStunAnimTimer;                         // _214, timer of the stun animation
	f32 mFriction;                              // _218, related to mass
	f32 mBitterTimer;                           // _21C, timer of the bitter spray stone state
	Sys::Sphere mBoundingSphere;                // _220
	Creature* mTargetCreature;                  // _230
	CollEvent mCollEvent;                       // _234
	Vector3f mEffectOffset;                     // _240
	EnemyStone::Obj* mEnemyStoneObj;            // _24C
	PelletMgr::OtakaraItemCode mPelletDropCode; // _250
	Pellet* mHeldPellet;                        // _254
	EnemyPelletInfo mPelletInfo;                // _258
	AILODParm mLodParm;                         // _264
	Sys::Sphere mCurLodSphere;                  // _270
	WaterBox* mWaterBox;                        // _280
	EnemyEffectNodeHamon* mEffectNodeHamon;     // _284
	Sys::Triangle* mWallTriangle;               // _288
	PSM::EnemyBase* mSoundObj;                  // _28C
	CNode mHamonEffectRoot;                     // _290 - treat as EnemyEffectNodeBase with EnemyEffectNodeHamon nodes
	f32 mExistTimer;                            // _2A8, how long cherry-spawned enemy has existed in 2P battle
	f32 mExistDuration;                         // _2AC, how long cherry-spawned enemy should exist in 2P battle
	s8 mDropGroup;                              // _2B0
	EnemyFSMState* mCurrentLifecycleState;      // _2B4
	EnemyBaseFSM::StateMachine* mLifecycleFSM;  // _2B8
	                                            // PelletView: _2BC - _2C8
};

struct EarthquakeStateArg : public StateArg {
	f32 mBounceFactor; // _00, weighting to scale vertical velocity by
};

namespace EnemyBaseFSM {
enum StateID {
	EBS_Drop = 0,
	EBS_DropPikmin,
	EBS_DropOlimar,
	EBS_DropTreasure,
	EBS_DropEarthquake,
	EBS_Appear,
	EBS_Living,
	EBS_Stone,
	EBS_Earthquake,
	EBS_Fit,
	EBS_DropAuto,
	EBS_Count, // 10
};

/**
 * Generic lifecycle state.
 */
struct State : public Game::EnemyFSMState {
	inline State(int stateID)
	    : EnemyFSMState(stateID)
	{
	}

	virtual void update(EnemyBase*) { }                          // _24 (weak)
	virtual void entry(EnemyBase*) { }                           // _28 (weak)
	virtual void simulation(EnemyBase*, f32) { }                 // _2C (weak)
	virtual void bounceProcedure(EnemyBase*, Sys::Triangle*) { } // _30 (weak)
	virtual void animation(EnemyBase*);                          // _34

	// _00 VTBL
	// _04 int stateID
	// _08 EnemyStateMachine* mStateMachine
	// _0C const char* mName
};

/**
 * Generic birth-by-dropping state.
 */
struct BirthTypeDropState : public State {
	inline BirthTypeDropState(int stateID)
	    : State(stateID)
	{
		mName = "BirthTypeDrop";
	}

	virtual void init(EnemyBase*, StateArg*);                  // _08
	virtual void cleanup(EnemyBase*);                          // _10
	virtual void update(EnemyBase*);                           // _24
	virtual void entry(EnemyBase*) { }                         // _28 (weak)
	virtual void simulation(EnemyBase*, f32) { }               // _2C (weak)
	virtual void animation(EnemyBase*) { }                     // _34 (weak)
	virtual bool isFinishableWaitingBirthTypeDrop(EnemyBase*); // _38
};

struct BirthTypeDropPikminState : public BirthTypeDropState {
	inline BirthTypeDropPikminState()
	    : BirthTypeDropState(EBS_DropPikmin)
	{
		mName = "BirthTypeDropPikmin";
	}

	virtual bool isFinishableWaitingBirthTypeDrop(EnemyBase*); // _38
};

struct BirthTypeDropOlimarState : public BirthTypeDropState {
	inline BirthTypeDropOlimarState()
	    : BirthTypeDropState(EBS_DropOlimar)
	{
		mName = "BirthTypeDropOlimar";
	}

	virtual bool isFinishableWaitingBirthTypeDrop(EnemyBase*); // _38
};

struct BirthTypeDropTreasureState : public BirthTypeDropState {
	inline BirthTypeDropTreasureState()
	    : BirthTypeDropState(EBS_DropTreasure)
	{
		mName = "BirthTypeDropTreasure";
	}

	virtual bool isFinishableWaitingBirthTypeDrop(EnemyBase*); // _38
};

struct BirthTypeDropEarthquakeState : public BirthTypeDropState {
	inline BirthTypeDropEarthquakeState()
	    : BirthTypeDropState(EBS_DropEarthquake)
	{
		mName = "BirthTypeDropEarthquake";
	}

	virtual bool isFinishableWaitingBirthTypeDrop(EnemyBase*); // _38
};

struct BirthTypeDropAutoState : public BirthTypeDropState {
	inline BirthTypeDropAutoState()
	    : BirthTypeDropState(EBS_DropAuto)
	{
		mName = "BirthTypeDropAuto";
	}

	virtual bool isFinishableWaitingBirthTypeDrop(EnemyBase*) { return true; }; // _38
};


/**
 * Birth-without-dropping state?
 */
struct AppearState : public State {
	inline AppearState()
	    : State(EBS_Appear)
	{
		mName = "Appear";
	}

	virtual void init(EnemyBase*, StateArg*);    // _08
	virtual void cleanup(EnemyBase*);            // _10
	virtual void update(EnemyBase*);             // _24
	virtual void entry(EnemyBase*);              // _28
	virtual void simulation(EnemyBase*, f32) { } // _2C (weak)
};

/**
 * Generic "alive" state.
 * @size = 0x10
 */

struct LivingState : public State {
	inline LivingState(int state = EBS_Living)
	    : State(state)
	{
		mName = "Living";
	}

	inline bool isConstrained(EnemyBase* enemy) { return (enemy->isEvent(0, EB_Constraint) || enemy->isEvent(0, EB_IsHardConstraint)); }

	virtual void update(EnemyBase*);           // _24
	virtual void entry(EnemyBase*);            // _28
	virtual void simulation(EnemyBase*, f32);  // _2C
	virtual void updateCullingOff(EnemyBase*); // _38
	virtual void updateAlways(EnemyBase*);     // _3C
};

/**
 * Bittered state.
 * @size = 0x10
 */
struct StoneState : public LivingState {
	inline StoneState()
	    : LivingState(EBS_Stone)
	{
		mName = "Stone";
	}

	virtual void init(EnemyBase*, StateArg*);                 // _08
	virtual void cleanup(EnemyBase*);                         // _10
	virtual void bounceProcedure(EnemyBase*, Sys::Triangle*); // _30
	virtual void updateCullingOff(EnemyBase*);                // _38
	virtual void updateAlways(EnemyBase*);                    // _3C
};

/**
 * @size = 0x14
 */
struct EarthquakeState : public LivingState {
	inline EarthquakeState()
	    : LivingState(EBS_Earthquake)
	    , mEarthquakeStepTimer(0)
	{
		mName = "Earthquake";
	}

	virtual void init(EnemyBase*, StateArg*);  // _08
	virtual void cleanup(EnemyBase*);          // _10
	virtual void updateCullingOff(EnemyBase*); // _38

	int mEarthquakeStepTimer; // _10
};

/**
 * @size = 0x24
 * FIT = Stunned
 */
struct FitState : public LivingState {
	inline FitState()
	    : LivingState(EBS_Fit)
	    , mEnemyPiyo()
	{
		mName = "Fit";
	}

	virtual void init(EnemyBase*, StateArg*);  // _08
	virtual void cleanup(EnemyBase*);          // _10
	virtual void updateCullingOff(EnemyBase*); // _38
	virtual void updateAlways(EnemyBase*);     // _3C

	efx::TEnemyPiyo mEnemyPiyo; // _10
};

/**
 * Generic lifecycle FSM that every teki has, often in addition to a more
 * specific FSM derived from Game::StateMachine.
 */
struct StateMachine : public Game::EnemyStateMachine {
	virtual void init(EnemyBase*);                  // _08
	virtual EnemyFSMState* getCurrState(EnemyBase*) // _1C (weak)
	{
		return mState;
	}
	virtual void setCurrState(EnemyBase* enemy, EnemyFSMState* state) // _20 (weak)
	{
		mState = static_cast<State*>(state);
	}
	virtual void update(EnemyBase*);          // _24
	virtual void entry(EnemyBase*);           // _28
	virtual void simulation(EnemyBase*, f32); // _2C
	virtual void animation(EnemyBase* enemy)  // _30 (weak)
	{
		mState->animation(enemy);
	}
	virtual void bounceProcedure(EnemyBase* enemy, Sys::Triangle* triangle) // _34 (weak)
	{
		mState->bounceProcedure(enemy, triangle);
	}

	State* mState; // _1C
};
} // namespace EnemyBaseFSM
} // namespace Game

// defined here to avoid include loop
namespace efx {
inline Arg::Arg(Game::EnemyBase* enemy) { mPosition = enemy->mPosition; }
} // namespace efx

#endif
