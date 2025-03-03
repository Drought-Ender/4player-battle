#ifndef _GAME_VSGAME_VSGAME_H
#define _GAME_VSGAME_VSGAME_H

#include "Graphics.h"
#include "Vector3.h"
#include "stream.h"
#include "CNode.h"
#include "Game/PikiContainer.h"
#include "Game/StateMachine.h"
#include "Game/VsGameSection.h"
#include "Game/EnemyBase.h"
#include "Game/gameChallenge2D.h"
#include "Game/Navi.h"
#include "Game/PikiMgr.h"
#include "Game/MoviePlayer.h"
#include "efx/TNaviEffect.h"
#include "efx/TPk.h"

struct JUTTexture;
struct LightObj;

extern bool gTournamentMode;

namespace Game {
namespace ItemHole {
struct Item;
} // namespace ItemHole

struct MovieConfig;
struct Challenge2D_ResultInfo;

namespace VsGame {

extern int CardCount;

enum StateID {
	VGS_Title  = 0,
	VGS_Load   = 1,
	VGS_Game   = 2,
	VGS_VS     = 3,
	VGS_Result = 4,
	VGS_StateCount,
};

enum VsCaveInfoType {
	VSCAVEINFO_Default  = 0,
	VSCAVEINFO_Metal    = 1,
	VSCAVEINFO_Concrete = 2,
	VSCAVEINFO_Tsuchi   = 3,
};

enum LoseReasonFlags {
	VSLOSE_OrimaDown     = 0x1,
	VSLOSE_Extinction    = 0x2,
	VSLOSE_ColoredMarble = 0x4,
	VSLOSE_TIMEUP        = 0x10,
	VSLOSE_Marble        = 0x80,
	
};

enum VSPlayerColor {
	VSPLAYER_Red    = 0,
	VSPLAYER_Blue   = 1,
	VSPlayer_White  = 2,
	VSPlayer_Purple = 3
};

struct TekiNode : public CNode {
	inline TekiNode() { }
	virtual ~TekiNode() {}; // _08 (weak)

	// _00 		= VTBL
	// _00-_18	= CNode
	EnemyTypeID::EEnemyTypeID mId; // _18
	int _1C;                       // _1C
	int mNodeID;                   // _20
};

struct TekiMgr {
	TekiMgr();

	void entry(EnemyTypeID::EEnemyTypeID, int);
	TekiNode* getNode(int); // unused; inlined into birth
	bool birthable(int);    // unused
	EnemyBase* birth(int, Vector3f&, bool);
	EnemyBase* birth(int, Vector3f&, float);
	EnemyBase* birthFromSky(int, Vector3f&, float);
	int getEnemy(EnemyTypeID::EEnemyTypeID);
	EnemyTypeID::EEnemyTypeID getID(int); // unused

	// these elements were likely private
	TekiNode mNode; // _00
	int mNodeCount; // _24
};

enum eCardType { // official enum name
	PIKMIN_5          = 0,
	PIKMIN_10         = 1,
	ALL_FLOWER        = 2,
	PIKMIN_XLU        = 3,
	DOPE_BLACK        = 4,
	DOPE_RED          = 5,
	RESET_BEDAMA      = 6,
	TEKI_HANACHIRASHI = 7,
	TEKI_SARAI        = 8,
	TEKI_ROCK         = 9,
	TEKI_BOMBOTAKRA   = 10,
	TEKI_TANK         = 11,
	TEKI_FUEFUKI      = 12,
	ALL_PLUCK         = 13,
	PATH_BLOCK        = 14,
	TEKI_DEMON        = 15,
	TEKI_KUMA         = 16,
	TEKI_JELLYFLOAT   = 17,
	STUN_STORM        = 18,
	WARP_HOME         = 19,
	BOMB_STORM        = 20,
	TEKI_OTAKARA      = 21,
	TEKI_MITES        = 22,
	TEKI_BABY         = 23,
	TEKI_GREENBOMB    = 24,
	CARD_ID_COUNT,
	UNRESOLVED = 0xffff
};

struct CardSelector {
	CardSelector(int);
	~CardSelector() {
		delete[] mValues;
		delete[] mCumulative;
	}
	int getTotalWeight();
	int selectCard();

