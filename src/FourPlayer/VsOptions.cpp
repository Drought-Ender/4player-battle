#include "FourPlayer.h"
#include "Controller.h"
#include "Graphics.h"
#include "JSystem/J2D/J2DPrint.h"
#include "P2JME/P2JME.h"
#include "Game/GameSystem.h"
#include "PSSystem/PSSystemIF.h"
#include "Game/VsGameSection.h"
#include "Game/GameConfig.h"
#include "VsSlotCard.h"
#include "VsOptions.h"
#include "Game/VsGame.h"
#include "LoadResource.h"

VsOptionsMenuMgr* gOptionMenu;

void Option::readOptions() {
    OSReport("Tournament Mode Ptr %p\n", &gTournamentMode);
    if (gTournamentMode) {
        gOptions[MARBLE_BURY].value = ConfigEnums::PLACE_BURY;
        gConfig[MARBLE_BURY] = ConfigEnums::PLACE_BURY;

        gOptions[MARBLE_CARRY].value = ConfigEnums::CARRY_ON;
        gConfig[MARBLE_CARRY] = ConfigEnums::CARRY_ON;

        gOptions[SPICY_TYPE].hide = true;
        gOptions[SPICY_TYPE].value = ConfigEnums::SPICY_NERF;
        gConfig[SPICY_TYPE] = ConfigEnums::SPICY_NERF;

        gOptions[EGG_DROPS].hide = true;
        gOptions[EGG_DROPS].value = ConfigEnums::EGG_NECTAR;
        gConfig[EGG_DROPS] = ConfigEnums::EGG_NECTAR;

        gOptions[PELLET_POSY].hide = true;
        gOptions[PELLET_POSY].value = ConfigEnums::PELMATCH_ON;
        gConfig[PELLET_POSY] = ConfigEnums::PELMATCH_ON;


        Game::VsGame::VsSlotCardMgr::sAllCards[Game::VsGame::ALL_FLOWER]->varibleForward();
        Game::VsGame::VsSlotCardMgr::sAllCards[Game::VsGame::RESET_BEDAMA]->varibleForward();
    }
}

