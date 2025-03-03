#include "Morimura/VsSelect.h"
#include "Morimura/Bases.h"
#include "FourPlayer.h"
#include "Game/VsGameSection.h"
#include "PSSystem/PSSystemIF.h"
#include "VsOptions.h"
#include "Controller.h"
#include "PS.h"

#define NAVI_BOX_OFFS_X (-20.0f)
#define NAVI_BOX_OFFS_Y (-12.0f)

#define WIN_BOX_OFFS_X (65.0f)
#define WIN_BOX_OFFS_Y (-7.5f)

int mRealWinCounts[4];
bool gDrawVsMenu = true;

namespace Morimura {

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

void TVsSelectScene::doCreateObj(JKRArchive* rarc)
{
	mObject = new TFourVsSelect;
	registObj(mObject, rarc);
	mConfirmEndWindow = new TConfirmEndWindow("endWindow");
	registObj(mConfirmEndWindow, rarc);
}

char* NaviNameArray[4] = { "Olimar", "Louie", "President", "Wife" };

const f32 baseXOffs[4] = { 341.0f, 385.0f, 429.0f, 475.0f };
const f32 baseYOffs[4] = { 146.0f, 166.0f, 186.0f, 206.0f }; // increments of 20

const f32 boxXOffs[2] = { 381.0f, 515.0f };
const f32 boxYOffs[4] = { 146.0f, 166.0f, 186.0f, 206.0f };

// demoStart__Q28Morimura13TFourVsSelectFv
void TFourVsSelect::demoStart()
{
	// OSReport("demoStart__Q28Morimura13TFourVsSelectFv\n");
	if (!canEnterStage()) {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
		return;
	}
	PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE, 0);
	// OSReport("TVsSelect::demoStart()\n");
	// gDrawVsMenu = false;
    // _229 = 1;
    // _240 = 1;
	TVsSelect::demoStart();
}

bool TFourVsSelect::canEnterStage()
{
	// OSReport("TFourVsSelect::canEnterStage()\n");

	Game::VsGame::StageData* data = GetVsGameSection()->mVsStageList->getStageData(mIndexPaneList[mCurrentSelect]->getIndex());

	char caveInfo[256];
	char editfile[256];

	char caveInfo2[256];
	char editfile2[256];

	char caveInfoFinal[256];
	char editfileFinal[256];

	const char* caveinfoBase = "/user/Mukki/mapunits/caveinfo";
	const char* editinfoBase = "/user/Abe/vs";

	strcpy(caveInfo, caveinfoBase);
	strcpy(editfile, editinfoBase);

	// bad practice but IDC
	if (Game::getTeamCount() > 2) {
		sprintf(caveInfo2, "%s/four", caveInfo);
		sprintf(editfile2, "%s/four", editfile);
	} else {
		strcpy(caveInfo2, caveInfo);
		strcpy(editfile2, editfile);
	}

	if (gGameModeID == MAINGAME_BINGO) {
		sprintf(caveInfo, "%s/bingo", caveInfo2);
		sprintf(editfile, "%s/bingo", editfile2);
	} else {
		strcpy(caveInfo, caveInfo2);
		strcpy(editfile, editfile2);
	}

	sprintf(caveInfoFinal, "%s/%s", caveInfo, data->mCaveInfoFilename);
	sprintf(editfileFinal, "%s/%s", editfile, data->mStageLayoutFilePath);

	s32 caveinfoEntrynum = DVDConvertPathToEntrynum(caveInfoFinal);
	s32 editinfoEntrynum = DVDConvertPathToEntrynum(editfileFinal);

	if (caveinfoEntrynum == -1) {
		OSReport("Entry failed, %s missing!\n", caveInfoFinal);
		return false;
	}

	if (editinfoEntrynum == -1) {
		OSReport("Entry failed, %s missing!\n", editfileFinal);
		return false;
	}

	if (gGameModeID == MAINGAME_BINGO) {
		int lastChar = strlen(data->mStageLayoutFilePath);

		char properCaveName[32];

		strncpy(properCaveName, data->mStageLayoutFilePath, lastChar - 4);
		properCaveName[lastChar - 4] = nullptr;

		char filepath[128];

		if (Game::getTeamCount() > 2) {
			sprintf(filepath, "/user/drought/bingocard/bingo/four/%s/0.txt", properCaveName);
		} else {
			sprintf(filepath, "/user/drought/bingocard/bingo/%s/0.txt", properCaveName);
		}

		s32 bingoPathEntrynum = DVDConvertPathToEntrynum(filepath);

		if (bingoPathEntrynum == -1) {
			OSReport("Entry failed, %s missing!\n", filepath);
			return false;
		}
	}

	return true;
}

