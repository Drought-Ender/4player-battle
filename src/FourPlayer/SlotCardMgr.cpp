#include "VsSlotCard.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Entities/ItemPikihead.h"
#include "Game/NaviState.h"
#include "Game/generalEnemyMgr.h"
#include "Dolphin/rand.h"
#include "VsOptions.h"
#include "DroughtLib.h"
#include "Game/pathfinder.h"
#include "Game/Cave/RandMapMgr.h"
#include "Game/PikiState.h"
#include "PikiAI.h"

namespace Game
{

namespace VsGame
{

VsSlotCardMgr* vsSlotCardMgr;

struct NaviTekiParams
{
    inline NaviTekiParams() {
        mCount = 0;
        mRadius = 0.0f;
        mSpawnHeight = 0.0f;
    }
    
    inline NaviTekiParams(int objCount, f32 spawnRadius, f32 spawnHeight) {
        mCount = objCount;
        mRadius = spawnRadius;
        mSpawnHeight = spawnHeight;
        mDespawnTimer = 0.0f;
    }

    inline NaviTekiParams(int objCount, f32 spawnRadius, f32 spawnHeight, f32 despawnTimerLength) {
        mCount = objCount;
        mRadius = spawnRadius;
        mSpawnHeight = spawnHeight;
        mDespawnTimer = despawnTimerLength;
    }

    int mCount;
    f32 mRadius;
    f32 mSpawnHeight;
    f32 mDespawnTimer;
};

struct NaviFallTekiParams : public NaviTekiParams {
    inline NaviFallTekiParams() : NaviTekiParams() {
        mStartSpawnTimer = 0.0f;
    }

    inline NaviFallTekiParams(int objCount, f32 spawnRadius, f32 spawnHeight)
        : NaviTekiParams(objCount, spawnRadius, spawnHeight)
    {
        mStartSpawnTimer = 0.0f;
    }

    inline NaviFallTekiParams(int objCount, f32 spawnRadius, f32 spawnHeight, f32 despawnTimerLength)
        : NaviTekiParams(objCount, spawnRadius, spawnHeight, despawnTimerLength)
    {
        mStartSpawnTimer = 0.0f;
    }

    inline NaviFallTekiParams(int objCount, f32 spawnRadius, f32 spawnHeight, f32 despawnTimerLength, f32 startSpawnWait)
        : NaviTekiParams(objCount, spawnRadius, spawnHeight, despawnTimerLength)
    {
        mStartSpawnTimer = startSpawnWait;
        mVarience = 0.0f;
    }

    inline NaviFallTekiParams(int objCount, f32 spawnRadius, f32 spawnHeight, f32 despawnTimerLength, f32 startSpawnWait, f32 varience)
        : NaviTekiParams(objCount, spawnRadius, spawnHeight, despawnTimerLength)
    {
        mStartSpawnTimer = startSpawnWait;
        mVarience = varience;
    }

    f32 mStartSpawnTimer;
    f32 mVarience;
};


struct AddPikminCard : public VsSlotMachineCard
{
    AddPikminCard(int pikiCount, const char* texname) : mPikiCount(pikiCount), VsSlotMachineCard(texname)
    {
    }

    virtual void onUseCard(CardMgr* cardMgr, int user) {
        Onyon* onyon = ItemOnyon::mgr->getOnyon(getVsPikiColor(user));
		if (onyon) {
			ItemOnyon::gVsChargeOkay = true;
			for (int i = 0; i < mPikiCount; i++) {
				onyon->vsChargePikmin();
			}
			ItemOnyon::gVsChargeOkay = false;
		}
    }

    virtual int getWeight(CardMgr* cardMgr, int teamID) {
        int pikiCount = GameStat::getMapPikmins(getPikiFromTeamEnum(teamID));

        if (pikiCount < 4) {
            return (pikiCount < 10) ? 200 : 150;
        }
        return VsSlotMachineCard::getWeight(cardMgr, teamID);
    }

    virtual const char* getDescription() {
        return "Grows Pikmin";
    }
    
    const int mPikiCount;
};

struct FlowerCard : public VsSlotMachineCard
{
    FlowerCard() : mFlowerSprouts(false), VsSlotMachineCard("all_flower.bti") {}

    bool mFlowerSprouts;

