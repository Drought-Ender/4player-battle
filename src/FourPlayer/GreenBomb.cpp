#include "Game/Entities/GreenBomb.h"

namespace Game
{

namespace GreenBomb
{

void Obj::onInit(CreatureInitArg* settings) {
    Bomb::Obj::onInit(settings);
    mIsStuck = false;
}

void Obj::bounceCallback(Sys::Triangle* tri) {
    Bomb::Obj::bounceCallback(tri);

    enableEvent(0, EB_IsHardConstraint);

    mIsStuck = true;
}

void Obj::collisionCallback(CollEvent& event) {
    Bomb::Obj::collisionCallback(event);

    if (event.mCollidingCreature->isNavi() || event.mCollidingCreature->isPiki()) {
        return;
    }

    if (!mIsStuck && event.mCollisionObj && event.mCollisionObj->isStickable()) {
        startStick(event.mCollidingCreature, event.mCollisionObj);
        enableEvent(0, EB_Constraint);
        forceBomb();
        mIsStuck = true;
    }
    else if (event.mCollidingCreature->mBounceTriangle) {
        enableEvent(0, EB_IsHardConstraint);
        forceBomb();
        mIsStuck = true;
    }
}

} // namespace GreenBomb


} // namespace Game