void TFourVsSelect::doCreate(JKRArchive* rarc)
{

	CharacterData::UpdateImages();

	gOptionMenu = new VsOptionsMenuMgr;
	gOptionMenu->init();

	for (int i = 0; i < GetConfigSize(); i++) {
	    gConfig[i] = gOptions[i].getValue();
	}

	TVsSelect::doCreate(rarc);

	mWhitePikiNum  = _1F8->mWhiteHandicap;
	mPurplePikiNum = _1F8->mPurpleHandicap;

	for (int i = 0; i < 4; i++) {
		mTeamIDs[i] = Game::getVsTeam(i);
	}

	for (int i = Game::gNaviNum; i < 4; i++) {
		mTeamIDs[i] = i;
	}

	// if (!isMemoryOverrideOn()) {
	//     for (int i = 0; i < 4; i++) {
	//         if (mTeamIDs[i] >= 2) {
	//             mTeamIDs[i] = 1;
	//         }
	//     }
	// }

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

	if (gWidescreenActive) {
		mWhitePikis->mPikminFlower->mOffset.x -= 30.0f;
		mWhitePikis->mPikminLeft->mOffset.x -= 30.0f;
		mWhitePikis->mPikminRight->mOffset.x -= 30.0f;

		mPurplePikis->mPikminFlower->mOffset.x -= 30.0f;
		mPurplePikis->mPikminLeft->mOffset.x -= 30.0f;
		mPurplePikis->mPikminRight->mOffset.x -= 30.0f;
	}

	if (isTeamIDActive(Game::TEAM_WHITE)) {
		mDispWhitePikiNum = mWhitePikiNum * 5;
		mWhitePikis->setupPosinfo(mWhitePikiNum);
	} else {
		mDispWhitePikiNum = 0;
		mWhitePikis->setupPosinfo(0);
	}

	if (isTeamIDActive(Game::TEAM_PURPLE)) {
		mDispPurplePikiNum = mPurplePikiNum * 5;
		mPurplePikis->setupPosinfo(mPurplePikiNum);
	} else {
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
	if (pikiWhite)
		pikiWhite->hide();

	J2DPane* pikiPurple = mMainScreen->mScreenObj->search('Npp_00');
	if (pikiPurple)
		pikiPurple->hide();

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

	const char* iconPaths[4] = { "orima003.bti", "lui003.bti", "president_large.bti", "wife_large.bti" };

	J2DPane* root = mMainScreen->mScreenObj->search('ROOT');

	mNaviNames[0] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('OliName'));
	mNaviNames[1] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('LuiName')); // Pardon my french
	mNaviNames[2] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('PresName'));
	mNaviNames[3] = static_cast<J2DTextBoxEx*>(mMainScreen->mScreenObj->search('WifeName'));

	mNewWinCallbacks[0] = new og::Screen::CallBack_CounterRV(const_cast<char**>(og::Screen::SujiTex32), 2, 4, mArchive);
	mNewWinCallbacks[0]->init(mMainScreen->mScreenObj, 'Pori2_r', 'Pori2_l', 'Pori2_c', &mNewWinValues[0], true);

	mNewWinCallbacks[0]->setPuyoAnim(true);
	mMainScreen->mScreenObj->addCallBack('Pori2_r', mNewWinCallbacks[0]);

	mNewWinCallbacks[1] = new og::Screen::CallBack_CounterRV(const_cast<char**>(og::Screen::SujiTex32), 2, 4, mArchive);
	;
	mNewWinCallbacks[1]->init(mMainScreen->mScreenObj, 'Plui2_r', 'Plui2_l', 'Plui2_c', &mNewWinValues[1], true);

	mNewWinCallbacks[1]->setPuyoAnim(true);
	mMainScreen->mScreenObj->addCallBack('Plui2_r', mNewWinCallbacks[1]);

	mNewWinCallbacks[2] = new og::Screen::CallBack_CounterRV(const_cast<char**>(og::Screen::SujiTex32), 2, 4, mArchive);
	;
	mNewWinCallbacks[2]->init(mMainScreen->mScreenObj, 'Ppres_r', 'Ppres_l', 'Ppres_c', &mNewWinValues[2], true);

	mNewWinCallbacks[2]->setPuyoAnim(true);
	mMainScreen->mScreenObj->addCallBack('Ppres_r', mNewWinCallbacks[2]);

	mNewWinCallbacks[3] = new og::Screen::CallBack_CounterRV(const_cast<char**>(og::Screen::SujiTex32), 2, 4, mArchive);
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

		mNaviImages[i] = og::Screen::CopyPictureToPane(static_cast<J2DPictureEx*>(mOrimaPikiIcon), root, baseX, baseY, 'ORI0' + i);

		mNaviImages[i]->updateScale(0.5f);
		mNaviImages[i]->changeTexture(sCharacters[i].mImage, 0);

		mNaviNames[i]->mOffset = JGeometry::TVec2f(baseX + 10.0f, baseY - 2.0f);

		if (gWidescreenActive) {
			mNaviNames[i]->mOffset.x *= 1.333f;
			mNaviNames[i]->mOffset.x -= 100.0f;
		}

		mNaviNames[i]->updateScale(1.0f, 0.8f);

		mNewWinCallbacks[i]->mPane->mOffset = JGeometry::TVec2f(baseX + 77.5f, baseY - 5.0f);
		mNewWinCallbacks[i]->update();

		const JUtility::TColor& color = vsTeamColors[mTeamIDs[i]];
		mLerpColors[i]                = color;
		f32 boxX                      = boxXOffs[mTeamIDs[i]];
		f32 boxY                      = boxYOffs[i];

		mNaviBoxes[i] = static_cast<J2DPictureEx*>(mMainScreen->mScreenObj->search('NaviBox0' + i));
		P2ASSERT(mNaviBoxes[i]);
		mNaviBoxes[i]->setWhite(color);
		mWinBoxes[i] = static_cast<J2DPictureEx*>(mMainScreen->mScreenObj->search('WinBox0' + i));

		mNaviBoxes[i]->setOffset(mNaviBasePos[i].x + NAVI_BOX_OFFS_X, mNaviBasePos[i].y + NAVI_BOX_OFFS_Y);
		mWinBoxes[i]->setOffset(mNaviBasePos[i].x + WIN_BOX_OFFS_X, mNaviBasePos[i].y + WIN_BOX_OFFS_Y);
	}

	for (int i = Game::gNaviNum; i < 4; i++) {
		mNaviImages[i]->hide();
		mNaviBoxes[i]->hide();
		mWinBoxes[i]->hide();
		mNewWinCallbacks[i]->hide();
		mNaviNames[i]->hide();
	}

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