    virtual void onUseCard(CardMgr* cardMgr, int user) {
        Iterator<Piki> IPiki = pikiMgr;
        int pikiColor = getVsPikiColor(user);
        CI_LOOP(IPiki) {
            Piki* piki = *IPiki;
            if (piki->getKind() == pikiColor && piki->isAlive() && piki->getHappa() != Flower) {
                piki->changeHappa(Flower);
                Vector3f vec = piki->_25C;
                efx::TPkGlow2 particle;
                efx::Arg arg = vec;
                particle.create(&arg);
                piki->startSound(PSSE_PK_FLOWER_VOICE, true);
            }
        }
        if (!mFlowerSprouts) return;

        Iterator<ItemPikihead::Item> iPikiHead = ItemPikihead::mgr;
        CI_LOOP(iPikiHead) {
            ItemPikihead::Item* pikiHead = *iPikiHead;
            if (pikiHead->mColor == pikiColor && pikiHead->isAlive() && pikiHead->mHeadType != Flower) {
                pikiHead->mHeadType = Flower;
                Vector3f vec = pikiHead->_1E8;
                efx::TPkGlow2 particle;
                efx::Arg arg = vec;
                particle.create(&arg);
                if (pikiHead->mCurrentState->mId == 2) {
                    ((ItemPikihead::WaitState*)pikiHead->mCurrentState)->_10 = 100.0f;
                }
            }
        }
    }

    bool ToggleSprout() {
        mFlowerSprouts = !mFlowerSprouts;

        if (mFlowerSprouts) {
            updateTexName("all_flower_sprout.bti");
        }
        else {
            updateTexName("all_flower.bti");
        }
        return true;
    }

    virtual bool varibleForward() {
        return ToggleSprout();
    }

    virtual bool varibleBackward() {
        return ToggleSprout();
    }

    virtual const char* getDescription() {
        if (mFlowerSprouts) {
            return "Flowers all your pikmin and sprouts";
        }
        return "Flowers all your pikmin";
    }
};

// sEnemyXLU__Q24Game6VsGame
bool sEnemyXLU = false;

struct XLUCard : public VsSlotMachineCard
{
    XLUCard() : VsSlotMachineCard("pikmin_xlu.bti") {};

    virtual int getWeight(CardMgr* cardMgr, int teamID) {
        int firstPlayer = 0;
        for (int i = 0; i < 4; i++) {
            if (teamID == getVsTeam(i)) {
                firstPlayer = i;
            }
        }
        if (cardMgr->mSection->mGhostIconTimers[firstPlayer] > 5.0f) {
            return 0;
        }
        return VsSlotMachineCard::getWeight(cardMgr, teamID);
    }

    virtual void onUseCard(CardMgr* cardMgr, int user) {
        int vsTeam = getVsTeam(user);
        for (int i = 0; i < 4; i++) {
            Navi* navi = naviMgr->getAt(i);
            if (navi && navi->isAlive() && navi->onVsTeam(vsTeam)) {
                if (cardMgr->mSection->mGhostIconTimers[i] <= 0.0f) {
                    efx::TNaviEffect* naviEffect = navi->mEffectsObj;
                    if (!naviEffect->isFlag(efx::NAVIFX_IsSaved)) {
                        naviEffect->saveFlags();
                    }
                    naviEffect->mLight.forceKill();
                    naviEffect->mLightAct.forceKill();
                    naviEffect->mDamage.forceKill();
                    naviEffect->killHamonA_();
                    naviEffect->killHamonB_();
                    naviEffect->killLight_();
                    naviEffect->killLightAct_();
                    naviEffect->killCursor_();
                    naviEffect->killFueact_();
                }
                cardMgr->mSection->mGhostIconTimers[i] = 60.0f;
            }
        }
    }

    bool ToggleEnemyXLU() {
        sEnemyXLU = !sEnemyXLU;

        if (sEnemyXLU) {
            updateTexName("pikmin_teki_xlu.bti");
        }
        else {
            updateTexName("pikmin_xlu.bti");
        }
        return true;
    }


    virtual const char* getDescription() {
        if (sEnemyXLU) {
            return "Hides your team from enemy and creature view";
        }
        return "Hides your team from enemy view";
    }

    virtual bool varibleForward() {
        return ToggleEnemyXLU();
    }

    virtual bool varibleBackward() {
        return ToggleEnemyXLU();
    }

};

// isInvisible__Q24Game4PikiFv
bool Piki::isInvisible() {
    int firstNaviIndex = -1;
    for (int i = 0; i < 4; i++) {
        if (getVsPikiColor(i) == mPikiKind) {
            firstNaviIndex = i;
            break;
        }
    }
    return (firstNaviIndex != -1 && gameSystem->isVersusMode() && VsGame::sEnemyXLU && GetVsGameSection()->mGhostIconTimers[firstNaviIndex] > 0.0f && !doped());
}

// isInvisible__Q24Game4NaviFv
bool Navi::isInvisible() {
    return (gameSystem->isVersusMode() && VsGame::sEnemyXLU && GetVsGameSection()->mGhostIconTimers[mNaviIndex] > 0.0f);
}

struct DopeCard : public VsSlotMachineCard
{
    DopeCard(u8 dopeType, const char* texName, const char* texname2) : mDopeType(dopeType), mUseDope(false), VsSlotMachineCard(texName)
    {
        mGainDopeTex = texName;
        mUseDopeTex  = texname2;
    }

