#include "FourPlayer.h"
#include "VsSlotCard.h"
#include "PSGame/Rappa.h"

#define MEMORY_SIZE (*(u32*)0x800000f0)

inline bool isMemoryOverrideOn() {
    return MEMORY_SIZE >= 0x2000000;
}

namespace Game
{
struct Piki;
struct Pellet;

namespace ItemTreasure
{
struct Item;
} // namespace ItemTreasure


bool canCarryBedama(Piki* piki, Pellet* pellet);
bool canAttackBedamaIdle(Piki* piki, ItemTreasure::Item* treasure);
bool canAttackBedama(Piki* piki, Game::ItemTreasure::Item* treasure);

} // namespace Game


void DrawDebugMemory(Graphics& gfx);

extern bool gWidescreenActive;

struct IMenu;

static const char* cBackgroundName = "/background.bti";

extern bool sNameOverride[4];

extern f32 gPassiveSpicy;
extern f32 gPassiveBitter;
extern f32 gPassiveCherry;

static const f32 sSprayTimers[] = {
    3.402823466e+38f,
    300.0f, // 5 minutes
    180.0f, // 3 minutes
    60.0f,  // 1 minute
    30.0f,  // 30 seconds
    0.0f    // infinite
};

static const f32 sAttackPowers[] = {
    0.25f,
    0.5f,
    1.0f,
    1.5f,
    2.0f,
    3.0f,
    5.0f
};

static const f32 sSpeeds[] = {
    0.25f,
    0.5f,
    1.0f,
    1.5f,
    2.0f,
    3.0f,
    5.0f
};

struct VsOptionsMenuMgr {
    VsOptionsMenuMgr();
    ~VsOptionsMenuMgr();
    void init();
    bool update();
    void draw(Graphics&);

    bool checkToggleTournament();
    
    template <typename T>
    void StartMenu();

    bool mMenuCooldown;
    Controller* mController;
    IMenu* mActiveMenu;
    IMenu* mMenus[4];
    int mMenuIDs[4];
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
    CharacterData() {
        mCharaterID = -1;
        mName[0] = 0;
        mImage = nullptr;
    }

    const static int sMaxNameSize = 20;

    static void initDefaults();

    static void MakeDisplayName(int size, char* name);
    static void PrepareDisplayName(int size, char* name);
    static void CleanDisplayName(int size, char* name);
    static void UpdateImages();

    void makeDisplayName();

    void* loadModel();
    u32 loadRenderFlags();
    void* loadAST();
    ResTIMG* loadImage();
    
    int mCharaterID;
    char mName[sMaxNameSize];
    char mDispName[sMaxNameSize];
    ResTIMG* mImage;

    void read(Stream&);
    void write(Stream&);

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



    static ResTIMG* loadImage(const char*);
    ResTIMG* loadImage();

    void createPicture();

    void draw(Vector2f& position, Vector2f& size);

    void read(Stream&);

    char* getDisplayName();

    void draw() {
        draw(mPosition, mSize);
    }

    static void SetupGX(Graphics&);

    static JUTTexture* sLoadingPicture;

    void delMembers();

    Vector2f mPosition;
    Vector2f mSize;
    int mCharacterID;
    char* mCharacterName;
    JUTTexture* mPicture;
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

    Delegate<CharacterSelect>* mDelegateLoadIcons;
    DvdThreadCommand mDvdThread;

    void dvdload_icons();
};


enum EMainGamemodes {
    MAINGAME_BEDAMA,
    MAINGAME_BINGO
};

struct GamemodeSelect : public IMenu
{
    const static int sMenuID = 3;

    enum EGameModeTypeID {
        GAMEMODE_MAIN
    };

    void load();

    virtual void init(VsOptionsMenuMgr*);
    virtual bool update(VsOptionsMenuMgr*);
    virtual void draw(VsOptionsMenuMgr*, Graphics&);
    virtual void cleanup();

    void loadImage(J2DPictureEx*& source, const char* texname);
    void drawImage(J2DPictureEx*& img, Vector2f& position, Vector2f& size, bool);

    void drawCursor(VsOptionsMenuMgr*, Graphics&);

    int getMaxRow();

    int mCursorRow;
    EGameModeTypeID mCursorCol;

    u8 mActiveMainGamemodeID;
    
    J2DPictureEx* mMainGameImages[2];
};

extern EMainGamemodes gGameModeID;


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