bool TFourVsSelect::doUpdateFadein()
{
	if (!gDrawVsMenu && gOptionMenu) {
		gDrawVsMenu = gOptionMenu->update();
		return false;
	}
	return TVsSelect::doUpdateFadein();
}

void TFourVsSelect::doUpdateFadeoutFinish()
{
	TVsSelect::doUpdateFadeoutFinish();
	// PSStop2DStream();
	_1F8->mWhiteHandicap  = mWhitePikiNum;
	_1F8->mPurpleHandicap = mPurplePikiNum;
	DebugReport("Handicaps:\n Red %i\n Blue %i\n White %i\n Purple %i\n", _1F8->mOlimarHandicap, _1F8->mLouieHandicap, _1F8->mWhiteHandicap,
	            _1F8->mPurpleHandicap);
}

bool TFourVsSelect::doUpdate()
{
	if (!gDrawVsMenu && gOptionMenu) {
		gDrawVsMenu = gOptionMenu->update();

		if (gDrawVsMenu) {
			// PSStop2DStream();
			// PSStart2DStream(0xc001100f);
			for (int i = 0; i < 4; i++) {
				mNaviImages[i]->changeTexture(sCharacters[i].mImage, 0);
			}
		}

		return false;
	}

    // OSReport("Zoom State %i\n", _240);
    // OSReport("Zoom Level %f\n", _250);

	Game::gNaviNum = Game::CalcNaviNum();
	if (Game::gNaviNum == 3) {
		Game::gFancyCamera = true;
	} else {
		Game::gFancyCamera = false;
	}
	Controller* controllerArray[4] = { mController, mController2, Game::gControllerP3, Game::gControllerP4 };

	int* pikiNumArray[4] = { &mRedPikiNum, &mBluePikiNum, &mWhitePikiNum, &mPurplePikiNum };

	TConfirmEndWindow* confirmEndWindow = static_cast<TVsSelectScene*>(getOwner())->mConfirmEndWindow;

	if (_D4->mState == 0 && _240 == 0 && !confirmEndWindow->mIsActive) {
		if (mController->isButtonDown(JUTGamePad::PRESS_START)) {
			PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_OPEN, 0);
			// PSStop2DStream();
			// PSStart2DStream(0xc0011024);
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
						} else {
							PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_INCREMENT, 0);
						}
					} else if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_L)) {
						(*pikiNumArray[c])--;
						if (*pikiNumArray[c] < 1) {
							*pikiNumArray[c] = 1;
						} else {
							PSSystem::spSysIF->playSystemSe(PSSE_SY_PIKI_DECREMENT, 0);
						}
					}
				}
			}
		}
	}

	bool check = TVsSelect::doUpdate();
    // OSReport("check %i\n", check);

	if (_D4->mState == 0 && _240 == 0 && !confirmEndWindow->mIsActive) {
		for (int i = 0; i < 4; i++) {
			P2ASSERT(controllerArray[i]);
			if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_RIGHT) && !mAnimActive[i]) {
				// !isMemoryOverrideOn() && mTeamIDs[i] == Game::TEAM_BLUE)
				if (mTeamIDs[i] == Game::TEAM_PURPLE) {
					PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
					mErrAnimActive[i]   = true;
					mErrAnimProgress[i] = 0.0f;
					mErrAnimSpeed[i]    = 5.0f;
				} else {
					mTeamIDs[i]++;
					mAnimActive[i]   = true;
					mAnimProgress[i] = 0.0f;
					mAnimSpeed[i]    = 9.0f;
					mAnimDir[i]      = 1;
					PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_THROW, 0);
				}
			} else if (controllerArray[i]->isButtonDown(JUTGamePad::PRESS_LEFT) && !mAnimActive[i]) {
				if (mTeamIDs[i] == Game::TEAM_RED) {
					mErrAnimActive[i]   = true;
					mErrAnimProgress[i] = 1.0f;
					mErrAnimSpeed[i]    = -5.0f;
					PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
				} else {
					mTeamIDs[i]--;
					mAnimActive[i]   = true;
					mAnimProgress[i] = 0.0f;
					mAnimDir[i]      = -1;
					mAnimSpeed[i]    = 9.0f;
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
				mAnimActive[i]   = false;
				mAnimProgress[i] = 0.0f;

				mErrAnimActive[i]   = false;
				mErrAnimProgress[i] = 0.5f;
				mErrAnimSpeed[i]    = 5.0f;

				PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_GROUND, 0);
			} else if (mAnimProgress[i] > 1.0f) {
				mAnimActive[i]   = false;
				mAnimProgress[i] = 1.0f;

				mErrAnimActive[i]   = false;
				mErrAnimProgress[i] = 0.5f;
				mErrAnimSpeed[i]    = -5.0f;

				PSSystem::spSysIF->playSystemSe(PSSE_PK_CARROT_GROUND, 0);
			}
			f32 smoothedProgress = (1.0f - oddSqrt(pikmin2_cosf(mAnimProgress[i] * PI))) * 0.5f;
			mNaviBasePos[i].x
			    = (baseXOffs[mTeamIDs[i]] - baseXOffs[mTeamIDs[i] - mAnimDir[i]]) * smoothedProgress + baseXOffs[mTeamIDs[i] - mAnimDir[i]];
			mLerpColors[i].r
			    = vsTeamColors[mTeamIDs[i] - mAnimDir[i]].r * (1.0f - smoothedProgress) + vsTeamColors[mTeamIDs[i]].r * smoothedProgress;
			mLerpColors[i].g
			    = vsTeamColors[mTeamIDs[i] - mAnimDir[i]].g * (1.0f - smoothedProgress) + vsTeamColors[mTeamIDs[i]].g * smoothedProgress;
			mLerpColors[i].b
			    = vsTeamColors[mTeamIDs[i] - mAnimDir[i]].b * (1.0f - smoothedProgress) + vsTeamColors[mTeamIDs[i]].b * smoothedProgress;
		} else if (mErrAnimActive[i]) {
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
			mNaviBasePos[i].x   = baseXOffs[mTeamIDs[i]] + smoothedProgess * 5.0f;
		}

		mNaviImages[i]->setOffset(mNaviBasePos[i].x - 20.0f, mNaviBasePos[i].y - 20.0f);

		mNaviNames[i]->setOffset(mNaviBasePos[i].x + 10.0f, mNaviBasePos[i].y - 2.0f);

		if (gWidescreenActive) {
			mNaviNames[i]->mOffset.x /= 1.333f;
			mNaviNames[i]->mOffset.x += 85.0f;

			mNaviNames[i]->calcMtx();
		}

		mNewWinCallbacks[i]->mPane->mOffset = JGeometry::TVec2f(mNaviBasePos[i].x + 77.5f, mNaviBasePos[i].y - 5.0f);
		if (*mNewWinCallbacks[i]->mCountPtr < 10) {
			mNewWinCallbacks[i]->mPane->mOffset.x -= 6.0f;
			mNewWinCallbacks[i]->mCounters[0]->mSize.x = 1.2f;
		} else {
			mNewWinCallbacks[i]->mCounters[0]->mSize.x = 0.5f;
		}
		mNewWinCallbacks[i]->update();

		mNaviBoxes[i]->setOffset(mNaviBasePos[i].x + NAVI_BOX_OFFS_X, mNaviBasePos[i].y + NAVI_BOX_OFFS_Y);
		mNaviBoxes[i]->setWhite(mLerpColors[i]);

		mWinBoxes[i]->setOffset(mNaviBasePos[i].x + WIN_BOX_OFFS_X, mNaviBasePos[i].y + WIN_BOX_OFFS_Y);
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

	TVsPiki* vsPikis[4]    = { mVsPiki[0], mVsPiki[1], mWhitePikis, mPurplePikis };
	u32* dispPikiNumArr[4] = { &mDispRedPikiNum, &mDispBluePikiNum, &mDispWhitePikiNum, &mDispPurplePikiNum };

	for (int i = 0; i < 4; i++) {

		if (!isTeamIDActive(i)) {
			vsPikis[i]->update(0);
			*dispPikiNumArr[i] = 0;
		} else {
			vsPikis[i]->update(*pikiNumArray[i]);
			*dispPikiNumArr[i] = *pikiNumArray[i] * 5;
		}
	}
    // OSReport("return;\n");
	return false;
}