    const u8 mDopeType;
    const char* mGainDopeTex;
    const char* mUseDopeTex;
    bool mUseDope;

    int getWeight(CardMgr* cardMgr, int teamID) {
        int weight = VsSlotMachineCard::getWeight(cardMgr, teamID);

        int dopeCounts[4];

        for (int i = 0; i < 4; i++) {
            dopeCounts[i] = cardMgr->mSection->getGetDopeCount(i, mDopeType);
        }

        for (int i = 0; i < 4; i++) {
            if (i == teamID) continue;

            if (dopeCounts[teamID] > dopeCounts[i] + 2) {
                weight /= 2;
            }
        }

        return weight;
    }

    void onUseCard(CardMgr* cardMgr, int user) {
        Navi* navi = naviMgr->getAt(user);
		if (navi && navi->isAlive()) {
			if (!mUseDope) {
				navi->incDopeCount(mDopeType);
			}
			else {
                bool prev = NaviDopeArg::wasteable;
                
                NaviDopeArg::wasteable = true;
				NaviDopeArg dopearg (mDopeType);
				gDopeCountArray[getVsTeam(user)][mDopeType]++;
				navi->transit(NSID_Dope, &dopearg);

                NaviDopeArg::wasteable = prev;
			}
		}
    }

    bool ToggleSpray() {
        mUseDope = !mUseDope;

        if (mUseDope) {
            updateTexName(mUseDopeTex);
        }
        else {
            updateTexName(mGainDopeTex);
        }
        return true;
    }

    virtual bool varibleForward() {
        return ToggleSpray();
    }

    virtual bool varibleBackward() {
        return ToggleSpray();
    }

    virtual const char* getDescription() {
        if (!mUseDope) return "Increases your spray count";

        return "Uses a spray at no cost";
    }
};

struct TekiCard : public VsSlotMachineCard {
    EnemyTypeID::EEnemyTypeID mEnemyID;
    int mTekiMgrID;

    TekiCard(EnemyTypeID::EEnemyTypeID enemy, const char* texName) : mEnemyID(enemy), VsSlotMachineCard(texName)
    {
    }

    int checkAllocLeft() {
        // The enemy mgr will allways be allocated, so we don't have to worry about check if it exists
        EnemyMgrBase* ourEnemyMgr = generalEnemyMgr->getEnemyMgr(mEnemyID); 
        return ourEnemyMgr->mObjLimit - ourEnemyMgr->mNumObjects;
    }

    static int allocateTeki(TekiMgr* tekiMgr, EnemyTypeID::EEnemyTypeID EnemyId, int count=2) {
        int id = tekiMgr->getEnemy(EnemyId);
        if (id == -1) {
            tekiMgr->entry(EnemyId, count);
            return tekiMgr->mNodeCount - 1;
        }
        else {
            return id;
        }
    }

    virtual int getWeight(CardMgr* cardMgr, int teamID) {
        if (checkAllocLeft() == 0) {
            return 0;
        }
        return VsSlotMachineCard::getWeight(cardMgr, teamID);
    }

    virtual void allocate(VsGameSection* section) {
        mTekiMgrID = allocateTeki(section->mCardMgr->mTekiMgr, mEnemyID);
    }


    EnemyBase* birth(TekiMgr* tekiMgr, Vector3f& position, bool willDespawn) {
        EnemyBase* enemy = tekiMgr->birth(mTekiMgrID, position, willDespawn);
        if (enemy) enemy->setAnimSpeed(30.0f);
        return enemy;
    }

    EnemyBase* birth(TekiMgr* tekiMgr, Vector3f& position, float timer) {
        EnemyBase* enemy = tekiMgr->birth(mTekiMgrID, position, timer);
        P2ASSERT(enemy);
        if (enemy) enemy->setAnimSpeed(30.0f);
        return enemy;
    }

    EnemyBase* birthFromSky(TekiMgr* tekiMgr, Vector3f& position, float timer) {
        EnemyBase* enemy = tekiMgr->birthFromSky(mTekiMgrID, position, timer);
        if (enemy) enemy->setAnimSpeed(30.0f);
        return enemy;
    }

    
};

struct OnyonTekiCard : public TekiCard
{
    OnyonTekiCard(EnemyTypeID::EEnemyTypeID enemy, const char* texName) : TekiCard(enemy, texName)
    {
    }

