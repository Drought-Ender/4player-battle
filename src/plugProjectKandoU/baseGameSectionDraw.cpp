#include "Game/BaseGameSection.h"
#include "Game/GameSystem.h"
#include "Game/GameLight.h"

#include "FourPlayer.h"

#include "Sys/DrawBuffers.h"

#include "JSystem/JUtility/JUTTexture.h"
#include "JSystem/J3D/J3DSys.h"

#include "ParticleMgr.h"
#include "SysTimers.h"
#include "IDelegate.h"
#include "System.h"
#include "Light.h"
#include "nans.h"
#include "Game/MoviePlayer.h"
#include "VsOptions.h"
#include "Game/Navi.h"
#include "FloatingIconMgr.h"

#include "VsSlotCard.h"

const char* message = "drct-post";

#if FOURPLAYER_DEBUG == 1
bool sDebugMode = true;
#else
bool sDebugMode = false;
#endif

bool gDrawNavi[4];

bool gDrawNames = true;

static Color4 vsTeamColorsColor4[]
    = { Color4(0xff, 0x50, 0x50, 0xff), Color4(0x50, 0x50, 0xff, 0xff), Color4(0xff, 0xff, 0xff, 0xff), Color4(0x78, 0x00, 0xff, 0xff) };

namespace Game {

void DrawDebugScores(Graphics& gfx)
{
	J2DPrint print(getPikminFont(), 0.0f);
	print.mGlyphHeight /= 3;
	print.mGlyphWidth /= 3;

	print.print(85.0f, 10.0f, "Scores Red Blue");

	print.mCharColor = JUtility::TColor(0xff0000ff);
	print.print(85.0f, 20.0f, "%f\n", GetVsGameSection()->mRedBlueScore[Game::TEAM_RED]);
	print.mCharColor = JUtility::TColor(0x0000ffff);
	print.print(85.0f, 30.0f, "%f\n", GetVsGameSection()->mRedBlueScore[Game::TEAM_BLUE]);
	print.mCharColor = JUtility::TColor(0xffffffff);
	print.print(85.0f, 40.0f, "%f\n", GetVsGameSection()->mRedBlueScore[Game::TEAM_WHITE]);
	print.mCharColor = JUtility::TColor(0xff00ffff);
	print.print(85.0f, 50.0f, "%f\n", GetVsGameSection()->mRedBlueScore[Game::TEAM_PURPLE]);

	print.mCharColor = JUtility::TColor(0xffffffff);

	print.print(185.0f, 10.0f, "Scores Yellow");

	print.mCharColor = JUtility::TColor(0xff0000ff);
	print.print(185.0f, 20.0f, "%f\n", GetVsGameSection()->mYellowScore[Game::TEAM_RED]);
	print.mCharColor = JUtility::TColor(0x0000ffff);
	print.print(185.0f, 30.0f, "%f\n", GetVsGameSection()->mYellowScore[Game::TEAM_BLUE]);
	print.mCharColor = JUtility::TColor(0xffffffff);
	print.print(185.0f, 40.0f, "%f\n", GetVsGameSection()->mYellowScore[Game::TEAM_WHITE]);
	print.mCharColor = JUtility::TColor(0xff00ffff);
	print.print(185.0f, 50.0f, "%f\n", GetVsGameSection()->mYellowScore[Game::TEAM_PURPLE]);

	print.mCharColor = JUtility::TColor(0xffffffff);

	print.print(285.0f, 10.0f, "Scores Cherry");

	print.mCharColor = JUtility::TColor(0xff0000ff);
	print.print(285.0f, 20.0f, "%f\n", GetVsGameSection()->mCherryScore[Game::TEAM_RED]);
	print.mCharColor = JUtility::TColor(0x0000ffff);
	print.print(285.0f, 30.0f, "%f\n", GetVsGameSection()->mCherryScore[Game::TEAM_BLUE]);
	print.mCharColor = JUtility::TColor(0xffffffff);
	print.print(285.0f, 40.0f, "%f\n", GetVsGameSection()->mCherryScore[Game::TEAM_WHITE]);
	print.mCharColor = JUtility::TColor(0xff00ffff);
	print.print(285.0f, 50.0f, "%f\n", GetVsGameSection()->mCherryScore[Game::TEAM_PURPLE]);
}

void DrawDebugSlots(Graphics& gfx)
{
	J2DPrint print(getPikminFont(), 0.0f);
	print.mGlyphHeight /= 3;
	print.mGlyphWidth /= 3;

	VsGame::CardMgr* cardMgr = GetVsGameSection()->mCardMgr;
	VsGame::CardMgr::SlotMachine* machines[4]
	    = { cardMgr->getSlotMachine(0), cardMgr->getSlotMachine(1), cardMgr->getSlotMachine(2), cardMgr->getSlotMachine(3) };

	const char* spinStates[] = {
		"SPIN_UNSTARTED",
		"SPIN_WAIT_START", 
		"SPIN_START",
		"SPIN_WAIT_MAX_SPEED",
		"SPIN_DECELERATE",
		"SPIN_DECELERATE_END",
		"SPIN_DOWN_TO_CARD",
		"SPIN_WAIT_CARD_STOP",
		"SPIN_UP_TO_CARD",
		"SPIN_WAIT_CARD_ROLL",
		"SPIN_END"
	};

	const char* appearStates[] = {
		"APPEAR_LEAVE",
		"APPEAR_AWAIT",
		"APPEAR_ENTER",
		"APPEAR_RESET"
	};

	print.mCharColor = JUtility::TColor(0xff0000ff);
	print.print(85.0f, 20.0f, "Slot %i: mAppearState = %s,  mSpinState = %s\n", 0, appearStates[machines[0]->mAppearState], spinStates[machines[0]->mSpinState]);
	print.print(85.0f, 30.0f, "mAppearValue = %f, mSpinTimer = %f\n", 0, machines[0]->mAppearValue, machines[0]->mSpinTimer);
	print.mCharColor = JUtility::TColor(0x0000ffff);
	print.print(85.0f, 40.0f, "Slot %i: mAppearState = %s,  mSpinState = %s\n", 1, appearStates[machines[1]->mAppearState], spinStates[machines[1]->mSpinState]);
	print.print(85.0f, 50.0f, "mAppearValue = %f, mSpinTimer = %f\n", 0, machines[1]->mAppearValue, machines[1]->mSpinTimer);
	print.mCharColor = JUtility::TColor(0xffffffff);
	print.print(85.0f, 60.0f, "Slot %i: mAppearState = %s,  mSpinState = %s\n", 2, appearStates[machines[2]->mAppearState], spinStates[machines[2]->mSpinState]);
	print.print(85.0f, 70.0f, "mAppearValue = %f, mSpinTimer = %f\n", 0, machines[2]->mAppearValue, machines[2]->mSpinTimer);
	print.mCharColor = JUtility::TColor(0xff00ffff);
	print.print(85.0f, 80.0f, "Slot %i: mAppearState = %s,  mSpinState = %s\n", 3, appearStates[machines[3]->mAppearState], spinStates[machines[3]->mSpinState]);
	print.print(85.0f, 90.0f, "mAppearValue = %f, mSpinTimer = %f\n", 0, machines[3]->mAppearValue, machines[3]->mSpinTimer);
}

/*
 * --INFO--
 * Address:	802398D8
 * Size:	0001F4
 * Matches
 */
void BaseGameSection::newdraw_draw3D_all(Graphics& gfx)
{
	// DrawDebugMemory(gfx);
	// DrawDebugScores(gfx);
	// DrawDebugSlots(gfx);
	//  Setup viewport callback to be newdraw_drawAll
	Delegate1<BaseGameSection, Viewport*> vpDelegate(this, &BaseGameSection::newdraw_drawAll);
	gfx.mapViewport(&vpDelegate);

	// Initialise both draw buffers for the frame
	mDrawBuffer1->frameInitAll();
	mDrawBuffer2->frameInitAll();

	if (!gameSystem->isMultiplayerMode()) {
		particleMgr->setXfb(mXfbImage->mTexInfo);
	}

	// Draw particles for both viewports
	sys->mTimers->_start("part-draw", true);
	if (gDrawNavi[0] || moviePlayer->mFlags & moviePlayer->IS_ACTIVE) {
		drawParticle(gfx, 0);
	}
	if (gDrawNavi[1]) {
		drawParticle(gfx, 1);
	}
	if (gNaviNum > 2 && gDrawNavi[2]) {
		drawParticle(gfx, 2);
	}
	if (gNaviNum > 3 && gDrawNavi[3]) {
		drawParticle(gfx, 3);
	}
	sys->mTimers->_stop("part-draw");

	if (gDrawNavi[0]) {
		renderNames(gfx, gfx.getViewport(0));
	}
	if (gDrawNavi[1]) {
		renderNames(gfx, gfx.getViewport(1));
	}
	if (gNaviNum > 2 && gDrawNavi[2]) {
		renderNames(gfx, gfx.getViewport(2));
	}
	if (gNaviNum > 3 && gDrawNavi[3]) {
		renderNames(gfx, gfx.getViewport(3));
	}

	// Draw counters for both viewports
	// (Life gauge & Carry info)
	sys->mTimers->_start("drct-post", true);
	mLightMgr->set(gfx);
	Viewport* vp = gfx.getViewport(0);
	if (vp && vp->viewable() && gDrawNavi[0]) {
		gfx.mCurrentViewport = vp;
		directDrawPost(gfx, vp);
		directDrawExtras(gfx, vp);
	}

	mLightMgr->set(gfx);
	vp = gfx.getViewport(1);
	if (vp && vp->viewable() && gDrawNavi[1]) {
		gfx.mCurrentViewport = vp;
		directDrawPost(gfx, vp);
		directDrawExtras(gfx, vp);
	}
	sys->mTimers->_stop("drct-post");

	if (gNaviNum > 2) {
		mLightMgr->set(gfx);
		vp = gfx.getViewport(2);
		if (vp && vp->viewable() && gDrawNavi[2]) {
			gfx.mCurrentViewport = vp;
			directDrawPost(gfx, vp);
			directDrawExtras(gfx, vp);
		}
	}
	if (gNaviNum > 3) {
		mLightMgr->set(gfx);
		vp = gfx.getViewport(3);
		if (vp && vp->viewable() && gDrawNavi[3]) {
			gfx.mCurrentViewport = vp;
			directDrawPost(gfx, vp);
			directDrawExtras(gfx, vp);
		}
	}
}
/*
 * --INFO--
 * Address:	80239ACC
 * Size:	000360
 */
void BaseGameSection::newdraw_drawAll(Viewport* vp)
{
	if (vp->mVpId >= gNaviNum || !gDrawNavi[vp->mVpId] && !(vp->mVpId == 0 && moviePlayer->mFlags & moviePlayer->IS_ACTIVE)) {
		return;
	}
	sys->mTimers->_start("draw_calc", true);
	Graphics& gfx = *sys->mGfx;

	doSetView(vp->mVpId);
	vp->setJ3DViewMtx(true)->setViewCalcModeImm();
	doViewCalc();
	vp->setViewport();
	vp->setProjection();
	sys->mTimers->_stop("draw_calc");

	j3dSys.drawInit();

	sys->mTimers->_start("jdraw", true);
	mLightMgr->set(gfx);
	mDrawBuffer1->get(6)->draw();
	mDrawBuffer1->get(2)->draw();
	mDrawBuffer1->get(9)->draw();
	mDrawBuffer1->get(3)->draw();
	mDrawBuffer1->get(0)->draw();
	doSimpleDraw(vp);
	mLightMgr->set(gfx);
	mDrawBuffer2->get(3)->draw();
	mDrawBuffer2->get(0)->draw();
	mLightMgr->mFogMgr->off(gfx);
	mDrawBuffer1->get(1)->draw();
	mDrawBuffer2->get(1)->draw();
	mLightMgr->mFogMgr->set(gfx);
	sys->mTimers->_stop("jdraw");

	gfx.setToken("direct");

	sys->mTimers->_start("direct", true);
	j3dSys.drawInit();
	directDraw(gfx, vp);
	sys->mTimers->_stop("direct");

	Game::shadowMgr->draw(gfx, vp->mVpId);
	vp->setViewport();
	vp->setProjection();

	sys->mTimers->_start("j3d-etc", true);
	mDrawBuffer1->get(7)->draw();
	mDrawBuffer2->get(7)->draw();

	if (!_168 && (mXfbFlags & 3) == 0) {
		mXfbImage->capture(mXfbTexture1, mXfbTexture2, GX_TF_RGB565, true, 0);
	}
	mLightMgr->set(gfx);
	mLightMgr->mFogMgr->off(gfx);

	mDrawBuffer1->get(8)->draw();
	mDrawBuffer2->get(8)->draw();

	vp->setJ3DViewMtx(true);

	mLightMgr->mFogMgr->off(gfx);
	mDrawBuffer1->get(4)->draw();
	mDrawBuffer2->get(4)->draw();
	mLightMgr->mFogMgr->set(gfx);
	vp->setJ3DViewMtx(true);

	mDrawBuffer2->get(2)->draw();
	vp->setJ3DViewMtx(false);
	sys->mTimers->_stop("j3d-etc");
}

void BaseGameSection::renderNames(Graphics& gfx, Viewport* vp)
{

	if (!sDebugMode && gConfig[PLAYER_NAME] == ConfigEnums::NAME_OFF)
		return;

	if (moviePlayer->isActive())
		return;

	vp->setViewport();
	vp->setProjection();
	gfx.initPerspPrintf(vp);
	for (int i = 0; i < Game::gNaviNum; i++) {
		if (i == vp->mVpId && !gTournamentMode) {
			if (!sDebugMode)
				continue;
			PerspPrintfInfo info;
			info.mFont = getPikminFont();
			info._04   = 0;
			info._08   = 0;
			info._0C   = 0;
			info._10   = 0.3f;
			info._14   = vsTeamColorsColor4[getVsTeam_s(i)];
			info._18   = vsTeamColorsColor4[getVsTeam_s(i)];

			Vector3f position = naviMgr->getAt(i)->getPosition();
			position.y += 25.0f;
			gfx.mCurrentViewport = vp;

			gfx.perspPrintf(info, position, "%i, %i, %i | %f", (int)position.x, (int)(position.y - 25.0f), (int)position.z,
			                naviMgr->getAt(i)->getFaceDir() * 360.0f / TAU);
		} else if (gDrawNavi[i]) {
			PerspPrintfInfo info;
			info.mFont = getPikminFont();
			info._04   = 0;
			info._08   = 0;
			info._0C   = 0;
			info._10   = 0.3f;
			info._14   = vsTeamColorsColor4[getVsTeam_s(i)];
			info._18   = vsTeamColorsColor4[getVsTeam_s(i)];

			Navi* navi = naviMgr->getAt(i);

			Vector3f position = navi->getPosition();
			int vpID          = vp->mVpId;
			if (pikiMgr && pikiMgr->isVersusXlu(navi->getVsPikiColor()) && getVsPikiColor(vpID) != navi->getVsPikiColor()) {
				continue;
			}
			if (!navi) {
				continue;
			}
			position.y += 25.0f;

			gfx.mCurrentViewport = vp;
			gfx.perspPrintf(info, position, "%s", sCharacters[i].mDispName);
		}
	}
}

void BaseGameSection::directDrawExtras(Graphics& gfx, Viewport* vp)
{
	// OSReport("BaseGameSection::directDrawExtras(Graphics& gfx, Viewport* vp)\n");

	if (FloatingIcon::mgr) {
		FloatingIcon::mgr->FloatingIconMgr::draw(gfx);
	}

	if (VsGame::vsSlotCardMgr) {
		VsGame::vsSlotCardMgr->draw(gfx);
	}
}

} // namespace Game