// TVsPikiDraw__Q28Morimura13TFourVsSelectFR8Graphics
void TFourVsSelect::TVsPikiDraw(Graphics& gfx)
{
	mWhitePikis->draw();
	mPurplePikis->draw();

	for (int i = 0; i < 4; i++) {

		if (mNaviNames[i]->isVisible()) {

			J2DTextBoxEx* text = mNaviNames[i];
			JUTFont* font      = nullptr;
			if (text->mMaterial && text->mMaterial->getTevBlock()) {
				font = text->mMaterial->getTevBlock()->getFont();
			}

			if (!font) {
				font = getPikminFont();
			}

			J2DPrint print(font, JUtility::TColor(0xffffffff), JUtility::TColor(0x807700ff));
			size_t size = strlen(sCharacters[i].mDispName);
			float sizeX = 15.0f;
			if (gWidescreenActive) {
				sizeX /= 1.33333f;
			}
			if (size > 6) {
				sizeX = 85.0f / size;
			}
			print.setFontSize(sizeX, text->mFontSize.y);

			GXLoadPosMtxImm(text->mGlobalMtx, 0);

			print.printReturn(sCharacters[i].mDispName, mNaviNames[i]->mBounds.getWidth() + 50.0f, mNaviNames[i]->mBounds.getHeight(),
			                  mNaviNames[i]->getHBinding(), mNaviNames[i]->getVBinding(), mNaviNames[i]->_10C, mNaviNames[i]->_110, 255);
		}
	}
}