Option gOptions[] = {
    {
        "Onion Marbles",
        { "Vanilla", "Buried", "Removed" },
        { "Red and Blue marbles will spawn like in vanilla", "Red and Blue marbles will spawn buried", "Red and Blue marbles will not be spawned" },
        3,
        0
    },
    {
        "Marble Carrying",
        { "Disallowed", "Allowed" },
        { "Pikmin will not be able to pick up their marble", "Pikmin will be allowed to pick up their marble "},
        2,
        0
    },
    {
        "Cherries Spawn",
        { "Frenziedly", "Frequently", "Often", "Vanilla", "Occasionally", "Rarely", "Never" },
        { 
            "Controls the speed in which cherries will spawn",
            "Controls the speed in which cherries will spawn",
            "Controls the speed in which cherries will spawn",
            "Controls the speed in which cherries will spawn",
            "Controls the speed in which cherries will spawn",
            "Controls the speed in which cherries will spawn",
            "Controls the speed in which cherries will spawn"
        },
        7,
        3
    },
    {
        "Spicy Spray",
        { "Normal", "Nerfed", "Useless" },
        { "Spicy spray will act like normal", "Pikmin will lose their spicy effect after killing another pikmin", "Using a spicy spray will bloom pikmin flowers" },
        3,
        0
    },
    {
        "Bitter Spray",
        { "Bury", "Despicy", "Kill", "Zap", "Element", "Deflower" },
        { 
            "Bitter sprays will bury afflicted pikmin for 10 seconds", 
            "Bitter sprays will remove the spicy effect from afflicted pikmin or bury them if they are not spicy",
            "Bitter sprays will kill afflicted pikmin (they will be rebirthed at base)",
            "Bitter sprays will zap afflicted pikmin",
            "Bitter sprays will apply a fire/water effect to the afflicted pikmin",
            "Bitter sprays will deflower afflicted pikmin"
        },
        6,
        0
    },
    {
        "Shearwigs",
        { "Spawn", "Don't Spawn" },
        { "Shearwigs will spawn from marbles as normal", "Shearwigs will not spawn from marbles" },
        2,
        0
    },
    {
        "Eggs",
        { "Drop All", "Don't Drop Sprays", "Don't Drop Mitites", "Only Drop Nectar", "Only Drop 1 Nectar"},
        { 
            "Eggs will have their normal drops", 
            "Eggs and bittered enemies will not drop sprays", 
            "Eggs will not drop mitites", 
            "Eggs will not drop sprays or mitites and bittered enemies will not drop sprays", 
            "Eggs and bittered enemies will only drop a single nectar"
        },
        5,
        0
    },
    {
        "Autopluck",
        { "On", "Off" },
        { "Enables Pikmin 3 style autopluck", "Plucking will be the same as normal Pikmin 2" },
        2,
        1
    },
    {
        "Card Use",
        { "Manual", "Automatic" },
        { "Slot machine cards will be used with Y", "Slot machine cards will be automatically used" },
        2,
        0
    },
    {
        "Versus Hiba",
        { "Off", "On" },
        { "Versus Hiba will not spawn", "Versus Hiba will be spawned" },
        2,
        0
    },
    {
        "Pikmin Revive",
        { "On", "Off" },
        { "Pikmin will be rebirthed after fighting another pikmin", "Pikmin will not be rebirthed" },
        2,
        0
    },
    {
        "Pellet Posies",
        { "Normal", "Start Matched" },
        { "Pellet Posies will iterate through all active colors", "Pellet Posies will start matched with your color" },
        2,
        0
    },
    {
        "Pikmin Birthing",
        { "Sprouts", "Pikmin" },
        { "Pikmin will be born as sprouts", "Pikmin will be born like in Pikmin 4 dandori battles" },
        2,
        0
    },
    {
        "Friendly Bitters",
        { "Off", "On" },
        { "Pikmin cannot be afflicted by their Captain's bitters", "Pikmin will be afflicted by their Captains's bitters" },
        2,
        0
    },
    {
        "Friendly Fire",
        { "Off", "On" },
        { "Cherries can target you and your teammates", "Cherries cannot target you or your teammates" },
        2,
        0
    },
    {
        "Marble Capture",
        { "Victory", "Eliminate", "Steal Marbles", "Steal Sprays" },
        { 
            "The Player who captures a marble wins", 
            "The player who's marble was captured is eliminated", 
            "Eliminates the player and gives the capturer their marbles", 
            "Eliminates the player and gives the capturer their sprays" 
        },
        4,
        0
    }
};


// gConfig
int gConfig[ARRAY_SIZE(gOptions)];

int GetConfigSize() {
    return ARRAY_SIZE(gConfig);
}

#define OPTIONS_PER_PAGE (10)


#define PAGE_COUNT (ARRAY_SIZE(gOptions) / OPTIONS_PER_PAGE)

void VsOptionsMenuMgr::init() {
    mBackground = nullptr;
    LoadResource::Arg loadArg(cBackgroundName);
	LoadResource::Node* resource = gLoadResourceMgr->load(loadArg);
	if (resource) {
		ResTIMG* starImg = static_cast<ResTIMG*>(resource->mFile);
        mBackground = new J2DPictureEx(starImg, 0);
	}
    mMenuCooldown = true;
    mController = new Controller(JUTGamePad::PORT_0);
    for (int i = 0; i < ARRAY_SIZE(mMenus); i++) {
        mMenus[i] = nullptr;
        mMenuIDs[i] = 0;
    }
    StartMenu<VsConfigMenu>();
}

bool VsOptionsMenuMgr::update() {
    if (!mActiveMenu) return true;

    if (mMenuCooldown) {
        OSReport("Menu Cooldown %i\n", mMenuCooldown);
        mMenuCooldown = false;
        return false;
    }

    bool isDone = mActiveMenu->update(this);
    if (isDone) {
        for (int i = 0; i < ARRAY_SIZE(mMenus); i++) {
            if (mMenus[i]) {
                mMenus[i]->cleanup();
            }
        }
        return true;
    }
    return false;
}


void VsOptionsMenuMgr::draw(Graphics& gfx) {
    if (mBackground) {
        JGeometry::TBox2f screenSize (0.0f, 0.0f, getScreenSize().x, getScreenSize().y);
        mBackground->drawOut(screenSize, screenSize);
    }
    
    if (mActiveMenu) mActiveMenu->draw(this, gfx);

    if (gTournamentMode) {
        J2DPrint print (getPikminFont(), 0.0f);
        print.mGlyphHeight /= 3;
        print.mGlyphWidth  /= 3;
        print.print(10.0f, 60.0f, "Tournament Mode");
    }
}


