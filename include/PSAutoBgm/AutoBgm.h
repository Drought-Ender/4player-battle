#ifndef _PSAUTOBGM_AUTOBGM_H
#define _PSAUTOBGM_AUTOBGM_H

#include "types.h"
#include "PSSystem/PSBgm.h"
#include "PSSystem/Seq.h"
#include "PSSystem/PSBgmTask.h"
#include "JSystem/JAudio/JAI/JAInter.h"
#include "PSAutoBgm/Conductor.h"
#include "PSAutoBgm/MeloArr.h"

namespace JADUtility {
} // namespace JADUtility

namespace PSAutoBgm {

struct AutoBgmSeqTrackRoot : public PSSystem::SeqTrackRoot_JumpBgm {
	AutoBgmSeqTrackRoot(ConductorMgr* mgr)
	    : PSSystem::SeqTrackRoot_JumpBgm(mJumpPort)
	{
		// mDataMgr = mgr;
		P2ASSERTLINE(755, mgr);
	}

	virtual u16 beatUpdate()
	{
		SeqTrackRoot::beatUpdate();
		P2ASSERTLINE(760, mJumpPort->_18);
	} // _14 (weak)

	// _00      = VTABLE
	// _04-_2C8 = SeqTrackRoot
};

/**
 * @size = 0x350
 */
struct AutoBgm : public PSSystem::DirectedBgm {
	AutoBgm(const char*, const char*, const JAInter::SoundInfo&, JADUtility::AccessMode, PSSystem::DirectorMgrBase*);

	virtual ~AutoBgm() { mHeap->free(mHeap, nullptr); }                                                   // _08 (weak)
	virtual void scene1st(PSSystem::TaskChecker*);                                                        // _10
	virtual void startSeq();                                                                              // _14
	virtual void pauseOn(PSSystem::SeqBase::PauseMode);                                                   // _1C
	virtual void pauseOff();                                                                              // _20
	virtual u8 getCastType() { return TYPE_AutoBgm; }                                                     // _24 (weak)
	virtual PSSystem::SeqTrackRoot* newSeqTrackRoot() { return new AutoBgmSeqTrackRoot(&mConductorMgr); } // _44 (weak)

	void loadConductor(PSSystem::TaskChecker*);
	void loadedCallback(u32, u32);

	void setPikiMaskNum(u8* cond)
	{
		u16 num = 0;
		for (u8 i = 0; i < 16; i++) {
			if (cond[i]) {
				num |= cond[i] << i;
			}
		}
		mMeloArr.mTrackMaskIds = num;
	}

	// _00-_10  = JSULink<SeqBase>
	// _10      = VTABLE
	// _14-_B8  = DirectedBgm
	ConductorMgr mConductorMgr;          // _B8
	char* mConductorFilePath;            // _330 (.cnd)
	PSSystem::TaskChecker* mTaskChecker; // _334
	JKRHeap* mHeap;                      // _338
	MeloArrMgr mMeloArr;                 // _33C
};


} // namespace PSAutoBgm

#endif
