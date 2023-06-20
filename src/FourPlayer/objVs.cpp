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
	mPaneObake2P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP2YOffs, 'obake2P');
	mPaneObake1P->setAlpha(mAlphaObakeP1 * 255.0f);
	mPaneObake2P->setAlpha(mAlphaObakeP2 * 255.0f);
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
    f32 scale = (pikmin2_cosf(mScale * PI) + 1.0f) * 0.5f;
    if (mDisp->mTwoPlayer) {
        mScreenP3->mScreen->hide();
        mScreenP4->mScreen->hide();
        mScreenP1->mScreen->setXY(0.0f, scale * -300.0f);
        mScreenP2->mScreen->setXY(0.0f, scale * 300.0f + 205.0f);
    }
    else {
        if (mDoneState == 1) {
            if (mFinishTimer <= 0.0f)
                mDoneState = 2;
            else
                mFinishTimer -= sys->mDeltaTime;
        }
        mScreenP3->update(mDisp->mP3Data);
        mScreenP4->update(mDisp->mP4Data);

        mDisp->mDoneState = mDoneState;

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
    //OSReport("FourObjVs::setOnOffBdama4P(bool %i)\n", doEfx);
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

						efx2d::ArgScaleColorColor arg(&pos, 1.0f, 0x2020ffff, 0x5787ffff);
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
						og::Screen::calcGlbCenter(mPane_windama3P[i], &pos);

						efx2d::ArgScaleColorColor arg(&pos, 1.0f, 0x2020ffff, 0x5787ffff);
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

						efx2d::ArgScaleColorColor arg(&pos, 1.0f, 0x2020ffff, 0x5787ffff);
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

						efx2d::ArgScaleColorColor arg(&pos, 1.0f, 0xff0000ff, 0xff8787ff);
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

} // namespace newScreen


} // namespace og
