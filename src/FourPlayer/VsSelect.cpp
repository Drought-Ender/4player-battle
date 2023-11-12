#include "Morimura/VsSelect.h"
#include "Morimura/Bases.h"
#include "FourPlayer.h"
#include "Game/VsGameSection.h"
#include "PSSystem/PSSystemIF.h"
#include "VsOptions.h"
#include "Controller.h"
#include "PS.h"


int mRealWinCounts[4];
bool gDrawVsMenu = true;

namespace Morimura
{

// const static u64 newHidePanes[2][10] = {
//     {
//         'Nwp_00', 
//         'Nwp_01', 
//         'Nwp_02', 
//         'Nwp_03', 
//         'Nwp_04', 
//         'Nwp_05', 
//         'Nwp_06', 
//         'Nwp_07', 
//         'Nwp_08', 
//         'Nwp_09',
//     },
//     {
//         'Npp_00', 
//         'Npp_01', 
//         'Npp_02', 
//         'Npp_03', 
//         'Npp_04', 
//         'Npp_05', 
//         'Npp_06', 
//         'Npp_07', 
//         'Npp_08', 
//         'Npp_09',
//     },
// };
    
void TVsSelectScene::doCreateObj(JKRArchive* rarc) {
    mObject = new TFourVsSelect;
    registObj(mObject, rarc);
    mConfirmEndWindow = new TConfirmEndWindow("endWindow");
    registObj(mConfirmEndWindow, rarc);
}

char* NaviNameArray[4] = {
    "Olimar",
    "Louie",
    "President",
    "Wife"
};


const f32 baseXOffs[4] = {341.0f, 385.0f, 429.0f, 475.0f};
const f32 baseYOffs[4] = {146.0f, 166.0f, 186.0f, 206.0f}; // increments of 20

const f32 boxXOffs[2] = {381.0f, 515.0f};
const f32 boxYOffs[4] = {146.0f, 166.0f, 186.0f, 206.0f};


void TFourVsSelect::doCreate(JKRArchive* rarc) {

    gOptionMenu = new VsOptionsMenuMgr;
    gOptionMenu->init();

    for (int i = 0; i < GetConfigSize(); i++) {
        gConfig[i] = gOptions[i].getValue();        
    }

    TVsSelect::doCreate(rarc);

    
    mWhitePikiNum = _1F8->mWhiteHandicap;
    mPurplePikiNum = _1F8->mPurpleHandicap;

    for (int i = 0; i < 4; i++) {
        mTeamIDs[i] = Game::getVsTeam(i);
    }

    for (int i = Game::gNaviNum; i < 4; i++) {
        mTeamIDs[i] = i;
    }

    Game::gNaviNum = Game::CalcNaviNum();
    for (int i = 0; i < 4; i++) {
        mNewWinValues[i] = mRealWinCounts[i];
        DebugReport("Win Values %i\n", mNewWinValues[i]);
    }

    J2DPane* pikiWhiteFlower = mMainScreen->mScreenObj->search('Pwp_f_00');
    J2DPane* pikiWhiteRight  = mMainScreen->mScreenObj->search('Pwp_r_00');
    J2DPane* pikiWhiteLeft   = mMainScreen->mScreenObj->search('Pwp_l_00');

    J2DPane* pikiPurpleFlower = mMainScreen->mScreenObj->search('Ppp_f_00');
    J2DPane* pikiPurpleRight  = mMainScreen->mScreenObj->search('Ppp_r_00');
    J2DPane* pikiPurpleLeft   = mMainScreen->mScreenObj->search('Ppp_l_00');


    mWhitePikis = new TVsPiki(pikiWhiteLeft, pikiWhiteRight, pikiWhiteFlower);

    mPurplePikis = new TVsPiki(pikiPurpleLeft, pikiPurpleRight, pikiPurpleFlower);

    if (isTeamIDActive(Game::TEAM_WHITE)) {
        mDispWhitePikiNum  = mWhitePikiNum * 5;
        mWhitePikis->setupPosinfo(mWhitePikiNum);
    }
    else {
        mDispWhitePikiNum = 0;
        mWhitePikis->setupPosinfo(0);
    }

    if (isTeamIDActive(Game::TEAM_PURPLE)) {
        mDispPurplePikiNum  = mPurplePikiNum * 5;
        mPurplePikis->setupPosinfo(mPurplePikiNum);
    }
    else {
        mDispPurplePikiNum = 0;
        mPurplePikis->setupPosinfo(0);
    }
    
    og::Screen::setCallBack_CounterRV(mMainScreen->mScreenObj, 'Pwp_f_r', 'Pwp_f_l', 'Pwp_f_l', &mDispWhitePikiNum, 2, 0, true, mArchive);
    og::Screen::setCallBack_CounterRV(mMainScreen->mScreenObj, 'Ppp_f_r', 'Ppp_f_l', 'Ppp_f_l', &mDispPurplePikiNum, 2, 0, true, mArchive);

    // for (int paneType = 0; paneType < 2; paneType++) {
    //     for (int nameID = 0; nameID < 10; nameID++) {
    //         u64 name = newHidePanes[paneType][nameID];
    //         J2DPane* pane = mMainScreen->mScreenObj->search(name);
    //         if (pane) pane->hide();
    //     }
    // }

    J2DPane* pikiWhite = mMainScreen->mScreenObj->search('Nwp_00');
    if (pikiWhite) pikiWhite->hide();

    J2DPane* pikiPurple = mMainScreen->mScreenObj->search('Npp_00');
    if (pikiPurple) pikiPurple->hide();

    // f32 baseXOffs[2] = {335.0f, 359.0f};
    // f32 baseYOffs[2] = {282.0f, 300.0f};

    // f32 boxXOffs[2] = {335.0f, 360.0f};
    // f32 boxYOffs[2] = {282.0f, 303.0f};


    /* FORMULAS:

    Box    = (x+40,   y)
    Base   = (x,      y)
    Names  = (x+35,   y)
    WinNum = (x+77.5, y-5) // 1 digit
    WinNum = (x+77.5, y-5) // 2 digit
    WinBox = (x+77.5, y)
    */

    // f32 addY = 43.0f;

    const char* iconPaths[4] = {
        "orima003.bti",
        "lui003.bti",
        "president_large.bti",
        "wife_large.bti"
    };

    J2DPictureEx* outlineBox = static_cast<J2DPictureEx*>(mMainScreen->mScreenObj->search('NaviBox'));
    J2DPane* root = mMainScreen->mScreenObj->search('ROOT');

    mNaviNames[0] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('OliName'));
    mNaviNames[1] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('LuiName')); // Pardon my french
    mNaviNames[2] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('PresName'));
    mNaviNames[3] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('WifeName'));


    mNewWinCallbacks[0] = new og::Screen::CallBack_CounterRV(const_cast<char**>(og::Screen::SujiTex32), 2, 4,  mArchive);
    mNewWinCallbacks[0]->init(mMainScreen->mScreenObj, 'Pori2_r', 'Pori2_l', 'Pori2_c', &mNewWinValues[0], true);

    mNewWinCallbacks[0]->setPuyoAnim(true);
    mMainScreen->mScreenObj->addCallBack('Pori2_r', mNewWinCallbacks[0]);


    mNewWinCallbacks[1] = new og::Screen::CallBack_CounterRV(const_cast<char**>(og::Screen::SujiTex32), 2, 4,  mArchive);;
    mNewWinCallbacks[1]->init(mMainScreen->mScreenObj, 'Plui2_r', 'Plui2_l', 'Plui2_c', &mNewWinValues[1], true);

    mNewWinCallbacks[1]->setPuyoAnim(true);
    mMainScreen->mScreenObj->addCallBack('Plui2_r', mNewWinCallbacks[1]);


    mNewWinCallbacks[2] = new og::Screen::CallBack_CounterRV(const_cast<char**>(og::Screen::SujiTex32), 2, 4,  mArchive);;
    mNewWinCallbacks[2]->init(mMainScreen->mScreenObj, 'Ppres_r', 'Ppres_l', 'Ppres_c', &mNewWinValues[2], true);

    mNewWinCallbacks[2]->setPuyoAnim(true);
    mMainScreen->mScreenObj->addCallBack('Ppres_r', mNewWinCallbacks[2]);


    mNewWinCallbacks[3] = new og::Screen::CallBack_CounterRV(const_cast<char**>(og::Screen::SujiTex32), 2, 4,  mArchive);
    mNewWinCallbacks[3]->init(mMainScreen->mScreenObj, 'Pwife_r', 'Pwife_l', 'Pwife_c', &mNewWinValues[3], true);

    mNewWinCallbacks[3]->setPuyoAnim(true);
    mMainScreen->mScreenObj->addCallBack('Pwife_r', mNewWinCallbacks[3]);



    // mWinCounts[0]->hide();
    // mWinCounts[1]->hide();

    J2DPane* redPane = mMainScreen->mScreenObj->search('PICT_RED');
    J2DPane* bluePane = mMainScreen->mScreenObj->search('PICT_BLU');

    if (redPane)  redPane->move(-200.0f, 0.0f);
    if (bluePane) bluePane->move(-200.0f, 0.0f);

    
    for (int i = 0; i < 4; i++) {        
        f32 baseX = baseXOffs[mTeamIDs[i]];
        f32 baseY = baseYOffs[i];

        mAnimActive[i] = false;

        mAnimProgress[i] = mTeamIDs[i];

        mNaviBasePos[i] = Vector2f(baseX, baseY);

        mNaviImages[i] = og::Screen::CopyPictureToPane(static_cast<J2DPictureEx*>(mOrimaPikiIcon),
        root, baseX, baseY, 'Ph_or');
        
        mNaviImages[i]->updateScale(0.5f);
        mNaviImages[i]->changeTexture(sCharacters[i].mImage, 0);

        mNaviNames[i]->mOffset = JGeometry::TVec2f(baseX + 35.0f, baseY);
        mNaviNames[i]->updateScale(0.6f, 0.7f);
        if (i == 2) {
            mNaviNames[i]->updateScale(0.4f, 0.7f);
        }

        mNewWinCallbacks[i]->mPane->mOffset = JGeometry::TVec2f(baseX + 77.5f, baseY - 5.0f);
        mNewWinCallbacks[i]->update();

        

        const JUtility::TColor& color = vsTeamColors[mTeamIDs[i]];
        mLerpColors[i] = color;
        f32 boxX = boxXOffs[mTeamIDs[i]];
        f32 boxY = boxYOffs[i];

        mNaviBoxes[i] = og::Screen::CopyPictureToPane(outlineBox, root, boxX, boxY, 'Ph_or');
        mNaviBoxes[i]->updateScale(3.0f, 0.6f);
        mNaviBoxes[i]->setWhite(color);
        mWinBoxes[i] = og::Screen::CopyPictureToPane(outlineBox, root, boxX + 37.5f, boxY, 'Ph_or');
        mWinBoxes[i]->updateScale(0.6f, 0.4f);
        
    }

    for (int i = Game::gNaviNum; i < 4; i++) {
        mNaviImages[i]->hide();
        mNaviBoxes[i]->hide();
        mWinBoxes[i]->hide();
        mNewWinCallbacks[i]->hide();
        mNaviNames[i]->hide();
    }

    outlineBox->hide();
    mOrimaPikiIcon->hide();
    mLoozyPikiIcon->hide();


    // _154->hide();
    // _158->hide();
    // _15C->hide();
    mPbor0->hide();
    mPbor1->hide();
    // _16C->hide();
    // _170->hide();
    mPblo0->hide();
    mPblo1->hide();

    
}

