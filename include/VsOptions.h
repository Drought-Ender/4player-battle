#include "FourPlayer.h"
#include "VsSlotCard.h"

struct IMenu;

static const char* cBackgroundName = "/background.bti";

struct VsOptionsMenuMgr {
    VsOptionsMenuMgr();
    void init();
    bool update();
    void draw(Graphics&);
    
    template <typename T>
    void StartMenu();

    Controller* mController;
    IMenu* mActiveMenu;
    J2DPictureEx* mBackground;
};

struct IMenu {
    virtual void init(VsOptionsMenuMgr*) = 0;
    virtual bool update(VsOptionsMenuMgr*) = 0;
    virtual void draw(VsOptionsMenuMgr*, Graphics&) = 0;
    virtual void cleanup() = 0;
};

struct VsCardMenu;

struct CardImage {
    CardImage() {
        mPicture      = nullptr;
        mCardPtr      = nullptr;
        mIsCardActive = true;
    }

    Vector2f mPosition;
    Vector2f mSize;

    void SetCardPtr(Game::VsGame::VsSlotMachineCard* card) {
        mCardPtr = card;
    }
    void loadImage(JKRArchive*);

    void draw(Vector2f& position, Vector2f& size);

    void draw() {
        draw(mPosition, mSize);
    }

    void actionRight(VsCardMenu*);
    void actionLeft(VsCardMenu*);

    Game::VsGame::VsSlotMachineCard* mCardPtr;
    J2DPictureEx* mPicture;

    bool mIsCardActive;

};

struct VsCardMenu : public IMenu
{
    int mCursorAt;
    int mCardCount;
    CardImage* mCards;

    JKRArchive* mCardArchive;

    virtual void init(VsOptionsMenuMgr*);
    virtual bool update(VsOptionsMenuMgr*);
    virtual void draw(VsOptionsMenuMgr*, Graphics&);
    virtual void cleanup();
};


struct VsConfigMenu : public IMenu
{
    VsConfigMenu() {
        mPageNumber = 0;
        mSelectedOption = 0;
        mCursorOptionIndex = 0;
        mTooltipMessage = nullptr;
    }

    virtual void init(VsOptionsMenuMgr*);
    virtual bool update(VsOptionsMenuMgr*);
    virtual void cleanup();
    virtual void draw(VsOptionsMenuMgr*, Graphics&);

    int mPageNumber;
    int mSelectedOption;
    int mCursorOptionIndex;
    const char* mTooltipMessage;
};