void VsConfigMenu::init(VsOptionsMenuMgr* menu) {
    mPageNumber = 0;
    mTooltipMessage = "";
    mSelectedOption = 0;
    if (gTournamentMode) {
        mSelectedOption    = 1;
        mCursorOptionIndex = 1;
    }
}

void VsConfigMenu::cleanup() {
    for (int i = 0; i < ARRAY_SIZE(gConfig); i++) {
        gConfig[i] = gOptions[i].getValue();        
    }
    Game::gGameConfig.mParms.mVsHiba.mData = gConfig[VS_HIBA];
    Game::gGameConfig.mParms.mVsY.mData    = gConfig[VS_Y];
    if (gConfig[MARBLE_BURY] == ConfigEnums::PLACE_NOTHING) {
        Game::VsGame::VsSlotCardMgr::sUsingCards[Game::VsGame::RESET_BEDAMA] = false;
    }
}

bool VsConfigMenu::update(VsOptionsMenuMgr* menu) {
    int startIdx = OPTIONS_PER_PAGE * mPageNumber;
    int endIdx = OPTIONS_PER_PAGE * (mPageNumber + 1);
    endIdx = MIN(endIdx, ARRAY_SIZE(gOptions));

    if (menu->mController->isButtonDown(JUTGamePad::PRESS_Z)) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0);
        menu->StartMenu<VsCardMenu>();
        return false;
    }

    if (menu->mController->isButtonDown(JUTGamePad::PRESS_A)) {
        if (gOptions[mCursorOptionIndex].func) {
            gOptions[mCursorOptionIndex].func(menu);
        }
    }

    if ((menu->mController->isButtonDown(JUTGamePad::PRESS_A) && mCursorOptionIndex == endIdx) || menu->mController->isButtonDown(JUTGamePad::PRESS_START | JUTGamePad::PRESS_B)) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CLOSE, 0);
        return true;
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_DOWN | JUTGamePad::PRESS_A) && mCursorOptionIndex < endIdx) {
        mCursorOptionIndex++;

        while (gOptions[mCursorOptionIndex].hide && mCursorOptionIndex < ARRAY_SIZE(gOptions)) {
            mCursorOptionIndex++;
        }

        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_UP) && mCursorOptionIndex > startIdx) {
        int prevIdx = mCursorOptionIndex;
        mCursorOptionIndex--;
        while (gOptions[mCursorOptionIndex].hide) {
            
            if (mCursorOptionIndex % OPTIONS_PER_PAGE == 0 && gOptions[mCursorOptionIndex].hide) {
                while (gOptions[mCursorOptionIndex].hide) mCursorOptionIndex++;
            }
            else {
                mCursorOptionIndex--;
            }
        }
        if (prevIdx != mCursorOptionIndex) PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_RIGHT)) {
        gOptions[mCursorOptionIndex].incOption();
        PSSystem::spSysIF->playSystemSe(PSSE_SY_SOUND_CONFIG, 0);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_LEFT)) {
        gOptions[mCursorOptionIndex].decOption();
        PSSystem::spSysIF->playSystemSe(PSSE_SY_SOUND_CONFIG, 0);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_R) && mPageNumber < (PAGE_COUNT)) {
        mPageNumber++;
        mCursorOptionIndex += OPTIONS_PER_PAGE;
        while (gOptions[mCursorOptionIndex].hide) {
            mCursorOptionIndex++;
        }
        if (mCursorOptionIndex > ARRAY_SIZE(gOptions)) {
            mCursorOptionIndex = ARRAY_SIZE(gOptions);
        }
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_L) && mPageNumber > 0) {
        mPageNumber--;
        
        mCursorOptionIndex -= OPTIONS_PER_PAGE;
        while (gOptions[mCursorOptionIndex].hide) {
            mCursorOptionIndex++;
        }
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0);
    }
    return false;
}

const JUtility::TColor gBluePrintGrad = 0x2020ffff;
const JUtility::TColor gBluePrintBase = 0xffffffff;

const JUtility::TColor gRedPrintGrad = 0xff2020ff;
const JUtility::TColor gRedPrintBase = 0xffffffff;



