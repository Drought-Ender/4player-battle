#include "Game/Entities/Item.h"
#include "System.h"
#include "nans.h"
#include "types.h"

namespace Game {

static const int someArray[3] = { 0, 0, 0 };
static const char fileName[]  = "registItem";

template <typename T, typename T2>
inline void GenerateMgr(T2& mgr, char* name)
{
	OSReport("%s loaded\n", __PRETTY_FUNCTION__);
	sys->heapStatusStart(name, nullptr);
	mgr = new T();
	mgr->loadResources();
	itemMgr->addMgr(mgr);
	sys->heapStatusEnd(name);
}

/*
 * --INFO--
 * Address:	801E4B98
 * Size:	000664
 */
void ItemMgr::createManagers(u32 flags)
{
	bool inCave      = (flags >> 1) & 1;
	bool isExitFloor = flags & 1;

	//GenerateMgr<ItemBarrel::Mgr>(ItemBarrel::mgr, "-Barrel-");
	//GenerateMgr<ItemUjamushi::Mgr>(ItemUjamushi::mgr, "-Ujamushi-");

	sys->heapStatusStart("-Weed-", nullptr);

	ItemWeed::mgr = nullptr;
	
	sys->heapStatusEnd("-Weed-");

	GenerateMgr<ItemTreasure::Mgr>(ItemTreasure::mgr, "-Treasure-");

	GenerateMgr<ItemPikihead::Mgr>(ItemPikihead::mgr, "-PikiHead-");
	GenerateMgr<ItemDownFloor::Mgr>(ItemDownFloor::mgr, "-DownFloor-");
	GenerateMgr<ItemBridge::Mgr>(ItemBridge::mgr, "-Bridge-");
	
	
	

	sys->heapStatusStart("-Plant-", nullptr);


	ItemPlant::mgr = nullptr;
	
	sys->heapStatusEnd("-Plant-");

	sys->heapStatusStart("-Rock-", nullptr);

	ItemRock::mgr = nullptr;
	
	sys->heapStatusEnd("-Rock-");

	GenerateMgr<ItemHoney::Mgr>(ItemHoney::mgr, "-Honey-");

	// Had to be custom
	sys->heapStatusStart("-Onyon-", nullptr);
	ItemOnyon::mgr = new ItemOnyon::Mgr;
	itemMgr->addMgr(ItemOnyon::mgr);
	ItemOnyon::mgr->init();
	sys->heapStatusEnd("-Onyon-");

	sys->heapStatusStart("-Hole-", nullptr);

	ItemHole::mgr = nullptr;

	sys->heapStatusEnd("-Hole-");

	sys->heapStatusStart("-Cave-", nullptr);

	ItemCave::mgr = nullptr;
	
	sys->heapStatusEnd("-Cave-");

	sys->heapStatusStart("-BigFountain-", nullptr);

	ItemBigFountain::mgr = nullptr;
	
	sys->heapStatusEnd("-BigFountain-");

	sys->heapStatusStart("-Bridge-", nullptr);

	
	sys->heapStatusEnd("-Bridge-");

	sys->heapStatusStart("-Gate-", nullptr);
	itemGateMgr = new ItemGateMgr();
	itemMgr->addMgr(itemGateMgr);
	sys->heapStatusEnd("-Gate-");

	sys->heapStatusStart("-DengekiGate-", nullptr);
	if (inCave) {
		ItemDengekiGate::mgr = new ItemDengekiGate::Mgr;
		itemMgr->addMgr(ItemDengekiGate::mgr);
	} else {
		ItemDengekiGate::mgr = nullptr;
	}
	sys->heapStatusEnd("-DengekiGate-");

	OSReport("all loaded\n");
}

/*
 * --INFO--
 * Address:	801E51FC
 * Size:	000048
 */
void ItemMgr::clearGlobalPointers()
{
	ItemBarrel::mgr      = nullptr;
	ItemUjamushi::mgr    = nullptr;
	ItemWeed::mgr        = nullptr;
	ItemDownFloor::mgr   = nullptr;
	ItemTreasure::mgr    = nullptr;
	ItemPikihead::mgr    = nullptr;
	ItemPlant::mgr       = nullptr;
	ItemRock::mgr        = nullptr;
	ItemHoney::mgr       = nullptr;
	ItemOnyon::mgr       = nullptr;
	ItemHole::mgr        = nullptr;
	ItemCave::mgr        = nullptr;
	ItemBigFountain::mgr = nullptr;
	ItemBridge::mgr      = nullptr;
	itemGateMgr          = nullptr;
	ItemDengekiGate::mgr = nullptr;
}

/*
 * --INFO--
 * Address:	801E5244
 * Size:	0000E8
 */
void ItemMgr::killAllExceptOnyonMgr()
{
	if (ItemPlant::mgr) {
		ItemPlant::mgr->killAll();
		if (gameSystem) {
			gameSystem->detachObjectMgr(ItemPlant::mgr);
			itemMgr->delNode(ItemPlant::mgr);
		}
		ItemPlant::mgr = nullptr;
	}

	if (ItemRock::mgr) {
		ItemRock::mgr->killAll();
		if (gameSystem) {
			gameSystem->detachObjectMgr(ItemRock::mgr);
			itemMgr->delNode(ItemRock::mgr);
		}
		ItemRock::mgr = nullptr;
	}

	if (ItemHoney::mgr) {
		ItemHoney::mgr->killAll();
		if (gameSystem) {
			gameSystem->detachObjectMgr(ItemHoney::mgr);
			itemMgr->delNode(ItemHoney::mgr);
		}
		ItemHoney::mgr = nullptr;
	}
}

const char* UNUSED_CreatureKillArg = "CreatureKillArg";

} // namespace Game
