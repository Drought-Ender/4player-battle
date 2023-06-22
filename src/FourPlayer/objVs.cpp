#include "og/newScreen/Vs.h"
#include "og/newScreen/Challenge.h"
#include "og/Sound.h"
#include "efx2d/T2DSprayset.h"
#include "efx2d/T2DSensor.h"
#include "FourPlayer.h"
#include "JSystem/JUtility/JUTTexture.h"

namespace og
{

namespace newScreen
{

FourObjVs::FourObjVs(const char* name) : ObjVs(name) {
    mScreenP3 = nullptr;
    mScreenP4 = nullptr;

    mObakeEnabledP3 = false;
    mObakeEnabledP4 = false;
    mPaneObake3P = nullptr;
    mPaneObake4P = nullptr;
    mAlphaObakeP3 = 0.0f;
    mAlphaObakeP4 = 0.0f;

    for (int i = 0; i < 4; i++) {
        mWinDamaColor[i] = 0;

        mBedamaGotFlagsP3[i] = false;
        mBedamaGotFlagsP4[i] = false;

        mPane_nodama3P[i] = nullptr;
        mPane_bedama3P[i] = nullptr;
        mPane_windama3P[i] = nullptr;

        mPane_bedama4P[i] = nullptr;
        mPane_nodama4P[i] = nullptr;
        mPane_windama4P[i] = nullptr;

        mScaleMgrP3_1[i] = nullptr;
        mScaleMgrP3_2[i] = nullptr;

        mScaleMgrP4_1[i] = nullptr;
        mScaleMgrP4_2[i] = nullptr;

        mBedamaGetTimers[i] = 0.05f;

        mColoredBedamaPanes[i] = nullptr;
    }

    mHasAllBedamaP3 = false;
    mHasAllBedamaP4 = false;

    mFirstBedamaGetP3 = false;
    mFirstBedamaGetP4 = false; 
}

typedef JUtility::TColor TColorPair[2];

const TColorPair gGetMarbleColors[4] = { 
	{ 0xff0000ff, 0xff8787ff },  
	{ 0x2020ffff, 0x5787ffff },
	{ 0x00000000, 0x00000000 },
	{ 0x00000000, 0x00000000 }
};

void FourObjVs::doCreate(JKRArchive* arc) {
    mScreenP1 = new ScreenSet;
	mScreenP2 = new ScreenSet;
    mScreenP3 = new ScreenSet;
    mScreenP4 = new ScreenSet;

	og::Screen::DispMemberVs* disp = static_cast<og::Screen::DispMemberVs*>(getDispMember());
	if (disp->isID(OWNER_OGA, MEMBER_VS)) {
		mDisp = disp;
	} else {
		if (disp->isID(OWNER_OGA, MEMBER_DUMMY)) {
			mDisp = new og::Screen::DispMemberVs;
		} else {
			JUT_PANICLINE(246, "ERR! in ObjVS CreateŽ¸”sI\n");
		}
	}

	mBloGroup = new og::Screen::BloGroup(4);
	mBloGroup->addBlo("challenge_1P.blo", mScreenP1->mScreen, 0x1040000, arc);
	mBloGroup->addBlo("challenge_1P.blo", mScreenP2->mScreen, 0x1040000, arc);
    mBloGroup->addBlo("challenge_1P.blo", mScreenP3->mScreen, 0x1040000, arc);
    mBloGroup->addBlo("challenge_1P.blo", mScreenP4->mScreen, 0x1040000, arc);

	mScreenP1->init(&mDisp->mOlimarData, arc, &mDisp->mP1PikminCount);
	mScreenP2->init(&mDisp->mLouieData, arc, &mDisp->mP2PikminCount);
    mScreenP3->init(&mDisp->mP3Data, arc, &mDisp->mP3PikminCount);
    mScreenP4->init(&mDisp->mP4Data, arc, &mDisp->mP4PikminCount);

	P2DScreen::Mgr_tuning* bdamaScreen = new P2DScreen::Mgr_tuning;
	bdamaScreen->set("b_dama.blo", 0x1040000, arc);

	P2DScreen::Mgr_tuning* scrn1 = mScreenP1->mScreen;
	P2DScreen::Mgr_tuning* scrn2 = mScreenP2->mScreen;
    P2DScreen::Mgr_tuning* scrn3 = mScreenP3->mScreen;
    P2DScreen::Mgr_tuning* scrn4 = mScreenP4->mScreen;

	J2DPictureEx* louiePicture = static_cast<J2DPictureEx*>(mScreenP2->mScreen->search('navi'));
	J2DPictureEx* presidentPicture = static_cast<J2DPictureEx*>(mScreenP3->mScreen->search('navi'));
	J2DPictureEx* wifePicture = static_cast<J2DPictureEx*>(mScreenP4->mScreen->search('navi'));
	
	louiePicture->changeTexture("loozy_pk2.bti", 0);
	presidentPicture->changeTexture("president.bti", 0);
	wifePicture->changeTexture("wife.bti", 0);

	JUtility::TColor teamColors[4] = {
		JUtility::TColor(0xff, 0x00, 0x00, 0xff),
		JUtility::TColor(0x00, 0x00, 0xff, 0xff),
		JUtility::TColor(0x00, 0x00, 0x00, 0xff),
		JUtility::TColor(0x00, 0x00, 0x00, 0xff)
	};
	
	recolorPane(scrn1, teamColors[Game::getVsTeam(0)]);
	recolorPane(scrn2, teamColors[Game::getVsTeam(1)]);
	recolorPane(scrn3, teamColors[Game::getVsTeam(2)]);
	recolorPane(scrn4, teamColors[Game::getVsTeam(3)]);

	J2DPictureEx* paneBdamaR = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_red'));
	J2DPictureEx* paneBdamaY = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_yello'));
	J2DPictureEx* paneBdamaB = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_blue'));
	J2DPictureEx* panePcup   = static_cast<J2DPictureEx*>(bdamaScreen->search('Pcup'));

    mColoredBedamaPanes[0] = paneBdamaR;
    mColoredBedamaPanes[1] = paneBdamaB;

	J2DPane* root = scrn1->search('ROOT');

    bool use4PSetup = Game::gNaviNum > 2;

    f32 baseOffs = (Game::gNaviNum <= 2) ? msVal.mMarbleBaseXOffs : 260.0f;
    f32 baseYOffs = (Game::gNaviNum <= 2) ? msVal.mMarbleP1YOffs : msVal.mMarbleP1YOffs - 40.0f;

    

	u32 xoffs     = 0;
    u32 yoffs     = 0;
	for (int i = 0; i < 4; i++) {
		mPane_bedama1P[i]
		    = og::Screen::CopyPictureToPane(paneBdamaY, root, baseOffs + xoffs, baseYOffs + yoffs, 'bd1P_000' + i);
		mPane_nodama1P[i]
		    = og::Screen::CopyPictureToPane(panePcup, root, baseOffs + xoffs, baseYOffs + yoffs, 'nd1P_000' + i);
		mPane_windama1P[i]
		    = og::Screen::CopyPictureToPane(paneBdamaR, root, baseOffs + xoffs, baseYOffs + yoffs, 'wd1P_000' + i);
		mScaleMgrP1_1[i] = new og::Screen::ScaleMgr;
		mScaleMgrP1_2[i] = new og::Screen::ScaleMgr;
		xoffs += 40;
        if (i == 1 && use4PSetup) {
            xoffs = 0;
            yoffs += 40;
        }
		mPane_windama1P[i]->hide();
	}

    

	J2DPane* root2 = scrn2->search('ROOT');
	xoffs          = 0;
    yoffs          = 0;
	for (int i = 0; i < 4; i++) {
		mPane_bedama2P[i]
		    = og::Screen::CopyPictureToPane(paneBdamaY, root2, baseOffs + xoffs, baseYOffs + yoffs, 'bd1P_000' + i);
		mPane_nodama2P[i]
		    = og::Screen::CopyPictureToPane(panePcup, root2, baseOffs + xoffs, baseYOffs + yoffs, 'nd1P_000' + i);
		mPane_windama2P[i]
		    = og::Screen::CopyPictureToPane(paneBdamaR, root2, baseOffs + xoffs, baseYOffs + yoffs, 'wd1P_000' + i);
		mScaleMgrP2_1[i] = new og::Screen::ScaleMgr;
		mScaleMgrP2_2[i] = new og::Screen::ScaleMgr;
		xoffs += 40;
        if (i == 1 && use4PSetup) {
            xoffs = 0;
            yoffs += 40;
        }
		mPane_windama2P[i]->hide();
	}


    J2DPane* root3 = scrn3->search('ROOT');
    xoffs     = 0;
    yoffs     = 0;
	for (int i = 0; i < 4; i++) {
		mPane_bedama3P[i]
		    = og::Screen::CopyPictureToPane(paneBdamaY, root3, baseOffs + xoffs, baseYOffs + yoffs, 'bd1P_000' + i);
		mPane_nodama3P[i]
		    = og::Screen::CopyPictureToPane(panePcup, root3, baseOffs + xoffs, baseYOffs + yoffs, 'nd1P_000' + i);
		mPane_windama3P[i]
		    = og::Screen::CopyPictureToPane(paneBdamaR, root3, baseOffs + xoffs, baseYOffs + yoffs, 'wd1P_000' + i);
		mScaleMgrP3_1[i] = new og::Screen::ScaleMgr;
		mScaleMgrP3_2[i] = new og::Screen::ScaleMgr;
		xoffs += 40;
        if (i == 1 && use4PSetup) {
            xoffs = 0;
            yoffs += 40;
        }
		mPane_windama3P[i]->hide();
	}

    J2DPane* root4 = scrn4->search('ROOT');
    xoffs     = 0;
    yoffs     = 0;
	for (int i = 0; i < 4; i++) {
		mPane_bedama4P[i]
		    = og::Screen::CopyPictureToPane(paneBdamaY, root4, baseOffs + xoffs, baseYOffs + yoffs, 'bd1P_000' + i);
		mPane_nodama4P[i]
		    = og::Screen::CopyPictureToPane(panePcup, root4, baseOffs + xoffs, baseYOffs + yoffs, 'nd1P_000' + i);
		mPane_windama4P[i]
		    = og::Screen::CopyPictureToPane(paneBdamaR, root4, baseOffs + xoffs, baseYOffs + yoffs, 'wd1P_000' + i);
		mScaleMgrP4_1[i] = new og::Screen::ScaleMgr;
		mScaleMgrP4_2[i] = new og::Screen::ScaleMgr;
		xoffs += 40;
        if (i == 1 && use4PSetup) {
            xoffs = 0;
            yoffs += 40;
        }
		mPane_windama4P[i]->hide();
	}

	mScreenIcons = new P2DScreen::Mgr_tuning;
	mScreenIcons->set("obake_icon.blo", 0x1040000, arc);

	J2DPictureEx* paneObake = static_cast<J2DPictureEx*>(mScreenIcons->search('obake'));
	mPaneObake1P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP1YOffs, 'obake1P');
	mPaneObake2P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs + 300.0f, msVal.mRouletteP1YOffs, 'obake1P');
    mPaneObake3P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP2YOffs, 'obake2P');
	mPaneObake4P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs + 300.0f, msVal.mRouletteP2YOffs, 'obake2P');
	mPaneObake1P->setAlpha(mAlphaObakeP1 * 255.0f);
	mPaneObake2P->setAlpha(mAlphaObakeP2 * 255.0f);
    mPaneObake3P->setAlpha(mAlphaObakeP1 * 255.0f);
	mPaneObake4P->setAlpha(mAlphaObakeP2 * 255.0f);
    // for (int i = 0; i < 4; i++) {
    //     setWinBedamaColor(i, mDisp->mWinMarbleColors[i]);
    // }
    setOnOffBdama4P(false);
}

