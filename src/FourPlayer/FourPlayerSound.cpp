#include "Camera.h"
#include "Game/AILOD.h"
#include "Game/Creature.h"
#include "Game/GameSystem.h"
#include "Graphics.h"
#include "JSystem/JFramework/JFWSystem.h"
#include "JSystem/JUtility/JUTException.h"
#include "Sys/Sphere.h"
#include "types.h"
#include "System.h"
#include "Sys/Cylinder.h"
#include "Viewport.h"
#include "FourPlayer.h"
#include "Game/Navi.h"
#include "PSM/Director.h"

// interactive__FPQ23PSM20ActorDirector_Scaled
float interactive(PSM::ActorDirector_Scaled* director)
{
	if (Game::gNaviNum == 2)
		return director->getNearestDistance();

	float dist = 10000.0f;
	int* init;
	float p1dist = 32768.0f;
	float p2dist = 32768.0f;
	float p3dist = 32768.0f;
	float p4dist = 32768.0f;

	init                   = (int*)((int*)director)[0x19];
	init                   = init + 3;
	Game::Creature** actor = (Game::Creature**)*init;

	Game::Creature* creature = *actor;

	Vector3f actorPos;
	Vector3f p1Pos;
	Vector3f p2Pos;
	Vector3f p3Pos;
	Vector3f p4Pos;

	Game::Navi* navi1 = Game::naviMgr->getAt(0);
	Game::Navi* navi2 = Game::naviMgr->getAt(1);
	Game::Navi* navi3 = Game::naviMgr->getAt(2);
	Game::Navi* navi4 = Game::naviMgr->getAt(3);

	if (navi1 != 0)
		p1Pos = navi1->getPosition();

	if (navi2 != 0)
		p2Pos = navi2->getPosition();

	if (navi3 != 0 && Game::gNaviNum > 2)
		p3Pos = navi3->getPosition();

	if (navi4 != 0 && Game::gNaviNum > 3)
		p4Pos = navi4->getPosition();

	if (actor != 0) {
		actorPos = creature->getPosition();

		p1dist = (actorPos.x - p1Pos.x) * (actorPos.x - p1Pos.x) + (actorPos.y - p1Pos.y) * (actorPos.y - p1Pos.y)
		       + (actorPos.z - p1Pos.z) * (actorPos.z - p1Pos.z);
		p2dist = (actorPos.x - p2Pos.x) * (actorPos.x - p2Pos.x) + (actorPos.y - p2Pos.y) * (actorPos.y - p2Pos.y)
		       + (actorPos.z - p2Pos.z) * (actorPos.z - p2Pos.z);
		p3dist = (actorPos.x - p3Pos.x) * (actorPos.x - p3Pos.x) + (actorPos.y - p3Pos.y) * (actorPos.y - p3Pos.y)
		       + (actorPos.z - p3Pos.z) * (actorPos.z - p3Pos.z);
		p4dist = (actorPos.x - p4Pos.x) * (actorPos.x - p4Pos.x) + (actorPos.y - p4Pos.y) * (actorPos.y - p4Pos.y)
		       + (actorPos.z - p4Pos.z) * (actorPos.z - p4Pos.z);

		p1dist = ((1.0f / _sqrtf(p1dist)) * p1dist);
		p2dist = ((1.0f / _sqrtf(p2dist)) * p2dist);
		p3dist = ((1.0f / _sqrtf(p3dist)) * p3dist);
		p4dist = ((1.0f / _sqrtf(p4dist)) * p4dist);

		if (p1dist < p2dist && p1dist < p3dist && p1dist < p4dist && navi1 != 0)
			dist = p1dist;
		if (p2dist < p1dist && p2dist < p3dist && p2dist < p4dist && navi2 != 0)
			dist = p2dist;
		if (p3dist < p1dist && p3dist < p2dist && p3dist < p4dist && navi3 != 0 && Game::gNaviNum > 2)
			dist = p3dist;
		if (p4dist < p1dist && p4dist < p3dist && p4dist < p2dist && navi4 != 0 && Game::gNaviNum > 3)
			dist = p4dist;

		director->onSetMinDistObj(creature);
		// actor = actor[3];
	}
	return dist;
}