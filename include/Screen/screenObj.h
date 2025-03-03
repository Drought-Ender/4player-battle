#ifndef _SCREEN_BASES_H
#define _SCREEN_BASES_H

#include "Dolphin/gx.h"
#include "Dolphin/stl.h"
#include "JSystem/JKernel/JKRDisposer.h"
#include "JSystem/JUtility/TColor.h"
#include "Resource.h"
#include "Screen/Enums.h"
#include "og/Screen/DispMember.h"
#include "Screen/SceneInfoList.h"
#include "Graphics.h"

struct Controller;
struct Graphics;
struct JKRArchive;
struct JKRSolidHeap;

namespace og {
namespace Screen {
struct DispMemberBase;
}
} // namespace og

namespace Resource {
struct MgrCommand;
} // namespace Resource

namespace Screen {
struct IObjBase;
struct ObjBase;
struct ObjMgrBase;
struct Mgr;

struct MgrCommand : public CNode {
	virtual ~MgrCommand(); // _08 (weak)

	// _00     = VTBL
	// _00-_18 = CNode
};

struct SceneArgBase {
	virtual SceneType getSceneType() const; // _08 (weak)
	virtual int getClassSize() = 0;         // _0C

	// _00 = VTBL
};

// this has nothing in it aside from a vtable - if you need members, cast to the appropriate downstream type.
struct StartSceneArg : public SceneArgBase {
	// _00 = VTBL
};

template <typename T>
struct StartSceneArgTemplate : public StartSceneArg {
	virtual int getClassSize() { return sizeof(StartSceneArgTemplate); } // _08 (weak)

	// _00     = VTBL
	// _00-_04 = StartSceneArg
	SceneType mSceneType; // _04
	bool mFlag;           // _08, unknown
};

struct SetSceneArg : public SceneArgBase {
	inline SetSceneArg(SceneType sceneType, og::Screen::DispMemberBase* dispMember, bool a, bool b)
	    : mSceneType(sceneType)
	    , mDispMember(dispMember)
	    , _08(a)
	    , _09(b)
	{
	}

	inline SetSceneArg(SceneType sceneType, og::Screen::DispMemberBase* dispMember)
	    : mSceneType(sceneType)
	    , mDispMember(dispMember)
	    , _08(0)
	    , _09(true)
	{
	}

	virtual SceneType getSceneType() const { return mSceneType; } // _08
	virtual int getClassSize() { return sizeof(SetSceneArg); }    // _0C

	// _00 = VTBL
	SceneType mSceneType;                    // _04
	u8 _08;                                  // _08
	bool _09;                    // _09
	og::Screen::DispMemberBase* mDispMember; // _0C
};

struct EndSceneArg : public SceneArgBase {
	virtual int getClassSize() { return sizeof(EndSceneArg); } // _0C (weak)

	// _00 = VTBL
	u8 _04; // _04
};

struct SceneBase {
	enum StateID {
		SB_Finished3           = -3,
		SB_Finished2           = -2,
		SB_Finished1           = -1,
		SB_Unknown0            = 0,
		SB_WaitForResourceSync = 1,
		SB_Unknown2            = 2,
		SB_Started             = 3,
		SB_Unknown4            = 4,
		SB_Unknown5            = 5,
		SB_Unknown6            = 6,
		SB_Unknown7            = 7,
	};

	SceneBase();
	~SceneBase();

	virtual SceneType getSceneType()     = 0;                          // _08
	virtual ScreenOwnerID getOwnerID()   = 0;                          // _0C
	virtual ScreenMemberID getMemberID() = 0;                          // _10
	virtual bool isUseBackupSceneInfo() { return false; }              // _14 (weak)
	virtual bool isDrawInDemo() const { return true; }                 // _18 (weak)
	virtual const char* getResName() const = 0;                        // _1C
	virtual void doCreateObj(JKRArchive*)  = 0;                        // _20
	virtual void doUserCallBackFunc(Resource::MgrCommand*) { }         // _24 (weak)
	virtual void setPort(Graphics& gfx) { gfx.mPerspGraph.setPort(); } // _28 (weak)
	virtual void doUpdateActive();                                     // _2C
	virtual bool doConfirmSetScene(SetSceneArg&) { return true; }      // _30 (weak)
	virtual bool doConfirmStartScene(StartSceneArg*) { return true; }  // _34 (weak)
	virtual bool doConfirmEndScene(EndSceneArg*&) { return true; }     // _38 (weak)
	virtual bool doStart(StartSceneArg*);                              // _3C
	virtual bool doEnd(EndSceneArg*);                                  // _40
	virtual bool setDefaultDispMember()                                // _44 (weak)
	{
		og::Screen::DispMemberDummy disp;
		memcpy(mDispMember, (void*)&disp, sizeof(disp));
		return true;
	}
	virtual void doSetBackupScene(SetSceneArg&) { } // _48 (weak)
	virtual int doGetFinishState() { return -3; }   // _4C (weak)

