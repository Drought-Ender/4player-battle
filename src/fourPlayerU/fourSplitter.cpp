#include "Graphics.h"
#include "Splitter.h"
#include "System.h"
#include "Viewport.h"

inline Vector2<u16> getScreenSize() {
    return Vector2<u16>(
        System::getRenderModeObj()->fbWidth, 
        System::getRenderModeObj()->efbHeight);
} // doesn't have to be an inline

FourSplitter::FourSplitter(Graphics* gfx) {
    m_graphics = gfx;

    Vector2<u16> screenSize = getScreenSize();

    m_screen.p1.x = 0.0f;
    m_screen.p1.y = 0.0f;

    m_screen.p2.x = screenSize.x;
    m_screen.p2.y = screenSize.y;

    gfx->allocateViewports(4);
    
    Viewport* viewports[4];

    for (int i = 0; i < 4; i++) {
        viewports[i] = new Viewport;
    }

    Vector2f center = Vector2f(m_screen.p2.x / 2, m_screen.p2.y / 2);

    Rectf rects[4] = {
        Rectf(0.0f, 0.0f, center.x, center.y),                      // Top Left
        Rectf(center.x, 0.0f, m_screen.p2.x, center.y),             // Top Right
        Rectf(0.0f, center.y, center.x, m_screen.p2.y),             // Bottom Left
        Rectf(center.x, center.y, m_screen.p2.x, m_screen.p2.y)     // Bottom Right
    };

    for (int i = 0; i < 4; i++) {
        viewports[i]->setRect(rects[i]);
        gfx->addViewport(viewports[i]);
    }

}

void FourSplitter::split4(f32 scaleX, f32 scaleY) {

    Viewport* viewports[4]; 

    for (int i = 0; i < 4; i++) {
        viewports[i] = m_graphics->getViewport(i);
    }

    viewports[0]->m_vpScale.p2.x = scaleX / 0.5f;
    viewports[2]->m_vpScale.p2.x = scaleX / 0.5f;
    viewports[1]->m_vpScale.p2.x = (1 - scaleX) / 0.5f;
    viewports[3]->m_vpScale.p2.x = (1 - scaleX) / 0.5f;

    viewports[0]->m_vpScale.p2.y = scaleY / 0.5f;
    viewports[1]->m_vpScale.p2.y = scaleY / 0.5f;
    viewports[2]->m_vpScale.p2.y = (1 - scaleY) / 0.5f;
    viewports[3]->m_vpScale.p2.y = (1 - scaleY) / 0.5f;

    float rightViewLength = viewports[0]->m_vpRect1.p2.x - viewports[0]->m_vpRect1.p1.x;
    float topViewHeight = viewports[0]->m_vpRect1.p2.y - viewports[0]->m_vpRect1.p1.y;

    float xStart = viewports[0]->m_vpScale.p2.x;
    float yStart = viewports[0]->m_vpScale.p2.y;

    viewports[1]->m_vpScale.p1.x = xStart * rightViewLength - m_screen.p2.x * 0.5f;
    viewports[3]->m_vpScale.p1.x = xStart * rightViewLength - m_screen.p2.x * 0.5f;

    viewports[2]->m_vpScale.p1.y = yStart * topViewHeight - m_screen.p2.y * 0.5f;
    viewports[3]->m_vpScale.p1.y = yStart * topViewHeight - m_screen.p2.y * 0.5f;

    for (int i = 0; i < 4; i++) {
        viewports[i]->refresh();
    }
}