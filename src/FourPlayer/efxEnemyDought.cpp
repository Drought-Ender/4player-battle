#include "efx/TTank.h"

namespace efx
{

bool TTankGas::create(Arg* arg) {
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

void TTankGas::forceKill() {
    TChaseMtx3::forceKill();
    if (mParticleCallBack.mEfxHit) {
        mParticleCallBack.mEfxHit->forceKill();
    }
}


bool TTankSpore::create(Arg* arg) {
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

void TTankSpore::forceKill() {
    TChaseMtx4::forceKill();
    if (mParticleCallBack.mEfxHit) {
        mParticleCallBack.mEfxHit->forceKill();
    }
}


} // namespace efx
