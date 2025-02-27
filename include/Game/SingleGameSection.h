#ifndef _GAME_SINGLEGAMESECTION_H
#define _GAME_SINGLEGAMESECTION_H

#include "DvdThreadCommand.h"
#include "Game/BaseGameSection.h"
#include "Game/gamePlayData.h"
#include "Game/gameStages.h"
#include "efx/TChasePos.h"
#include "id32.h"

namespace og {
namespace Screen {
struct DispMemberSMenuAll;
}
} // namespace og

namespace Game {
namespace SingleGame {
struct FSM;
struct GameState;
struct State;
} // namespace SingleGame


enum DemoTimers2 {
	DEMOTIMER_None                   = 0,
	DEMOTIMER_Piki_Seed_In_Ground    = 1, // plays if you dont pluck the first red pikmin in 10 seconds
	DEMOTIMER_Camera_Tutorial        = 2, // Entirely unused, the camera tutorial was meant to use it, but nothing starts its timer
	DEMOTIMER_Unlock_Switch_To_Louie = 3,
	DEMOTIMER_Unk6                   = 6,
	DEMOTIMER_YouAppearLost          = 7, // When you wait 3 minutes on day 1 after growing 15 reds before crushing the first bag
};


/**
 * @Size{0x278}
 */
struct SingleGameSection : public BaseGameSection {
	typedef Game::SingleGame::State StateType;

	SingleGameSection(JKRHeap*);

	virtual ~SingleGameSection();                                      // _08
	virtual bool doUpdate();                                           // _3C
	virtual void doDraw(Graphics& gfx);                                // _40
	virtual int getCurrFloor();                                        // _58 (weak)
	virtual bool isDevelopSection();                                   // _5C (weak)
	virtual void startMainBgm();                                       // _64
	virtual void section_fadeout();                                    // _68
	virtual void goNextFloor(ItemHole::Item*);                         // _6C
	virtual void goCave(ItemCave::Item*);                              // _70
	virtual void goMainMap(ItemBigFountain::Item*);                    // _74
	virtual u32 getCaveID();                                           // _78 (weak)
	virtual CourseInfo* getCurrentCourseInfo();                        // _7C (weak)
	virtual char* getCaveFilename();                                   // _84 (weak)
	virtual void playMovie_firstexperience(int, Creature*);            // _98
	virtual void playMovie_bootup(Onyon*);                             // _9C
	virtual void playMovie_helloPikmin(Piki*);                         // _A0
	virtual void enableTimer(f32, u32);                                // _A4
	virtual void disableTimer(u32);                                    // _A8
	virtual u32 getTimerType();                                        // _AC (weak)
	virtual void onMovieStart(MovieConfig*, u32, u32);                 // _B0
	virtual void onMovieDone(MovieConfig*, u32, u32);                  // _B4
	virtual void onMovieCommand(int);                                  // _B8
	virtual void gmOrimaDown(int);                                     // _D0
	virtual void gmPikminZero();                                       // _D4
	virtual void openCaveInMenu(ItemCave::Item*, int);                 // _D8
	virtual void openCaveMoreMenu(ItemHole::Item*, Controller*);       // _DC
	virtual void openKanketuMenu(ItemBigFountain::Item*, Controller*); // _E0
	virtual void on_setCamController(int);                             // _E4
	virtual void onInit();                                             // _F0
	virtual void onSetupFloatMemory();                                 // _120
	virtual void onSetSoundScene();                                    // _128
	virtual void onStartHeap();                                        // _12C
	virtual void onClearHeap();                                        // _130

	void clearCaveMenus();
	void clearCaveOtakaraEarningsAndDrops();
	void createFallPikmins();
	void flow_goto_title();
	void loadMainMapSituation();
	void newCaveOtakaraEarningsAndDrops();
	void saveCaveMore();
	void saveMainMapSituation(bool isSubmergedCastle);
	void setDispMemberSMenu(og::Screen::DispMemberSMenuAll&);
	void setupCaveGames();
	void setupMainMapGames();
	bool updateCaveMenus();
	void updateCaveScreen();
	void updateMainMapScreen();
	void drawCaveScreen();

	inline void setCurrState(StateType* state) { mCurrentState = state; }
	inline StateType* getCurrState() { return mCurrentState; }

	f32 mTimer;                                    // _174
	bool mTimerEnabled;                            // _178
	u32 mTimerType;                                // _17C
	u8 mOpenMenuFlags;                             // _180
	struct Game::ItemCave::Item* mCurrentCave;     // _184
	struct Game::ItemHole::Item* mHole;            // _188
	struct Game::ItemBigFountain::Item* mFountain; // _18C
	u32 _190;                                      // _190
	bool _194;                                     // _194
	char mCaveFilename[0x20];                      // _195
	u8 _1B5;                                       // _1B5, unknown
	DvdThreadCommand mDvdThread;                   // _1B8
	Delegate<Game::SingleGameSection>* _224;       // _224
	u8 _228;                                       // _228
	Game::CourseInfo* mCurrentCourseInfo;          // _22C
	ID32 mCaveID;                                  // _230
	bool mInCave;                                  // _23C
	u8 _23D;                                       // _23D
	bool mNeedTreasureCalc;                        // _23E
	Delegate<Game::SingleGameSection>* _240;       // _240
	efx::TChasePos* _244;                          // _244
	int mCurrentFloor;                             // _248
	Game::SingleGame::FSM* mFsm;                   // _24C
	Game::SingleGame::State* mCurrentState;        // _250
	KindCounter _254;                              // _254
	KindCounter _25C;                              // _25C
	KindCounter mOtakaraCounter;                   // _264
	KindCounter mItemCounter;                      // _26C
	u8 _274;                                       // _274
};
} // namespace Game

#endif