void VsConfigMenu::draw(VsOptionsMenuMgr* menu, Graphics& gfx) {
    J2DPrint print (getPikminFont(), 0.0f);
    J2DPrint printInfo (getPikminFont(), 0.0f);
    printInfo.mGlyphHeight /= 2;
    printInfo.mGlyphWidth  /= 2;
    J2DPrint printBlue (getPikminFont(), gBluePrintGrad, gBluePrintBase);
    J2DPrint printRed (getPikminFont(), gRedPrintGrad, gRedPrintBase);
    Game::gNaviNum = Game::CalcNaviNum();
    print.print(10.0f, 30.0f, "4P-Battle Option Menu | Players: %i\n", Game::gNaviNum);
    print.print(500.0f, 440.0f, "Page %i", mPageNumber + 1);

    int startIdx = OPTIONS_PER_PAGE * mPageNumber;
    int endIdx = OPTIONS_PER_PAGE * (mPageNumber + 1);
    endIdx = MIN(endIdx, ARRAY_SIZE(gOptions));

    for (int i = startIdx; i < endIdx; i++) {
        J2DPrint& specialPrint = (i == mCursorOptionIndex) ? printRed : printBlue;
        gOptions[i].print(print, specialPrint, i - startIdx);
    }

    J2DPrint& donePrint = (endIdx == mCursorOptionIndex) ? printRed : print;
    
    donePrint.print(50.0f, 70.0f + 30.0f * (endIdx - startIdx), "Done");

    if (mCursorOptionIndex < endIdx) {
        mTooltipMessage = gOptions[mCursorOptionIndex].getTooltipString();
    }

    print.print(20.0f, 70.0f + (mCursorOptionIndex - startIdx) * 30.0f, ">");

    printInfo.print(20.0f, 440.0f, "%s", mTooltipMessage);
}

void Option::print(J2DPrint& printer, J2DPrint& printer2, int idx) {
    if (hide) {
        return;
    }
    if (!func) {
        printer.print(50.0f, 70.0f + 30.0f * idx, "%s", name);
        printer.print(300.0f, 70.0f + 30.0f * idx, "-");
        printer2.print(300.0f, 70.0f + 30.0f * idx, "  %s",  valueStrings[value]);
    }
    else {
        printer2.print(50.0f, 70.0f + 30.0f * idx, "%s", name);
    }
    
    //printer.print(50.0f, 70.0f + 30.0f * idx, "%s", name);
}




// NOTE: Screen size is 640x480

VsOptionsMenuMgr::VsOptionsMenuMgr() {
    mActiveMenu   = nullptr;
    mMenuCooldown = true;
    for (int i = 0; i < ARRAY_SIZE(mMenus); i++) {
        mMenus[i] = nullptr;
        mMenuIDs[i] = 0;
    }
}

template <typename T>
void VsOptionsMenuMgr::StartMenu() {
    mMenuCooldown = true;

    for (int i = 0; i < ARRAY_SIZE(mMenus); i++) {
        if (!mMenus[i]) {
            mMenus[i] = new T;
            mMenuIDs[i] = T::sMenuID;
            mActiveMenu = mMenus[i];
            mActiveMenu->init(this);
            break;
        }
        else if (mMenuIDs[i] == T::sMenuID) {
            mActiveMenu = mMenus[i];
        }
    }

    JUT_ASSERT(mActiveMenu, "NO ACTIVE MENU!");
}

void CardImage::loadImage(JKRArchive* archive) {
    const char* texname = mCardPtr->GetTexName();

    ResTIMG* img = (ResTIMG*)archive->getResource(texname);
    if (img) {
        mPicture = new J2DPictureEx(img, 0);
    } else {
        JUT_PANIC("%s not found !\n", texname);
    }
}

static JUtility::TColor activeWhite (0xff, 0xff, 0xff, 0xff);
static JUtility::TColor inactiveWhite (0x00, 0x00, 0x00, 0xff);

void CardImage::draw(Vector2f& position, Vector2f& size) {
    if (!mIsCardActive) {
        mPicture->setAlpha(0xA0);
    }
    else {
        mPicture->setAlpha(0xFF);
    }
    Vector2f corner2 = position + size;
    JGeometry::TBox2f box (position.x, position.y, corner2.x, corner2.y);
    if (mPicture) {
        mPicture->drawOut(box, box);
    }
}