void TFourVsSelect::doDraw(Graphics& gfx) {
    if (!gDrawVsMenu && gOptionMenu) {
        gOptionMenu->draw(gfx);
        return;
    }

	TVsSelect::doDraw(gfx);

    // if (!gDrawVsMenu) {
	// 	gOptionMenu->draw(gfx);
	// }

	// if (!isMemoryOverrideOn()) {

	//     J2DPrint print2(getPikminFont(), JUtility::TColor(0xffffffff), JUtility::TColor(0x807700ff));

	//     print2.print(20.0f, 30.0f, "MEMORY OVERRIDE IS OFF");
	//     print2.print(20.0f, 90.0f, "White and Purple teams are disabled\n some maps may crash");

	// }

	// J2DPrint printer(getPikminFont(), 0.0f);

	// printer.mGlyphHeight /= 4;
	// printer.mGlyphWidth /= 4;

	// printer.print(0.0f, 0.0f, "%p Piki Anaylis:\n", mVsPiki[1]);
	// printer.print(0.0f, 5.0f, "Image basePos %i, %i, %i\n", mVsPiki[1]->mPikminFlower->mBasePosition,
	// mVsPiki[1]->mPikminLeft->mBasePosition, mVsPiki[1]->mPikminRight->mBasePosition); for (int i = 0; i < 10; i++) {
	//     printer.print(0.0f, 20.0f * i + 10.0f, "posInfo %i:\n", i);
	//     printer.print(0.0f, 20.0f * i + 15.0f, "Position %f %f\n", mVsPiki[1]->mInfo[i].mPosition.x, mVsPiki[1]->mInfo[i].mPosition.y);
	//     printer.print(0.0f, 20.0f * i + 20.0f, "State Timer %f\n", mVsPiki[1]->mInfo[i].mStateTimer);
	//     printer.print(0.0f, 20.0f * i + 25.0f, "State %i\n", mVsPiki[1]->mInfo[i].mState);
	// }
	// printer.print(0.0f, 210.0f, "Bounds %f %f | %f %f\n", mVsPiki[1]->mBounds[0].x, mVsPiki[1]->mBounds[0].y, mVsPiki[1]->mBounds[1].x,
	// mVsPiki[1]->mBounds[1].y);

	// printer.print(200.0f, 0.0f, "%p Piki Anaylis:\n", mWhitePikis);
	// printer.print(200.0f, 5.0f, "Image basePos %i, %i, %i\n", mWhitePikis->mPikminFlower->mBasePosition,
	// mWhitePikis->mPikminLeft->mBasePosition, mWhitePikis->mPikminRight->mBasePosition); for (int i = 0; i < 10; i++) {
	//     printer.print(200.0f, 20.0f * i + 10.0f, "posInfo %i:\n", i);
	//     printer.print(200.0f, 20.0f * i + 15.0f, "Position %f %f\n", mWhitePikis->mInfo[i].mPosition.x,
	//     mWhitePikis->mInfo[i].mPosition.y); printer.print(200.0f, 20.0f * i + 20.0f, "State Timer %f\n",
	//     mWhitePikis->mInfo[i].mStateTimer); printer.print(200.0f, 20.0f * i + 25.0f, "State %i\n", mWhitePikis->mInfo[i].mState);
	// }
	// printer.print(200.0f, 210.0f, "Bounds %f %f | %f %f\n", mWhitePikis->mBounds[0].x, mWhitePikis->mBounds[0].y,
	// mWhitePikis->mBounds[1].x, mWhitePikis->mBounds[1].y);

	// J2DPrint printWhite(getPikminFont(), vsTeamColors[2], vsTeamColors[2]);
	// J2DPrint printPurple(getPikminFont(), vsTeamColors[3], vsTeamColors[3]);

	// printWhite.print(310.0f, 280.0f, "%i", mWhitePikiNum * 5);
	// printPurple.print(310.0f, 330.0f, "%i", mPurplePikiNum * 5);
}

