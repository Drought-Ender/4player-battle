#ifndef _KH_WINLOSE_H
#define _KH_WINLOSE_H

#include "og/Screen/DispMember.h"
#include "Screen/screenObj.h"
#include "P2DScreen.h"

struct JAISound;

enum WinLoseCondition { WinPlayer1 = 1, WinPlayer2 = 2, Draw = 3, Timeup1P = 4, Timeup2P = 5 };

namespace kh {
namespace Screen {
struct DispWinLose : public og::Screen::DispMemberBase {
	DispWinLose(int type, int state, int real[4], bool twoPlayer)
	{
		mOutcome = type;
		_0C      = state;
		for (int i = 0; i < 4; i++) {
			mNewOutcomes[i] = real[i];
		}
		mIsTwoPlayer = twoPlayer;
	}

	virtual u32 getSize() { return sizeof(DispWinLose); } // _08 (weak)
	virtual u32 getOwnerID() { return OWNER_KH; }         // _0C (weak)
	virtual u64 getMemberID() { return MEMBER_WIN_LOSE; } // _10 (weak)

	// _00     = VTBL
	// _00-_08 = DispMemberBase
	int mOutcome; // _08
	int _0C;      // _0C

	int mNewOutcomes[4];
	bool mIsTwoPlayer;
};

struct DispWinLoseFour : public og::Screen::DispMemberBase {
	DispWinLoseFour(int type[4], int state)
	{
		for (int i = 0; i < 4; i++) {
			mOutcomes[i] = type[i];
		}
		_0C      = state;
	}

	virtual u32 getSize() { return sizeof(DispWinLose); } // _08 (weak)
	virtual u32 getOwnerID() { return OWNER_KH; }         // _0C (weak)
	virtual u64 getMemberID() { return MEMBER_WIN_FOUR; } // _10 (weak)

	// _00     = VTBL
	// _00-_08 = DispMemberBase
	int mOutcomes[4]; // _08
	int _0C;          // _0C
};

struct DispWinLoseReason : public og::Screen::DispMemberBase {

	virtual u32 getSize() { return sizeof(DispWinLoseReason); }  // _08 (weak)
	virtual u32 getOwnerID() { return OWNER_KH; }                // _0C (weak)
	virtual u64 getMemberID() { return MEMBER_WIN_LOSE_REASON; } // _10 (weak)

	// _00     = VTBL
	// _00-_08 = DispMemberBase
	int mOutcomeNavis[4];
};

struct ObjWinLose : public ::Screen::ObjBase {
	ObjWinLose();

	virtual ~ObjWinLose() { }           // _08 (weak)
	virtual void doCreate(JKRArchive*); // _4C
	virtual bool doUpdate();            // _58
	virtual void doDraw(Graphics& gfx); // _68

	bool updateAnimation();

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_38 = Screen::ObjBase
	P2DScreen::Mgr_tuning* mScreenA[4]; // _38
	P2DScreen::Mgr_tuning* mScreenB[4]; // _40
	J2DAnmTransform* mAnim1[4];         // _48
	J2DAnmTransform* mAnim2[4];         // _50
	J2DAnmColor* mAnim3[4];             // _58
	J2DAnmColor* mAnim4[4];             // _60
	f32 mAnimTime1[4];                  // _68
	f32 mAnimTime2[4];                  // _70
	f32 mAnimTime3[4];                  // _78
	f32 mAnimTime4[4];                  // _80
	f32 mYOffset[4];                    // _88
	f32 mXOffset[4];
	bool mDoUpdateAnim;                 // _90
	int mFrameTimer;                    // _94
	int mScreenNum;                     // _98
	u8 mAlpha;                          // _9C

	static struct StaticValues {
		inline StaticValues()
		{
			mAnimSpeed   = 1.0f;
			mYOffsetP1   = -120.0f;
			mYOffsetP2   = 120.0f;
			mDuration    = 60.0f;
			mFinishFrame = 60;
			mEndBGMFrame = 180;
			mAlphaInc    = 16;
		}

