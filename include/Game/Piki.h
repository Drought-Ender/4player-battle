#ifndef _GAME_PIKI_H
#define _GAME_PIKI_H

#include "JSystem/JAudio/JAI/JAInter/Object.h"
#include "JSystem/JUtility/TColor.h"

#include "PSM/Piki.h"

#include "Game/FakePiki.h"
#include "Game/StateMachine.h"

namespace efx {
struct Context;
struct TPkEffect;
} // namespace efx

namespace PikiAI {
struct Brain;
struct ActTransportArg;
struct Action;
} // namespace PikiAI

namespace Sys {
struct Sphere;
} // namespace Sys

namespace SysShape {
struct AnimInfo;
struct Joint;
} // namespace SysShape

namespace Game {
struct Navi;
struct MoviePlayer;
struct ShadowParam;
struct Interaction;
struct Piki;
struct PikiState;
struct PikiParms;

typedef enum EPikiKind {
	NullColor           = -1,
	Blue                = 0,
	Red                 = 1,
	Yellow              = 2,
	OnyonCount          = 2,
	Purple              = 3,
	White               = 4,
	LastStoredPikiColor = White,
	AllPikmin           = 5,
	Bulbmin             = 5,
	Carrot              = 6,
	PikiColorCount,
} EPikiKind;

typedef enum EPikiHappa {
	Leaf   = 0,
	Bud    = 1,
	Flower = 2,
	PikiGrowthStageCount,

	Bud_Red    = 3,
	Flower_Red = 4,
	PikiHappaCount
} EPikiHappa; // Aka headtype

typedef enum EMovieUserCommands {
	ForceOnionPikis = 100, // Calls enterAllPikis and forceEnterPikis based on moviePlayer flags
	EnterCave       = 102, // Going into cave via the hole
	ExitCave        = 103, // Exit using fountain
	RemoveShadow    = 104,
	StopFX          = 105,
	ResetFX         = 106,
	AddShadow       = 107
} EMovieUserCommands;

struct PikiInitArg : public CreatureInitArg {
	inline PikiInitArg(int stateID)
	    : mLeader(nullptr)
	    , mState(stateID)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "PikiInitArg";
	}

	// _00 VTBL
	int mState;        // _04, state to start in
	Creature* mLeader; // _08
};

struct PikiKillArg : public CreatureKillArg {
	inline PikiKillArg(int p1)
	    : CreatureKillArg(p1)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "PikiKillArg";
	}

	// _00		 = VTBL
	// _00-_08 = CreatureKillArg
};

struct PikiFSM : public StateMachine<Piki> {
	virtual void init(Piki*);                    // _08
	virtual void transit(Piki*, int, StateArg*); // _14

	void transitForce(Piki*, int, StateArg*);

	// _00			= VTBL
	// _00-_1C	= StateMachine
	int mStateID; // _1C, state ID?
};

struct Piki : public FakePiki {
	typedef PikiState StateType;
	
	struct InvokeAIFreeArg {
		InvokeAIFreeArg(u8 a, u8 b)
		    : _00(a)
		    , _01(b)
		{
		}

		u8 _00;
		u8 _01;
	};

	Piki();

	inline bool isSearchable()
	{
		bool result = false;
		if (isPikmin() && isAlive() && !isStickToMouth()) {
			result = true;
		}

		return result;
	}

	// vtable 1 (Creature)
	virtual bool deferPikiCollision() { return true; }              // _20 (weak)
	virtual void onInit(CreatureInitArg* settings);                 // _30
	virtual void onKill(CreatureKillArg* settings);                 // _34
	virtual void doAnimation();                                     // _3C
	virtual void doDirectDraw(Graphics& gfx);                       // _50
	virtual void inWaterCallback(WaterBox* wb);                     // _84
	virtual void outWaterCallback();                                // _88
	virtual bool isAlive();                                         // _A8
	virtual void bounceCallback(Sys::Triangle* tri);                // _E8
	virtual void collisionCallback(CollEvent& event);               // _EC
	virtual void platCallback(PlatEvent& event);                    // _F0
	virtual JAInter::Object* getJAIObject();                        // _F4
	virtual PSM::Creature* getPSCreature();                         // _F8
	virtual void on_movie_begin(bool shouldResetAnims);             // _110
	virtual void on_movie_end(bool shouldResetAnims);               // _114
	virtual void movieStartAnimation(u32 animIdx);                  // _118
	virtual void movieStartDemoAnimation(SysShape::AnimInfo* info); // _11C
	virtual void movieSetTranslation(Vector3f& dest, f32 faceDir);  // _124
	virtual bool movieGotoPosition(Vector3f& dest);                 // _12C
	virtual void movieUserCommand(u32 command,
	                              MoviePlayer* curPlayer); // _130, check EMoviePlayerCommands enum for possible values
	virtual void getShadowParam(ShadowParam& settings);    // _134
	virtual void getLODSphere(Sys::Sphere& lodSphere);     // _140
	virtual void onStickStartSelf(Creature* c);            // _160
	virtual void onStickEndSelf(Creature* c);              // _164
	virtual bool ignoreAtari(Creature* toIgnore);          // _190
	virtual bool stimulate(Interaction& data);             // _1A4
	virtual char* getCreatureName() { return "pikmin"; }   // _1A8 (weak)
	virtual s32 getCreatureID() { return mMgrIndex; }      // _1AC (weak)
	// vtable 2 (MotionListener + FakePiki + self)
	virtual int getDownfloorMass();           // _1BC
	virtual bool isPikmin();                  // _1C0
	virtual void doColorChange();             // _1C4
	virtual void doDebugDL();                 // _1C8
	virtual void update();                    // _1CC
	virtual void wallCallback(Vector3f& pos); // _204
	virtual void startMotion(int anim1Idx, int anim2Idx, SysShape::MotionListener* ml1,
	                         SysShape::MotionListener* ml2);  // _208
	virtual void onKeyEvent(const SysShape::KeyEvent& event); // _20C
	virtual void do_updateLookCreature();                     // _214
	virtual void onSetPosition();                             // _218
	virtual bool isWalking();                                 // _21C

