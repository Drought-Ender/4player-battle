#include "og/newScreen/Vs.h"
#include "og/newScreen/Challenge.h"
#include "og/Sound.h"
#include "efx2d/T2DSprayset.h"
#include "efx2d/T2DSensor.h"
#include "FourPlayer.h"
#include "JSystem/JUtility/JUTTexture.h"
#include "Game/Navi.h"
#include "CherryTarget.h"
#include "Game/VsGameSection.h"
#include "Game/VsGame.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "VsOptions.h"


#if FOURPLAYER_DEBUG == 1
#define MemoryReport() OSReport("%i: %x Free Size\n", __LINE__, JKRHeap::sCurrentHeap->getFreeSize())
#else
#define MemoryReport()
#endif

namespace og
{

namespace newScreen
{

bool FourObjVs::sFlickerDNE = false;

FourObjVs::~FourObjVs() {

}

FourObjVs::FourObjVs(const char* name) : ObjVs(name), mClock() {
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

		for (int j = 0; j < 4; j++) {
			mPane_minibedama[i][j] = nullptr;
			mPane_mininodama[i][j] = nullptr;
		}
    }

    mHasAllBedamaP3 = false;
    mHasAllBedamaP4 = false;

    mFirstBedamaGetP3 = false;
    mFirstBedamaGetP4 = false; 

	mTimerScreen = nullptr;
}

typedef JUtility::TColor TColorPair[2];

const TColorPair gGetMarbleColors[4] = { 
	{ 0xff0000ff, 0xff8787ff },  
	{ 0x2020ffff, 0x5787ffff },
	{ 0xffffffff, 0xe8f9e2ff },
	{ 0xae42ffff, 0xd281ffff }
};

const JUtility::TColor gBingoGetColors[4] = {
	0xffa0a0ff,
	0xa0a0ffff,
	0xffffffff,
	0xbe60ffff
};



void FourObjVs::BingoCard::Setup(J2DPane* root, J2DPictureEx* basePane, J2DPictureEx* itemPane, f32 scale, f32 baseX, f32 baseY, int id) {
	f32 incSize = 25.0f * scale;


	P2ASSERT(basePane);
	P2ASSERT(itemPane);

	f32 xoffs     = 0;
	f32 yoffs     = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			mFlags[x][y] = false;
			mScaleMgrs[x][y] = new og::Screen::ScaleMgr;

			mPaneBase[x][y] = og::Screen::CopyPictureToPane(basePane, root, baseX + xoffs, baseY + yoffs, 'bpb_000' + id * 16 + x * 4 + y);
			P2ASSERT(itemPane);
			P2ASSERT(itemPane->getTIMG(0));
			mPaneItem[x][y] = og::Screen::CopyPictureToPane(itemPane, root, baseX + xoffs, baseY + yoffs, 'bpi_000' + id * 16 + x * 4 + y);
			MemoryReport();
			xoffs += incSize;

			
		}
		
		xoffs = 0;
		yoffs += incSize;
	}
}

void FourObjVs::BingoCard::SetColor(JUtility::TColor& color) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			mPaneBase[x][y]->setWhite(color);
		}
	}

	
}

void FourObjVs::UpdateBingoCardTextures() {
	for (int i = 0; i < 4; i++) {

		Game::VsGame::BingoMgr::BingoCard& card = mDisp->mBingoMgr->mCards[Game::getVsTeam_s(i)];
		Game::VsGame::BingoMgr::ObjectKey& key = mDisp->mBingoMgr->mKey;

		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if ((!FourObjVs::sFlickerDNE || mDoesNotExistActive) && card.isImpossible(key, x, y)) {
					//mBingoCards[i].mPaneItem[x][y]->changeTexture(key.mObjectEntries[card.mObjects[x][y]].mObjectTexture, 0);
					
					mBingoCards[i].mPaneItem[x][y]->changeTexture(mPaneBingoImpossible->getTIMG(0), 0);
				}
				else {
					mBingoCards[i].mPaneItem[x][y]->changeTexture(key.mObjectEntries[card.mObjects[x][y]].mObjectTexture, 0);
				}
			}
		}
	}
}

