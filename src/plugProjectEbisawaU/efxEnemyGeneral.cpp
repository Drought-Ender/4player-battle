#include "efx/TEnemyPiyo.h"
#include "efx/TEnemyPoison.h"
#include "efx/TSekika.h"
#include "efx/TEnemyDead.h"
#include "efx/TEnemyWalkSmoke.h"
#include "efx/TEnemyDownSmoke.h"
#include "efx/TEnemyDownWat.h"
#include "efx/TEnemyDive.h"
#include "efx/TEnemyBomb.h"
#include "efx/TEnemyApsmoke.h"
#include "efx/TEnemyHamon.h"

namespace efx {

static void _Print(char* format, ...) { OSReport(format, __FILE__); }

/*
 * --INFO--
 * Address:	803C7834
 * Size:	000274
 */
bool TEnemyPiyo::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(17, nameCheck);

	efx::ArgEnemyType* argt = static_cast<efx::ArgEnemyType*>(arg);

	bool docreate;
	f32 scale;
	switch (argt->mTypeID) {
	case SwitchChappy:
		scale = 1.75f;
		break;

	case SwitchKochappy:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		scale = 0.96f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		scale = 1.9f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
		scale = 0.6f;
		break;

	case SwitchTank:
		scale = 0.88f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		scale = 0.93f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		scale = 0.53f;
		break;

	case SwitchSarai:
		scale = 0.78f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		scale = 0.75f;
		break;

	case SwitchBug:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Catfish:
		scale = 1.1f;
		break;

	case SwitchGrub:
		scale = 0.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Qurione:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Armor:
		scale = 1.15f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		scale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		scale = 1.25f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		scale = 0.62f;
		break;

	case Game::EnemyTypeID::EnemyID_TamagoMushi:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		scale = 0.75f;
		break;

	case SwitchOtakara:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		scale = 0.77f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
		scale = 0.21f;
		break;

	case Game::EnemyTypeID::EnemyID_Hanachirashi:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_Kurage:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_OniKurage:
		scale = 1.9f;
		break;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		scale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeCrow:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_SnakeWhole:
		scale = 1.25f;
		break;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		scale = 2.15f;
		break;

	case SwitchMiniHoudai:
		scale = 1.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		scale = 1.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Kabuto:
	case Game::EnemyTypeID::EnemyID_Rkabuto:
	case Game::EnemyTypeID::EnemyID_Fkabuto:
		scale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		scale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		scale = 1.55f;
		break;

	case Game::EnemyTypeID::EnemyID_UmiMushi:
		scale = 2.45f;
		break;

	case SwitchBeetle:
		docreate = false;
		return docreate;

	case SwitchInanimate:
	case Game::EnemyTypeID::EnemyID_DangoMushi:
	case SwitchWraith:
		docreate = false;
		return docreate;

	default:
		docreate = false;
		return docreate;
	}

	scale *= argt->mScale;

	if (TSync::create(arg)) {
		docreate = true;
		mEmitter->setScaleOnly(scale);
		f32 offs = (scale - 1.0f) * 0.5f + 1.0f;
		volatile Vector3f vec1, vec2; // dumb way to get the stack in here.
		vec1.x = scale;
		vec1.y = scale;
		vec1.z = scale;
		vec2.x = offs;
		vec2.y = offs;
		vec2.z = offs;
		mEmitter->setGlobalScale(offs);

	} else {
		docreate = false;
	}

	return docreate;
}

/*
 * --INFO--
 * Address:	803C7AA8
 * Size:	0000DC
 */
bool TEnemyPoisonL::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(199, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}

	return docreate;
}

/*
 * --INFO--
 * Address:	803C7B84
 * Size:	0000DC
 */