	void attachRadar(bool);
	bool canVsBattle();
	void changeHappa(int);
	void changeShape(int);
	void checkInvokeAI(bool);
	void clearCurrAction();
	void clearDope();
	bool doped();
	void extendDopeTime();
	bool gasInvicible();
	f32 getAttackDamage();
	f32 getBaseScale();
	PikiAI::Action* getCurrAction();
	int getCurrActionID();
	int getFormationSlotID();
	f32 getPelletCarryPower();
	f32 getSpeed(f32);
	f32 getSpeed(f32, f32);
	int getStateID();
	f32 getThrowHeight();
	Piki* getVsBattlePiki();
	int graspSituation_Fast(Creature**);
	int graspSituation(Creature**);
	void initColor();
	bool invokeAI();
	bool invokeAI(CollEvent*, bool);
	bool invokeAI(PlatEvent*);
	bool invokeAIFree(InvokeAIFreeArg&);
	bool isMyPikmin(Creature*);
	bool isTekiFollowAI();
	bool isThrowable();
	bool might_bury();
	void setActTransportArg(PikiAI::ActTransportArg&);
	void setDopeEffect(bool);
	void setFreeLightEffect(bool);
	void setGasInvincible(u8);
	void setPastel(bool);
	void setSpeed(f32, Vector3f&, f32);
	void setSpeed(f32, Vector3f&);
	void setTekiKillID(int);
	bool startDope(int);
	void startSound(Creature*, u32, bool);
	void startSound(Creature*, u32, PSGame::SeMgr::SetSeId);
	void startSound(u32, bool);
	void startSound(u32, PSGame::SeMgr::SetSeId);
	bool surviveDayEnd();
	void updateGasInvincible();
	void updateDope();
	void updateColor();

	void updateBulbminMaterial();
	static void updateBulbminModel(SysShape::Model* model, u16 bulbminAffil);

	bool canAttackPiki(Piki*);

	inline PikiParms* getParms() { return static_cast<PikiParms*>(mParms); }
	inline u16 getKind() { return (u16)mPikiKind; }
	inline u16 getHappa() { return (u16)mHappaKind; }

	u16 getVsKind();

	inline efx::TPkEffect* getEffectObj() { return mEffectsObj; }

	inline void setCurrState(StateType* state) { mCurrentState = state; }
	inline StateType* getCurrState() { return mCurrentState; }

	static Color4 pikiColors[PikiColorCount + 1];
	static Color4 pikiColorsCursor[PikiColorCount + 1];

	bool isInvisible();

	// _000			 = VTBL
	// _000-_24C = FakePiki
	PSM::Piki* mSoundObj;             // _250
	f32 mTargetLookTimer;             // _254
	efx::TPkEffect* mEffectsObj;      // _258
	Vector3f _25C;                    // _25C
	SysShape::Joint* mHappaJoint3;    // _268
	Vector3f _26C;                    // _26C
	SysShape::Joint* mHappaJoint1;    // _278
	efx::Context* mEffectsContext;    // _27C
	u8 _280[4];                       // _280
	s16 mIsDoped;                     // _284
	u16 mBulbminTime;
	f32 mDopeTime;                    // _288
	PikiFSM* mFsm;                    // _28C
	PikiState* mCurrentState;         // _290
	PikiAI::Brain* mBrain;            // _294
	UpdateContext mPikiUpdateContext; // _298
	s16 mTekiKillID;                  // _2A4
	u8 mGasInvincible;                // _2A6
	Color4 _2A7;                      // _2A7
	Color4 _2AB;                      // _2AB
	Color4 mPikiColor;                // _2AF
	f32 mColorFloat;                  // _2B4
	u8 mPikiKind;                     // _2B8,  aka Piki kind (Blue, Yellow, Red, etc.)
	u8 mHappaKind;                    // _2B9, aka Happa kind (leaf, bud, flower)
	u8 mBulbminAffiliation;
	SysShape::Model* mLeafModel;      // _2BC
	int mMgrIndex;                    // _2C0
	Navi* mNavi;                      // _2C4
};
} // namespace Game

#endif