	inline void fixBrokenWeights() {
		for (int i = 0; i < mCount; i++) {
			if (mValues[i] < 0) mValues[i] = 0;
		}
	}

	int mCount;
	int* mValues;
	f32* mCumulative;
};

struct CardMgr {
	struct SlotMachine { // DO NOT EDIT THIS STRUCT, THERE ARE NOT POINTERS
		SlotMachine();

		void clear();
		void start();
		void startStop();
		void update();
		void updateAppear();
		void startZoomIn();
		void startZoomUse();
		void updateZoomIn();
		void updateZoomUse();

		bool dispCherryTarget(int user);

		bool equalTo(int);
		bool canJumpToCard(int card);

		int getNextCard(int);
		int getPrevCard(int);

		f32 mSpinAngle;     // _00
		int mCurrCardIndex; // _04
		int mPrevCardIndex; // _08
		f32 mSpinProgress;  // _0C
		f32 mSpinSpeed;     // _10
		f32 mSpinAccel;     // _14
		bool _18;           // _18
		int mCherryStock;   // _1C, cherry count
		int mSpinState;     // _20
		int mSelectedSlot;  // _24, pre-determined slot
		f32 _28;            // _28, unknown
		f32 mDecelerateTime;            // _2C
		u32 mAppearState;   // _30, unknown
		f32 mAppearValue;   // _34
		int mZoomState;            // _38
		f32 mZoominTimer;            // _3C, timer?
		f32 mZoomVal;            // _40
		f32 mZoomOther;            // _44
		f32 mZoomUseVal;            // _48
		int mSlotIndex;            // _4C, maybe currentSlotIndex?
		bool mZoomStarted;             // _50, unknown
		u8 mMachineCardSelected;             // _51
		f32 mSpinTimer;     // _54
		int mSlotID;        // _58
		int mPlayerIndex;   // _5C
		CardMgr* mCardMgr;  // _60
		int mPrevSelected;  // _64
		f32 _68;            // _68
		f32 _6C;            // _6C

		enum ESpinStates {
			SPIN_UNSTARTED      = 0,
			SPIN_WAIT_START     = 1,
			SPIN_START          = 2,
			SPIN_WAIT_MAX_SPEED = 3,
			SPIN_DECELERATE     = 4,
			SPIN_DECELERATE_END = 5,
			SPIN_DOWN_TO_CARD   = 6,
			SPIN_WAIT_CARD_STOP = 7,
			SPIN_UP_TO_CARD     = 8,
			SPIN_WAIT_CARD_ROLL = 9,
			SPIN_END            = 10
		};

		void Scissor(Graphics&, bool);

		enum EAppearStates { APPEAR_LEAVE = 0, APPEAR_AWAIT = 1, APPEAR_ENTER = 2, APPEAR_RESET = 3 };
	};

	CardMgr(VsGameSection*, TekiMgr*);

	void loadResource();
	void update();
	void clear();
	void draw(Graphics&);
	void stopSlot(int);
	bool usePlayerCard(int, TekiMgr*);
	void gotPlayerCard(int);
	void initDraw();
	void drawSlot(Graphics&, Vector3f&, SlotMachine&);

	void informMovieDone();

	SlotMachine* getSlotMachine(int i);

	Vector3f getSlotOrigin(int);
	Vector2f getLampPos(int, int);
	Vector2f getPlayerCard(int);
	void clearPlayerCard();

	JUTTexture* getTexture(eCardType);
	void vert(int);
	void norm(int);