		f32 mAnimSpeed;   // _00
		f32 mYOffsetP1;   // _04
		f32 mYOffsetP2;   // _08
		f32 mDuration;    // _0C
		int mFinishFrame; // _10
		int mEndBGMFrame; // _14
		u8 mAlphaInc;     // _18
	} msVal;
};

struct ObjWinLoseReason : public ::Screen::ObjBase {
	ObjWinLoseReason(int type)
	{
		mScreen = nullptr;
		mAnim1  = nullptr;
		mAnim2  = nullptr;
		_48     = 0.0f;
		_44     = 0.0f;
		_4C     = type;
	}

	virtual ~ObjWinLoseReason() { }     // _08 (weak)
	virtual void doCreate(JKRArchive*); // _4C
	virtual bool doUpdate();            // _58
	virtual void doDraw(Graphics& gfx); // _68

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_38 = Screen::ObjBase
	P2DScreen::Mgr_tuning* mScreen; // _38
	J2DAnmBase* mAnim1;             // _3C
	J2DAnmBase* mAnim2;             // _40
	f32 _44;                        // _44
	f32 _48;                        // _48
	u32 _4C;                        // _4C

	static struct StaticValues {
		inline StaticValues()
		{
			mAnimSpeed     = 1.0f;
			mYOffsetP1     = -120.0f;
			mYOffsetP2     = 120.0f;
			mProgressFrame = 100;
			mFinishFrame   = 125;
			_14            = 100;
			_18            = 2;
		}

		f32 mAnimSpeed; // _00
		f32 mYOffsetP1; // _04
		f32 mYOffsetP2; // _08
		int mProgressFrame;
		int mFinishFrame;
		int _14;
		u8 _18;
	} msVal;
};

struct ObjWinLoseTimeUp : public ObjWinLoseReason {
	ObjWinLoseTimeUp(int i) : ObjWinLoseReason(i) 
	{
	}
	
	virtual void doCreate(JKRArchive*);
	virtual bool doUpdate();            // _58
	virtual void doDraw(Graphics& gfx); // _68
};

struct SceneWinLose : public ::Screen::SceneBase {
	virtual const char* getResName() const { return "win_lose.szs"; } // _1C (weak)
	virtual SceneType getSceneType() { return SCENE_WIN_LOSE; }       // _08 (weak)
	virtual ScreenOwnerID getOwnerID() { return OWNER_KH; }           // _0C (weak)
	virtual ScreenMemberID getMemberID() { return MEMBER_WIN_LOSE; }  // _10 (weak)
	virtual void doCreateObj(JKRArchive* archive)                     // _20 (weak)
	{
		registObj(new ObjWinLose, archive);
	}

	// _00      = VTBL
	// _00-_220 = Screen::SceneBase
};

struct SceneWinLoseReason : public ::Screen::SceneBase {
	SceneWinLoseReason();

	virtual const char* getResName() const { return "win_lose_reason.szs"; }; // _1C (weak)
	virtual SceneType getSceneType() { return SCENE_WIN_LOSE_REASON; }        // _08 (weak)
	virtual ScreenOwnerID getOwnerID() { return OWNER_KH; }                   // _0C (weak)
	virtual ScreenMemberID getMemberID() { return MEMBER_WIN_LOSE_REASON; }   // _10 (weak)
	virtual void doCreateObj(JKRArchive*);                                    // _20
	virtual void doUpdateActive();                                            // _2C
	virtual bool doEnd(::Screen::EndSceneArg*);                               // _40

	// _00      = VTBL
	// _00-_220 = Screen::SceneBase
	::Screen::ObjBase* mScreenObj[4]; // _220
	int mOutcome[4];                  // _228
	bool mDone[4];
	int mCounter; // _234
};
} // namespace Screen
} // namespace kh

#endif