// gets inlined normally
void ObjVs::ScreenSet::update(og::Screen::DataNavi& data)
{
	f32 scale5 = mScaleMgr1->calc();
	f32 scale6 = mScaleMgr2->calc();
	if (mPaneToyo01)
		mPaneToyo01->updateScale(scale5);
	if (mPaneToyo00)
		mPaneToyo00->updateScale(scale6);

	og::Screen::DopingCheck* dope = mDoping;
	dope->mNaviLifeRatio          = data.mNaviLifeRatio;
	dope->mFollowPiki             = data.mFollowPikis;
	dope->mNextThrowPiki          = data.mNextThrowPiki;
	dope->mSpicySprayCount        = data.mDope1Count;
	dope->mBitterSprayCount       = data.mDope0Count;
	dope->mActiveNaviID           = data.mActiveNaviID;
	dope->update();
}

bool FourObjVs::checkUpdateWinColor() {
    bool updated = false;
    for (int i = 0; i < 4; i++) {
        if (mDisp->mWinMarbleColors[i] != mWinDamaColor[i]) {
            setWinBedamaColor(mDisp->mWinMarbleColors[i], i);
            updated = true;
        }
    }
    return updated;
}

void FourObjVs::doUpdateCommon() {
    checkUpdateWinColor();
    setOnOffBdama4P(!mSetBedamaFlag);
    checkObake();
	if (mDoneState == 1) {
		if (mFinishTimer <= 0.0f)
			mDoneState = 2;
		else
			mFinishTimer -= sys->mDeltaTime;
	}
	mDisp->mDoneState = mDoneState;
    f32 scale = (pikmin2_cosf(mScale * PI) + 1.0f) * 0.5f;
    if (mDisp->mTwoPlayer) {
        mScreenP3->mScreen->hide();
		
        mScreenP4->mScreen->hide();
		mScreenP3->mScreen->setXY(-300.0f, 0.0f);
		mScreenP4->mScreen->setXY(-300.0f, 0.0f); // hacky way to fix life gaudges
        mScreenP1->mScreen->setXY(0.0f, scale * -300.0f);
        mScreenP2->mScreen->setXY(0.0f, scale * 300.0f + 205.0f);
    }
    else {
        mScreenP3->update(mDisp->mP3Data);
        mScreenP4->update(mDisp->mP4Data);
        mScreenP1->mScreen->setXY(-10.0f, scale * -300.0f);
        mScreenP2->mScreen->setXY(300.0f, scale * -300.0f);
        mScreenP3->mScreen->setXY(-10.0f, scale * 300.0f + 205.0f);
        mScreenP4->mScreen->setXY(300.0f, scale * 300.0f + 205.0f);
        if (mDisp->mHideP4) {
            mScreenP4->mScreen->hide();
        }
    }
    mBloGroup->update();
}