	int mSlotNum;                  // _00, unknown
	JUTTexture** mSlotTextures;    // _04, slot textures?
	JUTTexture* mYButtonTexture;   // _08
	JUTTexture* mLampOnTexture;    // _0C
	JUTTexture* mLampOffTexture;   // _10
	JUTTexture* mHighlightTexture; // _14
	SlotMachine mSlotMachines[2];  // _18
	int _F8;                       // _F8
	Vector3f* _FC;                 // _FC, array of 0x100 vectors?
	Vector3f* _100;                // _100, array of 0x100 vectors?
	f32 _104;                      // _104
	LightObj* mLightObj;           // _108
	VsGameSection* mSection;       // _10C
	TekiMgr* mTekiMgr;             // _110
	bool mSlotsUpdated[4];
	SlotMachine mNewSlotMachines[2];
};

enum EMarbleFlags {
	MARBLEFLAG_Stage1_RoomOnly = 0x1,
	MARBLEFLAG_Stage2_RoomOnly = 0x2,
	MARBLEFLAG_Stage3_RoomOnly = 0x4,
	MARBLEFLAG_Random_RoomOnly = 0x8,
	MARBLEFLAG_4P_Stage1_RoomOnly = 0x10,
	MARBLEFLAG_4P_Stage2_RoomOnly = 0x20,
	MARBLEFLAG_4P_Stage3_RoomOnly = 0x40,
	MARBLEFLAG_4P_Random_RoomOnly = 0x80,
};

struct StageData : public CNode {
	StageData();

	virtual ~StageData() { } // _08 (weak)

	void read(Stream&);
	void write(Stream&);

	// _00 		= VTBL
	// _00-_18	= CNode
	PikiContainer mPikiContainer;  // _18
	char mCaveInfoFilename[64];    // _20, default = "caveinfo.txt"
	f32 mTimeLimit;                // _60
	int mStartNumBitter;           // _64
	int mStartNumSpicy;            // _68
	int mIndex2D;                  // _6C
	char mStageLayoutFilePath[64]; // _70
	int mStartNumYellowMarbles;    // _B0
	int mStartNumYellowMarblesVsFour;
	u8 mMarbleFlags;

	int mStartNumMiniMarbles;
	int mStartNumMiniMarblesFour;
};

struct StageList : public CNode {
	StageList();

	virtual ~StageList() { } // _08 (weak)

	void read(Stream&);
	void write(Stream&);
	StageData* getStageData(int);

	// _00 		= VTBL
	// _00-_18	= CNode
	StageData mStageData;
};

/////////////////////////////////////////////////////////////////
// STATE MACHINE DEFINITIONS
enum GameStateFlags {
	VSGS_Unk1  = 0x1,
	VSGS_Unk2  = 0x2,
	VSGS_Unk3  = 0x4,
	VSGS_Unk4  = 0x8,
	VSGS_Unk5  = 0x10,
	VSGS_Unk6  = 0x20,
	VSGS_Unk7  = 0x40,
	VSGS_Unk8  = 0x80,
	VSGS_Unk9  = 0x100,
	VSGS_Unk10 = 0x200,
	VSGS_Unk11 = 0x400,
	VSGS_Unk12 = 0x800,
	VSGS_Unk13 = 0x1000,
	VSGS_Unk14 = 0x2000,
	VSGS_Unk15 = 0x4000,
	VSGS_Unk16 = 0x8000,
};

struct FSM : public StateMachine<VsGameSection> {
	virtual void init(VsGameSection*);                    // _08
	virtual void transit(VsGameSection*, int, StateArg*); // _14

	void draw(VsGameSection*, Graphics&);
};

enum MarbleType {
	RED_OR_BLUE,
	YELLOW,
	MINI
};


struct State : public FSMState<VsGameSection> {
	inline State(int id)
	    : FSMState(id)
	{
	}

