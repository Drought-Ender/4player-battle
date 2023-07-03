#include "kh/khWinLose.h"
#include "JSystem/JKernel/JKRFileLoader.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "Morimura/GameOver.h"
#include "utilityU.h"
#include "PSSystem/PSGame.h"
#include "PSSystem/PSMainSide_Scene.h"
#include "JSystem/J2D/J2DAnmLoader.h"

static void _Print(char* format, ...) { OSReport(format, __FILE__); }

namespace kh {
namespace Screen {

/*
 * --INFO--
 * Address:	80410714
 * Size:	0000CC
 */
void ObjWinLoseReason::doCreate(JKRArchive* arc)
{
	mScreen = new P2DScreen::Mgr_tuning;
	mScreen->set("otakara_get.blo", 0x1040000, arc);
	void* file = JKRFileLoader::getGlbResource("otakara_get.bck", arc);
	mAnim1     = J2DAnmLoaderDataBase::load(file);
	file       = JKRFileLoader::getGlbResource("otakara_get.bpk", arc);
	mAnim2     = J2DAnmLoaderDataBase::load(file);
	mScreen->setAnimation(mAnim1);
	mScreen->setAnimation(mAnim2);
}

/*
 * --INFO--
 * Address:	804107E0
 * Size:	000008
 */
bool ObjWinLoseReason::doUpdate() { return false; }

/*
 * --INFO--
 * Address:	804107E8
 * Size:	000004
 */
void ObjWinLoseReason::doDraw(Graphics& gfx) { }

/*
 * --INFO--
 * Address:	804107EC
 * Size:	000060
 */
SceneWinLoseReason::SceneWinLoseReason()
{
	mScreenObj[1] = nullptr;
	mScreenObj[0] = nullptr;
	mOutcome[3]   = -1;
	mOutcome[2]   = -1;
	mOutcome[1]   = -1;
	mOutcome[0]   = -1;
	mDone[1]      = false;
	mDone[0]      = false;
	mCounter      = 0;
}

/*
 * --INFO--
 * Address:	8041084C
 * Size:	000588
 */
void SceneWinLoseReason::doCreateObj(JKRArchive* arc)
{
	if (!mDispMember->isID(OWNER_KH, MEMBER_WIN_LOSE_REASON)) {
		JUT_PANICLINE(140, "disp member err");
	}

	DispWinLoseReason* disp = static_cast<DispWinLoseReason*>(mDispMember);
	for (int i = 0; i < Game::gNaviNum; i++) {
		mOutcome[i]             = disp->mOutcomeNavis[i];
		f32 posY = (i < 2) ? ObjWinLoseReason::msVal.mYOffsetP1 : ObjWinLoseReason::msVal.mYOffsetP2;
		f32 posX = (i & 1) ? 160.0f : -160.0f;
		switch (mOutcome[i]) {
		case 1: // captain down
		{
			mScreenObj[i] = new Morimura::TOrimaDown2D;
			registObj(mScreenObj[i], arc);
			Morimura::TOrimaDown2D* screen = static_cast<Morimura::TOrimaDown2D*>(mScreenObj[i]);
			P2ASSERTLINE(149, screen);
			screen->mGameOverScreen->setPosXY(posX, posY);
			screen->mGameOverScreen->mScreen->scaleScreen(0.5f);
			screen->mType      = i + 1;
			screen->mTimeSpeed = ObjWinLoseReason::msVal._18;
			break;
		}
		case 2: // piki extinct
		{
			mScreenObj[i] = new Morimura::TPikminDown2D;
			registObj(mScreenObj[i], arc);
			Morimura::TPikminDown2D* screen = static_cast<Morimura::TPikminDown2D*>(mScreenObj[i]);
			P2ASSERTLINE(159, screen);
			screen->mGameOverScreen->setPosXY(posX, posY);
			screen->mGameOverScreen->mScreen->scaleScreen(0.5f);
			screen->mType      = i + 1;
			screen->mTimeSpeed = ObjWinLoseReason::msVal._18;
			break;
		}
		case 3: {
			mScreenObj[i] = new ObjWinLoseReason(i);
			registObj(mScreenObj[i], arc);
			mDone[i] = true;
			break;
		}
		default:
			mDone[i] = 1;
			break;
		}
	}

	setColorBG(0, 0, 0, 160);

	int flag = 0;
	switch (mOutcome[0]) {
	case 2:
		flag |= 1;
		break;
	case 1:
		flag |= 2;
		break;
	case 3:
		flag |= 4;
		break;
	}

	switch (mOutcome[1]) {
	case 2:
		flag |= 0x10;
		break;
	case 1:
		flag |= 0x20;
		break;
	case 3:
		flag |= 0x40;
		break;
	}

	if (!(flag & 0x44)) {
		int streamID;
		if (!(flag & 3)) {
			if (flag & 0x20) {
				streamID = 0xc001103d; // olimar win via louie dies
			} else {
				streamID = 0xc0011040; // olimar wins via extinct
			}
		} else if (!(flag & 0x30)) {
			if (flag & 0x2) {
				streamID = 0xc001103e; // louie win via olimar dies
			} else {
				streamID = 0xc0011041; // louie win via extinct
			}
		} else {
			streamID = 0xc0011045; // draw
		}

		PSStart2DStream(streamID);
		PSMuteSE_on2D();
		PSSystem::SceneMgr* mgr = PSSystem::getSceneMgr();
		PSSystem::checkSceneMgr(mgr);
		PSM::Scene_Game* scene = static_cast<PSM::Scene_Game*>(mgr->getChildScene());
		scene->stopAllSound(2);
	}
}

/*
 * --INFO--
 * Address:	80410DD4
 * Size:	0000CC
 */
void SceneWinLoseReason::doUpdateActive()
{
	mCounter++;
	for (int i = 0; i < 4; i++) {
		switch (mOutcome[i]) {
		case 1:
		case 2:
			if (mCounter == ObjWinLoseReason::msVal.mProgressFrame) {
				Morimura::TGameOverBase* obj = static_cast<Morimura::TGameOverBase*>(mScreenObj[i]);
				P2ASSERTLINE(272, obj);
				obj->mTimeSpeed = -ObjWinLoseReason::msVal._18;
			} else if (mCounter > ObjWinLoseReason::msVal.mFinishFrame) {
				mDone[i] = true;
			}
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	80410EA0
 * Size:	000020
 */
bool SceneWinLoseReason::doEnd(::Screen::EndSceneArg* arg) { return SceneBase::doEnd(arg); }

ObjWinLoseReason::StaticValues ObjWinLoseReason::msVal;

} // namespace Screen
} // namespace kh
