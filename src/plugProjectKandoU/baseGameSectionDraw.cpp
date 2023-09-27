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

const char* message = "drct-post";

bool sDebugMode = true;

bool gDrawNavi[4];

bool gDrawNames = true;


static Color4 vsTeamColorsColor4[] = { 
    Color4(0xff, 0x50, 0x50, 0xff),
    Color4(0x50, 0x50, 0xff, 0xff), 
    Color4(0xff, 0xff, 0xff, 0xff),
    Color4(0x78, 0x00, 0xff, 0xff)
};

namespace Game {


void BaseGameSection::renderNames(Graphics& gfx, Viewport* vp) {
	vp->setViewport();
	vp->setProjection();
	gfx.initPerspPrintf(vp);
	for (int i = 0; i < Game::gNaviNum; i++) {
		if (i == vp->mVpId && sDebugMode) {
			PerspPrintfInfo info;
			info.mFont = getPikminFont();
			info._04 = 0;
			info._08 = 0;
			info._0C = 0;
			info._10 = 0.3f;
			info._14 = vsTeamColorsColor4[getVsTeam_s(i)];
			info._18 = vsTeamColorsColor4[getVsTeam_s(i)];

			Vector3f position = naviMgr->getAt(i)->getPosition();
			position.y += 25.0f;
			gfx.mCurrentViewport = vp;

			gfx.perspPrintf(info, position, "%f, %f, %f | %f", position.x, position.y - 25.0f, position.z, naviMgr->getAt(i)->getFaceDir());
		}
		else if (gDrawNavi[i]) {
			PerspPrintfInfo info;
			info.mFont = getPikminFont();
			info._04 = 0;
			info._08 = 0;
			info._0C = 0;
			info._10 = 0.3f;
			info._14 = vsTeamColorsColor4[getVsTeam_s(i)];
			info._18 = vsTeamColorsColor4[getVsTeam_s(i)];

			Vector3f position = naviMgr->getAt(i)->getPosition();
			position.y += 25.0f;

			gfx.mCurrentViewport = vp;
			gfx.perspPrintf(info, position, "%s", sCharacters[i].mDispName);
		}
	}
	
}

/*
 * --INFO--
 * Address:	802398D8
 * Size:	0001F4
 * Matches
 */
void BaseGameSection::newdraw_draw3D_all(Graphics& gfx)
{
	// Setup viewport callback to be newdraw_drawAll
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
	drawParticle(gfx, 0);
	renderNames(gfx, gfx.getViewport(0));
	drawParticle(gfx, 1);
	renderNames(gfx, gfx.getViewport(1));
	if (gNaviNum > 2) {
		drawParticle(gfx, 2);
		renderNames(gfx, gfx.getViewport(2));
	}
	if (gNaviNum > 3) {
		drawParticle(gfx, 3);
		renderNames(gfx, gfx.getViewport(3));
	}
	sys->mTimers->_stop("part-draw");

	// Draw counters for both viewports
	// (Life gauge & Carry info)
	sys->mTimers->_start("drct-post", true);
	Viewport* vp = gfx.getViewport(0);
	if (vp && vp->viewable()) {
		gfx.mCurrentViewport = vp;
		directDrawPost(gfx, vp);
	}

	vp = gfx.getViewport(1);
	if (vp && vp->viewable()) {
		gfx.mCurrentViewport = vp;
		directDrawPost(gfx, vp);
	}
	sys->mTimers->_stop("drct-post");
	
	if (gNaviNum > 2) {
		vp = gfx.getViewport(2);
		if (vp && vp->viewable()) {
			gfx.mCurrentViewport = vp;
			directDrawPost(gfx, vp);
		}
	}
	if (gNaviNum > 3) {
		vp = gfx.getViewport(3);
		if (vp && vp->viewable()) {
			gfx.mCurrentViewport = vp;
			directDrawPost(gfx, vp);
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

} // namespace Game
