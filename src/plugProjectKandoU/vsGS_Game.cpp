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
#include "kh/WinLose.h"
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
	m_controller = new Controller(JUTGamePad::PORT_0);
}

/*
 * --INFO--
 * Address:	80229354
 * Size:	0001AC
 */
void GameState::init(VsGameSection* section, StateArg* stateArg)
{
	_16 = 0;
	m_flags.clear();
	section->refreshHIO();
	do_init(section);
	section->setFixNearFar(true, 1.0f, 12800.0f);
	DeathMgr::clear();
	gameSystem->m_flags &= ~0x2;
	gameSystem->m_flags |= 0x20;
	section->clearCaveMenus();
	if (!gameSystem->isMultiplayerMode()) {
		section->setPlayerMode(0);
	}
	if (gameSystem->m_mode == GSM_VERSUS_MODE) {
		section->setPlayerMode(2);
		clearLoseCauses();
		Screen::gGame2DMgr->startFadeBG_Floor();
	}
	m_hasKeyDemoPlayed = false;
	if (gameSystem->isChallengeMode()) {
		m_timer            = section->m_timeLimit;
		m_floorExtendTimer = section->m_challengeStageData->m_floorTimerExtentions[section->getCurrFloor()];
		m_displayTime      = m_timer / 4;
		section->m_timeLimit += m_floorExtendTimer;
	}
	section->_3D8                    = 0;
	section->_3D4                    = 0;
	section->m_yellowMarbleCounts[1] = 0;
	section->m_yellowMarbleCounts[0] = 0;
	section->m_obakeTimer[1]                 = 0.0f;
	section->m_obakeTimer[0]                 = 0.0f;
}

/*
 * --INFO--
 * Address:	80229500
 * Size:	000014
 */
void GameState::clearLoseCauses()
{
	m_loseCauses[0].clear();
	m_loseCauses[1].clear();
	_16 = 0;
}

/*
 * --INFO--
 * Address:	80229514
 * Size:	0001D4
 */
void GameState::do_init(VsGameSection* section)
{
	moviePlayer->_190 = section->_104;
	m_flags.clear();

	if (!gameSystem->isVersusMode()) {
		MoviePlayArg arg("s0B_cv_coursein", nullptr, section->_C8, 0);
		arg._10 = section->_CC;
		mapMgr->getStartPosition(arg.m_origin, 0);
		arg.m_origin.y = mapMgr->getMinY(arg.m_origin);

		ItemOnyon::mgr->m_pod;
		if (ItemOnyon::mgr->m_pod) {
			arg.m_angle = ItemOnyon::mgr->m_pod->getFaceDir();
		}

		moviePlayer->play(arg);
		Screen::gGame2DMgr->startCount_Floor();

	} else {
		open_GameChallenge(section, 1);
		gameSystem->setPause(false, "vs-readygo", 3);
		gameSystem->setPause(true, "vs readygo", 6);
		gameSystem->setMoviePause(true, "vs readygo");
		setFlag(VSGS_Unk8);
		gameSystem->setFlag(GAMESYS_Unk2);
		section->setCamController();
	}

	if (gameSystem->isVersusMode()) {
		section->createVsPikmins();
		section->initCardGeneration();
	} else {
		section->createFallPikmins(section->m_container1, 0);
	}

	Screen::gGame2DMgr->m_screenMgr->_91 = 1;
}

/*
 * --INFO--
 * Address:	802296E8
 * Size:	00000C
 */
bool GameState::goingToCave(VsGameSection* section) { return isFlag(VSGS_Unk1); }

/*
 * --INFO--
 * Address:	802296F4
 * Size:	0008FC
 */