bool TEnemyPoisonS::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(214, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C7C60
 * Size:	0000DC
 */
bool TSekikaLOff::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(231, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C7D3C
 * Size:	0000DC
 */
bool TSekikaLOn::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(246, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C7E18
 * Size:	0000DC
 */
bool TSekikaSOff::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(261, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C7EF4
 * Size:	0000DC
 */
bool TSekikaSOn::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(276, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C7FD0
 * Size:	0000DC
 */
bool TEnemyDead_ArgScale::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(295, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C80AC
 * Size:	00024C
 */
bool TEnemyDead::create(efx::Arg* arg)
{
	bool docreate;
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(312, nameCheck);

	efx::ArgEnemyType* argt = static_cast<efx::ArgEnemyType*>(arg);

	f32 scale;
	switch (argt->mTypeID) {
	case SwitchChappy:
		scale = 1.8f;
		break;

	case SwitchKochappy:
		scale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		scale = 1.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
		scale = 0.8f;
		break;

	case SwitchTank:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		scale = 0.75f;
		break;

	case SwitchSarai:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		scale = 1.35f;
		break;

	case SwitchBug:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_Catfish:
		scale = 1.3f;
		break;

	case SwitchGrub:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Qurione:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Armor:
		scale = 1.45f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		scale = 0.95f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_TamagoMushi:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		scale = 1.0f;
		break;

	case SwitchOtakara:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		scale = 0.85f;
		break;

	case SwitchFlying:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		scale = 0.55f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeCrow:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeWhole:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		scale = 2.0f;
		break;

	case SwitchMiniHoudai:
		scale = 1.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		scale = 1.45f;
		break;

	case SwitchKabuto:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		scale = 1.7f;
		break;

	case Game::EnemyTypeID::EnemyID_UmiMushi:
		docreate = false;
		return docreate;

	case SwitchBeetle:
		scale = 0.94f;
		break;

	case SwitchWraith:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_DangoMushi:
		scale = 2.5f;
		break;

	case SwitchInanimate:
		docreate = false;
		return docreate;

	default:
		docreate = false;
		return docreate;
	}

	scale *= argt->mScale;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C82F8
 * Size:	000318
 */
bool TEnemyWalkSmoke::create(efx::Arg* arg)
{
	int isSmall;
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(491, nameCheck);

	efx::ArgEnemyType* argt = static_cast<efx::ArgEnemyType*>(arg);
	Vector3f pos            = arg->mPosition;

	f32 scale;
	switch (argt->mTypeID) {
	case SwitchChappy:
		scale   = 1.4f;
		isSmall = false;
		break;

	case SwitchKochappy:
		scale   = 1.0f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		scale   = 0.6f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		scale   = 1.4f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
		return false;

	case SwitchTank:
		scale   = 1.0f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		return false;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		return false;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		return false;

	case SwitchSarai:
		return false;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		return false;

	case SwitchBug:
		return false;

	case Game::EnemyTypeID::EnemyID_Catfish:
		return false;

	case SwitchGrub:
		return false;

	case Game::EnemyTypeID::EnemyID_Qurione:
		return false;

	case Game::EnemyTypeID::EnemyID_Armor:
		return false;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		scale   = 1.3f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		scale   = 0.9f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		return false;

	case Game::EnemyTypeID::EnemyID_TamagoMushi:
		return false;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		return false;

	case SwitchOtakara:
		scale   = 1.3f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		scale   = 1.5f;
		isSmall = true;
		break;

	case SwitchFlying:
	case Game::EnemyTypeID::EnemyID_SnakeCrow:
	case Game::EnemyTypeID::EnemyID_SnakeWhole:
	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		return false;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		scale   = 1.25f;
		isSmall = false;
		break;

	case SwitchMiniHoudai:
		scale   = 1.0f;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		scale   = 1.6f;
		isSmall = true;
		break;

	case SwitchKabuto:
		scale   = 1.6f;
		isSmall = true;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		return false;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		scale   = 1.0f;
		isSmall = false;
		break;

	case SwitchBeetle:
	case Game::EnemyTypeID::EnemyID_UmiMushi:
		return false;

	case Game::EnemyTypeID::EnemyID_BlackMan:
		scale   = 1.0;
		isSmall = false;
		break;

	case Game::EnemyTypeID::EnemyID_Tyre:
		return false;

	case Game::EnemyTypeID::EnemyID_DangoMushi:
		scale   = 1.35f;
		isSmall = false;
		break;

	case SwitchInanimate:
		return false;

	default:
		return false;
	}

	scale *= argt->mScale;
	efx::ArgScale args(pos, scale);
	if (isSmall == 0) {
		efx::TEnemyWalkSmokeM effect(PID_EnemyWalkSmokeM);
		return effect.create(&args);
	} else if (isSmall == 1) {
		efx::TEnemyWalkSmokeS effect(PID_EnemyWalkSmokeS);
		return effect.create(&args);
	} else {
		return false;
	}
}

/*
 * --INFO--
 * Address:	803C8610
 * Size:	0000DC
 */
bool TEnemyWalkSmokeM::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(686, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C86EC
 * Size:	000078
 */
bool TEnemyWalkSmokeS::create(efx::Arg* arg)
{
	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);
	f32 scale           = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C8764
 * Size:	000068
 */
bool TEnemyDownSmoke::create(efx::Arg* arg)
{
	bool docreate;
	if (TSimple1::create(arg)) {
		f32 scale = mScale;
		docreate  = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C87CC
 * Size:	00010C
 */
bool TEnemyDownWat::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(734, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple3::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
		mEmitters[1]->setScale(scale);
		mEmitters[2]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C88D8
 * Size:	0000F4
 */
bool TEnemyDive::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(750, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple2::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
		mEmitters[1]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C89CC
 * Size:	0003B8
 */
TEnemyBombScaleTable::TEnemyBombScaleTable(Game::EnemyTypeID::EEnemyTypeID id)
{
	switch (id) {
	case SwitchChappy:
		mType  = 1;
		mScale = 0.92f;
		break;

	case SwitchKochappy:
		mType  = 2;
		mScale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		mType  = 2;
		mScale = 1.65f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		mType  = 1;
		mScale = 0.92f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
		mType  = 2;
		mScale = 1.0f;
		break;

	case SwitchTank:
		mType  = 1;
		mScale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		mType  = 1;
		mScale = 0.7f;
		break;
	case Game::EnemyTypeID::EnemyID_MaroFrog:
		mType  = 1;
		mScale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		mType  = 2;
		mScale = 1.2f;
		break;

	case SwitchSarai:
		mType  = 1;
		mScale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		mType  = 1;
		mScale = 0.8f;
		break;

	case SwitchBug:
		mType  = 1;
		mScale = 0.65f;
		break;

	case Game::EnemyTypeID::EnemyID_Catfish:
		mType  = 1;
		mScale = 0.75f;
		break;

	case SwitchGrub:
		mType  = 2;
		mScale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Qurione:
		mType  = 2;
		mScale = 1.1f;
		break;

	case Game::EnemyTypeID::EnemyID_Egg:
		mType  = 2;
		mScale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Armor:
		mType  = 1;
		mScale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		mType  = 2;
		mScale = 1.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		mType  = 1;
		mScale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		mType  = 0;
		mScale = 0.0f;
		break;

	case Game::EnemyTypeID::EnemyID_TamagoMushi:
		mType  = 2;
		mScale = 1.2f;
		break;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		mType  = 2;
		mScale = 1.5f;
		break;

	case SwitchOtakara:
		mType  = 2;
		mScale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		mType  = 2;
		mScale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
		mType  = 1;
		mScale = 1.2f;
		break;

	case Game::EnemyTypeID::EnemyID_Hanachirashi:
		mType  = 1;
		mScale = 0.72f;
		break;

	case Game::EnemyTypeID::EnemyID_Kurage:
		mType  = 1;
		mScale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_OniKurage:
		mType  = 1;
		mScale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		mType  = 2;
		mScale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeCrow:
	case Game::EnemyTypeID::EnemyID_SnakeWhole:
		mType  = 0;
		mScale = 0.0f;
		break;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		mType  = 1;
		mScale = 1.25f;
		break;

	case SwitchMiniHoudai:
		mType  = 1;
		mScale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		mType  = 1;
		mScale = 0.9f;
		break;

	case SwitchKabuto:
		mType  = 1;
		mScale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		mType  = 2;
		mScale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		mType  = 1;
		mScale = 0.85f;
		break;

	case Game::EnemyTypeID::EnemyID_UmiMushi:
		mType  = 1;
		mScale = 1.2f;
		break;

	case SwitchBeetle:
		mType  = 2;
		mScale = 1.25f;
		break;

	case Game::EnemyTypeID::EnemyID_BlackMan:
		mType  = 1;
		mScale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_Tyre:
		mType  = 0;
		mScale = 0.0f;
		break;

	case Game::EnemyTypeID::EnemyID_DangoMushi:
		mType  = 1;
		mScale = 1.45f;
		break;

	case SwitchHiba:
		mType  = 2;
		mScale = 1.0f;
		break;

	case SwitchPom:
		mType  = 1;
		mScale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Bomb:
		mType  = 1;
		mScale = 0.65f;
		break;

	default:
		mType  = 0;
		mScale = 0.0f;
		break;
	}
}

/*
 * --INFO--
 * Address:	803C8D84
 * Size:	0001EC
 */
bool TEnemyBomb::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(987, nameCheck);

	efx::ArgEnemyType* argt = static_cast<efx::ArgEnemyType*>(arg);

	Vector3f pos = arg->mPosition;
	TEnemyBombScaleTable data(argt->mTypeID);
	f32 scale = argt->mScale * data.mScale;

	efx::ArgScale args(pos, scale);

	if (data.mType == 0) {
		return false;
	} else {
		if (data.mType == 1) {
			efx::TEnemyBombM effect;
			return effect.create(&args);
		} else if (data.mType == 2) {
			efx::TEnemyBombS effect;
			return effect.create(&args);
		} else {
			return false;
		}
	}
}

/*
 * --INFO--
 * Address:	803C8F70
 * Size:	000124
 */
bool TEnemyBombM::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(1012, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple4::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
		mEmitters[1]->setScale(scale);
		mEmitters[2]->setScale(scale);
		mEmitters[3]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C9094
 * Size:	000124
 */
bool TEnemyBombS::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(1029, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple4::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
		mEmitters[1]->setScale(scale);
		mEmitters[2]->setScale(scale);
		mEmitters[3]->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C91B8
 * Size:	0001A4
 */
bool TEnemyApsmoke::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(1047, nameCheck);

	efx::ArgEnemyType* argt = static_cast<efx::ArgEnemyType*>(arg);

	Vector3f pos = arg->mPosition;
	TEnemyBombScaleTable data(argt->mTypeID);
	f32 scale = argt->mScale * data.mScale;

	efx::ArgScale args(pos, scale);

	if (data.mType == 0) {
		return false;
	} else {
		if (data.mType == 1) {
			efx::TEnemyApsmokeM effect;
			return effect.create(&args);
		} else if (data.mType == 2) {
			efx::TEnemyApsmokeS effect;
			return effect.create(&args);
		} else {
			return false;
		}
	}
}

/*
 * --INFO--
 * Address:	803C935C
 * Size:	0000DC
 */
bool TEnemyApsmokeM::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(1072, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}

	return docreate;
}

/*
 * --INFO--
 * Address:	803C9438
 * Size:	0000DC
 */
bool TEnemyApsmokeS::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(1089, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSimple1::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitters[0]->setScale(scale);
	} else {
		docreate = false;
	}

	return docreate;
}

/*
 * --INFO--
 * Address:	803C9514
 * Size:	0000DC
 */
bool TEnemyHamonM::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(1108, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSync::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitter->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C95F0
 * Size:	0000DC
 */
bool TEnemyHamonMInd::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(1122, nameCheck);

	efx::ArgScale* args = static_cast<efx::ArgScale*>(arg);

	f32 scale = args->mScale;
	bool docreate;

	if (TSync::create(arg)) {
		docreate = true;
		volatile Vector3f scaleVec; // dumb.
		scaleVec.x = scale;
		scaleVec.y = scale;
		scaleVec.z = scale;
		mEmitter->setScale(scale);
	} else {
		docreate = false;
	}
	return docreate;
}

/*
 * --INFO--
 * Address:	803C96CC
 * Size:	0002FC
 */
bool TEnemyHamonChasePos::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(1136, nameCheck);

	efx::ArgEnemyType* argt = static_cast<efx::ArgEnemyType*>(arg);

	Vector3f pos = arg->mPosition;

	bool docreate;
	f32 scale;
	switch (argt->mTypeID) {
	case SwitchChappy:
		scale = 1.3f;
		break;

	case SwitchKochappy:
		scale = 0.45f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		scale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
		scale = 0.65f;
		break;

	case SwitchTank:
		scale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		scale = 1.00f;
		break;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		scale = 0.55f;
		break;

	case SwitchSarai:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		scale = 1.4f;
		break;

	case SwitchBug:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_Catfish:
		scale = 1.0f;
		break;

	case SwitchGrub:
		scale = 0.45f;
		break;

	case Game::EnemyTypeID::EnemyID_Qurione:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Armor:
		scale = 1.4f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		scale = 0.8f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		scale = 1.15f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_TamagoMushi:
		scale = 0.6f;
		break;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		scale = 0.9f;
		break;

	case SwitchOtakara:
		scale = 1.1f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
		scale = 2.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Hanachirashi:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Kurage:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_OniKurage:
		scale = 2.0f;
		break;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		scale = 0.9f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeCrow:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_SnakeWhole:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_KingChappy:
		scale = 1.85f;
		break;

	case SwitchMiniHoudai:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_Hana:
		scale = 1.8f;
		break;

	case SwitchKabuto:
		scale = 1.3f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		scale = 1.0f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		scale = 1.35f;
		break;

	case Game::EnemyTypeID::EnemyID_UmiMushi:
		docreate = false;
		return docreate;

	case Game::EnemyTypeID::EnemyID_Kogane:
		scale = 0.75f;
		break;

	case Game::EnemyTypeID::EnemyID_Wealthy:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_Fart:
		scale = 0.7f;
		break;

	case Game::EnemyTypeID::EnemyID_BlackMan:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_Tyre:
		scale = 1.5f;
		break;

	case Game::EnemyTypeID::EnemyID_DangoMushi:
		scale = 2.8f;
		break;

	case SwitchInanimate:
		docreate = false;
		return docreate;

	default:
		docreate = false;
		return docreate;
	}

	scale *= argt->mScale;
	ArgScale arg2(pos, scale);

	if (!mHamonM.create(&arg2)) {
		return false;
	} else if (scale > 0.75 && !mHamonMInd.create(&arg2)) {
		return false;
	} else {
		return true;
	}
}

/*
 * --INFO--
 * Address:	803C99C8
 * Size:	000138
 */
void TEnemyHamon::update(Vector3f& pos)
{
	if (mSeaHeightPtr && mActive) {
		f32 y  = *mSeaHeightPtr - pos.y;
		f32 y2 = mScale * getLimitDepth_();

		if ((0.0f <= y) && y < y2) {
			mPosition = Vector3f(pos.x, *mSeaHeightPtr, pos.z);
			efx::ArgEnemyType arg(Vector3f::zero, mEnemyID, mScale);
			mHamonChasePos.create(&arg);
		} else {
			mHamonChasePos.fade();
		}
	}
}

/*
 * --INFO--
 * Address:	803C9B00
 * Size:	0000A0
 */
bool TEnemyHamon::create(efx::Arg* arg)
{
	bool nameCheck = strcmp("ArgEnemyType", arg->getName()) == 0;
	P2ASSERTLINE(1351, nameCheck);

	efx::ArgEnemyType* argt = static_cast<efx::ArgEnemyType*>(arg);

	mEnemyID = argt->mTypeID;
	mScale   = argt->mScale;
	mActive  = true;
	return true;
}

/*
 * --INFO--
 * Address:	803C9BA0
 * Size:	000140
 */
f32 TEnemyHamon::getLimitDepth_()
{
	f32 depth = 10000.0f;

	switch (mEnemyID) {
	case SwitchChappy:
		depth = 80.0f;
		break;

	case SwitchKochappy:
		depth = 27.0f;
		break;

	case Game::EnemyTypeID::EnemyID_LeafChappy:
		depth = 20.0f;
		break;

	case Game::EnemyTypeID::EnemyID_FireChappy:
		depth = 80.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Baby:
		depth = 20.0f;
		break;

	case SwitchTank:
		depth = 34.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Frog:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_MaroFrog:
		depth = 30.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Tadpole:
		depth = 17.0f;
		break;

	case SwitchSarai:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_BombSarai:
		depth = 110.0f;
		break;

	case SwitchBug:
		depth = 27.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Catfish:
		depth = 30.0f;
		break;

	case SwitchGrub:
		depth = 12.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Egg:
		depth = 26.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Armor:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_PanModoki:
		depth = 35.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Miulin:
		depth = 60.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Imomushi:
		depth = 15.0f;
		break;

	case Game::EnemyTypeID::EnemyID_TamagoMushi:
		depth = 20.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Jigumo:
		depth = 40.0f;
		break;

	case SwitchOtakara:
		depth = 45.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Fuefuki:
		depth = 40.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Mar:
		depth = 80.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Hanachirashi:
		depth = 50.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Kurage:
		depth = 60.0f;
		break;

	case Game::EnemyTypeID::EnemyID_OniKurage:
		depth = 100.0f;
		break;

	case Game::EnemyTypeID::EnemyID_ShijimiChou:
		depth = 20.0f;
		break;

	case SwitchKabuto:
		depth = 55.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Sokkuri:
		depth = 12.0f;
		break;

	case Game::EnemyTypeID::EnemyID_OoPanModoki:
		depth = 80.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Kogane:
		depth = 20.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Wealthy:
		depth = 15.0f;
		break;

	case Game::EnemyTypeID::EnemyID_Fart:
		depth = 15.0f;
		break;

	case SwitchPom:
	case Game::EnemyTypeID::EnemyID_Qurione:
	case Game::EnemyTypeID::EnemyID_SnakeCrow:
	case Game::EnemyTypeID::EnemyID_SnakeWhole:
	case Game::EnemyTypeID::EnemyID_KingChappy:
	case SwitchMiniHoudai:
	case Game::EnemyTypeID::EnemyID_Hana:
	case Game::EnemyTypeID::EnemyID_UmiMushi:
	case SwitchWraith:
	case Game::EnemyTypeID::EnemyID_DangoMushi:
		break;
	}

	return depth;
}

} // namespace efx