bool TFourVsSelect::doUpdateFadein() {
    if (!gDrawVsMenu) {
        gDrawVsMenu = gOptionMenu->update();
        return false;
    }
    return TVsSelect::doUpdateFadein();
}

void TFourVsSelect::doUpdateFadeoutFinish() {
    TVsSelect::doUpdateFadeoutFinish();
    PSStop2DStream();
    _1F8->mWhiteHandicap  = mWhitePikiNum;
    _1F8->mPurpleHandicap = mPurplePikiNum;
    DebugReport("Handicaps:\n Red %i\n Blue %i\n White %i\n Purple %i\n", _1F8->mOlimarHandicap, _1F8->mLouieHandicap, _1F8->mWhiteHandicap, _1F8->mPurpleHandicap);
}

bool TFourVsSelect::doUpdate() {
    if (!gDrawVsMenu) {
        gDrawVsMenu = gOptionMenu->update();            
        
        if (gDrawVsMenu) {
            PSStop2DStream();
            PSStart2DStream(0xc001100f);
            for (int i = 0; i < 4; i++) {
                mNaviImages[i]->changeTexture(sCharacters[i].mImage, 0);
            }
            
        }

        return false;
    }

    Game::gNaviNum = Game::CalcNaviNum();
    if (Game::gNaviNum == 3) {
		Game::gFancyCamera = true;
	}
	else {
		Game::gFancyCamera = false;
	}
    Controller* controllerArray[4] = { mController, mController2, Game::gControllerP3, Game::gControllerP4};

    int* pikiNumArray[4] = { &mRedPikiNum, &mBluePikiNum, &mWhitePikiNum, &mPurplePikiNum };

    TConfirmEndWindow* confirmEndWindow = static_cast<TVsSelectScene*>(getOwner())->mConfirmEndWindow;

    if (_D4->mState == 0 && _240 == 0 && !confirmEndWindow->mIsActive) {
        if (mController->isButtonDown(JUTGamePad::PRESS_START)) {
            PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_OPEN, 0);
            PSStop2DStream();
            PSStart2DStream(0xc0011024);
            gDrawVsMenu = false;
            return false;
        }
        for (int i = 0; i < 4; i++) {
            for (int c = 0; c < 4; c++) {
                if (mTeamIDs[i] == c) {
                    if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_R)) {
                        (*pikiNumArray[c])++;
                        if (*pikiNumArray[c] > 10) {
                            *pikiNumArray[c] = 10;
                        }
                        else {
                            PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_INCREMENT, 0);
                        }
                    }
                    else if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_L)) {
                        (*pikiNumArray[c])--;
                        if (*pikiNumArray[c] < 1) {
                            *pikiNumArray[c] = 1;
                        }
                        else {
                            PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_DECREMENT, 0);
                        }
                    }
                }
            }
        }
    }


    bool check = TVsSelect::doUpdate();
    
    if (_D4->mState == 0 && _240 == 0 && !confirmEndWindow->mIsActive) {
        for (int i = 0; i < 4; i++) {
            P2ASSERT(controllerArray[i]);
            if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_RIGHT) && !mAnimActive[i]) {
                if (mTeamIDs[i] == Game::TEAM_PURPLE) {
                    PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
                    mErrAnimActive[i] = true;
                    mErrAnimProgress[i] = 0.0f;
                    mErrAnimSpeed[i] = 5.0f;
                }
                else {
                    mTeamIDs[i]++;
                    mAnimActive[i] = true;
                    mAnimProgress[i] = 0.0f;
                    mAnimSpeed[i] = 9.0f;
                    mAnimDir[i] = 1;
                    PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_THROW, 0);
                }
            }
            else if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_LEFT) && !mAnimActive[i]) {
                if (mTeamIDs[i] == Game::TEAM_RED) {
                    mErrAnimActive[i] = true;
                    mErrAnimProgress[i] = 1.0f;
                    mErrAnimSpeed[i] = -5.0f;
                    PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
                }
                else {
                    mTeamIDs[i]--;
                    mAnimActive[i] = true;
                    mAnimProgress[i] = 0.0f;
                    mAnimDir[i] = -1;
                    mAnimSpeed[i] = 9.0f;
                    PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_THROW, 0);
                }
            }
        }
    }

        
    /* FORMULAS:

    Box    = (x+40,   y)
    Base   = (x,      y)
    Names  = (x+35,   y)
    WinNum = (x+77.5, y-5) // 1 digit
    WinNum = (x+77.5, y-5) // 2 digit
    WinBox = (x+77.5, y)
    */


    for (int i = 0; i < 4; i++) {
        if (mAnimActive[i]) {
            mAnimProgress[i] += sys->mDeltaTime * mAnimSpeed[i];
            if (mAnimProgress[i] < 0.0f) {
                mAnimActive[i] = false;
                mAnimProgress[i] = 0.0f;

                mErrAnimActive[i] = false;
                mErrAnimProgress[i] = 0.5f;
                mErrAnimSpeed[i] = 5.0f;
                
                PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_GROUND, 0);
            }
            else if (mAnimProgress[i] > 1.0f) {
                mAnimActive[i] = false;
                mAnimProgress[i] = 1.0f;

                mErrAnimActive[i] = false;
                mErrAnimProgress[i] = 0.5f;
                mErrAnimSpeed[i] = -5.0f;
                
                PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_GROUND, 0);
            }
            f32 smoothedProgress = (1.0f - oddSqrt(pikmin2_cosf(mAnimProgress[i] * PI))) * 0.5f;
            mNaviBasePos[i].x = (baseXOffs[mTeamIDs[i]] - baseXOffs[mTeamIDs[i] - mAnimDir[i]]) * smoothedProgress + baseXOffs[mTeamIDs[i] - mAnimDir[i]];
            mLerpColors[i].r = vsTeamColors[mTeamIDs[i] - mAnimDir[i]].r * (1.0f - smoothedProgress) + vsTeamColors[mTeamIDs[i]].r * smoothedProgress;
            mLerpColors[i].g = vsTeamColors[mTeamIDs[i] - mAnimDir[i]].g * (1.0f - smoothedProgress) + vsTeamColors[mTeamIDs[i]].g * smoothedProgress;
            mLerpColors[i].b = vsTeamColors[mTeamIDs[i] - mAnimDir[i]].b * (1.0f - smoothedProgress) + vsTeamColors[mTeamIDs[i]].b * smoothedProgress;
        }
        else if (mErrAnimActive[i]) {
            mErrAnimProgress[i] += sys->mDeltaTime * mErrAnimSpeed[i];

            if (mErrAnimProgress[i] > 1.0f) {
                mNaviBasePos[i].x = baseXOffs[mTeamIDs[i]];
                mErrAnimActive[i] = false;
            }
            if (mErrAnimProgress[i] < 0.0f) {
                mNaviBasePos[i].x = baseXOffs[mTeamIDs[i]];
                mErrAnimActive[i] = false;
            }

            f32 smoothedProgess = pikmin2_sinf(2 * mErrAnimProgress[i] * PI);
            mNaviBasePos[i].x = baseXOffs[mTeamIDs[i]] + smoothedProgess * 5.0f;
        }

        

        mNaviImages[i]->setOffset(mNaviBasePos[i].x - 20.0f, mNaviBasePos[i].y - 20.0f);

        mNaviNames[i]->setOffset(mNaviBasePos[i].x + 35.0f, mNaviBasePos[i].y);

        mNewWinCallbacks[i]->mPane->mOffset = JGeometry::TVec2f(mNaviBasePos[i].x + 77.5f, mNaviBasePos[i].y - 5.0f);
        if (*mNewWinCallbacks[i]->mCountPtr < 10) {
            mNewWinCallbacks[i]->mPane->mOffset.x -= 6.0f;
            mNewWinCallbacks[i]->mCounters[0]->mSize.x = 1.2f;
        }
        else {
            mNewWinCallbacks[i]->mCounters[0]->mSize.x = 0.5f;
        }
        mNewWinCallbacks[i]->update();

        mNaviBoxes[i]->setOffset(mNaviBasePos[i].x + 20.0f, mNaviBasePos[i].y - 20.0f);
        mNaviBoxes[i]->setWhite(mLerpColors[i]);
        
        mWinBoxes[i]->setOffset(mNaviBasePos[i].x + 57.5f, mNaviBasePos[i].y - 20.0f);
        mWinBoxes[i]->calcMtx();
    
    }

    for (int i = 0; i < Game::gNaviNum; i++) {
        Game::SetVsTeam(i, (Game::TeamID)mTeamIDs[i]);
    }

    for (int i = Game::gNaviNum; i < 4; i++) {
        Game::SetVsTeam(i, Game::TEAM_NULL);
        sNameOverride[i] = false;
    }

    for (int i = 0; i < Game::gNaviNum; i++) {
        mNaviImages[i]->show();
        mNaviBoxes[i]->show();
        mWinBoxes[i]->show();
        mNewWinCallbacks[i]->show();
        mNaviNames[i]->show();
    }


    for (int i = Game::gNaviNum; i < 4; i++) {
        mNaviImages[i]->hide();
        mNaviBoxes[i]->hide();
        mWinBoxes[i]->hide();
        mNewWinCallbacks[i]->hide();
        mNaviNames[i]->hide();
    }

    TVsPiki* vsPikis[4] = { mVsPiki[0], mVsPiki[1], mWhitePikis, mPurplePikis };
    u32* dispPikiNumArr[4] = { &mDispRedPikiNum, &mDispBluePikiNum, &mDispWhitePikiNum, &mDispPurplePikiNum };

    for (int i = 0; i < 4; i++) {
    
        if (!isTeamIDActive(i)) {
            vsPikis[i]->update(0);
            *dispPikiNumArr[i] = 0;
        }
        else {
            vsPikis[i]->update(*pikiNumArray[i]);
            *dispPikiNumArr[i] = *pikiNumArray[i] * 5;
        }
    }


    return check;
}

