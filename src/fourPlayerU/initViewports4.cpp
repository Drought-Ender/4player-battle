#include "Game/BaseGameSection.h"
#include "Splitter.h"


namespace Game {
    void BaseGameSection::initViewports4(Graphics& gfx) {
        m_splitter = new FourSplitter(&gfx);
        setSplitter(false);
        for (int i = 0; i < 4; i++) {
            
        }

    }
}