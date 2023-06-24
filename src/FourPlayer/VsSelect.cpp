#include "Morimura/VsSelect.h"
#include "Morimura/Bases.h"
#include "FourPlayer.h"
#include "Game/VsGameSection.h"
#include "PSSystem/PSSystemIF.h"
#include "Controller.h"

int mRealWinCounts[4];
bool gDrawVsMenu = true;

namespace Morimura
{
    
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


const f32 baseXOffs[2] = {341.0f, 475.0f};
const f32 baseYOffs[4] = {146.0f, 166.0f, 186.0f, 206.0f}; // increments of 20

const f32 boxXOffs[2] = {381.0f, 515.0f};
const f32 boxYOffs[4] = {146.0f, 166.0f, 186.0f, 206.0f};

const JUtility::TColor vsTeamColors[2] = { 0xff5050ff, 0x5050ffff };

void TFourVsSelect::doCreate(JKRArchive* rarc) {

    gOptionMenu = new VsOptionsMenu;
    gOptionMenu->init();

    TVsSelect::doCreate(rarc);

    for (int i = 0; i < 4; i++) {
        mTeamIDs[i] = Game::getVsTeam(i);
    }

    Game::gNaviNum = Game::CalcNaviNum();
    for (int i = 0; i < 4; i++) {
        mNewWinValues[i] = mRealWinCounts[i];
        OSReport("Win Values %i\n", mNewWinValues[i]);
    }

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

    
    for (int i = 0; i < 4; i++) {        
        f32 baseX = baseXOffs[mTeamIDs[i]];
        f32 baseY = baseYOffs[i];

        mAnimActive[i] = false;

        mAnimProgress[i] = mTeamIDs[i];

        mNaviBasePos[i] = Vector2f(baseX, baseY);

        mNaviImages[i] = og::Screen::CopyPictureToPane(static_cast<J2DPictureEx*>(mOrimaPikiIcon),
        root, baseX, baseY, 'Ph_or');
        
        mNaviImages[i]->updateScale(0.5f);
        mNaviImages[i]->changeTexture(iconPaths[i], 0);

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

bool TFourVsSelect::doUpdate() {
    if (!gDrawVsMenu) {
        gDrawVsMenu = gOptionMenu->update();
        return false;
    }
    Game::gNaviNum = Game::CalcNaviNum();
    Controller* controllerArray[4] = { mController, mController2, Game::gControllerP3, Game::gControllerP4};

    int* pikiNumArray = &mRedPikiNum;

    if (_D4->mState == 0) {
        if (mController->isButtonDown(JUTGamePad::PRESS_START) && !mCanCancel) {
            PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_OPEN, 0);
            gDrawVsMenu = false;
            return false;
        }
        for (int i = 0; i < 4; i++) {
            for (int c = 0; c < 2; c++) {
                if (mTeamIDs[i] == c) {
                    if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_R)) {
                        pikiNumArray[c]++;
                        if (pikiNumArray[c] > 10) {
                            pikiNumArray[c] = 10;
                        }
                        else {
                            PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_INCREMENT, 0);
                        }
                    }
                    else if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_L)) {
                        pikiNumArray[c]--;
                        if (pikiNumArray[c] < 1) {
                            pikiNumArray[c] = 1;
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
    
    if (_D4->mState == 0)
    for (int i = 0; i < 4; i++) {
        P2ASSERT(controllerArray[i]);
        if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_RIGHT)) {
            if (mTeamIDs[i] == 1) {
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
                mErrAnimActive[i] = true;
                mErrAnimProgress[i] = 0.0f;
                mErrAnimSpeed[i] = 5.0f;
            }
            else {
                mTeamIDs[i]++;
                mAnimActive[i] = true;
                mAnimSpeed[i] = 3.0f;
                PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_THROW, 0);
            }
        }
        else if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_LEFT)) {
            if (mTeamIDs[i] == 0) {
                mErrAnimActive[i] = true;
                mErrAnimProgress[i] = 1.0f;
                mErrAnimSpeed[i] = -5.0f;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
            }
            else {
                mTeamIDs[i]--;
                mAnimActive[i] = true;
                mAnimSpeed[i] = -3.0f;
                PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_THROW, 0);
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
            f32 smoothedProgress = (1.0f - domainSqrt(pikmin2_cosf(mAnimProgress[i] * PI))) * 0.5f;
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
            mNaviBasePos[i].x = (baseXOffs[1] - baseXOffs[0]) * smoothedProgress + baseXOffs[0];
            mLerpColors[i].r = vsTeamColors[0].r * (1.0f - smoothedProgress) + vsTeamColors[1].r * smoothedProgress;
            mLerpColors[i].g = vsTeamColors[0].g * (1.0f - smoothedProgress) + vsTeamColors[1].g * smoothedProgress;
            mLerpColors[i].b = vsTeamColors[0].b * (1.0f - smoothedProgress) + vsTeamColors[1].b * smoothedProgress;
        }
        else if (mErrAnimActive[i]) {
            mErrAnimProgress[i] += sys->mDeltaTime * mErrAnimSpeed[i];
            f32 smoothedProgess = pikmin2_sinf(2 * mErrAnimProgress[i] * PI);
            mNaviBasePos[i].x = baseXOffs[mTeamIDs[i]] + smoothedProgess * 5.0f;
            if (mErrAnimProgress[i] > 1.0f) {
                mNaviBasePos[i].x = baseXOffs[mTeamIDs[i]];
                mErrAnimActive[i] = false;
            }
            if (mErrAnimProgress[i] < 0.0f) {
                mNaviBasePos[i].x = baseXOffs[mTeamIDs[i]];
                mErrAnimActive[i] = false;
            }
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

    for (int i = 0; i < 4; i++) {
        Game::SetVsTeam(i, (Game::TeamID)mTeamIDs[i]);
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
    


    return check;
}

void TFourVsSelect::doDraw(Graphics& gfx) {
    if (!gDrawVsMenu) {
        gOptionMenu->draw(gfx);
        return;
    }
    TVsSelect::doDraw(gfx);
}

} // namespace name
