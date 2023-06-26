#include "FourPlayer.h"
#include "Controller.h"
#include "Graphics.h"
#include "JSystem/J2D/J2DPrint.h"
#include "P2JME/P2JME.h"
#include "Game/GameSystem.h"
#include "PSSystem/PSSystemIF.h"
#include "Game/VsGameSection.h"
#include "Game/GameConfig.h"

VsOptionsMenu* gOptionMenu;

Option gOptions[] = {
    {
        "Maps", 
        { "Reworked", "Vanilla" },
        { "Use remade maps that are better balenced then the Vanilla game", "Use Vanilla 2p-battle maps" },
        2,
        1
    },
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
        { "Bury", "Despicy", "Kill", "Element", "Deflower" },
        { 
            "Bitter sprays will bury afflicted pikmin for 10 seconds", 
            "Bitter sprays will remove the spicy effect from afflicted pikmin or bury them if they are not spicy",
            "Bitter sprays will kill afflicted pikmin (they will be rebirthed at base)",
            "Bitter sprays will apply a fire/water effect to the afflicted pikmin",
            "Bitter sprays will deflower afflicted pikmin"
        },
        5,
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
        "Marble Return",
        { "Vanilla", "Bury", "Disabled" },
        { "Marble return will work like vanilla", "Marble return will instead bury your marble", "You will not be able to roll marble return" },
        3,
        0
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
        "Card Sprays",
        { "Gain Spray", "Use Spray", "Disabled" },
        { "Using a spray card will give your team a spray", "Using a spray card will use a spray to no cost", "Card sprays will not be rolled" },
        3,
        0
    }
};

// gConfig
int gConfig[ARRAY_SIZE(gOptions)];

int GetConfigSize() {
    return ARRAY_SIZE(gConfig);
}


JUTFont* getPikminFont() {
    return gP2JMEMgr->mFont;
}

#define OPTIONS_PER_PAGE (10)


#define PAGE_COUNT (ARRAY_SIZE(gOptions) / OPTIONS_PER_PAGE)

void VsOptionsMenu::init() {
    mController = new Controller(JUTGamePad::PORT_0);
    mPageNumber = 0;
    mTooltipMessage = "";
    mSelectedOption = 0;
}



bool VsOptionsMenu::update() {
    int startIdx = OPTIONS_PER_PAGE * mPageNumber;
    int endIdx = OPTIONS_PER_PAGE * (mPageNumber + 1);
    endIdx = MIN(endIdx, ARRAY_SIZE(gOptions));

    if ((mController->isButtonDown(JUTGamePad::PRESS_A) && mCursorOptionIndex == endIdx) || mController->isButtonDown(JUTGamePad::PRESS_START | JUTGamePad::PRESS_B)) {
        for (int i = 0; i < ARRAY_SIZE(gConfig); i++) {
            gConfig[i] = gOptions[i].getValue();        
        }
        Game::gGameConfig.mParms.mVsHiba.mData = gConfig[VS_HIBA];
        Game::gGameConfig.mParms.mVsY.mData    = gConfig[VS_Y];
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CLOSE, 0);

        
        return true;
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_DOWN | JUTGamePad::PRESS_A) && mCursorOptionIndex < endIdx) {
        mCursorOptionIndex++;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_UP) && mCursorOptionIndex > startIdx) {
        mCursorOptionIndex--;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_RIGHT)) {
        gOptions[mCursorOptionIndex].incOption();
        PSSystem::spSysIF->playSystemSe(PSSE_SY_SOUND_CONFIG, 0);
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_LEFT)) {
        gOptions[mCursorOptionIndex].decOption();
        PSSystem::spSysIF->playSystemSe(PSSE_SY_SOUND_CONFIG, 0);
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_R) && mPageNumber < (PAGE_COUNT)) {
        mPageNumber++;
        mCursorOptionIndex += OPTIONS_PER_PAGE;
        if (mCursorOptionIndex > ARRAY_SIZE(gOptions)) {
            mCursorOptionIndex = ARRAY_SIZE(gOptions);
        }
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0);
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_L) && mPageNumber > 0) {
        mPageNumber--;
        mCursorOptionIndex -= OPTIONS_PER_PAGE;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MESSAGE_EXIT, 0);
    }

    return false;
}



const JUtility::TColor gBluePrintGrad = 0x2020ffff;
const JUtility::TColor gBluePrintBase = 0xffffffff;

const JUtility::TColor gRedPrintGrad = 0xff2020ff;
const JUtility::TColor gRedPrintBase = 0xffffffff;



// NOTE: Screen size is 640x480

void VsOptionsMenu::draw(Graphics& gfx) {
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
    printer.print(50.0f, 70.0f + 30.0f * idx, "%s", name);
    printer.print(300.0f, 70.0f + 30.0f * idx, "-");
    printer2.print(300.0f, 70.0f + 30.0f * idx, "  %s",  valueStrings[value]);
    
    //printer.print(50.0f, 70.0f + 30.0f * idx, "%s", name);
}

VsOptionsMenu::VsOptionsMenu() {
    mPageNumber = 0;
    mSelectedOption = 0;
    mCursorOptionIndex = 0;
    mTooltipMessage = nullptr;
}