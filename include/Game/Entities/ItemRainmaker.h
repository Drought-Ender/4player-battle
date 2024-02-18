#ifndef _GAME_ENTITIES_ITEMRAINMAKER_H
#define _GAME_ENTITIES_ITEMRAINMAKER_H

#include "BaseParm.h"
#include "Game/BaseItem.h"
#include "Game/EnemyParmsBase.h"
#include "Game/TSoundEvent.h"
#include "Game/gameGenerator.h"
#include "Game/itemMgr.h"
#include "Parameters.h"

namespace Game {
namespace ItemRainmaker {
struct Item;

/**
 * @fabricated
 */
enum StateID {
	RainState_Normal  = 0,
	RainState_Damaged = 1,
	RainState_Dead    = 2,
	RAINMAKER_STATE_COUNT, // 3
};

/**
 * @size{0x1C}
 */
struct FSM : public ItemFSM<Item> {
	virtual void init(Item*); // _08

	// _00     = VTBL
	// _00-_1C = ItemFSM
};

struct State : public ItemState<Item> {
	inline State(int stateID)
	    : ItemState(stateID)
	{
	}

	virtual void onDamage(Item*, f32, Creature*) { } // _20

	// _00     = VTBL
	// _00-_0C = ItemState
	char* mName; // _0C
};

/**
 * @size{0x10}
 */
struct NormalState : public State {
	inline NormalState()
	    : State(RainState_Normal)
	{
	}

	virtual void init(Item*, StateArg*);                       // _08
	virtual void exec(Item*);                                  // _0C
	virtual void cleanup(Item*);                               // _10
	virtual void onDamage(Item*, f32, Creature*);              // _20
	virtual void onKeyEvent(Item*, const SysShape::KeyEvent&); // _24

	// _00     = VTBL
	// _00-_10 = State
};

/**
 * @size{0x14}
 */
struct DamagedState : public State {
	inline DamagedState()
	    : State(RainState_Damaged)
	{
	}

	virtual void init(Item*, StateArg*);                       // _08
	virtual void exec(Item*);                                  // _0C
	virtual void cleanup(Item*);                               // _10
	virtual void onDamage(Item*, f32, Creature*);              // _20
	virtual void onKeyEvent(Item*, const SysShape::KeyEvent&); // _24

	// _00     = VTBL
	// _00-_10 = State
};

/**
 * @size{0x14}
 */
struct DeadState : public State {
	inline DeadState()
	    : State(RainState_Dead)
	{
	}

	virtual void init(Item*, StateArg*);                       // _08
	virtual void exec(Item*);                                  // _0C
	virtual void cleanup(Item*);                               // _10
	virtual void onDamage(Item*, f32, Creature*);              // _20
	virtual void onKeyEvent(Item*, const SysShape::KeyEvent&); // _24

	// _00     = VTBL
	// _00-_10 = State
};

struct RainmakerParms : public CreatureParms {
	struct Parms : public Parameters {
		inline Parms()
		    : Parameters(nullptr, "Rainamker::Parms")
		    , mHealth(this, 'p000', "ƒ‰ƒCƒt", 100.0f, 1.0f, 60000.0f) // 'life'
		{
		}

		Parm<f32> mHealth; // _E8, p000
	};

	RainmakerParms() { }

	virtual void read(Stream& input) // _00
	{
		mRainmakerParms.read(input);
	}

	// _00-_D8 = CreatureParms
	// _D8		 = VTBL
	Parms mRainmakerParms; // _DC
};

/**
 * @size{0x1F8}
 */
struct Item : public FSMItem<Item, FSM, State> {
	Item();

	// vtable 1
	virtual void constructor();                          // _2C
	virtual void onInit(CreatureInitArg* settings);      // _30
	virtual void doSave(Stream&);                        // _E0
	virtual void doLoad(Stream&);                        // _E4
	virtual char* getCreatureName() { return "Rainmaker"; } // _1A8 (weak)

	// vtable 2
	virtual void doAI();                                  // _1C8
	virtual bool interactAttack(InteractAttack&);         // _1E0
	virtual bool getVectorField(Sys::Sphere&, Vector3f&); // _204
	virtual f32 getWorkDistance(Sys::Sphere&);            // _208
	virtual void updateBoundSphere();                     // _210
	virtual void onSetPosition();                         // _21C

	f32 getWorkRadius();

	void addDamage(u8 color, f32 damage);

	// _00      = VTBL
	// _00-_1EC = WorkItem
	f32 mHealth;       // _1EC
	f32 mDamage;
    u8 mColorOwner;
};

/**
 * @size{0x94}
 */
struct Mgr : public TNodeItemMgr {
	Mgr();

	// vtable 1
	virtual void onLoadResources();                                       // _48
	virtual u32 generatorGetID() { return 'rain'; }                       // _58 (weak)
	virtual BaseItem* generatorBirth(Vector3f&, Vector3f&, GenItemParm*); // _5C

	// vtable 2
	virtual BaseItem* doNew() { return new Item(); } // _A0 (weak)
	virtual ~Mgr() { }                               // _B8 (weak, thunked at _00)
	virtual BaseItem* birth();                       // _BC (Yes, TNodeItemMgr::birth() isn't virtual, but this is. Deal with it.)

	// _00     = VTBL 1
	// _30     = VTBL 2
	// _00-_88 = TNodeItemMgr
	RainmakerParms* mParms; // _88
};

extern Mgr* mgr;
} // namespace ItemRainmaker
} // namespace Game

#endif