bool visable[4];

// TVsPikiDraw__Q28Morimura13TFourVsSelectFR8Graphics
void TFourVsSelect::TVsPikiDraw(Graphics& gfx) {
    mWhitePikis->draw();
    mPurplePikis->draw();

    for (int i = 0; i < 4; i++) {

        if (visable[i]) {
            mNaviNames[i]->show();
            
            J2DTextBoxEx* text = mNaviNames[i];
            JUTFont* font = nullptr;
            if (text->mMaterial && text->mMaterial->getTevBlock()) {
                font = text->mMaterial->getTevBlock()->getFont();
            }

            if (!font) {
                font = getPikminFont();
            }

			text->makeMatrix(mNaviNames[i]->getGlbVtx(2).x - 15.0f, mNaviNames[i]->getGlbVtx(2).y + 0.5f, 0.0f, 0.0f);

            
            J2DPrint print(font, JUtility::TColor(0xffffffff), JUtility::TColor(0x807700ff));
            size_t size = strlen(sCharacters[i].mDispName);
            float sizeX = 15.0f;
            if (size > 6) {
                sizeX = 85.0f / size;
            }
            print.setFontSize(sizeX, 15.0f);

            print.print(mNaviNames[i]->getGlbVtx(2).x - 15.0f, mNaviNames[i]->getGlbVtx(2).y + 0.5f, 255, "%s", sCharacters[i].mDispName);
			
        }
    }
}

