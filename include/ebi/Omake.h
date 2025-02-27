#ifndef _EBI_OMAKE_H
#define _EBI_OMAKE_H

#include "types.h"
#include "ebi/Screen/TScreenBase.h"
#include "ebi/Screen/TOmake.h"
#include "Game/StateMachine.h"

struct Controller;

namespace ebi {
namespace Omake {
struct TMgr;

struct FSMStateMachine : public Game::StateMachine<TMgr> {
	virtual void init(TMgr*); // _08

	// _00     = VTBL
	// _00-_1C = Game::StateMachine
};

struct FSMState : public Game::FSMState<TMgr> {
	inline FSMState(int stateID); // likely

	virtual void init(TMgr*, Game::StateArg*);    // _08 (weak)
	virtual void exec(TMgr*);                     // _0C (weak)
	virtual void do_init(TMgr*, Game::StateArg*); // _20 (weak)
	virtual void do_exec(TMgr*);                  // _24 (weak)

	// _00     = VTBL
	// _00-_0C = Game::FSMState
};

struct FSMState_CardEScreen : public FSMState {
	inline FSMState_CardEScreen(); // likely

	virtual void do_init(TMgr*, Game::StateArg*); // _20
	virtual void do_exec(TMgr*);                  // _24

	// _00     = VTBL
	// _00-_0C = FSMState
};

struct FSMState_OmakeScreen : public FSMState {
	inline FSMState_OmakeScreen(); // likely

	virtual void do_init(TMgr*, Game::StateArg*); // _20
	virtual void do_exec(TMgr*);                  // _24

	// _00     = VTBL
	// _00-_0C = FSMState
};

struct FSMState_SelectGame : public FSMState {
	inline FSMState_SelectGame(); // likely

	virtual void do_init(TMgr*, Game::StateArg*); // _20
	virtual void do_exec(TMgr*);                  // _24

	// _00     = VTBL
	// _00-_0C = FSMState
};

struct TMgr {
	typedef FSMState StateType;
	TMgr();

	void draw();
	void forceQuit();
	int getMovieID();
	int getStateID();
	void goEnd_();
	bool isFinish();
	bool isMovieState();
	bool isTouchAnyKey_();
	void loadResource();
	void newCardEMgrAndTask();
	void restartFromMovieState();
	void start();
	void update();

	inline void setControllers(Controller* control)
	{
		mController = control;
		mOmake.setController(control);
		mOmakeCardE.mInput = control;
		mOmakeGame.setController(control);
	}

	inline void setCurrState(StateType* state) { mCurrentState = state; }
	inline StateType* getCurrState() { return mCurrentState; }

	Controller* mController;              // _000
	u8 _004[4];                           // _004
	ebi::Screen::TOmake mOmake;           // _008
	ebi::Screen::TOmakeCardE mOmakeCardE; // _468
	ebi::Screen::TOmakeGame mOmakeGame;   // _5DC
	bool mIsFinished;                     // _890
	u32 _894;                             // _894, both unused values?
	u32 _898;                             // _898
	FSMStateMachine mStateMachine;        // _89C
	FSMState* mCurrentState;              // _8B8
};
} // namespace Omake
} // namespace ebi

#endif
