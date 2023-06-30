#include "Game/GameSystem.h"
#include "Game/GameConfig.h"
#include "Game/Cave/RandMapMgr.h"
#include "Game/mapParts.h"
#include "types.h"

namespace Game {
namespace Cave {
extern RandMapMgr* randMapMgr;
} // namespace Cave

/*
 * --INFO--
 * Address:	8024C5E4
 * Size:	0000F0
 */
void RoomMapMgr::nishimuraCreateRandomMap(MapUnitInterface* muiArray, int p2, Cave::FloorInfo* floorInfo, bool lastFloor,
                                          Cave::EditMapUnit* unit)
{
	bool isVersusHiba = false;
	if (gameSystem && gameSystem->isVersusMode() && gGameConfig.mParms.mVsHiba.mData) {
		isVersusHiba = true;
	}

	Cave::randMapMgr = new Cave::RandMapMgr(isVersusHiba);
	Cave::randMapMgr->loadResource(muiArray, p2, floorInfo, lastFloor, unit);
	Cave::randMapMgr->create();

	const int numRooms = Cave::randMapMgr->getNumRooms();
	for (int i = 0; i < numRooms; i++) {
		char* name = Cave::randMapMgr->getUseUnitName(i);
		useUnit(name);
	}
}

void RoomMapMgr::getStartPosition(Vector3f& pos, int idx) {
	OSReport("RoomMapMgr::getStartPosition(Vector3f&, int)\n");
	P2ASSERT(mStartPositions);
	pos = mStartPositions[idx];
}

/*
 * --INFO--
 * Address:	8024C6D4
 * Size:	00011C
 */
void RoomMapMgr::nishimuraPlaceRooms()
{
	const int numRooms = Cave::randMapMgr->getNumRooms();
	OSReport("Room count %i\n", numRooms);
	allocRooms(numRooms);

	for (int index = 0; index < numRooms; index++) {
		float centreX;
		float centreY;
		int direction;
		OSReport("RandMapMgr::getRoomData(int, f32&, f32&, int&)\n");
		char* unitName         = Cave::randMapMgr->getRoomData(index, centreX, centreY, direction); // sets centreX, centreY, and direction
		OSReport("RandMapMgr::makeRoomLink(int)\n");
		RoomLink* pRoomLink    = Cave::randMapMgr->makeRoomLink(index);
		OSReport("RandMapMgr::makeObjectLayoutInfo(int)\n");
		ObjectLayoutInfo* pOLI = Cave::randMapMgr->makeObjectLayoutInfo(index);

		OSReport("RoomMapMgr::makeRoom(char*, f32, f32, int, int, RoomLink*, ObjectLayoutInfo*)\n");
		makeRoom(unitName, centreX, centreY, direction, index, pRoomLink, pOLI);
	}

	mStartPositions = new Vector3f[4];

	for (int i = 0; i < 4; i++) {
		Vector3f startPos(0.0f, 0.0f, 0.0f);
		Cave::randMapMgr->getStartPosition(startPos, i);

		mStartPositions[i].x = startPos.x;
		mStartPositions[i].y = startPos.y;
		mStartPositions[i].z = startPos.z;
	}
	OSReport("Done\n");
}

/*
 * --INFO--
 * Address:	8024C7F0
 * Size:	000088
 */
void RoomMapMgr::nishimuraSetTexture()
{
	const int numRooms = Cave::randMapMgr->getNumRooms();
	for (int i = 0; i < numRooms; i++) {
		char* unitName      = Cave::randMapMgr->getUseUnitName(i);
		JUTTexture* texture = getTexture(unitName);
		Cave::randMapMgr->setUnitTexture(i, texture);
	}
}
} // namespace Game