void GameState::exec(VsGameSection* section)
{
	if (isFlag(VSGS_Unk16)) {
		return;
	}

	section->BaseGameSection::doUpdate();

	if (section->m_state->m_id != VGS_Game) {
		return;
	}

	if (isFlag(VSGS_Unk8)) {
		switch (Screen::gGame2DMgr->check_ReadyGo()) {
		case 1:
			gameSystem->setPause(false, "vs-rg-arr", 3);
			gameSystem->setMoviePause(false, "vs-rg-arr");
			resetFlag(VSGS_Unk8);
			gameSystem->setFlag(GAMESYS_Unk2);
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
	}

	checkPikminZero(section);

	if (gameSystem->isVersusMode()) {
		section->calcVsScores();
		if (!gameSystem->paused()) {
			section->updateCardGeneration();
			section->m_cardMgr->update();
		}

		if (isFlag(VSGS_Unk9)) {
			if ((u8)Screen::gGame2DMgr->check_WinLoseReason()) {
				resetFlag(VSGS_Unk9);
				setFlag(VSGS_Unk10);
				int outcome;
				u8 redLost  = getLoseCauses(VSPLAYER_Red);
				u8 blueLost = getLoseCauses(VSPLAYER_Blue);

				if (!redLost && !blueLost) { // neither player lost
					outcome = 3;             // draw
					VsGameSection::mDrawCount += 1;

				} else if (!redLost) { // red didn't lose
					outcome = 1;       // red win
					VsGameSection::mRedWinCount += 1;
					section->m_vsWinner = 0;

				} else if (!blueLost) { // blue didn't lose
					outcome = 2;        // blue win
					VsGameSection::mBlueWinCount += 1;
					section->m_vsWinner = 1;

				} else {         // both lost/something wacky happened
					outcome = 3; // draw
					VsGameSection::mDrawCount += 1;
					section->m_vsWinner = -1;
				}

				kh::Screen::DispWinLose winLose;
				winLose._08 = outcome;
				winLose._0C = 1;
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
			if (!GameStat::getAllPikmins(Red)) {
				setLoseCause(VSPLAYER_Red, VSLOSE_Extinction);
			}
			if (!GameStat::getAllPikmins(Blue)) {
				setLoseCause(VSPLAYER_Blue, VSLOSE_Extinction);
			}
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
				arg.m_endFlag.clear();
				transit(section, VGS_Result, &arg);
			}
			return;
		}

		if (!gameSystem->paused() && section->m_timeLimit > 0.0f && isFlag(VSGS_Unk3) && !section->m_menuFlags
		    && gameSystem->isFlag(GAMESYS_Unk6) && !gameSystem->paused_soft()
		    && !moviePlayer->m_demoState) { // check game is in a state where timer should go down (not paused/menu/CS/etc)

			section->m_timeLimit -= sys->m_deltaTime * 0.5f;
			if (section->m_timeLimit <= 0.0f && !(isFlag(VSGS_Unk4))) {
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

	if (!isFlag(VSGS_Unk1) && section->m_hole) {
		switch (Screen::gGame2DMgr->check_CaveMoreMenu()) {
		case 0:
			break;

		case 1:
			gameSystem->resetFlag(GAMESYS_Unk6);
			gameSystem->setPause(false, "cmore-yes", 3);
			gameSystem->setMoviePause(false, "cmore-yes");
			section->goNextFloor(section->m_hole);
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

	if (!section->m_menuFlags || section->updateCaveMenus()) {
		update_GameChallenge(section);
		if (!_16) {
			checkSMenu(section);
		}

		// check we're in VS Mode and that someone needs to lose
		if (gameSystem->isVersusMode() && !isFlag(VSGS_Unk9) && !isFlag(VSGS_Unk10) && _16 != 1
		    && (getLoseCauses(VSPLAYER_Red) || getLoseCauses(VSPLAYER_Blue))) {

			gameSystem->resetFlag(GAMESYS_Unk6);
			setFlag(VSGS_Unk9);
			gameSystem->setPause(true, nullptr, 3);

			int redReason  = -1;
			int blueReason = -1;
			if (isLoseCause(VSPLAYER_Red, VSLOSE_Unk3)) {
				blueReason = 3;

			} else if (isLoseCause(VSPLAYER_Red, VSLOSE_Unk1)) {
				redReason = 1;

			} else if (isLoseCause(VSPLAYER_Red, VSLOSE_Extinction)) {
				redReason = 2;
			}

			if (blueReason == 3) {

			} else if (isLoseCause(VSPLAYER_Blue, VSLOSE_Unk3)) {
				redReason = 3;

			} else if (isLoseCause(VSPLAYER_Blue, VSLOSE_Unk1)) {
				blueReason = 1;

			} else if (isLoseCause(VSPLAYER_Blue, VSLOSE_Extinction)) {
				blueReason = 2;
			}

			kh::Screen::DispWinLoseReason winLoseReason;
			winLoseReason._08 = redReason;
			winLoseReason._0C = blueReason;

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
	if (!m_hasKeyDemoPlayed) {
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
						MoviePlayArg arg("s16_find_key", nullptr, section->_C8, 0);
						arg._10      = section->_CC;
						arg.m_origin = obj->getPosition();

						arg.m_angle = JMath::atanTable_.atan2_(obj->m_mainMatrix(0, 2), obj->m_mainMatrix(2, 2));

						moviePlayer->m_targetObject = obj;
						moviePlayer->play(arg);

						m_hasKeyDemoPlayed = true;
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
		JUT_PANICLINE(617, "??????????????\n"); // 'impossible'
		return;

	case 3:
		JUT_PANICLINE(620, "????\n"); // 'no'
		return;

	case 5:
		gameSystem->setMoviePause(false, "sm-quit");
		if (gameSystem->isVersusMode()) {
			section->m_vsWinner = -1;
			gameSystem->m_flags &= ~0x20;
			TitleArg titleArg;
			titleArg._00 = 1;
			transit(section, VGS_Title, &titleArg);
			return;
		}
		if (moviePlayer->m_demoState == 0 && !isFlag(VSGS_Unk2)) {
			gameSystem->m_flags &= ~0x20;
			MoviePlayArg movieArgs("s12_cv_giveup", 0x0, section->_C8, 0);
			movieArgs._10 = section->_CC;
			Onyon* onyon  = ItemOnyon::mgr->m_pod;
			JUT_ASSERTLINE(652, onyon, "no pod demo 12");
			movieArgs.m_origin = onyon->getPosition();
			movieArgs.m_angle  = onyon->getFaceDir();
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

	if (moviePlayer->m_demoState == 0 && !gameSystem->paused_soft()) {
		if (section->_10C->isButtonDown(JUTGamePad::PRESS_START)) {
			og::Screen::DispMemberSMenuAll sMenu;
			int versus = 2;
			if (gameSystem->isVersusMode()) {
				versus = 1;
			}
			sMenu._BC = versus;
			Screen::gGame2DMgr->setGamePad(section->_10C);
			if (Screen::gGame2DMgr->open_SMenu(sMenu)) {
				gameSystem->setPause(true, "open-sm", 3);
				gameSystem->setMoviePause(true, "open-sm");
			}

		} else if (gameSystem->isMultiplayerMode()) {
			if ((section->_110->isButtonDown(JUTGamePad::PRESS_START))) {
				og::Screen::DispMemberSMenuAll sMenu;
				int versus = 2;
				if (gameSystem->isVersusMode()) {
					versus = 1;
				}
				sMenu._BC = versus;
				Screen::gGame2DMgr->setGamePad(section->_110);
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
	if (gameSystem->isVersusMode() && !m_flags.typeView && !moviePlayer->m_demoState) {
		section->m_cardMgr->draw(gfx);
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
	gameSystem->resetFlag(GAMESYS_Unk2);
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

	setLoseCause(1 - winnerMaybe, VSLOSE_Unk3);

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

/*
 * --INFO--
 * Address:	8022A868
 * Size:	00014C
 */
void GameState::onRedOrBlueSuckStart(VsGameSection* section, int player, bool isYellow)
{
	if (isYellow) {
		section->m_yellowMarbleCounts[player]++;
		if (isYellow && section->m_yellowMarbleCounts[player] < 4) {
			return;
		}
	}

	if (_16) {
		return;
	}

	_16 = 1;

	u8 loseReason = VSLOSE_Unk3;
	if (!isYellow) {
		loseReason |= VSLOSE_Marble;
	}

	BitFlag<u8>& loseCauses = m_loseCauses[1 - player];
	setLoseCause(loseCauses, loseReason);

	Onyon* onyon                 = ItemOnyon::mgr->getOnyon(1 - player);
	BaseGameSection* baseSection = gameSystem->m_section;

	MoviePlayArg movieArgs("x19_vs_bedama", nullptr, baseSection->_C8, 0);
	movieArgs._08 = const_cast<char*>(VsOtakaraName::cBedamaRed);
	movieArgs._10 = baseSection->_CC;
	movieArgs.setTarget(onyon);

	moviePlayer->play(movieArgs);
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
			if (!gameSystem->m_section->m_prevNaviIdx) {
				naviIndex = 0;
			}
			activeNavi = naviMgr->getAt(naviIndex);
		}

		setFlag(VSGS_Unk2);

		MoviePlayArg movieArg("s05_pikminzero", nullptr, section->_C8, 0);
		movieArg._10 = section->_CC;
		movieArg.setTarget(activeNavi);
		moviePlayer->play(movieArg);

		Screen::gGame2DMgr->open_GameOver(Screen::Game2DMgr::GOTITLE_PikminZero);
	}
	/*
	stwu     r1, -0x60(r1)
	mflr     r0
	stw      r0, 0x64(r1)
	stw      r31, 0x5c(r1)
	mr       r31, r4
	stw      r30, 0x58(r1)
	mr       r30, r3
	stw      r29, 0x54(r1)
	lwz      r5, gameSystem__4Game@sda21(r13)
	lwz      r0, 0x44(r5)
	cmpwi    r0, 1
	beq      lbl_8022AB20
	lhz      r0, 0x14(r30)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	bne      lbl_8022AB20
	li       r3, -1
	bl       getAllPikmins__Q24Game8GameStatFi
	cmpwi    r3, 0
	bne      lbl_8022AB20
	lwz      r3, gameSystem__4Game@sda21(r13)
	bl       paused_soft__Q24Game10GameSystemFv
	clrlwi.  r0, r3, 0x18
	bne      lbl_8022AB20
	lwz      r3, gameSystem__4Game@sda21(r13)
	lbz      r0, 0x3c(r3)
	rlwinm.  r0, r0, 0, 0x1a, 0x1a
	beq      lbl_8022AB20
	lwz      r3, naviMgr__4Game@sda21(r13)
	bl       getActiveNavi__Q24Game7NaviMgrFv
	or.      r29, r3, r3
	bne      lbl_8022AA64
	lwz      r3, gameSystem__4Game@sda21(r13)
	li       r4, 1
	lwz      r3, 0x58(r3)
	lwz      r0, 0xe4(r3)
	cmpwi    r0, 0
	bne      lbl_8022AA4C
	li       r4, 0

lbl_8022AA4C:
	lwz      r3, naviMgr__4Game@sda21(r13)
	lwz      r12, 0(r3)
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	mr       r29, r3

lbl_8022AA64:
	lhz      r0, 0x14(r30)
	lis      r3, lbl_8048363C@ha
	lfs      f0, lbl_8051A274@sda21(r2)
	addi     r5, r3, lbl_8048363C@l
	ori      r3, r0, 2
	li       r0, 0
	sth      r3, 0x14(r30)
	mr       r4, r29
	addi     r3, r1, 8
	lwz      r6, 0xc8(r31)
	stw      r5, 0x14(r1)
	stw      r0, 0x18(r1)
	stw      r6, 0x20(r1)
	stfs     f0, 0x2c(r1)
	stfs     f0, 0x30(r1)
	stfs     f0, 0x34(r1)
	stfs     f0, 0x38(r1)
	stw      r0, 0x3c(r1)
	stw      r0, 0x24(r1)
	stw      r0, 0x1c(r1)
	stw      r0, 0x40(r1)
	stw      r0, 0x28(r1)
	stw      r0, 0x44(r1)
	lwz      r0, 0xcc(r31)
	stw      r0, 0x24(r1)
	lwz      r12, 0(r29)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f2, 8(r1)
	mr       r3, r29
	lfs      f1, 0xc(r1)
	lfs      f0, 0x10(r1)
	stfs     f2, 0x2c(r1)
	stfs     f1, 0x30(r1)
	stfs     f0, 0x34(r1)
	lwz      r12, 0(r29)
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	stfs     f1, 0x38(r1)
	addi     r4, r1, 0x14
	lwz      r3, moviePlayer__4Game@sda21(r13)
	bl       play__Q24Game11MoviePlayerFRQ24Game12MoviePlayArg
	lwz      r3, gGame2DMgr__6Screen@sda21(r13)
	li       r4, 4
	bl open_GameOver__Q26Screen9Game2DMgrFQ36Screen9Game2DMgr13GameOverTitle

lbl_8022AB20:
	lwz      r0, 0x64(r1)
	lwz      r31, 0x5c(r1)
	lwz      r30, 0x58(r1)
	lwz      r29, 0x54(r1)
	mtlr     r0
	addi     r1, r1, 0x60
	blr
	*/
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
			gameOverTitle = Screen::Game2DMgr::GOTITLE_Unk1;
			if (!gameSystem->isMultiplayerMode()) {
				section->setPlayerMode(0);
			}
		} else {
			gameOverTitle = Screen::Game2DMgr::GOTITLE_Unk2;
			if (!gameSystem->isMultiplayerMode()) {
				section->setPlayerMode(1);
			}
		}
		Screen::gGame2DMgr->open_GameOver(gameOverTitle);
	}

	if (config->is("s12_cv_giveup")) {
		Screen::gGame2DMgr->m_screenMgr->reset();
		Iterator<Piki> pikiIterator(pikiMgr);
		CI_LOOP(pikiIterator)
		{
			Piki* piki = *pikiIterator;
			if (piki->isAlive() && !piki->isStickTo()) {
				piki->movie_begin(false);
				piki->endStick();
				piki->m_brain->start(1, nullptr);
			}
		}
	}

	if (config->is("s09_holein")) {
		Vector3f holePos = section->m_hole->getPosition();
		section->prepareHoleIn(holePos, true);
		pikiMgr->saveAllPikmins(section->m_container1);
		for (int i = 0; i < 2; i++) {
			Navi* navi = naviMgr->getAt(i);
			if (navi->isAlive() && navi->isStickTo()) {
				navi->endStick();
			}
		}
		section->m_hole = nullptr;
	}

	if (config->is("s0C_cv_escape")) {
		Vector3f fountainPos = section->m_fountain->getPosition();
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
		section->setPlayerMode(2);
	}

	RoomMapMgr* mgr   = static_cast<RoomMapMgr*>(mapMgr);
	int currFloor     = mgr->_30;
	int floorMax      = mgr->m_caveInfo->getFloorMax();
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

	if (config->is("x19_vs_bedama") && (isLoseCause(VSPLAYER_Red, VSLOSE_Marble) || isLoseCause(VSPLAYER_Blue, VSLOSE_Marble))) {
		PSSystem::SceneMgr* sceneMgr = PSSystem::getSceneMgr();
		checkSceneMgr(sceneMgr);
		PSM::SceneBase* scene = static_cast<PSM::SceneBase*>(sceneMgr->getChildScene());

		scene = (scene->isGameScene()) ? scene : nullptr;

		scene->_10.stopAllSound(15);
	}

	if (config->is("e00_E3_cavestart")) {
		gameSystem->setFlag(GAMESYS_Unk2);
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
			piki->m_position2 = Vector3f(0.0f);
			piki->m_velocity  = Vector3f(0.0f);
		}

		Screen::gGame2DMgr->close_Floor();
		setFlag(VSGS_Unk3);
		if (currFloor == 0) {
			if (sys->getPlayCommonData()->challenge_is_virgin_check_only()) {
				if (!gameSystem->isVersusMode()) {
					MoviePlayArg movieArg("e00_E3_cavestart", nullptr, section->_C8, 0);
					if (gameSystem->isMultiplayerMode()) {
						section->setPlayerMode(0);
					}
					section->setCamController();
					movieArg._10 = section->_CC;
					if (ItemOnyon::mgr->m_pod) {
						Onyon* pod        = ItemOnyon::mgr->m_pod;
						movieArg.m_angle  = pod->getFaceDir();
						movieArg.m_origin = pod->getPosition();
					}

					movieArg.m_origin.y = mapMgr->getMinY(movieArg.m_origin);
					moviePlayer->play(movieArg);
					return;
				}
			}
		}

		gameSystem->setFlag(GAMESYS_Unk2);
		section->setCamController();
		gameSystem->setFlag(GAMESYS_Unk2);
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

			sceneMgr->m_scenes->m_child->startMainSeq();
		}

	} else if (config->is("s09_holein")) {
		PSMCancelToPauseOffMainBgm();
		section->m_currentFloor++;
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
			JUT_PANICLINE(1279, "cannot happen !\n");

		} else {
			GameStat::alivePikis.clear();
			PSMCancelToPauseOffMainBgm();
			ResultArg arg;
			arg.m_endFlag.clear();
			transit(section, VGS_Result, &arg);
		}

	} else if (config->is("s05_pikminzero")) {
		PSMCancelToPauseOffMainBgm();
		Screen::gGame2DMgr->close_GameOver();
		ResultArg arg;
		arg.m_endFlag.clear();
		transit(section, VGS_Result, &arg);

	} else if (config->is("s0C_cv_escape")) {
		PSMCancelToPauseOffMainBgm();
		ResultArg arg;
		arg.m_endFlag.clear();
		arg.m_endFlag.typeView |= 0x1;
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
	MoviePlayArg movieArg("s09_holein", nullptr, section->_C8, 0);

	movieArg.setTarget(hole);
	movieArg._10                = section->_CC;
	movieArg._10                = section->_CC;
	moviePlayer->m_targetObject = hole;

	moviePlayer->play(movieArg);
}

/*
 * --INFO--
 * Address:	8022BA64
 * Size:	00019C
 */
void GameState::onOrimaDown(VsGameSection* section, int naviIdx)
{
	P2ASSERTBOUNDSLINE(1341, 0, naviIdx, 2);

	if (gameSystem->isVersusMode()) {
		if (!_16) {
			setLoseCause(naviIdx, VSLOSE_Unk1);
		}

	} else {
		MoviePlayArg movieArg("s03_orimadown", nullptr, section->_C8, naviIdx);
		movieArg._10 = section->_CC;

		Navi* deadNavi = naviMgr->getAt(naviIdx);
		movieArg.setTarget(deadNavi);
		moviePlayer->_18C = deadNavi;
		if (naviIdx == 0) {
			moviePlayer->_190 = section->_104;
		} else {
			moviePlayer->_190 = section->_108;
		}

		moviePlayer->play(movieArg);
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
		disp.m_dataGame.m_floorNum = section->getCurrFloor();
		disp._60                   = m_floorExtendTimer;
		Screen::gGame2DMgr->open_GameChallenge1P(disp, in);

	} else {
		if (gameSystem->isVersusMode()) {
			og::Screen::DispMemberVs disp;
			Screen::gGame2DMgr->open_GameVs(disp, in);

		} else {
			og::Screen::DispMemberChallenge2P disp;
			disp.m_dataGame.m_floorNum = section->getCurrFloor();
			disp._60                   = m_floorExtendTimer;
			Screen::gGame2DMgr->open_GameChallenge2P(disp, in);
		}
	}
	/*
	stwu     r1, -0x180(r1)
	mflr     r0
	stw      r0, 0x184(r1)
	li       r0, 0
	stw      r31, 0x17c(r1)
	mr       r31, r5
	stw      r30, 0x178(r1)
	mr       r30, r3
	stw      r29, 0x174(r1)
	stw      r28, 0x170(r1)
	lwz      r6, gameSystem__4Game@sda21(r13)
	lwz      r3, 0x44(r6)
	cmpwi    r3, 1
	beq      lbl_8022BC40
	cmpwi    r3, 3
	bne      lbl_8022BC44

lbl_8022BC40:
	li       r0, 1

lbl_8022BC44:
	clrlwi.  r0, r0, 0x18
	bne      lbl_8022BD48
	lis      r3, __vt__Q32og6Screen14DispMemberBase@ha
	li       r28, 0
	addi     r29, r3, __vt__Q32og6Screen14DispMemberBase@l
	li       r9, 1
	lfs      f3, lbl_8051A274@sda21(r2)
	lis      r6, __vt__Q32og6Screen21DispMemberChallenge1P@ha
	li       r7, 0xa
	lfs      f2, lbl_8051A268@sda21(r2)
	lfs      f1, lbl_8051A2B0@sda21(r2)
	li       r8, 2
	lfs      f0, lbl_8051A2B4@sda21(r2)
	lis      r3, __vt__Q32og6Screen21DispMemberDayEndCount@ha
	li       r11, 0x4d2
	li       r10, 0x32
	li       r5, 0x9ec
	li       r0, 0x1092
	stw      r29, 0xf4(r1)
	addi     r12, r6, __vt__Q32og6Screen21DispMemberChallenge1P@l
	addi     r6, r3, __vt__Q32og6Screen21DispMemberDayEndCount@l
	mr       r3, r4
	stw      r29, 0x15c(r1)
	stw      r28, 0xf8(r1)
	stw      r12, 0xf4(r1)
	stfs     f3, 0xfc(r1)
	stw      r28, 0x100(r1)
	stw      r28, 0x108(r1)
	stw      r11, 0x104(r1)
	stw      r10, 0x10c(r1)
	stb      r28, 0x110(r1)
	stw      r28, 0x114(r1)
	stfs     f2, 0x118(r1)
	stw      r9, 0x11c(r1)
	stw      r8, 0x120(r1)
	stw      r7, 0x124(r1)
	stw      r7, 0x128(r1)
	stb      r9, 0x12c(r1)
	stfs     f2, 0x130(r1)
	stw      r9, 0x134(r1)
	stw      r8, 0x138(r1)
	stw      r7, 0x13c(r1)
	stw      r7, 0x140(r1)
	stb      r9, 0x144(r1)
	stw      r28, 0x160(r1)
	stw      r6, 0x15c(r1)
	stfs     f1, 0x168(r1)
	stfs     f1, 0x164(r1)
	stw      r5, 0x148(r1)
	stb      r28, 0x14c(r1)
	stfs     f0, 0x150(r1)
	stw      r0, 0x158(r1)
	stfs     f3, 0x154(r1)
	lwz      r12, 0(r4)
	lwz      r12, 0x58(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x108(r1)
	mr       r5, r31
	lwz      r3, gGame2DMgr__6Screen@sda21(r13)
	addi     r4, r1, 0xf4
	lfs      f0, 0x1c(r30)
	stfs     f0, 0x154(r1)
	bl
open_GameChallenge1P__Q26Screen9Game2DMgrFRQ32og6Screen21DispMemberChallenge1Pi
	b        lbl_8022BF1C

lbl_8022BD48:
	cmpwi    r3, 1
	bne      lbl_8022BE24
	lis      r3, __vt__Q32og6Screen14DispMemberBase@ha
	li       r28, 0
	addi     r4, r3, __vt__Q32og6Screen14DispMemberBase@l
	li       r9, 1
	lfs      f1, lbl_8051A268@sda21(r2)
	lis      r3, __vt__Q32og6Screen12DispMemberVs@ha
	li       r7, 0xa
	lfs      f0, lbl_8051A2B8@sda21(r2)
	li       r8, 2
	lfs      f2, lbl_8051A274@sda21(r2)
	li       r11, 0x4d2
	li       r10, 0x32
	li       r6, 0x6f
	li       r0, 0xde
	stw      r4, 0x80(r1)
	addi     r12, r3, __vt__Q32og6Screen12DispMemberVs@l
	lwz      r3, gGame2DMgr__6Screen@sda21(r13)
	mr       r5, r31
	stw      r28, 0x84(r1)
	addi     r4, r1, 0x80
	stw      r12, 0x80(r1)
	stfs     f2, 0x8c(r1)
	stw      r28, 0x90(r1)
	stw      r28, 0x98(r1)
	stw      r11, 0x94(r1)
	stw      r10, 0x9c(r1)
	stb      r28, 0xa0(r1)
	stw      r28, 0xa4(r1)
	stfs     f1, 0xa8(r1)
	stw      r9, 0xac(r1)
	stw      r8, 0xb0(r1)
	stw      r7, 0xb4(r1)
	stw      r7, 0xb8(r1)
	stb      r9, 0xbc(r1)
	stfs     f1, 0xc0(r1)
	stw      r9, 0xc4(r1)
	stw      r8, 0xc8(r1)
	stw      r7, 0xcc(r1)
	stw      r7, 0xd0(r1)
	stb      r9, 0xd4(r1)
	stw      r6, 0xd8(r1)
	stw      r0, 0xdc(r1)
	stw      r28, 0xe0(r1)
	stw      r28, 0xe4(r1)
	stw      r28, 0x88(r1)
	stb      r28, 0xe8(r1)
	stb      r28, 0xe9(r1)
	stb      r28, 0xea(r1)
	stb      r28, 0xeb(r1)
	stfs     f0, 0xec(r1)
	stfs     f0, 0xf0(r1)
	bl       open_GameVs__Q26Screen9Game2DMgrFRQ32og6Screen12DispMemberVsi
	b        lbl_8022BF1C

lbl_8022BE24:
	lis      r3, __vt__Q32og6Screen14DispMemberBase@ha
	li       r29, 0
	addi     r28, r3, __vt__Q32og6Screen14DispMemberBase@l
	li       r9, 1
	lfs      f3, lbl_8051A274@sda21(r2)
	lis      r6, __vt__Q32og6Screen21DispMemberChallenge2P@ha
	li       r7, 0xa
	lfs      f2, lbl_8051A268@sda21(r2)
	lfs      f1, lbl_8051A2B0@sda21(r2)
	li       r8, 2
	lfs      f0, lbl_8051A2B4@sda21(r2)
	lis      r3, __vt__Q32og6Screen21DispMemberDayEndCount@ha
	li       r11, 0x4d2
	li       r10, 0x32
	li       r5, 0x9ec
	li       r0, 0x1092
	stw      r28, 8(r1)
	addi     r12, r6, __vt__Q32og6Screen21DispMemberChallenge2P@l
	addi     r6, r3, __vt__Q32og6Screen21DispMemberDayEndCount@l
	mr       r3, r4
	stw      r28, 0x70(r1)
	stw      r29, 0xc(r1)
	stw      r12, 8(r1)
	stfs     f3, 0x10(r1)
	stw      r29, 0x14(r1)
	stw      r29, 0x1c(r1)
	stw      r11, 0x18(r1)
	stw      r10, 0x20(r1)
	stb      r29, 0x24(r1)
	stw      r29, 0x28(r1)
	stfs     f2, 0x2c(r1)
	stw      r9, 0x30(r1)
	stw      r8, 0x34(r1)
	stw      r7, 0x38(r1)
	stw      r7, 0x3c(r1)
	stb      r9, 0x40(r1)
	stfs     f2, 0x44(r1)
	stw      r9, 0x48(r1)
	stw      r8, 0x4c(r1)
	stw      r7, 0x50(r1)
	stw      r7, 0x54(r1)
	stb      r9, 0x58(r1)
	stw      r29, 0x74(r1)
	stw      r6, 0x70(r1)
	stfs     f1, 0x7c(r1)
	stfs     f1, 0x78(r1)
	stw      r5, 0x5c(r1)
	stb      r29, 0x60(r1)
	stfs     f0, 0x64(r1)
	stw      r0, 0x6c(r1)
	stfs     f3, 0x68(r1)
	lwz      r12, 0(r4)
	lwz      r12, 0x58(r12)
	mtctr    r12
	bctrl
	stw      r3, 0x1c(r1)
	mr       r5, r31
	lwz      r3, gGame2DMgr__6Screen@sda21(r13)
	addi     r4, r1, 8
	lfs      f0, 0x1c(r30)
	stfs     f0, 0x68(r1)
	bl
open_GameChallenge2P__Q26Screen9Game2DMgrFRQ32og6Screen21DispMemberChallenge2Pi

lbl_8022BF1C:
	lwz      r0, 0x184(r1)
	lwz      r31, 0x17c(r1)
	lwz      r30, 0x178(r1)
	lwz      r29, 0x174(r1)
	lwz      r28, 0x170(r1)
	mtlr     r0
	addi     r1, r1, 0x180
	blr
	*/
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

		disp.m_dataGame.m_floorNum = section->getCurrFloor();
		disp.m_deadPiki            = section->_208;
		disp.m_pokos               = section->m_pokoCount;
		disp._60                   = m_floorExtendTimer;
		disp._5C                   = section->m_timeLimit;

		Navi* olimar                      = naviMgr->getAt(0);
		disp.m_olimarData.m_followPikis   = GameStat::formationPikis.m_counter[0];
		disp.m_olimarData.m_nextThrowPiki = olimar->ogGetNextThrowPiki();
		disp.m_olimarData.m_dope1Count    = playData->getDopeCount(1);
		disp.m_olimarData.m_dope0Count    = playData->getDopeCount(0);
		disp.m_olimarData.m_naviLifeRatio = olimar->getLifeRatio();

		Navi* louie                      = naviMgr->getAt(1);
		disp.m_louieData.m_followPikis   = GameStat::formationPikis.m_counter[1];
		disp.m_louieData.m_nextThrowPiki = louie->ogGetNextThrowPiki();
		disp.m_louieData.m_dope1Count    = playData->getDopeCount(1);
		disp.m_louieData.m_dope0Count    = playData->getDopeCount(0);
		disp.m_louieData.m_naviLifeRatio = louie->getLifeRatio();

		Navi* activeNavi = naviMgr->getActiveNavi();
		int check        = 2;
		if (activeNavi) {
			check = activeNavi->m_naviIndex.typeView;
		}

		if (check == 0) {
			disp.m_olimarData.m_activeNaviID = 1;
			disp.m_louieData.m_activeNaviID  = 0;

		} else if (check == 1) {
			disp.m_olimarData.m_activeNaviID = 0;
			disp.m_louieData.m_activeNaviID  = 1;

		} else if (section->m_prevNaviIdx == 0) {
			disp.m_olimarData.m_activeNaviID = 0;
			disp.m_louieData.m_activeNaviID  = 1;

		} else {
			disp.m_olimarData.m_activeNaviID = 1;
			disp.m_louieData.m_activeNaviID  = 0;
		}

		disp.m_dataGame.m_mapPikminCount = GameStat::getMapPikmins(-1);
		Screen::gGame2DMgr->setDispMember(&disp);

	} else if (gameSystem->isVersusMode()) {
		if (Screen::gGame2DMgr->check_VsStatus() == 2 && _16 == 1 && !(moviePlayer->m_flags & MoviePlayer::IS_ACTIVE)) {

			_16 = 2;

		} else if (_16 == 1) {
			Screen::gGame2DMgr->check_VsStatus(); // probably in a leftover && check
		}

		og::Screen::DispMemberVs disp;

		Navi* olimar                      = naviMgr->getAt(0);
		disp.m_olimarData.m_followPikis   = GameStat::formationPikis.m_counter[0];
		disp.m_olimarData.m_nextThrowPiki = olimar->ogGetNextThrowPiki();
		disp.m_olimarData.m_dope1Count    = olimar->getDopeCount(1);
		disp.m_olimarData.m_dope0Count    = olimar->getDopeCount(0);
		disp.m_olimarData.m_naviLifeRatio = olimar->getLifeRatio();

		Navi* louie                      = naviMgr->getAt(1);
		disp.m_louieData.m_followPikis   = GameStat::formationPikis.m_counter[1];
		disp.m_louieData.m_nextThrowPiki = louie->ogGetNextThrowPiki();
		disp.m_louieData.m_dope1Count    = louie->getDopeCount(1);
		disp.m_louieData.m_dope0Count    = louie->getDopeCount(0);
		disp.m_louieData.m_naviLifeRatio = louie->getLifeRatio();

		disp.m_redPikminCount  = GameStat::getMapPikmins(1);
		disp.m_bluePikminCount = GameStat::getMapPikmins(0);

		disp._6A = section->m_obakeTimer[0] > 0.0f;
		disp._6B = section->m_obakeTimer[1] > 0.0f;

		disp._6C = section->m_obakeTimer[0];
		disp._70 = section->m_obakeTimer[1];

		int yellowsVal0 = section->_3D4;
		int yellowsVal1 = section->_3D8;

		if (section->_3D4 == 4 && moviePlayer->m_flags & MoviePlayer::IS_ACTIVE) {
			yellowsVal0 = section->_3D4 - 1;
		}

		if (section->_3D8 == 4 && moviePlayer->m_flags & MoviePlayer::IS_ACTIVE) {
			yellowsVal1 = section->_3D8 - 1;
		}

		disp.m_mode = yellowsVal0;
		disp._64    = yellowsVal1;

		bool moviePlayerActive = moviePlayer->m_flags & MoviePlayer::IS_ACTIVE;

		bool blueMarble, redMarble;
		isLoseMarble(redMarble, blueMarble);
		disp.setMarbleConditions(redMarble, blueMarble);

		Screen::gGame2DMgr->setDispMember(&disp);

	} else {
		og::Screen::DispMemberChallenge2P disp;

		disp.m_dataGame.m_floorNum = section->getCurrFloor();

		disp.m_pokos     = section->m_pokoCount;
		disp._60         = m_floorExtendTimer;
		disp.m_timeLimit = section->m_timeLimit;
		disp.m_deadPiki  = section->_208;

		Navi* olimar                      = naviMgr->getAt(0);
		disp.m_olimarData.m_followPikis   = GameStat::formationPikis.m_counter[0];
		disp.m_olimarData.m_nextThrowPiki = olimar->ogGetNextThrowPiki();
		disp.m_olimarData.m_dope1Count    = playData->getDopeCount(1);
		disp.m_olimarData.m_dope0Count    = playData->getDopeCount(0);
		disp.m_olimarData.m_naviLifeRatio = olimar->getLifeRatio();

		Navi* louie                      = naviMgr->getAt(1);
		disp.m_louieData.m_followPikis   = GameStat::formationPikis.m_counter[1];
		disp.m_louieData.m_nextThrowPiki = louie->ogGetNextThrowPiki();
		disp.m_louieData.m_dope1Count    = playData->getDopeCount(1);
		disp.m_louieData.m_dope0Count    = playData->getDopeCount(0);
		disp.m_louieData.m_naviLifeRatio = louie->getLifeRatio();
		disp.m_dataGame.m_mapPikminCount = GameStat::getMapPikmins(-1);
		Screen::gGame2DMgr->setDispMember(&disp);
	}
}

/*
 * --INFO--
 * Address:	8022C70C
 * Size:	000004
 */
void GameState::drawStatus(Graphics&, VsGameSection* section) { }

} // namespace VsGame
} // namespace Game

// namespace og {

// namespace Screen {

// /*
//  * --INFO--
//  * Address:	8022C710
//  * Size:	000008
//  */
// u32 DispMemberVs::getSize(void) { return 0x74; }

// /*
//  * --INFO--
//  * Address:	8022C718
//  * Size:	00000C
//  */
// void DispMemberVs::getOwnerID(void)
// {
// 	/*
// lis      r3, 0x004F4741@ha
// addi     r3, r3, 0x004F4741@l
// blr
// 	*/
// }

// /*
//  * --INFO--
//  * Address:	8022C724
//  * Size:	00000C
//  */
// void DispMemberVs::getMemberID(void)
// {
// 	/*
// li       r4, 0x5653
// li       r3, 0
// blr
// 	*/
// }

// /*
//  * --INFO--
//  * Address:	8022C730
//  * Size:	000008
//  */
// u32 DispMemberChallenge1P::getSize(void) { return 0x78; }

// /*
//  * --INFO--
//  * Address:	8022C738
//  * Size:	00000C
//  */
// void DispMemberChallenge1P::getOwnerID(void)
// {
// 	/*
// lis      r3, 0x004F4741@ha
// addi     r3, r3, 0x004F4741@l
// blr
// 	*/
// }

// /*
//  * --INFO--
//  * Address:	8022C744
//  * Size:	000010
//  */
// void DispMemberChallenge1P::getMemberID(void)
// {
// 	/*
// lis      r4, 0x414C3150@ha
// li       r3, 0x4348
// addi     r4, r4, 0x414C3150@l
// blr
// 	*/
// }

// namespace kh {

// } // namespace kh

// /*
//  * --INFO--
//  * Address:	8022C754
//  * Size:	000008
//  */
// u32 DispWinLoseReason::getSize(void) { return 0x10; }

// /*
//  * --INFO--
//  * Address:	8022C75C
//  * Size:	000008
//  */
// u32 DispWinLoseReason::getOwnerID(void) { return 0x4B48; }

// /*
//  * --INFO--
//  * Address:	8022C764
//  * Size:	000010
//  */
// void DispWinLoseReason::getMemberID(void)
// {
// 	/*
// lis      r4, 0x5F52534E@ha
// li       r3, 0x574c
// addi     r4, r4, 0x5F52534E@l
// blr
// 	*/
// }

// /*
//  * --INFO--
//  * Address:	8022C774
//  * Size:	000008
//  */
// u32 DispWinLose::getSize(void) { return 0x10; }

// /*
//  * --INFO--
//  * Address:	8022C77C
//  * Size:	000008
//  */
// u32 DispWinLose::getOwnerID(void) { return 0x4B48; }

// /*
//  * --INFO--
//  * Address:	8022C784
//  * Size:	000014
//  */
// void DispWinLose::getMemberID(void)
// {
// 	/*
// lis      r4, 0x4C4F5345@ha
// lis      r3, 0x57494E5F@ha
// addi     r4, r4, 0x4C4F5345@l
// addi     r3, r3, 0x57494E5F@l
// blr
// 	*/
// }

// } // namespace Screen

// namespace og {

// /*
//  * --INFO--
//  * Address:	8022C798
//  * Size:	000008
//  */
// u32 DispMemberChallenge2P::getSize(void) { return 0x78; }

// /*
//  * --INFO--
//  * Address:	8022C7A0
//  * Size:	00000C
//  */
// void DispMemberChallenge2P::getOwnerID(void)
// {
// 	/*
// lis      r3, 0x004F4741@ha
// addi     r3, r3, 0x004F4741@l
// blr
// 	*/
// }

// /*
//  * --INFO--
//  * Address:	8022C7AC
//  * Size:	000010
//  */
// void DispMemberChallenge2P::getMemberID(void)
// {
// 	/*
// lis      r4, 0x414C3250@ha
// li       r3, 0x4348
// addi     r4, r4, 0x414C3250@l
// blr
// 	*/
// }

// namespace Game {

// } // namespace Game

// } // namespace og

// /*
//  * --INFO--
//  * Address:	8022C7BC
//  * Size:	000010
//  */
// void GameState::on_section_fadeout(VsGameSection* section)
// {
// 	/*
// 	lhz      r0, 0x14(r3)
// 	ori      r0, r0, 0x8000
// 	sth      r0, 0x14(r3)
// 	blr
// 	*/
// }

// } // namespace og

// /*
//  * --INFO--
//  * Address:	8022C7CC
//  * Size:	000028
//  */
// void __sinit_vsGS_Game_cpp(void)
// {
// 	/*
// 	lis      r4, __float_nan@ha
// 	li       r0, -1
// 	lfs      f0, __float_nan@l(r4)
// 	lis      r3, lbl_804C0F08@ha
// 	stw      r0, lbl_80515C68@sda21(r13)
// 	stfsu    f0, lbl_804C0F08@l(r3)
// 	stfs     f0, lbl_80515C6C@sda21(r13)
// 	stfs     f0, 4(r3)
// 	stfs     f0, 8(r3)
// 	blr
// 	*/
// }
