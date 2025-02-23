#ifndef _GAME_ENTITIES_GREENBOMB_H
#define _GAME_ENTITIES_GREENBOMB_H

#include "Game/Entities/Bomb.h"

namespace Game
{
    
namespace GreenBomb
{

struct Obj : public Bomb::Obj
{
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID()         // _258 (weak)
	{
		return EnemyTypeID::EnemyID_GreenBomb;
	}

	virtual void onInit(CreatureInitArg* settings);
    virtual void bounceCallback(Sys::Triangle* tri);
    virtual void collisionCallback(CollEvent& event);

	bool mIsStuck;
};


struct Mgr : public EnemyMgrBase {
	Mgr(int objLimit, u8 modelType);

	//////////////// VTABLE
	// virtual ~Mgr();                                     // _58 (weak)
	virtual EnemyBase* birth(EnemyBirthArg&);          // _70
	virtual void doAlloc();                            // _A8
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() // _AC (weak)
	{
		return EnemyTypeID::EnemyID_GreenBomb;
	}
	virtual void createObj(int count) // _A0 (weak)
	{
		mObj = new Obj[count];
	}
	virtual EnemyBase* getEnemy(int index) // _A4 (weak)
	{
		return &mObj[index];
	}

	virtual void loadModelData();

	virtual J3DModelData* doLoadBmd(void* filename) // _D4 (weak)
	{
		return J3DModelLoaderDataBase::load(filename, 0x20240030);
	}

	//////////////// VTABLE END

	// _00 		= VTBL
	// _00-_44	= EnemyMgrBase
	Obj* mObj; // _44, array of Objs, probably
};


} // namespace GreenBomb
} // namespace Game

#endif