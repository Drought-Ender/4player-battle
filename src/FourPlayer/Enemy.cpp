#include "Dolphin/rand.h"
#include "Game/generalEnemyMgr.h"
#include "Game/Entities/Armor.h"
#include "Game/Entities/Baby.h"
#include "Game/Entities/BigFoot.h"
#include "Game/Entities/BigTreasure.h"
#include "Game/Entities/BlackMan.h"
#include "Game/Entities/BlueChappy.h"
#include "Game/Entities/BlueKochappy.h"
#include "Game/Entities/Bomb.h"
#include "Game/Entities/BombOtakara.h"
#include "Game/Entities/BombSarai.h"
#include "Game/Entities/Catfish.h"
#include "Game/Entities/Chappy.h"
#include "Game/Entities/Damagumo.h"
#include "Game/Entities/DangoMushi.h"
#include "Game/Entities/Demon.h"
#include "Game/Entities/Egg.h"
#include "Game/Entities/ElecBug.h"
#include "Game/Entities/ElecHiba.h"
#include "Game/Entities/ElecOtakara.h"
#include "Game/Entities/Fart.h"
#include "Game/Entities/FireChappy.h"
#include "Game/Entities/FireOtakara.h"
#include "Game/Entities/WaterOtakara.h"
#include "Game/Entities/Frog.h"
#include "Game/Entities/Fuefuki.h"
#include "Game/Entities/GasHiba.h"
#include "Game/Entities/GasOtakara.h"
#include "Game/Entities/Hana.h"
#include "Game/Entities/Hanachirashi.h"
#include "Game/Entities/Hiba.h"
#include "Game/Entities/Houdai.h"
#include "Game/Entities/Imomushi.h"
#include "Game/Entities/Jigumo.h"
#include "Game/Entities/Kabuto.h"
#include "Game/Entities/KingChappy.h"
#include "Game/Entities/Kochappy.h"
#include "Game/Entities/Koganemushi.h"
#include "Game/Entities/KumaKochappy.h"
#include "Game/Entities/Kurage.h"
#include "Game/Entities/LeafChappy.h"
#include "Game/Entities/Mar.h"
#include "Game/Entities/MaroFrog.h"
#include "Game/Entities/MiniHoudai.h"
#include "Game/Entities/Miulin.h"
#include "Game/Entities/Nest.h"
#include "Game/Entities/OniKurage.h"
#include "Game/Entities/OoPanModoki.h"
#include "Game/Entities/PanModoki.h"
#include "Game/Entities/Pelplant.h"
#include "Game/Entities/Pom.h"
#include "Game/Entities/Queen.h"
#include "Game/Entities/Qurione.h"
#include "Game/Entities/Rock.h"
#include "Game/Entities/ShijimiChou.h"
#include "Game/Entities/SnakeCrow.h"
#include "Game/Entities/SnakeWhole.h"
#include "Game/Entities/Sokkuri.h"
#include "Game/Entities/Tadpole.h"
#include "Game/Entities/TamagoMushi.h"
#include "Game/Entities/Tank.h"
#include "Game/Entities/Tobi.h"
#include "Game/Entities/Tyre.h"
#include "Game/Entities/Ujia.h"
#include "Game/Entities/Ujib.h"
#include "Game/Entities/UmiMushi.h"
#include "Game/Entities/WaterOtakara.h"
#include "Game/Entities/Wealthy.h"
#include "Game/Entities/YellowChappy.h"
#include "Game/Entities/YellowKochappy.h"

#include "Game/Entities/Tank.h"
#include "Game/Entities/SporeOtakara.h"
#include "Game/Entities/Hibas.h"
#include "Game/Entities/GreenBomb.h"

#include "Game/plantsMgr.h"
#include "Game/gamePlayData.h"
#include "Game/MapMgr.h"
#include "Game/Interaction.h"
#include "LoadResource.h"

