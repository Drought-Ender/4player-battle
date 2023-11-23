#include "FourPlayer.h"
#include "Game/Piki.h"
#include "Game/Navi.h"
#include "JSystem/JUtility/JUTGamePad.h"
#include "Game/NaviParms.h"
#include "Game/NaviState.h"
#include "Game/Entities/ItemPikihead.h"
#include "Game/PikiMgr.h"
#include "PikiAI.h"
#include "Game/cellPyramid.h"
#include "ebi/Screen/TTitleMenu.h"
#include "Game/mapParts.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/mapParts.h"
#include "types.h"
#include "Vector3.h"
#include "Game/Entities/Item.h"
#include "Game/EnemyBase.h"
#include "Game/CurrTriInfo.h"
#include "Game/gamePlayData.h"
#include "Game/generalEnemyMgr.h"
#include "Game/Cave/Node.h"
#include "Game/Cave/RandMapMgr.h"
#include "Dolphin/rand.h"
#include "Game/Entities/PelletNumber.h"
#include "DroughtLib.h"

namespace Game
{
    
int gVsNaviIndexArray[4] = { Red, Blue, Blue, Red };
int gDopeCountArray[4][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0} };

int Navi::getVsPikiColor() {
    return gVsNaviIndexArray[mNaviIndex];
}

int Navi::getVsTeam() {
    return Game::getVsTeam(mNaviIndex);
}

int getVsPikiColor(int idx) {
    return gVsNaviIndexArray[idx];
}



int getVsTeam(int idx) {
    return getTeamFromPiki((EPikiKind)gVsNaviIndexArray[idx]);
}

int getVsTeam_s(int idx) {
    int team = getTeamFromPiki((EPikiKind)gVsNaviIndexArray[idx]);
	if (team == -1) {
		return 0;
	}
	return team;
}

int getPikiFromTeamEnum(int idx) {
	EPikiKind pikiColor = (EPikiKind)idx;
	switch (idx)
    {
    case TEAM_RED:
        pikiColor = Red;
        break;
    case TEAM_BLUE:
        pikiColor = Blue;
        break;
	case TEAM_WHITE:
		pikiColor = White;
		break;
	case TEAM_PURPLE:
		pikiColor = Purple;
		break;
	case TEAM_NULL:
		pikiColor = NullColor;
		break;
    }
	return pikiColor;
}



// onTeam__Q24Game4NaviFi
bool Navi::onTeam(int color) {
    return getVsPikiColor() == color;
}

bool Navi::onVsTeam(int color) {
    return getVsTeam() == color;
}

int CalcNaviNum() {
    if (JUTGamePad::mPadStatus[2].err <= PAD_ERR_NO_CONTROLLER) {
        return 2;
    }
    if (JUTGamePad::mPadStatus[3].err <= PAD_ERR_NO_CONTROLLER) {
        return 3;
    }
    return 4;
}

int Navi::getDopeCount(int dope) {
    if (gameSystem->isVersusMode()) {
        return gDopeCountArray[getVsTeam()][dope];
    }
    else {
        return playData->getDopeCount(dope);
    }
}

bool Navi::hasDope(int dope) {
    if (gameSystem->isVersusMode()) {
        return gDopeCountArray[getVsTeam()][dope] > 0; 
    }
    else {
        return playData->hasDope(dope);
    }
}

void Navi::useDope(int dope) {
    if (gameSystem->isVersusMode()) {
		mSprayCounts[dope]--;
        gDopeCountArray[getVsTeam()][dope]--; 
    }
    else {
        playData->useDope(dope);
    }
}

void Navi::incDopeCount(int dope) {
    if (gameSystem->isVersusMode()) {
		mSprayCounts[dope]++;
        GameMessageVsGetDoping dopeMsg (mNaviIndex, dope);
        gameSystem->mSection->sendMessage(dopeMsg);
        gDopeCountArray[getVsTeam()][dope]++;
    }
    else {
        playData->incDopeCount(dope);
    }
}

