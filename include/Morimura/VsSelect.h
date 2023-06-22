#ifndef _MORIMURA_VSSELECT_H
#define _MORIMURA_VSSELECT_H

#include "Screen/Enums.h"
#include "og/Screen/ogScreen.h"
#include "og/Screen/callbackNodes.h"
#include "Morimura/Window.h"
#include "Morimura/mrUtil.h"
#include "Morimura/ScrollList.h"
#include "efx2d/T2DCountKira.h"
#include "og/Screen/callbackNodes.h"
#include "og/Screen/StickAnimMgr.h"

namespace Game {
struct Vs2D_TitleInfo;
} // namespace Game

namespace Morimura {
struct DispMemberVsSelect : public og::Screen::DispMemberBase {
	DispMemberVsSelect()
	{
		mTitleInfo            = nullptr;
		mDebugExpHeap         = nullptr;
		mDispWorldMapInfoWin0 = nullptr;
		mSelectedStageIndex   = -1;
		mStageNumber          = 0;
		mOlimarHandicap       = 3;
		mLouieHandicap        = 3;
		mRedWinCount          = 0;
		mBlueWinCount         = 0;
		mVsWinner             = -1;
		mStageCount           = 0;
		_34                   = 0;
	}

	virtual u32 getSize() { return sizeof(DispMemberVsSelect); } // _08
	virtual u32 getOwnerID() { return OWNER_MRMR; }              // _0C
	virtual u64 getMemberID() { return MEMBER_VS_SELECT; }       // _10

	// _00     = VTBL
	// _00-_08 = og::Screen::DispMemberBase
	Game::Vs2D_TitleInfo* mTitleInfo;                              // _08
	JKRHeap* mDebugExpHeap;                                        // _0C
	og::Screen::DispMemberWorldMapInfoWin0* mDispWorldMapInfoWin0; // _10
	int mSelectedStageIndex;                                       // _14
	int mStageNumber;                                              // _18
	int mOlimarHandicap;                                           // _1C
	int mLouieHandicap;                                            // _20
	int mRedWinCount;                                              // _24
	int mBlueWinCount;                                             // _28
	int mVsWinner;                                                 // _2C
	int mStageCount;                                               // _30
	int _34;                                                       // _34
};

struct TVsSelectCBWinNum : public og::Screen::CallBack_CounterDay {
	inline TVsSelectCBWinNum(JKRArchive* rarc) : og::Screen::CallBack_CounterDay(const_cast<char**>(og::Screen::SujiTex32), 4, rarc)
	, _AC(0)
	, mScaleMgr(nullptr)
	{
		mScaleMgr = new og::Screen::ScaleMgr;
	}
	virtual ~TVsSelectCBWinNum();      // _08 (weak)
	virtual void update();             // _10
	virtual void setValue(bool, bool); // _28

	// _00     = VTBL
	// _00-_AC = og::Screen::CallBack_CounterDay
	u8 _AC;                          // _AC
	og::Screen::ScaleMgr* mScaleMgr; // _B0
};

struct TVsSelectExplanationWindow : public TSelectExplanationWindow {
	virtual void create(const char*, u32); // _08
	virtual void screenScaleUp();          // _14

	// _00     = VTBL
	// _00-_30 = TSelectExplanationWindow
};

struct TVsSelectIndPane : public TIndPane {
	virtual ~TVsSelectIndPane(); // _08 (weak)
	virtual void draw();         // _10

	// _00     = VTBL
	// _00-_18 = TIndPane
	JUTTexture* _18; // _18
	JUTTexture* _1C; // _1C
	u8 _20[0x14];    // _20, unknown
	f32 _34;         // _34
	f32 _38;         // _38
	s16 _3C;         // _3C
	f32 _40;         // _40
};

struct TVsSelectListScreen : public TListScreen {
	virtual void create(const char*, u32); // _08 (weak)
	virtual void update();                 // _0C (weak)

	// _00     = VTBL
	// _00-_18 = TScreenBase
};

struct TVsSelectScreen : public TScreenBase {
	virtual void create(const char*, u32); // _08

	// _00     = VTBL
	// _00-_18 = TScreenBase
	TCallbackScissor* mCallbackScissor; // _18
};

struct TVsSelectScene : public THIOScene {
	TVsSelectScene() { mConfirmEndWindow = nullptr; }
	virtual SceneType getSceneType() { return SCENE_VS_SELECT; }          // _08 (weak)
	virtual ScreenOwnerID getOwnerID() { return OWNER_MRMR; }             // _0C (weak)
	virtual ScreenMemberID getMemberID() { return MEMBER_VS_SELECT; }     // _10 (weak)
	virtual const char* getResName() const { return "res_vsSelect.szs"; } // _1C (weak)
	virtual void doCreateObj(JKRArchive*);                                // _20
	virtual bool doStart(Screen::StartSceneArg*);                         // _3C