void TFourVsSelect::doDraw(Graphics& gfx) {
    if (!gDrawVsMenu) {
        gOptionMenu->draw(gfx);
        return;
    }

    

    for (int i = 0; i < 4; i++) {
        visable[i] = false;
        if (mNaviNames[i]->isVisible()) {
            visable[i] = true;
            mNaviNames[i]->hide();
        }
    }
    
    

    TVsSelect::doDraw(gfx);
    
    // J2DPrint printer(getPikminFont(), 0.0f);

    // printer.mGlyphHeight /= 4;
    // printer.mGlyphWidth /= 4;


    // printer.print(0.0f, 0.0f, "%p Piki Anaylis:\n", mVsPiki[1]);
    // printer.print(0.0f, 5.0f, "Image basePos %i, %i, %i\n", mVsPiki[1]->mPikminFlower->mBasePosition, mVsPiki[1]->mPikminLeft->mBasePosition, mVsPiki[1]->mPikminRight->mBasePosition);
    // for (int i = 0; i < 10; i++) {
    //     printer.print(0.0f, 20.0f * i + 10.0f, "posInfo %i:\n", i);
    //     printer.print(0.0f, 20.0f * i + 15.0f, "Position %f %f\n", mVsPiki[1]->mInfo[i].mPosition.x, mVsPiki[1]->mInfo[i].mPosition.y);
    //     printer.print(0.0f, 20.0f * i + 20.0f, "State Timer %f\n", mVsPiki[1]->mInfo[i].mStateTimer);
    //     printer.print(0.0f, 20.0f * i + 25.0f, "State %i\n", mVsPiki[1]->mInfo[i].mState);
    // }
    // printer.print(0.0f, 210.0f, "Bounds %f %f | %f %f\n", mVsPiki[1]->mBounds[0].x, mVsPiki[1]->mBounds[0].y, mVsPiki[1]->mBounds[1].x, mVsPiki[1]->mBounds[1].y);




    // printer.print(200.0f, 0.0f, "%p Piki Anaylis:\n", mWhitePikis);
    // printer.print(200.0f, 5.0f, "Image basePos %i, %i, %i\n", mWhitePikis->mPikminFlower->mBasePosition, mWhitePikis->mPikminLeft->mBasePosition, mWhitePikis->mPikminRight->mBasePosition);
    // for (int i = 0; i < 10; i++) {
    //     printer.print(200.0f, 20.0f * i + 10.0f, "posInfo %i:\n", i);
    //     printer.print(200.0f, 20.0f * i + 15.0f, "Position %f %f\n", mWhitePikis->mInfo[i].mPosition.x, mWhitePikis->mInfo[i].mPosition.y);
    //     printer.print(200.0f, 20.0f * i + 20.0f, "State Timer %f\n", mWhitePikis->mInfo[i].mStateTimer);
    //     printer.print(200.0f, 20.0f * i + 25.0f, "State %i\n", mWhitePikis->mInfo[i].mState);
    // }
    // printer.print(200.0f, 210.0f, "Bounds %f %f | %f %f\n", mWhitePikis->mBounds[0].x, mWhitePikis->mBounds[0].y, mWhitePikis->mBounds[1].x, mWhitePikis->mBounds[1].y);

    

    // J2DPrint printWhite(getPikminFont(), vsTeamColors[2], vsTeamColors[2]);
    // J2DPrint printPurple(getPikminFont(), vsTeamColors[3], vsTeamColors[3]);
    
    
    // printWhite.print(310.0f, 280.0f, "%i", mWhitePikiNum * 5);
    // printPurple.print(310.0f, 330.0f, "%i", mPurplePikiNum * 5);   
    
    
}

