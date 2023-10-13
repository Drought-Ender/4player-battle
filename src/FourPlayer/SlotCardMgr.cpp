#include "VsSlotCard.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Entities/ItemPikihead.h"
#include "Game/NaviState.h"
#include "Game/generalEnemyMgr.h"
#include "Dolphin/rand.h"
#include "VsOptions.h"
#include "DroughtLib.h"


namespace Game
{

namespace VsGame
{

VsSlotCardMgr* vsSlotCardMgr;

struct NaviTekiParams
{
    inline NaviTekiParams() {
        count = 0;
        radius = 0.0f;
        spawnHeight = 0.0f;
    }
    
    inline NaviTekiParams(int objCount, f32 spawnRadius, f32 spawnHeight) {
        count = objCount;
        radius = spawnRadius;
        spawnHeight = spawnHeight;
        despawnTimer = 0.0f;
    }

    inline NaviTekiParams(int objCount, f32 spawnRadius, f32 spawnHeight, f32 despawnTimerLength) {
        count = objCount;
        radius = spawnRadius;
        spawnHeight = spawnHeight;
        despawnTimer = despawnTimerLength;
    }

    int count;
    f32 radius;
    f32 spawnHeight;
    f32 despawnTimer;
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
    return (gameSystem->isVersusMode() && VsGame::sEnemyXLU && GetVsGameSection()->mGhostIconTimers[getTeamFromPiki(mPikiKind)] > 0.0f && !doped());
}

// isInvisible__Q24Game4NaviFv
bool Navi::isInvisible() {
    return (gameSystem->isVersusMode() && VsGame::sEnemyXLU && GetVsGameSection()->mGhostIconTimers[getVsTeam()] > 0.0f);
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
        enemy->setAnimSpeed(30.0f);
        return enemy;
    }

    EnemyBase* birth(TekiMgr* tekiMgr, Vector3f& position, float timer) {
        EnemyBase* enemy = tekiMgr->birth(mTekiMgrID, position, timer);
        enemy->setAnimSpeed(30.0f);
        return enemy;
    }

    virtual bool useTarget() { return true; }
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
        return TekiCard::getWeight(cardMgr, teamID) * (float)averageOnionEnemies / 3.5f;
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
};

struct NaviTekiCard : public TekiCard
{
    NaviTekiParams mParms;
    NaviTekiCard(EnemyTypeID::EEnemyTypeID id, NaviTekiParams parms, const char* texName) : mParms(parms), TekiCard(id, texName) 
    {
    };

    virtual void onUseCard(CardMgr* cardMgr, int user, int target) {
        Navi* navi = naviMgr->getAt(target);
        for (int i = 0; i < mParms.count; i++) {
            Vector3f spawnNaviPos;
            if (navi) {
                spawnNaviPos = navi->getPosition();
                
                float faceDir = navi->getFaceDir();
                float radius = randFloat() * mParms.radius;
                
                float angle  = randFloat() * TAU;
                float height = mParms.spawnHeight;
                
            
                Vector3f spawnOffset = Vector3f(
                    radius * pikmin2_sinf(angle), 
                    height, 
                    radius * pikmin2_cosf(angle)
                );

                spawnNaviPos += spawnOffset;

                birth(cardMgr->mTekiMgr, spawnNaviPos, mParms.despawnTimer);
            }   
        }
    }

    virtual void allocate(VsGameSection* section) {
        mTekiMgrID = allocateTeki(section->mCardMgr->mTekiMgr, mEnemyID, mParms.count * 2);
    }

    virtual const char* getDescription() {
        return "Spawns an enemy on your target";
    }

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
        mGTankId   = allocateTeki(tekiMgr, mGTankTeki);
        mMTankId   = allocateTeki(tekiMgr, mMTankTeki);
    }

    virtual void onUseCard(CardMgr* cardMgr, int user, int target) {
        OSReport("TankOnyonTeki::onUseCard(CardMgr* %p, int %i, int %i)\n", cardMgr, user, target);
        
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
    

    void onUseCard(CardMgr* cardMgr, int user) {
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

            updateMarbleEffectiveness(bedama);
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

    float calcMarbleDist(Vector3f& marbleLocation, int user) {


    }

    void updateMarbleEffectiveness(Pellet* bedama) {

    }


    int getBedamaWeight(CardMgr* cardMgr, int teamID, int total, int baseWeight) {
        float redBlueScoreCount = cardMgr->mSection->mRedBlueScore[teamID];

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
        if (resetBedamaProb > 0.0f) {
            return total * resetBedamaProb;
        }
        return 30;
    }

    virtual const char* getDescription() {
        if (!mBuryBedama) return "Returns your marble";

        return "Buries your marble";
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
            OSReport("mUsingCards[%i] %p\n", currCard, mUsingCards[currCard]);
            mUsingCards[currCard]->allocate(section);

            currCard++;
        }
    }
}


} // namespace VsGame


} // namespace Game
