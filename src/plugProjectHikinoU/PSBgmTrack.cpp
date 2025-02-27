#include "JSystem/JUtility/JUTException.h"
#include "PSSystem/SeqTrack.h"

namespace PSSystem {

/*
 * --INFO--
 * Address:	803422A8
 * Size:	00002C
 */
void BeatMgr::proc()
{
	if (_00 & 0x40) {
		_00 &= 1;
	} else if (_00 & 0x80) {
		_00 |= 0x40;
	}
}

/*
 * --INFO--
 * Address:	803422D4
 * Size:	000028
 */
bool SeqTrackBase::update()
{
	mTaskEntryMgr.update();
	return false;
}

/*
 * --INFO--
 * Address:	803422FC
 * Size:	000008
 */
void SeqTrackBase::init(JASTrack* track) { mTaskEntryMgr._24 = track; }

/*
 * --INFO--
 * Address:	80342304
 * Size:	000008
 */
TaskEntryMgr* SeqTrackBase::getTaskEntryList() { return &mTaskEntryMgr; }

/*
 * --INFO--
 * Address:	8034230C
 * Size:	0003A4
 * __ct__Q28PSSystem12SeqTrackRootFv
 */
SeqTrackRoot::SeqTrackRoot()
    : _34(2.0f)
    , _38(0)
    , mBeatInterval(60)
    , _100(2)
{
}

/*
 * --INFO--
 * Address:	803426B0
 * Size:	000078
 */
void SeqTrackRoot::init(JASTrack* track)
{
	P2ASSERTLINE(229, track != nullptr);
	mTaskEntryMgr._24 = track;
	_2C               = track->_352;
	_2E               = _2C;
	mBeatMgr._00      = 0;
	initSwingRatio();
}

/*
 * --INFO--
 * Address:	80342728
 * Size:	00007C
 */
void SeqTrackRoot::initSwingRatio()
{
	_32 = _2C * (_34 + 1.0f) / 2;
	_30 = _32 / _34;
}

/*
 * --INFO--
 * Address:	803427A4
 * Size:	000088
 */
void SeqTrackRoot::pitchModulation(float f1, float f2, u32 arg, PSSystem::DirectorBase* base)
{
	mTaskEntryMgr.removeEntry(&_16C);
	_16C.makeEntry(f1, f2, arg);
	mTaskEntryMgr.appendEntry(&_16C, base);
}

/*
 * --INFO--
 * Address:	8034282C
 * Size:	000078
 */
void SeqTrackRoot::tempoChange(float tempo, u32 arg, PSSystem::DirectorBase* base)
{
	mTaskEntryMgr.removeEntry(&_40);
	_40.makeEntry(tempo, arg);
	mTaskEntryMgr.appendEntry(&_40, base);
}

/*
 * --INFO--
 * Address:	803428A4
 * Size:	000024
 */
void SeqTrackRoot::onStopSeq() { mTaskEntryMgr.removeAllEntry(); }

/*
 * --INFO--
 * Address:	803428C8
 * Size:	00009C
 */
u16 SeqTrackRoot::beatUpdate()
{
	mBeatMgr._00 = (mBeatMgr._00 & 1 ^ 1) & 0x00FF | 0x80;
	if (_38 == 1) {
		if (mBeatMgr._00 & 1) {
			_2E = _30;
		} else {
			_2E = _32;
		}
	} else {
		_2E = _2C;
	}
	mTaskEntryMgr._24->setTempo(_2E);
	onBeatTop();
	return mBeatInterval;
}

/*
 * --INFO--
 * Address:	80342964
 * Size:	0002EC
 * __ct__Q28PSSystem13SeqTrackChildFRCQ28PSSystem12SeqTrackRoot
 */
SeqTrackChild::SeqTrackChild(const PSSystem::SeqTrackRoot&)
    : _1B8(1)
{
}

/*
 * --INFO--
 * Address:	80342C50
 * Size:	000084
 */
void SeqTrackChild::muteOffAndFadeIn(float arg1, u32 arg2, PSSystem::DirectorBase* base)
{
	mTaskEntryMgr.removeEntry(&_2C);
	mTaskEntryMgr.removeEntry(&_12C);
	_2C.makeEntry(arg1, arg2);
	mTaskEntryMgr.appendEntry(&_2C, base);
}

/*
 * --INFO--
 * Address:	80342CD4
 * Size:	000074
 */
void SeqTrackChild::fadeoutAndMute(u32 arg, PSSystem::DirectorBase* base)
{
	mTaskEntryMgr.removeEntry(&_2C);
	mTaskEntryMgr.removeEntry(&_12C);
	_12C.makeEntry(arg);
	mTaskEntryMgr.appendEntry(&_12C, base);
}

/*
 * --INFO--
 * Address:	80342D48
 * Size:	000078
 */
void SeqTrackChild::fade(float arg1, u32 arg2, PSSystem::DirectorBase* base)
{
	mTaskEntryMgr.removeEntry(&_1B8);
	_1B8.makeEntry(arg1, arg2);
	mTaskEntryMgr.appendEntry(&_1B8, base);
}

/*
 * --INFO--
 * Address:	80342DC0
 * Size:	000068
 */
void SeqTrackChild::setIdMask(u8 mask, PSSystem::DirectorBase* base)
{
	mTaskEntryMgr.removeEntry(&_224);
	_224.makeEntry(mask);
	mTaskEntryMgr.appendEntry(&_224, base);
}

/*
 * --INFO--
 * Address:	80342E28
 * Size:	000024
 */
void SeqTrackChild::onStopSeq() { mTaskEntryMgr.removeAllEntry(); }
} // namespace PSSystem