    int calcOnyonEnemies(int teamID) {
        int enemies = 0;
        Onyon* userOnyon = ItemOnyon::mgr->getOnyon(getPikiFromTeamEnum(teamID));
        Vector3f onyonPos = userOnyon->getPosition();

        Sys::Sphere onyonSphere (onyonPos, 300.0f);

        CellIteratorArg CellArg = onyonSphere;
        CellIterator iCell (CellArg);

        CI_LOOP(iCell) {
            CellObject* obj = *iCell;
            if (obj->getObjType() == OBJTYPE_Teki) {
                EnemyBase* enemy = static_cast<EnemyBase*>(obj);
                if (EnemyInfoFunc::getEnemyInfo(enemy->getEnemyTypeID(), 0xFFFF)->mBitterDrops == BDT_Strong) {
                    enemies++;
                }
            }
        }

        
        return enemies;
    }

    virtual int getWeight(CardMgr* cardMgr, int teamID) {
        float averageOnionEnemies = 0.0f;
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (i != teamID && ItemOnyon::mgr->getOnyon(getPikiFromTeamEnum(i))) {
                averageOnionEnemies += calcOnyonEnemies(i);
                count++;
            } 
        }

        averageOnionEnemies /= count;

        float enemyMultiplier = (3.2f - averageOnionEnemies) / 3.2f;

        if (enemyMultiplier < 0.0f) enemyMultiplier = 0.0f;
        
        return TekiCard::getWeight(cardMgr, teamID) * enemyMultiplier;
    }

    virtual void onUseCard(CardMgr* cardMgr, int user, int target) {
        Onyon* onyon = ItemOnyon::mgr->getOnyon(getVsPikiColor(target));
        Vector3f onyonPos;
        if (onyon) do {
            onyonPos = onyon->getPosition();
            
            float faceDir = onyon->getFaceDir();
            
            float radius = randFloat() * 150.0f + 50.0f;
            float angle  = randFloat() * TAU;
            float height = 0.0f;
        
            Vector3f spawnOffset = Vector3f(
                radius * pikmin2_sinf(angle), 
                height, 
                radius * pikmin2_cosf(angle)
            );

            onyonPos += spawnOffset;
        } while (!DroughtLib::hasValidFloor(onyonPos));
        
        birth(cardMgr->mTekiMgr, onyonPos, true);
    }

    virtual const char* getDescription() {
        return "Spawns an enemy at your target's onion";
    }

    virtual TargetSpecifier useTarget() { return TEAM; }
};

struct NaviTekiCard : public TekiCard
{
    NaviTekiParams mParms;
    NaviTekiCard(EnemyTypeID::EEnemyTypeID id, NaviTekiParams parms, const char* texName) : mParms(parms), TekiCard(id, texName) 
    {
    };

    virtual void onUseCard(CardMgr* cardMgr, int user, int target) {
        Navi* navi = naviMgr->getAt(target);
        for (int i = 0; i < mParms.mCount; i++) {
            Vector3f spawnNaviPos;
            if (navi) {
                spawnNaviPos = navi->getPosition();
                
                float faceDir = navi->getFaceDir();
                float radius = randFloat() * mParms.mRadius;
                
                float angle  = randFloat() * TAU;
                float height = mParms.mSpawnHeight;
                
            
                Vector3f spawnOffset = Vector3f(
                    radius * pikmin2_sinf(angle), 
                    height, 
                    radius * pikmin2_cosf(angle)
                );

                spawnNaviPos += spawnOffset;

                birth(cardMgr->mTekiMgr, spawnNaviPos, mParms.mDespawnTimer);
            }   
        }
    }

    virtual void allocate(VsGameSection* section) {
        mTekiMgrID = allocateTeki(section->mCardMgr->mTekiMgr, mEnemyID, mParms.mCount * 2);
    }

    virtual const char* getDescription() {
        return "Spawns an enemy on your target";
    }

    virtual TargetSpecifier useTarget() { return PLAYER; }

};

struct TankOnyonTeki : public OnyonTekiCard
{
    EnemyTypeID::EEnemyTypeID mWTankTeki;
    EnemyTypeID::EEnemyTypeID mGTankTeki;
    EnemyTypeID::EEnemyTypeID mMTankTeki;
    
    int mWTankId;
    int mGTankId;
    int mMTankId;
    
