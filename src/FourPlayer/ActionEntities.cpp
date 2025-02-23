#include "VsSlotCard.h"
#include "efx/TBarrier.h"
#include "efx/TOta.h"
#include "Game/MapMgr.h"
#include "efx/THdama.h"
#include "Game/Entities/ItemPikihead.h"
#include "PSM/Navi.h"
#include "Game/PikiState.h"
#include "efx/TChibi.h"
#include "PSSystem/PSSystemIF.h"
#include "ModdingUtility/List.h"
#include "PS.h"

#define HAZARD_BARRIER_DURATION (10.0f)
#define PLUCKFUE_DURATION       (1.5f)
#define PLUCKFUE_SIZE           (100.0f)
#define PLUCKFUE_PIKI_COUNT     (30)

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

bool TeamPositionTimerEntity::update()
{
	if (!isPaused()) {
		mTimer -= sys->mDeltaTime;
	}
	mLifeGauge.update(0.0f, mTimer / mMaxTimer);

	return mTimer <= 0.0f;
}

void TeamPositionTimerEntity::drawLifeGauge(Graphics& gfx, f32 height)
{
	LifeGauge::initLifeGaugeDraw();

	Vector3f pos = getPosition();
	pos.y += height;

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

bool PositionTimerEntity::update()
{
	if (!isPaused()) {
		mTimer -= sys->mDeltaTime;
	}
	mLifeGauge.update(0.0f, mTimer / mMaxTimer);

	return mTimer <= 0.0f;
}

void PositionTimerEntity::drawLifeGauge(Graphics& gfx, f32 height)
{
	LifeGauge::initLifeGaugeDraw();

	Vector3f pos = getPosition();
	pos.y += height;

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

HazardBarrier::HazardBarrier(int teamID, Vector3f position)
    : TeamPositionTimerEntity(teamID, position, HAZARD_BARRIER_DURATION)
{
	mEfxTimer = 0.0f;

	mEfx = MakeEfx((TeamID)teamID);

	efx::Arg efxArg(mPosition);
	mEfx->create(&efxArg);
}

bool HazardBarrier::update()
{
	bool done = TeamPositionTimerEntity::update();

	DebugReport("HazardBarrier::update\n");
	if (!isPaused()) {
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

	return done;
}

HazardBarrier::~HazardBarrier()
{
	mEfx->fade();
	delete mEfx;
}

#define ICON_HEIGHT (50.0f)

void HazardBarrier::draw(Graphics& gfx) { drawLifeGauge(gfx, ICON_HEIGHT); }

WaitEnemySpawn::WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime, JUTTexture* tex)
    : PositionTimerEntity(position, timer)
{
	mMaxWaitTimer   = timer;
	mExistenceTimer = existenceTime;
	mEntityID       = entityId;
	mIcon           = new HoveringFloatingIcon(tex, &mPosition, ICON_HEIGHT);

	init();
}

WaitEnemySpawn::WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime)
    : PositionTimerEntity(position, timer)
{
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
	PositionTimerEntity::update();

	if (mTimer < 0.0f) {
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

void WaitEnemySpawn::draw(Graphics& gfx) { drawLifeGauge(gfx, ICON_HEIGHT + 20.0f); }

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

FloatingIconInitializer::FloatingIconInitializer(const Vector3f* vecPtr, JUTTexture* tex, f32 offs)
{
	mIsHide = false;
	mIcon   = new HoveringFloatingIcon(tex, vecPtr, offs);
	FloatingIconMgr::add(mIcon);
}

FloatingIconInitializer::~FloatingIconInitializer()
{
	if (!mIsHide) {
		FloatingIconMgr::del(mIcon);
	}
	delete mIcon;
}

bool FloatingIconInitializer::show()
{
	if (mIsHide) {
		FloatingIconMgr::add(mIcon);
		mIsHide = false;
	}
}

bool FloatingIconInitializer::hide()
{
	if (!mIsHide) {
		FloatingIconMgr::del(mIcon);
		mIsHide = true;
	}
}

PluckAllFue::PluckAllFue(const Navi* navi, int teamID, Vector3f pos, JUTTexture* tex)
    : TeamPositionTimerEntity(teamID, pos, PLUCKFUE_DURATION)
    , mPluckedPikiCount(0)
    , mIconContainer(&mPosition, tex, ICON_HEIGHT)
    , mNaviPtr(navi)
{
	init();
}

void PluckAllFue::init()
{
	mEfxWhistle = new efx::TCursor(1);

	efx::ArgCursor argCursor(mPosition, 0.0f);
	mEfxWhistle->create(&argCursor);
}

void PluckAllFue::updateWhistleEffect(f32 scale)
{
	efx::ArgCursor argCursor(mPosition, scale);
	mEfxWhistle->update(&argCursor);
}

bool PluckAllFue::update()
{
	// mNaviPtr->mSoundObj->playShugoSE();

	mNaviPtr->mSoundObj->startSound(PSSE_EN_FUEFUKI_WHISTLE, 0);

	mPosition = const_cast<Navi*>(mNaviPtr)->getPosition();

	f32 activeTimer = mMaxTimer - mTimer;
	if (activeTimer > 1.0f) {
		activeTimer = 1.0f;
	}

	f32 whistleRadius = activeTimer * PLUCKFUE_SIZE;

	updateWhistleEffect(whistleRadius);
	pluckPikis(whistleRadius);

	return TeamPositionTimerEntity::update();
}

void PluckAllFue::draw(Graphics& gfx) { }

void PluckAllFue::pluckPikis(f32 radius)
{

	if (mPluckedPikiCount >= PLUCKFUE_PIKI_COUNT) {
		return;
	}

	Iterator<ItemPikihead::Item> iPikiHead = ItemPikihead::mgr;

	int pikiColor = getPikiFromTeamEnum(mTeamID);
	CI_LOOP(iPikiHead)
	{
		ItemPikihead::Item* pikiHead = *iPikiHead;
		if (pikiHead->mColor == pikiColor && pikiHead->isAlive() && sqrDistanceXZ(pikiHead->mPosition, mPosition) < SQUARE(radius)) {
			if (!pikiHead->canPullout())
				continue;
			PikiMgr::mBirthMode = 1;
			Piki* pluckedPiki   = pikiMgr->birth();
			PikiMgr::mBirthMode = 0;
			if (pluckedPiki) {
				pluckedPiki->init(nullptr);
				pluckedPiki->changeShape(pikiHead->mColor);
				pluckedPiki->changeHappa(pikiHead->mHeadType);
				pluckedPiki->setPosition(pikiHead->mPosition, false);
				pluckedPiki->mNavi = const_cast<Navi*>(mNaviPtr);
				pluckedPiki->mFsm->transit(pluckedPiki, PIKISTATE_AutoNuki, nullptr);
				pikiHead->kill(nullptr);
				pikiHead->setAlive(false);

				mPluckedPikiCount++;
				break;
			}
		}
	}
}

PluckAllFue::~PluckAllFue()
{
	mEfxWhistle->fade();
	delete mEfxWhistle;
}

StunStorm::StunStorm(Navi* user, Navi* target, JUTTexture* tex)
    : mUser(user)
    , mTarget(target)
    , mIconContainer(&user->mPosition3, tex, ICON_HEIGHT)
{


	ModdingUtility::List<int> randomNotes(STUN_STORM_BEAT_COUNT, 0);

	ModdingUtility::ListIterator<int> iList = &randomNotes;

	int n = 0;

	CI_LOOP(iList) {
		int& obj = *iList;
		obj = n++;
	}


	for (int i = 0; i < ARRAY_SIZE(mShells); i++) {
		int spawnBeatIdx = randomNotes.pop_value(randFloat() * (STUN_STORM_BEAT_COUNT - i));

		f32 rounding   = STUN_STORM_MAX_LENGTH / 32.0f; // 4 measures of 8th notes
		f32 spawnTimer = spawnBeatIdx * rounding;
		mShells[i].setTimer(spawnTimer);
	}

}

StunStorm::~StunStorm() { }

bool StunStorm::update()
{
	bool b = true;
	for (int i = 0; i < ARRAY_SIZE(mShells); i++) {
		b = mShells[i].update(mUser, mTarget) && b;
	}
	return b;
}

StunStorm::Shell::Shell()
{
	mShellEfx            = new efx::TChibiShell;
	mShellEfx->mPosition = &mPosition;

	mPosition = 0.0f;
}

StunStorm::Shell::~Shell()
{
	mShellEfx->fade();
	delete mShellEfx;
}

void StunStorm::Shell::setTimer(f32 f) { mTimer = -f - STUN_STORM_STARTUP; }

void StunStorm::Shell::init(Vector3f& pos)
{
	PSStartSoundVec(PSSE_EN_HOUDAI_SHOT, (Vec*)&pos);
	mPosition = pos;

	mShellEfx->create(nullptr);
}

void StunStorm::Shell::hit(Vector3f& pos)
{
	PSStartSoundVec(PSSE_EN_HOUDAI_IMPACT, (Vec*)&pos);

	mPosition = pos;

	mShellEfx->fade();

	efx::ArgScale fxArg(pos, 1.0f);
	efx::TChibiHit hitFX;
	hitFX.create(&fxArg);

	f32 radius = STUN_SHELL_ATTACK_RADIUS;

	Sys::Sphere sphere(pos, radius);
	CellIteratorArg ciArg(sphere);
	CellIterator iCell = ciArg;

	CI_LOOP(iCell)
	{
		CellObject* obj = *iCell;

		if (obj->isPiki() || obj->isNavi()) {
			FakePiki* creature = static_cast<FakePiki*>(obj);

			Vector3f creaturePos = creature->getPosition();
			f32 dist             = pos.distance(creaturePos);
			Vector3f targetSep   = creaturePos - pos;
			f32 factor           = dist / radius;
			f32 mag              = 150.0f * (1.0f - factor) + 75.0f * factor;
			targetSep.y          = 0.0f;
			targetSep.normalise();
			if (obj->isPiki()) {
				targetSep.y = 1.0f;
			}

			targetSep *= mag;

			InteractWind wind(nullptr, 0.0f, &targetSep);
			creature->stimulate(wind);
		}
	}
}

bool StunStorm::Shell::update(Navi* user, Navi* target)
{

	if (mTimer <= 0.0f) {
		mTimer += sys->mDeltaTime;
		if (mTimer > 0.0f) {
			init(user->mPosition3);
		}
	} else if (mTimer <= STUN_STORM_WAIT_TIMER) {
		mTimer += sys->mDeltaTime;
		updateFly(user);
		if (mTimer >= STUN_STORM_WAIT_TIMER) {
			mPosition   = target->getPosition();
			mPosition.y = STUN_SHELL_MAX_HEIGHT + mapMgr->getMinY(mPosition);
		}
	} else if (mTimer <= STUN_STORM_WAIT_TIMER + STUN_STORM_FALL_TIMER) {
		mTimer += sys->mDeltaTime;
		updateLand(target);

		if (mTimer >= STUN_STORM_WAIT_TIMER + STUN_STORM_FALL_TIMER) {
			mPosition.y = mapMgr->getMinY(mPosition);
			hit(mPosition);
		}
	} else {
		return true;
	}

	return false;
}

void StunStorm::Shell::updateFly(Navi* user)
{

	const f32 velocity = STUN_SHELL_MAX_HEIGHT / STUN_STORM_WAIT_TIMER;

	mPosition.y += velocity * sys->mDeltaTime;
}

void StunStorm::Shell::updateLand(Navi* target)
{

	const f32 velocity = STUN_SHELL_MAX_HEIGHT / STUN_STORM_FALL_TIMER;

	mPosition.y -= velocity * sys->mDeltaTime;
}

} // namespace VsGame

} // namespace Game