bool FourObjVs::doUpdateFadein() {
	bool check = false;
	mFadeLevel += sys->mDeltaTime;

	if (mFadeLevel > msVal.mFadeInRate) {
		mFadeLevel = msVal.mFadeInRate;
		check      = true;
	}
	mScale = mFadeLevel / msVal.mFadeInRate;
	doUpdateCommon();
	return check;
}

void FourObjVs::doUpdateFadeinFinish() {

}

bool FourObjVs::doUpdate() {
    doUpdateCommon();
    if (mSetBedamaFlag) {
		mSetBedamaFlag = false;
	}
    return false;
}

void FourObjVs::doUpdateFinish() {
    mFadeLevel = 0.0f;
}

bool FourObjVs::doUpdateFadeout() {
	bool check = false;
	mFadeLevel += sys->mDeltaTime;
	if (mFadeLevel > msVal.mFadeOutRate) {
		mFadeLevel = msVal.mFadeOutRate;
		check      = true;
	}
	mScale = 1.0f - mFadeLevel / msVal.mFadeOutRate;
	doUpdateCommon();
	return check;
}

void FourObjVs::doUpdateFadeoutFinish() {
    ObjVs::doUpdateFadeoutFinish();
}

void FourObjVs::doDraw(Graphics& gfx) {
    if (!mDisp->mTwoPlayer) {
        J2DPerspGraph* graf = &gfx.mPerspGraph;
        graf->setPort();

        JUtility::TColor color1 = ObjChallenge2P::msVal._20;
        int test                = (f32)color1.a * mScale;
        color1.a                = test;
        graf->setColor(color1);

        JGeometry::TBox2f box;
        box.i   = JGeometry::TVec2f(302, 0);
        box.f.x = box.i.x + 4;
        box.f.y = box.i.y + 450;

        graf->fillBox(box);
    }
    ObjVs::doDraw(gfx);
}

