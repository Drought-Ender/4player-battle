#ifndef _FLOATINGICONMGR_H_
#define _FLOATINGICONMGR_H_

#include "CNode.h"
#include "Vector3.h"
#include "Matrixf.h"

struct ResTIMG;
struct JUTTexture;
struct Camera;
struct Graphics;

namespace Game
{

struct FloatingIconMgr;

struct IFloatingIcon {
    virtual void draw(Graphics&) = 0;
    virtual bool satisfy() = 0;
    virtual f32 getSize() = 0;
    virtual Vector3f getPosition() = 0;
    virtual Matrixf setupViewMtx(Graphics&) = 0;
    virtual bool drawOver() = 0;
};

struct FloatingIcon : public CNode, public IFloatingIcon
{
    FloatingIcon(JUTTexture*, const Vector3f*);

    ~FloatingIcon();

    virtual void draw(Graphics&);
    virtual bool satisfy() { return true; };
    virtual f32 getSize();
    virtual Vector3f getPosition();
    virtual bool drawOver() { return false; }

    f32 calcZ(Camera*);

    // img owned by upper class (just like real life)
    JUTTexture* mImg;
    const Vector3f* mPosition;

    static FloatingIconMgr* mgr;

    protected:
    virtual Matrixf setupViewMtx(Graphics&);
};

struct HoveringFloatingIcon : public FloatingIcon
{
    HoveringFloatingIcon(JUTTexture*, const Vector3f*, f32);

    virtual Vector3f getPosition();

    f32 mYOffset;
};

struct OnyonFloatingIcon : public HoveringFloatingIcon
{
    inline OnyonFloatingIcon(JUTTexture* a, Vector3f* b, f32 c) 
    : HoveringFloatingIcon(a, b, c)
    {
    }
    virtual bool satisfy();
    virtual void draw(Graphics&);

    virtual bool drawOver() { return true; }
};



struct FloatingIconMgr : public CNode
{
    
    void draw(Graphics&);

    static void add(FloatingIcon*);
    static void del(FloatingIcon*);

    static bool sDrawOptimize;
    static bool sIsEnabled;

    Matrixf mViewMatrix;

    static void create();
    static void destroy();

    private:
    void setupViewMtx(Graphics&);
};

} // namespace Game

#endif