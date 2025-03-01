#include "Game/Entities/Hanachirashi.h"
#include "Game/Entities/Mar.h"
#include "Game/MapMgr.h"
#include "Game/EnemyFunc.h"
#include "Game/PikiMgr.h"
#include "Game/Navi.h"
#include "Dolphin/rand.h"

namespace Game {
namespace Hanachirashi {

Piki* Obj::getSearchedPikmin()
{
	f32 FOV      = PI;
	f32 sight    = C_GENERALPARMS.mSightRadius.mValue;
	f32 sqrSight = SQUARE(sight);
	if (mStuckPikminCount == 0) {
		FOV = C_GENERALPARMS.mViewAngle.mValue * DEG2RAD * PI;
	}

	Iterator<Piki> iPiki = pikiMgr;
	CI_LOOP(iPiki)
	{
		Piki* piki = *iPiki;
		if (piki->isAlive() && piki->isPikmin() && piki->mBounceTriangle && !piki->isStickToMouth() && piki->mSticker != this) {
			f32 sightDiff = getCreatureViewAngle(piki);
			if (FABS(sightDiff) <= FOV) {
				Vector3f pos      = getPosition();
				Vector3f pikiPos2 = piki->getPosition();
				if (sqrDistanceXZ(pikiPos2, pos) < sqrSight) {
					return piki;
				}
			}
		}
	}
	return nullptr;
}

} // namespace Hanachirashi
namespace Mar {

Piki* Obj::getSearchedPikmin()
{
	f32 FOV      = PI;
	f32 sight    = C_GENERALPARMS.mSightRadius.mValue;
	f32 sqrSight = SQUARE(sight);
	if (mStuckPikminCount == 0) {
		FOV = C_GENERALPARMS.mViewAngle.mValue * DEG2RAD * PI;
	}

	Iterator<Piki> iPiki = pikiMgr;
	CI_LOOP(iPiki)
	{
		Piki* piki = *iPiki;
		if (piki->isAlive() && piki->isPikmin() && piki->mBounceTriangle && !piki->isStickToMouth() && piki->mSticker != this) {
			f32 sightDiff = getCreatureViewAngle(piki);
			if (FABS(sightDiff) <= FOV) {
				Vector3f pikiPos2 = piki->getPosition();
				if (sqrDistanceXZ(mPosition, pikiPos2) < sqrSight) {
					return piki;
				}
			}
		}
	}
	return nullptr;
}

} // namespace Mar

} // namespace Game