void FourObjVs::setOnOffBdama4P(bool doEfx)
{
    bool P1win = false;
    bool P2win = false;
	bool P3win = false;
	bool P4win = false;

	for (int i = 0; i < 4; i++) {
        f32 p1ScaleYellow = mScaleMgrP1_1[i]->calc();
		f32 p2ScaleYellow = mScaleMgrP2_1[i]->calc();
		f32 p1ScaleColor = mScaleMgrP1_2[i]->calc();
		f32 p2ScaleColor = mScaleMgrP2_2[i]->calc();
		f32 p3ScaleYellow = mScaleMgrP3_1[i]->calc();
		f32 p4ScaleYellow = mScaleMgrP4_1[i]->calc();
		f32 p3ScaleColor = mScaleMgrP3_2[i]->calc();
		f32 p4ScaleColor = mScaleMgrP4_2[i]->calc();

        mPane_windama1P[i]->updateScale(p1ScaleColor);
        mPane_windama2P[i]->updateScale(p2ScaleColor);
		mPane_windama3P[i]->updateScale(p3ScaleColor);
		mPane_windama4P[i]->updateScale(p4ScaleColor);

        if (mDisp->mFlags[0] && mDisp->mMarbleCountP1 == i && mBedamaGetTimers[0] > 0.0f) {
			mBedamaGetTimers[0] -= sys->mDeltaTime;
			if (mBedamaGetTimers[0] <= 0.0f) {
				mPane_windama1P[i]->show();
				if (!mFirstBedamaGetP1) {
					mFirstBedamaGetP1 = true;
					if (doEfx) {
						Vector2f pos;
						og::Screen::calcGlbCenter(mPane_windama1P[i], &pos);
						const TColorPair& colors = gGetMarbleColors[mWinDamaColor[0]];
						efx2d::ArgScaleColorColor arg(&pos, 1.0f, colors[0], colors[1]);
						efx2d::T2DSprayset_forVS efx;
						efx.create(&arg);
						ogSound->setBdamaGet();
						mDoneState = 1;
						mScaleMgrP1_2[i]->up();
						P1win = true;
					}
				}
			}
		}

        if (mDisp->mFlags[1] && mDisp->mMarbleCountP2 == i && mBedamaGetTimers[1] > 0.0f) {
			mBedamaGetTimers[1] -= sys->mDeltaTime;
			if (mBedamaGetTimers[1] <= 0.0f) {
				mPane_windama2P[i]->show();
				if (!mFirstBedamaGetP2) {
					mFirstBedamaGetP2 = true;
					if (doEfx) {
						Vector2f pos;
						og::Screen::calcGlbCenter(mPane_windama2P[i], &pos);
						const TColorPair& colors = gGetMarbleColors[mWinDamaColor[1]];
						efx2d::ArgScaleColorColor arg(&pos, 1.0f, colors[0], colors[1]);
						efx2d::T2DSprayset_forVS efx;
						efx.create(&arg);
						ogSound->setBdamaGet();
						mDoneState = 1;
						mScaleMgrP2_2[i]->up();
						P2win = true;
					}
				}
			}
		}

		if (mDisp->mFlag2[0] && mDisp->mMarbleCountP3 == i && mBedamaGetTimers[2] > 0.0f) {
			mBedamaGetTimers[2] -= sys->mDeltaTime;
			if (mBedamaGetTimers[2] <= 0.0f) {
				mPane_windama3P[i]->show();
				if (!mFirstBedamaGetP3) {
					mFirstBedamaGetP3 = true;
					if (doEfx) {
						Vector2f pos;
						og::Screen::calcGlbCenter(mPane_windama3P[i], &pos);
						const TColorPair& colors = gGetMarbleColors[mWinDamaColor[2]];
						efx2d::ArgScaleColorColor arg(&pos, 1.0f, colors[0], colors[1]);
						efx2d::T2DSprayset_forVS efx;
						efx.create(&arg);
						ogSound->setBdamaGet();
						mDoneState = 1;
						mScaleMgrP3_2[i]->up();
						P3win = true;
					}
				}
			}
		}

		if (mDisp->mFlag2[1] && mDisp->mMarbleCountP4 == i && mBedamaGetTimers[3] > 0.0f) {
			mBedamaGetTimers[3] -= sys->mDeltaTime;
			if (mBedamaGetTimers[3] <= 0.0f) {
				mPane_windama4P[i]->show();
				if (!mFirstBedamaGetP4) {
					mFirstBedamaGetP4 = true;
					if (doEfx) {
						Vector2f pos;
						og::Screen::calcGlbCenter(mPane_windama4P[i], &pos);
						const TColorPair& colors = gGetMarbleColors[mWinDamaColor[3]];
						efx2d::ArgScaleColorColor arg(&pos, 1.0f, colors[0], colors[1]);
						efx2d::T2DSprayset_forVS efx;
						efx.create(&arg);
						ogSound->setBdamaGet();
						mDoneState = 1;
						mScaleMgrP4_2[i]->up();
						P4win = true;
					}
				}
			}
		}

		if (!mFirstBedamaGetP1 && !mFirstBedamaGetP2 && !mFirstBedamaGetP3 && !mFirstBedamaGetP4) {
            if (mDisp->mMarbleCountP1 > i) {
				mPane_nodama1P[i]->hide();
				mPane_bedama1P[i]->show();
				mPane_bedama1P[i]->updateScale(p1ScaleYellow);
				if (!mBedamaGotFlagsP1[i]) {
					if (i == 3) {
						mDoneState = 1;
					}
					mHasAllBedamaP1 = (i == 3);
					if (doEfx) {
						if (mDoneState != 1) {
							ogSound->setBdamaGet();
							Vector2f pos;
							og::Screen::calcGlbCenter(mPane_bedama1P[i], &pos);

							efx2d::ArgScaleColorColor arg(&pos, 1.0f, 0xcfcf00ff, 0xe7e757ff);
							efx2d::T2DSprayset_forVS efx;
							efx.create(&arg);
						}
						mScaleMgrP1_1[i]->up();
					}
				}
				mBedamaGotFlagsP1[i] = true;
			} else {
				mPane_bedama1P[i]->hide();
				mPane_nodama1P[i]->show();
				mPane_nodama1P[i]->updateScale(p1ScaleYellow);
				mBedamaGotFlagsP1[i] = false;
			}

            if (mDisp->mMarbleCountP2 > i) {
				mPane_nodama2P[i]->hide();
				mPane_bedama2P[i]->show();
				mPane_bedama2P[i]->updateScale(p2ScaleYellow);
				if (!mBedamaGotFlagsP2[i]) {
					if (i == 3) {
						mDoneState = 1;
					}
					mHasAllBedamaP2 = (i == 3);
					if (doEfx) {
						if (mDoneState != 1) {
							ogSound->setBdamaGet();
							Vector2f pos;
							og::Screen::calcGlbCenter(mPane_bedama2P[i], &pos);

							efx2d::ArgScaleColorColor arg(&pos, 1.0f, 0xcfcf00ff, 0xe7e757ff);
							efx2d::T2DSprayset_forVS efx;
							efx.create(&arg);
						}
						mScaleMgrP3_1[i]->up();
					}
				}
				mBedamaGotFlagsP2[i] = true;
			} else {
				mPane_bedama2P[i]->hide();
				mPane_nodama2P[i]->show();
				mPane_nodama2P[i]->updateScale(p2ScaleYellow);
				mBedamaGotFlagsP2[i] = false;
			}

            if (mDisp->mMarbleCountP3 > i) {
				mPane_nodama3P[i]->hide();
				mPane_bedama3P[i]->show();
				mPane_bedama3P[i]->updateScale(p3ScaleYellow);
				if (!mBedamaGotFlagsP3[i]) {
					if (i == 3) {
						mDoneState = 1;
					}
					mHasAllBedamaP3 = (i == 3);
					if (doEfx) {
						if (mDoneState != 1) {
							ogSound->setBdamaGet();
							Vector2f pos;
							og::Screen::calcGlbCenter(mPane_bedama3P[i], &pos);

							efx2d::ArgScaleColorColor arg(&pos, 1.0f, 0xcfcf00ff, 0xe7e757ff);
							efx2d::T2DSprayset_forVS efx;
							efx.create(&arg);
						}
						mScaleMgrP3_1[i]->up();
					}
				}
				mBedamaGotFlagsP3[i] = true;
			} else {
				mPane_bedama3P[i]->hide();
				mPane_nodama3P[i]->show();
				mPane_nodama3P[i]->updateScale(p3ScaleYellow);
				mBedamaGotFlagsP3[i] = false;
			}


			if (mDisp->mMarbleCountP4 > i) {
				mPane_nodama4P[i]->hide();
				mPane_bedama4P[i]->show();
				mPane_bedama4P[i]->updateScale(p4ScaleYellow);
				if (!mBedamaGotFlagsP4[i]) {
					if (i == 3) {
						mDoneState = 1;
					}
					mHasAllBedamaP4 = (i == 3);
					if (doEfx) {
						if (mDoneState != 1) {
							ogSound->setBdamaGet();
							Vector2f pos;
							og::Screen::calcGlbCenter(mPane_bedama4P[i], &pos);

							efx2d::ArgScaleColorColor arg(&pos, 1.0f, 0xcfcf00ff, 0xe7e757ff);
							efx2d::T2DSprayset_forVS efx;
							efx.create(&arg);
						}
						mScaleMgrP4_1[i]->up();
					}
				}
				mBedamaGotFlagsP4[i] = true;
			} else {
				mPane_bedama4P[i]->hide();
				mPane_nodama4P[i]->show();
				mPane_nodama4P[i]->updateScale(p4ScaleYellow);
				mBedamaGotFlagsP4[i] = false;
			}
		}
	}

    if (mHasAllBedamaP1 && mBedamaGetTimers[0] > 0.0f) {
		mBedamaGetTimers[0] -= sys->mDeltaTime;
		if (mBedamaGetTimers[0] < 0.0f && doEfx) {
			ogSound->setBdamaGet();
			f32 scale = 0.6f;
			for (int i = 0; i < 4; i++) {
				mScaleMgrP1_1[i]->up();
				Vector2f pos;
				og::Screen::calcGlbCenter(mPane_bedama1P[i], &pos);

				efx2d::ArgScale arg(&pos, scale);
				efx2d::T2DSensorGet_forVS efx;
				efx.create(&arg);
				P1win = true;
			}
		}
	}

    if (mHasAllBedamaP2 && mBedamaGetTimers[1] > 0.0f) {
		mBedamaGetTimers[1] -= sys->mDeltaTime;
		if (mBedamaGetTimers[1] < 0.0f && doEfx) {
			ogSound->setBdamaGet();
			f32 scale = 0.6f;
			for (int i = 0; i < 4; i++) {
				mScaleMgrP2_1[i]->up();
				Vector2f pos;
				og::Screen::calcGlbCenter(mPane_bedama2P[i], &pos);

				efx2d::ArgScale arg(&pos, scale);
				efx2d::T2DSensorGet_forVS efx;
				efx.create(&arg);
				P2win = true;
			}
		}
	}

	if (mHasAllBedamaP3 && mBedamaGetTimers[2] > 0.0f) {
		mBedamaGetTimers[2] -= sys->mDeltaTime;
		if (mBedamaGetTimers[2] < 0.0f && doEfx) {
			ogSound->setBdamaGet();
			f32 scale = 0.6f;
			for (int i = 0; i < 4; i++) {
				mScaleMgrP3_1[i]->up();
				Vector2f pos;
				og::Screen::calcGlbCenter(mPane_bedama3P[i], &pos);

				efx2d::ArgScale arg(&pos, scale);
				efx2d::T2DSensorGet_forVS efx;
				efx.create(&arg);
				P3win = true;
			}
		}
	}

	if (mHasAllBedamaP4 && mBedamaGetTimers[3] > 0.0f) {
		mBedamaGetTimers[3] -= sys->mDeltaTime;
		if (mBedamaGetTimers[3] < 0.0f && doEfx) {
			ogSound->setBdamaGet();
			f32 scale = 0.6f;
			for (int i = 0; i < 4; i++) {
				mScaleMgrP4_1[i]->up();
				Vector2f pos;
				og::Screen::calcGlbCenter(mPane_bedama4P[i], &pos);

				efx2d::ArgScale arg(&pos, scale);
				efx2d::T2DSensorGet_forVS efx;
				efx.create(&arg);
				P4win = true;
			}
		}
	}

	if (!mPlayWinSound) {
		if (P1win && P2win) {
			mPlayWinSound = true;
			ogSound->setVsDraw();
		} else if (P1win) {
			mPlayWinSound = true;
			ogSound->setVsWin1P();
		} else if (P2win) {
			mPlayWinSound = true;
			ogSound->setVsWin2P();
		}
	}
}

