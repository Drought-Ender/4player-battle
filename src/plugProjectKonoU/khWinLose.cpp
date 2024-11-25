#include "kh/khWinLose.h"
#include "JSystem/JKernel/JKRFileLoader.h"
#include "kh/khUtil.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "utilityU.h"
#include "JSystem/J2D/J2DAnmLoader.h"

static void _Print(char* format, ...) { OSReport(format, __FILE__); }

namespace kh {
namespace Screen {

/*
 * --INFO--
 * Address:	8040FCE8
 * Size:	0000B8
 */
ObjWinLose::ObjWinLose()
{
	for (int i = 0; i < 4; i++) {
		mScreenA[i]   = nullptr;
		mScreenB[i]   = nullptr;
		mAnim1[i]     = nullptr;
		mAnim2[i]     = nullptr;
		mAnim3[i]     = nullptr;
		mAnim4[i]     = nullptr;
		mAnimTime4[i] = 0.0f;
		mAnimTime3[i] = 0.0f;
		mAnimTime2[i] = 0.0f;
		mAnimTime1[i] = 0.0f;
		mYOffset[i]   = 0.0f;
	}

	mDoUpdateAnim = false;
	mFrameTimer   = 0;
	mScreenNum    = 4;
	mAlpha        = 0;
}

/*
 * --INFO--
 * Address:	8040FDA0
 * Size:	000418
 */
void ObjWinLose::doCreate(JKRArchive* arc)
{

	char* winLoseList[3][3]
	    = { "win.blo", "win.bck", "win.bpk", "lose.blo", "lose.bck", "lose.bpk", "time_up.blo", "time_up.bck", "time_up.bpk" };

	char* drawList[4][3] = { "win_wait.blo",     "win_wait.bck",     "win_wait.bpk",     "lose_wait.blo", "lose_wait.bck", "lose_wait.bpk",
		                     "time_up_wait.blo", "time_up_wait.bck", "time_up_wait.bpk", "draw.blo",      "draw.bck",      "draw.bpk" };

	int arg[4] = { 0, 0, 0, 0 };

	if (!getDispMember()->isID(OWNER_KH, MEMBER_WIN_LOSE)) {
		JUT_PANICLINE(79, "disp member err");
	}

	DispWinLose* disp = static_cast<DispWinLose*>(getDispMember());
	mScreenNum = Game::gNaviNum;
	switch (disp->mOutcome) {
	case WinPlayer1:
	case WinPlayer2:
		arg[0] = 1 - disp->mNewOutcomes[0];
		arg[1] = 1 - disp->mNewOutcomes[1];
		arg[2] = 1 - disp->mNewOutcomes[2];
		arg[3] = 1 - disp->mNewOutcomes[3];
		break;
	case Draw: // draw
		arg[0] = 3;
		arg[1] = 3;
		arg[2] = 3;
		arg[3] = 3;
		break;
	case Timeup1P: // time out 1p
		arg[0]     = 2;
		arg[1]     = -1;
		mScreenNum = 1;
		break;
	case Timeup2P: // time out 2p
		arg[0] = 1 - disp->mNewOutcomes[0];
		arg[1] = 1 - disp->mNewOutcomes[1];
		arg[2] = 1 - disp->mNewOutcomes[2];
		arg[3] = 1 - disp->mNewOutcomes[3];
		break;
	}

	for (int i = 0; i < mScreenNum; i++) {
		if (disp->mOutcome != Draw) {
			mScreenA[i] = new P2DScreen::Mgr_tuning;
			mScreenA[i]->set(winLoseList[arg[i]][0], 0x40000, arc);

			void* file = JKRFileLoader::getGlbResource(winLoseList[arg[i]][1], arc);
			mAnim1[i]  = static_cast<J2DAnmTransform*>(J2DAnmLoaderDataBase::load(file));

			file      = JKRFileLoader::getGlbResource(winLoseList[arg[i]][2], arc);
			mAnim3[i] = static_cast<J2DAnmColor*>(J2DAnmLoaderDataBase::load(file));
			mScreenA[i]->setAnimation(mAnim1[i]);
			mScreenA[i]->setAnimation(mAnim3[i]);

		} else {
			mDoUpdateAnim = true;
		}

		mScreenB[i] = new P2DScreen::Mgr_tuning;
		mScreenB[i]->set(drawList[arg[i]][0], 0x40000, arc);

		void* file = JKRFileLoader::getGlbResource(drawList[arg[i]][1], arc);
		mAnim2[i]  = static_cast<J2DAnmTransform*>(J2DAnmLoaderDataBase::load(file));

		file      = JKRFileLoader::getGlbResource(drawList[arg[i]][2], arc);
		mAnim4[i] = static_cast<J2DAnmColor*>(J2DAnmLoaderDataBase::load(file));
		mScreenB[i]->setAnimation(mAnim2[i]);
		mScreenB[i]->setAnimation(mAnim4[i]);

		setInfAlpha(mScreenB[i]->search('ROOT'));
		mScreenB[i]->search('ROOT')->setAlpha(mAlpha);
	}

	if (mScreenNum == 2) {
		mYOffset[0] = msVal.mYOffsetP1;
		mYOffset[1] = msVal.mYOffsetP2;
	}
	else {
		mYOffset[0] = msVal.mYOffsetP1;
		mYOffset[1] = msVal.mYOffsetP1;
		mYOffset[2] = msVal.mYOffsetP2;
		mYOffset[3] = msVal.mYOffsetP2;

		mXOffset[0] = -160.0f;
		mXOffset[1] = 160.0f;
		mXOffset[2] = -160.0f;
		mXOffset[3] = 160.0f;
	}

	getOwner()->setColorBG(0, 0, 0, 160);
	switch (disp->mOutcome) {
	case Timeup1P:
	case Timeup2P:
		PSStartChallengeTimeUpStream();
		break;
	}
}

/*
 * --INFO--
 * Address:	804101B8
 * Size:	000020
 */
bool ObjWinLose::doUpdate() { return updateAnimation(); }

/*
 * --INFO--
 * Address:	804101D8
 * Size:	0000B8
 */
void ObjWinLose::doDraw(Graphics& gfx)
{
	gfx.mOrthoGraph.setPort();

	for (int i = 0; i < mScreenNum; i++) {
		u16 y0 = 0;
		u16 y2 = System::getRenderModeObj()->efbHeight;
		u16 y1 = y2;

		u16 x0 = 0;
		u16 x1 = System::getRenderModeObj()->fbWidth;
		u16 x2 = x1;
		int type = (Game::gNaviNum > 2) ? i + 3 : i + 1;
		switch (type) {
		case 1: // top
			y1 = y2 / 2;
			break;
		case 2: // bottom
			y0 = y2 / 2;
			break;
		case 3: // top left
			y1 = y2 / 2;
			x1 = x2 / 2;
			break;
		case 4: // top right
			y1 = y2 / 2;
			x0 = x2 / 2;
			break;
		case 5: // bottom left
			y0 = y2 / 2;
			x1 = x2 / 2;
			break;
		case 6: // bottom right
			y0 = y2 / 2;
			x0 = x2 / 2;
		}

		GXSetScissor(x0, y0, x1, y1);

		if (mScreenA[i])
			mScreenA[i]->draw(gfx, gfx.mOrthoGraph);

		mScreenB[i]->draw(gfx, gfx.mOrthoGraph);
	}
}

/*
 * --INFO--
 * Address:	80410290
 * Size:	00038C
 */
bool ObjWinLose::updateAnimation()
{
	for (int i = 0; i < mScreenNum; i++) {
		if (mScreenA[i]) {
			mAnim1[i]->mCurrentFrame = mAnimTime1[i];
			mAnim3[i]->mCurrentFrame = mAnimTime3[i];
			mScreenA[i]->animation();
			mAnimTime1[i] += msVal.mAnimSpeed;
			mAnimTime3[i] += msVal.mAnimSpeed;

			if (mAnimTime1[i] >= msVal.mDuration) {
				mDoUpdateAnim = true;
			}

			if (mAnimTime1[i] >= mAnim1[i]->mMaxFrame || mAnimTime3[i] >= mAnim3[i]->mMaxFrame) {
				mAnimTime3[i] = 0.0f;
				mAnimTime1[i] = 0.0f;
				mScreenA[i]->hide();
			}
			mScreenA[i]->search('ROOT')->add(mXOffset[i], mYOffset[i]);
		}

		if (mDoUpdateAnim) {
			mAnim2[i]->mCurrentFrame = mAnimTime2[i];
			mAnim4[i]->mCurrentFrame = mAnimTime4[i];
			mScreenB[i]->animation();
			mAnimTime2[i] += 1.0f;
			mAnimTime4[i] += 1.0f;

			if (mAnimTime2[i] >= mAnim2[i]->mMaxFrame) {
				mAnimTime2[i] = 0.0f;
			}
			if (mAnimTime4[i] >= mAnim4[i]->mMaxFrame) {
				mAnimTime4[i] = 0.0f;
			}
			mScreenB[i]->search('ROOT')->setOffset(mXOffset[i], mYOffset[i]);
			mScreenB[i]->search('ROOT')->setAlpha(mAlpha);
			if (mAlpha < 255 - msVal.mAlphaInc) {
				mAlpha += msVal.mAlphaInc;
			} else {
				mAlpha = 255;
			}
		}
	}

	if (!getDispMember()->isID(OWNER_KH, MEMBER_WIN_LOSE)) {
		JUT_PANICLINE(276, "disp member err");
	}

	DispWinLose* disp = static_cast<DispWinLose*>(getDispMember());
	int old           = mFrameTimer + 1;
	mFrameTimer       = old;
	if (old > msVal.mEndBGMFrame) {
		disp->_0C = 3;
		PSStop2DStream();
		PSMuteOffSE_on2D();
	} else if (mFrameTimer > msVal.mFinishFrame) {
		disp->_0C = 2;
	}
	return false;
}

ObjWinLose::StaticValues ObjWinLose::msVal;

} // namespace Screen
} // namespace kh
