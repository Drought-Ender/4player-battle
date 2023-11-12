#include "VsSlotCard.h"
#include "efx/TBarrier.h"
#include "Game/MapMgr.h"


namespace Game
{
namespace VsGame
{

HazardBarrier::HazardBarrier(int teamID, Vector3f position) : TeamPositionEntity(teamID, position) {
    mTimer = 0.0f;
    mEfxTimer = 0.0f;

    mEfx = new efx::TBarrier;

    efx::ArgBarrier efxArg (mPosition, mTeamID);
    mEfx->create(&efxArg);
}

bool HazardBarrier::update() {
    DebugReport("HazardBarrier::update\n");
    mTimer    += sys->mDeltaTime;
    mEfxTimer += sys->mDeltaTime;

    Sys::Sphere effectSphere (mPosition, 30.0f);
    CellIteratorArg arg = effectSphere;
    CellIterator iCell = arg;

    CI_LOOP(iCell) {
        CellObject* obj = *iCell;
        if (!obj->isPiki() && !obj->isNavi()) continue;

        FakePiki* piki = static_cast<FakePiki*>(obj);

        if (!piki->isAlive()) continue;
        
        switch (mTeamID)
        {
        case TEAM_RED:
            InteractFire fire (nullptr, 10.0f);
            piki->stimulate(fire);
            break;
        case TEAM_BLUE:
            InteractBubble water (nullptr, 10.0f);
            piki->stimulate(water);
            break;
        case TEAM_WHITE:
            InteractGas gas (nullptr, 10.0f);
            piki->stimulate(gas);
            break;
        case TEAM_PURPLE:
            InteractSpore spore (nullptr, 10.0f);
            piki->stimulate(spore);
            break;
        }
    }

    if (mEfxTimer > 0.5f) {
        mEfxTimer = 0.0f;
        efx::ArgBarrier efxArg (mPosition, mTeamID);
        mEfx->create(&efxArg);
    }

    return mTimer > 30.0f;
}

HazardBarrier::~HazardBarrier() {
    mEfx->fade();
}

} // namespace VsGame

} // namespace Game
