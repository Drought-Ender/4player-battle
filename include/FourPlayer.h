#ifndef _FOURPLAYER_H_
#define _FOURPLAYER_H_

#include "Game/CameraMgr.h"
#include "JSystem/J2D/J2DPrint.h"
#include "ConfigEnums.h"
#include "types.h"
#include "P2JME/P2JME.h"
#include "Dolphin/rand.h"

enum ScoreDelegations { FIRST_SCORE, SECOND_SCORE };
enum ScoreDelegationSeconds { FIRST_ONYON_DELEGATE, SECOND_ONYON_DELEGATE };

// struct DelegationIndex {
// 	ScoreDelegations mScoreDelegation;
// 	ScoreDelegationSeconds mScoreOnyonDelegation;
// };

int FindScoreDelegation(int onyonType);

typedef f32 VsWeights[2]; // delegations

extern int gScoreDelegations[2][2];
extern int gEffectiveTeamCount;
extern bool gThreePlayer;

struct Controller;

#define FOURPLAYER_DEBUG 0

extern int mRealWinCounts[4];
extern bool gDrawVsMenu;
extern bool gDrawNavi[4];

extern bool gDrawNames;

static const JUtility::TColor vsTeamColors[] = { 0xff5050ff, 0x5050ffff, 0xffffffff, 0x7800ffff };

inline void DebugReport(const char* msg, ...)
{
// #if FOURPLAYER_DEBUG == 1
	va_list marker;

	va_start(marker, msg);
	vprintf(msg, marker);
	va_end(marker);
// #endif
}

JUTFont* getPikminFont() { return gP2JMEMgr->mFont; }

struct VsOptionsMenuMgr;

typedef void OptionFunction(VsOptionsMenuMgr*);

struct Option {
	const char* name;
	const char* valueStrings[10];
	const char* toolTipStrings[10];
	const int valueNum;
	int value; // doubles as default value
	bool hide;

	void print(J2DPrint& printer, J2DPrint& printer2, int idx);

	int getValue() { return value; }

	void incOption()
	{
		value++;
		if (value == valueNum) {
			value = 0;
		}
	}

	void decOption()
	{
		if (value == 0) {
			value = valueNum;
		}
		value--;
	}

	const char* getTooltipString() { return toolTipStrings[value]; }

	static void OpenOptionsFile();
	static void GenerateOptionsFile();

	static void ReadOptions(Stream& stream);
	static void SetDefaults();
	static void WriteOptions(Stream& stream);
};

int GetConfigSize();

extern Option gOptions[];
extern int gConfig[];

enum OptionsEnum {
	WIDESCREEN,
	PLAYER_NAME,
	AUTO_BALENECE,
	MARBLE_BURY,
	MARBLE_CARRY,
	CHERRY_RATE,
	SPICY_TYPE,
	BITTER_TYPE,
	SPAWN_SHEARWIG,
	EGG_DROPS,
	AUTOPLUCK,
	VS_Y,
	VS_HIBA,
	PIKI_DIE,
	PELLET_POSY,
	PIKMIN_BIRTH,
	FRIEND_BITTER,
	FRIENDLY_FIRE,
	CAPTURE_MARBLE,
	FLARE_GAURD,
	HAZARD_TIMER,
	BITTER_PASSIVE,
	SPICY_PASSIVE,
	CHERRY_PASSIVE,
	STALEMATE_TIMER,
	GLOBAL_SPICY,
	RESERVOIR,
	CARRY_BOMB,
	CARRY_BLOWHOG,
	CARRY_MISC,
	CAPTAIN_CORPSE,
	ATTACK_POWER,
	PIKMIN_SPEED,
	CARRY_SPEED
};

namespace ConfigEnums {
bool EggCanSpray() { return gConfig[EGG_DROPS] == EGG_ALL || gConfig[EGG_DROPS] == EGG_NOMITE; }
bool EggCanMites() { return gConfig[EGG_DROPS] == EGG_ALL || gConfig[EGG_DROPS] == EGG_NOSPRAY; }
bool EggCanDoubleNectar() { return gConfig[EGG_DROPS] != EGG_SINGLE; }
// isGlobalSpicy__11ConfigEnumsFv
bool isGlobalSpicy() { return gConfig[GLOBAL_SPICY]; }

void SpicyGlobal(Game::Navi*);
}; // namespace ConfigEnums

extern VsOptionsMenuMgr* gOptionMenu;