union U32Name
{
    U32Name(u32 val) {
        mU32View = val;
    }

    u32 mU32View;
    u8 mU8View[4];
};

typedef J2DPictureEx* BedamaPaneType[4];

void FourObjVs::setWinBedamaColor(int color, int player) {
    OSReport("FourObjVs::setWinBedamaColor(int %i, int %i)\n", color, player);
    ScreenSet* screens[4] = { mScreenP1, mScreenP2, mScreenP3, mScreenP4 }; 

    J2DPictureEx** winDamaPanes[] = { mPane_windama1P, mPane_windama2P, mPane_windama3P, mPane_windama4P};

    f32 baseOffs = (Game::gNaviNum <= 2) ? msVal.mMarbleBaseXOffs : 260.0f;
    f32 baseYOffs = (Game::gNaviNum <= 2) ? msVal.mMarbleP1YOffs : msVal.mMarbleP1YOffs - 40.0f;

    

    u32 xoffs = 0;
    u32 yoffs = 0;
    J2DPane* root = screens[player]->mScreen->search('ROOT');
    J2DPictureEx** winDamas = winDamaPanes[player];

    mWinDamaColor[player] = color;


    for (int bedamaIdx = 0; bedamaIdx < 4; bedamaIdx++) {
        winDamas[bedamaIdx]->changeTexture(mColoredBedamaPanes[color]->getTIMG(0), 0);
    }
    
}

