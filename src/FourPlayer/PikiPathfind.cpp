#include "PikiAI.h"
#include "Game/Piki.h"
#include "Game/routeMgr.h"
#include "Game/MapMgr.h"
#include "Game/pathfinder.h"
#include "Game/GameSystem.h"
#include "Game/Cave/RandMapMgr.h"

namespace PikiAI {

ActPathfind::ActPathfind(Game::Piki* piki)
    : Action(piki)
{
}

void ActPathfind::init(ActionArg* settings)
{
	PathfindArg* arg = static_cast<PathfindArg*>(settings);
	mTargetPosition  = arg->mTargetPos;

	Vector3f ourPosition = mParent->getPosition();

	if (sqrDistanceXZ(ourPosition, mTargetPosition) < SQUARE(10.0f) || initPathfinding() != 1) {
		mState = 4;
	} else {
		OSReport("START PATHFIND\n");
		mParent->startMotion(Game::IPikiAnims::WALK, Game::IPikiAnims::WALK, nullptr, nullptr);
	}
}

bool ActPathfind::initPathfinding()
{
	Vector3f currPos = mParent->getPosition();

	Game::WPEdgeSearchArg arg(currPos);
	if (mParent->inWater()) {
		arg.mInWater = true;
	}

	s16 roomindex = mParent->mRoomIndex;
	if (Game::gameSystem->mIsInCave) {
		Sys::Sphere sphere;
		sphere.mPosition = currPos;
		sphere.mRadius   = 1.0f;

		roomindex = static_cast<Game::RoomMapMgr*>(Game::mapMgr)->findRoomIndex(sphere);
	}
	arg.mHandles = nullptr;

	Game::WayPoint* start;
	if (Game::mapMgr->mRouteMgr->getNearestEdge(arg)) {
		Game::WayPoint* wp = arg.mWp1;
		if (!(wp->mFlags & Game::WPF_Closed)) {
			start = wp;
		} else {
			start = arg.mWp2;
		}
	} else if (Game::mapMgr->mRouteMgr->getNearestEdge(arg)) {
		Game::WayPoint* wp = arg.mWp1;
		if ((wp->mFlags & Game::WPF_Closed)) {
			start = arg.mWp2;
		} else {
			start = wp;
		}
	} else {
		return 2; // exit state
	}

	mPathCheckID = 0;

	Game::WPSearchArg arg2(mTargetPosition, nullptr, false, 100.0f);
	Game::WayPoint* end = Game::mapMgr->mRouteMgr->getNearestWayPoint(arg2);
	if (!end) {
		return 2; // exit state

	} else {
		// efx::TPodOpenA* pod = new efx::TPodOpenA;
		// efx::Arg efxarg (start->getPosition());
		// pod->create(&efxarg);
		// pod = new efx::TPodOpenA;
		// efx::Arg efxarg2 (end->getPosition());
		// pod->create(&efxarg2);

		Game::PathfindRequest req(start->mIndex, end->mIndex, 0x47);
		mPathCheckID = Game::testPathfinder->start(req);
		mState       = 0;
		return 1;
	}
}

int ActPathfind::execPathfinding()
{
	if (mPathCheckID == 0) {
		return 2;
	}

	int state = Game::testPathfinder->check(mPathCheckID);
	mAttempts++;
	switch (state) {
	case 0:
		mPathNodes    = Game::testPathfinder->makepath(mPathCheckID, &mPathNode);
		mPathNodePrev = mPathNode;
		mState        = 1;
		break;
	case 1:
		return 2;
	}
	if (mAttempts > 100) {

		return 2;
	}
	return 0;
}

int ActPathfind::exec()
{
	bool end = false;
	switch (mState) {
	case 0:
		int check = execPathfinding();

		if (check == 2) {
			end = true;
			break;
		}

		break;
	case 1: {
		if (execMove())
			mState = 3;
		return ACTEXEC_Continue;
	}
	case 2: {
		if (execMoveGoal())
			mState = 4;
		break;
	}
	case 3: {
		mState    = 1;
		mPathNode = mPathNode->mNext;
		if (!mPathNode) {
			mState = 2;
		}
		break;
	}
	case 4: {
		end = true;
		break;
	}
	}

	if (end) {
		if (mPathCheckID) {
			Game::testPathfinder->release(mPathCheckID);
		}
		return ACTEXEC_Success;
	}
	return ACTEXEC_Continue;
}

bool ActPathfind::execMove()
{
	Game::WayPoint* wp      = Game::mapMgr->mRouteMgr->getWayPoint(mPathNode->mWpIndex);
	Vector3f targetPosition = wp->getPosition();

	Vector3f deltaPos = targetPosition - mParent->getPosition();
	Vector3f dir      = deltaPos;
	dir.normalise();

	mParent->setSpeed(1.0f, dir);

	return deltaPos.sqrMagnitude() < SQUARE(wp->mRadius);
}

bool ActPathfind::execMoveGoal()
{
	Vector3f targetPosition = mTargetPosition;

	Vector3f deltaPos = targetPosition - mParent->getPosition();
	Vector3f dir      = deltaPos;
	dir.normalise();

	mParent->setSpeed(1.0f, dir);

	return deltaPos.sqrMagnitude() < SQUARE(10.0f);
}

void ActPathfind::cleanup()
{
	if (mPathCheckID) {
		Game::testPathfinder->release(mPathCheckID);
	}
}

} // namespace PikiAI