void CardImage::actionLeft(VsCardMenu* menu) {
    if (mCardPtr->varibleBackward()) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_SOUND_CONFIG, 0);
        delete mPicture;
        loadImage(menu->mCardArchive);
    }
}

void CardImage::actionRight(VsCardMenu* menu) {
    if (mCardPtr->varibleForward()) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_SOUND_CONFIG, 0);
        delete mPicture;
        loadImage(menu->mCardArchive);
    }
}


void VsCardMenu::init(VsOptionsMenuMgr* menu) {
    mCursorAt = 0;
    mCardCount = Game::VsGame::VsSlotCardMgr::sTotalCardCount;
    mCards = new CardImage[mCardCount];

    mCardArchive = JKRArchive::mount("user/Kando/vstex/arc.szs", JKRArchive::EMM_Mem, nullptr, JKRArchive::EMD_Head);

    Vector2f startOffset(50.0f, 150.0f);

    Vector2f cardSize (60.0f);
    Vector2f spaceBetween (20.0f);

    for (int i = 0; i < mCardCount; i++) {
        mCards[i].SetCardPtr(Game::VsGame::VsSlotCardMgr::sAllCards[i]);
        mCards[i].loadImage(mCardArchive);

        int x = i % 6;
        int y = i / 6;

        mCards[i].mPosition.x = startOffset.x + (spaceBetween.x + cardSize.x) * x;
        mCards[i].mPosition.y = startOffset.y + (spaceBetween.y + cardSize.y) * y;
        mCards[i].mSize = cardSize;
        mCards[i].mIsCardActive = Game::VsGame::VsSlotCardMgr::sUsingCards[i];
    }
}

bool VsCardMenu::update(VsOptionsMenuMgr* menu) {

    if (menu->mController->isButtonDown(JUTGamePad::PRESS_RIGHT) && mCursorAt + 1 < mCardCount) {
        mCursorAt++;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_LEFT) && mCursorAt - 1 >= 0) {
        mCursorAt--;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_DOWN) && mCursorAt + 6 < mCardCount) {
        mCursorAt += 6;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_UP) && mCursorAt - 6 >= 0) {
        mCursorAt -= 6;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }

    if (menu->mController->isButtonDown(JUTGamePad::PRESS_A)) {
        bool& isCardActive = mCards[mCursorAt].mIsCardActive;
        if (isCardActive) {
            isCardActive = false;
            PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CANCEL, 0);
        }
        else {
            isCardActive = true;
            PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE, 0);
        }
        
    }

    if (menu->mController->isButtonDown(JUTGamePad::PRESS_Y)) {
        mCards[mCursorAt].actionRight(this);
    }
    else if (menu->mController->isButtonDown(JUTGamePad::PRESS_X)) {
        mCards[mCursorAt].actionLeft(this);
    }


    if (menu->mController->isButtonDown(JUTGamePad::PRESS_Z)) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0);
        menu->StartMenu<CharacterSelect>();
        return false;
    }
    if (menu->mController->isButtonDown(JUTGamePad::PRESS_START | JUTGamePad::PRESS_B)) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CLOSE, 0);
        return true;
    }
    return false;
}

void VsCardMenu::draw(VsOptionsMenuMgr* menu, Graphics& gfx) {
    J2DPrint print (getPikminFont(), 0.0f);
    J2DPrint printCursor (getPikminFont(), 0.0f);

    printCursor.mGlyphHeight *= 3.75f;
    printCursor.mGlyphWidth  *= 2.75f;

    J2DPrint printInfo (getPikminFont(), 0.0f);
    printInfo.mGlyphHeight /= 2;
    printInfo.mGlyphWidth  /= 2;

    Game::gNaviNum = Game::CalcNaviNum();
    print.print(10.0f, 30.0f, "4P-Battle Card Menu | Players: %i\n", Game::gNaviNum);

    if (mCursorAt < mCardCount) {
    
        Vector2f cursorPosition = mCards[mCursorAt].mPosition;

        printCursor.print(cursorPosition.x - (printCursor.mGlyphWidth / 3) / 2, cursorPosition.y + mCards[mCursorAt].mSize.y, "[ ]");

        printInfo.print(20.0f, 440.0f, "%s", mCards[mCursorAt].mCardPtr->getDescription());
    }

    for (int i = 0; i < mCardCount; i++) {
        mCards[i].draw();
    }

    

    
}