void FourObjVs::checkObake()
{
	if (mObakeEnabledP1) {
		mAlphaObakeP1 += sys->mDeltaTime;
		if (mAlphaObakeP1 > 1.0f)
			mAlphaObakeP1 = 1.0f;

		if (mDisp->mGhostIconTimerP1 <= 0.0f) {
			mObakeEnabledP1 = false;
		}
	} else {
		mAlphaObakeP1 -= sys->mDeltaTime;
		if (mAlphaObakeP1 < 0.0f)
			mAlphaObakeP1 = 0.0f;

		if (mDisp->mFlags[2]) {
			mObakeEnabledP1 = true;
		}
	}

	if (mObakeEnabledP2) {
		mAlphaObakeP2 += sys->mDeltaTime;
		if (mAlphaObakeP2 > 1.0f)
			mAlphaObakeP2 = 1.0f;

		if (mDisp->mGhostIconTimerP2 <= 0.0f) {
			mObakeEnabledP2 = false;
		}
	} else {
		mAlphaObakeP2 -= sys->mDeltaTime;
		if (mAlphaObakeP2 < 0.0f)
			mAlphaObakeP2 = 0.0f;

		if (mDisp->mFlags[3]) {
			mObakeEnabledP2 = true;
		}
	}

    if (mObakeEnabledP2) {
		mAlphaObakeP2 += sys->mDeltaTime;
		if (mAlphaObakeP2 > 1.0f)
			mAlphaObakeP2 = 1.0f;

		if (mDisp->mGhostIconTimerP2 <= 0.0f) {
			mObakeEnabledP2 = false;
		}
	} else {
		mAlphaObakeP2 -= sys->mDeltaTime;
		if (mAlphaObakeP2 < 0.0f)
			mAlphaObakeP2 = 0.0f;

		if (mDisp->mFlags[3]) {
			mObakeEnabledP2 = true;
		}
	}

    if (mObakeEnabledP3) {
		mAlphaObakeP3 += sys->mDeltaTime;
		if (mAlphaObakeP3 > 1.0f)
			mAlphaObakeP3 = 1.0f;

		if (mDisp->mGhostIconTimerP3 <= 0.0f) {
			mObakeEnabledP3 = false;
		}
	} else {
		mAlphaObakeP3 -= sys->mDeltaTime;
		if (mAlphaObakeP3 < 0.0f)
			mAlphaObakeP3 = 0.0f;

		if (mDisp->mFlag2[2]) {
			mObakeEnabledP3 = true;
		}
	}

    if (mObakeEnabledP4) {
		mAlphaObakeP4 += sys->mDeltaTime;
		if (mAlphaObakeP4 > 1.0f)
			mAlphaObakeP4 = 1.0f;

		if (mDisp->mGhostIconTimerP4 <= 0.0f) {
			mObakeEnabledP4 = false;
		}
	} else {
		mAlphaObakeP4 -= sys->mDeltaTime;
		if (mAlphaObakeP4 < 0.0f)
			mAlphaObakeP4 = 0.0f;

		if (mDisp->mFlag2[3]) {
			mObakeEnabledP4 = true;
		}
	}

	f32 calc = mObakeMovePos * 2.0f;
	calc     = (pikmin2_sinf(calc) + 1.0f) * 0.5f;

	f32 mod1 = 1.0f;
	f32 mod2 = 1.0f;
    f32 mod3 = 1.0f;
    f32 mod4 = 1.0f;
	f32 angle1, angle2, angle3, angle4;

	if (!mObakeEnabledP1) {
		angle1 = 0.0f;
	} else {
		f32 temp = mDisp->mGhostIconTimerP1;
		angle1   = 1.0f;
		if (temp < 10.0f) {
			angle1 = temp / 10.0f;
			mod1   = calc * 0.6f + 0.4f;
		}
	}

	if (!mObakeEnabledP2) {
		angle2 = 0.0f;
	} else {
		f32 temp = mDisp->mGhostIconTimerP2;
		angle2   = 1.0f;
		if (temp < 10.0f) {
			angle2 = temp / 10.0f;
			mod2   = calc * 0.6f + 0.4f;
		}
	}

    if (!mObakeEnabledP3) {
		angle3 = 0.0f;
	} else {
		f32 temp = mDisp->mGhostIconTimerP3;
		angle3   = 1.0f;
		if (temp < 10.0f) {
			angle3 = temp / 10.0f;
			mod3   = calc * 0.6f + 0.4f;
		}
	}

    if (!mObakeEnabledP4) {
		angle4 = 0.0f;
	} else {
		f32 temp = mDisp->mGhostIconTimerP4;
		angle4   = 1.0f;
		if (temp < 10.0f) {
			angle4 = temp / 10.0f;
			mod4   = calc * 0.6f + 0.4f;
		}
	}

	mPaneObake1P->setAlpha(mAlphaObakeP1 * 255.0f * mod1);
	mPaneObake2P->setAlpha(mAlphaObakeP2 * 255.0f * mod2);
    mPaneObake3P->setAlpha(mAlphaObakeP3 * 255.0f * mod3);
	mPaneObake4P->setAlpha(mAlphaObakeP4 * 255.0f * mod4);

	mObakeMovePos += sys->mDeltaTime * TAU;
	if (mObakeMovePos > TAU) {
		mObakeMovePos -= TAU;
	}
	f32 sin = pikmin2_sinf(mObakeMovePos);
	f32 cos = pikmin2_cosf(mObakeMovePos);
    f32 sin2 = pikmin2_sinf(mObakeMovePos + PI);
    f32 cos2 = pikmin2_cosf(mObakeMovePos + PI);
 	mPaneObake1P->rotate(angle1 * sin * 20.0f);
	mPaneObake2P->rotate(angle2 * sin2 * 20.0f);
    mPaneObake3P->rotate(angle3 * cos * 20.0f);
	mPaneObake4P->rotate(angle4 * cos2 * 20.0f);

	mPaneObake1P->setOffset(msVal.mRouletteXOffs + (sin * angle1) * msVal._2C,
	                        msVal.mRouletteP1YOffs + (cos * angle1) * msVal._30);
	mPaneObake2P->setOffset(300.0f + msVal.mRouletteXOffs + (sin2 * angle2) * msVal._2C,
	                        msVal.mRouletteP1YOffs + (cos2 * angle2) * msVal._30);
	mPaneObake3P->setOffset(msVal.mRouletteXOffs + (cos * angle3) * msVal._2C,
	                        msVal.mRouletteP2YOffs + (sin * angle3) * msVal._30);
	mPaneObake4P->setOffset(300.0f + msVal.mRouletteXOffs + (cos2 * angle4) * msVal._2C,
	                        msVal.mRouletteP2YOffs + (sin2 * angle4) * msVal._30);

	mPaneObake1P->updateScale(msVal.mRouletteScale);
	mPaneObake2P->updateScale(msVal.mRouletteScale);
    mPaneObake3P->updateScale(msVal.mRouletteScale);
    mPaneObake4P->updateScale(msVal.mRouletteScale);
}