	// _00      = VTBL
	// _00-_224 = THIOScene
	// _220, treat as TVsSelect
	TConfirmEndWindow* mConfirmEndWindow; // _224
};

struct TVsPiki;

struct TVsSelect : public TScrollList {
	TVsSelect();

	virtual ~TVsSelect() { }                                 // _08 (weak)
	virtual void doCreate(JKRArchive*);                      // _4C
	virtual void doUpdateFadeinFinish();                     // _54
	virtual bool doUpdate();                                 // _58
	virtual void doUpdateFadeoutFinish();                    // _64
	virtual void doDraw(Graphics& gfx);                      // _68
	virtual og::Screen::DispMemberBase* getDispMemberBase(); // _78 (weak)
	virtual void paneInit();                                 // _80
	virtual void changePaneInfo();                           // _84
	virtual int getIdMax();                                  // _88 (weak)
	virtual u64 getNameID(int);                              // _8C
	virtual void setShortenIndex(int, int, bool);            // _94

	void getCourseID(int);
	void doZoom();
	void doMoveOnyon();
	void doScreenEffect();
	void onyonDemoInit();
	void demoStart();
	void changeCourseTexture();
	void changeIndirectTexture();
	void updateFacePicture();
	void changeFaceTexture();
	void changeOrimaTexture(int);
	void changeLouieTexture(int);
	void changeSlotPage();

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_B4 = TScrollList
	JKRArchive* _B4;
	Controller* mController2;
	TVsSelectScreen* _BC;
	TScreenBase* _C0;
	TScreenBase* _C4;
	TScreenBase* _C8;
	TScreenBase* _CC;
	TScreenBase* _D0;
	TVsSelectExplanationWindow* _D4;
	TVsSelectIndPane* _d8;
	J2DPane* _DC;

	J2DPane* _E0;
	J2DPane* _E4;
	J2DPane* _E8;
	J2DPane* _EC;
	J2DPane* _F0;
	J2DPane* _F4[3];
	J2DPane* _100;
	J2DPane* _104;
	J2DPane* _108[2];
	J2DPane* _110;
	J2DPane* _114[6];
	J2DPane* _12C[5];
	J2DPane* _140[5];
	J2DPane* _154;
	J2DPane* _158;
	J2DPane* _15C;

	J2DPane* mOrimaPikiIcon;
	J2DPane* mPbor0;
	J2DPane* mPbor1;
	J2DPane* _16C;
	J2DPane* _170;
	J2DPane* _174;
	J2DPane* mLoozyPikiIcon;
	J2DPane* mPblo0;
	J2DPane* mPblo1;
	u8 _184[0x30];
	J2DPane* _1B4[6];
	J2DPane* _1CC[6];
	J2DPictureEx* _1E4;
	unknown* _1E8[2];
	TVsPiki* _1F0[2];
	DispMemberVsSelect* _1F8;
	TOffsetMsgSet* _1FC;
	efx2d::T2DCountKira* _200;
	og::Screen::CallBack_Picture* _204;
	og::Screen::StickAnimMgr* _208;
	og::Screen::ArrowAlphaBlink* _20C;
	TVsSelectCBWinNum* mWinCounts[2];
	u8 _214[0x10];
	u8 _228;
	u8 _229;
	u8 _22A;
	u8 _22B;
	u8 _22C;
	u8 _22D;
	u8 _22E;
	u8 _22F;
	f32 _230;
	f32 _234;
	f32 _238;
	u8 _23C;
	u8 _23D;
	u8 _23E[2];
	int _240;
	int _244;
	int mStageCount;
	int _24C;
	f32 _250;
	f32 _254;
	f32 _258;
	f32 _25C;
	f32 _260;
	f32 _264;
	f32 _268;
	f32 _26C;
	f32 _270;
	int _274;
	int _278;
	u32 _27C;
	u32 _280;
	u32 _284;
	u32 _288;
	u8 _28C;
	u8 _28D;
	u8 _28E[2];
	f32 _290;
	f32 _294;
	f32 _298;
	f32 _29C;
	f32 _2A0;
	f32 _2A4;
	Vector2f _2A8[5];
	Vector2f _2D0[5];
	Vector2f _2F8[2];
	Vector2f _308[2];
	f32 _318;
	f32 _31C;
	u8 _320[8];
	ResTIMG** mLevelTextures;
};

struct TFourVsSelect : public TVsSelect
{
	virtual void doCreate(JKRArchive*);
	virtual bool doUpdate();

	J2DPictureEx* mNaviImages[4];
	J2DPictureEx* mNaviBoxes[4];

	J2DTextBoxEx* mNaviNames[4];
	TVsSelectCBWinNum* mNewWinCounts[4];
	J2DPictureEx* mWinBoxes[4];

	u32 mNewWinValues[4];

	Vector2f mNaviBasePos[4];

	int mTeamIDs[4];
};


} // namespace Morimura

#endif