inline void FourObjVs::SetupBedamaPanes(J2DPane* root, int player, J2DPictureEx* firstPane, J2DPictureEx* secondPane, J2DPictureEx* thirdPane, J2DPictureEx* minipane, f32 baseX, f32 baseY) {
	J2DPictureEx** allBedamaPanes[4]  = { mPane_bedama1P, mPane_bedama2P, mPane_bedama3P, mPane_bedama4P };
	J2DPictureEx** allNodamaPanes[4]  = { mPane_nodama1P, mPane_nodama2P, mPane_nodama3P, mPane_nodama4P };
	J2DPictureEx** allWindamaPanes[4] = { mPane_windama1P, mPane_windama2P, mPane_windama3P, mPane_windama4P };

	og::Screen::ScaleMgr** allScaleMgrs[4][2] = { 
		{mScaleMgrP1_1, mScaleMgrP1_2},
		{mScaleMgrP2_1, mScaleMgrP2_2},
		{mScaleMgrP3_1, mScaleMgrP3_2},
		{mScaleMgrP4_1, mScaleMgrP4_2}
	};

	J2DPictureEx** ourBedamaPanes  = allBedamaPanes[player];
	J2DPictureEx** ourNodamaPanes  = allNodamaPanes[player];
	J2DPictureEx** ourWindamaPanes = allWindamaPanes[player];

	og::Screen::ScaleMgr** ourScaleMgrs_1 = allScaleMgrs[player][0];
	og::Screen::ScaleMgr** ourScaleMgrs_2 = allScaleMgrs[player][1];

	{
		f32 incSize = 40.0f * mBedamaScale;

		f32 xoffs     = 0;
		f32 yoffs     = 0;
		for (int i = 0; i < 4; i++) {
			ourBedamaPanes[i]
				= og::Screen::CopyPictureToPane(firstPane, root, baseX + xoffs, baseY + yoffs, 'bd1P_000' + i);
			ourNodamaPanes[i]
				= og::Screen::CopyPictureToPane(secondPane, root, baseX + xoffs, baseY + yoffs, 'nd1P_000' + i);
			ourWindamaPanes[i]
				= og::Screen::CopyPictureToPane(thirdPane, root, baseX + xoffs, baseY + yoffs, 'wd1P_000' + i);
			ourScaleMgrs_1[i] = new og::Screen::ScaleMgr;
			ourScaleMgrs_2[i] = new og::Screen::ScaleMgr;
			xoffs += incSize;
			ourWindamaPanes[i]->hide();
		}
	}

	{
		f32 incSize = 20.0f * mBedamaScale;

		baseX -= 10.0f * mBedamaScale;
		baseY -= 30.0f * mBedamaScale;

		f32 xoffs     = 0;
		f32 yoffs     = 0;
		for (int i = 0; i < 4; i++) {
			mPane_minibedama[player][i]
				= og::Screen::CopyPictureToPane(minipane, root, baseX + xoffs, baseY + yoffs, 'bd1P_000' + i);
			mPane_mininodama[player][i]
				= og::Screen::CopyPictureToPane(secondPane, root, baseX + xoffs, baseY + yoffs, 'nd1P_000' + i);
			mMinidamaScaleMgr[player][i] = new og::Screen::ScaleMgr;
			xoffs += incSize;
		}

	}
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

	const char* bloName = (Game::gNaviNum == 2) ? "challenge_1P.blo" : "small_1P.blo";
	mBloGroup->addBlo(const_cast<char*>(bloName), mScreenP1->mScreen, 0x1040000, arc);
	mBloGroup->addBlo(const_cast<char*>(bloName), mScreenP2->mScreen, 0x1040000, arc);
    mBloGroup->addBlo(const_cast<char*>(bloName), mScreenP3->mScreen, 0x1040000, arc);
    mBloGroup->addBlo(const_cast<char*>(bloName), mScreenP4->mScreen, 0x1040000, arc);

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

	J2DPictureEx* olimarPicture = static_cast<J2DPictureEx*>(mScreenP1->mScreen->search('navi'));
	J2DPictureEx* louiePicture = static_cast<J2DPictureEx*>(mScreenP2->mScreen->search('navi'));
	J2DPictureEx* presidentPicture = static_cast<J2DPictureEx*>(mScreenP3->mScreen->search('navi'));
	J2DPictureEx* wifePicture = static_cast<J2DPictureEx*>(mScreenP4->mScreen->search('navi'));
	
	olimarPicture->changeTexture(sCharacters[0].mImage, 0);
	louiePicture->changeTexture(sCharacters[1].mImage, 0);
	presidentPicture->changeTexture(sCharacters[2].mImage, 0);
	wifePicture->changeTexture(sCharacters[3].mImage, 0);

	JUtility::TColor teamColors[4] = {
		JUtility::TColor(0xff, 0x00, 0x00, 0xff),
		JUtility::TColor(0x00, 0x00, 0xff, 0xff),
		JUtility::TColor(0xff, 0xff, 0xff, 0xff),
		JUtility::TColor(0x78, 0x00, 0xff, 0xff)
	};
	
	recolorPane(scrn1, teamColors[Game::getVsTeam(0)]);
	recolorPane(scrn2, teamColors[Game::getVsTeam(1)]);
	recolorPane(scrn3, teamColors[Game::getVsTeam(2)]);
	recolorPane(scrn4, teamColors[Game::getVsTeam(3)]);

	J2DPictureEx* paneBdamaR = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_red'));
	J2DPictureEx* paneBdamaW = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_white'));
	J2DPictureEx* paneBdamaP = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_purpl'));
	J2DPictureEx* paneBdamaY = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_yello'));
	J2DPictureEx* paneBdamaB = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_blue'));
	J2DPictureEx* panePcup   = static_cast<J2DPictureEx*>(bdamaScreen->search('Pcup'));
	J2DPictureEx* paneMiniDama = static_cast<J2DPictureEx*>(bdamaScreen->search('Pb_mini'));
	J2DPictureEx* paneBingobase = static_cast<J2DPictureEx*>(bdamaScreen->search('bngoBase'));
	J2DPictureEx* paneBingoItem = static_cast<J2DPictureEx*>(bdamaScreen->search('bngoItem'));
	mPaneBingoGet = static_cast<J2DPictureEx*>(bdamaScreen->search('bngoGet'));
	mPaneBingoImpossible = paneBingoItem;

	P2ASSERT(paneBingoItem);
	P2ASSERT(mPaneBingoGet);

    mColoredBedamaPanes[0] = paneBdamaR;
    mColoredBedamaPanes[1] = paneBdamaB;
	mColoredBedamaPanes[2] = paneBdamaW;
	mColoredBedamaPanes[3] = paneBdamaP;

    bool use4PSetup = Game::gNaviNum > 2;

	mBedamaScale = (Game::gNaviNum <= 2) ? 1.0f : 0.75f;

    f32 baseOffs = (Game::gNaviNum <= 2) ? msVal.mMarbleBaseXOffs : 220.0f;
    f32 baseYOffs = (Game::gNaviNum <= 2) ? msVal.mMarbleP1YOffs : msVal.mMarbleP1YOffs + (20.0f - 20.0f * mBedamaScale);

	J2DPane* root = scrn1->search('ROOT');
	J2DPane* root2 = scrn2->search('ROOT');
	J2DPane* root3 = scrn3->search('ROOT');
	J2DPane* root4 = scrn4->search('ROOT');

	if (gGameModeID == MAINGAME_BEDAMA) {
		
		SetupBedamaPanes(root, 0, paneBdamaY, panePcup, paneBdamaR, paneMiniDama, baseOffs, baseYOffs);

		
		SetupBedamaPanes(root2, 1, paneBdamaY, panePcup, paneBdamaR, paneMiniDama, baseOffs, baseYOffs);

		
		SetupBedamaPanes(root3, 2, paneBdamaY, panePcup, paneBdamaR, paneMiniDama, baseOffs, baseYOffs);

		
		SetupBedamaPanes(root4, 3, paneBdamaY, panePcup, paneBdamaR, paneMiniDama, baseOffs, baseYOffs);
	}
	else if (gGameModeID == MAINGAME_BINGO) {
		OSReport("bingo game\n");
		baseYOffs -= (Game::gNaviNum <= 2) ? 70.0f : 50.0f;

		baseOffs += (Game::gNaviNum <= 2) ? -10.0f : 35.0f;
		
		mBingoCards[0].Setup(root,  paneBingobase, paneBingoItem, mBedamaScale, baseOffs, baseYOffs, 0);
		mBingoCards[1].Setup(root2, paneBingobase, paneBingoItem, mBedamaScale, baseOffs, baseYOffs, 1);
		mBingoCards[2].Setup(root3, paneBingobase, paneBingoItem, mBedamaScale, baseOffs, baseYOffs, 2);
		mBingoCards[3].Setup(root4, paneBingobase, paneBingoItem, mBedamaScale, baseOffs, baseYOffs, 3);

		OSReport("Setup Done\n");

		for (int i = 0; i < 4; i++) {
			mBingoCards[i].SetColor(teamColors[Game::getVsTeam_s(i)]);
		}

		mDoesNotExistTimer  = 3.0f;
		mDoesNotExistActive = false;

		UpdateBingoCardTextures();
	}

	mScreenIcons = new P2DScreen::Mgr_tuning;
	mScreenIcons->set("obake_icon.blo", 0x1040000, arc);

	J2DPictureEx* paneObake = static_cast<J2DPictureEx*>(mScreenIcons->search('obake'));
	if (Game::gNaviNum > 2) {
		mPaneObake1P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP1YOffs, 'obake1P');
		mPaneObake2P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs + 300.0f, msVal.mRouletteP1YOffs, 'obake2P');
    	mPaneObake3P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP2YOffs, 'obake3P');
		mPaneObake4P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs + 300.0f, msVal.mRouletteP2YOffs, 'obake4P');
	}
	else {
		mPaneObake1P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP1YOffs, 'obake1P');
		mPaneObake2P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP2YOffs, 'obake2P');
    	mPaneObake3P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP2YOffs, 'obake3P');
		mPaneObake4P            = og::Screen::CopyPictureToPane(paneObake, root, msVal.mRouletteXOffs, msVal.mRouletteP2YOffs, 'obake4P');
	}
	mPaneObake1P->setAlpha(mAlphaObakeP1 * 255.0f);
	mPaneObake2P->setAlpha(mAlphaObakeP2 * 255.0f);
    mPaneObake3P->setAlpha(mAlphaObakeP1 * 255.0f);
	mPaneObake4P->setAlpha(mAlphaObakeP2 * 255.0f);
	MemoryReport();


	mScreenStickIcons = new P2DScreen::Mgr_tuning;
	MemoryReport();
	mScreenStickIcons->set("cherry_target.blo", 0x1040000, arc);
	MemoryReport();
	J2DPictureEx* paneOutStick = static_cast<J2DPictureEx*>(mScreenStickIcons->search('CtrlBubl'));
	J2DPictureEx* paneCtick    = static_cast<J2DPictureEx*>(mScreenStickIcons->search('CStick'));
	JUT_ASSERT(paneOutStick, "ctrlbubl missing\n");
	JUT_ASSERT(paneCtick, "cstick missing\n");

	Vector2f positions[4] = { Vector2f(-15.0f, -15.0f), Vector2f(15.0f, -15.0f), Vector2f(-15.0f, 15.0f), Vector2f(15.0f, 15.0f) };

	J2DPane* roots[4] = { root, root2, root3, root4 };
	J2DPictureEx* naviIcons[4] = { olimarPicture, louiePicture, presidentPicture, wifePicture };

	const float xoff = (Game::gNaviNum > 2) ? 125.0f : 425.0f;

	for (int i = 0; i < 4; i++) {
		mOutCircle[i] = og::Screen::CopyPictureToPane(paneOutStick, roots[i], msVal.mRouletteXOffs + xoff, msVal.mRouletteP1YOffs + 150.0f, 'CtrlBb00' + i);
		mCStick[i]    = og::Screen::CopyPictureToPane(paneCtick, roots[i], msVal.mRouletteXOffs + xoff, msVal.mRouletteP1YOffs + 150.0f, 'CStick00' + i);
		mCStickBasePos[i] = Vector2f(mCStick[i]->mOffset.x, mCStick[i]->mOffset.y);
		for (int j = 0; j < 4; j++) {
			mExtraIcons[i][j] = og::Screen::CopyPictureToPane(naviIcons[j], roots[i], 
			msVal.mRouletteXOffs + 125.0f + positions[j].x, 
			msVal.mRouletteP1YOffs + 150.0f + positions[j].y, 
			'NaviIcn0' + i * 4 + j
			);
			mExtraIcons[i][j]->updateScale(0.5f);
			mExtraIcons[i][j]->setAlpha(127);
		}
		MemoryReport();
	}

	MemoryReport();
	mTimerScreen = new P2DScreen::Mgr_tuning;
	mTimerScreen->set("timer.blo", 0x2040000, arc);
	MemoryReport();


	mClock.minute = og::Screen::setCallBack_CounterRV(mTimerScreen, 'MTime1', &mDisp->mTimerMinute, 1, false, true, arc);
    mClock.second = og::Screen::setCallBack_CounterRV(mTimerScreen, 'STime1', &mDisp->mTimerSecond, 2, false, true, arc);
    mClock.second->setZeroAlpha(255);
    mClock.colon  = (J2DPicture*)mTimerScreen->search('CTime');
    mClock.base   = mTimerScreen->search('BaseTime');

	MemoryReport();

    if (!gConfig[STALEMATE_TIMER]) {
        mClock.base->hide();
    }

    mClock.init();

    // for (int i = 0; i < 4; i++) {
    //     setWinBedamaColor(i, mDisp->mWinMarbleColors[i]);
    // }
	if (gGameModeID == MAINGAME_BEDAMA) setOnOffBdama4P(false);

	ScreenSet* screens[] = { mScreenP1, mScreenP2, mScreenP3, mScreenP4 };

	for (int i = 0; i < 4; i++) {
		P2DScreen::Node& node1 = screens[i]->mScreen->_118;
		mLifeGaugeAfter[i] = (og::Screen::CallBack_DrawAfter*)node1.getChildAt(node1.getChildCount() - 1);
	}

	if (gConfig[SPICY_PASSIVE] == ConfigEnums::SPICYPASSIVE_INF) {
		DebugReport("SPICY OFF!!!!\n");
		for (int i = 0; i < 4; i++) {
			screens[i]->mScreen->search('dy_r')->move(-600.0f, 0.0f);
			screens[i]->mScreen->search('dy_l')->move(-600.0f, 0.0f);
			J2DPane* pane = screens[i]->mScreen->search('dy_inf');
			if (pane) pane->show();
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			J2DPane* pane = screens[i]->mScreen->search('dy_inf');
			if (pane) pane->hide();
		}
	}
	if (gConfig[BITTER_PASSIVE] == ConfigEnums::BITTERPASSIVE_INF) {
		for (int i = 0; i < 4; i++) {
			screens[i]->mScreen->search('dr_r')->move(-600.0f, 0.0f);
			screens[i]->mScreen->search('dr_l')->move(-600.0f, 0.0f);
			J2DPane* pane = screens[i]->mScreen->search('dr_inf');
			if (pane) pane->show();
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			J2DPane* pane = screens[i]->mScreen->search('dr_inf');
			if (pane) pane->hide();
		}
	}
}