void VsCardMenu::cleanup() {
    for (int i = 0; i < mCardCount; i++) {
        Game::VsGame::VsSlotCardMgr::sUsingCards[i] = mCards[i].mIsCardActive;
    }
}


void CharacterSelect::load() {
    loadAndRead(this, "/player/names.txt");
    for (int i = 0; i < mCharacterCount; i++) {
        mCharacters[i].mPicture = new J2DPictureEx(mCharacters[i].loadImage(), 0);
    }
}

ResTIMG* CharacterImage::loadImage() {
    char buffer[256];
    sprintf(buffer, "/player/%s/icon.bti", mCharacterName);

    LoadResource::Arg loadArg(buffer);
	LoadResource::Node* resource = gLoadResourceMgr->load(loadArg);


    if (resource) {
		ResTIMG* characterIcon = static_cast<ResTIMG*>(resource->mFile);
        return characterIcon;
	}
    
    return nullptr;
}

ResTIMG* CharacterData::loadImage() {
    char buffer[256];
    sprintf(buffer, "/player/%s/icon.bti", mName);

    LoadResource::Arg loadArg(buffer);
	LoadResource::Node* resource = gLoadResourceMgr->load(loadArg);


    if (resource) {
		ResTIMG* characterIcon = static_cast<ResTIMG*>(resource->mFile);
        return characterIcon;
	}
    
    return nullptr;
}

CharacterData sCharacters[4];

void* CharacterData::loadModel() {
    char buffer[256];
    OSReport("Name %s\n", mName);
    sprintf(buffer, "/player/%s/model.bmd", mName);

    LoadResource::Arg loadArg(buffer);
	LoadResource::Node* resource = gLoadResourceMgr->load(loadArg);

    void* model = nullptr;

    if (resource) {
		model = (resource->mFile);
        if (model) return model;
	}

    JUT_ASSERT("%s Missing!\n", buffer);
    
    
}

void* CharacterData::loadAST() {
    char buffer[256];
    sprintf(buffer, "/player/%s/theme.ast", mName);

    LoadResource::Arg loadArg(buffer);
	LoadResource::Node* resource = gLoadResourceMgr->load(loadArg);

    void* file = nullptr;

    if (resource) {
		file = resource->mFile;
	}
    
    return file;
}

VsCardMenu::~VsCardMenu() {
    delete mCardArchive;
    delete[] mCards;
}

void CharacterImage::draw(Vector2f& position, Vector2f& size) {
    Vector2f corner2 = position + size;
    JGeometry::TBox2f box (position.x, position.y, corner2.x, corner2.y);
    if (mPicture) {
        mPicture->drawOut(box, box);
    }
}



void CharacterImage::read(Stream& stream) {
    mCharacterName = stream.readString(nullptr, 0);
}

void CharacterSelect::read(Stream& stream) {
    mCharacterCount = stream.readInt();
    mCharacters = new CharacterImage[mCharacterCount];
    for (int i = 0; i < mCharacterCount; i++) {
        mCharacters[i].SetID(i);
        mCharacters[i].read(stream);
    }
}

void CharacterSelect::init(VsOptionsMenuMgr* menu) {
    load();

    mControllers[0] = menu->mController;
    for (int i = 1; i < 4; i++) {
        mControllers[i] = new Controller((JUTGamePad::EPadPort)i);
    }

    for (int i = 0; i < 4; i++) {
        mCursors[i] = sCharacters[i].mCharaterID;
        mNameCursors[i] = 0;
        strcpy(mPlayerNames[i], sCharacters[i].mDispName);
        CharacterData::PrepareDisplayName(CharacterData::sMaxNameSize, mPlayerNames[i]);
        mSelectingCharactor[i] = false;
    }

    Vector2f startOffset(0.0f, 50.0f);

    Vector2f cardSize (50.0f);
    Vector2f spaceBetween (0.0f);

    for (int i = 0; i < mCharacterCount; i++) {
        

        int x = i % sRowSize;
        int y = i / sRowSize;

        mCharacters[i].mPosition.x = startOffset.x + (spaceBetween.x + cardSize.x) * x;
        mCharacters[i].mPosition.y = startOffset.y + (spaceBetween.y + cardSize.y) * y;
        mCharacters[i].mSize = cardSize;
    }
}