    TankOnyonTeki(EnemyTypeID::EEnemyTypeID tekiA, EnemyTypeID::EEnemyTypeID tekiB, EnemyTypeID::EEnemyTypeID tekiC, EnemyTypeID::EEnemyTypeID tekiD, const char* texName) 
        : OnyonTekiCard(tekiA, texName) {
        mWTankTeki = tekiB;
        mGTankTeki = tekiC;
        mMTankTeki = tekiD;
    };

    virtual void allocate(VsGameSection* section) {
        TekiMgr* tekiMgr = section->mCardMgr->mTekiMgr;
        mTekiMgrID = allocateTeki(tekiMgr, mEnemyID);
        mWTankId   = allocateTeki(tekiMgr, mWTankTeki);
        if (isMemoryOverrideOn()) {
            mGTankId   = allocateTeki(tekiMgr, mGTankTeki);
            mMTankId   = allocateTeki(tekiMgr, mMTankTeki);
        }
        else {
            mGTankId = -1;
            mMTankId = -1;
        }
    }

    virtual void onUseCard(CardMgr* cardMgr, int user, int target) {
        
        int FTankId = mTekiMgrID;

        int tekiMgrIds[4] = { FTankId, mWTankId, mGTankId, mMTankId };

        mTekiMgrID = tekiMgrIds[getVsTeam(user)];

        OnyonTekiCard::onUseCard(cardMgr, user, target);

        mTekiMgrID = FTankId;
    }

    virtual const char* getDescription() {
        return "Spawns your enemy at your target's base";
    }

};
    
struct BedamaCard : public VsSlotMachineCard
{

    BedamaCard(const char* texName, const char* texName2) : mTexName(texName), mBuryTexname(texName2), VsSlotMachineCard(texName) {

    };

    const char* mTexName;
    const char* mBuryTexname;

    bool mBuryBedama;

    f32 mUseEffectiveness[4];

    void updateUseEffectiveness(CardMgr* cardMgr, int teamID) {
        float redBlueScoreCount = cardMgr->mSection->mRedBlueScore[teamID];

        f32 ourYellowScoreCount = cardMgr->mSection->mYellowScore[teamID] * getAliveTeamCount();

        f32 enemyYellowScoreCount = 0.0f;

        for (int i = 0; i < 4; i++) {
            if (i != teamID && isTeamAlive(i)) {
                enemyYellowScoreCount += cardMgr->mSection->mYellowScore[i];
            }
        }

        float resetBedamaProb = 0.0f;
        
        if (redBlueScoreCount < 0.2f) {
            
        }
        else if (redBlueScoreCount < 0.4f) {
            resetBedamaProb = 0.2f;
        }
        else if (redBlueScoreCount < 0.7f) {
            resetBedamaProb = 0.5f;
        }
        else {
            resetBedamaProb = 0.8f;
        }

        if (ourYellowScoreCount - enemyYellowScoreCount >= 0.4f) {
            resetBedamaProb *= 0.7f;
        }

        mUseEffectiveness[teamID] += resetBedamaProb / 3.0f;
    }

    virtual void allocate(VsGameSection* section) {
        for (int i = 0; i < 4; i++) {
            mUseEffectiveness[i] = 0.0f;
        }
    }
    

    void onUseCard(CardMgr* cardMgr, int user) {
        updateUseEffectiveness(cardMgr, getVsTeam(user));
        if (mBuryBedama) {
            
            BuryBedama(cardMgr, user);
            return;
        }
        int color = getVsPikiColor(user);
        int teamID = getVsTeam(user);
        Onyon* onyon = ItemOnyon::mgr->getOnyon(color);
        Pellet* bedama = cardMgr->mSection->mMarbleRedBlue[teamID];

        if (bedama && bedama->isAlive()) {
            Vector3f pos = onyon->getFlagSetPos();
            PelletReturnArg arg (pos);
            { // needed for stickers to call dtor
				Stickers stickers            = bedama;
				Iterator<Creature> ICreature = &stickers;
				CI_LOOP(ICreature) { (*ICreature)->endStick(); }
			}

            bedama->mPelletSM->transit(bedama, PELSTATE_Return, &arg);
        }
    }

    void BuryBedama(CardMgr* cardMgr, int user) {
        int color = getVsPikiColor(user);
        int teamID = getVsTeam(user);
        Pellet* bedama = cardMgr->mSection->mMarbleRedBlue[teamID];
        if (bedama && bedama->isAlive()) {
            BounceBuryStateArg arg;
            Stickers stickers = bedama;
            arg.mHeldPikis = &stickers;
            bedama->mPelletSM->transit(bedama, PELSTATE_BounceBury, &arg);
        }
    }

    bool ToggleBedama() {
        mBuryBedama = !mBuryBedama;

        if (mBuryBedama) {
            updateTexName(mBuryTexname);
        }
        else {
            updateTexName(mTexName);
        }
        return true;
    }

