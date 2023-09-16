#include "Game/VsGame.h"
#include "PSSystem/PSSystemIF.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Stickers.h"
#include "Dolphin/rand.h"
#include "efx2d/T2DSprayset.h"
#include "FourPlayer.h"
#include "Game/NaviState.h"
#include "Game/gameStat.h"
#include "types.h"
#include "Dolphin/rand.h"
#include "Game/VsGame.h"
#include "efx2d/Arg.h"
#include "efx2d/T2DSprayset.h"
#include "Light.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "PSSystem/PSSystemIF.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Stickers.h"
#include "Game/pelletMgr.h"
#include "Game/GameConfig.h"
#include "CherryTarget.h"
#include "VsSlotCard.h"
#include "nans.h"

namespace Game
{

// wasteable__Q24Game11NaviDopeArg
bool NaviDopeArg::wasteable = false;

namespace VsGame
{

VsGame::CardMgr::CardMgr(Game::VsGameSection* section, Game::VsGame::TekiMgr* tekiMgr)
{
	mSection                      = section;
	mTekiMgr                      = tekiMgr;
	mSlotNum                      = 0;
	mSlotTextures                 = nullptr;
	mSlotMachines[0].mPlayerIndex = 0;
	mSlotMachines[1].mPlayerIndex = 1;
	mNewSlotMachines[0].mPlayerIndex = 2;
	mNewSlotMachines[1].mPlayerIndex = 3;
	mSlotMachines[0].mCardMgr     = this;
	mSlotMachines[1].mCardMgr     = this;
	mNewSlotMachines[0].mCardMgr = this;
	mNewSlotMachines[1].mCardMgr = this;
	_104                          = 40.0f;

	initDraw();

	JUtility::TColor color(0xFF, 0xFF, 0xFF, 0xFF);
	mLightObj = new LightObj("test", GX_LIGHT0, TYPE_2, color);

	mLightObj->mElevation     = Vector3f(0.0f, 0.0f, -1.0f);
	mLightObj->mPosition      = Vector3f(555.0f, -250.0f, 4500.0f);
	mLightObj->mCutoffAngle   = 40.0f;
	mLightObj->mColor         = Color4(0xFF, 0xFF, 0xFF, 0xFF);
	mLightObj->mRefBrightness = 0.98f;
}

void VsGame::CardMgr::update()
{
	if (!gameSystem->paused()) {
		mSlotMachines[0].update();
		mSlotMachines[1].update();
		mNewSlotMachines[0].update();
		mNewSlotMachines[1].update();
	}
}

void CardMgr::loadResource()
{
	JKRArchive* arch = JKRArchive::mount("user/Kando/vstex/arc.szs", JKRArchive::EMM_Mem, nullptr, JKRArchive::EMD_Head);

	JUT_ASSERTLINE(258, arch, "vstex/arc.szs not found !\n");

	mSlotNum      = VsGame::vsSlotCardMgr->getCardCount();
	mSlotTextures = new JUTTexture*[mSlotNum];

	for (int i = 0; i < mSlotNum; i++) {
		ResTIMG* img = (ResTIMG*)arch->getResource(VsGame::vsSlotCardMgr->getAt(i)->GetTexName());
		if (img) {
			mSlotTextures[i] = new JUTTexture(img);
		} else {
			JUT_PANICLINE(269, "%s not found !\n", VsGame::vsSlotCardMgr->getAt(i)->GetTexName());
		}
	}

	ResTIMG* pressY = (ResTIMG*)arch->getResource("press_y.bti");
	JUT_ASSERTLINE(274, pressY, "press_y.bti");
	mYButtonTexture = new JUTTexture(pressY);

	ResTIMG* lampOn = (ResTIMG*)arch->getResource("lamp_on.bti");
	JUT_ASSERTLINE(279, lampOn, "lamp_on.bti");
	mLampOnTexture = new JUTTexture(lampOn);

	ResTIMG* lampOff = (ResTIMG*)arch->getResource("lamp_off.bti");
	JUT_ASSERTLINE(284, lampOff, "lamp_off.bti");
	mLampOffTexture = new JUTTexture(lampOff);

	ResTIMG* highlight = (ResTIMG*)arch->getResource("hl.bti");
	JUT_ASSERTLINE(289, highlight, "hl.bti");
	mHighlightTexture = new JUTTexture(highlight);
}

void CardMgr::stopSlot(int idx) {
	SlotMachine* machines[] = { &mSlotMachines[0], &mSlotMachines[1], &mNewSlotMachines[0], &mNewSlotMachines[1] };
	machines[idx]->startStop(); 
}

CardMgr::SlotMachine* CardMgr::getSlotMachine(int idx) {
	SlotMachine* machines[] = { &mSlotMachines[0], &mSlotMachines[1], &mNewSlotMachines[0], &mNewSlotMachines[1] };
	return machines[idx];
}

bool CardMgr::SlotMachine::dispCherryTarget() {
	switch (mSlotID)
	{
	case TEKI_HANACHIRASHI:
	case TEKI_SARAI:
	case TEKI_BOMBOTAKRA:
	case TEKI_ROCK:
	case TEKI_TANK:
		return true;
	default:
		return false;
	};
}

bool CardMgr::usePlayerCard(int user, TekiMgr* tekiMgr)
{
	tekiMgr    = mTekiMgr;
	SlotMachine* machines[] = { &mSlotMachines[0], &mSlotMachines[1], &mNewSlotMachines[0], &mNewSlotMachines[1] };
	int slotID = machines[user]->mSlotID;

	bool used = true;

	int target = CherryTarget::GetTarget(naviMgr->getAt(gUseCardNavi)->mController2);
	DebugReport("Target is %i\n", target);

	if (machines[user]->_18) {
		return false;
	}

	if (slotID == UNRESOLVED) {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
        return false;
	}

	vsSlotCardMgr->mUsingCards[slotID]->useCard(this, user, target);

	PSSystem::spSysIF->playSystemSe(PSSE_SY_2PSLOT_GO, 0);
	if (machines[user]->mCherryStock > 0) {
		machines[user]->mCherryStock--;
		machines[user]->start();
		machines[user]->_18 = 0;
	} else {
		machines[user]->mSpinSpeed   = 0.0f;
		machines[user]->mSpinAccel   = 0.0f;
		machines[user]->mAppearState = 2;
		machines[user]->mSlotID      = UNRESOLVED;
		machines[user]->startZoomUse();
		machines[user]->_18 = 1;
	}

	return used;
}

Vector3f CardMgr::getSlotOrigin(int playerIdx)
{
    if (gNaviNum == 2) {
        if (playerIdx == 0) {
            return Vector3f(515.0f, 115.0f, 0.0f);
        }
        else {
            return Vector3f(515.0f, 315.0f, 0.0f);
        }
    }
    else {
        switch (playerIdx)
        {
        case 0:
            return Vector3f(265.0f, 115.0f, 0.0f);
        case 1:
            return Vector3f(575.0f, 115.0f, 0.0f);
        case 2:
            return Vector3f(265.0f, 315.0f, 0.0f);
        case 3:
            return Vector3f(575.0f, 315.0f, 0.0f);
        }
    }
}

void CardMgr::draw(Graphics& gfx) {
    if (!moviePlayer->isActive()) {
		for (int i = 0; i < 4; i++) {
			mSlotsUpdated[i] = false;
		}

		SlotMachine* machines[] = { &mSlotMachines[0], &mSlotMachines[1], &mNewSlotMachines[0], &mNewSlotMachines[1] };

		Vector3f olimarSlotPos = getSlotOrigin(0);
		Vector3f louieSlotPos  = getSlotOrigin(1);
        Vector3f p3SlotPos     = getSlotOrigin(2);
        Vector3f p4SlotPos     = getSlotOrigin(3);
        
		if (machines[getVsTeam(0)]->mSpinState) {
			drawSlot(gfx, olimarSlotPos, *machines[getVsTeam(0)]);
		}
		if (machines[getVsTeam(1)]->mSpinState) {
			drawSlot(gfx, louieSlotPos, *machines[getVsTeam(1)]);
		}
        if (gNaviNum >= 3) {
            if (machines[getVsTeam(2)]->mSpinState) {
                drawSlot(gfx, p3SlotPos, *machines[getVsTeam(2)]);
            }
            if (gNaviNum == 4 && machines[getVsTeam(3)]->mSpinState) {
                drawSlot(gfx, p4SlotPos, *machines[getVsTeam(3)]);
            }
        }
	}
}

inline Vector2f CardMgr::getLampPos(int user, int cherries)
{
    Vector3f slotPos = getSlotOrigin(user);
	Vector2f lampOrigin = Vector2f(slotPos.x, slotPos.y);
	lampOrigin -= Vector2f(22.4f, 80.0f);
	f32 lampWidth = 8.0f;
	lampOrigin.x += cherries * lampWidth * 2.0f;
	return lampOrigin;
}

void CardMgr::gotPlayerCard(int user)
{
	SlotMachine* machines[] = { &mSlotMachines[0], &mSlotMachines[1], &mNewSlotMachines[0], &mNewSlotMachines[1] };
	if (machines[user]->mSpinState == 0) {
		machines[user]->start();
		machines[user]->_18 = 0;
	} else if (machines[user]->mCherryStock < 4) {
        for (int i = 0; i < 4; i++) {
            if (getVsTeam(i) == user) {
                Vector2f panePos = getLampPos(i, machines[user]->mCherryStock);
                DebugReport("Owner %i\n", i);

                JUtility::TColor color1(0xff, 0x96, 0x64, 0xff);
                JUtility::TColor color2(0xff, 0x46, 0x46, 0xff);

                efx2d::ArgScaleColorColor spraysetArg(&panePos, 0.4f, color1, color2);
                efx2d::T2DSprayset_forVS vsSpraySet;

                vsSpraySet.create(&spraysetArg);
                PSSystem::spSysIF->playSystemSe(PSSE_SY_2P_SLOT_STOC, 0);
                
            }
        }
		machines[user]->mCherryStock++;
	}
}

void CardMgr::SlotMachine::updateZoomIn()
{
	if (mCardMgr->mSlotsUpdated[mPlayerIndex]) {
		return;
	}
	else {
		mCardMgr->mSlotsUpdated[mPlayerIndex] = true;
	}
	if (_50 == 0) {
		_3C += sys->mDeltaTime * 4.0f;
		_44 = _3C * 10.0f + 20.0f;
		_48 = 0.0f;
		if (_3C > 1.0f) {
			_3C = 0.0f;
			_50 = 1;
		}
	} else {
		_3C += sys->mDeltaTime;
		if (_3C > 1.0f) {
			_3C -= 1.0f;
		}

		_44 = pikmin2_sinf(_3C * TAU) * 5.0f + 30.0f;
		_48 = pikmin2_sinf(_3C * TAU * 2.0f) * 5.0f + 30.0f;
		_40 = pikmin2_cosf(_3C * TAU) * 10.0f * DEG2RAD * PI;
	}
}
/*
 * --INFO--
 * Address:	80238D44
 * Size:	000128
 */
void CardMgr::SlotMachine::updateZoomUse()
{
	if (mCardMgr->mSlotsUpdated[mPlayerIndex]) {
		return;
	}
	else {
		mCardMgr->mSlotsUpdated[mPlayerIndex] = true;
	}
	_3C += sys->mDeltaTime * 3.0f;
	if (_3C > 1.0f) {
		_3C -= 1.0f;
	}

	_44 = pikmin2_sinf(_3C * TAU) * 5.0f + 30.0f;
	_48 = -(_3C * 30.0f - 30.0f);
	_40 = (pikmin2_cosf(_3C * TAU) * 5.0f + 5.0f) * 360.0f * DEG2RAD * PI;
}

CardSelector::CardSelector(int count)
{
	mCount = count;	
	mValues = new int[count];
	mCumulative = new f32[count];
	for (int i = 0; i < count; i++) {
		mValues[i] = 100;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
int CardSelector::getTotalWeight()
{
	int sum = 0;
	for (int i = 0; i < mCount; i++) {
		sum += mValues[i];
	}
	return sum;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000274
 */
int CardSelector::selectCard()
{
	f32 fullCumulative = 0.0f;
	int arraySum       = getTotalWeight();
	for (int i = 0; i < mCount; i++) {
		fullCumulative += (f32)mValues[i] / arraySum;
		if (mValues[i] == 0) {
			mCumulative[i] = -100.0f;
		} else {
			mCumulative[i] = fullCumulative;
		}
	}
	f32 value = randFloat();
	for (int i = 0; i < mCount; i++) {
		if (value < mCumulative[i])
			return i;
	}
	return (int)(randFloat() * mCount);
}


void CardMgr::SlotMachine::start()
{
	_51 = false;

	int cardCount = vsSlotCardMgr->mCardCount;

    CardSelector cardSelector(cardCount);

	
    
    int bedamaIdx = -1;

    for (int i = 0; i < cardCount; i++) {
        cardSelector.mValues[i] = vsSlotCardMgr->mUsingCards[i]->getWeight(mCardMgr, mPlayerIndex);
    }

    cardSelector.fixBrokenWeights();


    int totalMeasure = cardSelector.getTotalWeight();
    
    for (int i = 0; i < cardCount; i++) {
        cardSelector.mValues[i] = vsSlotCardMgr->mUsingCards[i]->getBedamaWeight(mCardMgr, mPlayerIndex, totalMeasure, cardSelector.mValues[i]);
    }

    mSelectedSlot = cardSelector.selectCard();

    if (mPrevSelected != UNRESOLVED) {
        cardSelector.mValues[mPrevSelected] /= 10;
    }
    

    mPrevSelected = mSelectedSlot;
    _28 = randFloat();
    mSlotID = UNRESOLVED;
    mAppearState = APPEAR_LEAVE;
    PSSystem::spSysIF->playSystemSe(PSSE_SY_2PSLOT_APPEAR, 0);
    switch (mSpinState) {
        case SPIN_END:
        case SPIN_UNSTARTED:
            mSpinSpeed = 72.0f * DEG2RAD;
            mSpinState = SPIN_WAIT_START;
            mSpinAccel = -TAU;
            return;
        case SPIN_WAIT_START:
        case SPIN_START:
            break;
        default:
            mSpinState = SPIN_START;
            return;
    }
}


} // namespace VsGame


} // namespace Game