	virtual void draw(VsGameSection*, Graphics&) { }                      // _20 (weak)
	virtual void pre2dDraw(Graphics&, VsGameSection*) { }                 // _24 (weak)
	virtual void onOrimaDown(VsGameSection*, int) { }                     // _28 (weak)
	virtual void onMovieStart(VsGameSection*, MovieConfig*, u32, u32) { } // _2C (weak)
	virtual void onMovieDone(VsGameSection*, MovieConfig*, u32, u32) { }  // _30 (weak)
	virtual void onNextFloor(VsGameSection*, ItemHole::Item*) { }         // _34 (weak)
	virtual void on_section_fadeout(VsGameSection*) { }                   // _38 (weak)
	virtual bool goingToCave(VsGameSection*) { return false; }            // _3C (weak)
	virtual void onBattleFinished(VsGameSection*, int, bool) { }          // _40 (weak)
	virtual void onRedOrBlueSuckStart(VsGameSection*, int, MarbleType) { }      // _44 (weak)
	virtual void onBingoSuckStart(VsGameSection*, int, Pellet*) { }
	virtual bool isCardUsable(VsGameSection*) { return false; }           // _48 (weak)
	virtual void onYellowBedamaGet(VsGameSection*) { }
	virtual void onMiniBedamaGet(VsGameSection*) { }

	// _00     = VTBL
	// _00-_0C = FSMState
};

extern int gBedamaColor;

struct GameState : public State {
	GameState();

	virtual void init(VsGameSection*, StateArg*);                      // _08
	virtual void exec(VsGameSection*);                                 // _0C
	virtual void cleanup(VsGameSection*);                              // _10
	virtual void draw(VsGameSection*, Graphics&);                      // _20
	virtual void pre2dDraw(Graphics&, VsGameSection*);                 // _24
	virtual void onOrimaDown(VsGameSection*, int);                     // _28
	virtual void onMovieStart(VsGameSection*, MovieConfig*, u32, u32); // _2C
	virtual void onMovieDone(VsGameSection*, MovieConfig*, u32, u32);  // _30
	virtual void onNextFloor(VsGameSection*, ItemHole::Item*);         // _34
	virtual void on_section_fadeout(VsGameSection*)                    // _38 (weak)
	{
		setFlag(VSGS_Unk16);
	}
	virtual bool goingToCave(VsGameSection*);                     // _3C
	virtual void onBattleFinished(VsGameSection*, int, bool);     // _40
	virtual void onRedOrBlueSuckStart(VsGameSection*, int, MarbleType); // _44
	virtual void onBingoSuckStart(VsGameSection*, int, Pellet*);
	virtual bool isCardUsable(VsGameSection*);                    // _48
	virtual void drawStatus(Graphics&, VsGameSection*);           // _4C
	virtual void do_init(VsGameSection*);                         // _50

	virtual void onYellowBedamaGet(VsGameSection*);
	virtual void onMiniBedamaGet(VsGameSection*);

	void clearLoseCauses();
	void checkFindKeyDemo(VsGameSection*);
	void checkSMenu(VsGameSection*);
	void checkPikminZero(VsGameSection*);
	void open_GameChallenge(VsGameSection*, int);
	void update_GameChallenge(VsGameSection*);

	void checkVsPikminZero(VsGameSection*);
	void checkOrimaDown(VsGameSection*);
	void setDeathLose();

	bool isWinExtinction();
	int getExtinctionWinner();
	void onOrimaDownDone(int idx);

	inline void updateNavi(VsGameSection* section, int naviIndex)
	{
		if (naviIndex >= Game::gNaviNum) {
			return;
		}
		if (section->mGhostIconTimers[naviIndex] > 0.0f) {
			section->mGhostIconTimers[naviIndex] -= sys->mDeltaTime;

			Navi* navi = naviMgr->getAt(naviIndex);
			if (navi && section->mGhostIconTimers[naviIndex] <= 0.0f) {
				efx::TNaviEffect* naviEffect = navi->mEffectsObj;

				if (naviEffect->isFlag(efx::NAVIFX_IsSaved)) {
					naviEffect->mFlags = naviEffect->mSavedFlags;
					naviEffect->resetFlag(efx::NAVIFX_IsSaved);
				}

				bool inWater = naviEffect->isFlag(efx::NAVIFX_InWater);
				if (naviEffect->isFlag(efx::NAVIFX_InWater)) { // in water?
					naviEffect->setFlag(efx::NAVIFX_InWater);
					naviEffect->updateHamon_();

					if (!inWater) { // what is bro doing
						efx::createSimpleDive(naviEffect->mHamonPosition);
					}
				}

				if (naviEffect->isFlag(efx::NAVIFX_LightOn)) {
					naviEffect->createLight();
				}
			}

			pikiMgr->setVsXlu(getVsPikiColor(naviIndex), false);

		} else {
			pikiMgr->setVsXlu(getVsPikiColor(naviIndex), true);
		}
	}