    virtual bool varibleForward() {
        return ToggleBedama();
    }

    virtual bool varibleBackward() {
        return ToggleBedama();
    }


    int getBedamaWeight(CardMgr* cardMgr, int teamID, int total, int baseWeight) {

        Pellet* marble = cardMgr->mSection->mMarbleRedBlue[teamID];
        if (marble->mPelletState->mId == PELSTATE_BounceBury || marble->mPelletState->mId == PELSTATE_Return) {
            return 0; // If its already recovering, don't even
        }

        float redBlueScoreCount = cardMgr->mSection->mRedBlueScore[teamID];

        f32 ourYellowScoreCount = cardMgr->mSection->mYellowScore[teamID] * getAliveTeamCount();

        f32 enemyYellowScoreCount = 0.0f;

        for (int i = 0; i < 4; i++) {
            if (i != teamID && isTeamAlive(i)) {
                enemyYellowScoreCount += cardMgr->mSection->mYellowScore[i];
            }
        }

        float resetBedamaProb = 0.0f;
        
        if (redBlueScoreCount < 0.2f) {
            
        }
        else if (redBlueScoreCount < 0.4f) {
            resetBedamaProb = 0.2f;
        }
        else if (redBlueScoreCount < 0.7f) {
            resetBedamaProb = 0.5f;
        }
        else {
            resetBedamaProb = 0.8f;
        }

        if (ourYellowScoreCount - enemyYellowScoreCount >= 0.4f) {
            resetBedamaProb *= 0.7f;
        }

        f32 overuseFactor = mUseEffectiveness[teamID];
        if (overuseFactor > 0.4f) {
            overuseFactor = 0.4f;
        }

        resetBedamaProb -= overuseFactor;

        if (resetBedamaProb > 0.0f) {
            return total * resetBedamaProb;
        }

        if (mBuryBedama) {
            if (marble->isBuried()) {
                return 15;
            }
            else {
                return 60;
            }
        }

        return 30;
    }

    virtual const char* getDescription() {
        if (!mBuryBedama) return "Returns your marble";

        return "Buries your marble";
    }
};

struct HazardBarrierCard : public VsSlotMachineCard
{
    HazardBarrierCard(const char* texName) : VsSlotMachineCard(texName) {
    };

    void onUseCard(CardMgr* cardMgr, int user) {
        HazardBarrier* card = new HazardBarrier(getVsTeam(user), naviMgr->getAt(user)->getPosition());
        vsSlotCardMgr->mActionMgr.add(card);
    }

    virtual const char* getDescription() {
        return "Creates a barrier of your color for a short time";
    }
};

struct PluckAllCard : public VsSlotMachineCard
{
    PluckAllCard(const char* texName) : VsSlotMachineCard(texName) {};

    virtual void onUseCard(CardMgr* cardMgr, int user) {
        Iterator<ItemPikihead::Item> iPikiHead = ItemPikihead::mgr;
        Navi* navi = naviMgr->getAt(user);
        int pikiColor = getVsPikiColor(user);
        CI_LOOP(iPikiHead) {
            ItemPikihead::Item* pikiHead = *iPikiHead;
            if (pikiHead->mColor == pikiColor && pikiHead->isAlive()) {
                if (!pikiHead->canPullout()) continue;
                PikiMgr::mBirthMode = 1;
                Piki* pluckedPiki = pikiMgr->birth();
                PikiMgr::mBirthMode = 0;
                if (pluckedPiki) {
                    pluckedPiki->init(nullptr);
                    pluckedPiki->changeShape(pikiHead->mColor);
                    pluckedPiki->changeHappa(pikiHead->mHeadType);
                    pluckedPiki->setPosition(pikiHead->mPosition, false);
                    pluckedPiki->mFsm->transit(pluckedPiki, PIKISTATE_AutoNuki, nullptr);
                    pikiHead->kill(nullptr);
                    pikiHead->setAlive(false);
                }

            }
        }
    }

    virtual int getWeight(CardMgr* cardMgr, int teamID) {
        int ourPikiHead = 0;
        int theirPikiHead = 0;
        Iterator<ItemPikihead::Item> iPikihead = ItemPikihead::mgr;
        CI_LOOP(iPikihead) {
            ItemPikihead::Item* pikiHead = *iPikihead;
            if (pikiHead->mColor == getPikiFromTeamEnum(teamID)) {
                ourPikiHead++;
            }
            else if (isTeamAlive(pikiHead->mColor)) {
                theirPikiHead++;
            }
        }
        int bonus = ourPikiHead - theirPikiHead;
        return (50 * getAliveTeamCount()) + bonus;
    }

