#include "FourPlayer.h"
#include "Controller.h"
#include "Graphics.h"
#include "JSystem/J2D/J2DPrint.h"
#include "P2JME/P2JME.h"
#include "Game/GameSystem.h"
#include "PSSystem/PSSystemIF.h"

VsOptionsMenu* gOptionMenu;

enum ToolTipIDs {
    TIP_EMPTY,
    TIP_MODERN,
    TIP_LEGACY
};

void Option::print(J2DPrint& printer, J2DPrint& printer2, int idx, bool active) {
    printer.print(50.0f, 70.0f + 30.0f * idx, "%s", name);
    printer.print(300.0f, 70.0f + 30.0f * idx, "-");
    printer2.print(300.0f, 70.0f + 30.0f * idx, "  %s",  valueStrings[value]);
    
    //printer.print(50.0f, 70.0f + 30.0f * idx, "%s", name);
}

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
        { "Pikmin will not be able to pick up their marble", "Pikmin will allowed to pick up their marble "},
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
        { "Bury", "Despicy", "Electric", "Element", "Deflower" },
        { 
            "Bitter sprays will bury afflicted pikmin for 10 seconds", 
            "Bitter sprays will remove the spicy effect from afflicted pikmin",
            "Bitter sprays will electricute afflicted pikmin",
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
        { "Vanilla", "Bury", "Disabled"},
        { "Marble return will work like vanilla", "Marble return will instead bury your marble", "You will not be able to roll marble return" },
        3,
        0
    }
};


JUTFont* getPikminFont() {
    return gP2JMEMgr->mFont;
}

void VsOptionsMenu::init() {
    mController = new Controller(JUTGamePad::PORT_0);
    mPageNumber = 0;
    mTooltipMessage = "";
    
}

bool VsOptionsMenu::update() {
    if (mController->isButtonDown(JUTGamePad::PRESS_DOWN) && mCursorOptionIndex < ARRAY_SIZE(gOptions)) {
        mCursorOptionIndex++;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_UP) && mCursorOptionIndex > 0) {
        mCursorOptionIndex--;
        PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_A) && mCursorOptionIndex == ARRAY_SIZE(gOptions)) {
        return true;
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_A | JUTGamePad::PRESS_RIGHT)) {
        gOptions[mCursorOptionIndex].incOption();
        PSSystem::spSysIF->playSystemSe(PSSE_SY_SOUND_CONFIG, 0);
    }
    else if (mController->isButtonDown(JUTGamePad::PRESS_LEFT)) {
        gOptions[mCursorOptionIndex].decOption();
        PSSystem::spSysIF->playSystemSe(PSSE_SY_SOUND_CONFIG, 0);
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
    //print.print(500.0f, 440.0f, "Page %i", mPageNumber + 1);

    for (int i = 0; i < ARRAY_SIZE(gOptions); i++) {
        J2DPrint& specialPrint = (i == mCursorOptionIndex) ? printRed : printBlue;
        gOptions[i].print(print, specialPrint, i, i == mCursorOptionIndex);
    }

    J2DPrint& donePrint = (ARRAY_SIZE(gOptions) == mCursorOptionIndex) ?  printRed : print;
    
    donePrint.print(50.0f, 70.0f + 30.0f * ARRAY_SIZE(gOptions), "Done");

    if (mCursorOptionIndex < ARRAY_SIZE(gOptions)) {
        mTooltipMessage = gOptions[mCursorOptionIndex].getTooltipString();
    }

    print.print(20.0f, 70.0f + mCursorOptionIndex * 30.0f, ">");

    printInfo.print(20.0f, 440.0f, "%s", mTooltipMessage);


}