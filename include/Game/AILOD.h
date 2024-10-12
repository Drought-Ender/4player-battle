#ifndef _GAME_AILOD_H
#define _GAME_AILOD_H

#include "types.h"

#define AILOD_FLAG_NONE        (0x0)
#define AILOD_FLAG_IS_MID      (0x01)
#define AILOD_FLAG_IS_FAR      (0x02)
#define AILOD_FLAG_NEED_SHADOW (0x04)
#define AILOD_FLAG_UNKNOWN4    (0x08)
#define AILOD_FLAG_VISIBLE_VP0 (0x10) // Is it visible on viewport 0? etc.
#define AILOD_FLAG_VISIBLE_VP1 (0x20)
#define AILOD_FLAG_VISIBLE_VP2 (0x40)
#define AILOD_FLAG_VISIBLE_VP3 (0x80)



enum AILODFlags {
	AILOD_NULL       = 0x0,
	AILOD_IsMid      = 0x1,  // is in mid-ground camera
	AILOD_IsFar      = 0x2,  // is in far-ground camera
	AILOD_IsVisible  = 0x4,  // is marked as visible
	AILOD_PikiInCell = 0x8,  // is at least 1 piki in its cell
	AILOD_IsVisVP0   = 0x10, // is visible in viewport 0
	AILOD_IsVisVP1   = 0x20, // is visible in viewport 1
	AILOD_IsVisVP2   = 0x40, // is visible in viewport 2
	AILOD_IsVisVP3   = 0x80, // is visible in viewport 3

	AILOD_IsVisibleBoth = AILOD_IsVisible | AILOD_IsVisVP0 | AILOD_IsVisVP1, // set visible for both main viewports
};


namespace Game {
struct AILODParm {
	AILODParm();

	f32 mFar;         // _00
	f32 mClose;       // _04
	bool mIsCylinder; // _08
};

struct AILOD {
	AILOD();

	inline int isFlag(u32 flag) const { return mFlags & flag; }
	inline void setFlag(u32 flag) { mFlags |= flag; }
	inline void resetFlag(u32 flag) { mFlags &= ~flag; }
	inline int isVPVisible(u32 vpNum) const { return mFlags & (0x10 << vpNum); }
	inline void setVPVisible(u32 vpNum) { mFlags |= (0x10 << vpNum); }


	u8 mFlags;   // _00
	s8 mSoundVPID; // _01, sound viewport ID

	static bool drawInfo;
};
} // namespace Game

#endif