    virtual const char* getDescription() {
        return "Plucks all of your buried pikmin";
    }
};



struct WarpHomeCard : public VsSlotMachineCard
{
    WarpHomeCard(const char* texname) : VsSlotMachineCard(texname) {}

    static void WarpAll(int user, Vector3f& place) {
        Navi* victim = naviMgr->getAt(user);
        victim->mPosition3 = place;

        Iterator<Piki> iPiki = pikiMgr;

        CI_LOOP(iPiki) {
            Piki* piki = *iPiki;
            if (piki->isAlive() && piki->mNavi == victim && piki->mBrain->mActionId == PikiAI::ACT_Formation) {
                piki->setPosition(place, false);
                piki->mNavi = nullptr;
                InteractFue fue (victim, true, true);
                piki->stimulate(fue);
            }
        }
    }

    virtual void onUseCard(CardMgr* cardMgr, int user) {
        Vector3f onyonPos = ItemOnyon::mgr->getOnyon(getVsPikiColor(user))->getSuckPos();
        WarpAll(user, onyonPos);
    }

    virtual const char* getDescription() {
        return "Teleports you and your squad back to your base";
    }
};

struct NaviAwaitFallSkyCard : public NaviTekiCard
{
    f32 mWaitTimer;
    f32 mVarience;
    
    NaviAwaitFallSkyCard(EnemyTypeID::EEnemyTypeID id, NaviFallTekiParams parms, const char* texName) : NaviTekiCard(id, parms, texName)
    {
        mWaitTimer = parms.mStartSpawnTimer;
        mVarience  = parms.mVarience;
    }

    virtual void onUseCard(CardMgr* cardMgr, int user, int target) {
        
        Navi* navi = naviMgr->getAt(target);
        for (int i = 0; i < mParms.mCount; i++) {
            Vector3f spawnNaviPos;
            if (navi) {
                spawnNaviPos = navi->getPosition();
                
                float faceDir = navi->getFaceDir();
                float radius = randFloat() * mParms.mRadius;
                
                float angle  = randFloat() * TAU;                
            
                Vector3f spawnOffset = Vector3f(
                    radius * pikmin2_sinf(angle), 
                    0.0f, 
                    radius * pikmin2_cosf(angle)
                );

                spawnNaviPos += spawnOffset;
                if (mWaitTimer == 0.0f) {
                    EnemyBase* enemy = birth(cardMgr->mTekiMgr, spawnNaviPos, mParms.mDespawnTimer);
                }
                else {
                    f32 wait = mWaitTimer + randFloat() * mVarience;
                    WaitEnemySpawn* card = new WaitEnemySpawn(spawnNaviPos, mTekiMgrID, mWaitTimer, mParms.mDespawnTimer);
                    vsSlotCardMgr->mActionMgr.add(card);
                }
            }
        }
    }