const char* getPikiColorName(int pikiKind) {
	switch (pikiKind)
	{
	case Game::Red:
		return "Red Pikmin";
	case Game::Blue:
		return "Blue Pikmin";
	case Game::Yellow:
		return "Yellow Pikmin";
	case Game::White:
		return "White Pikmin";
	case Game::Purple:
		return "Purple Pikmin";
	case Game::Bulbmin:
		return "Bulbmin";
	case Game::Carrot:
		return "Carrot";
	case -1:
		return "Null";
	default:
		return "Unknown";
	}
}

const char* getNaviColorName(int teamColor) {
	switch (teamColor)
	{
	case TEAM_RED:
		return "Red Navi";
	case TEAM_BLUE:
		return "Blue Navi";
	case TEAM_WHITE:
		return "White Navi";
	case TEAM_PURPLE:
		return "Purple Navi";
	case TEAM_NULL:
		return "Null Navi";
	default:
		return "Unknown Navi";
	}
}


void PikiMgr::setVsXlu(int p1, bool p2)
{
	if (p2) {
		mFlags[0] &= ~(1 << p1);
	} else {
		//DebugReport("XLU %s\n", getPikiColorName(p1));
		mFlags[0] |= 1 << p1;
	}
}

bool PikiMgr::isVersusXlu(int piki) {
	return mFlags[0] & (1 << piki);
}


void PikiMgr::doEntry() {

    
    u8 flag = mFlags[1];
    if (gameSystem->isVersusMode()) {
        for (int i = 0; i < mMax; i++) {
            if (mOpenIds[i]) {
                continue;
            }

            Piki* piki = &mArray[i];
            if (flag & 1 && !piki->isMovieActor()) {
                piki->mLod.mFlags &= ~0xF4;
            }

            for (int vpID = 0; vpID < 4; vpID++) {
                if (pikiMgr->isVersusXlu(piki->mPikiKind) && getVsPikiColor(vpID) != piki->mPikiKind) {
					piki->mLod.mFlags &= ~(0x10 << vpID);
                }
            }
            piki->doEntry();
        }
    }
    else {
        for (int i = 0; i < mMax; i++) {
            if (mOpenIds[i]) {
                continue;
            }
            Piki* piki = &mArray[i];
            if (flag & 1 && !piki->isMovieActor()) {
                piki->mLod.mFlags &= ~0xF4;
            }
            piki->doEntry();
        }
    }
}

void NaviMgr::doEntry() {
    u8 flag = _5C;
    for (int i = 0; i < mMax; i++) {
        if (mOpenIds[i]) {
            continue;
        }

        Navi* navi = &mArray[i];
        if (flag & 1 && !navi->isMovieActor()) {
            navi->mLod.mFlags &= ~0xF4;
        }
        else if (navi->isMovieActor()) {
            navi->mLod.mFlags |= 0xF4;
        }

        if (gameSystem->isVersusMode()) {
            for (int vpID = 0; vpID < 4; vpID++) {
                if (pikiMgr->isVersusXlu(navi->getVsPikiColor()) && getVsPikiColor(vpID) != navi->getVsPikiColor()) {
                    navi->mLod.mFlags &= ~(0x10 << vpID);
                }
            }
        }
        navi->doEntry();
    }
}

