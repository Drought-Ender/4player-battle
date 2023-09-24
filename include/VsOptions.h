#include "FourPlayer.h"
#include "VsSlotCard.h"
#include "PSGame/Rappa.h"

struct IMenu;

static const char* cBackgroundName = "/background.bti";

struct VsOptionsMenuMgr {
    VsOptionsMenuMgr();
    void init();
    bool update();
    void draw(Graphics&);
    
    template <typename T>
    void StartMenu();

    bool mMenuCooldown;
    Controller* mController;
    IMenu* mActiveMenu;
    IMenu* mMenus[3];
    int mMenuIDs[3];
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

    const static int sMenuID = 1;

    virtual void init(VsOptionsMenuMgr*);
    virtual bool update(VsOptionsMenuMgr*);
    virtual void draw(VsOptionsMenuMgr*, Graphics&);
    virtual void cleanup();

    ~VsCardMenu();
};


struct VsConfigMenu : public IMenu
{
    VsConfigMenu() {
        mPageNumber = 0;
        mSelectedOption = 0;
        mCursorOptionIndex = 0;
        mTooltipMessage = nullptr;
    }

    const static int sMenuID = 0;

    virtual void init(VsOptionsMenuMgr*);
    virtual bool update(VsOptionsMenuMgr*);
    virtual void cleanup();
    virtual void draw(VsOptionsMenuMgr*, Graphics&);

    int mPageNumber;
    int mSelectedOption;
    int mCursorOptionIndex;
    const char* mTooltipMessage;

    ~VsConfigMenu() { }
};

struct CharacterData
{

    static void initDefaults();

    void makeDisplayName();

    void* loadModel();
    void* loadAST();
    ResTIMG* loadImage();
    
    int mCharaterID;
    char mName[64];
    char mDispName[64];
    ResTIMG* mImage;

};


extern CharacterData sCharacters[4];




struct CharacterImage
{
    CharacterImage() {
        mPicture      = nullptr;        
    }

    ~CharacterImage();

    void SetID(int id) {
        mCharacterID = id;
    }


    
    ResTIMG* loadImage();

    void draw(Vector2f& position, Vector2f& size);

    void read(Stream&);

    char* getDisplayName();

    void draw() {
        draw(mPosition, mSize);
    }

    void delMembers();

    Vector2f mPosition;
    Vector2f mSize;
    int mCharacterID;
    char* mCharacterName;
    J2DPictureEx* mPicture;
};


struct CharacterSelect : public IMenu
{
    CharacterSelect() {
        mControllers[0] = nullptr;
        mControllers[1] = nullptr;
        mControllers[2] = nullptr;
        mControllers[3] = nullptr;
    }

    const static int sRowSize = 10;

    const static int sMenuID = 2;

    void load();
    void read(Stream&);

    virtual void init(VsOptionsMenuMgr*);
    virtual bool update(VsOptionsMenuMgr*);
    virtual void draw(VsOptionsMenuMgr*, Graphics&);
    virtual void cleanup();

    ~CharacterSelect();

    int mCharacterCount;
    CharacterImage* mCharacters;
    Controller* mControllers[4];
    int mCursors[4];
};




