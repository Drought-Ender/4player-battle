#include "Game/VsGame.h"
#include "Game/DeathMgr.h"
#include "Game/MoviePlayer.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Entities/ItemHole.h"
#include "Game/Entities/PelletItem.h"
#include "Game/MapMgr.h"
#include "Game/gameStat.h"
#include "Game/Data.h"
#include "Game/mapParts.h"
#include "VsOtakaraName.h"
#include "Screen/Game2DMgr.h"
#include "kh/khWinLose.h"
#include "PSM/Director.h"
#include "PSM/Global.h"
#include "PSSystem/PSScene.h"
#include "PSSystem/PSGame.h"
#include "PSSystem/PSMainSide_Scene.h"
#include "utilityU.h"
#include "Controller.h"
#include "PikiAI.h"
#include "Radar.h"
#include "nans.h"
#include "FourPlayer.h"
#include "VsOptions.h"

namespace Game {
namespace VsGame {

static const char unusedVsGSGameArray[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const char vsGSGameName[]        = "vsGS_Game";

/*
 * --INFO--
 * Address:	802292A4
 * Size:	0000A4
 */
GameState::GameState()
    : State(VGS_Game)
{
	mController = new Controller(JUTGamePad::PORT_0);
}

/*
 * --INFO--
 * Address:	80229354
 * Size:	0001AC
 */
void GameState::init(VsGameSection* section, StateArg* stateArg)
{
	_16 = 0;
	mFlags.clear();
	section->refreshHIO();
	do_init(section);
	section->setFixNearFar(true, 1.0f, 12800.0f);
	DeathMgr::clear();
	gameSystem->resetFlag(GAMESYS_IsPlaying);
	gameSystem->setFlag(GAMESYS_Unk6);
	section->clearCaveMenus();

	if (!gameSystem->isMultiplayerMode()) {
		section->setPlayerMode(0);
	}

	if (gameSystem->isVersusMode()) {
		DebugReport("Set mode %i\n", gNaviNum);
		section->setPlayerMode(gNaviNum);
		section->setCamController();
		clearLoseCauses();
		Screen::gGame2DMgr->startFadeBG_Floor();
	}

	mHasKeyDemoPlayed = false;

	if (gameSystem->isChallengeMode()) {
		mTimer            = section->mTimeLimit;
		mFloorExtendTimer = section->mChallengeStageData->mFloorTimerExtensions[section->getCurrFloor()];
		mDisplayTime      = mTimer / 4;
		section->mTimeLimit += mFloorExtendTimer;
	}

	for (int i = 0; i < 4; i++) {
		section->mDispMarbleCounts[i] = 0;
		section->mRealMarbleCounts[i] = 0;
		section->mDispMiniCounts[i]   = 0;
		section->mRealMiniCounts[i]   = 0;
		mWinColors[i] = 0;
		mNaviStatus[i] = -1;
		mExtinctions[i] = false;
		if (!doesTeamHavePlayers(i)) {
			mExtinctions[i] = true;
			
		}
		DebugReport("mExtinctions[%i] = %i\n", i, mExtinctions[i]);
		mOrimaDownState[i] = 0;
	}
	section->mGhostIconTimers[0]    = 0.0f;
	section->mGhostIconTimers[1]    = 0.0f;
	section->mGhostIconTimers[2]    = 0.0f;
	section->mGhostIconTimers[3]    = 0.0f;

	gPassiveBitter = sSprayTimers[gConfig[BITTER_PASSIVE]];
	gPassiveSpicy  = sSprayTimers[gConfig[SPICY_PASSIVE]];

	mTimeLeft = VS_TIMER_START_TIME; // 8 minutes default timer
}

/*
 * --INFO--
 * Address:	80229500
 * Size:	000014
 */
void GameState::clearLoseCauses()
{
	mLoseCauses[0].clear();
	mLoseCauses[1].clear();
	mLoseCauses[2].clear();
	mLoseCauses[3].clear();
	_16 = 0;
}

/*
 * --INFO--
 * Address:	80229514
 * Size:	0001D4
 */
void GameState::do_init(VsGameSection* section)
{
	moviePlayer->mActingCamera = section->mOlimarCamera;
	mFlags.clear();

	if (!gameSystem->isVersusMode()) {
		MoviePlayArg arg("s0B_cv_coursein", nullptr, section->mMovieFinishCallback, 0);
		arg.mDelegateStart = section->mMovieStartCallback;
		mapMgr->getStartPosition(arg.mOrigin, 0);
		arg.mOrigin.y = mapMgr->getMinY(arg.mOrigin);

		ItemOnyon::mgr->mPod;
		if (ItemOnyon::mgr->mPod) {
			arg.mAngle = ItemOnyon::mgr->mPod->getFaceDir();
		}

		moviePlayer->play(arg);
		Screen::gGame2DMgr->startCount_Floor();

	} else {
		open_GameChallenge(section, 1);
		gameSystem->setPause(false, "vs-readygo", 3);
		gameSystem->setPause(true, "vs readygo", 6);
		gameSystem->setMoviePause(true, "vs readygo");
		setFlag(VSGS_Unk8);
		gameSystem->setFlag(GAMESYS_IsPlaying);
		section->setCamController();
	}

	if (gameSystem->isVersusMode()) {
		section->createVsPikmins();
		section->initCardGeneration();
	} else {
		section->createFallPikmins(section->mContainer1, 0);
	}

	Screen::gGame2DMgr->mScreenMgr->mInCave = 1;
}

/*
 * --INFO--
 * Address:	802296E8
 * Size:	00000C
 */
bool GameState::goingToCave(VsGameSection* section) { return isFlag(VSGS_Unk1); }

/*
 * This fake function is here to generate the vtables in the correct order
 * - I cannot see a way for them to generate correctly without something here to
 * spawn DispMemberChallenge2P 'before' (after) DispWinLose, so this will have to suffice. - HP
 */
static void fakeFuncVsGsGame() { og::Screen::DispMemberChallenge2P disp; }

void pikminZeroFunc(int idx) {
	
	VsGameSection* section = static_cast<VsGameSection*>(gameSystem->mSection);

	MoviePlayArg movieArg("s05_pikminzero", nullptr, section->mMovieFinishCallback, idx);
	movieArg.mDelegateStart = section->mMovieStartCallback;

	Navi* deadNavi = naviMgr->getAt(idx);
	movieArg.setTarget(deadNavi);
	moviePlayer->mTargetNavi = deadNavi;
	switch (idx)
	{
	case 0:
		moviePlayer->mActingCamera = section->mOlimarCamera;
		break;
	case 1:
		moviePlayer->mActingCamera = section->mLouieCamera;
		break;
	case 2:
		moviePlayer->mActingCamera = gCameraP3;
		break;
	case 3:
		moviePlayer->mActingCamera = gCameraP4;
		break;
	}

	Screen::gGame2DMgr->open_GameOver(Screen::Game2DMgr::GOTITLE_PikminZero);
	moviePlayer->play(movieArg);

	
}

/*
 * --INFO--
 * Address:	802296F4
 * Size:	0008FC
 */

void GameState::setDeathLose() {
	for (int i = 0; i < Game::gNaviNum; i++) {
		if (mNaviStatus[i] != -1 && mExtinctions[getVsTeam(i)]) {
			setLoseCause(getVsTeam(i), mNaviStatus[i]);
		}
	}
}

bool GameState::isWinExtinction() {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (mExtinctions[i]) {
			count++;
		}
	}
	return count >= 3;
}


int GameState::getExtinctionWinner() {
	for (int i = 0; i < 4; i++) {
		if (!mExtinctions[i]) {
			return i;
		}
	}
	return -1;
}

void GameState::checkVsPikminZero(VsGameSection* section) {
	for (int teamID = 0; teamID < 4; teamID++) {
		int pikiColor = getPikiFromTeamEnum(teamID);
		if (isTeamActive(teamID) && GameStat::getAllPikmins(pikiColor) == 0 && ItemOnyon::mgr->getOnyon(pikiColor)->mToBirth == 0) {
			for (int i = 0; i < 4; i++) {
				if (getVsPikiColor(i) == pikiColor && mNaviStatus[i] == -1) {
					mNaviStatus[i] = VSLOSE_Extinction;
					mOrimaDownState[i] = 3;
				}
			}
			for (int i = 0; i < 4; i++) {
				if (getVsPikiColor(i) == pikiColor && !mExtinctions[teamID]) {
					
					mExtinctions[teamID] = true;
					naviMgr->getAt(i)->movie_begin(true);
					if (isWinExtinction()) {
						setDeathLose();
					}
					else {
						pikminZeroFunc(i);
					}
				}
			}

		}
	}
}

void GameState::onOrimaDownDone(int idx) {

}

void GameState::exec(VsGameSection* section)
{
	if (isFlag(VSGS_Unk16)) {
		return;
	}

	section->BaseGameSection::doUpdate();

	for (int i = 0; i < 4; i++) {
		if (mNaviStatus[i] != -1) {
			naviMgr->getAt(i)->disableController();
		}
	}

	// if (gFancyCamera) {
	// 	section->updateFancyCam();
	// }

	if (section->mState->mId != VGS_Game) {
		return;
	}

	if (isFlag(VSGS_Unk8)) {
		switch (Screen::gGame2DMgr->check_ReadyGo()) {
		case 1:
			gameSystem->setPause(false, "vs-rg-arr", 3);
			gameSystem->setMoviePause(false, "vs-rg-arr");
			resetFlag(VSGS_Unk8);
			gameSystem->setFlag(GAMESYS_IsPlaying);
			break;

		default:
			return;
		}
	}

	if (gameSystem->isChallengeMode()) {
		checkFindKeyDemo(section);

	} else if (!gameSystem->paused_soft() && gameSystem->isVersusMode()) {
		updateNavi(section, VSPLAYER_Red);
		updateNavi(section, VSPLAYER_Blue);
		updateNavi(section, VSPlayer_Purple);
		updateNavi(section, VSPlayer_White);

		if (vsSlotCardMgr) {
			vsSlotCardMgr->update();
		}

		if (!gameSystem->paused() && mTimeLeft >= 0.0f && !section->mMenuFlags
		    && !moviePlayer->mDemoState) 
		{
			if (gConfig[SPICY_PASSIVE] != ConfigEnums::SPICYPASSIVE_OFF && gConfig[SPICY_PASSIVE] != ConfigEnums::SPICYPASSIVE_INF) {
				gPassiveSpicy  -= sys->mDeltaTime;
				if (gPassiveSpicy <= 0.0f) {
					DebugReport("Inc Spicy Dope\n");
					gPassiveSpicy += sSprayTimers[gConfig[SPICY_PASSIVE]];
					incAllGlobalDope(SPRAY_TYPE_SPICY);
				}
			}
			if (gConfig[BITTER_PASSIVE] != ConfigEnums::BITTERPASSIVE_OFF && gConfig[BITTER_PASSIVE] != ConfigEnums::BITTERPASSIVE_INF) {
				gPassiveBitter -= sys->mDeltaTime;
				if (gPassiveBitter <= 0.0f) {
					gPassiveBitter += sSprayTimers[gConfig[BITTER_PASSIVE]];
					incAllGlobalDope(SPRAY_TYPE_BITTER);
				}
			}

			if (gConfig[STALEMATE_TIMER]) {
				mTimeLeft -= sys->mDeltaTime;

				if (mTimeLeft <= 0.0f) {
					vsTimeUp(section);
				}
			}
		}
	}

	checkPikminZero(section);
	

	if (gameSystem->isVersusMode()) {
		section->calcVsScores();
		if (!gameSystem->paused()) {
			section->updateCardGeneration();
			section->mCardMgr->update();
		}

		if (isFlag(VSGS_Unk9)) {
			if ((u8)Screen::gGame2DMgr->check_WinLoseReason()) {
				resetFlag(VSGS_Unk9);
				setFlag(VSGS_Unk10);
				int outcome;
				int outcomes[4] = {0, 0, 0, 0};
				u8 redLost    = getLoseCauses(VSPLAYER_Red);
				u8 blueLost   = getLoseCauses(VSPLAYER_Blue);
				u8 whiteLost  = getLoseCauses(VSPlayer_White);
				u8 purpleLost = getLoseCauses(VSPlayer_Purple);

				DebugReport("Loss %i, %i, %i, %i\n", redLost, blueLost, whiteLost, purpleLost);

				if (!isTeamActive(VSPLAYER_Red)) {
					redLost = 3;
				}

				if (!isTeamActive(VSPLAYER_Blue)) {
					blueLost = 3;
				}

				if (!isTeamActive(VSPlayer_White)) {
					whiteLost = 3;
				}
				if (!isTeamActive(VSPlayer_Purple)) {
					purpleLost = 3;
				}


				if (!redLost && !blueLost && !whiteLost && !purpleLost) { // neither player lost
					outcome = 3;             // draw
					VsGameSection::mDrawCount += 1;

				} else if (!redLost && doesTeamHavePlayers(TEAM_RED)) { // red didn't lose
					outcome = 1;       // red win
					VsGameSection::mRedWinCount += 1;
					section->mVsWinner = 0;
					DebugReport("Red Won\n");
					for (int i = 0; i < 4; i++) {
						DebugReport("Checking %i\n", i);
						if (getVsPikiColor(i) == Red) {
							DebugReport("Red Team Member %i\n", i);
							mRealWinCounts[i]++;
							outcomes[i] = 1;
						}
					}

				} else if (!blueLost && doesTeamHavePlayers(TEAM_BLUE)) { // blue didn't lose
					outcome = 2;        // blue win
					VsGameSection::mBlueWinCount += 1;
					section->mVsWinner = 1;
					DebugReport("Blue Won\n");
					for (int i = 0; i < 4; i++) {
						if (getVsPikiColor(i) == Blue) {
							DebugReport("Blue Team Member %i\n", i);
							mRealWinCounts[i]++;
							outcomes[i] = 1;
						}
					}
				} else if (!whiteLost && doesTeamHavePlayers(TEAM_WHITE)) {
					outcome = 1;        // blue win
					VsGameSection::mWhiteWinCount += 1;
					section->mVsWinner = 2;
					DebugReport("White Won\n");
					for (int i = 0; i < 4; i++) {
						if (getVsPikiColor(i) == White) {
							mRealWinCounts[i]++;
							outcomes[i] = 1;
						}
					}
				} else if (!purpleLost && doesTeamHavePlayers(TEAM_PURPLE)) {
					outcome = 1;        // blue win
					VsGameSection::mPurpleWinCount += 1;
					section->mVsWinner = 3;
					DebugReport("Purple Won\n");
					for (int i = 0; i < 4; i++) {
						if (getVsPikiColor(i) == Purple) {
							mRealWinCounts[i]++;
							outcomes[i] = 1;
						}
					}
				}
				else {         // both lost/something wacky happened
					DebugReport("Draw!\n");
					outcome = 3; // draw
					VsGameSection::mDrawCount += 1;
				}

				if (mTimeLeft <= 0.0f) {
					for (int i = 0; i < 4; i++) {
						if (outcomes[i] == 0 || outcome == 3) {
							outcomes[i] = -1; // timeup
						}
						outcome = Timeup2P;
					}
				}


				kh::Screen::DispWinLose winLose(outcome, 1, outcomes, false);
				Screen::gGame2DMgr->open_WinLose(winLose);
				
				return;

			} else {
				return;
			}
		}

		if (isFlag(VSGS_Unk10)) {
			switch (Screen::gGame2DMgr->check_WinLose()) {
			case 0:
			case 1:
			case 2:
				break;
			case 3:
				TitleArg arg;
				arg._00 = 1;
				transit(section, VGS_Title, &arg);
			}
			return;
		}

		if (!_16) {
			checkVsPikminZero(section);
			checkOrimaDown(section);
		}

	} else {
		PSM::PikminNumberDirector* pikiDirector = PSMGetPikminNumD();
		if (GameStat::getMapPikmins_exclude_Me(-1) < 10 && DeathMgr::mSoundDeathCount > 0) {
			if (pikiDirector) {
				pikiDirector->directOn();
			}

		} else if (pikiDirector) {
			pikiDirector->directOff();
		}

		if (isFlag(VSGS_Unk4)) {
			switch (Screen::gGame2DMgr->check_WinLose()) {
			case 0:
			case 1:
			case 2:
				break;
			case 3:
				GameStat::alivePikis.clear();
				ResultArg arg;
				arg.mEndFlag.clear();
				transit(section, VGS_Result, &arg);
			}
			return;
		}

		if (!gameSystem->paused() && section->mTimeLimit > 0.0f && isFlag(VSGS_Unk3) && !section->mMenuFlags
		    && gameSystem->isFlag(GAMESYS_Unk6) && !gameSystem->paused_soft()
		    && !moviePlayer->mDemoState) { // check game is in a state where timer should go down (not paused/menu/CS/etc)

			section->mTimeLimit -= sys->mDeltaTime * 0.5f;
			if (section->mTimeLimit <= 0.0f && !(isFlag(VSGS_Unk4))) {
				gameSystem->resetFlag(GAMESYS_Unk6);
				gameSystem->setPause(true, "timeup", 3);
				gameSystem->setMoviePause(true, "timeup");
				setFlag(VSGS_Unk4);

				if (!gameSystem->isMultiplayerMode()) {
					Screen::gGame2DMgr->open_TimeUp1P();
					return;
				}
				Screen::gGame2DMgr->open_TimeUp2P();
				return;
			}
		}
	}

	if (!isFlag(VSGS_Unk1) && section->mHole) {
		switch (Screen::gGame2DMgr->check_CaveMoreMenu()) {
		case 0:
			break;

		case 1:
			gameSystem->resetFlag(GAMESYS_Unk6);
			gameSystem->setPause(false, "cmore-yes", 3);
			gameSystem->setMoviePause(false, "cmore-yes");
			section->goNextFloor(section->mHole);
			setFlag(VSGS_Unk1);
			return;

		case 2:
			gameSystem->setPause(false, "cmore-no", 3);
			gameSystem->setMoviePause(false, "cmore-no");
			break;

		case 3:
			gameSystem->resetFlag(GAMESYS_Unk6);
			gameSystem->setMoviePause(false, "cmore-zenk");
			break;
		}
	}

	if (!section->mMenuFlags || section->updateCaveMenus()) {
		update_GameChallenge(section);
		if (!_16) {
			checkSMenu(section);
		}


		// check we're in VS Mode and that someone needs to lose
		if (gameSystem->isVersusMode() && !isFlag(VSGS_Unk9) && !isFlag(VSGS_Unk10) && _16 != 1
		    && (getLoseCauses(VSPLAYER_Red) || getLoseCauses(VSPLAYER_Blue) || getLoseCauses(VSPlayer_White) || getLoseCauses(VSPlayer_Purple))) {
			gameSystem->resetFlag(GAMESYS_Unk6);
			setFlag(VSGS_Unk9);
			gameSystem->setPause(true, nullptr, 3);

			int redReason  = -1;
			int blueReason = -1;
			if (isLoseCause(VSPLAYER_Red, VSLOSE_ColoredMarble)) {
				blueReason = 3;

			} else if (isLoseCause(VSPLAYER_Red, VSLOSE_OrimaDown)) {
				redReason = 1;

			} else if (isLoseCause(VSPLAYER_Red, VSLOSE_Extinction)) {
				redReason = 2;
			}

			if (blueReason == 3) {

			} else if (isLoseCause(VSPLAYER_Blue, VSLOSE_ColoredMarble)) {
				redReason = 3;

			} else if (isLoseCause(VSPLAYER_Blue, VSLOSE_OrimaDown)) {
				blueReason = 1;

			} else if (isLoseCause(VSPLAYER_Blue, VSLOSE_Extinction)) {
				blueReason = 2;
			}

			kh::Screen::DispWinLoseReason winLoseReason;
			winLoseReason.mOutcomeRed = -1;
			winLoseReason.mOutcomeBlue = -1;

			for (int i = 0; i < 4; i++) {
				DebugReport("Outcome for %i: %i\n", i, mNaviStatus[i]);
				winLoseReason.mOutcomeNavis[i] = mNaviStatus[i];
			}

			P2ASSERTLINE(513, Screen::gGame2DMgr->open_WinLoseReason(winLoseReason));
		}
	}
}

/*
 * --INFO--
 * Address:	80229FF0
 * Size:	000388
 */
void GameState::checkFindKeyDemo(VsGameSection* section)
{
	if (!mHasKeyDemoPlayed) {
		Navi* navi = naviMgr->getActiveNavi();
		if (navi) {
			Iterator<Game::PelletItem::Object> pelletIterator(PelletItem::mgr);
			CI_LOOP(pelletIterator)
			{
				PelletItem::Object* obj = (*pelletIterator);
				if (obj->getConfigIndex() == 12) {
					Vector3f pos = obj->getPosition();

					Sys::Sphere sphere(pos, 100.0f + obj->getBottomRadius());

					if (navi->checkDemoNaviAndPiki(sphere) && sys->getPlayCommonData()->challenge_is_virgin()) {
						MoviePlayArg arg("s16_find_key", nullptr, section->mMovieFinishCallback, 0);
						arg.mDelegateStart = section->mMovieStartCallback;
						arg.mOrigin        = obj->getPosition();

						arg.mAngle = JMath::atanTable_.atan2_(obj->mObjMatrix(0, 2), obj->mObjMatrix(2, 2));

						moviePlayer->mTargetObject = obj;
						moviePlayer->play(arg);

						mHasKeyDemoPlayed = true;
					}
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8022A378
 * Size:	0003E4
 */
void GameState::checkSMenu(VsGameSection* section)
{
	switch (Screen::gGame2DMgr->check_SMenu()) {
	case 1:
		gameSystem->setPause(false, "sm-canc", 3);
		gameSystem->setMoviePause(false, "sm-canc");
	case 0: // this is just cursed
		return;

	case 2:
		JUT_PANICLINE(617, "‚ ‚è‚¦‚È‚¢‚Á‚·\n"); // 'impossible'
		return;

	case 3:
		JUT_PANICLINE(620, "‚È‚¢\n"); // 'no'
		return;

	case 5:
		gameSystem->setMoviePause(false, "sm-quit");
		if (gameSystem->isVersusMode()) {
			section->mVsWinner = -1;
			gameSystem->resetFlag(GAMESYS_Unk6);
			TitleArg titleArg;
			titleArg._00 = 1;
			transit(section, VGS_Title, &titleArg);
			return;
		}
		if (moviePlayer->mDemoState == 0 && !isFlag(VSGS_Unk2)) {
			gameSystem->resetFlag(GAMESYS_Unk6);
			MoviePlayArg movieArgs("s12_cv_giveup", 0x0, section->mMovieFinishCallback, 0);
			movieArgs.mDelegateStart = section->mMovieStartCallback;
			Onyon* onyon             = ItemOnyon::mgr->mPod;
			JUT_ASSERTLINE(652, onyon, "no pod demo 12");
			movieArgs.mOrigin = onyon->getPosition();
			movieArgs.mAngle  = onyon->getFaceDir();
			for (int i = 0; i < 2; i++) {
				Navi* navi = naviMgr->getAt(i);
				if (navi->isAlive() && navi->isStickTo()) {
					navi->endStick();
				}
			}
			moviePlayer->play(movieArgs);
			return;
		}
		gameSystem->setMoviePause(false, "sm-quit");
		gameSystem->setPause(false, "sm-quit", 3);
		return;
	}

	if (moviePlayer->mDemoState == 0 && !gameSystem->paused_soft()) {
		Controller* controllers[4] = { section->mControllerP1, section->mControllerP2, gControllerP3, gControllerP4 };
		for (int i = 0; i < ARRAY_SIZE(controllers); i++) {
			if (controllers[i]->isButtonDown(JUTGamePad::PRESS_START)) {
				og::Screen::DispMemberSMenuAll sMenu;
				int versus = 2;
				if (gameSystem->isVersusMode()) {
					versus = 1;
				}
				sMenu.mOpenMode = versus;
				Screen::gGame2DMgr->setGamePad(controllers[i]);
				if (Screen::gGame2DMgr->open_SMenu(sMenu)) {
					gameSystem->setPause(true, "open-sm", 3);
					gameSystem->setMoviePause(true, "open-sm");
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8022A75C
 * Size:	000050
 */
void GameState::pre2dDraw(Graphics& gfx, VsGameSection* section)
{
	if (gameSystem->isVersusMode() && !mFlags.typeView && !moviePlayer->mDemoState) {
		section->mCardMgr->draw(gfx);
	}
}

/*
 * --INFO--
 * Address:	8022A7AC
 * Size:	000034
 */
void GameState::draw(VsGameSection* section, Graphics& gfx)
{
	if (!isFlag(VSGS_Unk16)) {
		section->BaseGameSection::doDraw(gfx);
	}
}

/*
 * --INFO--
 * Address:	8022A7E0
 * Size:	000044
 */
void GameState::cleanup(VsGameSection* section)
{
	gameSystem->resetFlag(GAMESYS_IsPlaying);
	gameSystem->setMoviePause(false, "vsgs_game:clean");
	PSMCancelToPauseOffMainBgm();
}

/*
 * --INFO--
 * Address:	8022A824
 * Size:	000034
 */
void GameState::onBattleFinished(VsGameSection* section, int winnerMaybe, bool check)
{
	if (_16) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (i != winnerMaybe) {
			setLoseCause(i, VSLOSE_ColoredMarble);
		}
	}

	if (check) {
		_16 = 1;
	}
}

/*
 * --INFO--
 * Address:	8022A858
 * Size:	000010
 */
bool GameState::isCardUsable(VsGameSection* section) { return (u32) !(_16); }

void GameState::setWinMarbleColor(int teamID, int color) {

}

/*
 * --INFO--
 * Address:	8022A868
 * Size:	00014C
 */
void GameState::onRedOrBlueSuckStart(VsGameSection* section, int player, MarbleType marbleType)
{
	if (marbleType == RED_OR_BLUE && !_16 && gConfig[CAPTURE_MARBLE] == ConfigEnums::CAPTURE_STEALMARBLE) {
		section->mRealMarbleCounts[player] += section->mDispMarbleCounts[gBedamaColor];
		section->mDispMarbleCounts[player] += section->mDispMarbleCounts[gBedamaColor];

		section->mRealMiniCounts[player] += section->mDispMiniCounts[gBedamaColor];
		section->mDispMiniCounts[player] += section->mDispMiniCounts[gBedamaColor];

		section->mRealMarbleCounts[gBedamaColor] -= section->mDispMarbleCounts[gBedamaColor];
		section->mDispMarbleCounts[gBedamaColor] -= section->mDispMarbleCounts[gBedamaColor];

		section->mDispMiniCounts[gBedamaColor] -= section->mDispMiniCounts[gBedamaColor];
		section->mRealMiniCounts[gBedamaColor] -= section->mDispMiniCounts[gBedamaColor];
		
		if (section->mRealMiniCounts[player] >= 5) {
			section->mRealMiniCounts[player] -= 5;
			section->mDispMiniCounts[player] -= 5;
			section->mRealMarbleCounts[player]++;			
		}

		if (section->mRealMarbleCounts[player] >= 4) {
			marbleType = YELLOW;
			section->mRealMarbleCounts[player] = 3;
			section->mDispMarbleCounts[player] = 4;
		}
	}

	if (marbleType == MINI) {
		section->mRealMiniCounts[player]++;
		if (section->mRealMiniCounts[player] == 5) {
			section->mRealMiniCounts[player] = 0;
			section->mDispMiniCounts[player] = 0;
			marbleType = YELLOW;
		}
		else {
			return;
		}
	}

	if (marbleType == YELLOW) {
		section->mRealMarbleCounts[player]++;
		if (section->mRealMarbleCounts[player] == 4 && !_16) {
			_16 = true;

			u8 loseReason = VSLOSE_ColoredMarble;

			for (int i = 0; i < 4; i++) {
				if (i != player) {
					BitFlag<u8>& loseCauses = mLoseCauses[i];
					setLoseCause(loseCauses, loseReason);
				}
			}

			mWinColors[player] = gBedamaColor;
			DebugReport("Win color %i %i\n", player, gBedamaColor);
			Onyon* onyon                 = ItemOnyon::mgr->getOnyon(getPikiFromTeamEnum(player));
			BaseGameSection* baseSection = gameSystem->mSection;

			MoviePlayArg movieArgs("x19_vs_bedama", nullptr, baseSection->mMovieFinishCallback, 0);
			movieArgs.mPelletName    = const_cast<char*>(VsOtakaraName::cBedamaRed);
			movieArgs.mDelegateStart = baseSection->mMovieStartCallback;
			movieArgs.setTarget(onyon);

			moviePlayer->play(movieArgs);
		}
		return;
		
	}

	
	if (_16) {
		return;
	}

	switch (gConfig[CAPTURE_MARBLE])
	{
	case ConfigEnums::CAPTURE_VICTORY: {
		_16 = 1;

		u8 loseReason = VSLOSE_ColoredMarble | VSLOSE_Marble;

		for (int i = 0; i < 4; i++) {
			if (i != player) {
				BitFlag<u8>& loseCauses = mLoseCauses[i];
				setLoseCause(loseCauses, loseReason);
			}
		}

		mWinColors[player] = gBedamaColor;
		DebugReport("Win color %i %i\n", player, gBedamaColor);
		Onyon* onyon                 = ItemOnyon::mgr->getOnyon(getPikiFromTeamEnum(player));
		BaseGameSection* baseSection = gameSystem->mSection;

		MoviePlayArg movieArgs("x19_vs_bedama", nullptr, baseSection->mMovieFinishCallback, 0);
		movieArgs.mPelletName    = const_cast<char*>(VsOtakaraName::cBedamaRed);
		movieArgs.mDelegateStart = baseSection->mMovieStartCallback;
		movieArgs.setTarget(onyon);

		moviePlayer->play(movieArgs);
		break;
	}
	case ConfigEnums::CAPTURE_STEALSPRAY:
			
		gDopeCountArray[player][0] += gDopeCountArray[gBedamaColor][0];
		gDopeCountArray[player][1] += gDopeCountArray[gBedamaColor][1];			
	
	case ConfigEnums::CAPTURE_STEALMARBLE:
	case ConfigEnums::CAPTURE_KILLPIKI:
	case ConfigEnums::CAPTURE_ELIMINATE: 
		Onyon* onyon                 = ItemOnyon::mgr->getOnyon(getPikiFromTeamEnum(player));
		BaseGameSection* baseSection = gameSystem->mSection;

		MoviePlayArg movieArgs("x19_vs_bedama", nullptr, baseSection->mMovieFinishCallback, 0);
		movieArgs.mPelletName    = const_cast<char*>(VsOtakaraName::cBedamaRed);
		movieArgs.mDelegateStart = baseSection->mMovieStartCallback;
		movieArgs.setTarget(onyon);

		moviePlayer->play(movieArgs);
	}


	
}



/*
 * --INFO--
 * Address:	8022A9B4
 * Size:	000188
 */
void GameState::checkPikminZero(VsGameSection* section)
{
	if (!gameSystem->isVersusMode() && !isFlag(VSGS_Unk2) && GameStat::getAllPikmins(-1) == 0 && !gameSystem->paused_soft()
	    && gameSystem->isFlag(GAMESYS_Unk6)) {

		Navi* activeNavi = naviMgr->getActiveNavi();
		if (!activeNavi) {
			int naviIndex = 1;
			if (!gameSystem->mSection->mPrevNaviIdx) {
				naviIndex = 0;
			}
			activeNavi = naviMgr->getAt(naviIndex);
		}

		setFlag(VSGS_Unk2);

		MoviePlayArg movieArg("s05_pikminzero", nullptr, section->mMovieFinishCallback, 0);
		movieArg.mDelegateStart = section->mMovieStartCallback;
		movieArg.setTarget(activeNavi);
		moviePlayer->play(movieArg);

		Screen::gGame2DMgr->open_GameOver(Screen::Game2DMgr::GOTITLE_PikminZero);
	}
}

/*
 * --INFO--
 * Address:	8022AB3C
 * Size:	000474
 */
void GameState::onMovieStart(VsGameSection* section, MovieConfig* config, u32 p1, u32 p2)
{
	if (config->is("g2F_appear_hole") || config->is("g30_appear_fountain")) {
		Screen::gGame2DMgr->setToumeiBG();
	}

	if (config->is("s0B_cv_coursein")) {
		section->createFallPikminSound();
	}

	Screen::gGame2DMgr->startFadeBG_Floor();
	if (config->is("s03_orimadown")) {
		Screen::Game2DMgr::GameOverTitle gameOverTitle;
		if (p2 == 0) {
			gameOverTitle = Screen::Game2DMgr::GOTITLE_OlimarDown;
			if (!gameSystem->isMultiplayerMode()) {
				section->setPlayerMode(0);
			}
		} else {
			gameOverTitle = Screen::Game2DMgr::GOTITLE_LouieDown;
			if (!gameSystem->isMultiplayerMode()) {
				section->setPlayerMode(1);
			}
		}
		Screen::gGame2DMgr->open_GameOver(gameOverTitle);
	}

	if (config->is("s12_cv_giveup")) {
		Screen::gGame2DMgr->mScreenMgr->reset();
		Iterator<Piki> pikiIterator(pikiMgr);
		CI_LOOP(pikiIterator)
		{
			Piki* piki = *pikiIterator;
			if (piki->isAlive() && !piki->isStickTo()) {
				piki->movie_begin(false);
				piki->endStick();
				piki->mBrain->start(1, nullptr);
			}
		}
	}

	if (config->is("s09_holein")) {
		Vector3f holePos = section->mHole->getPosition();
		section->prepareHoleIn(holePos, true);
		pikiMgr->saveAllPikmins(section->mContainer1);
		for (int i = 0; i < 2; i++) {
			Navi* navi = naviMgr->getAt(i);
			if (navi->isAlive() && navi->isStickTo()) {
				navi->endStick();
			}
		}
		section->mHole = nullptr;
	}

	if (config->is("s0C_cv_escape")) {
		Vector3f fountainPos = section->mFountain->getPosition();
		section->prepareFountainOn(fountainPos);
	}
}

/*
 * --INFO--
 * Address:	8022AFB0
 * Size:	0009D0
 */
void GameState::onMovieDone(VsGameSection* section, MovieConfig* config, u32 p1, u32 p2)
{
	if (gameSystem->isMultiplayerMode()) {
		section->setPlayerMode(gNaviNum);
		section->setCamController();
	}

	RoomMapMgr* mgr   = static_cast<RoomMapMgr*>(mapMgr);
	int currFloor     = mgr->mSublevel;
	int floorMax      = mgr->mCaveInfo->getFloorMax();
	bool isFinalFloor = (currFloor == floorMax - 1);

	if (gameSystem->isChallengeMode() && Radar::Mgr::getNumOtakaraItems() == 0
	    && (config->is("g2F_appear_hole") || config->is("g30_appear_fountain"))) {

		PSSystem::SceneMgr* sceneMgr = PSSystem::getSceneMgr();
		checkSceneMgr(sceneMgr);
		PSM::Scene_Cave* scene = static_cast<PSM::Scene_Cave*>(sceneMgr->getChildScene());
		checkGameScene(scene);
		if (scene->isCave()) {
			scene->startPollutUpSe();
		}
	}

	if (config->is("x19_vs_bedama") && _16) {
		PSSystem::SceneMgr* sceneMgr = PSSystem::getSceneMgr();
		checkSceneMgr(sceneMgr);
		PSM::SceneBase* scene = static_cast<PSM::SceneBase*>(sceneMgr->getChildScene());

		scene = (scene->isGameScene()) ? scene : nullptr;

		scene->_10.stopAllSound(15);
	}
	else if (config->is("x19_vs_bedama")) {
		for (int i = 0; i < 4; i++) {
			if (getVsTeam(i) == gBedamaColor && mNaviStatus[i] == -1) {
				mNaviStatus[i] = VSLOSE_ColoredMarble;
				naviMgr->getAt(i)->kill(nullptr);
				naviMgr->informOrimaDead(i);
				naviMgr->getAt(i)->setDeadLaydown();
				gDrawNavi[i] = false;
			}
		}
		mExtinctions[gBedamaColor] = true;

		if (gConfig[CAPTURE_MARBLE] == ConfigEnums::CAPTURE_KILLPIKI) {
			section->killAllPiki(VsGame::gBedamaColor);
		}

		if (isWinExtinction()) {
			int winner = getExtinctionWinner();
			mWinColors[winner] = gBedamaColor;
			for (int i = 0; i < 4; i++) {
				if (i != winner) {
					setLoseCause(i, VSLOSE_Marble);
				}
			}
			onBattleFinished(section, winner, true);
			PSSystem::SceneMgr* sceneMgr = PSSystem::getSceneMgr();
			checkSceneMgr(sceneMgr);
			PSM::SceneBase* scene = static_cast<PSM::SceneBase*>(sceneMgr->getChildScene());

			scene = (scene->isGameScene()) ? scene : nullptr;

			scene->_10.stopAllSound(15);
			
		}
		else {
			section->startMainBgm();
		}
	}

	if (config->is("e00_E3_cavestart")) {
		gameSystem->setFlag(GAMESYS_IsPlaying);
		section->setCamController();

		if (isFinalFloor) {
			open_GameChallenge(section, 3);
		} else {
			open_GameChallenge(section, 1);
		}

		gameSystem->setPause(true, "readygo", 6);
		gameSystem->setMoviePause(true, "readygo");
		setFlag(VSGS_Unk8);

	} else if (config->is("s0B_cv_coursein")) {
		Iterator<Piki> pikiIterator(pikiMgr);
		CI_LOOP(pikiIterator)
		{
			Piki* piki       = *pikiIterator;
			Vector3f pikiPos = piki->getPosition();
			pikiPos.y        = mapMgr->getMinY(pikiPos);

			piki->setPosition(pikiPos, false);
			piki->mSimVelocity = Vector3f(0.0f);
			piki->mVelocity    = Vector3f(0.0f);
		}

		Screen::gGame2DMgr->close_Floor();
		setFlag(VSGS_Unk3);
		if (currFloor == 0) {
			if (sys->getPlayCommonData()->challenge_is_virgin_check_only()) {
				if (!gameSystem->isVersusMode()) {
					MoviePlayArg movieArg("e00_E3_cavestart", nullptr, section->mMovieFinishCallback, 0);
					if (gameSystem->isMultiplayerMode()) {
						section->setPlayerMode(0);
					}
					section->setCamController();
					movieArg.mDelegateStart = section->mMovieStartCallback;
					if (ItemOnyon::mgr->mPod) {
						Onyon* pod       = ItemOnyon::mgr->mPod;
						movieArg.mAngle  = pod->getFaceDir();
						movieArg.mOrigin = pod->getPosition();
					}

					movieArg.mOrigin.y = mapMgr->getMinY(movieArg.mOrigin);
					moviePlayer->play(movieArg);
					return;
				}
			}
		}

		gameSystem->setFlag(GAMESYS_IsPlaying);
		section->setCamController();
		gameSystem->setFlag(GAMESYS_IsPlaying);
		if (currFloor == 0) {
			if (isFinalFloor) {
				open_GameChallenge(section, 3);
			} else {
				open_GameChallenge(section, 1);
			}

			gameSystem->setPause(true, "readygo2", 6);
			gameSystem->setMoviePause(true, "readygo2");
			setFlag(VSGS_Unk8);

		} else if (isFinalFloor) {
			open_GameChallenge(section, 2);

		} else {
			open_GameChallenge(section, 0);
			PSSystem::SceneMgr* sceneMgr = PSSystem::getSceneMgr();
			sceneMgr->checkScene();

			sceneMgr->mScenes->mChild->startMainSeq();
		}

	} else if (config->is("s09_holein")) {
		PSMCancelToPauseOffMainBgm();
		section->mCurrentFloor++;
		LoadArg arg;
		arg._04 = 0;
		arg._08 = true;
		transit(section, VGS_Load, &arg);

	} else if (config->is("s12_cv_giveup")) {
		PSMCancelToPauseOffMainBgm();
		GameStat::alivePikis.clear();
		moviePlayer->clearSuspendedDemo();
		TitleArg arg;
		arg._00 = 1;
		transit(section, VGS_Title, &arg);

	} else if (config->is("s03_orimadown")) {
		naviMgr->informOrimaDead(p2);
		Screen::gGame2DMgr->close_GameOver();
		
		if (gameSystem->isVersusMode()) {
			naviMgr->getAt(p2)->setDeadLaydown();
			gDrawNavi[p2] = false;
			onOrimaDownDone(p2);
			return;
			JUT_PANICLINE(1279, "cannot happen !\n");

		} else {
			GameStat::alivePikis.clear();
			PSMCancelToPauseOffMainBgm();
			ResultArg arg;
			arg.mEndFlag.clear();
			transit(section, VGS_Result, &arg);
		}

	} else if (config->is("s05_pikminzero")) {
		Screen::gGame2DMgr->close_GameOver();
		og::Screen::DispMemberVs vs;
		vs.mBingoMgr = section->mBingoMgr;
		Screen::gGame2DMgr->open_GameVs(vs, 0);
		section->startMainBgm();
		if (gameSystem->isVersusMode()) {
			for (int i = 0; i < 4; i++) {
				if (getVsPikiColor(i) == getVsPikiColor(p2)) {
					naviMgr->getAt(i)->kill(nullptr);
					naviMgr->informOrimaDead(i);
					naviMgr->getAt(i)->setDeadLaydown();
					gDrawNavi[i] = false;
				}
			}

			return;
			JUT_PANICLINE(1279, "cannot happen !\n");
		}
		PSMCancelToPauseOffMainBgm();
		ResultArg arg;
		arg.mEndFlag.clear();
		transit(section, VGS_Result, &arg);

	} else if (config->is("s0C_cv_escape")) {
		PSMCancelToPauseOffMainBgm();
		ResultArg arg;
		arg.mEndFlag.clear();
		arg.mEndFlag.typeView |= 0x1;
		transit(section, VGS_Result, &arg);
	}
}

/*
 * --INFO--
 * Address:	8022B980
 * Size:	0000E4
 */
void GameState::onNextFloor(VsGameSection* section, ItemHole::Item* hole)
{
	MoviePlayArg movieArg("s09_holein", nullptr, section->mMovieFinishCallback, 0);

	movieArg.setTarget(hole);
	movieArg.mDelegateStart = section->mMovieStartCallback;
	movieArg.mDelegateStart = section->mMovieStartCallback;

	moviePlayer->mTargetObject = hole;

	moviePlayer->play(movieArg);
}

/*
 * --INFO--
 * Address:	8022BA64
 * Size:	00019C
 */
void GameState::onOrimaDown(VsGameSection* section, int idx)
{
	int teamIdx = getVsTeam(idx);
	mOrimaDownState[idx] = 1;

	P2ASSERTBOUNDSLINE(1341, 0, teamIdx, 4);

	if (gameSystem->isVersusMode()) {
		if (!_16) {
			mNaviStatus[idx] = VSLOSE_OrimaDown;
			bool naviTeamExinct = true;
			for (int i = 0; i < 4; i++) {
				if (i == idx) continue;
				DebugReport("mNaviStatus[%i] = %i\n", i, mNaviStatus[i]);
				if (mNaviStatus[i] == -1 && getVsPikiColor(idx) == getVsPikiColor(i)) {
					naviTeamExinct = false;
				}
			}
			DebugReport("naviTeamExtict %i\n", naviTeamExinct);
			if (naviTeamExinct) {
				mExtinctions[teamIdx] = true;
				DebugReport("mExtinctions[%i] = %i\n", teamIdx, mExtinctions[teamIdx]);
				if (isWinExtinction()) {
					mOrimaDownState[idx] = 3;
					setDeathLose();
				}
			}
		}
	}

	DebugReport("Downed Navi %i\n", idx);


}

void GameState::checkOrimaDown(VsGameSection* section) {
	int orimaDownCount = 0;
	for (int i = 0; i < 4; i++) {
		if (mOrimaDownState[i] > 0) {
			orimaDownCount++;
		}
		if (mOrimaDownState[i] == 1) {
			mOrimaDownState[i] = 2;
		}
	}

	if (orimaDownCount == 4) {
		for (int i = 0; i < 4; i++) {
			mExtinctions[i] = true;
			if (mNaviStatus[i] == -1) {
				mNaviStatus[i] = VSLOSE_OrimaDown;
				mOrimaDownState[i] = 3;
			}
		}
		setDeathLose();
		DebugReport("DRAW!\n");
		return;
	}

	for (int idx = 0; idx < 4; idx++) {
		if ((mOrimaDownState[idx] == 2 && orimaDownCount == 3)) {
			mNaviStatus[idx] = VSLOSE_OrimaDown;
			bool naviTeamExinct = true;
			for (int i = 0; i < 4; i++) {
				if (mNaviStatus[i] == -1 && getVsPikiColor(idx) == getVsPikiColor(i)) {
					naviTeamExinct = false;
				}
			}
			if (naviTeamExinct) {
				mExtinctions[getVsTeam(idx)] = true;
				if (isWinExtinction()) {
					DebugReport("Set death lose\n");
					setDeathLose();
				}
			}
		}
	}

	if (orimaDownCount >= 3) {
		for (int i = 0; i < 4; i++) {
			if (mOrimaDownState[i] == 2) {
				mOrimaDownState[i] = 3;
			}
		}
		return;
	}


	
	for (int i = 0; i < 4; i++) {
		if (mOrimaDownState[i] != 2) continue;
		MoviePlayArg movieArg("s03_orimadown", nullptr, section->mMovieFinishCallback, i);
		movieArg.mDelegateStart = section->mMovieStartCallback;

		Navi* deadNavi = naviMgr->getAt(i);
		movieArg.setTarget(deadNavi);
		moviePlayer->mTargetNavi = deadNavi;
		switch (i)
		{
		case 0:
			moviePlayer->mActingCamera = section->mOlimarCamera;
			break;
		case 1:
			moviePlayer->mActingCamera = section->mLouieCamera;
			break;
		case 2:
			moviePlayer->mActingCamera = gCameraP3;
			break;
		case 3:
			moviePlayer->mActingCamera = gCameraP4;
			break;
		}
		moviePlayer->play(movieArg);
		mOrimaDownState[i] = 3;
	}
}

/*
 * --INFO--
 * Address:	8022BC00
 * Size:	00033C
 */
void GameState::open_GameChallenge(VsGameSection* section, int in)
{
	if (!gameSystem->isMultiplayerMode()) {
		og::Screen::DispMemberChallenge1P disp;
		disp.mDataGame.mFloorNum = section->getCurrFloor();
		disp.mFloorExtendTimer   = mFloorExtendTimer;
		Screen::gGame2DMgr->open_GameChallenge1P(disp, in);

	} else if (gameSystem->isVersusMode()) {
		og::Screen::DispMemberVs disp;
		disp.mBingoMgr = section->mBingoMgr;
		Screen::gGame2DMgr->open_GameVs(disp, in);

	} else {
		og::Screen::DispMemberChallenge2P disp;
		disp.mDataGame.mFloorNum = section->getCurrFloor();
		disp.mFloorExtendTimer   = mFloorExtendTimer;
		Screen::gGame2DMgr->open_GameChallenge2P(disp, in);
	}
}

/*
 * --INFO--
 * Address:	8022BF3C
 * Size:	0007D0
 */
void GameState::update_GameChallenge(VsGameSection* section)
{
	if (!gameSystem->isMultiplayerMode()) {
		og::Screen::DispMemberChallenge1P disp;

		disp.mDataGame.mFloorNum = section->getCurrFloor();
		disp.mDeadPikiCount      = section->mDeadPikiCount;
		disp.mPokoCount          = section->mPokoCount;
		disp.mFloorExtendTimer   = mFloorExtendTimer;
		disp.mTimeLimit          = section->mTimeLimit;

		Navi* olimar                    = naviMgr->getAt(0);
		disp.mOlimarData.mFollowPikis   = GameStat::formationPikis.mCounter[0];
		disp.mOlimarData.mNextThrowPiki = olimar->ogGetNextThrowPiki();
		disp.mOlimarData.mDope1Count    = playData->getDopeCount(1);
		disp.mOlimarData.mDope0Count    = playData->getDopeCount(0);
		disp.mOlimarData.mNaviLifeRatio = olimar->getLifeRatio();

		Navi* louie                    = naviMgr->getAt(1);
		disp.mLouieData.mFollowPikis   = GameStat::formationPikis.mCounter[1];
		disp.mLouieData.mNextThrowPiki = louie->ogGetNextThrowPiki();
		disp.mLouieData.mDope1Count    = playData->getDopeCount(1);
		disp.mLouieData.mDope0Count    = playData->getDopeCount(0);
		disp.mLouieData.mNaviLifeRatio = louie->getLifeRatio();

		Navi* activeNavi = naviMgr->getActiveNavi();
		int check        = 2;
		if (activeNavi) {
			check = activeNavi->mNaviIndex;
		}

		if (check == 0) {
			disp.mOlimarData.mActiveNaviID = 1;
			disp.mLouieData.mActiveNaviID  = 0;

		} else if (check == 1) {
			disp.mOlimarData.mActiveNaviID = 0;
			disp.mLouieData.mActiveNaviID  = 1;

		} else if (section->mPrevNaviIdx == 0) {
			disp.mOlimarData.mActiveNaviID = 0;
			disp.mLouieData.mActiveNaviID  = 1;

		} else {
			disp.mOlimarData.mActiveNaviID = 1;
			disp.mLouieData.mActiveNaviID  = 0;
		}

		disp.mDataGame.mMapPikminCount = GameStat::getMapPikmins(-1);
		Screen::gGame2DMgr->setDispMember(&disp);
		return;
	}

	if (gameSystem->isVersusMode()) {
		if (Screen::gGame2DMgr->check_VsStatus() == 2 && _16 == 1 && !(moviePlayer->mFlags & MoviePlayer::IS_ACTIVE)) {
			_16 = 2;
		} else if (_16 == 1) {
			Screen::gGame2DMgr->check_VsStatus(); // probably in a leftover && check
		}

		og::Screen::DispMemberVs disp;
		disp.mBingoMgr = section->mBingoMgr;

		Navi* olimar                    = naviMgr->getAt(0);
		disp.mOlimarData.mFollowPikis   = GameStat::formationPikis.mCounter[0];
		disp.mOlimarData.mNextThrowPiki = olimar->ogGetNextThrowPiki();
		disp.mOlimarData.mDope1Count    = olimar->getDopeCount(1);
		disp.mOlimarData.mDope0Count    = olimar->getDopeCount(0);
		disp.mOlimarData.mNaviLifeRatio = olimar->getLifeRatio();

		Navi* louie                    = naviMgr->getAt(1);
		disp.mLouieData.mFollowPikis   = GameStat::formationPikis.mCounter[1];
		disp.mLouieData.mNextThrowPiki = louie->ogGetNextThrowPiki();
		disp.mLouieData.mDope1Count    = louie->getDopeCount(1);
		disp.mLouieData.mDope0Count    = louie->getDopeCount(0);
		disp.mLouieData.mNaviLifeRatio = louie->getLifeRatio();

		Navi* navi3 = naviMgr->getAt(2);
		if (navi3 && navi3->isAlive()) {
			disp.mP3Data.mFollowPikis = GameStat::formationPikis.mCounter[2];
			disp.mP3Data.mNextThrowPiki = navi3->ogGetNextThrowPiki();
			disp.mP3Data.mDope1Count    = navi3->getDopeCount(1);
			disp.mP3Data.mDope0Count    = navi3->getDopeCount(0);
			disp.mP3Data.mNaviLifeRatio = navi3->getLifeRatio();
		}

		Navi* navi4 = naviMgr->getAt(3);
		if (navi4 && navi4->isAlive()) {
			disp.mP4Data.mFollowPikis = GameStat::formationPikis.mCounter[3];
			disp.mP4Data.mNextThrowPiki = navi4->ogGetNextThrowPiki();
			disp.mP4Data.mDope1Count    = navi4->getDopeCount(1);
			disp.mP4Data.mDope0Count    = navi4->getDopeCount(0);
			disp.mP4Data.mNaviLifeRatio = navi4->getLifeRatio();
		}

		disp.mHideP4 = gFancyCamera;
		disp.mTwoPlayer = gNaviNum <= 2;

		disp.mP1PikminCount = GameStat::getMapPikmins(gVsNaviIndexArray[0]);
		disp.mP2PikminCount = GameStat::getMapPikmins(gVsNaviIndexArray[1]);
		disp.mP3PikminCount = GameStat::getMapPikmins(gVsNaviIndexArray[2]);
		disp.mP4PikminCount = GameStat::getMapPikmins(gVsNaviIndexArray[3]);

		disp.mFlags[2] = section->mGhostIconTimers[0] > 0.0f;
		disp.mFlags[3] = section->mGhostIconTimers[1] > 0.0f;

		disp.mFlag2[2] = section->mGhostIconTimers[2] > 0.0f;
		disp.mFlag2[3] = section->mGhostIconTimers[3] > 0.0f;

		disp.mGhostIconTimerP1 = section->mGhostIconTimers[0];
		disp.mGhostIconTimerP2 = section->mGhostIconTimers[1];
		disp.mGhostIconTimerP3 = section->mGhostIconTimers[2];
		disp.mGhostIconTimerP4 = section->mGhostIconTimers[3];

		int marbleCountP1 = section->mDispMarbleCounts[getVsTeam(0)];
		int marbleCountP2 = section->mDispMarbleCounts[getVsTeam(1)];
		int marbleCountP3 = section->mDispMarbleCounts[getVsTeam(2)];
		int marbleCountP4 = section->mDispMarbleCounts[getVsTeam(3)];

		if (marbleCountP1 == 4 && moviePlayer->mFlags & MoviePlayer::IS_ACTIVE) {
			marbleCountP1--;
		}

		if (marbleCountP2 == 4 && moviePlayer->mFlags & MoviePlayer::IS_ACTIVE) {
			marbleCountP2--;
		}

		if (marbleCountP3 == 4 && moviePlayer->mFlags & MoviePlayer::IS_ACTIVE) {
			marbleCountP3--;
		}

		if (marbleCountP4 == 4 && moviePlayer->mFlags & MoviePlayer::IS_ACTIVE) {
			marbleCountP4--;
		}


		disp.mMarbleCountP1 = marbleCountP1;
		disp.mMarbleCountP2 = marbleCountP2;
		if (Game::gNaviNum >= 3) {
			disp.mMarbleCountP3 = marbleCountP3;
			if (Game::gNaviNum == 4) disp.mMarbleCountP4 = marbleCountP4;
			else disp.mMarbleCountP4 = 0;
		}
		else {
			disp.mMarbleCountP3 = 0;
		}

		for (int i = 0; i < 4; i++) {
			disp.mWinMarbleColors[i] = mWinColors[getVsTeam_s(i)];

			disp.mNaviInactiveFlags[i] = mNaviStatus[i] != -1;
		}

		for (int i = 0; i < 4; i++) {
			disp.mMiniMarbleCounts[i] = section->mDispMiniCounts[i];
		}

		disp.mHideMiniMarble = !section->mHasMiniBedamas;

		disp.mTimerSecond = ((u32)mTimeLeft) % 60;
		disp.mTimerMinute = ((u32)mTimeLeft) / 60;

		bool blueMarble, redMarble, whiteMarble, purpleMarble;
		getMarbleLoss(redMarble, blueMarble, whiteMarble, purpleMarble);
		disp.setMarbleConditions(redMarble, blueMarble, whiteMarble, purpleMarble);

		Screen::gGame2DMgr->setDispMember(&disp);

		return;
	}

	og::Screen::DispMemberChallenge2P disp;

	disp.mDataGame.mFloorNum = section->getCurrFloor();

	disp.mPokos            = section->mPokoCount;
	disp.mFloorExtendTimer = mFloorExtendTimer;
	disp.mTimeLimit        = section->mTimeLimit;
	disp.mDeadPiki         = section->mDeadPikiCount;

	Navi* olimar                    = naviMgr->getAt(0);
	disp.mOlimarData.mFollowPikis   = GameStat::formationPikis.mCounter[0];
	disp.mOlimarData.mNextThrowPiki = olimar->ogGetNextThrowPiki();
	disp.mOlimarData.mDope1Count    = playData->getDopeCount(1);
	disp.mOlimarData.mDope0Count    = playData->getDopeCount(0);
	disp.mOlimarData.mNaviLifeRatio = olimar->getLifeRatio();

	Navi* louie                    = naviMgr->getAt(1);
	disp.mLouieData.mFollowPikis   = GameStat::formationPikis.mCounter[1];
	disp.mLouieData.mNextThrowPiki = louie->ogGetNextThrowPiki();
	disp.mLouieData.mDope1Count    = playData->getDopeCount(1);
	disp.mLouieData.mDope0Count    = playData->getDopeCount(0);
	disp.mLouieData.mNaviLifeRatio = louie->getLifeRatio();
	disp.mDataGame.mMapPikminCount = GameStat::getMapPikmins(-1);
	Screen::gGame2DMgr->setDispMember(&disp);

	
}

void GameState::vsTimeUp(VsGameSection* section) {
	int highestMarbleCount = 0;
	int highestID = 0;
	bool marbleDraw = true;

	for (int i = 0; i < ARRAY_SIZE(section->mDispMarbleCounts); i++) {
		int marbleCount = section->mDispMarbleCounts[i] * 5 + section->mDispMiniCounts[i];
		if (marbleCount > highestMarbleCount) {
			highestID = i;
			highestMarbleCount = marbleCount;
			marbleDraw = false;
		}
		else if (marbleCount == highestMarbleCount) {
			marbleDraw = true;
		}
	}

	if (marbleDraw) {
		for (int i = 0; i < 4; i++) {
			setLoseCause(i, VSLOSE_TIMEUP);
			mNaviStatus[i] = VSLOSE_TIMEUP;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (i == highestID) continue;
			mNaviStatus[i] = VSLOSE_TIMEUP;
			setLoseCause(i, VSLOSE_TIMEUP);
		}
	}
}

/*
 * --INFO--
 * Address:	8022C70C
 * Size:	000004
 */
void GameState::drawStatus(Graphics&, VsGameSection* section) { }

void GameState::onYellowBedamaGet(VsGameSection* section) {
	mTimeLeft += VS_TIMER_ADD_TIME;
}

void GameState::onMiniBedamaGet(VsGameSection* section) {
	mTimeLeft += VS_TIMER_ADD_TIME / 5;
}


} // namespace VsGame
} // namespace Game
