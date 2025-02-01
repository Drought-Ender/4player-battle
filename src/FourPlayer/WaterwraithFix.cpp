#include "types.h"
#include "Game/Entities/BlackMan.h"
#include "Game/generalEnemyMgr.h"
#include "efx/TKage.h"
#include "PSSystem/PSMainSide_ObjSound.h"
#include "PSM/EnemyBoss.h"
#include "Game/MapMgr.h"
#include "Game/pathfinder.h"
#include "Game/routeMgr.h"
#include "Radar.h"
#include "Sys/MatBaseAnimation.h"
#include "Sys/MatBaseAnimator.h"
#include "Game/Navi.h"
#include "PSSystem/PSGame.h"
#include "PSSystem/PSScene.h"
#include "PSM/Scene.h"
#include "PSSystem/Seq.h"
#include "Game/MoviePlayer.h"
#include "JSystem/J3D/J3DTexMtx.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/mapParts.h"
#include "Game/EnemyFunc.h"
#include "Game/PikiMgr.h"
#include "Dolphin/rand.h"
#include "PS.h"
#include "Game/Cave/RandMapMgr.h"
#include "ModdingUtility/String.h"
#include "nans.h"

namespace Game
{
namespace BlackMan
{


// isWaypointTraversable__Q34Game8BlackMan3ObjFPQ24Game8WayPoint
bool Obj::isWaypointTraversable(WayPoint* wp) {
    OSReport("Waypoint %p\n", wp);
    FOREACH_NODE(WayPoint::RoomList, wp->mRoomList.mChild, room) {
        P2ASSERT(Cave::randMapMgr);
        const char* unitName = Cave::randMapMgr->getUseUnitName(room->mRoomIdx);
        string s = unitName;
        if (s.starts_with("way") && s.ends_with("pipe")) {
            return false;
        }
    }
    return true;
}

} // namespace BlackMan

} // namespace Game
