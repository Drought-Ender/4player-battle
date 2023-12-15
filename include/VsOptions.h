#include "FourPlayer.h"
#include "VsSlotCard.h"
#include "PSGame/Rappa.h"

#define MEMORY_SIZE (*(u32*)0x800000f0)

inline bool isMemoryOverrideOn() {
    return MEMORY_SIZE >= 0x2000000;
}

struct IMenu;

static const char* cBackgroundName = "/background.bti";

extern bool sNameOverride[4];

extern f32 gPassiveSpicy;
extern f32 gPassiveBitter;

static const f32 sSprayTimers[] = {
    3.402823466e+38f,
    300.0f, // 5 minutes
    180.0f, // 3 minutes
    60.0f,  // 1 minute
    30.0f,  // 30 seconds
    0.0f    // infinite
};

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

    const static int sMaxNameSize = 20;

    static void initDefaults();

    static void MakeDisplayName(int size, char* name);
    static void PrepareDisplayName(int size, char* name);
    static void CleanDisplayName(int size, char* name);
    static void UpdateImages();

    void makeDisplayName();

    void* loadModel();
    void* loadAST();
    ResTIMG* loadImage();
    
    int mCharaterID;
    char mName[sMaxNameSize];
    char mDispName[sMaxNameSize];
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

    void createPicture();

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

    const static int sRowSize = 12;

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
    int mNameCursors[4];
    int mLoadAt;

    char mPlayerNames[4][CharacterData::sMaxNameSize];
    bool mSelectingCharactor[4];
};

bool isUpper(const char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLower(const char c) {
    return c >= 'a' && c <= 'z';
}

char NextChar(const char c) {

    switch (c) {
    case 'Z': 
        return ' ';
    case 'z':
        return '_';
    case ' ':
        return 'A';
    case '_':
        return 'a';
    }
    return c + 1;
}

char PrevChar(const char c) {
    switch (c)
    {
    case 'A':
        return ' ';
    case 'a':
        return '_';
    case ' ':
        return 'Z';
    case '_':
        return 'z';
    }
    return c - 1;
}

char ToggleUpper(const char c) {
    if (isUpper(c)) {
        return c + 0x20;
    }
    else if (isLower(c)) {
        return c - 0x20;
    }
    else if (c == '_') {
        return ' ';
    }
    else if (c == ' ') {
        return '_';
    }
    return c;
}