void FourObjVs::Clock::init() {
    
    P2ASSERT(minute);
    P2ASSERT(second);
    P2ASSERT(colon);
    P2ASSERT(base);
    minuteHidden = false;
    secondPushed = false;
	chimeRed    = true;
	chimeOrange = true;
    
    secondPos1 = second->mPane->mOffset;
    secondPos2 = JGeometry::TVec2f(second->mPane->mBounds.f.x, 0.0f);
    secondPos3 = JGeometry::TVec2f(0.0f, 0.0f);
    update();
}

void FourObjVs::Clock::update() {
    
    if (!minute || !second || !colon) return;
    if (!gConfig[STALEMATE_TIMER]) return;

    bool shouldTransitMinute = *(minute->mCountPtr) == 0;
    bool shouldTransitSecond = *(second->mCountPtr) < 10;


    // second->mPane->mOffset = JGeometry::TVec2f(0, 0);
    // second->mPane->calcMtx();

    if (shouldTransitMinute && shouldTransitSecond && !secondPushed) {
        secondPushed = true;
        second->mPane->mOffset = secondPos3;
    }
    else if (!shouldTransitSecond && secondPushed) {
        secondPushed = false;
        second->mPane->mOffset = secondPos2;
    }
    else if (shouldTransitMinute && !minuteHidden) {
        secondPushed = false;
        second->mPane->mOffset = secondPos2;
        second->mPane->calcMtx();
        second->setZeroAlpha(0);
        minuteHidden = true;
        colon->hide();
        minute->hide();
        second->mZeroAlpha = 0;
    }
    else if (!shouldTransitMinute && minuteHidden) {
        secondPushed = false;
        second->mPane->mOffset = secondPos1;
        second->mPane->calcMtx();
        minuteHidden = false;
        second->setZeroAlpha(255);
        colon->show();
        minute->show();
    }

    minute->update();
    second->update();
    
    setColors();
    MemoryReport();
}

