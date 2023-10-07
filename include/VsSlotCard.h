#ifndef _VSSLOTCARD_H_
#define _VSSLOTCARD_H_

#include "Game/VsGame.h"
#include "Game/Stickers.h"

namespace Game
{
namespace VsGame
{

struct VsSlotEntityArg {
    VsSlotEntityArg(int i) { mUser = i; }
    int mUser;
};

struct VsSlotCardEntity : public TPositionObject, public CNode {

    VsSlotCardEntity() {
        mToDelete = false;
        mPosition = 0.0f;
    }

    Vector3f mPosition;
    bool mToDelete;

    virtual Vector3f getPosition() { return mPosition; }

    void create(VsSlotEntityArg* arg) {
        init(arg); 
    }

    virtual void init(VsSlotEntityArg*) {};
    virtual void exec() {};
    virtual void cleanup() {};
};

struct VsSlotCardEntityMgr : public CNode {
    void exec();
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
    virtual bool useTarget() { return false; }

    void updateTexName(const char* texname) { mTexName = texname; }
    virtual bool varibleForward() { return false; }
    virtual bool varibleBackward() { return false; }

    virtual const char* getDescription() = 0;



    void useCard(CardMgr* cardMgr, int user, int target) {
        onUseCard(cardMgr, user, target);
        onUseCard(cardMgr, user);
    }
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


    int mCardCount;
    
    VsSlotMachineCard** mUsingCards;
};

extern bool sEnemyXLU;


extern VsSlotCardMgr* vsSlotCardMgr;

} // namespace VsGame
} // namespace Game

#endif