namespace 
{
    const char* VsNames[] = {
        "otegaru",
        "ujyaujya",
        "hirobiro",
        "karakuchi",
        "semai",
        "hiyahiya",
        "nobinobi",
        "kakukaku",
        "meiro",
        "tile",
        "be_dama_r"
    };
} // namespace 


void TVsSelect::setSelectTextures() {
    DebugReport("loading textures...\n");
    DebugReport("Stage Count: %i\n", mStageCount);
    DebugReport("Icon Names: %i\n", ARRAY_SIZE(VsNames));
    for (int i = 0; i < mStageCount; i++) {
        mLevelTextures[i] = nullptr;
        if (i < ARRAY_SIZE(VsNames)) {
            
            char buffer[64];
            sprintf(buffer, "timg/%s.bti", VsNames[i]);
            DebugReport("loading %s...\n", buffer);
            void* obj = _B4->getResource(buffer);
            mLevelTextures[i] = (ResTIMG*)obj;
            
        }
        DebugReport("%p obj\n", mLevelTextures[i]);
        if (!mLevelTextures[i]) {
            DebugReport("replacing Image\n");
            void* obj2 = mArchive->getResource("timg/loozy_icon.bti");
            mLevelTextures[i] = (ResTIMG*)obj2;
            P2ASSERT(mLevelTextures[i]);
        }
    } 
    DebugReport("Func has no issues\n");
}

void TVsSelect::makeMsgTag() {
    u64 spots[] = { '4771_00', '4712_00' };
    _1FC = new TOffsetMsgSet(spots, '4770_00', ARRAY_SIZE(spots));
}

} // namespace name
