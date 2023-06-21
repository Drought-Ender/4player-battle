#include "Game/VsGame.h"
#include "PSSystem/PSSystemIF.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Stickers.h"
#include "Dolphin/rand.h"
#include "efx2d/T2DSprayset.h"
#include "FourPlayer.h"

namespace Game
{

namespace VsGame
{

bool CardMgr::usePlayerCard(int user, Game::VsGame::TekiMgr* tekiMgr)
{
	tekiMgr    = mTekiMgr;
	int slotID = mSlotMachines[user].mSlotID;

	bool used = true;

	if (mSlotMachines[user]._18) {
		return false;
	}

	switch (slotID) {
	case UNRESOLVED: {
		PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
		used = false;
		break;
	}
	case PIKMIN_5: {
		Onyon* onyon = ItemOnyon::mgr->getOnyon(1 - user);
		if (onyon) {
			for (int i = 0; i < 5; i++) {
				onyon->vsChargePikmin();
			}
		}
		break;
	}
	case PIKMIN_10: {
		Onyon* onyon = ItemOnyon::mgr->getOnyon(1 - user);
		if (onyon) {
			for (int i = 0; i < 10; i++) {
				onyon->vsChargePikmin();
			}
		}
		break;
	}
	case DOPE_BLACK: {
        for (int i = 0; i < 4; i++) {
            Navi* navi = naviMgr->getAt(i);
            if (navi && navi->isAlive() && navi->onVsTeam(user)) {
                navi->incDopeCount(SPRAY_TYPE_BITTER);
                break;
            }
        }
		break;
	}
	case DOPE_RED: {
        for (int i = 0; i < 4; i++) {
            Navi* navi = naviMgr->getAt(i);
            if (navi && navi->isAlive() && navi->onVsTeam(user)) {
                navi->incDopeCount(SPRAY_TYPE_SPICY);
                break;
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
			if (piki->getKind() == 1 - user && piki->isAlive() && (int)piki->getHappa() != Flower) {
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
		int color      = 1 - user;
		Onyon* onyon   = ItemOnyon::mgr->getOnyon(color);
		Pellet* bedama = nullptr;
		PelletIterator IPellet;

		CI_LOOP(IPellet)
		{
			Pellet* pellet = *IPellet;
			if (color == pellet->getBedamaColor()) {
				bedama = pellet;
				break;
			}
		}
		if (bedama && bedama->isAlive()) {
			{ // needed for stickers to call dtor
				Stickers stickers            = bedama;
				Iterator<Creature> ICreature = &stickers;
				CI_LOOP(ICreature) { (*ICreature)->endStick(); }
			}
			Vector3f onyonPos  = onyon->getFlagSetPos();
			Vector3f bedamaPos = bedama->getPosition();
			if (_distanceXZflag(bedamaPos, onyonPos) > 30.0f) {
				onyonPos.y += bedama->getCylinderHeight() * 0.5f;
				PelletReturnArg end = onyonPos;

				bedama->mPelletSM->transit(bedama, PELSTATE_Return, &end);
			}
		}
		break;
	}
	case TEKI_HANACHIRASHI:
	case TEKI_SARAI: {
		int tekiID   = slotID - 7;
		Onyon* onyon = ItemOnyon::mgr->getOnyon(user);
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

		float radiusVariance = 90.0f;
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
		Navi* navi = naviMgr->getAt(1 - user);
		for (int i = 0; i < num; i++) {
			Vector3f spawnNaviPos;
			if (navi) {
				spawnNaviPos = navi->getPosition();

				float faceDir = navi->getFaceDir();
				float radius  = randFloat() * 150.0f * radiusVariance;

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
		u32 TekiID = (!user) ? 4 : 5;

		Onyon* onyon = ItemOnyon::mgr->getOnyon(user);
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
		if (mSlotMachines[user].mCherryStock > 0) {
			mSlotMachines[user].mCherryStock--;
			mSlotMachines[user].start();
			mSlotMachines[user]._18 = 0;
		} else {
			mSlotMachines[user].mSpinSpeed   = 0.0f;
			mSlotMachines[user].mSpinAccel   = 0.0f;
			mSlotMachines[user].mAppearState = 2;
			mSlotMachines[user].mSlotID      = UNRESOLVED;
			mSlotMachines[user].startZoomUse();
			mSlotMachines[user]._18 = 1;
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
            return Vector3f(515.0f, 115.0f, 0.0f);
        case 2:
            return Vector3f(265.0f, 315.0f, 0.0f);
        case 3:
            return Vector3f(515.0f, 315.0f, 0.0f);
        }
    }
}

void CardMgr::draw(Graphics& gfx) {
    if (!moviePlayer->isActive()) {
		for (int i = 0; i < 4; i++) {
			mSlotsUpdated[i] = false;
		}

		Vector3f olimarSlotPos = getSlotOrigin(0);
		Vector3f louieSlotPos  = getSlotOrigin(1);
        Vector3f p3SlotPos     = getSlotOrigin(2);
        Vector3f p4SlotPos     = getSlotOrigin(3);
        
		if (mSlotMachines[getVsTeam(0)].mSpinState) {
			drawSlot(gfx, olimarSlotPos, mSlotMachines[getVsTeam(0)]);
		}
		if (mSlotMachines[getVsTeam(1)].mSpinState) {
			drawSlot(gfx, louieSlotPos, mSlotMachines[getVsTeam(1)]);
		}
        if (gNaviNum >= 3) {
            if (mSlotMachines[getVsTeam(2)].mSpinState) {
                drawSlot(gfx, p3SlotPos, mSlotMachines[getVsTeam(2)]);
            }
            if (mSlotMachines[getVsTeam(3)].mSpinState) {
                drawSlot(gfx, p4SlotPos, mSlotMachines[getVsTeam(3)]);
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
	if (mSlotMachines[user].mSpinState == 0) {
		mSlotMachines[user].start();
		mSlotMachines[user]._18 = 0;
	} else if (mSlotMachines[user].mCherryStock < 4) {
        for (int i = 0; i < 4; i++) {
            if (getVsTeam(i) == user) {
                Vector2f panePos = getLampPos(i, mSlotMachines[user].mCherryStock);
                OSReport("Owner %i\n", i);

                JUtility::TColor color1(0xff, 0x96, 0x64, 0xff);
                JUtility::TColor color2(0xff, 0x46, 0x46, 0xff);

                efx2d::ArgScaleColorColor spraysetArg(&panePos, 0.4f, color1, color2);
                efx2d::T2DSprayset_forVS vsSpraySet;

                vsSpraySet.create(&spraysetArg);
                PSSystem::spSysIF->playSystemSe(PSSE_SY_2P_SLOT_STOC, 0);
                
            }
        }
		mSlotMachines[user].mCherryStock++;
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

} // namespace VsGame


} // namespace Game
