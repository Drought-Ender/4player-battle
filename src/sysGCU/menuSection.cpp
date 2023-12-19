#include "JSystem/JKernel/JKRHeap.h"
#include "RootMenuSection.h"
#include "System.h"
#include "GameFlow.h"
#include "FourPlayer.h"
#include "VsSlotCard.h"
#include "VsOptions.h"

#include "types.h"
#include "GameFlow.h"
#include "BootSection.h"
#include "Demo.h"
#include "Game/SingleGameSection.h"
#include "Game/VsGameSection.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTException.h"
#include "RootMenuSection.h"
#include "Title.h"
#include "nans.h"

/*
 * --INFO--
 * Address:	804245CC
 * Size:	000048
 */
MenuSection::MenuSection(JFWDisplay* display, JKRHeap* heap, bool b)
    : Section(display, heap, b)
{
	mCurrentSection = nullptr;
	_3C             = false;
}

/*
 * --INFO--
 * Address:	80424614
 * Size:	000054
 */
void MenuSection::run()
{
	Game::VsGame::VsSlotCardMgr::initAllCards();
	Option::SetDefaults();
	CharacterData::initDefaults();
	
	_3C = false;
	do {
		mIsMainActive = true;		
		MenuSection::runChildSection();
	} while (!_3C);
}

/*
 * --INFO--
 * Address:	80424668
 * Size:	000148
 */
bool MenuSection::runChildSection()
{
	JKRHeap::sCurrentHeap->getFreeSize();

	JKRExpHeap* expHeap  = JKRExpHeap::create(mDisplayHeap->getFreeSize(), mDisplayHeap, true);
	JKRHeap* currentHeap = expHeap->becomeCurrentHeap();

	mCurrentSection = (Section*)setChildSection(expHeap);

	if (mCurrentSection) {
		sys->heapStatusStart("ChildSection::init", nullptr);
		mCurrentSection->init();

		sys->heapStatusEnd("ChildSection::init");
		sys->mDeltaTime = sys->mFpsFactor / 60.0f;
		mCurrentSection->run();
		mCurrentSection->exit();

		delete mCurrentSection;
		mCurrentSection = nullptr;
	}

	expHeap->destroy();
	currentHeap->becomeCurrentHeap();
	JKRHeap::sCurrentHeap->getFreeSize();

	return (mCurrentSection != 0);
}


ISection* GameFlow::createSection(JKRHeap* heap)
{
	ISection* section;
	switch (mActiveSectionFlag) {
	case 0x17:
		section = new Demo::Section(heap);
		break;
	case 0x16:
		section = new Title::Section(heap);
		break;
	case 0x2:
		section = new Game::SingleGameSection(heap);
		break;
	case 0x3:
		section = new Game::VsGameSection(heap, false);
		break;
	case 0x1E:
		section = new Game::VsGameSection(heap, true);
		break;
	default:
		section = new Title::Section(heap);
		break;
	}

	mActiveSectionFlag = 22;
	return section;
}