void FourObjVs::recolorPane(P2DScreen::Mgr_tuning* pane, JUtility::TColor& color) {
	J2DGXColorS10 s10Color (color.r, color.g, color.b, 0x00);
	J2DGXColorS10 s10ColorWeak (color.r / 255.0f * 70, color.g / 255.0f * 70, color.b / 255.0f * 70, 0);
	
	JUtility::TColor tColorWeak(color.r / 255.0f * 191, color.g / 255.0f * 191, color.b / 255.0f * 191, 33);
	// P2ASSERT(pane);

	// color.a = 40;
	
    pane->getMaterial(pane->mNameTab->getIndex("mat_PICT_003_v_x"))->getTevBlock()->setTevColor(0, s10ColorWeak);
	pane->getMaterial(pane->mNameTab->getIndex("mat_PICT_004_v_x"))->getTevBlock()->setTevColor(0, s10ColorWeak);
	pane->getMaterial(pane->mNameTab->getIndex("mat_w_00_v"))->mTevBlock->setTevColor(0, s10Color);
	pane->getMaterial(pane->mNameTab->getIndex("mat_w_01_v"))->mTevBlock->setTevColor(0, s10Color);
	// pane->getMaterial(pane->mNameTab->getIndex("mat_x_00_v"))->mTevBlock->setTevColor(0, s10Color);
	// pane->getMaterial(pane->mNameTab->getIndex("mat_PICT_002_v_x"))->mTevBlock->setTevColor(0, s10Color);

	J2DMaterial* matX = pane->getMaterial(pane->mNameTab->getIndex("mat_x_00_v"));
	P2ASSERT(matX);
	matX->getTevBlock()->setTevColor(0, s10Color);

	J2DMaterial* matSlash = pane->getMaterial(pane->mNameTab->getIndex("mat_PICT_002_v"));
	P2ASSERT(matSlash);
	matSlash->getTevBlock()->setTevColor(0, s10Color);

	// color.a = 40;

	// J2DPictureEx* box1 = (J2DPictureEx*)pane->search('PICT_003');
	// box1->mCornerColors.mColor0 = color;
	// box1->mCornerColors.mColor1 = tColorWeak;
	// box1->mCornerColors.mColor2 = tColorWeak;
	// box1->mCornerColors.mColor3 = tColorWeak;

	// J2DPictureEx* box2 = (J2DPictureEx*)pane->search('PICT_004');
	// box2->mCornerColors.mColor0 = color;
	// box2->mCornerColors.mColor1 = color;
	// box2->mCornerColors.mColor2 = color;
	// box2->mCornerColors.mColor3 = color;

	// color.a = 0xff;

	static_cast<J2DPictureEx*>(pane->search('PICT_003'))->setWhite(color);
	static_cast<J2DPictureEx*>(pane->search('PICT_004'))->setWhite(color);
	//static_cast<J2DPictureEx*>(pane->search('PICT_002'))->setWhite(color);
	//static_cast<J2DPictureEx*>(pane->search('w_00'))->setWhite(color);
	//static_cast<J2DPictureEx*>(pane->search('w_01'))->setWhite(color);
	//static_cast<J2DPictureEx*>(pane->search('x_00'))->setWhite(color);

}

} // namespace newScreen


} // namespace og