void FourObjVs::Clock::setColors() {

    static const JUtility::TColor HighWhite(0xff, 0xff, 0xff, 0xff);
    static const JUtility::TColor MidWhite(0xff, 0x80, 0x00, 0xff);
    static const JUtility::TColor LowWhite(0xff, 0x00, 0x00, 0xff);

    static const JUtility::TColor HighBlack(0x00, 0x00, 0x00, 0x00);
    static const JUtility::TColor MidBlack(0x40, 0x20, 0x00, 0x00);
    static const JUtility::TColor LowBlack(0x40, 0x00, 0x00, 0x00);


    int time = (*second->mCountPtr) + (*minute->mCountPtr) * 60;

    if (time <= 60) {
        second->mPic1->setWhite(LowWhite);
        minute->mPic1->setWhite(LowWhite);
        colon->setWhite(LowWhite);

        second->mPic1->setBlack(LowBlack);
        minute->mPic1->setBlack(LowBlack);
        colon->setBlack(LowBlack);
		
		if (!chimeRed) {
			ogSound->setChime();
			chimeRed = true;
		}
    }
    else if (time <= 180) {
		chimeRed = false;
		
        second->mPic1->setWhite(MidWhite);
        minute->mPic1->setWhite(MidWhite);
        colon->setWhite(MidWhite);

        second->mPic1->setBlack(MidBlack);
        minute->mPic1->setBlack(MidBlack);
        colon->setBlack(MidBlack);

		if (!chimeOrange) {
			ogSound->setChime();
			chimeOrange = true;
		}
    }
    else {
		chimeRed = false;
		chimeOrange = false;

        second->mPic1->setWhite(HighWhite);
        minute->mPic1->setWhite(HighWhite);
        colon->setWhite(HighWhite);

        second->mPic1->setBlack(HighBlack);
        minute->mPic1->setBlack(HighBlack);
        colon->setBlack(HighBlack);
    }
}

