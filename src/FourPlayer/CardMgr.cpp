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

	switch (slotID) {
	case UNRESOLVED: {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
		used = false;
		break;
	}
	case PIKMIN_5: {
		Onyon* onyon = ItemOnyon::mgr->getOnyon(getPikiFromTeam(user));
		if (onyon) {
			ItemOnyon::gVsChargeOkay = true;
			for (int i = 0; i < 5; i++) {
				onyon->vsChargePikmin();
			}
			ItemOnyon::gVsChargeOkay = false;
		}
		break;
	}
	case PIKMIN_10: {
		Onyon* onyon = ItemOnyon::mgr->getOnyon(getPikiFromTeam(user));
		if (onyon) {
			ItemOnyon::gVsChargeOkay = true;
			for (int i = 0; i < 10; i++) {
				onyon->vsChargePikmin();
			}
			ItemOnyon::gVsChargeOkay = false;
		}
		break;
	}
	case DOPE_BLACK: {
		Navi* navi = naviMgr->getAt(gUseCardNavi);
		if (navi && navi->isAlive() && navi->onVsTeam(user)) {
			if (gConfig[SPRAY_CARD] == ConfigEnums::SPRAYCARD_NORMAL) {
				navi->incDopeCount(SPRAY_TYPE_BITTER);
			}
			else if (gConfig[SPRAY_CARD] == ConfigEnums::SPRAYCARD_USE) {
				NaviDopeArg dopearg (SPRAY_TYPE_BITTER);
				gDopeCountArray[getVsTeam(gUseCardNavi)][SPRAY_TYPE_BITTER]++;
				navi->transit(NSID_Dope, &dopearg);
				
			}
		}
		break;
	}
	case DOPE_RED: {
		Navi* navi = naviMgr->getAt(gUseCardNavi);
		if (navi && navi->isAlive() && navi->onVsTeam(user)) {
			if (gConfig[SPRAY_CARD] == ConfigEnums::SPRAYCARD_NORMAL) {
				navi->incDopeCount(SPRAY_TYPE_SPICY);
			}
			else if (gConfig[SPRAY_CARD] == ConfigEnums::SPRAYCARD_USE) {
				NaviDopeArg dopearg (SPRAY_TYPE_SPICY);
				NaviDopeArg::wasteable = true;
				
				gDopeCountArray[getVsTeam(gUseCardNavi)][SPRAY_TYPE_SPICY]++;
				navi->transit(NSID_Dope, &dopearg);
				NaviDopeArg::wasteable = false;
			}
		}

		break;
	}
	case PIKMIN_XLU: {
        for (int i = 0; i < 4; i++) {
            Navi* navi = naviMgr->getAt(i);
            if (navi && navi->isAlive() && navi->onVsTeam(user)) {
                if (mSection->mGhostIconTimers[i] <= 0.0f) {
                    efx::TNaviEffect* naviEffect = navi->mEffectsObj;
                    if (!naviEffect->isFlag(efx::NAVIFX_IsSaved)) {
                        naviEffect->saveFlags();
                    }
                    naviEffect->mLight.forceKill();
                    naviEffect->mLightAct.forceKill();
                    naviEffect->mDamage.forceKill();
                    naviEffect->killHamonA_();
                    naviEffect->killHamonB_();
                    naviEffect->killLight_();
                    naviEffect->killLightAct_();
                    naviEffect->killCursor_();
                    naviEffect->killFueact_();
                }
                mSection->mGhostIconTimers[i] = 60.0f;
            }
        }

		break;
	}
	case ALL_FLOWER: {
		Iterator<Piki> IPiki = pikiMgr;
		CI_LOOP(IPiki)
		{
			Piki* piki = *IPiki;
			if (piki->getKind() == getPikiFromTeam(user) && piki->isAlive() && (int)piki->getHappa() != Flower) {
				piki->changeHappa(Flower);
				Vector3f vec = piki->_25C;
				efx::TPkGlow2 particle;
				efx::Arg arg = vec;
				particle.create(&arg);
				piki->startSound(PSSE_PK_FLOWER_VOICE, true);
			}
		}
		break;
	}
	case RESET_BEDAMA: {
		int color      = getPikiFromTeam(user);
		Onyon* onyon   = ItemOnyon::mgr->getOnyon(color);
		Pellet* bedama = nullptr;
		PelletIterator IPellet;

		CI_LOOP(IPellet)
		{
			Pellet* pellet = *IPellet;
			if (color == pellet->getBedamaPikiColor()) {
				bedama = pellet;
				break;
			}
		}
		if (bedama && bedama->isAlive()) {
			{
			Stickers stickers            = bedama;
			Iterator<Creature> ICreature = &stickers;
			CI_LOOP(ICreature) { (*ICreature)->endStick(); }
			}
			Vector3f onyonPos  = onyon->getFlagSetPos();
			Vector3f bedamaPos = bedama->getPosition();
			if (_distanceXZflag(bedamaPos, onyonPos) > 30.0f && gConfig[MARBLE_RETURN] == ConfigEnums::RETURN_NORMAL) {
				onyonPos.y += bedama->getCylinderHeight() * 0.5f;
				PelletReturnArg end = onyonPos;

				bedama->mPelletSM->transit(bedama, PELSTATE_Return, &end);
			}
			else if (gConfig[MARBLE_RETURN] == ConfigEnums::RETURN_BURY) {
				BounceBuryStateArg arg;
				Stickers stickers = bedama;
				arg.mIsBuried = bedama->isBuried();
				arg.mHeldPikis = &stickers;

				bedama->mPelletSM->transit(bedama, PELSTATE_BounceBury, &arg);
			}
			
		}
		break;
	}
	case TEKI_HANACHIRASHI:
	case TEKI_SARAI: {
		if (target == -1) {
			PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
			used = false;
			break;
		}
		int tekiID   = slotID - 7;
		Onyon* onyon = ItemOnyon::mgr->getOnyon(getVsPikiColor(target));
		Vector3f onyonPos;
		if (onyon) {
			onyonPos = onyon->getPosition();

			float faceDir = onyon->getFaceDir();

			float radius = randFloat() * 150.0f + 50.0f;
			float angle  = randFloat() * TAU;
			float height = 0.0f;

			Vector3f spawnOffset = Vector3f(radius * pikmin2_sinf(angle), height, radius * pikmin2_cosf(angle));

			onyonPos += spawnOffset;
		}
		tekiMgr->birth(tekiID, onyonPos, true);
		break;
	}
	case TEKI_ROCK:
	case TEKI_BOMBOTAKRA: {
		if (target == -1) {
			PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
			used = false;
			break;
		}

		float radiusVariance = 150.0f;
		float enemyHeight    = 0.0f;
		int num;
		if (slotID == TEKI_ROCK) {
			num = 8;
		} else {
			num            = 1;
			radiusVariance = 0.0f;
			enemyHeight    = 1.0f;
		}

		int tekiID = slotID - 7;


		Navi* navi = naviMgr->getAt(target);
		for (int i = 0; i < num; i++) {
			Vector3f spawnNaviPos;
			if (navi) {
				spawnNaviPos = navi->getPosition();

				float faceDir = navi->getFaceDir();
				float radius  = randFloat() * radiusVariance;

				float angle  = randFloat() * TAU;
				float height = enemyHeight;

				Vector3f spawnOffset = Vector3f(radius * pikmin2_sinf(angle), height, radius * pikmin2_cosf(angle));

				spawnNaviPos += spawnOffset;
			}
			tekiMgr->birth(tekiID, spawnNaviPos, true);
		}
		
		break;
	}
	case TEKI_TANK: {
		if (target == -1) {
			PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
			used = false;
			break;
		}
		u32 TekiID = 4 + user;

		Onyon* onyon = ItemOnyon::mgr->getOnyon(getVsPikiColor(target));
		Vector3f onyonPos;
		if (onyon) {

			onyonPos = onyon->getPosition();

			float faceDir = onyon->getFaceDir();

			float radius = randFloat() * 150.0f + 50.0f;
			float angle  = randFloat() * TAU;
			float height = 0.0f;

			angle = faceDir;

			Vector3f spawnOffset = Vector3f(radius * pikmin2_sinf(angle), height, radius * pikmin2_cosf(angle));

			onyonPos += spawnOffset;
		}
		tekiMgr->birth(TekiID, onyonPos, true);
		break;
	}
	}

	if (used) {
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
            if (machines[getVsTeam(3)]->mSpinState && gNaviNum == 4) {
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

CardSelector::CardSelector()
{
	for (int i = 0; i < CARD_ID_COUNT; i++) {
		mValues[i] = 100;
	}
	mValues[RESET_BEDAMA] = 30;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
int CardSelector::getTotalWeight()
{
	int sum = 0;
	for (int i = 0; i < CARD_ID_COUNT; i++) {
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
	for (int i = 0; i < CARD_ID_COUNT; i++) {
		fullCumulative += (f32)mValues[i] / arraySum;
		if (mValues[i] == 0) {
			mCumulative[i] = -100.0f;
		} else {
			mCumulative[i] = fullCumulative;
		}
	}
	f32 value = randFloat();
	for (int i = 0; i < CARD_ID_COUNT; i++) {
		if (value < mCumulative[i])
			return i;
	}
	return (int)(randFloat() * CARD_ID_COUNT);
}


void CardMgr::SlotMachine::start()
{
	_51 = false;

	CardSelector selector;

	int pikminCounts[4];
	f32 redBlueScoreCount = mCardMgr->mSection->mRedBlueScore[mPlayerIndex];

	int dopeCount0;
	int dopeCount1;

	f32 scoreCount0 = mCardMgr->mSection->mYellowScore[mPlayerIndex];
	f32 scoreCount1 = mCardMgr->mSection->mYellowScore[mPlayerIndex];

	pikminCounts[TEAM_RED] = GameStat::getMapPikmins(Red);
	pikminCounts[TEAM_BLUE] = GameStat::getMapPikmins(Blue);
	pikminCounts[TEAM_WHITE] = GameStat::getMapPikmins(White);
	pikminCounts[TEAM_PURPLE] = GameStat::getMapPikmins(Purple);

	if (pikminCounts[mPlayerIndex] < 4) {
		selector.mValues[PIKMIN_5]  = 200;
		selector.mValues[PIKMIN_10] = 150;
	}

	// dopeCount0 = mCardMgr->mSection->getGetDopeCount(mPlayerIndex, 0);
	// dopeCount1 = mCardMgr->mSection->getGetDopeCount(1 - mPlayerIndex, 0);

	// if (dopeCount0 > dopeCount1 + 2) {
	// 	selector.mValues[DOPE_RED] /= 2;
	// }

	// dopeCount0 = mCardMgr->mSection->getGetDopeCount(mPlayerIndex, 1);
	// dopeCount1 = mCardMgr->mSection->getGetDopeCount(1 - mPlayerIndex, 1);

	// if (dopeCount0 > dopeCount1 + 2) {
	// 	selector.mValues[DOPE_BLACK] /= 2;
	// }

	if (mPrevSelected != UNRESOLVED) {
		selector.mValues[mPrevSelected] = 10;
	}

	if (mCardMgr->mSection->mGhostIconTimers[mPlayerIndex] > 5.0f) {
		selector.mValues[PIKMIN_XLU] = 0;
	}

	int total = selector.getTotalWeight();

	f32 resetBedamaProb = 0.0f;

	if (redBlueScoreCount < 0.2f) {

	} else if (redBlueScoreCount < 0.4f) {
		resetBedamaProb = 0.2f;
	} else if (redBlueScoreCount < 0.7f) {
		resetBedamaProb = 0.5f;
	} else {
		resetBedamaProb = 0.8f;
	}

	if (scoreCount0 - scoreCount1 >= 0.4f) {
		resetBedamaProb *= 0.7f;
	}

	if (resetBedamaProb > 0.0f) {
		selector.mValues[RESET_BEDAMA] = total * resetBedamaProb;
	}

	if (gConfig[MARBLE_RETURN] == ConfigEnums::RETURN_REMOVED) {
		selector.mValues[RESET_BEDAMA] = 0;
	}
	if (gConfig[SPRAY_CARD] == ConfigEnums::SPRAYCARD_OFF) {
		selector.mValues[DOPE_RED] = 0;
		selector.mValues[DOPE_BLACK] = 0;
	}

	mSelectedSlot = selector.selectCard();

	mPrevSelected = mSelectedSlot;
	_28           = randFloat();
	mSlotID       = UNRESOLVED;
	mAppearState  = 0;

	PSSystem::spSysIF->playSystemSe(PSSE_SY_2PSLOT_APPEAR, 0);
	switch (mSpinState) {
	case SPIN_END:
	case SPIN_UNSTARTED:
		mSpinSpeed = 72.0f * (PI / 180.0f);
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
