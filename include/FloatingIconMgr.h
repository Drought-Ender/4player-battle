#ifndef _FLOATINGICONMGR_H_
#define _FLOATINGICONMGR_H_

#include "CNode.h"
#include "Vector3.h"
#include "Matrixf.h"

struct ResTIMG;
struct JUTTexture;
struct Graphics;

namespace Game
{

struct FloatingIconMgr;

struct FloatingIcon : public CNode
{
    FloatingIcon(ResTIMG*, Vector3f*);
    FloatingIcon(JUTTexture*, Vector3f*);

    ~FloatingIcon();

    void draw(Graphics&);

    bool mTextureOwner;
    JUTTexture* mImg;
    Vector3f* mPosition;

    static FloatingIconMgr* mgr;

    private:
    void setupViewMtx(Graphics&);
};

struct FloatingIconMgr : public CNode
{
    
    void draw(Graphics&);

    static void add(FloatingIcon*);
    static void del(FloatingIcon*);

    Matrixf mViewMatrix;

    static void create();
    static void destroy();

    private:
    void setupViewMtx(Graphics&);
};

} // namespace Game

#endif