// gets inlined normally
void ObjVs::ScreenSet::update(og::Screen::DataNavi& data)
{
	f32 scale5 = mScaleMgr1->calc();
	f32 scale6 = mScaleMgr2->calc();
	if (mPaneToyo01) {
		mPaneToyo01->updateScale(scale5);
	}
	if (mPaneToyo00) {
		mPaneToyo00->updateScale(scale6);
	}

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

void FourObjVs::updateCSticks() {
	for (int i = 0; i < Game::gNaviNum; i++) {
		Game::Navi* navi = Game::naviMgr->getAt(i);
		if (navi && navi->isAlive() && navi->mController1) {
			Vector2f pos = CherryTarget::GetXY(navi->mController1) * 10.0f;
			Vector2f netPos = pos + mCStickBasePos[i];
			mCStick[i]->setOffset(netPos.x, netPos.y);
		}

		if (static_cast<Game::VsGameSection*>(Game::gameSystem->mSection)->mCardMgr->getSlotMachine(Game::getVsTeam(i))->dispCherryTarget(i)) {
			mCStick[i]->show();
			mOutCircle[i]->show();
			for (int j = 0; j < 4; j++) {
				if (gDrawNavi[j]) {
					mExtraIcons[i][j]->show();
				}
				else {
					mExtraIcons[i][j]->hide();
				}
			}
		}
		else {
			mCStick[i]->hide();
			mOutCircle[i]->hide();
			for (int j = 0; j < 4; j++) {
				mExtraIcons[i][j]->hide();
			}
		}
	}
}

void FourObjVs::doUpdateCommon() {
	mClock.update();
    
	if (gGameModeID == MAINGAME_BEDAMA) {
		checkUpdateWinColor();
    	setOnOffBdama4P(!mSetBedamaFlag && !Game::moviePlayer->isActive());
	}
	else if (gGameModeID == MAINGAME_BINGO) {
		setOnOffBingo(!mSetBedamaFlag && !Game::moviePlayer->isActive());
	}
    checkObake();
	updateCSticks();
	mScreenP1->update(mDisp->mOlimarData);
	mScreenP2->update(mDisp->mLouieData);
	mScreenP3->update(mDisp->mP3Data);
	mScreenP4->update(mDisp->mP4Data);
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
        mScreenP2->mScreen->setXY(295.0f, scale * -300.0f);
        mScreenP3->mScreen->setXY(-10.0f, scale * 300.0f + 225.0f);
        mScreenP4->mScreen->setXY(295.0f, scale * 300.0f + 225.0f);
        if (mDisp->mHideP4) {
            mScreenP4->mScreen->hide();
        }
    }
	ScreenSet* screens[] = { mScreenP1, mScreenP2, mScreenP3, mScreenP4 };
	for (int i = 0; i < ARRAY_SIZE(screens); i++) {
		if (i >= Game::gNaviNum) {
			screens[i]->mScreen->setXY(0.0f, -600.0f);
			screens[i]->mScreen->hide();
		}
		if (mDisp->mNaviInactiveFlags[i]) {
			mLifeGaugeAfter[i]->mIsVisible = false;
			screens[i]->mLifeGauge[i].mNaviLifeRatio = 0.0f;
			screens[i]->mScreen->search('NALL')->hide();
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
	mTimerScreen->draw(gfx, gfx.mPerspGraph);
	if (gGameModeID == MAINGAME_BINGO) {
		DrawThreeInARow(gfx);
	}
}

void FourObjVs::DrawThreeInARow(Graphics& gfx) {

	const int MaxLine = (mDisp->mBingoMgr->mWinner == -1) ? 3 : 4; 

	J2DPerspGraph* graf = &gfx.mPerspGraph;
	graf->setPort();

	JUtility::TColor color1 = 0xffffffff;
	JUtility::TColor color2 = 0x000000ff;
	

	for (int player = 0; player < 4; player++) {
		int team = Game::getVsTeam_s(player);
		Game::VsGame::BingoMgr::BingoCard& card = mDisp->mBingoMgr->mCards[team];
		Game::VsGame::BingoMgr::ObjectKey& key = mDisp->mBingoMgr->mKey;

		Game::VsGame::BingoMgr::LineData data[10];

		int count = card.CheckLine(MaxLine, data, ARRAY_SIZE(data), true);

		for (int i = 0; i < count; i++) {
			int x1 = data[i].mXValues[0];
			int x2 = data[i].mXValues[3];

			int y1 = data[i].mYValues[0];
			int y2 = data[i].mYValues[3];

			Vector2f pos1;
			Vector2f pos2;

			og::Screen::calcGlbCenter(mBingoCards[player].mPaneBase[x1][y1], &pos1);
			og::Screen::calcGlbCenter(mBingoCards[player].mPaneBase[x2][y2], &pos2);

			JGeometry::TVec2f first = pos1;
			JGeometry::TVec2f second = pos2;

			u8 oldWidth = graf->mLineWidth;

			graf->setLineWidth(10);
			graf->setColor(color2);
			graf->line(first, second);

			graf->setLineWidth(4);
			graf->setColor(color1);
			graf->line(first, second);

			graf->setLineWidth(oldWidth);
		}
	}
}

// this function does something, and it's important, don't ask me what it is though
inline void FourObjVs::CheckWindama(int idx, int playerID, bool doEfx, bool& isWin) {
	bool flagArr[] = { mDisp->mFlags[0], mDisp->mFlags[1], mDisp->mFlag2[0], mDisp->mFlag2[1] };
	int marbleCounts[] = { mDisp->mMarbleCountP1, mDisp->mMarbleCountP2, mDisp->mMarbleCountP3, mDisp->mMarbleCountP4 };
	J2DPictureEx** windamaPanes[] = { mPane_windama1P, mPane_windama2P, mPane_windama3P, mPane_windama4P };
	bool* firstBedamaGet[] = { &mFirstBedamaGetP1, &mFirstBedamaGetP2, &mFirstBedamaGetP3, &mFirstBedamaGetP4 };

	og::Screen::ScaleMgr** windamaScaleMgr[] = { mScaleMgrP1_2, mScaleMgrP2_2, mScaleMgrP3_2, mScaleMgrP4_2 };

	if (flagArr[playerID] && marbleCounts[playerID] == idx && mBedamaGetTimers[playerID] > 0.0f) {
		mBedamaGetTimers[playerID] -= sys->mDeltaTime;
		if (mBedamaGetTimers[playerID] <= 0.0f) {
			windamaPanes[playerID][idx]->show();
			if (!*firstBedamaGet[playerID]) {
				*firstBedamaGet[playerID] = true;
				if (doEfx) {
					Vector2f pos;
					og::Screen::calcGlbCenter(windamaPanes[playerID][idx], &pos);
					const TColorPair& colors = gGetMarbleColors[mWinDamaColor[0]];
					efx2d::ArgScaleColorColor arg(&pos, mBedamaScale, colors[0], colors[1]);
					efx2d::T2DSprayset_forVS efx;
					efx.create(&arg);
					ogSound->setBdamaGet();
					mDoneState = 1;
					windamaScaleMgr[playerID][idx]->up();
					isWin = true;
				}
			}
		}
	}
}

inline void FourObjVs::CheckBedama(int idx, int playerID, bool doEfx, f32 scale, bool& isWin) {

	bool flagArr[] = { mDisp->mFlags[0], mDisp->mFlags[1], mDisp->mFlag2[0], mDisp->mFlag2[1] };
	
	int marbleCounts[] = { mDisp->mMarbleCountP1, mDisp->mMarbleCountP2, mDisp->mMarbleCountP3, mDisp->mMarbleCountP4 };
	

	J2DPictureEx** bedamaPanes[] = { mPane_bedama1P, mPane_bedama2P, mPane_bedama3P, mPane_bedama4P };
	J2DPictureEx** nodamaPanes[] = { mPane_nodama1P, mPane_nodama2P, mPane_nodama3P, mPane_nodama4P };
	J2DPictureEx** windamaPanes[] = { mPane_windama1P, mPane_windama2P, mPane_windama3P, mPane_windama4P };
	
	bool* firstBedamaGet[] = { &mFirstBedamaGetP1, &mFirstBedamaGetP2, &mFirstBedamaGetP3, &mFirstBedamaGetP4 };

	bool* bedamaGotFlags[] = { mBedamaGotFlagsP1, mBedamaGotFlagsP2, mBedamaGotFlagsP3, mBedamaGotFlagsP4 };
	bool* hasAllBedamaFlags[] = { &mHasAllBedamaP1, &mHasAllBedamaP2, &mHasAllBedamaP3, &mHasAllBedamaP4 };

	og::Screen::ScaleMgr** bedamaScaleMgr[] = { mScaleMgrP1_1, mScaleMgrP2_1, mScaleMgrP3_1, mScaleMgrP4_1 };




	if (marbleCounts[playerID] > idx) {
		nodamaPanes[playerID][idx]->hide();
		bedamaPanes[playerID][idx]->show();
		bedamaPanes[playerID][idx]->updateScale(scale);
		if (!bedamaGotFlags[playerID][idx]) {
			if (idx == 3) {
				mDoneState = 1;
			}
			*hasAllBedamaFlags[playerID] = (idx == 3);
			if (doEfx) {
				if (mDoneState != 1) {
					ogSound->setBdamaGet();
					Vector2f pos;
					og::Screen::calcGlbCenter(bedamaPanes[playerID][idx], &pos);

					efx2d::ArgScaleColorColor arg(&pos, mBedamaScale, 0xcfcf00ff, 0xe7e757ff);
					efx2d::T2DSprayset_forVS efx;
					efx.create(&arg);
				}
				bedamaScaleMgr[playerID][idx]->up();
			}
		}
		bedamaGotFlags[playerID][idx] = true;
	} else {
		bedamaPanes[playerID][idx]->hide();
		nodamaPanes[playerID][idx]->show();
		nodamaPanes[playerID][idx]->updateScale(scale);
		bedamaGotFlags[playerID][idx] = false;
	}

}

inline void FourObjVs::CheckMiniBedama(int idx, int playerID, bool doEfx, f32 scale) {

	if (mDisp->mHideMiniMarble) {
		mPane_mininodama[playerID][idx]->hide();
		mPane_minibedama[playerID][idx]->hide();
		return;
	}


	if (mDisp->mMiniMarbleCounts[playerID] == 0) {
		mMiniDamaGotFlags[playerID][idx] = 0;
	}

	if (mDisp->mMiniMarbleCounts[playerID] > idx) {
		mPane_mininodama[playerID][idx]->hide();
		mPane_minibedama[playerID][idx]->show();
		mPane_minibedama[playerID][idx]->updateScale(scale);
		if (!mMiniDamaGotFlags[playerID][idx]) {
			if (doEfx && mDoneState != 1) {
				ogSound->setBdamaGet();
				Vector2f pos;
				og::Screen::calcGlbCenter(mPane_minibedama[playerID][idx], &pos);

				efx2d::ArgScaleColorColor arg(&pos, 0.5f * mBedamaScale, 0xcfcf00ff, 0xe7e757ff);
				efx2d::T2DSprayset_forVS efx;
				efx.create(&arg);
			}
			mMinidamaScaleMgr[playerID][idx]->up();
		}
		mMiniDamaGotFlags[playerID][idx] = true;
	} else {
		mPane_minibedama[playerID][idx]->hide();
		mPane_mininodama[playerID][idx]->show();
		mPane_mininodama[playerID][idx]->updateScale(scale * 0.5f);
		mMiniDamaGotFlags[playerID][idx] = false;
	}

}

inline void FourObjVs::CheckBedamaWin(int playerID, bool doEfx, bool& isWin) {

	J2DPictureEx** bedamaPanes[] = { mPane_bedama1P, mPane_bedama2P, mPane_bedama3P, mPane_bedama4P };
	og::Screen::ScaleMgr** bedamaScaleMgr[] = { mScaleMgrP1_1, mScaleMgrP2_1, mScaleMgrP3_1, mScaleMgrP4_1 };

	bool hasAllBedamaFlags[] = { mHasAllBedamaP1, mHasAllBedamaP2, mHasAllBedamaP3, mHasAllBedamaP4 };

	if (hasAllBedamaFlags[playerID] && mBedamaGetTimers[playerID] > 0.0f) {
		mBedamaGetTimers[playerID] -= sys->mDeltaTime;
		if (mBedamaGetTimers[playerID] < 0.0f && doEfx) {
			ogSound->setBdamaGet();
			f32 scale = 0.6f;
			for (int i = 0; i < 4; i++) {
				bedamaScaleMgr[playerID][i]->up();
				Vector2f pos;
				og::Screen::calcGlbCenter(bedamaPanes[playerID][i], &pos);

				efx2d::ArgScale arg(&pos, scale);
				efx2d::T2DSensorGet_forVS efx;
				efx.create(&arg);
				isWin = true;
			}
		}
	}
}

void FourObjVs::setOnOffBdama4P(bool doEfx)
{
    bool P1win = false;
    bool P2win = false;
	bool P3win = false;
	bool P4win = false;

	for (int i = 0; i < 4; i++) {
        f32 p1ScaleYellow = mScaleMgrP1_1[i]->calc() * mBedamaScale;
		f32 p2ScaleYellow = mScaleMgrP2_1[i]->calc() * mBedamaScale;
		f32 p1ScaleColor = mScaleMgrP1_2[i]->calc()  * mBedamaScale;
		f32 p2ScaleColor = mScaleMgrP2_2[i]->calc()  * mBedamaScale;
		f32 p3ScaleYellow = mScaleMgrP3_1[i]->calc() * mBedamaScale;
		f32 p4ScaleYellow = mScaleMgrP4_1[i]->calc() * mBedamaScale;
		f32 p3ScaleColor = mScaleMgrP3_2[i]->calc()  * mBedamaScale;
		f32 p4ScaleColor = mScaleMgrP4_2[i]->calc()  * mBedamaScale;

		for (int player = 0; player < 4; player++) {
			CheckMiniBedama(i, player, doEfx, mMinidamaScaleMgr[player][i]->calc() * mBedamaScale);
		}

        mPane_windama1P[i]->updateScale(p1ScaleColor);
        mPane_windama2P[i]->updateScale(p2ScaleColor);
		mPane_windama3P[i]->updateScale(p3ScaleColor);
		mPane_windama4P[i]->updateScale(p4ScaleColor);

		CheckWindama(i, 0, doEfx, P1win);
		CheckWindama(i, 1, doEfx, P2win);
		CheckWindama(i, 2, doEfx, P3win);
		CheckWindama(i, 3, doEfx, P4win);

		if (!mFirstBedamaGetP1 && !mFirstBedamaGetP2 && !mFirstBedamaGetP3 && !mFirstBedamaGetP4) {

			CheckBedama(i, 0, doEfx, p1ScaleYellow, P1win);
			CheckBedama(i, 1, doEfx, p2ScaleYellow, P2win);
			CheckBedama(i, 2, doEfx, p3ScaleYellow, P3win);
			CheckBedama(i, 3, doEfx, p4ScaleYellow, P4win);
		}
	}

    CheckBedamaWin(0, doEfx, P1win);
	CheckBedamaWin(1, doEfx, P2win);
	CheckBedamaWin(2, doEfx, P3win);
	CheckBedamaWin(3, doEfx, P4win);
    

	if (!mPlayWinSound) {
		if (P1win && P2win && P3win && P4win && Game::gNaviNum == 4) {
			mPlayWinSound = true;
			ogSound->setVsDraw();
		} else if (P1win && P2win && P3win && Game::gNaviNum == 3) {
			mPlayWinSound = true;
			ogSound->setVsDraw();
		} else if (P1win && P2win && Game::gNaviNum == 2) {
			mPlayWinSound = true;
			ogSound->setVsDraw();
		} else if (P1win) {
			mPlayWinSound = true;
			ogSound->setVsWin1P();
		} else if (P3win) {
			mPlayWinSound = true;
			ogSound->setVsWin1P();
		}
		else if (P4win) {
			mPlayWinSound = true;
			ogSound->setVsWin1P();
		} else if (P2win) {
			mPlayWinSound = true;
			ogSound->setVsWin2P();
		}
	}
}

void FourObjVs::setOnOffBingo(bool doEfx) {

	if (FourObjVs::sFlickerDNE) {
		mDoesNotExistTimer -= sys->mDeltaTime;

		if (mDoesNotExistTimer < 0.0f) {
			mDoesNotExistTimer = 3.0f;
			mDoesNotExistActive = !mDoesNotExistActive;
			UpdateBingoCardTextures();
		}
	}

	
	for (int i = 0; i < 4; i++) {
		int team = Game::getVsTeam_s(i);
		Game::VsGame::BingoMgr::BingoCard& card = mDisp->mBingoMgr->mCards[team];
		Game::VsGame::BingoMgr::ObjectKey& key = mDisp->mBingoMgr->mKey;

		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {

				f32 scale = mBingoCards[i].mScaleMgrs[x][y]->calc();
				mBingoCards[i].mPaneBase[x][y]->updateScale(scale * mBedamaScale);
				mBingoCards[i].mPaneItem[x][y]->updateScale(scale * mBedamaScale);

				if (card.mDisp[x][y] && !mBingoCards[i].mFlags[x][y]) {
					mBingoCards[i].mFlags[x][y] = true;

					mBingoCards[i].mPaneBase[x][y]->changeTexture(mPaneBingoGet->getTIMG(0), 0);
					mBingoCards[i].mPaneBase[x][y]->setWhite(gBingoGetColors[team]);


					if (doEfx) {
						mBingoCards[i].mScaleMgrs[x][y]->up();
						og::ogSound->setSE(PSSE_SY_EQUIP_LADER);
					}
					
				}
			}
		}
	}

	if (mDisp->mBingoMgr->mDeathInformed && !FourObjVs::sFlickerDNE) {
		mDisp->mBingoMgr->mDeathInformed = false;
		UpdateBingoCardTextures();
	}
	

	if (!mPlayWinSound) {
		if (mDisp->mBingoMgr->mWinner != -1 && doEfx) {
			mPlayWinSound = true;
			ogSound->setVsWin1P();
			mDoneState = 1;
			setWinBingoBounce();
		}
	}
}

void FourObjVs::setWinBingoBounce() {
	DebugReport("FourObjVs::setWinBingoBounce()\n");
	int team = mDisp->mBingoMgr->mWinner;
	Game::VsGame::BingoMgr::BingoCard& card = mDisp->mBingoMgr->mCards[team];
	Game::VsGame::BingoMgr::ObjectKey& key = mDisp->mBingoMgr->mKey;
	
	Game::VsGame::BingoMgr::LineData lineData;
	bool found = card.CheckLine(4, lineData);

	if (!found) {
		return;
	}

	for (int player = 0; player < 4; player++) {
		if (Game::getVsTeam_s(player) != team) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int x = lineData.mXValues[i];
			int y = lineData.mYValues[i];
			mBingoCards[player].mScaleMgrs[x][y]->up();

			Vector2f pos;
			og::Screen::calcGlbCenter(mBingoCards[player].mPaneBase[x][y], &pos);
			const TColorPair& colors = gGetMarbleColors[team];
			efx2d::ArgScaleColorColor arg(&pos, 0.325f * mBedamaScale, colors[0], colors[1]);
			efx2d::T2DSprayset_forVS efx;
			efx.create(&arg);
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
    DebugReport("FourObjVs::setWinBedamaColor(int %i, int %i)\n", color, player);
    ScreenSet* screens[4] = { mScreenP1, mScreenP2, mScreenP3, mScreenP4 }; 

    J2DPictureEx** winDamaPanes[] = { mPane_windama1P, mPane_windama2P, mPane_windama3P, mPane_windama4P };

    

    u32 xoffs = 0;
    u32 yoffs = 0;
    J2DPane* root = screens[player]->mScreen->search('ROOT');
    J2DPictureEx** winDamas = winDamaPanes[player];

    mWinDamaColor[player] = color;


    for (int bedamaIdx = 0; bedamaIdx < 4; bedamaIdx++) {
		P2ASSERT(winDamas[bedamaIdx]);
		P2ASSERT(mColoredBedamaPanes[color]);
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
