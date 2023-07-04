#include "Dolphin/rand.h"
#include "efx/TEnemyApsmoke.h"
#include "Game/Cave/RandMapMgr.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Entities/PelletOtakara.h"
#include "Game/Farm.h"
#include "Game/GameConfig.h"
#include "Game/gameGenerator.h"
#include "Game/gameGeneratorCache.h"
#include "Game/GameMessage.h"
#include "Game/gamePlayData.h"
#include "Game/gameStages.h"
#include "Game/gameStat.h"
#include "Game/GameSystem.h"
#include "Game/MoviePlayer.h"
#include "Game/Navi.h"
#include "Game/NaviParms.h"
#include "Game/PikiMgr.h"
#include "Game/rumble.h"
#include "Game/shadowMgr.h"
#include "Game/SingleGame.h"
#include "Game/TimeMgr.h"
#include "Game/VsGame.h"
#include "JSystem/JUtility/JUTGraphFifo.h"
#include "PSGame/PikScene.h"
#include "PSSystem/PSGame.h"
#include "Screen/Game2DMgr.h"
#include "Radar.h"
#include "utilityU.h"
#include "VsOtakaraName.h"
#include "nans.h"

#include "FourPlayer.h"
#include "Game/Entities/ItemTreasure.h"
#include "Game/generalEnemyMgr.h"
#include "Game/gamePlayData.h"

