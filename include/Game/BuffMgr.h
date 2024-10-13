#ifndef _GAME_BUFFMGR_H_
#define _GAME_BUFFMGR_H_

#include "JSystem/JUtility/JUTTexture.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "CNode.h"
#include "Matrixf.h"
#include "BitFlag.h"

struct Graphics;

namespace Game
{

enum GlobalBuffIDs {
    PLUCK_SPEED_UP = 0
};

struct NaviBuffBase : public CNode
{
    virtual JUTTexture* getTexture() = 0;
    virtual void draw(Graphics&);
    virtual const char* getName() = 0;
    virtual void update() { }

    void setupDraw(Graphics& gfx);
    virtual Matrixf setupMtx(u8 vp, Graphics& gfx, u32 slotID);
};

struct NaviBuffContainer : public CNode
{
    void add(NaviBuffBase* obj) { CNode::add(obj); }
    void del(NaviBuffBase* obj) { obj->del(); }
};

struct PluckSpeedBuff : public NaviBuffBase
{
    PluckSpeedBuff(u8 type);

    enum PluckType {
        WEAK,
        MED,
        STRONG
    };

    virtual JUTTexture* getTexture();
    static void load(JKRArchive*);
    virtual const char* getName() { return "PluckSpeedBuff"; }
    virtual void draw(Graphics&);
    virtual void update();
    
    f32 getSpeedBuff();
    
    u8 mType;
    f32 mAnimationTimer;

    static JUTTexture* sTextureOnePointFive;
    static JUTTexture* sTextureTwo;
    static JUTTexture* sTextureThree;
};


struct NaviBuffData
{
    NaviBuffContainer mContainer;
    u8 mViewport;

    void draw(u8 vp, Graphics&);
    void update();
};

struct BuffMgr
{
    NaviBuffData mBuffData[4];

    void draw(Graphics&);

    void addBuff(NaviBuffBase* buff, u8 naviID);

    static void init();

    void update();

    void setInitialBuff();

    void setupResources();
};

extern BuffMgr* naviBuffMgr;


} // namespace Game



#endif