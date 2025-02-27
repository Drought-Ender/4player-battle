#include "Game/enemyInfo.h"
#include "Dolphin/string.h"
#include "types.h"

namespace Game {
// clang-format off
EnemyInfo gEnemyInfo[] = {
// name                   ID                                   pID                                members flags      model           anim            animgr          texture     param       collision       stone           childID                           chNum droptype
   {"Pelplant",           EnemyTypeID::EnemyID_Pelplant,       -1,                                1,      0x0007,    "Pelplant",     "Pelplant",     "Pelplant",     "Pelplant", "Pelplant", "Pelplant",     "Pelplant",     -1,                               0,    BDT_Empty},
   {"Kochappy",           EnemyTypeID::EnemyID_Kochappy,       -1,                                1,      0x0117,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Normal},
   {"BlueKochappy",       EnemyTypeID::EnemyID_BlueKochappy,   -1,                                1,      0x0117,    "Kochappy",     "Kochappy",     "Kochappy",     "",         "",         "Kochappy",     "Kochappy",     -1,                               0,    BDT_Normal},
   {"YellowKochappy",     EnemyTypeID::EnemyID_YellowKochappy, -1,                                1,      0x0117,    "Kochappy",     "Kochappy",     "Kochappy",     "",         "",         "Kochappy",     "Kochappy",     -1,                               0,    BDT_Normal},
   {"KumaKochappy",       EnemyTypeID::EnemyID_KumaKochappy,   -1,                                1,      0x0117,    "",             "Kochappy",     "Kochappy",     "",         "",         "Kochappy",     "",             -1,                               0,    BDT_Normal},
   {"Chappy",             EnemyTypeID::EnemyID_Chappy,         -1,                                1,      0x0097,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"BlueChappy",         EnemyTypeID::EnemyID_BlueChappy,     -1,                                1,      0x0097,    "Chappy",       "Chappy",       "Chappy",       "",         "",         "Chappy",       "Chappy",       -1,                               0,    BDT_Strong},
   {"YellowChappy",       EnemyTypeID::EnemyID_YellowChappy,   -1,                                1,      0x0097,    "Chappy",       "Chappy",       "Chappy",       "",         "",         "Chappy",       "Chappy",       -1,                               0,    BDT_Strong},
   {"Pom",                EnemyTypeID::EnemyID_Pom,            -1,                                1,      0x0001,    "Pom",          "Pom",          "Pom",          "Pom",      "Pom",      "Pom",          "Pom",          -1,                               0,    BDT_Empty},
   {"BluePom",            EnemyTypeID::EnemyID_BluePom,        EnemyTypeID::EnemyID_Pom,          1,      0x0006,    "Pom",          "Pom",          "Pom",          "Pom",      "Pom",      "Pom",          "Pom",          -1,                               0,    BDT_Empty},
   {"RedPom",             EnemyTypeID::EnemyID_RedPom,         EnemyTypeID::EnemyID_Pom,          1,      0x0006,    "Pom",          "Pom",          "Pom",          "Pom",      "Pom",      "Pom",          "Pom",          -1,                               0,    BDT_Empty},
   {"YellowPom",          EnemyTypeID::EnemyID_YellowPom,      EnemyTypeID::EnemyID_Pom,          1,      0x0006,    "Pom",          "Pom",          "Pom",          "Pom",      "Pom",      "Pom",          "Pom",          -1,                               0,    BDT_Empty},
   {"BlackPom",           EnemyTypeID::EnemyID_BlackPom,       EnemyTypeID::EnemyID_Pom,          1,      0x0006,    "Pom",          "Pom",          "Pom",          "Pom",      "Pom",      "Pom",          "Pom",          -1,                               0,    BDT_Empty},
   {"WhitePom",           EnemyTypeID::EnemyID_WhitePom,       EnemyTypeID::EnemyID_Pom,          1,      0x0006,    "Pom",          "Pom",          "Pom",          "Pom",      "Pom",      "Pom",          "Pom",          -1,                               0,    BDT_Empty},
   {"RandPom",            EnemyTypeID::EnemyID_RandPom,        EnemyTypeID::EnemyID_Pom,          1,      0x0006,    "Pom",          "Pom",          "Pom",          "Pom",      "Pom",      "Pom",          "Pom",          -1,                               0,    BDT_Empty},
   {"Kogane",             EnemyTypeID::EnemyID_Kogane,         -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Wealthy",            EnemyTypeID::EnemyID_Wealthy,        -1,                                1,      0x0007,    "Kogane",       "Kogane",       "Kogane",       "",         "",         "Kogane",       "Kogane",       -1,                               0,    BDT_Empty},
   {"Fart",               EnemyTypeID::EnemyID_Fart,           -1,                                1,      0x0007,    "Kogane",       "Kogane",       "Kogane",       "",         "",         "Kogane",       "Kogane",       -1,                               0,    BDT_Empty},
   {"Frog",               EnemyTypeID::EnemyID_Frog,           -1,                                1,      0x0097,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"MaroFrog",           EnemyTypeID::EnemyID_MaroFrog,       -1,                                1,      0x0097,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"UjiA",               EnemyTypeID::EnemyID_UjiA,           -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Weak},
   {"UjiB",               EnemyTypeID::EnemyID_UjiB,           -1,                                1,      0x0117,    "",             "UjiA",         "",             "",         "",         "",             "",             -1,                               0,    BDT_Weak},
   {"Armor",              EnemyTypeID::EnemyID_Armor,          -1,                                1,      0x0097,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Tobi",               EnemyTypeID::EnemyID_Tobi,           -1,                                1,      0x0117,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Weak},
   {"Imomushi",           EnemyTypeID::EnemyID_Imomushi,       -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Weak},
   {"Qurione",            EnemyTypeID::EnemyID_Qurione,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_Egg,         1,    BDT_Empty},
   {"Rock",               EnemyTypeID::EnemyID_Rock,           -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Stone",              EnemyTypeID::EnemyID_Stone,          EnemyTypeID::EnemyID_Rock,         1,      0x0206,    "Rock",         "Rock",         "Rock",         "Rock",     "Rock",     "Rock",         "Rock",         -1,                               0,    BDT_Empty},
   {"Kabuto",             EnemyTypeID::EnemyID_Kabuto,         -1,                                1,      0x0097,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_Stone,       5,    BDT_Normal},
   {"Rkabuto",            EnemyTypeID::EnemyID_Rkabuto,        -1,                                1,      0x0097,    "Kabuto",       "Kabuto",       "Kabuto",       "",         "",         "Kabuto",       "Kabuto",       EnemyTypeID::EnemyID_Stone,       5,    BDT_Normal},
   {"Fkabuto",            EnemyTypeID::EnemyID_Fkabuto,        -1,                                1,      0x0097,    "Kabuto",       "Kabuto",       "Kabuto",       "",         "",         "Kabuto",       "Kabuto",       EnemyTypeID::EnemyID_Stone,       5,    BDT_Normal},
   {"Hiba",               EnemyTypeID::EnemyID_Hiba,           -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"GasHiba",            EnemyTypeID::EnemyID_GasHiba,        -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"ElecHiba",           EnemyTypeID::EnemyID_ElecHiba,       -1,                                2,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Sarai",              EnemyTypeID::EnemyID_Sarai,          -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Demon",              EnemyTypeID::EnemyID_Demon,          -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"BombSarai",          EnemyTypeID::EnemyID_BombSarai,      -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_Bomb,        2,    BDT_Strong},
   {"Tank",               EnemyTypeID::EnemyID_Tank,           -1,                                1,      0x0097,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Wtank",              EnemyTypeID::EnemyID_Wtank,          -1,                                1,      0x0097,    "Tank",         "Tank",         "Tank",         "",         "",         "Tank",         "Tank",         -1,                               0,    BDT_Strong},
   {"Catfish",            EnemyTypeID::EnemyID_Catfish,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Normal},
   {"Tadpole",            EnemyTypeID::EnemyID_Tadpole,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Weak},
   {"ElecBug",            EnemyTypeID::EnemyID_ElecBug,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Normal},
   {"Mar",                EnemyTypeID::EnemyID_Mar,            -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Hanachirashi",       EnemyTypeID::EnemyID_Hanachirashi,   -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Kurage",             EnemyTypeID::EnemyID_Kurage,         -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Normal},
   {"OniKurage",          EnemyTypeID::EnemyID_OniKurage,      -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Queen",              EnemyTypeID::EnemyID_Queen,          -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_Baby,        50,   BDT_Boss},
   {"Baby",               EnemyTypeID::EnemyID_Baby,           -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Weak},
   {"FireChappy",         EnemyTypeID::EnemyID_FireChappy,     -1,                                1,      0x0097,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Hana",               EnemyTypeID::EnemyID_Hana,           -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"KumaChappy",         EnemyTypeID::EnemyID_KumaChappy,     -1,                                1,      0x0097,    "",             "Chappy",       "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"LeafChappy",         EnemyTypeID::EnemyID_LeafChappy,     -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"SnakeCrow",          EnemyTypeID::EnemyID_SnakeCrow,      -1,                                1,      0x0037,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Boss},
   {"SnakeWhole",         EnemyTypeID::EnemyID_SnakeWhole,     -1,                                1,      0x0037,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Boss},
   {"Bomb",               EnemyTypeID::EnemyID_Bomb,           -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Egg",                EnemyTypeID::EnemyID_Egg,            -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_TamagoMushi, 10,   BDT_Empty},
   {"PanModoki",          EnemyTypeID::EnemyID_PanModoki,      -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_PanHouse,    1,    BDT_Empty},
   {"OoPanModoki",        EnemyTypeID::EnemyID_OoPanModoki,    -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_PanHouse,    1,    BDT_Empty},
   {"PanHouse",           EnemyTypeID::EnemyID_PanHouse,       -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Fuefuki",            EnemyTypeID::EnemyID_Fuefuki,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Tanpopo",            EnemyTypeID::EnemyID_Tanpopo,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_ShijimiChou, 5,    BDT_Empty},
   {"Watage",             EnemyTypeID::EnemyID_Watage,         -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Clover",             EnemyTypeID::EnemyID_Clover,         -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"HikariKinoko",       EnemyTypeID::EnemyID_HikariKinoko,   -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Ooinu_s",            EnemyTypeID::EnemyID_Ooinu_s,        -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"KareOoinu_s",        EnemyTypeID::EnemyID_KareOoinu_s,    -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Ooinu_l",            EnemyTypeID::EnemyID_Ooinu_l,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_ShijimiChou, 5,    BDT_Empty},
   {"KareOoinu_l",        EnemyTypeID::EnemyID_KareOoinu_l,    -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Wakame_s",           EnemyTypeID::EnemyID_Wakame_s,       -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Wakame_l",           EnemyTypeID::EnemyID_Wakame_l,       -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Tukushi",            EnemyTypeID::EnemyID_Tukushi,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"DaiodoRed",          EnemyTypeID::EnemyID_DaiodoRed,      -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"DaiodoGreen",        EnemyTypeID::EnemyID_DaiodoGreen,    -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Magaret",            EnemyTypeID::EnemyID_Magaret,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_ShijimiChou, 5,    BDT_Empty},
   {"Nekojarashi",        EnemyTypeID::EnemyID_Nekojarashi,    -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Chiyogami",          EnemyTypeID::EnemyID_Chiyogami,      -1,                                1,      0x0207,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"Zenmai",             EnemyTypeID::EnemyID_Zenmai,         -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"KingChappy",         EnemyTypeID::EnemyID_KingChappy,     -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Boss},
   {"Miulin",             EnemyTypeID::EnemyID_Miulin,         -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Strong},
   {"Damagumo",           EnemyTypeID::EnemyID_Damagumo,       -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Boss},
   {"BigFoot",            EnemyTypeID::EnemyID_BigFoot,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_TamagoMushi, 30,   BDT_Boss},
   {"Houdai",             EnemyTypeID::EnemyID_Houdai,         -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Boss},
   {"FireOtakara",        EnemyTypeID::EnemyID_FireOtakara,    -1,                                1,      0x0007,    "",             "",             "Otakara",      "",         "",         "Otakara",      "Otakara",      -1,                               0,    BDT_Normal},
   {"WaterOtakara",       EnemyTypeID::EnemyID_WaterOtakara,   -1,                                1,      0x0007,    "FireOtakara",  "FireOtakara",  "Otakara",      "",         "",         "Otakara",      "Otakara",      -1,                               0,    BDT_Normal},
   {"GasOtakara",         EnemyTypeID::EnemyID_GasOtakara,     -1,                                1,      0x0007,    "FireOtakara",  "FireOtakara",  "Otakara",      "",         "",         "Otakara",      "Otakara",      -1,                               0,    BDT_Normal},
   {"ElecOtakara",        EnemyTypeID::EnemyID_ElecOtakara,    -1,                                1,      0x0007,    "FireOtakara",  "FireOtakara",  "Otakara",      "",         "",         "Otakara",      "Otakara",      -1,                               0,    BDT_Normal},
   {"Jigumo",             EnemyTypeID::EnemyID_Jigumo,         -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_PanHouse,    1,    BDT_Strong},
   {"TamagoMushi",        EnemyTypeID::EnemyID_TamagoMushi,    -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Weak},
   {"UmiMushiBase",       EnemyTypeID::EnemyID_UmiMushiBase,   -1,                                1,      0x0001,    "UmiMushi",     "UmiMushi",     "UmiMushi",     "UmiMushi", "UmiMushi", "UmiMushi",     "UmiMushi",     -1,                               0,    BDT_Boss},
   {"UmiMushi",           EnemyTypeID::EnemyID_UmiMushi,       EnemyTypeID::EnemyID_UmiMushiBase, 1,      0x0006,    "UmiMushi",     "UmiMushi",     "UmiMushi",     "UmiMushi", "UmiMushi", "UmiMushi",     "UmiMushi",     -1,                               0,    BDT_Boss},
   {"UmiMushiBlind",      EnemyTypeID::EnemyID_UmiMushiBlind,  EnemyTypeID::EnemyID_UmiMushiBase, 1,      0x0006,    "UmiMushi",     "UmiMushi",     "UmiMushi",     "UmiMushi", "UmiMushi", "UmiMushi",     "UmiMushi",     -1,                               0,    BDT_Strong},
   {"BigTreasure",        EnemyTypeID::EnemyID_BigTreasure,    -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_FinalBoss},
   {"ShijimiChou",        EnemyTypeID::EnemyID_ShijimiChou,    -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"MiniHoudai",         EnemyTypeID::EnemyID_MiniHoudai,     -1,                                1,      0x0097,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Normal},
   {"FminiHoudai",        EnemyTypeID::EnemyID_FminiHoudai,    -1,                                1,      0x0097,    "MiniHoudai",   "MiniHoudai",   "MiniHoudai",   "",         "",         "MiniHoudai",   "MiniHoudai",   -1,                               0,    BDT_Normal},
   {"Sokkuri",            EnemyTypeID::EnemyID_Sokkuri,        -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Weak},
   {"BombOtakara",        EnemyTypeID::EnemyID_BombOtakara,    -1,                                1,      0x0007,    "FireOtakara",  "FireOtakara",  "Otakara",      "",         "",         "Otakara",      "Otakara",      EnemyTypeID::EnemyID_Bomb,        1,    BDT_Normal},
   {"BlackMan",           EnemyTypeID::EnemyID_BlackMan,       -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             EnemyTypeID::EnemyID_Tyre,        1,    BDT_Boss},
   {"Tyre",               EnemyTypeID::EnemyID_Tyre,           -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Empty},
   {"DangoMushi",         EnemyTypeID::EnemyID_DangoMushi,     -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Boss},
   {"Gtank",              EnemyTypeID::EnemyID_Gtank,          -1,                                1,      0x0097,    "Tank",         "Tank",         "Tank",         "",         "",         "Tank",         "Tank",         -1,                               0,    BDT_Strong},
   {"Mtank",              EnemyTypeID::EnemyID_Mtank,          -1,                                1,      0x0097,    "Tank",         "Tank",         "Tank",         "",         "",         "Tank",         "Tank",         -1,                               0,    BDT_Strong},
   {"SporeOtakara",       EnemyTypeID::EnemyID_SporeOtakara,   -1,                                1,      0x0007,    "FireOtakara",  "FireOtakara",  "Otakara",      "",         "",         "Otakara",      "Otakara",      -1,                               0,    BDT_Normal},
   {"TechnoHoudai",       EnemyTypeID::EnemyID_TechnoHoudai,   -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Boss},
   {"TechnoBug",          EnemyTypeID::EnemyID_TechnoBug,      -1,                                1,      0x0007,    "",             "",             "",             "",         "",         "",             "",             -1,                               0,    BDT_Normal},
   {"WaterHiba",          EnemyTypeID::EnemyID_WaterHiba,      -1,                                1,      0x0207,    "Hiba",         "Hiba",         "Hiba",         "Hiba",     "Hiba",     "Hiba",         "Hiba",         -1,                               0,    BDT_Empty},
   {"GasLineHiba",        EnemyTypeID::EnemyID_GasLineHiba,    -1,                                1,      0x0207,    "Hiba",         "Hiba",         "Hiba",         "Hiba",     "Hiba",     "Hiba",         "Hiba",         -1,                               0,    BDT_Empty},
   {"SporeHiba",          EnemyTypeID::EnemyID_SporeHiba,      -1,                                1,      0x0207,    "Hiba",         "Hiba",         "Hiba",         "Hiba",     "Hiba",     "Hiba",         "Hiba",         -1,                               0,    BDT_Empty},
   {"GreenBomb",          EnemyTypeID::EnemyID_GreenBomb,      -1,                                1,      0x0207,    "",             "Bomb",         "Bomb",         "",         "Bomb",     "Bomb",         "Bomb",         -1,                               0,    BDT_Empty},
};
// clang-format on

int gEnemyInfoNum = ARRAY_SIZE(gEnemyInfo);

int gMaxEnemyID = EnemyTypeID::EnemyID_COUNT;

namespace EnemyInfoFunc {
/**
 * Common loop used by at least getEnemyName.
 */
inline EnemyInfo* getInfo(int enemyID, int enemyFlags)
{
	EnemyInfo* result = nullptr;
	for (int enemy_num = gEnemyInfoNum, slot = 0; enemy_num > 0; --enemy_num) {
		if ((enemyID == gEnemyInfo[slot].mId) && ((enemyFlags & (u32)gEnemyInfo[slot].mFlags) != 0)) {
			result = &gEnemyInfo[slot];
			break;
		}
		++slot;
	}
	return result;
}

EnemyInfo* getEnemyInfo(int enemyID, int enemyFlags)
{
	EnemyInfo* result = nullptr;
	int slot          = 0;
	int enemy_num     = gEnemyInfoNum;

	while (enemy_num > 0) {
		if ((enemyID == gEnemyInfo[slot].mId) && ((enemyFlags & (u32)gEnemyInfo[slot].mFlags) != 0)) {
			result = gEnemyInfo + slot;
			break;
		}
		--enemy_num;
		++slot;
	}
	return result;
}

char* getEnemyName(int enemyID, int enemyFlags)
{
	EnemyInfo* result = getInfo(enemyID, enemyFlags);
	return result ? result->mName : nullptr;
}

char* getEnemyResName(int enemyID, int enemyFlags)
{
	switch (enemyID) {
	case EnemyTypeID::EnemyID_FireOtakara:
	case EnemyTypeID::EnemyID_WaterOtakara:
	case EnemyTypeID::EnemyID_GasOtakara:
	case EnemyTypeID::EnemyID_ElecOtakara:
	case EnemyTypeID::EnemyID_SporeOtakara:
		return "Otakara";
		break;
	}

	if (enemyID == EnemyTypeID::EnemyID_INVALID || enemyID == EnemyTypeID::EnemyID_INVALID2) {
		enemyID = EnemyTypeID::EnemyID_PanHouse;
	}

	EnemyInfo* result = getInfo(enemyID, enemyFlags);
	return result->mAnimName == "" ? result->mName : result->mAnimName;
}

char getEnemyMember(int enemyID, int enemyFlags)
{
	EnemyInfo* result = getInfo(enemyID, enemyFlags);
	return result ? result->mMembers : '\0';
}

int getEnemyID(char* name, int enemyFlags)
{
	EnemyInfo* result = nullptr;
	for (int slot = 0; slot < gEnemyInfoNum; ++slot) {
		if ((stricmp(gEnemyInfo[slot].mName, name) == 0) && ((enemyFlags & (u32)gEnemyInfo[slot].mFlags) != 0)) {
			result = &gEnemyInfo[slot];
			break;
		}
	}
	return result->mId;
}
} // namespace EnemyInfoFunc
} // namespace Game
