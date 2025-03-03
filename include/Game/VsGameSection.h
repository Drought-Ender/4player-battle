#ifndef _GAME_VSGAMESECTION_H
#define _GAME_VSGAMESECTION_H

#include "types.h"
#include "Game/BaseGameSection.h"
#include "Game/ChallengeGame.h"
#include "Vector3.h"
#include "VSFifo.h"
#include "Game/Entities/ItemBigFountain.h"
#include "Game/Entities/ItemHole.h"
#include "Game/BingoMgr.h"
#include "FourPlayer.h"

struct Controller;

int GetEditNum();

namespace Game {
struct PikiContainer;
struct MovieConfig;

namespace ItemHole {
struct Item;
} // namespace ItemHole

namespace ItemBigFountain {
struct Item;
} // namespace ItemBigFountain

namespace VsGame {
struct TekiMgr;
struct CardMgr;
struct StageData;
struct StageList;
struct State;
} // namespace VsGame

typedef f32 VsWeights[2]; // delegations

struct VsGameSection : public BaseGameSection {
	typedef VsGame::State StateType;

	struct DropCardArg {
		VsWeights mMinDists; // _00
		VsWeights mMaxDists; // _04
	};

	VsGameSection(JKRHeap*, bool);

	virtual ~VsGameSection();                                          // _08
	virtual bool doUpdate();                                           // _3C
	virtual void doDraw(Graphics& gfx);                                // _40
	virtual bool sendMessage(GameMessage&);                            // _50
	virtual void pre2dDraw(Graphics&);                                 // _54
	virtual int getCurrFloor();                                        // _58
	virtual void addChallengeScore(int);                               // _60
	virtual void startMainBgm();                                       // _64
	virtual void section_fadeout();                                    // _68
	virtual void goNextFloor(ItemHole::Item*);                         // _6C
	virtual bool challengeDisablePelplant(); /*{ return false; }*/     // _80 (weak)
	virtual bool player2enabled(); /*{ return true; }*/                // _134 (weak)
	virtual char* getCaveFilename(); /*{ return mCaveInfoFilename; }*/ // _84 (weak)
	virtual char* getEditorFilename(); /*{ return mEditFilename; }*/   // _88 (weak)
	virtual int getVsEditNumber(); /*{ return mEditNumber; }*/         // _8C (weak)
	virtual void onMovieStart(MovieConfig*, u32, u32);                 // _B0
	virtual void onMovieDone(MovieConfig*, u32, u32);                  // _B4
	virtual void gmOrimaDown(int);                                     // _D0
	virtual void gmPikminZero();                                       // _D4
	virtual void openCaveMoreMenu(ItemHole::Item*, Controller*);       // _DC
	virtual void openKanketuMenu(ItemBigFountain::Item*, Controller*); // _E0
	virtual void onInit();                                             // _F0
	virtual void onSetupFloatMemory();                                 // _120
	virtual void postSetupFloatMemory();                               // _124
	virtual void onSetSoundScene();                                    // _128
	virtual void onClearHeap();                                        // _130

	void setupBedamaUse(const char* name);

	void calcVsScores();
	void clearCaveMenus();
	void clearGetCherryCount();
	void clearGetDopeCount();
	void createFallPikmins(PikiContainer&, int);
	void createRedBlueBedamas(Vector3f&);
	void createVsPikmins();
	void createYellowBedamas(int);
	void dropCard(DropCardArg&);
	int& getGetCherryCount(int);
	int& getGetDopeCount(int, int);
	void initCardGeneration();
	void initCardPellets();
	void initPlayData();
	void loadChallengeStageList();
	void loadVsStageList();
	void updateCardGeneration();
	bool updateCaveMenus();
	void useCard();

	void SetupCourseinfo();

	void updateFancyCam();
	Creature* fancyCamLookForTarget();
	f32 fancyCamCalcIntrest(Creature*);

	Pellet* createCardPellet();

	void killAllPiki(int color);

	inline void setCurrState(StateType* state) { mCurrentState = state; }
	inline StateType* getCurrState() { return mCurrentState; }

	static int mRedWinCount;
	static int mBlueWinCount;
	static int mWhiteWinCount;
	static int mPurpleWinCount;
	static int mDrawCount;
	static int mNaviWinCounts[4];

#define YELLOW_MARBLE_COUNT 13

#define MINI_MARBLE_COUNT 77

	void killNearestP4Marbles();

	bool mIsVersusMode;                            // _174
	VSFifo* mVsFifo;                               // _178
	StateMachine<Game::VsGameSection>* mFsm;       // _17C
	VsGame::State* mCurrentState;                  // _180
	DvdThreadCommand mDvdThreadCommand;            // _184
	f32 mGhostIconTimers[4];                       // _1F0
	u8 mMenuFlags;                                 // _1F8
	struct ItemHole::Item* mHole;                  // _1FC
	struct ItemBigFountain::Item* mFountain;       // _200
	bool mIsMenuRunning;                           // _204
	bool _205;                                     // _205
	int mDeadPikiCount;                            // _208 - pikmin spawn queue
	ChallengeGame::StageList* mChallengeStageList; // _20C
	VsGame::StageList* mVsStageList;               // _210
	PikiContainer mContainer1;                     // _214
	PikiContainer mContainer2;                     // _21C
	char mCaveInfoFilename[128];                   // _248
	char mEditFilename[128];                       // _2A4
	int mCurrentFloor;                             // _324
	int mEditNumber;                               // _328
	VsGame::TekiMgr* mTekiMgr;                     // _32C
	VsGame::CardMgr* mCardMgr;                     // _330
	ChallengeGame::StageData* mChallengeStageData; // _334
	int mChallengeStageNum;                        // _338
	VsGame::StageData* mVsStageData;               // _33C
	int mVsStageNum;                               // _340
	int mOlimarHandicap;                           // _344
	int mLouieHandicap;                            // _348
	int mWhiteHandicap;
	int mPurpleHandicap;
	int mVsWinner;                              // _34C
	f32 mPikminRatio;                           // _350
	f32 mPikminCountTimer;                      // _354
	f32 mRedBlueYellowScore[4];                 // _358
	f32 mCherryScore[4];                        // _360
	f32 mMinCherryScore[4];                     // _368
	f32 mYellowScore[4];                        // _370
	f32 mRedBlueScore[4];                       // _378
	Pellet* mMarbleRedBlue[4];                  // _380
	Pellet* mMarbleYellow[YELLOW_MARBLE_COUNT]; // _388
	int mPokoCount;                             // _3BC
	f32 mTimeLimit;                             // _3C0
	int mCardCount;                             // _3C4
	f32 mSpawnTimer;                            // _3C8
	int mMaxCherries;                           // _3CC
	Pellet** mCherryArray;                      // _3D0
	int mDispMarbleCounts[4];                   // _3D4
	int mRealMarbleCounts[4];                   // _3DC
	int mGetDopeCount[4][2];
	// mini marbles
	int mDispMiniCounts[4];
	int mRealMiniCounts[4];

	Pellet* mMarbleMini[MINI_MARBLE_COUNT];
	u32 mMiniBedamaRemainingCount;
	bool mHasMiniBedamas;

	VsGame::BingoMgr* mBingoMgr;
};

// vsGameSize__4Game
const static int vsGameSize = sizeof(VsGameSection);

} // namespace Game

Game::VsGameSection* GetVsGameSection() { return static_cast<Game::VsGameSection*>(Game::gameSystem->mSection); }

int SaveEditNum(int);

#endif
