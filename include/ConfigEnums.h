
bool canAutopluck();

namespace ConfigEnums
{

enum EPlayerName {
    NAME_OFF,
    NAME_ON
};

enum EPlaceMarbleConfig {
    PLACE_VANILLA,
    PLACE_BURY,
    PLACE_NOTHING
};

enum ECarryMarbleConfig {
    CARRY_OFF,
    CARRY_ON
};

enum ECherryRateConfig {
    RATE_FRENZY,
    RATE_FREQUENT,
    RATE_OFTEN,
    RATE_NORMAL,
    RATE_OCCASION,
    RATE_RARE,
    RATE_NEVER
};

enum ESpicyType {
    SPICY_NORMAL,
    SPICY_NERF,
    SPICY_FLOWER
};

enum EBitterType {
    BITTER_BURY,
    BITTER_DEPSPICY,
    BITTER_KILL,
    BITTER_ZAP,
    BITTER_ELEMENT,
    BITTER_DEFLOWER
};

enum ESpawnShearwig {
    SHEARWIG_SPAWN,
    SHEARWIG_DONTSPAWN,
    SHEARWIG_COLORSPAWN
};

enum EEggDrops {
    EGG_ALL,
    EGG_NOSPRAY,
    EGG_NOMITE,
    EGG_NECTAR,
    EGG_SINGLE
};

enum EAutopluck {
    AUTOPLUCK_ON,
    AUTOPLUCK_CANCEL,
    AUTOPLUCK_OFF
};

enum EMarbleReturn {
    RETURN_NORMAL,
    RETURN_BURY,
    RETURN_REMOVED
};

enum EVsY {
    VSY_OFF,
    VSY_ON
};

enum EVsHiba {
    VSHIBA_OFF,
    VSHIBA_ON,
    VSHIBA_OLD
};

enum EPikiRevive {
    REVIVE_ON,
    REVIVE_OFF
};

enum ESprayCard {
    SPRAYCARD_NORMAL,
    SPRAYCARD_USE,
    SPRAYCARD_OFF
};

enum EPelletMatching {
    PELMATCH_OFF,
    PELMATCH_ON
};

enum EDandoriBirthing {
    BIRTH_SPROUTS,
    BIRTH_PIKMIN
};

enum EFriendBitter {
    FRIENDBITTER_OFF,
    FRIENDBITTER_ON
};

enum EFriendlyFire {
    FRIENDCHERRY_OFF,
    FRIENDCHERRY_ON
};

enum ECaptureMarble {
    CAPTURE_VICTORY,
    CAPTURE_ELIMINATE,
    CAPTURE_STEALMARBLE,
    CAPTURE_STEALSPRAY,
    CAPTURE_KILLPIKI
};

enum EFlareGaurd {
    GAURD_OFF,
    GAURD_ON
};

enum EHazardTimer {
    HAZARD_OFF,
    HAZARD_ON
};

enum EStalemateTimer {
    STALEMATE_OFF,
    STALEMATE_ON
};

enum EBitterPassive {
    BITTERPASSIVE_OFF = 0,
    BITTERPASSIVE_INF = 5
};

enum ESpicyPassive {
    SPICYPASSIVE_OFF = 0,
    SPICYPASSIVE_INF = 5
};

enum EReservoir {
    RESERVOIR_OFF = 0,
    RESERVOIR_ON
};

enum EBombCarry {
    BOMBCARRY_OFF,
    BOMBCARRY_BOMBS,
    BOMBCARRY_EGGS,
    BOMBCARRY_BOTH
};

enum EBlowhogCarry {
    BLOWHOGCARRY_OFF,
    BLOWHOGCARRY_ON
};

enum EMiscCarry {
    MISCCARRY_OFF,
    MISCCARRY_CHERRY,
    MISCCARRY_LIGHT,
    MISCCARRY_ALL
};

enum ECaptainCorpse {
    CORPSE_OFF,
    COPRSE_ON
};

enum ECherryPassive {
    CHERRYPASSIVE_OFF = 0,
    CHERRYPASSIVE_INF = 5
};

enum EAutobalance {
    AUTOBALANCE_OFF    = 0,
    AUTOBALANCE_WEAK   = 1,
    AUTOBALANCE_STRONG = 2
};

} // namespace ConfigEnums
