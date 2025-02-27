#ifndef _PSSYSTEM_SEQDATA_H
#define _PSSYSTEM_SEQDATA_H

#include "types.h"
#include "JSystem/JKernel/JKRDisposer.h"
#include "JSystem/JKernel/JKRDvdRipper.h"
#include "PSSystem/SingletonBase.h"

struct Stream;

namespace PSSystem {

/**
 * @size = 0x1C
 */
struct TextDataBase : public JKRDisposer {
	TextDataBase();

	virtual ~TextDataBase();        // _08
	virtual bool read(Stream&) = 0; // _0C

	bool load(const char*, JKRDvdRipper::EAllocDirection);
	bool onlyLoad(const char*, JKRDvdRipper::EAllocDirection);

	// _00      = VTABLE
	// _04-_1C  = JKRDisposer
	uint _18; // _18
};

/**
 * @size = 0x20
 */
struct SeqDataList : public TextDataBase {
	SeqDataList();

	virtual ~SeqDataList();     // _08 (weak)
	virtual bool read(Stream&); // _0C
	// virtual void _10() = 0;      // _10 - possibly
	// virtual void _14() = 0;      // _14 - possibly

	// _00      = VTABLE
	// _04-_1C  = TextDataBase
	SingletonBase<SeqDataList> _1C; // _1C
};

} // namespace PSSystem

#endif
