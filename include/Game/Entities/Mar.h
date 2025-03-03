#ifndef _GAME_ENTITIES_MAR_H
#define _GAME_ENTITIES_MAR_H

#include "Game/EnemyStateMachine.h"
#include "Game/EnemyAnimatorBase.h"
#include "Game/EnemyParmsBase.h"
#include "Game/EnemyMgrBase.h"
#include "Game/EnemyBase.h"
#include "efx/TFusen.h"
#include "Sys/MatBaseAnimation.h"
#include "Sys/MatBaseAnimator.h"

/**
 * --Header for Puffy Blowhog (Mar)--
 */

namespace Game {
namespace Mar {
struct FSM;

struct Obj : public EnemyBase {
	Obj();

	//////////////// VTABLE
	virtual void onInit(CreatureInitArg* settings);         // _30
	virtual void onKill(CreatureKillArg* settings);         // _34
	virtual void doDirectDraw(Graphics& gfx);               // _50
	virtual void inWaterCallback(WaterBox* wb);             // _84 (weak)
	virtual void outWaterCallback();                        // _88 (weak)
	virtual void getShadowParam(ShadowParam& settings);     // _134
	virtual ~Obj() { }                                      // _1BC (weak)
	virtual void setInitialSetting(EnemyInitialParamBase*); // _1C4
	virtual void doUpdate();                                // _1CC
	virtual void doDebugDraw(Graphics&);                    // _1EC
	virtual void changeMaterial();                          // _200
	virtual Vector3f getOffsetForMapCollision();            // _224
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID();     // _258 (weak)
	virtual void getThrowupItemPosition(Vector3f*);         // _268
	virtual void getThrowupItemVelocity(Vector3f*);         // _26C
	virtual void throwupItemInDeathProcedure();             // _270 (weak)
	virtual void doStartStoneState();                       // _2A4
	virtual void doFinishStoneState();                      // _2A8
	virtual void doStartWaitingBirthTypeDrop();             // _2E0
	virtual void doFinishWaitingBirthTypeDrop();            // _2E4
	virtual f32 getDownSmokeScale();                        // _2EC (weak)
	virtual void doStartMovie();                            // _2F0
	virtual void doEndMovie();                              // _2F4
	virtual void setFSM(FSM*);                              // _2F8
	//////////////// VTABLE END

	void getHeadJointPos();
	void setHeightVelocity();
	void setRandTarget();
	void resetShadowOffset();
	void setShadowOffsetMax();
	void addShadowOffset();
	void subShadowOffset();
	void resetShadowRadius();
	void subShadowRadius();
	void updateFallTimer();
	void getFlyingNextState();
	void addPitchRatio();
	Piki* getSearchedPikmin();
	void isTargetLost();
	void isAttackable();
	void updateEmit();
	void getAttackPosition();
	void windTarget();
	void createEffect();
	void setupEffect();
	void startDeadEffect();
	void createSuckEffect();
	void startWindEffect();
	void finishWindEffect();
	void createDownEffect();
	void effectDrawOn();
	void effectDrawOff();

	// _00 		= VTBL
	// _00-_2BC	= EnemyBase
	FSM* mFsm;                     // _2BC
	f32 _2C0;                      // _2C0
	f32 mFallTimer;                // _2C4
	f32 mShadowOffset;             // _2C8
	f32 mShadowRadius;             // _2CC
	Vector3f mTargetPosition;      // _2D0
	Matrixf* _2DC;                 // _2DC
	Vector3f _2E0;                 // _2E0
	Vector3f _2EC;                 // _2EC
	Vector3f mAttackPosition;      // _2F8
	f32 _304;                      // _304
	u8 _308;                       // _308, unknown
	f32 _30C;                      // _30C, pitch ratio maybe?
	efx::TFusenDead* mEfxDead;     // _310
	efx::TFusenAirhit* mEfxAirhit; // _314
	efx::TFusenAir* mEfxAir;       // _318
	efx::TFusenSui* mEfxSui;       // _31C
	Sys::MatLoopAnimator* _320;    // _320, array of two animators
	                               // _324 = PelletView
};

struct Mgr : public EnemyMgrBase {
	Mgr(int objLimit, u8 modelType);