char* CharacterImage::getDisplayName() {
    return mCharacterName; 
}

static Vector2f sNamePositions[4] = {
    Vector2f(0.0f,   350.0f),
    Vector2f(320.0f, 350.0f),
    Vector2f(0.0f,   400.0f),
    Vector2f(320.0f, 400.0f),
};

void CharacterSelect::draw(VsOptionsMenuMgr* menu, Graphics& gfx) {
    for (int i = 0; i < mCharacterCount; i++) {
        mCharacters[i].draw();
    }

    static JUtility::TColor colors[4] =
    {
        0xff0000ff,
        0x0000ffff,
        0xffff00ff,
        0x00ff00ff
    };

    for (int i = 0; i < Game::gNaviNum; i++) {

        J2DPrint print (getPikminFont(), 0.0f);
        print.print(10.0f, 30.0f, "4P-Battle Character Select | Players: %i\n", Game::gNaviNum);

        mCharacters[mCursors[i]].draw(sNamePositions[i], mCharacters[mCursors[i]].mSize);

        Vector2f position = mCharacters[mCursors[i]].mPosition;
        Vector2f size = mCharacters[mCursors[i]].mSize;

        J2DPrint printer (getPikminFont(), colors[i], activeWhite);

        J2DPrint printer2 (getPikminFont(), colors[i], activeWhite);
        Vector2f textPosition = sNamePositions[i];
        textPosition.x += mCharacters[mCursors[i]].mSize.x;
        textPosition.y += mCharacters[mCursors[i]].mSize.y / 2;

        printer2.print(textPosition.x, textPosition.y, "%s", mPlayerNames[i]);

        f32 width;

        {
            J2DPrint testPrinter (getPikminFont(), colors[i], activeWhite);

            const char saveChar = mPlayerNames[i][mNameCursors[i]];

            char& saveCharRef = mPlayerNames[i][mNameCursors[i]];

            saveCharRef = 0;

            width = testPrinter.getWidth("%s", mPlayerNames[i]);

            saveCharRef = saveChar;
        }


        

        if (mSelectingCharactor[i]) {

            printer.mGlyphHeight /= 2;
            printer.mGlyphWidth  /= 2;

            f32 offsetX = (i & 1) ? size.x - printer.mGlyphWidth : 0.0f;
            f32 offsetY = (i > 1) ? size.y - printer.mGlyphHeight : 0.0f;

            offsetY += 10.0f;
            
            printer.print(position.x + offsetX, position.y + offsetY, "P%i", i + 1);
        }
        else {
            Vector2f textPosition = sNamePositions[i];
            textPosition.x += mCharacters[mCursors[i]].mSize.x + width;
            textPosition.y += mCharacters[mCursors[i]].mSize.y;

            printer.print(textPosition.x, textPosition.y, "^");

        }

        


        // Vector2f size = mCharacters[mCursors[i]].mSize;

        // JGeometry::TBox2f box (position, position + size);

        // mSelectImg[i]->drawOut(box, box);
    }

    
}