	inline void setFlag(u16 flag) { mFlags.typeView |= flag; }

	inline void resetFlag(u16 flag) { mFlags.typeView &= ~flag; }

	inline bool isFlag(u16 flag) { return mFlags.typeView & flag; }

	inline void setLoseCause(int player, u32 flag) { mLoseCauses[player].typeView |= flag; }

	inline bool isLoseCause(int player, u32 flag) { return mLoseCauses[player].typeView & flag; }

	inline u8 getLoseCauses(int player) { return mLoseCauses[player].typeView; }

	inline void setLoseCause(BitFlag<u8>& player, u32 flag) { player.typeView |= flag; }

	inline bool getMarbleLoss(bool& loseRed, bool& loseBlue, bool& loseWhite, bool& losePurple)
	{
		bool moviePlayerActive = moviePlayer->mFlags & MoviePlayer::IS_ACTIVE;

		loseRed  = false;
		loseBlue = false;
		loseWhite = false;
		losePurple = false;

		bool marbleCollected = isLoseCause(VSPLAYER_Blue, VSLOSE_Marble) || isLoseCause(VSPLAYER_Red, VSLOSE_Marble) || isLoseCause(VSPlayer_White, VSLOSE_Marble) || isLoseCause(VSPlayer_Purple, VSLOSE_Marble);

		if (!moviePlayerActive && marbleCollected) {
			loseRed = true;
			loseBlue = true;
			loseWhite = true;
			losePurple = true;
		

			if (isLoseCause(VSPLAYER_Blue, VSLOSE_Marble)) {
				loseBlue = false;
			}

			if (isLoseCause(VSPLAYER_Red, VSLOSE_Marble)) {
				loseRed = false;
			}

			if (isLoseCause(VSPlayer_White, VSLOSE_Marble)) {
				loseWhite = false;
			}

			if (isLoseCause(VSPlayer_Purple, VSLOSE_Marble)) {
				losePurple = false;
			}
		}
	}

	void setWinMarbleColor(int teamId, int color);

	void vsTimeUp(VsGameSection* section);

	// _00     = VTBL
	// _00-_0C = State
	u32 _0C;                    // _0C
	Controller* mController;    // _10
	BitFlag<u16> mFlags;        // _14
	u8 _16;                     // _16
	f32 mTimer;                 // _18
	f32 mFloorExtendTimer;      // _1C
	f32 mDisplayTime;           // _20
	bool mHasKeyDemoPlayed;     // _24
	BitFlag<u8> mLoseCauses[4]; // _25
	int mWinColors[4];
	int mNaviStatus[4];
	int mOrimaDownState[4];
	bool mExtinctions[4];
	float mTimeLeft;
};

#define VS_TIMER_START_TIME (480.0f)
#define VS_TIMER_ADD_TIME (120.0f)

struct VSState : public GameState {
	VSState();

	virtual void do_init(VsGameSection*); // _50

	// _00     = VTBL
	// _00-_0C = State
};

struct LoadArg : public StateArg {
	inline LoadArg()
	    : _00(0)
	    , _04(0)
	    , _08(false)
	{
	}

	inline LoadArg(u32 a, int b, bool c)
	    : _00(a)
	    , _04(b)
	    , _08(c)
	{
	}

	u32 _00;  // _00, unknown
	int _04;  // _04, unknown
	bool _08; // _08
};

struct LoadState : public State {
	LoadState();