Onyon* Pellet::getPelletGoal()
{
	Onyon* goalOnyon;

	if ((gameSystem->isVersusMode())
	    || ((getKind() != PELTYPE_TREASURE) && (getKind() != PELTYPE_BERRY) && (getKind() != PELTYPE_UPGRADE))) {
		int maxCount = -1;
		int counter  = 0;
		int i        = 0;

		for (int j = 0; j < ONYON_TYPE_MAX; j++) {
			if (maxCount < (int)mPikminCount[j]) {
				maxCount = mPikminCount[j];
			}
		}

		int onyonType[ONYON_TYPE_MAX];
		for (int j = 0; j < ONYON_TYPE_MAX; j++) {
			if (maxCount == (int)mPikminCount[j]) {
				onyonType[i++] = j;
				counter++;
			}
		}

		int idx = (int)((float)counter * randFloat());
		if (idx >= counter) {
			idx = ONYON_TYPE_BLUE;
		}

		int type  = onyonType[idx];
		goalOnyon = ItemOnyon::mgr->getOnyon(type);
		if ((gameSystem->mMode == GSM_STORY_MODE) && (!playData->hasBootContainer(type))) {
			goalOnyon = nullptr;
		}

		if (goalOnyon == nullptr) {
			goalOnyon = ItemOnyon::mgr->getOnyon(ONYON_TYPE_RED);
			if (goalOnyon == nullptr) {
				goalOnyon = ItemOnyon::mgr->mPod;
			}
		}
	} else {
		goalOnyon = ItemOnyon::mgr->mUfo;
		if (ItemOnyon::mgr->mUfo == nullptr) {
			goalOnyon = ItemOnyon::mgr->mPod;
		}
	}

	return goalOnyon;
}

void PelletGoalState::init(Pellet* pellet, StateArg* arg)
{
	pellet->clearClaim();

	// check if a new upgrade is acquired
	if (pellet->getKind() == PELTYPE_UPGRADE && gameSystem->mMode == GSM_STORY_MODE) {
		int id = pellet->getConfigIndex();
		if (id >= 0 && id < 12) {
			playData->mOlimarData->getItem(id);
		}
	}
	pellet->setAlive(false);
	bool flag                = false;
	PelletGoalStateArg* sarg = static_cast<PelletGoalStateArg*>(arg);
	mOnyon                   = sarg->mCreature;
	if (gameSystem->mMode == GSM_STORY_MODE || gameSystem->isChallengeMode()) {
		flag = checkMovie(pellet);

	} else if (gameSystem->mMode == GSM_VERSUS_MODE) {
		int type = pellet->mPelletFlag;
		int team = getTeamFromPiki((EPikiKind)static_cast<Onyon*>(mOnyon)->mOnyonType);
		if ((u32)type == Pellet::FLAG_VS_BEDAMA_RED) {
			pellet->movie_begin(false);
			mOnyon->movie_begin(false);
			GameMessageVsRedOrSuckStart mesg(team);
			mesg.mIsYellow = false;
			mesg.mBedamaColor = 0;
			gameSystem->mSection->sendMessage(mesg);

		} else if ((u32)type == Pellet::FLAG_VS_BEDAMA_BLUE) {
			pellet->movie_begin(false);
			mOnyon->movie_begin(false);
			GameMessageVsRedOrSuckStart mesg2(team);
			mesg2.mIsYellow = false;
			mesg2.mBedamaColor = 1;
			gameSystem->mSection->sendMessage(mesg2);

		} else if ((u32)type == Pellet::FLAG_VS_BEDAMA_WHITE) {
			pellet->movie_begin(false);
			mOnyon->movie_begin(false);
			GameMessageVsRedOrSuckStart mesg2(team);
			mesg2.mIsYellow = false;
			mesg2.mBedamaColor = 2;
			gameSystem->mSection->sendMessage(mesg2);

		} else if ((u32)type == Pellet::FLAG_VS_BEDAMA_PURPLE) {
			pellet->movie_begin(false);
			mOnyon->movie_begin(false);
			GameMessageVsRedOrSuckStart mesg2(team);
			mesg2.mIsYellow = false;
			mesg2.mBedamaColor = 3;
			gameSystem->mSection->sendMessage(mesg2);

		} else if ((u32)type == Pellet::FLAG_VS_BEDAMA_YELLOW) {
			if ((int)mOnyon->mObjectTypeID == OBJTYPE_Onyon) {
				pellet->movie_begin(false);
				mOnyon->movie_begin(false);
				GameMessageVsRedOrSuckStart mesg3(team);
				mesg3.mIsYellow = true;
				mesg3.mBedamaColor = 0;
				gameSystem->mSection->sendMessage(mesg3);

			} else {
				JUT_PANICLINE(512, "not onyon %d\n", mOnyon->mObjectTypeID);
			}
		}
	}

	if (flag) {
		mOnyon->movie_begin(false);
		pellet->movie_begin(false);
	}

	Vector3f sep = mOnyon->getSuckPos() - pellet->getPosition();
	mDistance    = _length(sep);
	_14          = 0.0f;
	mSuckDelay   = 1.5f;

	Vector3f vel = pellet->getVelocity();
	vel.y        = 0.0f;
	pellet->setVelocity(vel);
	mScale = 1.0f;

	if (pellet->mPelletView) {
		mScale = pellet->mPelletView->viewGetBaseScale();
	}

	if (((int)mOnyon->mObjectTypeID == OBJTYPE_Onyon || (int)mOnyon->mObjectTypeID == OBJTYPE_Ufo) && !flag) {
		static_cast<Onyon*>(mOnyon)->efxSuikomi();
	}
	mInDemo     = flag;
	mDidSuikomi = false;
	if (!mInDemo) {
		Iterator<Piki> it(pikiMgr);
		CI_LOOP(it)
		{
			Piki* piki = *it;
			piki->movie_end(false);
		}

		GeneralMgrIterator<EnemyBase> it2(generalEnemyMgr);
		for (it2.first(); it2.mContainer; it2.next()) {
			EnemyBase* enemy = it2.getObject();
			enemy->movie_end(false);
		}
	}

	pellet->sound_otakaraEventFinish();
	if (!(u8)mOnyon->isSuckArriveWait()) {
		InteractSuckArrive act(pellet);
		mOnyon->stimulate(act);
		mIsWaiting = 0;
	} else {
		mIsWaiting = 1;
	}
}

