#ifndef _PSSYSTEM_SYSIF_H
#define _PSSYSTEM_SYSIF_H

#include "types.h"
#include "Dolphin/os.h"
#include "JSystem/JAudio/JAI/JAIBasic.h"
#include "JSystem/JAudio/JAI/JAIStream.h"
#include "JSystem/JKernel/JKRDisposer.h"
#include "JSystem/JKernel/JKRFileLoader.h"
#include "PSGame/BASARC.h"
#include "JSystem/JMath.h"
#include "PSM/Se.h"
#include "PSSystem/SeqData.h"
#include "JSystem/JAudio/JAI/JAISequence.h"
#include "PSSystem/PSBgm.h"
#include "JSystem/JAudio/JAI/JAInter/SeMgr.h"
#include "PSSystem/SeqSound.h"
#include "PSSystem/PSStream.h"

namespace PSSystem {

u32 getObject(JASTrack* track, u8 p2);
void setObject(JASTrack* track, void* p2, u8 p3);

extern u8 sDistanceParameterMoveTime;
extern JMath::TRandom_fast_ oRandom;

struct SetupArg {
	JKRSolidHeap* mHeap; // _00
	u32 mHeapSize;       // _04
	int _08;             // _08
	void* _0C;           // _0C
	void* mAafFile;      // _10
	char* mPath;         // _14
};

typedef PSM::SeSound* (*MakeSeCallback)();

// fabricated
struct SysChecker {
	inline SysChecker()
	{
		OSInitMutex(&mMutex);
		mIsEnabled = 0;
	}

	OSMutex mMutex; // _00
	int mIsEnabled; // _18
};

struct FxMgr {
	FxMgr();
};

// Size: 0x4C
struct SysIF : public JAIBasic {
	SysIF(const SetupArg&);

	virtual JAISequence* makeSequence() // _08 (weak)
	{
		if (mHeap) {
			return new (mHeap, 0) SeqSound;
		}
		return new (JASDram, 0) SeqSound;
	}
	virtual JAISe* makeSe();        // _0C
	virtual JAIStream* makeStream() // _10 (weak)
	{
		if (mHeap) {
			return new (mHeap, 0) StreamSound;
		}
		return new (JASDram, 0) StreamSound;
	}
	virtual void initIF(const SetupArg&); // _28

	void stopSoundSystem();
	JAISe* playSystemSe(u32, u32);
	void playSystemSe(u32 soundID, JAISound** handles, u32 p3);
	void mainLoop();
	void setConfigVol_Se(f32);
	void setConfigVol_Bgm(f32);
	static void start1stSeq() { JAInter::SeMgr::seHandle = nullptr; }

	f32 mSfxVolume;      // _20
	f32 mBgmVolume;      // _24
	SysChecker mChecker; // _28
	FxMgr mFxMgr;        // _44
	u32 _48;             // _48

	static MakeSeCallback sMakeJAISeCallback;
};

template <typename T>
struct ArcMgr : public JKRDisposer {
	ArcMgr()
	{
		mArchive = nullptr;
		mArchive = JKRMountArchive("/AudioRes/Key.arc", JKRArchive::EMM_Mem, JKRGetCurrentHeap(), JKRArchive::EMD_Head);
		P2ASSERTLINE(92, mArchive);
	}

	static void createInstance()
	{
		P2ASSERTLINE(71, !sInstance);
		sInstance = new ArcMgr<T>;
		P2ASSERTLINE(74, sInstance);
	}

	virtual ~ArcMgr() // _08
	{
		P2ASSERTLINE(77, false); // lol
	}

	static ArcMgr* sInstance;

	// _00      = VTABLE
	// _04-_18  = JKRDisposer
	JKRArchive* mArchive; // _18
};

inline JKRFileLoader* getLoaderInstance()
{
	P2ASSERTLINE(80, PSSystem::ArcMgr<PSGame::BASARC>::sInstance);
	return PSSystem::ArcMgr<PSGame::BASARC>::sInstance->mArchive;
}

extern SysIF* spSysIF;
} // namespace PSSystem

inline PSSystem::SysIF* PSGetSystemIFA()
{
	P2ASSERTLINE(395, PSSystem::spSysIF);
	return PSSystem::spSysIF;
}

inline u32 isValidSeType(u32 soundID)
{
	u32 ass = (soundID >> 12) & 0xF;
	// problem here
	if ((soundID >> 30) == 0) {
		return ass;
	}

	if ((soundID >> 30) == 2) {
		P2ASSERTLINE(31, false);
	} else {
		P2ASSERTLINE(35, (soundID >> 30) != 3);
	}

	P2ASSERTLINE(37, false);
	return 0;
}

inline PSSystem::SysIF* PSGetSystemIF() { return PSSystem::spSysIF; }

#endif
