#ifndef _EBI_SCREEN_TOMAKE_H
#define _EBI_SCREEN_TOMAKE_H

#include "ebi/E2DCallBack.h"
#include "ebi/Screen/TScreenBase.h"
#include "ebi/Utility.h"
#include "P2DScreen.h"
#include "types.h"

namespace ebi {
namespace Screen {

// TODO: Data members.
struct TOmake : public TScreenBase {
	TOmake();

	~TOmake();

	virtual void doSetArchive(JKRArchive*); // _24
	virtual void doOpenScreen(ArgOpen*);    // _28
	virtual void doCloseScreen(ArgClose*);  // _2C
	virtual void doInitWaitState();         // _34
	virtual bool doUpdateStateOpen();       // _38
	virtual bool doUpdateStateWait();       // _3C
	virtual bool doUpdateStateClose();      // _40
	virtual void doDraw();                  // _44
	virtual char* getName();                // _48

	void setController(Controller*);
	void showPanes_() const;
	void hidePanes_() const;
	void openFromMovie_() const;
	void openFromCardE_() const;

	// _00     = VTBL
	// _00-_08 = TScreenBase
	int mState2;                          // _0C
	EUTPadInterface_countNum mInput;      // _10
	int mCurrSel;                         // _3C
	Controller* mController;              // _40
	JUtility::TColor mColor1;             // _44
	u8 mAlpha;                            // _48
	int mState;                           // _4C
	u32 mCounter;                         // _50
	int _54;                              // _54
	P2DScreen::Mgr_tuning* mScreenMain;   // _58
	J2DPane* mPaneWindow;                 // _5C
	J2DPane* mPaneTitle;                  // _60
	J2DPane* mPaneAButton;                // _64
	J2DPane* mPaneBButton;                // _68
	J2DPane* mPaneList1[7];               // _6C
	J2DPane* mPaneSelect;                 // _88
	J2DPane* mPaneList2[7];               // _8C
	J2DPane* mPaneList3[7];               // _A8
	J2DPane* mPaneList4[7];               // _C4
	E2DCallBack_AnmBase mAnims[3];        // _E0
	bool _194;                            // _194
	JGeometry::TBox2f mBox1;              // _198
	JGeometry::TBox2f mBox2;              // _1A8
	int _1B8;                             // _1B8
	int _1BC;                             // _1BC
	og::Screen::ScaleMgr mScalemgr;       // _1C0
	f32 _1DC;                             // _1DC
	J2DPane* _1E0;                        // _1E0
	E2DCallBack_BlinkFontColor mFonts[7]; // _1E4
	u64 mMesgTags[7];                     // _3F8
	JUtility::TColor mColors[12];         // _430
};

// TODO: Data members.
struct TOmakeCardE : public TScreenBase {
	TOmakeCardE();
	~TOmakeCardE() { }

	enum CardEState { MainMenu, InZoomed, ExitingZoomed, EnteringZoomed };

	virtual void doSetArchive(JKRArchive*);           // _24
	virtual void doOpenScreen(ArgOpen*);              // _28
	virtual void doCloseScreen(ArgClose*);            // _2C
	virtual void doInitWaitState();                   // _34
	virtual bool doUpdateStateOpen();                 // _38
	virtual bool doUpdateStateWait();                 // _3C
	virtual bool doUpdateStateClose();                // _40
	virtual void doDraw();                            // _44
	virtual char* getName() { return "TOmakeCardE"; } // _48

	// _00     = VTBL
	// _00-_0C = TScreenBase
	Controller* mInput;                        // _0C
	bool mExitState;                           // _10 (false when press A to continue, true when press B to exit)
	P2DScreen::Mgr_tuning* mScreenObj;         // _14
	J2DPane* mPaneArrowUp;                     // _18
	J2DPane* mPaneArrowDown;                   // _1C
	E2DCallBack_AnmBase mAnimationEnter;       // _20
	E2DCallBack_AnmBase mAnimationIdle;        // _5C
	E2DCallBack_AnmBase mAnimationExit;        // _98
	E2DCallBack_AnmBase mAnimationChange;      // _D4
	E2DCallBack_AnmBase mAnimationColor;       // _110
	E2DCallBack_CalcAnimation mAnimCalc;       // _14C
	void* mMesgScroll; // _16C
	int mState;                                // _170
};


// TODO: Data members.
struct TOmakeGame : public TScreenBase {
	TOmakeGame();
	~TOmakeGame();

	virtual void doSetArchive(JKRArchive*); // _24
	virtual void doOpenScreen(ArgOpen*);    // _28
	virtual void doCloseScreen(ArgClose*);  // _2C
	virtual bool doUpdateStateOpen();       // _38
	virtual bool doUpdateStateWait();       // _3C
	virtual bool doUpdateStateClose();      // _40
	virtual void doDraw();                  // _44
	virtual char* getName();                // _48

	bool isDelegateControl();
	bool openMsg(long);
	void setController(Controller*);
	void setSelfControl();

	// _00     = VTBL
	// _00-_08 = TScreenBase
	u8 _0C[0x2A8];
};
} // namespace Screen
} // namespace ebi

#endif