	virtual void init(VsGameSection*, StateArg*); // _08
	virtual void exec(VsGameSection*);            // _0C
	virtual void cleanup(VsGameSection*);         // _10
	virtual void draw(VsGameSection*, Graphics&); // _20

	void dvdLoad();

	// _00     = VTBL
	// _00-_0C = State
	f32 _0C;                                      // _0C
	f32 _14;                                      // _10
	Controller* mController;                      // _14
	VsGameSection* mSection;                      // _18
	bool _1C;                                     // _1C
	u32 _20;                                      // _20
	int _24;                                      // _24
	bool _28;                                     // _28
	Delegate<Game::VsGame::LoadState>* mDelegate; // _2C
	DvdThreadCommand mDvdThreadCommand;           // _30
	bool _9C;                                     // _9c
	f32 _A0;                                      // _A0
};

struct ResultArg : public StateArg {
	BitFlag<u8> mEndFlag; // _00, 0 if extinction/captain down/give up, 1 if normal end
};

struct ResultState : public State {
	enum ResultStage {
		VSRES_PrepareInfo = 0,
		VSRES_PrepareDisp = 1,
		VSRES_Display     = 2,
	};

	ResultState();

	virtual void init(VsGameSection*, StateArg*); // _08
	virtual void exec(VsGameSection*);            // _0C
	virtual void cleanup(VsGameSection*);         // _10
	virtual void draw(VsGameSection*, Graphics&); // _20

	void prepareMorimuraInfo(VsGameSection*);
	void dvdload();

	inline bool isNormalEnd() { return mEndFlags.typeView & 1; }

	// _00     = VTBL
	// _00-_0C = State
	f32 _0C;                                        // _0C
	Controller* mPlayer1Controller;                 // _10
	Controller* mPlayer2Controller;                 // _14
	u8 mResultStage;                                // _18
	JKRExpHeap* mExpHeap;                           // _1C
	JKRHeap* mHeap;                                 // _20
	Delegate<Game::VsGame::ResultState>* mDelegate; // _24
	int mPikminLeft;                                // _28
	int _2C;                                        // _2C
	int mPokoTimeScore;                             // _30
	BitFlag<u8> mEndFlags;                          // _34, 0 if pikmin extinction/captain down/given up
	Challenge2D_ResultInfo* mResultInfo;            // _38
};

struct TitleArg : public StateArg {
	u8 _00; // _00, unknown
};

struct TitleState : public State {
	enum TitleStage {
		VSTITLE_PrepareInfo = 0,
		VSTITLE_PrepareDisp = 1,
		VSTITLE_Display     = 2,
	};

	TitleState();

	virtual void init(VsGameSection*, StateArg*); // _08
	virtual void exec(VsGameSection*);            // _0C
	virtual void cleanup(VsGameSection*);         // _10
	virtual void draw(VsGameSection*, Graphics&); // _20

	void dvdload();
	void execChallenge(VsGameSection*);
	void execVs(VsGameSection*);

	inline int getChallengeStageNum() { return 30; }

	inline int getVsStageNum() { return mSection->mVsStageList->mStageData.getChildCount(); }

	// _00     = VTBL
	// _00-_0C = State
	f32 _0C;                                       // _0C
	u8 mTitleStage;                                // _10
	JKRExpHeap* mExpHeap;                          // _14
	JKRHeap* mHeap;                                // _18
	Delegate<Game::VsGame::TitleState>* mDelegate; // _1C
	int _20;                                       // _20
	int mCaveInfoType;                             // _24
	int mStageNum;                                 // _28
	int _2C;                                       // _2C
	Controller* mPlayer1Controller;                // _2C
	Controller* mPlayer2Controller;                // _30
	VsGameSection* mSection;                       // _38
	Challenge2D_TitleInfo* mChallengeTitleInfo;    // _3C
	Vs2D_TitleInfo* mVsTitleInfo;                  // _40
};
/////////////////////////////////////////////////////////////////
} // namespace VsGame
} // namespace Game

#endif
