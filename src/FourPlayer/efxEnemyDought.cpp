#include "efx/TTank.h"
#include "efx/TDenki.h"
#include "JSystem/JParticle/JPAMath.h"
#include "Game/Entities/ElecHiba.h"
#include "efx/TBarrier.h"
#include "efx/TOta.h"
#include "efx/THibaFire.h"

namespace efx {

bool TTankGas::create(Arg* arg)
{
	mParticleCallBack.mEfxHit = &mEfxHit;
	mParticleCallBack.mEfxHit->create(nullptr);
	mParticleCallBack._04 = 1000.0f;
	if (TChaseMtx3::create(arg)) {
		for (int i = 0; i < ARRAY_SIZE(mItems); i++) {
			mItems[i].mEmitter->mParticleCallback = &mParticleCallBack;
		}
	}
	return true;
}

void TTankGas::forceKill()
{
	TChaseMtx3::forceKill();
	if (mParticleCallBack.mEfxHit) {
		mParticleCallBack.mEfxHit->forceKill();
	}
}

bool TTankSpore::create(Arg* arg)
{
	mParticleCallBack.mEfxHit = &mEfxHit;
	mParticleCallBack.mEfxHit->create(nullptr);
	mParticleCallBack._04 = 1000.0f;
	if (TChaseMtx4::create(arg)) {
		for (int i = 0; i < ARRAY_SIZE(mItems); i++) {
			mItems[i].mEmitter->mParticleCallback = &mParticleCallBack;
		}
	}
	return true;
}

void TTankSpore::forceKill()
{
	TChaseMtx4::forceKill();
	if (mParticleCallBack.mEfxHit) {
		mParticleCallBack.mEfxHit->forceKill();
	}
}

bool TBarrier::create(Arg* arg)
{
	P2ASSERTLINE(0x2EF, strcmp(arg->getName(), "ArgVsBarrier") == 0);
	ArgBarrier* denkiArg = static_cast<ArgBarrier*>(arg);
	if (!TSimple3::create(denkiArg)) {
		return false;
	}
	for (int i = 0; i < ARRAY_SIZE(mEmitters); i++) {
		JPABaseEmitter* emitter = mEmitters[i];
		if (emitter) {
			if (denkiArg->mVsHibaColor == 0) {
				emitter->mColor1.r = 0xff;
				emitter->mColor1.g = 0x00;
				emitter->mColor1.b = 0x00;
				emitter->mColor2.r = 0xff;
				emitter->mColor2.g = 0x00;
				emitter->mColor2.b = 0x00;
			} else if (denkiArg->mVsHibaColor == 1) {
				emitter->mColor1.r = 0x00;
				emitter->mColor1.g = 0x00;
				emitter->mColor1.b = 0xff;
				emitter->mColor2.r = 0x00;
				emitter->mColor2.g = 0x00;
				emitter->mColor2.b = 0xff;
			} else if (denkiArg->mVsHibaColor == 2) {
				emitter->mColor1.r = 0x80;
				emitter->mColor1.g = 0x80;
				emitter->mColor1.b = 0xff;
				emitter->mColor2.r = 0x80;
				emitter->mColor2.g = 0x80;
				emitter->mColor2.b = 0xff;
			} else if (denkiArg->mVsHibaColor == 3) {
				emitter->mColor1.r = 0x40;
				emitter->mColor1.g = 0x00;
				emitter->mColor1.b = 0xff;
				emitter->mColor2.r = 0x80;
				emitter->mColor2.g = 0x00;
				emitter->mColor2.b = 0xff;
			}
		}
	}
	return true;
}

bool TDenkiHiba::create(Arg* arg)
{
	P2ASSERTLINE(0x2EF, strcmp(arg->getName(), "ArgDenkiHiba") == 0);
	ArgDenkiHiba* denkiArg = static_cast<ArgDenkiHiba*>(arg);
	Vector3f startPos      = denkiArg->mOwnerPos;
	Vector3f endPos        = denkiArg->mTargetPos;
	if (!TForever3::create(denkiArg)) {
		return false;
	}
	Matrixf matrix;
	makeMtxZAxisAlongPosPos(matrix.mMatrix.mtxView, startPos, endPos);

	for (int i = 0; i < ARRAY_SIZE(mItems); i++) {
		JPABaseEmitter* emitter = mItems[i].mEmitter;
		if (emitter) {
			JPASetRMtxTVecfromMtx(matrix.mMatrix.mtxView, emitter->_68, &emitter->mPositon);
			if (denkiArg->mVsHibaColor == Game::ElecHiba::VHT_Red) {
				emitter->mColor1.r = 0xff;
				emitter->mColor1.g = 0x00;
				emitter->mColor1.b = 0x00;
				emitter->mColor2.r = 0xff;
				emitter->mColor2.g = 0x00;
				emitter->mColor2.b = 0x00;
			} else if (denkiArg->mVsHibaColor == Game::ElecHiba::VHT_Blue) {
				emitter->mColor1.r = 0x00;
				emitter->mColor1.g = 0x00;
				emitter->mColor1.b = 0xff;
				emitter->mColor2.r = 0x00;
				emitter->mColor2.g = 0x00;
				emitter->mColor2.b = 0xff;
			} else if (denkiArg->mVsHibaColor == Game::ElecHiba::VHT_White) {
				emitter->mColor1.r = 0x80;
				emitter->mColor1.g = 0x80;
				emitter->mColor1.b = 0xff;
				emitter->mColor2.r = 0x80;
				emitter->mColor2.g = 0x80;
				emitter->mColor2.b = 0xff;
			} else if (denkiArg->mVsHibaColor == Game::ElecHiba::VHT_Purple) {
				emitter->mColor1.r = 0x40;
				emitter->mColor1.g = 0x00;
				emitter->mColor1.b = 0xff;
				emitter->mColor2.r = 0x80;
				emitter->mColor2.g = 0x00;
				emitter->mColor2.b = 0xff;
			}
		}
	}

	float scale = _normaliseDistance(startPos, endPos) / 120.0f;

	mItems[0].mEmitter->mScale = Vector3f(1.0f, 1.0f, scale);
	mItems[1].mEmitter->mScale = Vector3f(1.0f, scale, 1.0f);
	Vector3f& highScale        = mItems[2].mEmitter->mScale;
	highScale                  = Vector3f(highScale.x, highScale.y * scale, highScale.z);
	return true;
}

} // namespace efx