namespace Game {

enum TeamID { TEAM_NULL = -1, TEAM_RED = 0, TEAM_BLUE = 1, TEAM_WHITE, TEAM_PURPLE };

#define PIKI_COLOR_BLUE    0
#define PIKI_COLOR_RED     1
#define PIKI_COLOR_YELLOW  2
#define PIKI_COLOR_PURPLE  3
#define PIKI_COLOR_WHITE   4
#define PIKI_COLOR_BULBMIN 5
#define PIKI_COLOR_CARROT  6
#define PIKI_COLOR_NULL    -1

extern int gNaviNum;
extern int gVsNaviIndexArray[4];
extern int gDopeCountArray[4][2];

extern bool gFancyCamera;
extern PlayCamera* gCameraP3;
extern PlayCamera* gCameraP4;
extern Controller* gControllerP3;
extern Controller* gControllerP4;

void incAllGlobalDope(int color)
{
	for (int i = 0; i < 4; i++) {
		gDopeCountArray[i][color]++;
	}
}

int CalcNaviNum();
int getVsTeam(int);
int getVsTeam_s(int);
int getVsPikiColor(int); // Gets the piki color of an index
const char* getPikiColorName(int);
const char* getNaviColorName(int);
void SetVsTeam(int idx, TeamID teamID)
{
	int pikiColor = (int)teamID;
	switch (teamID) {
	case TEAM_RED:
		pikiColor = PIKI_COLOR_RED;
		break;
	case TEAM_BLUE:
		pikiColor = PIKI_COLOR_BLUE;
		break;
	case TEAM_WHITE:
		pikiColor = PIKI_COLOR_WHITE;
		break;
	case TEAM_PURPLE:
		pikiColor = PIKI_COLOR_PURPLE;
		break;
	case TEAM_NULL:
		pikiColor = -1;
		break;
	}
	gVsNaviIndexArray[idx] = pikiColor;
}

/// @brief takes in a piki color and converts it to the corrisponding team
/// @param pikiColor int from 0 to 6 representing a piki color
/// @return the team idx from 0 to 3
int getTeamFromPiki(int pikiColor)
{
	switch (pikiColor) {
	case PIKI_COLOR_RED: // red
		return TEAM_RED;
	case PIKI_COLOR_BLUE: // blue
		return TEAM_BLUE;
	case PIKI_COLOR_WHITE: // white
		return TEAM_WHITE;
	case PIKI_COLOR_PURPLE: // purple
		return TEAM_PURPLE;
	case PIKI_COLOR_NULL:
		return TEAM_NULL;
	}
	JUT_PANIC("GET PIKI %i\n", pikiColor);
}

int getTeamFromPelplant(int pikiColor)
{
	switch (pikiColor) {
	case PIKI_COLOR_RED: // red
		return TEAM_RED;
	case PIKI_COLOR_BLUE: // blue
		return TEAM_BLUE;
	case PIKI_COLOR_WHITE: // white
		return TEAM_WHITE;
	case PIKI_COLOR_PURPLE: // purple
		return TEAM_PURPLE;
	}
	return TEAM_NULL;
}

int getTruePelletColor(int pikiColor)
{
	int teamID;
	switch (pikiColor) {
	case PIKI_COLOR_RED: // red
		teamID = TEAM_RED;
		break;
	case PIKI_COLOR_BLUE: // blue
		teamID = TEAM_BLUE;
		break;
	case PIKI_COLOR_WHITE: // white
		teamID = TEAM_WHITE;
		break;
	case PIKI_COLOR_PURPLE: // purple
		teamID = TEAM_PURPLE;
		break;
	default:
		return pikiColor;
	}
	return reinterpret_cast<int*>(gScoreDelegations)[teamID];
}

void lookupScoreDelegation(int teamColor, int& scoreColor, int& scoreHighLow)
{
	for (scoreColor = 0; scoreColor < 2; scoreColor++) {
		for (scoreHighLow = 0; scoreHighLow < 2; scoreHighLow++) {
			if (teamColor == gScoreDelegations[scoreColor][scoreHighLow]) {
				return;
			}
		}
	}
	scoreColor   = -1;
	scoreHighLow = -1;
}

int getPikiFromTeamEnum(int);

int getTeamCount()
{
	bool active[4] = { false, false, false, false };
	int count      = 0;

	for (int i = 0; i < 4; i++) {
		int teamIdx = getVsTeam(i);
		if (teamIdx != TEAM_NULL && !active[teamIdx]) {
			count++;
			active[teamIdx] = true;
		}
	}

	return count;
}

int getAliveTeamCount()
{
	bool active[4] = { false, false, false, false };
	int count      = 0;

	for (int i = 0; i < gNaviNum; i++) {
		if (gDrawNavi[i]) {
			int teamIdx = getVsTeam(i);
			if (teamIdx != TEAM_NULL && !active[teamIdx]) {
				count++;
				active[teamIdx] = true;
			}
		}
	}

	return count;
}

int getAliveAdversaries(int team)
{
	int count = 0;
	for (int i = 0; i < gNaviNum; i++) {
		if (gDrawNavi[i]) {
			int teamIdx = getVsTeam(i);
			if (teamIdx != TEAM_NULL && teamIdx != team) {
				count++;
			}
		}
	}

	return count;
}

int getTeamMembers(int team)
{
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (getVsTeam(i) == team) {
			count++;
		}
	}
	return count;
}

bool isTeamActive(int idx)
{
	if (idx < 0 || idx >= 4)
		return false;
	if (gEffectiveTeamCount == 4)
		return true;
	for (int i = 0; i < 4; i++) {
		if (getVsTeam(i) == idx) {
			return true;
		}
	}
	return false;
}

bool isTeamAlive(int idx)
{
	if (idx < 0 || idx >= 4)
		return false;
	if (gEffectiveTeamCount == 4)
		return true;
	for (int i = 0; i < 4; i++) {
		if (gDrawNavi[i] && getVsTeam(i) == idx) {
			return true;
		}
	}
	return false;
}

bool doesTeamHavePlayers(int idx)
{
	for (int i = 0; i < Game::gNaviNum; i++) {
		if (getVsTeam(i) == idx) {
			return true;
		}
	}
	return false;
}

int getRandomAliveTeamate(int teamIdx)
{
	int list[4];
	int count = 0;

	for (int i = 0; i < Game::gNaviNum; i++) {
		if (getVsTeam(i) == teamIdx) {
			list[count++] = i;
		}
	}

	return list[randInt(count)];
}

bool isTeamLouie(int teamID);

} // namespace Game

// a sqrt function suited to all domains
f32 oddSqrt(f32 x)
{
	if (x > 0.0f) {
		return sqrtf(x);
	} else {
		x = -x;
		return -sqrtf(x);
	}
}

#endif