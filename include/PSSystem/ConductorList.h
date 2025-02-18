#ifndef _PSGAME_CONDUCTORLIST_H
#define _PSGAME_CONDUCTORLIST_H

#include "types.h"
#include "stream.h"

namespace PSGame {
// as far as I can tell, should inherit one thing, then inherit
// PSSystem::SingletonBase<ConductorList> which is at _1C
struct ConductorList : public PSSystem::TextDataBase, public PSSystem::SingletonBase<ConductorList> {
	struct CaveInfo {
		CaveInfo()
		{
			mFileNameCount = 255;
			mFileNames     = nullptr;
		}

		u8 mFileNameCount; // _00, num file names in _04
		char* mFileNames;  // _04, array of file names
	};

	ConductorList();

	virtual ~ConductorList();         // _08 (weak)
	virtual bool read(Stream& input); // _0C
	// dtor thunk at _18, so something is getting smushed together here

	void getSeqAndWaveFromConductor(const char*, u8*, char**);

	// unused/inlined:
	char* getInfo(u8, u8);
	u8 getAutoBgmInfo(u8, u8);

	// _00 = VTBL
	u8 mCaveCount;        // _20
	CaveInfo* mCaveInfos; // _24

	static bool sToolMode;
};
} // namespace PSGame

#endif