    virtual const char* getDescription() {
        return "Spawns an enemy on your target from the sky";
    }
};


VsSlotMachineCard** VsSlotCardMgr::sAllCards = nullptr;
int VsSlotCardMgr::sTotalCardCount = 0;
bool* VsSlotCardMgr::sUsingCards;

void VsSlotCardMgr::initAllCards() {
    VsSlotCardMgr::sTotalCardCount = CARD_ID_COUNT;

    VsSlotCardMgr::sAllCards = new VsSlotMachineCard*[VsSlotCardMgr::sTotalCardCount];

    VsSlotCardMgr::sUsingCards = new bool[VsSlotCardMgr::sTotalCardCount];

    for (int i = 0; i < 12; i++) {
        VsSlotCardMgr::sUsingCards[i] = true;
    }
    for (int i = 12; i < VsSlotCardMgr::sTotalCardCount; i++) {
        VsSlotCardMgr::sUsingCards[i] = false;
    }

    sAllCards[PIKMIN_5] = new AddPikminCard(5, "pikmin_5.bti");
    sAllCards[PIKMIN_10] = new AddPikminCard(10, "pikmin_10.bti");
    sAllCards[ALL_FLOWER] = new FlowerCard;
    sAllCards[PIKMIN_XLU] = new XLUCard;
    sAllCards[DOPE_BLACK] = new DopeCard(SPRAY_TYPE_BITTER, "dope_black.bti", "use_bitter.bti");
    sAllCards[DOPE_RED] = new DopeCard(SPRAY_TYPE_SPICY, "dope_red.bti", "use_spicy.bti");
    sAllCards[RESET_BEDAMA] = new BedamaCard("reset_bedama.bti", "bedama_fall.bti");
    sAllCards[TEKI_HANACHIRASHI] = new OnyonTekiCard(EnemyTypeID::EnemyID_Hanachirashi, "teki_hanachirashi.bti");
    sAllCards[TEKI_SARAI] = new OnyonTekiCard(EnemyTypeID::EnemyID_Sarai, "teki_sarai.bti");
    sAllCards[TEKI_ROCK] = new NaviTekiCard(EnemyTypeID::EnemyID_Rock, NaviTekiParams(8, 90.0f, 0.0f), "teki_rock.bti");
    sAllCards[TEKI_BOMBOTAKRA] = new NaviTekiCard(EnemyTypeID::EnemyID_BombOtakara, NaviTekiParams(1, 0.0f, 1.0f), "teki_bombotakara.bti");
    sAllCards[TEKI_TANK] = new TankOnyonTeki(
        EnemyTypeID::EnemyID_Tank,
        EnemyTypeID::EnemyID_Wtank,
        EnemyTypeID::EnemyID_Gtank,
        EnemyTypeID::EnemyID_Mtank,
        "teki_tank.bti"
    );
    sAllCards[TEKI_DEMON] = new OnyonTekiCard(EnemyTypeID::EnemyID_Demon, "teki_demon.bti");
    sAllCards[TEKI_FUEFUKI] = new OnyonTekiCard(EnemyTypeID::EnemyID_Fuefuki, "teki_fuefuki.bti");
    sAllCards[TEKI_JELLYFLOAT] = new OnyonTekiCard(EnemyTypeID::EnemyID_Kurage, "teki_kurage.bti");
    sAllCards[TEKI_FKABUTO] = new NaviTekiCard(EnemyTypeID::EnemyID_Fkabuto, NaviTekiParams(1, 0.0f, 0.0f, 10.0f), "teki_kabuto.bti");
    sAllCards[ALL_PLUCK] = new PluckAllCard("fue_pullout.bti");
    sAllCards[PATH_BLOCK] = new HazardBarrierCard("fire_water.bti");
    sAllCards[WARP_HOME] = new WarpHomeCard("warp_home.bti");
    sAllCards[TEKI_KUMA] = new NaviAwaitFallSkyCard(EnemyTypeID::EnemyID_KumaChappy, NaviFallTekiParams(1, 0.0f, 0.0f, 20.0f, 3.0f), "teki_kuma.bti");
    sAllCards[BOMB_STORM] = new NaviAwaitFallSkyCard(EnemyTypeID::EnemyID_Bomb, NaviFallTekiParams(8, 90.0f, 0.0f, 30.0f, 1.0f, 1.0f), "bombs.bti");
    sAllCards[TEKI_OTAKARA] = new TankOnyonTeki(
        EnemyTypeID::EnemyID_FireOtakara,
        EnemyTypeID::EnemyID_WaterOtakara,
        EnemyTypeID::EnemyID_GasOtakara,
        EnemyTypeID::EnemyID_SporeOtakara,
        "teki_otakara.bti"
    );
    sAllCards[TEKI_MITES] = new NaviTekiCard(EnemyTypeID::EnemyID_TamagoMushi, NaviTekiParams(1, 0.0f, 0.0f), "teki_fuefuki.bti");
}

VsSlotCardMgr::VsSlotCardMgr() {
    mUsingCards = nullptr;
}

void VsSlotCardMgr::generateCards(VsGameSection* section) {

    int cardCount = 0;
    for (int i = 0; i < sTotalCardCount; i++) {
        if (VsSlotCardMgr::sUsingCards[i]) {
            cardCount++;
        }
    }

    CardCount   = cardCount;
    mCardCount  = cardCount;
    
    mUsingCards = new VsSlotMachineCard*[sTotalCardCount];

    int currCard = 0;
    for (int i = 0; i < sTotalCardCount; i++) {
        
        if (VsSlotCardMgr::sUsingCards[i]) {

            mUsingCards[currCard] = sAllCards[i];
            DebugReport("mUsingCards[%i] %p\n", currCard, mUsingCards[currCard]);
            mUsingCards[currCard]->allocate(section);

            currCard++;
        }
    }
}

void VsSlotCardMgr::update() {
    mActionMgr.update();
}

void ActionEntityMgr::update() {
    FOREACH_NODE(ActionEntity, mChild, entity) {
        bool toDel = entity->update();
        if (toDel) {
            ActionEntity* prev = static_cast<ActionEntity*>(entity->mPrev);
            entity->del();
            delete entity;
            entity = prev;
            if (!entity) break;
            
        }
    }
}

void ActionEntityMgr::add(ActionEntity* entity) {
    if (entity) {
        CNode::add(entity);
    }
}


} // namespace VsGame


} // namespace Game
