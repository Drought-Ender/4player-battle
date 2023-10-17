#include "Game/Entities/ElecBug.h"
#include "Game/EnemyIterator.h"
#include "Game/generalEnemyMgr.h"
#include "Dolphin/rand.h"

namespace Game {
namespace ElecBug {

void StateCharge::exec(EnemyBase* enemy)
{
	Obj* bug = static_cast<Obj*>(enemy);
	Obj* seachingBugs[56];
	u8 bugCount = 0;
	if (!bug->mHadLookedForPartner && bug->_2C4 >= 2.0f) {
		bug->mHadLookedForPartner = true;
		Vector3f bugPos           = bug->getPosition();
		Mgr* mgr                  = static_cast<Mgr*>(generalEnemyMgr->getEnemyMgr(EnemyTypeID::EnemyID_ElecBug));
		if (mgr) {                                                                     // sanity check moment
			EnemyIterator<Obj> iElecBug = ((Container<Obj>*)(GenericContainer*)(mgr)); // this is correct... /shrug
			CI_LOOP(iElecBug)
			{
				Obj* otherBug = *iElecBug;
				if (bug != otherBug && otherBug->isBecomeChargeState()) {
					Vector3f otherPos = otherBug->getPosition();
					if (_distanceBetween(bugPos, otherPos) < 300.0f) {
						seachingBugs[bugCount] = otherBug;
						bugCount++;
					}
				}
			}
		}
		if (bugCount > 0) {
			Obj* randBug = seachingBugs[(int)(randFloat() * bugCount)];
			bug->startChargeState(randBug);
			bug->disableEvent(0, EB_IsCullable);
		}
	}
	Obj* partner = bug->mPartner;
	if (partner) {
		Vector3f partnerPos = partner->getPosition();
		partner->turnToTarget2(partnerPos, 0.15f, CG_PARMS(bug)->mGeneral.mRotationalSpeed.mValue);
	}
	if (bug->_2C4 >= 3.0f) {
		if (!bug->mPartner) {
			bug->finishPartnerAndEffect();
			transit(bug, ELECBUG_Turn, nullptr);
		} else {
			transit(bug, ELECBUG_Discharge, nullptr);
		}
	}
	bug->_2C4 += sys->mDeltaTime;
}
}
}