void Game::GeneralEnemyMgr::createEnemyMgr(u8 type, int enemyID, int limit)
{
	// int limit = objLimit;
	EnemyInfoFunc::getEnemyInfo(enemyID, 0xFFFF);
	char* name = getEnemyName(enemyID, 0xFFFF);
	sys->heapStatusStart(name, nullptr);

	EnemyMgrBase* mgr;

	switch (enemyID) {
	case EnemyTypeID::EnemyID_Pelplant:
		mgr = new Pelplant::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Kochappy:
		mgr = new Kochappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_BlueKochappy:
		mgr = new BlueKochappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_YellowKochappy:
		mgr = new YellowKochappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Chappy:
		mgr = new Chappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_BlueChappy:
		mgr = new BlueChappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_YellowChappy:
		mgr = new YellowChappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Pom:
		mgr = new Pom::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Frog:
		mgr = new Frog::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Kogane:
		mgr = new Koganemushi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Wealthy:
		mgr = new Wealthy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Fart:
		mgr = new Fart::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Qurione:
		mgr = new Qurione::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_MaroFrog:
		mgr = new MaroFrog::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Rock:
		mgr = new Rock::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_UjiA:
		mgr = new Ujia::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_UjiB:
		mgr = new Ujib::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Tobi:
		mgr = new Tobi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Armor:
		mgr = new Armor::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Hiba:
		mgr = new Hiba::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_GasHiba:
		mgr = new GasHiba::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_ElecHiba:
		mgr = new ElecHiba::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Sarai:
		mgr = new Sarai::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Tank:
		mgr = new Ftank::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Wtank:
		mgr = new Wtank::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Catfish:
		mgr = new Catfish::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Tadpole:
		mgr = new Tadpole::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_ElecBug:
		mgr = new ElecBug::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Mar:
		mgr = new Mar::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Queen:
		mgr = new Queen::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Baby:
		mgr = new Baby::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Demon:
		mgr = new Demon::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_FireChappy:
		mgr = new FireChappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_SnakeCrow:
		mgr = new SnakeCrow::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_KumaChappy:
		mgr = new KumaChappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Bomb:
		mgr = new Bomb::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Egg:
		mgr = new Egg::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_PanModoki:
		mgr = new PanModoki::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_OoPanModoki:
		mgr = new OoPanModoki::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_PanHouse:
		mgr = new Nest::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Fuefuki:
		mgr = new Fuefuki::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Tanpopo:
		mgr = new Tanpopo::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Clover:
		mgr = new Clover::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_HikariKinoko:
		mgr = new HikariKinoko::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Ooinu_s:
		mgr = new Ooinu_s::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_KareOoinu_s:
		mgr = new KareOoinu_s::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Ooinu_l:
		mgr = new Ooinu_l::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_KareOoinu_l:
		mgr = new KareOoinu_l::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Wakame_s:
		mgr = new Wakame_s::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Wakame_l:
		mgr = new Wakame_l::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Tukushi:
		mgr = new Tukushi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Watage:
		mgr = new Watage::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_DaiodoRed:
		mgr = new DiodeRed::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_DaiodoGreen:
		mgr = new DiodeGreen::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Magaret:
		mgr = new Margaret::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Nekojarashi:
		mgr = new Nekojarashi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Chiyogami:
		mgr = new Chiyogami::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Zenmai:
		mgr = new Zenmai::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_KingChappy:
		mgr = new KingChappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Miulin:
		mgr = new Miulin::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Hanachirashi:
		mgr = new Hanachirashi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Damagumo:
		mgr = new Damagumo::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Kurage:
		mgr = new Kurage::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_BombSarai:
		mgr = new BombSarai::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_FireOtakara:
		mgr = new FireOtakara::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_WaterOtakara:
		mgr = new WaterOtakara::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_GasOtakara:
		mgr = new GasOtakara::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_ElecOtakara:
		mgr = new ElecOtakara::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_BombOtakara:
		mgr = new BombOtakara::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Jigumo:
		mgr = new Jigumo::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Imomushi:
		mgr = new Imomushi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Houdai:
		mgr = new Houdai::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_LeafChappy:
		mgr = new LeafChappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_TamagoMushi:
		if ((gameSystem != nullptr) && (gameSystem->mIsInCave == 0)) {
			limit = 10;
		} else {
			limit = 30;
		}
		mgr = new TamagoMushi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_BigFoot:
		mgr = new BigFoot::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_SnakeWhole:
		mgr = new SnakeWhole::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_UmiMushiBase:
		mgr = new UmiMushi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_OniKurage:
		mgr = new OniKurage::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_BigTreasure:
		mgr = new BigTreasure::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Kabuto:
		mgr = new GreenKabuto::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Rkabuto:
		mgr = new RedKabuto::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Fkabuto:
		mgr = new FixKabuto::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_KumaKochappy:
		mgr = new KumaKochappy::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_ShijimiChou:
		if ((gameSystem != nullptr) && (gameSystem->mIsInCave == 0)) {
			limit = 10;
		} else {
			limit = 25;
		}
		mgr = new ShijimiChou::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_MiniHoudai:
		mgr = new NormMiniHoudai::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_FminiHoudai:
		mgr = new FixMiniHoudai::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Sokkuri:
		mgr = new Sokkuri::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Hana:
		mgr = new Hana::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_BlackMan:
		mgr = new BlackMan::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Tyre:
		mgr = new Tyre::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_DangoMushi:
		mgr = new DangoMushi::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Gtank:
		mgr = new Gtank::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_Mtank:
		mgr = new Mtank::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_SporeOtakara:
		mgr = new SporeOtakara::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_TechnoHoudai:
		mgr = new TechnoHoudai::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_TechnoBug:
		mgr = new TechnoBug::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_WaterHiba:
		mgr = new WaterHiba::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_GasLineHiba:
		mgr = new GasLineHiba::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_SporeHiba:
		mgr = new SporeHiba::Mgr(limit, type);
		break;
	case EnemyTypeID::EnemyID_GreenBomb:
		mgr = new GreenBomb::Mgr(limit, type);
		break;
	default:
		JUT_PANIC("UNKNOWN ENEMY MANAGER %i FOR %s", enemyID, name);
		break;
	}

	mgr->alloc();
	mEnemyMgrNode.add(new EnemyMgrNode(enemyID, name, mgr));
	add(mgr);
	sys->heapStatusEnd(name);
}

