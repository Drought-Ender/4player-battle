#include "VsSlotCard.h"
#include "efx/TBarrier.h"
#include "efx/TOta.h"
#include "Game/MapMgr.h"
#include "efx/THdama.h"

#define HAZARD_BARRIER_DURATION (10.0f)

namespace Game {
namespace VsGame {

bool isPaused() { return gameSystem->paused() || GetVsGameSection()->mMenuFlags || moviePlayer->mDemoState; }

efx::TBase* HazardBarrier::MakeEfx(TeamID team)
{
	switch (team) {
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

f32 HazardBarrier::GetEfxTimer(TeamID team)
{
	switch (team) {
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

HazardBarrier::HazardBarrier(int teamID, Vector3f position)
    : TeamPositionEntity(teamID, position)
{
	mTimer    = 0.0f;
	mEfxTimer = 0.0f;

	mEfx = MakeEfx((TeamID)teamID);

	efx::Arg efxArg(mPosition);
	mEfx->create(&efxArg);

	mLifeGauge.mCurrentSegmentNum = 0;
}

bool HazardBarrier::update()
{
	mLifeGauge.update(0.0f, 1.0f - mTimer / HAZARD_BARRIER_DURATION);

	DebugReport("HazardBarrier::update\n");
	if (!isPaused()) {
		mTimer += sys->mDeltaTime;
		mEfxTimer += sys->mDeltaTime;
	}

	Sys::Sphere effectSphere(mPosition, 30.0f);
	CellIteratorArg arg = effectSphere;
	CellIterator iCell  = arg;

	CI_LOOP(iCell)
	{
		CellObject* obj = *iCell;
		if (!obj->isPiki() && !obj->isNavi())
			continue;

		FakePiki* piki = static_cast<FakePiki*>(obj);

		if (!piki->isAlive())
			continue;

		switch (mTeamID) {
		case TEAM_RED:
			InteractFire fire(nullptr, 10.0f);
			piki->stimulate(fire);
			break;
		case TEAM_BLUE:
			InteractBubble water(nullptr, 10.0f);
			piki->stimulate(water);
			break;
		case TEAM_WHITE:
			InteractGas gas(nullptr, 10.0f);
			piki->stimulate(gas);
			break;
		case TEAM_PURPLE:
			InteractSpore spore(nullptr, 10.0f);
			piki->stimulate(spore);
			break;
		}
	}

	if (mEfxTimer > GetEfxTimer((TeamID)mTeamID)) {
		mEfxTimer = 0.0f;
		efx::ArgBarrier efxArg(mPosition, mTeamID);
		mEfx->create(&efxArg);
	}

	return mTimer > HAZARD_BARRIER_DURATION;
}

HazardBarrier::~HazardBarrier() { mEfx->fade(); }

#define ICON_HEIGHT (50.0f)

void HazardBarrier::draw(Graphics& gfx)
{

	LifeGauge::initLifeGaugeDraw();

	Vector3f pos = mPosition;
	pos.y += ICON_HEIGHT;

	Viewport* cVp = gfx.mCurrentViewport;

	Matrixf* viewMtx = cVp->getMatrix(true);
	Matrixf transScaledMtx;
	transScaledMtx(0, 0) = viewMtx->mMatrix.mtxView[0][0];
	transScaledMtx(1, 0) = viewMtx->mMatrix.mtxView[0][1];
	transScaledMtx(2, 0) = viewMtx->mMatrix.mtxView[0][2];
	transScaledMtx(0, 1) = -viewMtx->mMatrix.mtxView[1][0];
	transScaledMtx(1, 1) = -viewMtx->mMatrix.mtxView[1][1];
	transScaledMtx(2, 1) = -viewMtx->mMatrix.mtxView[1][2];
	transScaledMtx(0, 2) = viewMtx->mMatrix.mtxView[2][0];
	transScaledMtx(1, 2) = viewMtx->mMatrix.mtxView[2][1];
	transScaledMtx(2, 2) = viewMtx->mMatrix.mtxView[2][2];

	transScaledMtx(0, 3) = pos.x;
	transScaledMtx(1, 3) = pos.y;
	transScaledMtx(2, 3) = pos.z;

	Mtx posMtx;
	PSMTXConcat(cVp->getMatrix(true)->mMatrix.mtxView, transScaledMtx.mMatrix.mtxView, posMtx);
	GXLoadPosMtxImm(posMtx, GX_MTX3x4);

	mLifeGauge.drawCherry(10.0f, 0.0f, 0.0f);
}

WaitEnemySpawn::WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime, JUTTexture* tex)
    : PositionEntity(position)
{
	mWaitTimer      = timer;
	mMaxWaitTimer   = timer;
	mExistenceTimer = existenceTime;
	mEntityID       = entityId;
	mIcon           = new HoveringFloatingIcon(tex, &mPosition, ICON_HEIGHT);

	init();
}

WaitEnemySpawn::WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime)
    : PositionEntity(position)
{
	mWaitTimer      = timer;
	mMaxWaitTimer   = timer;
	mExistenceTimer = existenceTime;
	mEntityID       = entityId;
	mIcon           = nullptr;

	init();
}

void WaitEnemySpawn::init()
{
	
	mEfx = new efx::THdamaSight;

	efx::Arg efxArg(mPosition);
	mEfx->create(&efxArg);

	if (mIcon) {
		FloatingIconMgr::add(mIcon);
	}
}

bool WaitEnemySpawn::update()
{

	mLifeGauge.update(0.0f, mWaitTimer / mMaxWaitTimer);

	if (!isPaused()) {
		mWaitTimer -= sys->mDeltaTime;
	}

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

void WaitEnemySpawn::draw(Graphics& gfx) {
	LifeGauge::initLifeGaugeDraw();

	Vector3f pos = mPosition;
	pos.y += ICON_HEIGHT + 20.0f;

	Viewport* cVp = gfx.mCurrentViewport;

	Matrixf* viewMtx = cVp->getMatrix(true);
	Matrixf transScaledMtx;
	transScaledMtx(0, 0) = viewMtx->mMatrix.mtxView[0][0];
	transScaledMtx(1, 0) = viewMtx->mMatrix.mtxView[0][1];
	transScaledMtx(2, 0) = viewMtx->mMatrix.mtxView[0][2];
	transScaledMtx(0, 1) = -viewMtx->mMatrix.mtxView[1][0];
	transScaledMtx(1, 1) = -viewMtx->mMatrix.mtxView[1][1];
	transScaledMtx(2, 1) = -viewMtx->mMatrix.mtxView[1][2];
	transScaledMtx(0, 2) = viewMtx->mMatrix.mtxView[2][0];
	transScaledMtx(1, 2) = viewMtx->mMatrix.mtxView[2][1];
	transScaledMtx(2, 2) = viewMtx->mMatrix.mtxView[2][2];

	transScaledMtx(0, 3) = pos.x;
	transScaledMtx(1, 3) = pos.y;
	transScaledMtx(2, 3) = pos.z;

	Mtx posMtx;
	PSMTXConcat(cVp->getMatrix(true)->mMatrix.mtxView, transScaledMtx.mMatrix.mtxView, posMtx);
	GXLoadPosMtxImm(posMtx, GX_MTX3x4);

	mLifeGauge.drawCherry(10.0f, 0.0f, 0.0f);
}

WaitEnemySpawn::~WaitEnemySpawn()
{
	mEfx->fade();
	delete mEfx;
}

EnemyBase* WaitEnemySpawn::birthFromSky()
{
	TekiMgr* tekiMgr = GetVsGameSection()->mCardMgr->mTekiMgr;
	EnemyBase* enemy = tekiMgr->birthFromSky(mEntityID, mPosition, mExistenceTimer);
	if (enemy) {
		enemy->setAnimSpeed(30.0f);
	}
	return enemy;
}

FloatingIconHolderBase::FloatingIconHolderBase(Vector3f position, JUTTexture* tex)
    : PositionEntity(position)
{
	mIcon = new HoveringFloatingIcon(tex, &mPosition, CARD_ICON_HEIGHT);
	FloatingIconMgr::add(mIcon);
}

FloatingIconHolderBase::~FloatingIconHolderBase()
{
	FloatingIconMgr::del(mIcon);
	delete mIcon;
}

FloatingIconHolderCallback::FloatingIconHolderCallback(Vector3f position, JUTTexture* tex, const BoolCallback* callback,
                                                       const CallbackArgs* args)
    : FloatingIconHolderBase(position, tex)
{
	mCallback = callback;
	mArgs     = args;
}

bool FloatingIconHolderCallback::update() { return mCallback(mPosition, mArgs); }

} // namespace VsGame

} // namespace Game