	bool confirmEndScene(EndSceneArg*);
	bool confirmSetScene(SetSceneArg&);
	bool confirmStartScene(StartSceneArg*);
	void create();
	void createObj(JKRArchive*);
	void destroy();
	void draw(Graphics&);
	bool end(EndSceneArg*);
	void endScene(EndSceneArg*);
	int getFinishState();
	Controller* getGamePad() const;
	void registObj(ObjBase*, JKRArchive*);
	IObjBase* searchObj(char*);
	bool setBackupScene();
	void setColorBG(u8, u8, u8, u8);
	bool setScene(SetSceneArg&);
	bool setDispMember(og::Screen::DispMemberBase*);
	bool start(StartSceneArg*);
	bool startScene(StartSceneArg*);
	void update();
	bool updateActive();
	void userCallBackFunc(Resource::MgrCommand*);

	inline og::Screen::DispMemberBase* getDispMember() { return mDispMember; }

	// Unused/inlined:
	u32 getBackupSceneType();
	void setBGMode(int);

	inline Mgr* getScreenMgr() { return mScreenMgr; }


	// _00 = VTBL
	char mName[256];                                  // _004
	Controller* mController;                          // _104
	Mgr* mScreenMgr;                                  // _108
	Delegate1<SceneBase, Resource::MgrCommand*> _10C; // _10C
	int mStateID;                                     // _120
	f32 mSomeTime;                                    // _124
	Resource::MgrCommand mCommand;                    // _128
	ObjMgrBase* mObjMgr;                              // _218
	og::Screen::DispMemberBase* mDispMember;          // _21C
};

struct IObjBase : public CNode, public JKRDisposer {
	IObjBase()
	    : CNode("No Name")
	{
	}

	// vtable 2
	virtual ~IObjBase() { CNode::del(); }               // _08 (weak)
	virtual bool update()                          = 0; // _1C
	virtual void draw(Graphics&)                   = 0; // _20
	virtual bool start(const StartSceneArg*)       = 0; // _24
	virtual bool end(const EndSceneArg*)           = 0; // _28
	virtual void setOwner(SceneBase*)              = 0; // _2C
	virtual SceneBase* getOwner() const            = 0; // _30
	virtual void create(JKRArchive*)               = 0; // _34
	virtual bool confirmSetScene(SetSceneArg&)     = 0; // _38
	virtual bool confirmStartScene(StartSceneArg*) = 0; // _3C
	virtual bool confirmEndScene(EndSceneArg*)     = 0; // _40

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_18 = CNode
	// _18-_30 = JKRDisposer
};

struct ObjBase : public IObjBase {
	ObjBase();

	// vtable 2
	virtual ~ObjBase() { }                     // _08 (weak)
	virtual bool update();                     // _1C
	virtual void draw(Graphics&);              // _20
	virtual bool start(const StartSceneArg*);  // _24
	virtual bool end(const EndSceneArg*);      // _28
	virtual void setOwner(SceneBase* newOwner) // _2C (weak)
	{
		P2ASSERTLINE(129, !mOwner);
		mOwner = newOwner;
	}
	virtual SceneBase* getOwner() const { return mOwner; }            // _30 (weak)
	virtual void create(JKRArchive*);                                 // _34
	virtual bool confirmSetScene(SetSceneArg&);                       // _38
	virtual bool confirmStartScene(StartSceneArg*);                   // _3C
	virtual bool confirmEndScene(EndSceneArg*);                       // _40
	virtual bool doStart(const StartSceneArg*) { return true; }       // _44 (weak)
	virtual bool doEnd(const EndSceneArg*) { return true; }           // _48 (weak)
	virtual void doCreate(JKRArchive*) { }                            // _4C (weak)
	virtual bool doUpdateFadein() { return true; }                    // _50 (weak)
	virtual void doUpdateFadeinFinish() { }                           // _54 (weak)
	virtual bool doUpdate() { return false; }                         // _58 (weak)
	virtual void doUpdateFinish() { }                                 // _5C (weak)
	virtual bool doUpdateFadeout() { return true; }                   // _60 (weak)
	virtual void doUpdateFadeoutFinish() { }                          // _64 (weak)
	virtual void doDraw(Graphics& gfx);                               // _68
	virtual bool doConfirmSetScene(SetSceneArg&) { return true; }     // _6C (weak)
	virtual bool doConfirmStartScene(StartSceneArg*) { return true; } // _70 (weak)
	virtual bool doConfirmEndScene(EndSceneArg*&) { return true; }    // _74 (weak)

	og::Screen::DispMemberBase* getDispMember();
	Controller* getGamePad() const;

	// _00     = VTBL1
	// _18     = VTBL2
	// _00-_30 = IObjBase
	int _30;           // _30
	SceneBase* mOwner; // _34
};

struct ObjMgrBase {
	ObjMgrBase();

	bool confirmSetScene(SetSceneArg&);
	bool confirmStartScene(StartSceneArg*);
	bool confirmEndScene(EndSceneArg*);
	void draw(Graphics&);
	void registObj(IObjBase*, SceneBase*);
	IObjBase* search(SceneBase*, char*);

	bool start(StartSceneArg*);
	bool update();
	bool end(EndSceneArg*);

	CNode _00; // _00
};
} // namespace Screen

#endif