JAISound* PSStartEnemyGhostSE(Game::EnemyBase* enemy, float)
{
	JAISound* ghost = enemy->getJAIObject()->startSound(PSSE_EN_ENEMY_GHOST, 0);
	if (ghost) {
		f32 volume = 0.0f;
		f32 pitch  = 0.0f;
		switch (enemy->getEnemyTypeID()) {
		case Game::EnemyTypeID::EnemyID_KingChappy:
			volume = 1.0f;
			pitch  = 0.8f;
			break;
		case Game::EnemyTypeID::EnemyID_FireChappy:
		case Game::EnemyTypeID::EnemyID_OoPanModoki:
			volume = 1.0f;
			pitch  = 0.9f;
			break;
		case SwitchChappy:
			volume = 1.0f;
			pitch  = 1.0f;
			break;
		case Game::EnemyTypeID::EnemyID_MiniHoudai:
			volume = 1.0f;
			pitch  = 1.1f;
			break;
		case Game::EnemyTypeID::EnemyID_SnakeCrow:
		case Game::EnemyTypeID::EnemyID_SnakeWhole:
		case Game::EnemyTypeID::EnemyID_Kabuto:
		case Game::EnemyTypeID::EnemyID_Hana:
			volume = 1.0f;
			pitch  = 1.2f;
			break;
		case Game::EnemyTypeID::EnemyID_Armor:
		case Game::EnemyTypeID::EnemyID_Catfish:
		case Game::EnemyTypeID::EnemyID_Miulin:
		case Game::EnemyTypeID::EnemyID_BombSarai:
			volume = 0.9f;
			pitch  = 1.3f;
			break;
		case Game::EnemyTypeID::EnemyID_Frog:
		case Game::EnemyTypeID::EnemyID_MaroFrog:
		case SwitchTank:
			volume = 0.8f;
			pitch  = 1.4f;
			break;
		case SwitchSarai:
		case SwitchBug:
		case Game::EnemyTypeID::EnemyID_PanModoki:
		case Game::EnemyTypeID::EnemyID_Fuefuki:
		case Game::EnemyTypeID::EnemyID_Jigumo:
		case Game::EnemyTypeID::EnemyID_LeafChappy:
			volume = 0.7f;
			pitch  = 1.5f;
			break;
		case SwitchKochappy:
		case Game::EnemyTypeID::EnemyID_Sokkuri:
			volume = 0.6f;
			pitch  = 1.6f;
			break;
		case Game::EnemyTypeID::EnemyID_Tadpole:
		case Game::EnemyTypeID::EnemyID_Baby:
			volume = 0.6f;
			pitch  = 1.7f;
			break;

		case SwitchGrub:
		case Game::EnemyTypeID::EnemyID_TamagoMushi:
			volume = 0.5f;
			pitch  = 2.0f;
			break;
		case SwitchOtakara:
			volume = 0.6f;
			pitch  = 1.8f;
			break;
		case Game::EnemyTypeID::EnemyID_ShijimiChou:
			volume = 0.4f;
			pitch  = 2.3f;
			break;
		}
		ghost->setVolume(volume, 0, 0);
		ghost->setPitch(pitch, 0, 0);
	}
	return ghost;
}