void PelletNumber::Object::changeMaterial() {
	J3DGXColorS10 color;
	switch (mPelletColor)
	{
	case Red:
		color.r = 0xfb;
		color.b = 0x11;
		color.g = 0x00;
		color.a = 0xff;
		break;
	case Blue:
		color.r = 0x00;
		color.b = 0xff;
		color.g = 0x33;
		color.a = 0xff;
		break;
	case Yellow:
		color.r = 0xff;
		color.g = 0xdc;
		color.b = 0x34;
		color.a = 0xff;
		break;
	case Purple:
		color.r = 50;
		color.g = 0;
		color.b = 100;
		color.a = 0xff;
		break;
	case White:
		color.r = 179;
		color.g = 230;
		color.b = 179;
		color.a = 0xff;
	default:
		color.r = 0xff;
		color.g = 0xff;
		color.b = 0xff;
		color.a = 0xff;
		break;
	}

	s32 matIdx = mModel->mJ3dModel->mModelData->mMaterialTable.mMaterialNames->getIndex("bpel1");
	mModel->mJ3dModel->mModelData->mMaterialTable.mMaterials[matIdx]->setTevColor(0, &color);


	mModel->mJ3dModel->calcMaterial();
	mModel->mJ3dModel->diff();
}

struct HasFloor : public WPCondition {
	bool satisfy(WayPoint* other) {
		Vector3f position = other->getPosition();
		return DroughtLib::hasValidFloor(position);
	}
};

void Navi::voidout() {
	HasFloor condition;
	WPSearchArg arg (mPosition3, &condition, 0, 0.0f);
	WayPoint* nearest = mapMgr->mRouteMgr->getNearestWayPoint(arg);
	Vector3f landPos = nearest->getPosition();
	landPos.y = mapMgr->getMinY(landPos) + 300.0f;
	mPosition3 = landPos;
	InteractFlick flick (nullptr, 0.0f, 10.0f, 0.0f);
	stimulate(flick);
}

} // namespace Game

// GetBackupWaypoint__FRQ24Game15WPEdgeSearchArg
Game::WayPoint* GetBackupWaypoint(Game::WPEdgeSearchArg& searchArg) {
	Game::WPSearchArg arg (searchArg.mStartPosition, nullptr, 0, 100.0f);
	return Game::mapMgr->mRouteMgr->getNearestWayPoint(arg);
}