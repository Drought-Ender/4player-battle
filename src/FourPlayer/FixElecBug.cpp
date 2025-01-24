#include "Game/Entities/ElecBug.h"
#include "Game/EnemyIterator.h"
#include "Game/generalEnemyMgr.h"
#include "Dolphin/rand.h"

namespace Game {

// GetOurEnemyMgr__4GameFPQ24Game9EnemyBase
EnemyMgrBase* GetOurEnemyMgr(EnemyBase* enemy) { return generalEnemyMgr->getEnemyMgr(enemy->getEnemyTypeID()); }

} // namespace Game