namespace Game {
namespace VsGame {

static const char someVsArray[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const char vsName[]      = "VsGameSection";

/*
 * --INFO--
 * Address:	801C0DF8
 * Size:	0000D0
 */
void FSM::init(VsGameSection* section)
{
	create(VGS_StateCount);
	registerState(new TitleState);
	registerState(new LoadState);
	registerState(new GameState);
	registerState(new VSState);
	registerState(new ResultState);
}

/*
 * --INFO--
 * Address: ........
 * Size:    000038
 * --UNUSED--
 */
void FSM::draw(VsGameSection* section, Graphics& gfx) { static_cast<State*>(mStates[0])->draw(section, gfx); }

/*
 * --INFO--
 * Address:	801C0ECC
 * Size:	000020
 */
void FSM::transit(VsGameSection* section, int state, StateArg* arg) { StateMachine<VsGameSection>::transit(section, state, arg); }
} // namespace VsGame

int VsGameSection::mRedWinCount;
int VsGameSection::mBlueWinCount;
int VsGameSection::mWhiteWinCount;
int VsGameSection::mPurpleWinCount;
int VsGameSection::mDrawCount;

int VsGameSection::mNaviWinCounts[4] = {0, 0, 0, 0};


/*
 * --INFO--
 * Address:	801C0EEC
 * Size:	0000FC
 */

VsGameSection::VsGameSection(JKRHeap* heap, bool gameMode)
    : BaseGameSection(heap)
    , mMenuFlags(0)
{
	mIsVersusMode          = gameMode;
	_205                   = true;
	mChallengeStageNum     = 0;
	mVsStageNum            = 0;
	mVsWinner              = -1;
	mLouieHandicap         = 2;
	mOlimarHandicap        = 2;
	mWhiteHandicap         = 2;
	mPurpleHandicap        = 2;
	for (int i = 0; i < 4; i++)
	{
		mRealMarbleCounts[i] = 0;
		mDispMarbleCounts[i] = 0;
	}
	
	mEditNumber            = -2;
	mVsFifo                = nullptr;

	if (gGameConfig.mParms.mVsFifo.mData > 0) {
		size_t size = gGameConfig.mParms.mVsFifo.mData * KILOBYTE_BYTECOUNT;
		mVsFifo     = new VSFifo(size);
		mVsFifo->becomeCurrent();
		GXSetGPFifo(mVsFifo->mFifo);
	}
	OSReport("Memory Size %p\n", *(int*)(0x80000028));
}

/*
 * --INFO--
 * Address:	801C0FE8
 * Size:	0000CC
 */
VsGameSection::~VsGameSection()
{
	if (mVsFifo) {
		GXSaveCPUFifo(mVsFifo->mFifo);
		while (VSFifo::isGPActive())
			;
		GXDrawDone();
		GXInitFifoPtrs(JUTGraphFifo::sCurrentFifo->mFifo, JUTGraphFifo::sCurrentFifo->mBase, JUTGraphFifo::sCurrentFifo->mBase);
		GXSetCPUFifo(JUTGraphFifo::sCurrentFifo->mFifo);
		GXSetGPFifo(JUTGraphFifo::sCurrentFifo->mFifo);
	}
}

} // namespace Game

/*
 * --INFO--
 * Address:	801C10B4
 * Size:	00005C
 * TODO: should be weak
 */
bool VSFifo::isGPActive()
{
	GXGetGPStatus(&mGpStatus[0], &mGpStatus[1], &mGpStatus[2], &mGpStatus[3], &mGpStatus[4]);
	return !mGpStatus[2];
}

namespace Game {

/*
 * --INFO--
 * Address:	801C1110
 * Size:	000034
 */
void VsGameSection::section_fadeout() { mState->on_section_fadeout(this); }

/*
 * --INFO--
 * Address:	801C1148
 * Size:	000090
 */
void VsGameSection::startMainBgm()
{
	PSSystem::SceneMgr* sceneMgr = PSSystem::getSceneMgr();
	sceneMgr->checkScene();
	sceneMgr->mScenes->mChild->startMainSeq();
}

/*
 * --INFO--
 * Address:	801C11D8
 * Size:	00020C
 */
void VsGameSection::onInit()
{
	mPikminRatio        = 0.0f;
	mPikminCountTimer   = 0.5f;
	mGhostIconTimers[1] = 0.0f;
	mGhostIconTimers[0] = 0.0f;
	mGhostIconTimers[2] = 0.0f;
	mGhostIconTimers[3] = 0.0f;

	clearGetDopeCount();
	clearGetCherryCount();

	if (mIsVersusMode) {
		gameSystem->mMode = GSM_VERSUS_MODE;
	} else {
		gameSystem->mMode = GSM_ONE_PLAYER_CHALLENGE;
	}

	gameSystem->mIsInCave = true;
	_11C                  = 0;
	mHole                 = nullptr;
	mPokoCount            = 0;
	mIsMenuRunning        = false;

	sprintf(mCaveInfoFilename, "caveinfo.txt");
	sprintf(mEditFilename, "random");
	setupFixMemory();

	mChallengeStageList = new ChallengeGame::StageList();
	addGenNode(mChallengeStageList);
	mVsStageList = new VsGame::StageList();
	addGenNode(mVsStageList);
	loadChallengeStageList();
	loadVsStageList();

	mFsm = new VsGame::FSM();
	mFsm->init(this);
	initPlayData();
	mFsm->start(this, VsGame::VGS_Title, nullptr);

	mCurrentFloor          = 0;
	mRedBlueYellowScore[1] = 0.0f;
	mRedBlueYellowScore[0] = 0.0f;
	mYellowScore[1]        = 0.0f;
	mYellowScore[0]        = 0.0f;
	mCherryScore[1]        = 0.0f;
	mCherryScore[0]        = 0.0f;
	mMinCherryScore[1]     = 0.0f;
	mMinCherryScore[0]     = 0.0f;
	mRedBlueScore[1]       = 0.0f;
	mRedBlueScore[0]       = 0.0f;
	mMarbleRedBlue[1]      = nullptr;
	mMarbleRedBlue[0]      = nullptr;

	Radar::mgr = new Radar::Mgr();

	for (int i = 0; i < YELLOW_MARBLE_COUNT; i++) {
		mMarbleYellow[i] = nullptr;
	}
}

/*
 * --INFO--
 * Address:	801C13E4
 * Size:	000034
 */
void StateMachine<VsGameSection>::start(VsGameSection* section, int stateID, StateArg* arg)
{
	section->mState = nullptr;
	transit(section, stateID, arg);
}

/*
 * --INFO--
 * Address:	801C1418
 * Size:	000008
 */
int VsGameSection::getCurrFloor() { return mCurrentFloor; }

/*
 * --INFO--
 * Address:	801C1420
 * Size:	0001B8
 */
bool VsGameSection::doUpdate()
{
	if (mIsMenuRunning) {
		mIsMainActive = false;
		return false;
	}

	mFsm->exec(this);

	if (gameSystem->isVersusMode()) {

		int redPikmins  = GameStat::getMapPikmins(1) - (mOlimarHandicap - 3);
		int bluePikmins = GameStat::getMapPikmins(0) - (mLouieHandicap - 3);
		if (redPikmins < 0) {
			redPikmins = 1;
		}
		if (bluePikmins < 0) {
			bluePikmins = 1;
		}
		if (!redPikmins || !bluePikmins) {
			if (!redPikmins) {
				mPikminCountTimer = 1.0f;
			} else if (!bluePikmins) {
				mPikminCountTimer = 0.0f;
			}

		} else {
			if (bluePikmins > redPikmins) {
				mPikminRatio = (f32)bluePikmins / (f32)redPikmins;
			} else {
				mPikminRatio = (f32)redPikmins / (f32)bluePikmins;
			}

			mPikminCountTimer = log(mPikminRatio, 50.0);

			if (redPikmins < bluePikmins) {
				mPikminCountTimer = -mPikminCountTimer;
			}
		}
	}

	return mIsMainActive;
}

/*
 * --INFO--
 * Address:	801C15D8
 * Size:	00003C
 */
void VsGameSection::pre2dDraw(Graphics& gfx)
{
	if (mState) {
		mState->pre2dDraw(gfx, this);
	}
}

/*
 * --INFO--
 * Address:	801C1618
 * Size:	000050
 */
void VsGameSection::doDraw(Graphics& gfx)
{
	if (!mIsMenuRunning && mState) {
		mState->draw(this, gfx);
	}
}

/*
 * --INFO--
 * Address:	801C1668
 * Size:	0001DC
 */
void VsGameSection::onSetSoundScene()
{
	PSGame::CaveFloorInfo floorInfo;

	if (gameSystem->isChallengeMode()) {
		floorInfo.mSceneType = PSGame::SceneInfo::CHALLENGE_MODE;
		floorInfo._40        = getCurrFloor();
		floorInfo._49        = mChallengeStageNum;
	} else {
		floorInfo.mSceneType = PSGame::SceneInfo::TWO_PLAYER_BATTLE;
		floorInfo._40        = mVsStageNum;
	}

	floorInfo.mAlphaType = static_cast<RoomMapMgr*>(mapMgr)->mFloorInfo->mParms.mFloorAlphaType.mValue;
	floorInfo.mBetaType  = 0; // hardcoded mBetaType to 0; ignores floorinfo f012 setting

	if (!gameSystem->isMultiplayerMode()) {
		floorInfo.setStageFlag(PSGame::SceneInfo::SCENEFLAG_Unk0, PSGame::SceneInfo::SFBS_1);
	} else {
		floorInfo.setStageFlag(PSGame::SceneInfo::SCENEFLAG_Unk1, PSGame::SceneInfo::SFBS_1);
	}

	setDefaultPSSceneInfo(floorInfo);
	PSSystem::SceneMgr* sceneMgr = PSSystem::getSceneMgr();
	static_cast<PSGame::PikSceneMgr*>(sceneMgr)->newAndSetCurrentScene(&floorInfo);
	sceneMgr = PSSystem::getSceneMgr();
	sceneMgr->checkScene();
	sceneMgr->mScenes->mChild->scene1stLoadSync();
	naviMgr->createPSMDirectorUpdator();
}

/*
 * --INFO--
 * Address:	801C1844
 * Size:	00005C
 */
void VsGameSection::initPlayData()
{
	playData->reset();
	playData->setDevelopSetting(true, true);
	playData->mNaviLifeMax[0] = naviMgr->mNaviParms->mNaviParms.mMaxHealth.mValue;
	playData->mNaviLifeMax[1] = naviMgr->mNaviParms->mNaviParms.mMaxHealth.mValue;
}

/*
 * --INFO--
 * Address:	801C18A0
 * Size:	000168
 */

void VsGameSection::onSetupFloatMemory()
{

	Farm::farmMgr = nullptr;
	mTekiMgr      = new VsGame::TekiMgr();

	mTekiMgr->entry(EnemyTypeID::EnemyID_Hanachirashi, 4);
	mTekiMgr->entry(EnemyTypeID::EnemyID_Sarai, 4);
	mTekiMgr->entry(EnemyTypeID::EnemyID_Rock, 12);
	mTekiMgr->entry(EnemyTypeID::EnemyID_BombOtakara, 2);
	mTekiMgr->entry(EnemyTypeID::EnemyID_Tank, 2);
	mTekiMgr->entry(EnemyTypeID::EnemyID_Wtank, 2);
	mTekiMgr->entry(EnemyTypeID::EnemyID_Gtank, 2);
	mTekiMgr->entry(EnemyTypeID::EnemyID_Mtank, 2);
	mTekiMgr->entry(EnemyTypeID::EnemyID_Tobi, 20);

	mCardMgr      = new VsGame::CardMgr(this, mTekiMgr);
	mCardMgr->loadResource();
	const char* marbles[] = { VsOtakaraName::cBedamaRed, VsOtakaraName::cBedamaBlue, VsOtakaraName::cBedamaYellow, VsOtakaraName::cBedamaPurple, VsOtakaraName::cBedamaWhite };

	for (int i = 0; i < ARRAY_SIZE(marbles); i++) {

		PelletInitArg initArg;
		PelletList::cKind cKind;

		PelletConfig* pelletConfig = PelletList::Mgr::getConfigAndKind(const_cast<char*>(marbles[i]), cKind);

		JUT_ASSERTLINE(904, pelletConfig, "zannenn\n"); // 'disappointing'

		initArg._10             = pelletConfig->mParams.mIndex;
		initArg.mTextIdentifier = pelletConfig->mParams.mName.mData;
		initArg.mPelletType     = cKind;
		pelletMgr->setUse(&initArg);
	}
}

/*
 * --INFO--
 * Address:	801C1A08
 * Size:	0000A0
 */
void VsGameSection::postSetupFloatMemory()
{
	if (gameSystem->isVersusMode()) {
		mRedBlueYellowScore[1] = 0.0f;
		mRedBlueYellowScore[0] = 0.0f;
		mMarbleRedBlue[1]      = nullptr;
		mMarbleRedBlue[0]      = nullptr;
		Vector3f position      = Vector3f(0.0f);
		createRedBlueBedamas(position);

		for (int i = 0; i < YELLOW_MARBLE_COUNT; i++) {
			mMarbleYellow[i] = nullptr;
		}

		createYellowBedamas(7);
		initCardPellets();
	}

	BaseGameSection::postSetupFloatMemory();
}

/*
 * --INFO--
 * Address:	801C1AA8
 * Size:	000020
 */
void VsGameSection::onClearHeap()
{
	if (gameSystem->isVersusMode()) {
		mCherryArray = nullptr;
		mMaxCherries = 0;
	}
}

/*
 * --INFO--
 * Address:	801C1AC8
 * Size:	0000B0
 */
void VsGameSection::loadChallengeStageList()
{
	JKRDvdRipper::EAllocDirection EAlloc = JKRDvdRipper::ALLOC_DIR_BOTTOM;
	JKRExpandSwitch expandSwitch         = JKRExpandSwitch();
	void* loadRam                        = JKRDvdRipper::loadToMainRAM(
        ((gGameConfig.mParms.mKFesVersion.mData) ? "/user/Matoba/challenge/kfes-stages.txt" : "/user/Matoba/challenge/stages.txt"), nullptr,
        expandSwitch, nullptr, nullptr, EAlloc, nullptr, nullptr, nullptr);
	if (!loadRam) {
		return;
	}
	RamStream ram(loadRam, -1);
	ram.resetPosition(1, 1);
	mChallengeStageList->read(ram);
}

/*
 * --INFO--
 * Address:	801C1B78
 * Size:	000098
 */
void VsGameSection::loadVsStageList()
{
	JKRDvdRipper::EAllocDirection EAlloc = JKRDvdRipper::ALLOC_DIR_BOTTOM;
	JKRExpandSwitch expandSwitch         = JKRExpandSwitch();
	void* loadRam = JKRDvdRipper::loadToMainRAM("/user/abe/vs/stages.txt", nullptr, expandSwitch, nullptr, nullptr, EAlloc, nullptr,
	                                            nullptr, nullptr);
	if (!loadRam) {
		return;
	}

	RamStream ram(loadRam, -1);
	ram.resetPosition(true, 1);
	mVsStageList->read(ram);
}

/*
 * --INFO--
 * Address:	801C1C10
 * Size:	000044
 */
void VsGameSection::gmOrimaDown(int arg)
{
	if (mState) {
		mState->onOrimaDown(this, arg);
	}
}

/*
 * --INFO--
 * Address:	801C1C58
 * Size:	000004
 */
void VsGameSection::gmPikminZero() { }

/*
 * --INFO--
 * Address:	801C1C5C
 * Size:	00003C
 */
void VsGameSection::goNextFloor(ItemHole::Item* hole) { mState->onNextFloor(this, hole); }

/*
 * --INFO--
 * Address:	801C1C9C
 * Size:	0001D8
 */
void VsGameSection::openCaveMoreMenu(ItemHole::Item* hole, Controller* controller)
{
	if (mState->goingToCave(this)) {
		return;
	}

	if (gameSystem->isMultiplayerMode() && controller) {
		Screen::gGame2DMgr->setGamePad(controller);
	} else {
		Screen::gGame2DMgr->setGamePad(mControllerP1);
	}

	og::Screen::DispMemberCaveMore cave;
	int mePikis = GameStat::mePikis;
	if (mePikis > 0) {
		cave.mPikiInDanger = true;
		int map_pikis      = GameStat::getMapPikmins(-1);
		if (mePikis == map_pikis) {
			cave.mCantProceed = true;
		} else {
			cave.mCantProceed = false;
		}

	} else {
		cave.mCantProceed  = false;
		cave.mPikiInDanger = false;
	}

	bool open = Screen::gGame2DMgr->open_CaveMoreMenu(cave);
	if (open) {
		mHole = hole;
		gameSystem->setPause(true, "op-c-more", 3);
		gameSystem->setMoviePause(true, "op-c-more");
	}
}

/*
 * --INFO--
 * Address:	801C1E7C
 * Size:	0001B0
 */
void VsGameSection::openKanketuMenu(ItemBigFountain::Item* fountain, Controller* controller)
{
	if (gameSystem->isMultiplayerMode() && controller) {
		Screen::gGame2DMgr->setGamePad(controller);
	} else {
		Screen::gGame2DMgr->setGamePad(mControllerP1);
	}

	og::Screen::DispMemberKanketuMenu cave;
	int mePikis = GameStat::mePikis;
	if (mePikis > 0) {
		cave.mPikiInDanger = true;
		int map_pikis      = GameStat::getMapPikmins(-1);
		if (mePikis == map_pikis) {
			cave.mCantProceed = true;
		} else {
			cave.mCantProceed = false;
		}

	} else {
		cave.mCantProceed  = false;
		cave.mPikiInDanger = false;
	}

	bool open = Screen::gGame2DMgr->open_ChallengeKanketuMenu(cave);
	if (open) {
		mFountain = fountain;
		mMenuFlags |= 4;
		gameSystem->setPause(true, "op-kk", 3);
		gameSystem->setMoviePause(true, "op-kk");
	}
}

/*
 * --INFO--
 * Address:	801C202C
 * Size:	000014
 */
void VsGameSection::clearCaveMenus()
{
	mMenuFlags = 0;
	mHole      = nullptr;
	mFountain  = nullptr;
}

/*
 * --INFO--
 * Address:	801C2040
 * Size:	0002A8
 */
bool VsGameSection::updateCaveMenus()
{
	if (mMenuFlags & 2) {
		switch (Screen::gGame2DMgr->check_CaveMoreMenu()) {
		case 0:
			break;

		case 1:
			playData->mNaviLifeMax[0] = naviMgr->getAt(0)->mHealth;
			playData->mNaviLifeMax[1] = naviMgr->getAt(1)->mHealth;
			gameSystem->setPause(false, "more-yes", 3);
			gameSystem->setMoviePause(false, "more-yes");
			mMenuFlags &= ~2;
			goNextFloor(mHole);
			return true;

		case 2:
			gameSystem->setPause(false, "more-no", 3);
			gameSystem->setMoviePause(false, "more-no");
			mMenuFlags &= ~2;
			break;

		case 3:
			gameSystem->setMoviePause(false, "more-zenkai");
			break;
		}

	} else if (mMenuFlags & 4) {
		switch (Screen::gGame2DMgr->check_KanketuMenu()) {
		case 0:
			break;

		case 1:
			gameSystem->setPause(false, "kk-yes", 3);
			gameSystem->setMoviePause(false, "kk-yes");
			mMenuFlags &= ~4;
			MoviePlayArg arg("s0C_cv_escape", nullptr, mMovieFinishCallback, 0);
			arg.mOrigin        = mFountain->getPosition();
			arg.mAngle         = mFountain->getFaceDir();
			arg.mDelegateStart = mMovieStartCallback;
			mFountain->movie_begin(false);
			moviePlayer->mTargetObject = mFountain;
			moviePlayer->play(arg);
			return true;

		case 2:
			gameSystem->setPause(false, "kk-no", 3);
			gameSystem->setMoviePause(false, "kk-no");
			mMenuFlags &= ~4;
			break;

		case 3:
			break;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	801C22F0
 * Size:	0000DC
 */
void VsGameSection::onMovieStart(MovieConfig* movie, u32 param_2, u32 playerMode)
{
	movie->is("s03_orimadown");
	if (gameSystem->isMultiplayerMode()) {
		OSReport("PlayedMode %i\n", playerMode);
		switch (playerMode)
		{
		case 0:
			mSecondViewportHeight = 1.0f;
			gOtherViewportHeight  = 1.0f;
			break;
		case 1:
			gSplit4 = false;
			mSecondViewportHeight = 0.0f;
			gOtherViewportHeight  = 1.0f;
			break;
		case 2:
			mSecondViewportHeight = 1.0f;
			gOtherViewportHeight  = 0.0f;
			break;
		case 3:
			mSecondViewportHeight = 0.0f;
			gOtherViewportHeight  = 0.0f;
		default:
			break;
		}
	}

	BaseGameSection::setCamController();
	if (mState) {
		mState->onMovieStart(this, movie, param_2, playerMode);
	}
}

/*
 * --INFO--
 * Address:	801C23D0
 * Size:	000054
 */
void VsGameSection::onMovieDone(MovieConfig* movie, u32 param_2, u32 param_3)
{
	if (mState) {
		mState->onMovieDone(this, movie, param_2, param_3);
	}
}

/*
 * --INFO--
 * Address:	801C2428
 * Size:	000434
 */
void VsGameSection::createFallPikmins(PikiContainer& setPikmin, int param_2)
{
	Vector3f start;
	mapMgr->getStartPosition(start, param_2);
	setPikmin.dump("createFallPikmins");
	Navi* orima = naviMgr->getAt(0);
	start       = orima->getPosition();
	start.y     = mapMgr->getMinY(start);
	for (int color = Blue; color < PikiColorCount; color++) {
		for (int happa = Leaf; happa < PikiGrowthStageCount; happa++) {
			for (int i = 0; i < setPikmin.getCount(color, happa); i++) {
				// Gets Random in cylindrical geometry for some reason
				f32 radius = (randFloat() * 30.0f + 15.0f);
				f32 angle  = randFloat() * TAU;
				f32 height = (randFloat() * 120.0f + 850.0f) + 770.0f;

				Vector3f spawn = Vector3f(radius * pikmin2_sinf(angle), height, radius * pikmin2_cosf(angle));

				Piki* piki = pikiMgr->birth();
				spawn += start;
				if (piki) {
					PikiInitArg arg(15);
					piki->init(&arg);
					piki->mFaceDir = randFloat() * TAU;
					piki->setPosition(spawn, false);
					piki->changeShape(color);
					piki->changeHappa(happa);
					Vector3f velocity = Vector3f(0.0f, -(randFloat() * 150.0f + 2700.0f), 0.0f);
					piki->setVelocity(velocity);
					piki->movie_begin(false);
				}
			}
		}
	}
	setPikmin.clear();
}

/*
 * --INFO--
 * Address:	801C285C
 * Size:	000564
 */
void VsGameSection::createVsPikmins()
{
	Onyon* redOnyon = ItemOnyon::mgr->getOnyon(gScoreDelegations[0][0]);
	P2ASSERTLINE(1349, redOnyon);
	Vector3f redOnyonPos = redOnyon->getPosition();

	Onyon* blueOnyon = ItemOnyon::mgr->getOnyon(gScoreDelegations[0][1]);
	P2ASSERTLINE(1354, blueOnyon);
	Vector3f blueOnyonPos = blueOnyon->getPosition();

	Onyon* whiteOnyon = nullptr;
	Onyon* purpleOnyon = nullptr;
	Vector3f whiteOnyonPos;
	Vector3f purpleOnyonPos;

	if (gEffectiveTeamCount > 2) {

		whiteOnyon = ItemOnyon::mgr->getOnyon(gScoreDelegations[1][0]);
		P2ASSERTLINE(1354, whiteOnyon);
		whiteOnyonPos = whiteOnyon->getPosition();


		purpleOnyon = ItemOnyon::mgr->getOnyon(gScoreDelegations[1][1]);
		P2ASSERTLINE(1354, purpleOnyon);
		purpleOnyonPos = purpleOnyon->getPosition();
	}

	PikiContainer* pikmin = &mContainer1;
	pikmin->clear();

	int& reds  = pikmin->getCount(gScoreDelegations[0][0], Leaf);
	reds       = mOlimarHandicap * 5;
	int& blues = pikmin->getCount(gScoreDelegations[0][1], Leaf);
	blues      = mLouieHandicap * 5;

	if (gEffectiveTeamCount > 2) { 
		int& whites = pikmin->getCount(gScoreDelegations[1][0], Leaf);

		int& purples = pikmin->getCount(gScoreDelegations[1][1], Leaf);

		purples = mPurpleHandicap * 5;
		whites  = mWhiteHandicap * 5;
	}


	Vector3f spawnOnyonPos;

	for (int color = Blue; color < PikiColorCount; color++) {
		if (color == gScoreDelegations[0][0]) {
			spawnOnyonPos = redOnyonPos;
		} else if (color == gScoreDelegations[0][1]) {
			spawnOnyonPos = blueOnyonPos;
		}
		else if (color == gScoreDelegations[1][0] && gEffectiveTeamCount > 2) {
			spawnOnyonPos = whiteOnyonPos;
		}
		else if (color == gScoreDelegations[1][1] && gEffectiveTeamCount > 2) {
			spawnOnyonPos = purpleOnyonPos;
		} else {
			continue;
		}
		for (int happa = Leaf; happa < PikiGrowthStageCount; happa++) {
			for (int i = 0; i < pikmin->getCount(color, happa); i++) {
				f32 radius = randFloat() * 10.0f;
				f32 angle  = randFloat() * TAU;
				f32 height = 0.0f;

				Vector3f spawn = Vector3f(radius * pikmin2_sinf(angle), height, radius * pikmin2_cosf(angle));

				Piki* piki = pikiMgr->birth();
				spawn += spawnOnyonPos;

				if (piki) {
					PikiInitArg arg(-1);
					piki->init(&arg);
					piki->setPosition(spawn, false);
					piki->changeShape(color);
					piki->changeHappa(happa);
				}
			}
		}
	}
	
	const char* marbles[] = { VsOtakaraName::cBedamaRed, VsOtakaraName::cBedamaBlue, VsOtakaraName::cBedamaWhite, VsOtakaraName::cBedamaPurple };
	for (int onyonType = 0; onyonType < ARRAY_SIZE(marbles); onyonType++) {
		Onyon* currentOnyon = ItemOnyon::mgr->getOnyon(getPikiFromTeam(onyonType));
		if (!currentOnyon) continue;
		PelletIterator pelletIter;
		pelletIter.first();
		while (!pelletIter.isDone()) {
			Pellet* pellet = *pelletIter;
			int i          = strcmp(marbles[onyonType], pellet->mConfig->mParams.mName.mData);
			if (i == 0) {
				Vector3f flagPos = currentOnyon->getFlagSetPos();
				flagPos.y += pellet->getCylinderHeight() * 0.5f;
				pellet->setPosition(flagPos, false);

				if (gConfig[MARBLE_BURY] == ConfigEnums::PLACE_BURY) {
					pellet->mPelletPosition.y = mapMgr->getMinY(pellet->mPelletPosition);
					ItemTreasure::Item* pelletTreasure = (ItemTreasure::Item*)ItemTreasure::mgr->birth();
					pelletTreasure->init(nullptr);
					pelletTreasure->setPosition(pellet->mPelletPosition, false);
					pelletTreasure->setTreasure(pellet);
				}
			}
			pelletIter.next();
		}
	}

	for (int i = 0; i < 4; i++) {
		gDopeCountArray[i][0] = mVsStageData->mStartNumSpicy;
		gDopeCountArray[i][1] = mVsStageData->mStartNumBitter;
	}
}

/*
 * --INFO--
 * Address:	801C2DC0
 * Size:	000010
 */
void VsGameSection::addChallengeScore(int score) { mPokoCount += score; }

/*
 * --INFO--
 * Address:	801C2DD0
 * Size:	00006C
 */
bool VsGameSection::sendMessage(GameMessage& message)
{
	if (message.actCommon(this)) {
		return message.actVs(this);
	}
}

/*
 * --INFO--
 * Address:	801C2E3C
 * Size:	000040
 */
bool GameMessageVsGetDoping::actVs(VsGameSection* section)
{
	section->getGetDopeCount(getVsTeam(mNaviIndex), mSprayType)++;
	return true;
}

/*
 * --INFO--
 * Address:	801C2E7C
 * Size:	00004C
 */
bool GameMessageVsBattleFinished::actVs(VsGameSection* section)
{
	if (section->mState) {
		section->mState->onBattleFinished(section, mWinningSide, false);
	}
	return true;
}

int VsGame::gBedamaColor = 0;

/*
 * --INFO--
 * Address:	801C2ECC
 * Size:	00004C
 */
bool GameMessageVsRedOrSuckStart::actVs(VsGameSection* section)
{
	
	VsGame::gBedamaColor = mBedamaColor;
	OSReport("Bedama Color %i\n", VsGame::gBedamaColor);
	if (section->mState) {
		section->mState->onRedOrBlueSuckStart(section, mColor, mIsYellow);
	}
	return true;
}

/*
 * --INFO--
 * Address:	801C2F1C
 * Size:	0000B8
 */
bool GameMessageVsGetOtakara::actVs(VsGameSection* section)
{
	if (section->mState) {
		section->mDispMarbleCounts[_04]++;
		PSSetLastBeedamaDirection(_04 == 0, section->mDispMarbleCounts[_04] == 3);
		if (section->mDispMarbleCounts[_04] >= 4) {
			section->mState->onBattleFinished(section, _04, true);
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	801C2FD4
 * Size:	000034
 */
bool GameMessageVsAddEnemy::actVs(VsGameSection* section)
{
	//section->mTekiMgr->entry(_04, _08);
	return true;
}

/*
 * --INFO--
 * Address:	801C3008
 * Size:	000118
 */
bool GameMessagePelletBorn::actVs(VsGameSection* section)
{
	if (mPellet->mPelletFlag == Pellet::FLAG_VS_BEDAMA_YELLOW) { // is yellow bedama
		for (int i = 0; i < YELLOW_MARBLE_COUNT; i++) {
			if (section->mMarbleYellow[i] == mPellet) {
				return false;
			}
		}
		for (int i = 0; i < YELLOW_MARBLE_COUNT; i++) {
			if (!section->mMarbleYellow[i]) {
				section->mMarbleYellow[i] = mPellet;
				return true;
			}
		}
		JUT_PANICLINE(1592, "no space for new yellow\n");
	}
	return false;
}

/*
 * --INFO--
 * Address:	801C3120
 * Size:	00008C
 */
bool GameMessagePelletDead::actVs(VsGameSection* section)
{
	if (mPellet->mPelletFlag == Pellet::FLAG_VS_BEDAMA_YELLOW) { // is yellow bedama
		for (int i = 0; i < YELLOW_MARBLE_COUNT; i++) {
			if (section->mMarbleYellow[i] == mPellet) {
				section->mMarbleYellow[i] = nullptr;
				return true;
			}
		}
		JUT_PANICLINE(1617, "no entry for pellet\n");
	}

	return false;
}

/*
 * --INFO--
 * Address:	801C31AC
 * Size:	000228
 */
bool GameMessageVsBirthTekiTreasure::actVs(VsGameSection* section)
{
	if (gConfig[SPAWN_SHEARWIG] == ConfigEnums::SHEARWIG_DONTSPAWN) {
		return false;
	}

	// This function spawns the shearwigs (suprise maggots)
	Sys::Sphere sphere(mPosition, 20.0f);
	int target            = 0;
	int redPikis          = 0;
	int bluePikis         = 0;
	CellIteratorArg arg   = sphere;
	CellIterator cellIter = arg;

	CI_LOOP(cellIter)
	{
		CellObject* cell = *cellIter;
		if (cell->isPiki()) {
			Piki* piki = (Piki*)cell;
			if (piki->isAlive()) {
				if ((int)piki->mPikiKind == Red) {
					redPikis++;
				} else if ((int)piki->mPikiKind == Blue) {
					bluePikis++;
				}
			}
		}
	}

	if (bluePikis > redPikis) {
		target = 1;
	}

	f32 tobiFactor = section->mYellowScore[target] - section->mYellowScore[1 - target];

	f32 tobiChance = 0.2f;

	if (tobiFactor > 0.8f) {
		_10 += 2;
		tobiChance = 0.8f;
	} else if (tobiFactor > 0.5f) {
		_10 += 1;
		tobiChance = 0.5f;
	} else if (tobiFactor > 0.1f) {
		tobiChance = 0.2f;
	} else if (tobiFactor > -0.1f) {

	} else if (tobiFactor > -0.5f) {
		tobiChance = 0.1f;
	} else if (tobiFactor > -0.8f) {
		tobiChance = 0.051f;
	} else {
		tobiChance = 0.01f;
	}
	if (!(randFloat() > tobiChance)) {
		int nodes = section->mTekiMgr->mNodeCount - 1;
		for (int i = 0; i < _10; i++) {
			section->mTekiMgr->birth(nodes, mPosition, _14);
		}
		return true;
	}
}

/*
 * --INFO--
 * Address:	801C33D4
 * Size:	00001C
 */
bool GameMessageVsPikminDead::actVs(VsGameSection* section)
{
	section->_205 = false;
	section->mDeadPikiCount++;
	return true;
}

/*
 * --INFO--
 * Address:	801C33F0
 * Size:	00007C
 */
bool GameMessageVsGotCard::actVs(VsGameSection* section)
{
	VsGame::CardMgr::SlotMachine* slot = &section->mCardMgr->mSlotMachines[_04];
	if (!slot->_18 && slot->mSlotID != VsGame::UNRESOLVED) {
		section->useCard();
	}
	section->mCardMgr->gotPlayerCard(_04);
	return true;
}

int gUseCardNavi;

/*
 * --INFO--
 * Address:	801C346C
 * Size:	0000A8
 */
bool GameMessageVsUseCard::actVs(VsGameSection* section)
{
	if (section->mState) {
		if (!section->mState->isCardUsable(section)) {
			return false;
		}
	}
	if (gGameConfig.mParms.mVsY.mData == 0) {
		gUseCardNavi = mTeamIdx;
		if (section->mCardMgr->usePlayerCard(getVsTeam(mTeamIdx), section->mTekiMgr)) {
			section->useCard();
		}
	} else {
		int teamIdx = getVsTeam(mTeamIdx);
		int canidates[4];
		int canidateNum = 0;
		for (int i = 0; i < 4; i++) {
			if (getVsTeam(i) == teamIdx) {
				canidates[canidateNum] = i;
				canidateNum++;
			}
		}
		gUseCardNavi = canidates[(int)(randFloat() * canidateNum)];
		section->mCardMgr->stopSlot(teamIdx);
	}
	return true;
}

/*
 * --INFO--
 * Address:	801C351C
 * Size:	000010
 */
void FixedSizePelletMgr<PelletOtakara::Object>::setComeAlive(int index) { mMonoObjectMgr.mOpenIds[index] = false; }

/*
 * --INFO--
 * Address:	801C352C
 * Size:	000190
 */
void VsGameSection::initCardPellets()
{
	mMaxCherries = 10;
	mCherryArray = new Pellet*[mMaxCherries];

	char* name = const_cast<char*>(VsOtakaraName::cCoin);
	PelletList::cKind kind;
	PelletInitArg arg;

	PelletConfig* config = PelletList::Mgr::getConfigAndKind(name, kind);
	JUT_ASSERTLINE(1796, config, "zannenn\n"); // 'disappointing'
	arg._10             = config->mParams.mIndex;
	arg.mTextIdentifier = config->mParams.mName.mData;
	arg.mPelletType     = kind;
	arg.mMinCarriers    = 1;
	arg.mMaxCarriers    = 1;

	for (int j = 0; j < mMaxCherries; j++) {
		Pellet* pellet = pelletMgr->birth(&arg);
		if (pellet) {
			Vector3f position = Vector3f(0.0f);
			mCherryArray[j]   = pellet;
			pellet->setPosition(position, false);
			mCherryArray[j] = pellet;
		} else {
			JUT_PANICLINE(1813, "birth failed !\n");
		}
	}

	for (int i = 0; i < mMaxCherries; i++) {
		mCherryArray[i]->kill(nullptr);
	}
}

/*
 * --INFO--
 * Address:	801C36BC
 * Size:	000014
 */
void VsGameSection::initCardGeneration()
{
	mCardCount  = 0;
	mSpawnTimer = 25.0f;
}

/*
 * --INFO--
 * Address:	801C36D0
 * Size:	0002D8
 */
void VsGameSection::updateCardGeneration()
{
	int maxSpawnCherries[2] = { 0, 0 };
	f32 spawnFactor[2];
	for (int i = 0; i < 2; i++) {
		spawnFactor[i] = (mRedBlueScore[i * 2] - mYellowScore[i * 2]) - (mRedBlueScore[i * 2 + 1] - mYellowScore[i * 2 + 1]);
	}
	f32 lowFactor[2];
	for (int i = 0; i < 2; i++) {
		lowFactor[i] = mCherryScore[i * 2] - mCherryScore[i * 2 + 1];
	}
	f32 factors[2][2] = { {0.4f, 0.6f}, {0.4f, 0.6f} };
	bool isUrgent[2] = { false, false };
	for (int i = 0; i < gEffectiveTeamCount / 2; i++) {
		if (FABS(spawnFactor[i]) < 0.2f) {

		} else if (0.2f <= FABS(spawnFactor[i]) < 0.4f) {
			isUrgent[i]      = true;
			factors[i][0]          = 0.3f;
			factors[i][1]          = 0.5f;
		} else if (0.4f <= FABS(spawnFactor[i]) < 0.8f) {
			maxSpawnCherries[i] = 1;
			isUrgent[i]           = true;
			factors[i][0]          = 0.2f;
			factors[i][1]          = 0.4f;
		} else if (0.8f <= FABS(spawnFactor[i])) {
			maxSpawnCherries[i] = 2;
			isUrgent[i]           = true;
			factors[i][0]          = 0.2f;
			factors[i][1]          = 0.4f;
		}


		if (!isUrgent[i]) {
			f32 absLowFactor = FABS(lowFactor[i] * 0.5f);
			if (absLowFactor <= 0.1f) {

			} else {
				if (absLowFactor < 0.2f) {
					factors[i][0] = 0.4f;
					factors[i][1] = 0.55f;
				} else if (absLowFactor < 0.5f) {
					factors[i][0] = 0.4f;
					factors[i][1] = 0.5f;
				} else if (absLowFactor < 1.0f) {
					factors[i][0] = 0.3f;
					factors[i][1] = 0.5f;
					if (absLowFactor > 0.9f) {
						maxSpawnCherries[i] = 0;
					}
				}
			}
		}
	}

	mCardCount = 0;
	for (int i = 0; i < mMaxCherries; i++) {
		if (mCherryArray[i]->isAlive()) {
			mCardCount++;
		}
	}

	const f32 cardTimerConst[] = {0.5f,  3.0f, 6.0f, 10.0f, 14.0f, 20.0f, 0};
	const f32 cardTimerRand[]  = {0.75f, 1.0f, 2.0f, 3.0f,  4.0f,  6.0f,  0};

	bool hasUrgency = isUrgent[0] || isUrgent[1] || isUrgent[2] || isUrgent[3];
	int spawnCherries = maxSpawnCherries[0] + maxSpawnCherries[1] + maxSpawnCherries[2] + maxSpawnCherries[3] + 5;
	if (spawnCherries > 10) spawnCherries = 10;

	if (mCardCount < 4 || (hasUrgency && mCardCount < spawnCherries) && gConfig[CHERRY_RATE] != ConfigEnums::RATE_NEVER) { // config is never spawn
		f32 ticking = sys->mDeltaTime;
		if (hasUrgency) {
			ticking *= 2.0f;
		}
		mSpawnTimer -= ticking;
		if (mSpawnTimer <= 0.0f) {
			mSpawnTimer = cardTimerRand[gConfig[CHERRY_RATE]] * randFloat() + cardTimerConst[gConfig[CHERRY_RATE]];
			DropCardArg arg;
			arg.mMinDists[0] = factors[0][0];
			arg.mMinDists[1] = factors[1][0];
			arg.mMaxDists[0] = factors[0][1];
			arg.mMaxDists[1] = factors[1][1];
			dropCard(arg);
		}
	}
}

/*
 * --INFO--
 * Address:	801C39A8
 * Size:	000018
 */
void VsGameSection::useCard()
{
	if (mCardCount > 0) {
		mCardCount -= 1;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
Pellet* VsGameSection::createCardPellet()
{
	PelletList::cKind kind;
	char* name = const_cast<char*>(VsOtakaraName::cCoin);
	PelletInitArg pelletArg;

	PelletConfig* config = PelletList::Mgr::getConfigAndKind(name, kind);
	JUT_ASSERTLINE(1759, config, "zannenn\n");
	pelletArg._10             = config->mParams.mIndex;
	pelletArg.mTextIdentifier = config->mParams.mName.mData;
	pelletArg.mPelletType     = kind;
	pelletArg._1C             = 1;
	pelletArg.mMinCarriers    = 1;
	pelletArg.mMaxCarriers    = 1;

	for (int i = 0; i < mMaxCherries; i++) {
		Pellet* pellet = mCherryArray[i];
		if (!pellet->isAlive() && !pellet->getStateID()) {
			PelletOtakara::mgr->setComeAlive(pellet->mSlotIndex);
			pellet->init(&pelletArg);
			return pellet;
		}
	}
	return nullptr;
}

void VsGameSection::dropCard(VsGameSection::DropCardArg& arg)
{
	Vector3f spawn;
	Cave::randMapMgr->getItemDropPosition(spawn, arg.mMinDists, arg.mMaxDists);
	f32 radius = (randFloat() * 20.0f);
	f32 angle  = randFloat() * TAU;

	spawn += Vector3f(radius * pikmin2_sinf(angle), 0.0f, radius * pikmin2_cosf(angle));

	Pellet* pellet = createCardPellet();

	if (pellet) {
		spawn.y += 140.0f;
		pellet->setPosition(spawn, false);
		efx::TEnemyApsmoke smoke;
		efx::ArgEnemyType smokeArg(spawn, EnemyTypeID::EnemyID_Kochappy, 1.0f);
		smoke.create(&smokeArg);

		Vector3f newRand = Vector3f(0.0f, randFloat() * TAU, 0.0f);
		Matrixf mat;
		mat.makeTR(Vector3f::zero, newRand);
		pellet->setOrientation(mat);
		mCardCount++;
	} else {
		for (int i = 0; i < mMaxCherries; i++) {
			mCherryArray[i]->isAlive();
		}
	}
}

/*
 * --INFO--
 * Address:	801C3DB4
 * Size:	0001AC
 */
void VsGameSection::createYellowBedamas(int bedamas)
{
	if (mVsStageData) {
		if (gEffectiveTeamCount == 2) {
			bedamas = mVsStageData->mStartNumYellowMarbles;
		}
		else {
			bedamas = mVsStageData->mStartNumYellowMarblesVsFour;
		}
		if (bedamas == 0) {
			return;
		}
		if (bedamas >= YELLOW_MARBLE_COUNT) {
			bedamas = YELLOW_MARBLE_COUNT;
		}
	}

	OSReport("Bedamas %i\n", bedamas);

	PelletList::cKind kind;
	char* name = const_cast<char*>(VsOtakaraName::cBedamaYellow);
	PelletInitArg pelletArg;

	PelletConfig* config = PelletList::Mgr::getConfigAndKind(name, kind);
	JUT_ASSERTLINE(2154, config, "zannenn\n"); // 'disappointing'

	pelletArg._10 = config->mParams.mIndex;

	pelletArg.mTextIdentifier = config->mParams.mName.mData;
	pelletArg.mPelletType     = kind;
	pelletArg.mMinCarriers    = 1;
	pelletArg.mMaxCarriers    = 8;
	JUT_ASSERTLINE(2163, bedamas <= 50, "oosugi %d\n", bedamas);

	Vector3f positions[50];
	VsWeights mindists = { 0.45f, 0.45f };
	VsWeights maxdists = { 0.55f, 0.55f };
	Cave::randMapMgr->getItemDropPosition(positions, bedamas, mindists, maxdists);
	for (int i = 0; i < bedamas; i++) {
		Pellet* pellet = pelletMgr->birth(&pelletArg);
		Vector3f pos   = positions[i];
		pellet->setPosition(pos, false);
		mMarbleYellow[i] = pellet;
	}
}

void VsGameSection::createRedBlueBedamas(Vector3f& pos)
{
	if (gConfig[MARBLE_BURY] == ConfigEnums::PLACE_NOTHING) {
		return;
	}
	const char* marbles[] = { VsOtakaraName::cBedamaRed, VsOtakaraName::cBedamaBlue, VsOtakaraName::cBedamaWhite, VsOtakaraName::cBedamaPurple };
	for (int i = 0; i < ARRAY_SIZE(marbles); i++) {
		if (!isTeamActive(i)) {
			continue;
		}
		PelletList::cKind kind;

		PelletInitArg pelletArg;
		char* name           = const_cast<char*>(marbles[i]);
		PelletConfig* config = PelletList::Mgr::getConfigAndKind(name, kind);
		JUT_ASSERTLINE(2211, config, "zannenn\n"); // 'disappointing'
		pelletArg._10             = config->mParams.mIndex;
		pelletArg.mTextIdentifier = config->mParams.mName.mData;
		pelletArg.mPelletType     = kind;
		pelletArg.mMinCarriers    = 1;
		pelletArg.mMaxCarriers    = 8;
		Pellet* pellet            = pelletMgr->birth(&pelletArg);
		Vector3f position;
		Cave::randMapMgr->getItemDropPosition(position, 0.2f, 0.8f);
		pellet->setPosition(position, false);
		mMarbleRedBlue[i] = pellet;
	}
}


/*
 * --INFO--
 * Address:	801C40AC
 * Size:	000814
 */
void VsGameSection::calcVsScores()
{

	f32 yellowMarbleDist[4][YELLOW_MARBLE_COUNT];
	Onyon* onyons[4];
	onyons[0] = ItemOnyon::mgr->getOnyon(gScoreDelegations[0][0]);
	onyons[1] = ItemOnyon::mgr->getOnyon(gScoreDelegations[0][1]);
	onyons[2] = ItemOnyon::mgr->getOnyon(gScoreDelegations[1][0]);
	onyons[3] = ItemOnyon::mgr->getOnyon(gScoreDelegations[1][1]);

	int* scoreDelegationsArr = *gScoreDelegations;

	for (int i = 0; i < YELLOW_MARBLE_COUNT; i++) {
		Pellet* marble = mMarbleYellow[i];

		if (marble && marble->isAlive() && marble->getStateID() == 0) {
			int marbleCarryFactor = -1;
			if (marble->isCarried()) {
				if (marble->mCarryColor != 5) {
					marbleCarryFactor = getTeamFromPiki(marble->mCarryColor);
				}
			}

			Vector3f marblePosition   = marble->getPosition();
			f32 scores[4];
			for (int our = 0; our < gEffectiveTeamCount; our++) {
				Vector3f ourOnyonPos = onyons[our]->getPosition();
				f32 ourDistance = _distanceXZ(marblePosition, ourOnyonPos);
				scores[our] = 0;
				for (int their = 0; their < gEffectiveTeamCount; their++) {
					if (our == their) continue;
					Vector3f theirOnyonPos = onyons[their]->getPosition();
					f32 theirDistance = _distanceXZ(marblePosition, theirOnyonPos);
					scores[our] += 1.0f / ((f32)exp((theirDistance / (ourDistance + theirDistance) - 0.5f) * -10.0f) + 1.0f) / 3;
				}
			}

			if (!marble->isPelletBuried()) {
				for (int teamColor = 0; teamColor < gEffectiveTeamCount; teamColor++) {
					if (marbleCarryFactor == teamColor) {
						yellowMarbleDist[teamColor][i] = 0.0f;
					}
					else {
						yellowMarbleDist[teamColor][i] = scores[teamColor];
					}
				}
			} else {
				for (int teamColor = 0; teamColor < gEffectiveTeamCount; teamColor++) {
					yellowMarbleDist[teamColor][i] = 0.1f * scores[teamColor];
				}
			}
		} else {
			for (int teamColor = 0; teamColor < gEffectiveTeamCount; teamColor++) {
				yellowMarbleDist[teamColor][i] = 0.0f;
			}
		}
	}

	f32 yellowScore[4];
	for (int i = 0; i < gEffectiveTeamCount; i++) {
		f32 count = mRealMarbleCounts[i];
		for (int j = 0; j < YELLOW_MARBLE_COUNT; j++) {
			if (yellowMarbleDist[i][j] >= 0.0f) {
				count += yellowMarbleDist[i][j];
			}
		}
		if (count >= 4.0f) {
			count = 4.0f;
		}
		count /= 4.0f;
		yellowScore[i]  = count;
		mYellowScore[i] = yellowScore[i];
	}

	f32 redBlueScore[] = { 0.0f, 0.0f, 0.0f, 0.0f };

	for (int i = 0; i < gEffectiveTeamCount; i++) {
		Pellet* marble = mMarbleRedBlue[getTeamFromPiki(scoreDelegationsArr[i])];
		Onyon* onyon   = onyons[i];
		if (marble) {
			Vector3f marblePosition = marble->getPosition();
			Vector3f onyonPosition  = onyon->getPosition();
			f32 ourDist = _distanceXZ(marblePosition, onyonPosition);
			redBlueScore[i] = 0;
			for (int other = 0; other < gEffectiveTeamCount; other++) {
				if (other == i) continue;
				Vector3f otherOnyonPosition = onyons[other]->getPosition();
				f32 otherDist = _distanceXZ(marblePosition, otherOnyonPosition);
				redBlueScore[i] += 1.0f / ((f32)exp((ourDist / (ourDist + otherDist) - 0.5f) * -10.0f) + 1.0f) / 3;
			}
			mRedBlueScore[i] = redBlueScore[i];
		}
	}

	for (int our = 0; our < gEffectiveTeamCount; our++) {
		mRedBlueYellowScore[our] = yellowScore[our] - redBlueScore[our];
		for (int their = 0; their < gEffectiveTeamCount; their++) {
			if (our == their) continue;
			mRedBlueYellowScore[our] -= (yellowScore[their] - redBlueScore[their]) / 3;
		}
	}

	f32 cherryValue;
	f32 cherryDist[4][10];
	
	for (int i = 0; i < 10; i++) {
		Pellet* cherry = mCherryArray[i];
		if (cherry->isAlive() && cherry->getStateID() == 0) {
			int cherryCarryFactor = -1;
			if (cherry->isCarried()) {
				if (cherry->mCarryColor != 5) {
					cherryCarryFactor = getTeamFromPiki(cherry->mCarryColor);
				}
			}

			Vector3f cherryPosition   = cherry->getPosition();
			f32 score[4];

			for (int our = 0; our < gEffectiveTeamCount; our++) {
				Vector3f ourOnyonPosition = onyons[our]->getPosition();
				f32 ourDist            = _distanceXZ(cherryPosition, ourOnyonPosition);
				score[our] = 0.0f;
				for (int their = 0; their < gEffectiveTeamCount; their++) {
					if (our == their) continue;
					Vector3f theirOnyonPosition = onyons[their]->getPosition();
					f32 theirDist            = _distanceXZ(cherryPosition, theirOnyonPosition);
					score[our] = 1.0f / ((f32)exp((theirDist / (ourDist + theirDist) - 0.5f) * -10.0f) + 1.0f) / 3;
				}
			}

			if (!cherry->isPelletBuried()) {
				for (int teamColor = 0; teamColor < gEffectiveTeamCount; teamColor++) {
					if (cherry->mCarryColor == teamColor) {
						cherryDist[teamColor][i] = 0.0f;
					}
					else {
						cherryDist[teamColor][i] = score[teamColor];
					}
				}
			} else {
				for (int teamColor = 0; teamColor < gEffectiveTeamCount; teamColor++) {
					cherryDist[teamColor][i]  = 0.1f * score[teamColor];
				}
			}
		} else {
			for (int teamColor = 0; teamColor < gEffectiveTeamCount; teamColor++) {
				cherryDist[teamColor][i]  = 0.0f;
			}
		}
	}

	f32 redCherryValue;
	f32 blueCherryValue;
	for (int i = 0; i < gEffectiveTeamCount; i++) {
		mMinCherryScore[i] = 0.0f;
		f32 count          = 0.0f;
		for (int j = 0; j < 10; j++) {
			count += cherryDist[i][j];
			f32 miniCount = 0.0f;
			if (cherryDist[i][j] >= 0.0f) {
				miniCount = cherryDist[i][j];
			}
			if (mMinCherryScore[i] <= miniCount) {
				mMinCherryScore[i] = miniCount;
			}
		}
		mCherryScore[i] = count;
	}
}

/*
 * --INFO--
 * Address:	801C48C0
 * Size:	000018
 */
void VsGameSection::clearGetDopeCount()
{
	for (int i = 0; i < 4; i++) {
		mGetDopeCount[i][0] = 0;
		mGetDopeCount[i][1] = 0;
	}
}

/*
 * --INFO--
 * Address:	801C48D8
 * Size:	0000D0
 */
int& VsGameSection::getGetDopeCount(int player, int type)
{
	JUTASSERTBOUNDSINCLUSIVELINE(2567, 0, player, 3, "%d playerID\n");
	JUTASSERTBOUNDSINCLUSIVELINE(2568, 0, type, 3, "%d typeID\n");
	return mGetDopeCount[player][type];
}

/*
 * --INFO--
 * Address:	801C49A8
 * Size:	000010
 */
void VsGameSection::clearGetCherryCount()
{

}

/*
 * --INFO--
 * Address:	801C49B8
 * Size:	000008
 */
bool VsGameSection::challengeDisablePelplant() { return false; }

/*
 * --INFO--
 * Address:	801C49C0
 * Size:	000008
 */
bool VsGameSection::player2enabled() { return true; }

/*
 * --INFO--
 * Address:	801C49C8
 * Size:	000008
 */
char* VsGameSection::getCaveFilename() { return mCaveInfoFilename; }

/*
 * --INFO--
 * Address:	801C49D0
 * Size:	000008
 */
char* VsGameSection::getEditorFilename() { return mEditFilename; }

/*
 * --INFO--
 * Address:	801C49D8
 * Size:	000008
 */
int VsGameSection::getVsEditNumber() { return mEditNumber; }

/*
 * --INFO--
 * Address:	801C49E0
 * Size:	000004
 */
void StateMachine<VsGameSection>::init(VsGameSection*) { }

/*
 * --INFO--
 * Address:	801C49E4
 * Size:	000064
 */
void StateMachine<VsGameSection>::create(int states)
{
	mLimit          = states;
	mCount          = 0;
	mStates         = new FSMState<VsGameSection>*[mLimit];
	mIndexToIDArray = new int[mLimit];
	mIdToIndexArray = new int[mLimit];
}

/*
 * --INFO--
 * Address:	801C4A48
 * Size:	00009C
 */
void StateMachine<VsGameSection>::transit(VsGameSection* section, int stateID, StateArg* arg)
{

	int stateIndex              = mIdToIndexArray[stateID];
	VsGame::State* currentState = section->mState;
	if (currentState) {
		currentState->cleanup(section);
		mCurrentID = currentState->mId;
	}
	if (stateIndex >= mLimit) {
		while (true)
			;
	}
	VsGame::State* state = static_cast<VsGame::State*>(mStates[stateIndex]);
	section->mState      = state;
	state->init(section, arg);
}

/*
 * --INFO--
 * Address:	801C4AEC
 * Size:	000084
 */
void StateMachine<VsGameSection>::registerState(FSMState<VsGameSection>* state)
{
	if (mCount >= mLimit) {
		return;
	}
	mStates[mCount] = state;
	bool inBounds;
	if (state->mId < 0 || state->mId >= mLimit) {
		inBounds = false;
	} else {
		inBounds = true;
	}

	if (!inBounds) {
		return;
	}

	state->mStateMachine        = this;
	mIndexToIDArray[mCount]     = state->mId;
	mIdToIndexArray[state->mId] = mCount;
	mCount++;
}

/*
 * --INFO--
 * Address:	801C4B70
 * Size:	000038
 */
void StateMachine<VsGameSection>::exec(VsGameSection* section)
{
	if (section->mState) {
		section->mState->exec(section);
	}
}

} // namespace Game

namespace Game
{
	const float cTimerInterval = 10.0f;
	float gFancyTimer = 0.0f;
	const float cMinInterval = PI / 6;
	const float cIntervalTheta = PI / 2;
	Creature* gFancyTarget = nullptr;
	void VsGameSection::updateFancyCam() {
		gFancyTimer -= sys->mDeltaTime;
		if (gFancyTimer <= 0.0f) {
			OSReport("Update but fancy\n");
			gFancyTimer = cTimerInterval;
			gFancyTarget = fancyCamLookForTarget();
		}
		if (gFancyTarget) {
			Vector3f realPos = gCameraP4->mNavi->mPosition3;
			gCameraP4->mNavi->mPosition3 = gFancyTarget->getPosition();
			gCameraP4->_1B0 = gFancyTarget->getFaceDir();
			// gCameraP4->_1B4 = gFancyTimer * cIntervalTheta / cTimerInterval + cMinInterval;
			// gCameraP4->_1BC = gFancyTimer * cIntervalTheta / cTimerInterval + cMinInterval;
			
			//gCameraP4->mNavi->mPosition3 = realPos;
		}
		
	}

	Creature* VsGameSection::fancyCamLookForTarget() {
		Creature* targets[300];
		int currTarget = 0;
		f32 maxScore = 0.0f;
		
		// Find all the potentional targets

		// Every Navi
		for (int i = 0; i < 4; i++) {
			Navi* navi = naviMgr->getAt(i);
			if (navi->isAlive()) {
				targets[currTarget++] = navi;
			}
		}

		// Every Treasure
		PelletIterator iPellet;
		CI_LOOP(iPellet) {
			Pellet* pellet = *iPellet;
			if (pellet->isAlive()) {
				targets[currTarget++] = pellet;
			}
		}

		// Every Enemy
		GeneralMgrIterator<EnemyBase> iEnemyBase = generalEnemyMgr;
		CI_LOOP(iEnemyBase) {
			EnemyBase* enemy = *iEnemyBase;
			if (enemy->isAlive()) {
				targets[currTarget++] = enemy;
			}
		}

		// Calculate the most intresting target
		Creature* fanciestTarget = nullptr;
		for (int i = 0; i < currTarget; i++) {
			f32 score = fancyCamCalcIntrest(targets[i]);
			if (score > maxScore) {
				maxScore = score;
				fanciestTarget = targets[i];
			}
		}
		return fanciestTarget;
	}

	f32 VsGameSection::fancyCamCalcIntrest(Creature* target) {
		if (target->isPellet()) {
			Pellet* pellet = static_cast<Pellet*>(target);
			
		}
		return 0.0f;
	}
} // namespace Game