namespace {
const char* cVsNames[]
    = { "otegaru",     "ujyaujya",   "hirobiro", "karakuchi", "semai",  "hiyahiya", "nobinobi", "kakukaku", "meiro",  "tile",
	    "combat_zone", "kingchappy", "field",    "steel",     "toy",    "matrix",   "sewer",    "basin",    "metals", "deep_blue",
	    "theater",     "spider",     "seesaw",   "bridge",    "frozen", "wraith",   "rain",     "court",    "double", "gates" };
} // namespace

void TVsSelect::setSelectTextures()
{
	DebugReport("Icon Names: %i\n", ARRAY_SIZE(cVsNames));
	for (int i = 0; i < mStageCount; i++) {
		mLevelTextures[i] = nullptr;
		if (i < ARRAY_SIZE(cVsNames)) {

			char buffer[64];
			sprintf(buffer, "timg/%s.bti", cVsNames[i]);
			DebugReport("loading %s...\n", buffer);
			void* obj         = _B4->getResource(buffer);
			mLevelTextures[i] = (ResTIMG*)obj;
		}
		if (!mLevelTextures[i]) {
			void* obj2        = mArchive->getResource("timg/loozy_icon.bti");
			mLevelTextures[i] = (ResTIMG*)obj2;
			P2ASSERT(mLevelTextures[i]);
		}
	}
}

void TVsSelect::makeMsgTag()
{
	u64 spots[] = { '4771_00', '4810_00' };
	_1FC        = new TOffsetMsgSet(spots, '4770_00', ARRAY_SIZE(spots));
}

} // namespace Morimura

// _debug_print__Fv
void _debug_print() {
    // OSReport("ASM DEBUG PRINT\n");
}

// getPikminAlloc__Fv
int getPikminAlloc()
{
	return 250; // isMemoryOverrideOn() ? 200 : 100;
}