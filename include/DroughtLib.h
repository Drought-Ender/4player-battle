#include "types.h"
#include "CNode.h"
#include "Game/CurrTriInfo.h"
#include "Game/MapMgr.h"

#ifndef _DROUGHTLIB_H_
#define _DROUGHTLIB_H_


namespace DroughtLib
{


    
    inline void RotateXZ(Vector3f& vec, f32 theta) {
        vec.x = vec.x * pikmin2_cosf(theta) - vec.z * pikmin2_sinf(theta);
        vec.z = vec.z * pikmin2_sinf(theta) + vec.x * pikmin2_sinf(theta);
    }
    
    inline bool hasValidFloor(Vector3f& vec) {
        Game::CurrTriInfo triSpawn;
        triSpawn.mTriangle = nullptr;
        triSpawn.mMaxY = FLOAT_DIST_MAX;
        triSpawn.mMinY = FLOAT_DIST_MIN;
        triSpawn.mTable = nullptr;
        triSpawn.mNormalVec = Vector3f(0.0f, 1.0f, 0.0f);
        triSpawn._0D = 0;
        triSpawn.mPosition = vec;
        triSpawn._0C = 0;
        Game::mapMgr->getCurrTri(triSpawn);
        return triSpawn.mTriangle;
    }

} // namespace DroughtLib

#endif 