	// virtual ~Mgr();                                     // _58 (weak)
	virtual void createObj(int);                       // _A0
	virtual EnemyBase* getEnemy(int idx);              // _A4
	virtual void doAlloc();                            // _A8
	virtual SysShape::Model* createModel();            // _B0
	virtual void loadTexData();                        // _D0
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() // _AC (weak)
	{
		return EnemyTypeID::EnemyID_Mar;
	}

	// _00 		= VTBL
	// _00-_44	= EnemyMgrBase
	Sys::MatTexAnimation* mTexAnimation;       // _44
	Sys::MatTevRegAnimation* mTevRegAnimation; // _48
	Obj* mObj;                                 // _4C, array of Objs
};

struct Parms : public EnemyParmsBase {
	struct ProperParms : public Parameters {
		ProperParms()
		    : Parameters(nullptr, "EnemyParmsBase")
		    , mFp01(this, 'fp01', "���s����", 90.0f, 0.0f, 150.0f)   // 'standard flight height'
		    , mFp02(this, 'fp02', "�㏸�W��", 1.0f, 0.0f, 10.0f)         // 'rise factor'
		    , mFp03(this, 'fp03', "�󒆃E�F�C�g����", 3.0f, 0.0f, 10.0f) // 'air wait time'
		    , mFp10(this, 'fp10', "�n��E�F�C�g����", 3.0f, 0.0f, 10.0f) // 'ground wait time'
		    , mFp04(this, 'fp04', "�U����������", 3.0f, 0.0f, 10.0f)     // 'shake off time'
		    , mIp01(this, 'ip01', "�����Œ�s�L��", 10, 1, 50)           // 'falling minimum piki number'
		    , mFp05(this, 'fp05', "�㉺�̗h�ꑬ�x", 2.5f, 0.0f, 10.0f)   // 'vertical swing speed'
		    , mFp06(this, 'fp06', "�㉺�̗h�ꕝ", 5.0f, 0.0f, 10.0f)     // 'vertical swing width'
		{
		}

		Parm<f32> mFp01; // _804
		Parm<f32> mFp02; // _82C
		Parm<f32> mFp03; // _854
		Parm<f32> mFp10; // _87C
		Parm<f32> mFp04; // _8A4
		Parm<int> mIp01; // _8CC
		Parm<f32> mFp05; // _8F4
		Parm<f32> mFp06; // _91C
	};

	Parms() { }

	virtual void read(Stream& stream) // _08 (weak)
	{
		CreatureParms::read(stream);
		mGeneral.read(stream);
		mProperParms.read(stream);
	}

	// _00-_7F8	= EnemyParmsBase
	ProperParms mProperParms; // _7F8
};

struct ProperAnimator : public EnemyAnimatorBase {
	virtual ~ProperAnimator() { }                                   // _08 (weak)
	virtual void setAnimMgr(SysShape::AnimMgr* mgr);                // _0C
	virtual SysShape::Animator& getAnimator() { return mAnimator; } // _10 (weak)
	virtual SysShape::Animator& getAnimator(int idx);               // _14

	// _00 		= VTBL
	// _00-_10	= EnemyAnimatorBase
	SysShape::Animator mAnimator; // _10
};

/////////////////////////////////////////////////////////////////
// STATE MACHINE DEFINITIONS
struct FSM : public EnemyStateMachine {
	virtual void init(EnemyBase*); // _08

	// _00		= VTBL
	// _00-_1C	= EnemyStateMachine
};

struct State : public EnemyFSMState {
	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateAttack : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateChase : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateChaseInside : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateDead : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateFall : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateFlyFlick : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateGround : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateGroundFlick : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateLand : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateMove : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateTakeOff : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};

struct StateWait : public State {
	virtual void init(EnemyBase*, StateArg*); // _08
	virtual void exec(EnemyBase*);            // _0C
	virtual void cleanup(EnemyBase*);         // _10

	// _00		= VTBL
	// _00-_10 	= EnemyFSMState
};
/////////////////////////////////////////////////////////////////
} // namespace Mar
} // namespace Game

#endif
