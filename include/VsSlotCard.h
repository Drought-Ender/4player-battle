#ifndef _VSSLOTCARD_H_
#define _VSSLOTCARD_H_

#include "Game/VsGame.h"
#include "Game/Stickers.h"
#include "FloatingIconMgr.h"

struct JUTTexture;

namespace efx
{
    struct THdamaSight;
} // namespace efx

namespace Game
{
namespace VsGame
{

enum TargetSpecifier {
    NONE = 0,
    TEAM = 1,
    PLAYER = 2
};

class VsSlotMachineCard
{
    protected:
    VsSlotMachineCard(const char* texName) {
        mTexName = texName;
    }
    
    private:
    const char* mTexName;

    public:
    inline const char* GetTexName() { return mTexName; }
    virtual void allocate(VsGameSection* section) { }
    virtual int getBedamaWeight(CardMgr* cardMgr, int user, int total, int baseWeight) { return baseWeight; }
    virtual int getWeight(CardMgr* cardMgr, int teamID) { return 100; }
    virtual void onUseCard(CardMgr* cardMgr, int user, int target) { }
    virtual void onUseCard(CardMgr* cardMgr, int user) { }
    virtual TargetSpecifier useTarget() { return NONE; }

    void updateTexName(const char* texname) { mTexName = texname; }
    virtual bool varibleForward() { return false; }
    virtual bool varibleBackward() { return false; }
    virtual int getVaribleForwardCount() { return 0; }

    virtual const char* getDescription() = 0;

    void useCard(CardMgr* cardMgr, int user, int target) {
        onUseCard(cardMgr, user);
        onUseCard(cardMgr, user, target);
    }

    protected:
    JUTTexture* GetTextureFromMgr();
};

static bool isPaused();

enum EntityID {
    ENTITY_HAZARD,
    ENTITY_FALL,
    ENTITY_CALLBACKHOLDER
};

struct ActionEntity : public CNode {
    virtual bool update() { };
    virtual EntityID getEntityID() = 0;
};

struct TeamEntity : public ActionEntity {
    TeamEntity(int teamID) : mTeamID(teamID) 
    {
    }

    const int mTeamID;

    int getTeamID() const { return mTeamID; }
};

struct TeamPositionEntity : public TeamEntity, public TPositionObject {
    TeamPositionEntity(int teamID, Vector3f position) : TeamEntity(teamID), mPosition(position)
    {
    }

    Vector3f mPosition;

    virtual Vector3f getPosition() { return mPosition; }
};

struct PositionEntity : public ActionEntity, public TPositionObject
{
    PositionEntity(Vector3f position) : ActionEntity(), mPosition(position)
    {
    }

    Vector3f mPosition;

    virtual Vector3f getPosition() { return mPosition; }
};


struct HazardBarrier : TeamPositionEntity {
    HazardBarrier(int, Vector3f);
    ~HazardBarrier();

    static efx::TBase* MakeEfx(TeamID);
    static f32 GetEfxTimer(TeamID);

    efx::TBase* mEfx;
    f32 mTimer;
    f32 mEfxTimer;

    virtual bool update();
    virtual EntityID getEntityID() { return ENTITY_HAZARD; }
};


struct WaitEnemySpawn : PositionEntity {

    EnemyBase* birthFromSky();

    
    WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime, JUTTexture* tex);
    WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime);
    ~WaitEnemySpawn();

    void init();

    virtual bool update();

    efx::THdamaSight* mEfx;
    f32 mWaitTimer;
    f32 mExistenceTimer;
    int mEntityID;
    FloatingIcon* mIcon;

    virtual EntityID getEntityID() { return ENTITY_FALL; }
};

struct FloatingIconHolderBase : public PositionEntity
{
    FloatingIconHolderBase(Vector3f position, JUTTexture* tex);
    ~FloatingIconHolderBase();

    virtual bool update() = 0;

    FloatingIcon* mIcon;
};

struct CallbackArgs {};

typedef bool (BoolCallback(const Vector3f&, const CallbackArgs*));

struct FloatingIconHolderCallback : public FloatingIconHolderBase
{
    FloatingIconHolderCallback(Vector3f position, JUTTexture* tex, const BoolCallback* callback, const CallbackArgs* args);

    virtual bool update();
    virtual EntityID getEntityID() { return ENTITY_CALLBACKHOLDER; }

    const BoolCallback* mCallback;
    const CallbackArgs* mArgs;
};

struct ActionEntityMgr : public CNode {

    void add(ActionEntity* entity);

    void update();
};

struct VsSlotCardMgr
{
    VsSlotCardMgr();

    
    static int sTotalCardCount;
    static VsSlotMachineCard** sAllCards;
    static bool* sUsingCards;
    static void initAllCards();

    void generateCards(VsGameSection*);

    VsSlotMachineCard* getAt(int i) { return mUsingCards[i]; }
    int getCardCount() { return mCardCount; }

    void update();

    ActionEntityMgr* getActionMgr() { return &mActionMgr; };


    int mCardCount;
    
    VsSlotMachineCard** mUsingCards;

    ActionEntityMgr mActionMgr;
};



extern bool sEnemyXLU;


extern VsSlotCardMgr* vsSlotCardMgr;

} // namespace VsGame
} // namespace Game

#endif