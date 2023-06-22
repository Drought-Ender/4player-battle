#include "Morimura/VsSelect.h"
#include "Morimura/Bases.h"
#include "FourPlayer.h"
#include "Game/VsGameSection.h"
#include "Controller.h"

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


const f32 baseXOffs[2] = {341.0f, 466.0f};
const f32 baseYOffs[4] = {146.0f, 166.0f, 186.0f, 206.0f}; // increments of 20

const f32 boxXOffs[2] = {381.0f, 506.0f};
const f32 boxYOffs[4] = {146.0f, 166.0f, 186.0f, 206.0f};

const JUtility::TColor vsTeamColors[2] = { 0xff5050ff, 0x5050ffff };

void TFourVsSelect::doCreate(JKRArchive* rarc) {
    TVsSelect::doCreate(rarc);

    for (int i = 0; i < 4; i++) {
        mTeamIDs[i] = Game::getVsTeam(i);
    }

    Game::gNaviNum = Game::CalcNaviNum();
    mNewWinValues[0] = Game::VsGameSection::mP1WinCount;
    mNewWinValues[1] = Game::VsGameSection::mP2WinCount;
    mNewWinValues[2] = Game::VsGameSection::mP3WinCount;
    mNewWinValues[3] = Game::VsGameSection::mP4WinCount;

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
        "orima_icon.bti",
        "loozy_icon.bti",
        "president_large.bti",
        "wife_large.bti"
    };

    J2DPictureEx* outlineBox = static_cast<J2DPictureEx*>(mMainScreen->mScreenObj->search('NaviBox'));
    J2DPane* root = mMainScreen->mScreenObj->search('ROOT');

    mNaviNames[0] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('OliName'));
    mNaviNames[1] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('LuiName')); // Pardon my french
    mNaviNames[2] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('PresName'));
    mNaviNames[3] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('WifeName'));

    mNewWinCounts[0] = new TVsSelectCBWinNum(mArchive);
    mNewWinCounts[0]->init(mMainScreen->mScreenObj, 'Pori2_r', 'Pori2_l', 'Pori2_c', &mNewWinValues[0], true);

    mNewWinCounts[0]->setPuyoAnim(true);
    mMainScreen->mScreenObj->addCallBack('Pori2_r', mNewWinCounts[0]);


    mNewWinCounts[1] = new TVsSelectCBWinNum(mArchive);
    mNewWinCounts[1]->init(mMainScreen->mScreenObj, 'Plui2_r', 'Plui2_l', 'Plui2_c', &mNewWinValues[1], true);

    mNewWinCounts[1]->setPuyoAnim(true);
    mMainScreen->mScreenObj->addCallBack('Plui2_r', mNewWinCounts[1]);


    mNewWinCounts[2] = new TVsSelectCBWinNum(mArchive);
    mNewWinCounts[2]->init(mMainScreen->mScreenObj, 'Ppres_r', 'Ppres_l', 'Ppres_c', &mNewWinValues[2], true);

    mNewWinCounts[2]->setPuyoAnim(true);
    mMainScreen->mScreenObj->addCallBack('Ppres_r', mNewWinCounts[2]);


    mNewWinCounts[3] = new TVsSelectCBWinNum(mArchive);
    mNewWinCounts[3]->init(mMainScreen->mScreenObj, 'Pwife_r', 'Pwife_l', 'Pwife_c', &mNewWinValues[3], true);

    mNewWinCounts[3]->setPuyoAnim(true);
    mMainScreen->mScreenObj->addCallBack('Pwife_r', mNewWinCounts[3]);



    mWinCounts[0]->hide();
    mWinCounts[1]->hide();

    
    for (int i = 0; i < 4; i++) {        
        f32 baseX = baseXOffs[mTeamIDs[i]];
        f32 baseY = baseYOffs[i];

        mNaviBasePos[i] = Vector2f(baseX, baseY);

        mNaviImages[i] = og::Screen::CopyPictureToPane(static_cast<J2DPictureEx*>(mOrimaPikiIcon),
        root, baseX, baseY, 'Ph_or');
        
        mNaviImages[i]->updateScale(0.5f);
        mNaviImages[i]->changeTexture(iconPaths[i], 0);

        mNaviNames[i]->mOffset = JGeometry::TVec2f(baseX + 35.0f, baseY);
        mNaviNames[i]->updateScale(0.6f, 0.7f);

        mNewWinCounts[i]->mPane->mOffset = JGeometry::TVec2f(baseX + 77.5f, baseY - 5.0f);
        mNewWinCounts[i]->_A8->mOffset = JGeometry::TVec2f(baseX + 74.0f, baseY - 5.0f);
        mNewWinCounts[i]->update();

        

        const JUtility::TColor& color = vsTeamColors[mTeamIDs[i]];
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
        mNewWinCounts[i]->hide();
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

bool TFourVsSelect::doUpdate() {
    bool check = TVsSelect::doUpdate();
    Controller* controllerArray[4] = { mController, mController2, Game::gControllerP3, Game::gControllerP4};

    for (int i = 0; i < 4; i++) {
        P2ASSERT(controllerArray[i]);
        if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_RIGHT) && mTeamIDs[i] != 1) {
            mTeamIDs[i]++;
        }
        else if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_LEFT) && mTeamIDs[i] != 0) {
            mTeamIDs[i]--;
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
        f32 baseX = baseXOffs[mTeamIDs[i]];
        f32 baseY = baseYOffs[i];

        mNaviBasePos[i] = Vector2f(baseX, baseY);

        mNaviImages[i]->setOffset(mNaviBasePos[i].x - 20.0f, mNaviBasePos[i].y - 20.0f);

        mNaviNames[i]->setOffset(mNaviBasePos[i].x + 35.0f, mNaviBasePos[i].y);

        mNewWinCounts[i]->mPane->mOffset = JGeometry::TVec2f(mNaviBasePos[i].x + 77.5f, mNaviBasePos[i].y - 5.0f);
        mNewWinCounts[i]->_A8->mOffset = JGeometry::TVec2f(mNaviBasePos[i].x + 74.0f, mNaviBasePos[i].y - 5.0f);
        mNewWinCounts[i]->update();

        

        const JUtility::TColor& color = vsTeamColors[mTeamIDs[i]];
        f32 boxX = boxXOffs[mTeamIDs[i]];
        f32 boxY = boxYOffs[i];

        mNaviBoxes[i]->setOffset(mNaviBasePos[i].x + 20.0f, mNaviBasePos[i].y - 20.0f);
        mNaviBoxes[i]->setWhite(color);
        
        mWinBoxes[i]->setOffset(mNaviBasePos[i].x + 57.5f, mNaviBasePos[i].y - 20.0f);
        mWinBoxes[i]->calcMtx();
    
    }

    for (int i = 0; i < 4; i++) {
        Game::SetVsTeam(i, (Game::TeamID)mTeamIDs[i]);
    }
    


    return check;
}

} // namespace name
