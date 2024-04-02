#include "VsSlotCard.h"
#include "efx/TBarrier.h"
#include "efx/TOta.h"
#include "Game/MapMgr.h"
#include "efx/THdama.h"


namespace Game
{
namespace VsGame
{

efx::TBase* HazardBarrier::MakeEfx(TeamID team) {
    switch (team)
    {
    case TEAM_RED:
        return new efx::TOtaFire;
    case TEAM_BLUE:
        return new efx::TOtaWat;
    case TEAM_WHITE:
        return new efx::TOtaGas;
    case TEAM_PURPLE:
        return new efx::TOtaSpore;
    }
    JUT_PANIC("INVALID TEAM ID %i\n", team);
}

f32 HazardBarrier::GetEfxTimer(TeamID team) {
    switch (team)
    {
    case TEAM_RED:
        return 1.0f;
    case TEAM_BLUE:
        return 0.5f;
    case TEAM_WHITE:
        return 0.5f;
    case TEAM_PURPLE:
        return 0.5f;
    }
    JUT_PANIC("INVALID TEAM ID %i\n", team);
}

HazardBarrier::HazardBarrier(int teamID, Vector3f position) : TeamPositionEntity(teamID, position) {
    mTimer = 0.0f;
    mEfxTimer = 0.0f;

    mEfx = MakeEfx((TeamID)teamID);

    efx::Arg efxArg (mPosition);
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

    if (mEfxTimer > GetEfxTimer((TeamID)mTeamID)) {
        mEfxTimer = 0.0f;
        efx::ArgBarrier efxArg (mPosition, mTeamID);
        mEfx->create(&efxArg);
    }

    return mTimer > 30.0f;
}

HazardBarrier::~HazardBarrier() {
    mEfx->fade();
}


WaitEnemySpawn::WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime, JUTTexture* tex) : PositionEntity(position) {
    mWaitTimer = timer;
    mExistenceTimer = existenceTime;
    mEntityID = entityId;
    mIcon = new FloatingIcon(tex, &mIconPos);

    init();
}

WaitEnemySpawn::WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime) : PositionEntity(position) {
    mWaitTimer = timer;
    mExistenceTimer = existenceTime;
    mEntityID = entityId;
    mIcon = nullptr;
    

    init();

    
}

#define ICON_HEIGHT (70.0f)

void WaitEnemySpawn::init() {
    mIconPos = mPosition;
    mIconPos.y += ICON_HEIGHT;

    mEfx = new efx::THdamaSight;

    efx::Arg efxArg (mPosition);
    mEfx->create(&efxArg);

    if (mIcon) {
        FloatingIconMgr::add(mIcon);
    }
}

bool WaitEnemySpawn::update() {
    mWaitTimer -= sys->mDeltaTime;
    
    if (mWaitTimer < 0.0f) {
        if (mIcon) {
            FloatingIconMgr::del(mIcon);
            delete mIcon;
            mIcon = nullptr;
        }
        birthFromSky();
        return true;
    }
    return false;
}

WaitEnemySpawn::~WaitEnemySpawn() {
    mEfx->fade();
    delete mEfx;
}

EnemyBase* WaitEnemySpawn::birthFromSky() {
    TekiMgr* tekiMgr = GetVsGameSection()->mCardMgr->mTekiMgr;
    EnemyBase* enemy = tekiMgr->birthFromSky(mEntityID, mPosition, mExistenceTimer);
    if (enemy) {
        enemy->setAnimSpeed(30.0f);
    }
    return enemy;
}

} // namespace VsGame

} // namespace Game