bool CharacterSelect::update(VsOptionsMenuMgr* menu) {
    if (menu->mController->isButtonDown(JUTGamePad::PRESS_Z)) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0);
        menu->StartMenu<VsConfigMenu>();
        return false;
    }
    for (int i = 0; i < ARRAY_SIZE(mControllers); i++) {

        

        Controller* controller = mControllers[i];
        if (mSelectingCharactor[i]) {
            strncpy(mPlayerNames[i], mCharacters[mCursors[i]].mCharacterName, ARRAY_SIZE(mPlayerNames[i]) - 1);
            CharacterData::MakeDisplayName(ARRAY_SIZE(mPlayerNames[i]), mPlayerNames[i]);
            if (controller->isButtonDown(JUTGamePad::PRESS_RIGHT) && mCursors[i] + 1 < mCharacterCount) {
                mCursors[i]++;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_LEFT) && mCursors[i] - 1 >= 0) {
                mCursors[i]--;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_DOWN) && mCursors[i] + sRowSize < mCharacterCount) {
                mCursors[i] += sRowSize;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_UP) && mCursors[i] - sRowSize >= 0) {
                mCursors[i] -= sRowSize;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_A)) {
                mSelectingCharactor[i] = false;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE, 0);

            }
        }
        else {
            if (controller->isButtonDown(JUTGamePad::PRESS_B)) {
                mSelectingCharactor[i] = true;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CANCEL, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_RIGHT) && mNameCursors[i] < CharacterData::sMaxNameSize - 2) {
                mNameCursors[i]++;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_LEFT) && mNameCursors[i] > 0) {
                mNameCursors[i]--;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_UP)) {
                char& refChar = mPlayerNames[i][mNameCursors[i]];
                refChar = NextChar(refChar);
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_DOWN)) {
                char& refChar = mPlayerNames[i][mNameCursors[i]];
                refChar = PrevChar(refChar);
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
            else if (controller->isButtonDown(JUTGamePad::PRESS_A)) {
                char& refChar = mPlayerNames[i][mNameCursors[i]];
                refChar = ToggleUpper(refChar);
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
            }
        }
    }
    if (menu->mController->isButtonDown(JUTGamePad::PRESS_START)) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CLOSE, 0);
        return true;
    }
    
    return false;
}

CharacterImage::~CharacterImage() {
    delete[] mCharacterName;
    delete mPicture;
}

void CharacterImage::delMembers() {
    
}

void CharacterSelect::cleanup() {

    for (int i = 0; i < 4; i++) {
        sCharacters[i].mCharaterID = mCursors[i];
        strcpy(sCharacters[i].mName, mCharacters[mCursors[i]].mCharacterName);
        OSReport("Name %s\n", sCharacters[i].mName);
        strcpy(sCharacters[i].mDispName, mPlayerNames[i]);
        CharacterData::CleanDisplayName(ARRAY_SIZE(sCharacters[i].mDispName), sCharacters[i].mDispName);
        
        sCharacters[i].mImage = sCharacters[i].loadImage();
    }
}

void CharacterData::makeDisplayName() {
    strncpy(mDispName, mName, MIN(ARRAY_SIZE(mName), ARRAY_SIZE(mDispName)));

    for (int i = 0; mDispName[i]; i++) {
        if (mDispName[i] == '_') {
            mDispName[i] = ' ';
        }
    }
}

void CharacterData::MakeDisplayName(int size, char* chr) {
    for (int i = 0; i < size - 1; i++) {
        if (chr[i] == '_' || chr[i] == '\0') {
            chr[i] = ' ';
        }
    }

    chr[size - 1] = '\0'; 
}

void CharacterData::PrepareDisplayName(int size, char* chr) {
    bool setSpace = false;
    for (int i = 0; i < size - 1; i++) {
        if (setSpace || chr[i] == '\0') {
            chr[i] = ' ';
            setSpace = true;
        }
    }

    chr[size - 1] = '\0'; 
}

void CharacterData::CleanDisplayName(int size, char* chr) {
    int i;
    for (i = size - 2; chr[i] == ' '; i--) {
        if (i == 0) return;
    }

    chr[i + 1] = '\0';

    OSReport("Name %s %i\n", chr, i);
}

void CharacterData::initDefaults() {
    void* handle = JKRDvdRipper::loadToMainRAM("/player/names.txt", 0, Switch_0, 0, nullptr, JKRDvdRipper::ALLOC_DIR_BOTTOM, 0, 0, 0);
	if (!handle) {
		JUT_PANIC("/player/names.txt missing!");
	}

	RamStream stream(handle, -1);
	stream.resetPosition(true, 1);

    JUT_ASSERT(stream.readInt() > 4, "NOT ENOUGH ENTRIES IN NAMES");

    CharacterImage images[4];

    for (int i = 0; i < 4; i++) {
        char* string = stream.readString(nullptr, 0);
        strcpy(sCharacters[i].mName, string);
        OSReport("Name %i %s %s\n", i, string, sCharacters[i].mName);
        sCharacters[i].makeDisplayName();
        sCharacters[i].mImage = sCharacters[i].loadImage();
        sCharacters[i].mCharaterID = i;
    }
}

CharacterSelect::~CharacterSelect() {
    delete[] mCharacters;

    for (int i = 1; i < ARRAY_SIZE(mControllers); i++) {
        delete mControllers[i];    
    }
    
}