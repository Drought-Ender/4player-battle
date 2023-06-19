#include "Splitter.h"
#include "Graphics.h"
#include "Viewport.h"

FourSplitter::FourSplitter(Graphics* gfx) {
    mGraphics = gfx;

    Vector2<u16> screenSize = getScreenSize();

    mRect.p1.x = 0.0f;
    mRect.p1.y = 0.0f;

    mRect.p2.x = screenSize.x;
    mRect.p2.y = screenSize.y;

    gfx->allocateViewports(4);
    Viewport* viewports[4];
    for (int i = 0; i < ARRAY_SIZE(viewports); i++) {
        viewports[i] = new Viewport;
    }

    const Vector2f  cent = (mRect.p1 + mRect.p2) * 0.5f;
    const Vector2f& topL = mRect.p1;
    const Vector2f& botR = mRect.p2;

    Rectf rects[4] = {
        Rectf(topL.x, topL.y, cent.x, cent.y), // top left
        Rectf(cent.x, topL.y, botR.x, cent.y), // top right
        Rectf(topL.x, cent.y, cent.x, botR.y), // bottom left
        Rectf(cent.x, cent.y, botR.x, botR.y), // bottom right
    };

    for (int i = 0; i < ARRAY_SIZE(rects); i++) {
        viewports[i]->setRect(rects[i]);
    }

    for (int i = 0; i < ARRAY_SIZE(rects); i++) {
        gfx->addViewport(viewports[i]);
    }
}

void FourSplitter::split4(f32 scaleX, f32 scaleY) {
    Viewport* viewports[4];
    for (int i = 0; i < ARRAY_SIZE(viewports); i++) {
        viewports[i] = mGraphics->getViewport(i);
    }

    viewports[0]->mViewportScale.p2.x = scaleX / 0.5f;
    viewports[2]->mViewportScale.p2.x = scaleX / 0.5f;
    viewports[1]->mViewportScale.p2.x = (1.0f - scaleX) / 0.5f;
    viewports[3]->mViewportScale.p2.x = (1.0f - scaleX) / 0.5f;

    viewports[0]->mViewportScale.p2.y = scaleY / 0.5f;
    viewports[1]->mViewportScale.p2.y = scaleY / 0.5f;
    viewports[2]->mViewportScale.p2.y = (1.0f - scaleY) / 0.5f;
    viewports[3]->mViewportScale.p2.y = (1.0f - scaleY) / 0.5f;


    f32 viewHeight = viewports[0]->mRect1.p2.y - viewports[0]->mRect1.p1.y;
    f32 viewWidth  = viewports[0]->mRect1.p2.x - viewports[0]->mRect1.p1.x;

    viewports[1]->mViewportScale.p1.x = viewports[0]->mViewportScale.p2.x * viewWidth  - mRect.p2.x * 0.5f;
    viewports[3]->mViewportScale.p1.x = viewports[0]->mViewportScale.p2.x * viewWidth  - mRect.p2.x * 0.5f;

    viewports[2]->mViewportScale.p1.y = viewports[0]->mViewportScale.p2.y * viewHeight - mRect.p2.y * 0.5f;
    viewports[3]->mViewportScale.p1.y = viewports[0]->mViewportScale.p2.y * viewHeight - mRect.p2.y * 0.5f;

    for (int i = 0; i < ARRAY_SIZE(viewports); i++) {
        viewports[i]->refresh();
    }
}

void FourSplitter::split2(f32 scaleX) {
    split4(scaleX, 0.5f);
}