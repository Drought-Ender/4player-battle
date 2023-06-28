#include "Game/VsGameSection.h"
#include "Dolphin/rand.h"

namespace Game
{
void VsGameSection::updateCardGeneration()
{
	int maxSpawnCherries[4] = { 0, 0, 0, 0 };
	f32 spawnFactor[4];
	for (int i = 0; i < 4; i++) {
		spawnFactor[i] = mRedBlueScore[i] - mYellowScore[i];
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			spawnFactor[i] -= (mRedBlueScore[j] - mYellowScore[j]) / 3;
		}
	}
	f32 lowFactor[4];
	for (int i = 0; i < 4; i++) {
		lowFactor[i] = mCherryScore[i];
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			lowFactor[i] -= mCherryScore[j] / 3;
		}
	}
	f32 factors[4][2] = { {0.4f, 0.6f}, {0.4f, 0.6f}, {0.4f, 0.6f}, {0.4f, 0.6f} };
	bool isUrgent[4] = { false, false, false, false };
	for (int i = 0; i < 4; i++) {
		if (FABS(spawnFactor[i]) < 0.2f) {

		} else if (0.2f <= FABS(spawnFactor[i]) < 0.4f) {
			isUrgent[i]      = true;
			factors[i][0]          = 0.3f;
			factors[i][1]          = 0.5f;
		} else if (0.4f <= FABS(spawnFactor[i]) < 0.8f) {
			maxSpawnCherries[i] = 1;
			isUrgent[i]           = true;
			factors[i][0]          = 0.2f;
			factors[i][1]          = 0.4f;
		} else if (0.8f <= FABS(spawnFactor[i])) {
			maxSpawnCherries[i] = 2;
			isUrgent[i]           = true;
			factors[i][0]          = 0.2f;
			factors[i][1]          = 0.4f;
		}


		if (!isUrgent[i]) {
			f32 absLowFactor = FABS(lowFactor[i] * 0.5f);
			if (absLowFactor <= 0.1f) {

			} else {
				if (absLowFactor < 0.2f) {
					factors[i][0] = 0.4f;
					factors[i][1] = 0.55f;
				} else if (absLowFactor < 0.5f) {
					factors[i][0] = 0.4f;
					factors[i][1] = 0.5f;
				} else if (absLowFactor < 1.0f) {
					factors[i][0] = 0.3f;
					factors[i][1] = 0.5f;
					if (absLowFactor > 0.9f) {
						maxSpawnCherries[i] = 0;
					}
				}
			}
		}
	}

	mCardCount = 0;
	for (int i = 0; i < mMaxCherries; i++) {
		if (mCherryArray[i]->isAlive()) {
			mCardCount++;
		}
	}

	const f32 cardTimerConst[] = {0.5f,  3.0f, 6.0f, 10.0f, 14.0f, 20.0f, 0};
	const f32 cardTimerRand[]  = {0.75f, 1.0f, 2.0f, 3.0f,  4.0f,  6.0f,  0};

	bool hasUrgency = isUrgent[0] || isUrgent[1] || isUrgent[2] || isUrgent[3];
	int spawnCherries = maxSpawnCherries[0] + maxSpawnCherries[1] + maxSpawnCherries[2] + maxSpawnCherries[3] + 5;
	if (spawnCherries > 10) spawnCherries = 10;

	if (mCardCount < 4 || (hasUrgency && mCardCount < spawnCherries) && gConfig[CHERRY_RATE] != ConfigEnums::RATE_NEVER) { // config is never spawn
		f32 ticking = sys->mDeltaTime;
		if (hasUrgency) {
			ticking *= 2.0f;
		}
		mSpawnTimer -= ticking;
		if (mSpawnTimer <= 0.0f) {
			mSpawnTimer = cardTimerRand[gConfig[CHERRY_RATE]] * randFloat() + cardTimerConst[gConfig[CHERRY_RATE]];
			DropCardArg arg;
			for (int i = 0; i < 4; i++) {
			
				arg._00[i] = factors[i][0];
				arg._04[i] = factors[i][1];
			}
			dropCard(arg);
		}
	}
}

void VsGameSection::updateCardGeneration()
{
	int maxSpawnCherries[4] = { 0, 0, 0, 0 };
	f32 spawnFactor[4];
	for (int i = 0; i < 4; i++) {
		spawnFactor[i] = mRedBlueScore[i] - mYellowScore[i];
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			spawnFactor[i] -= (mRedBlueScore[j] - mYellowScore[j]) / 3;
		}
	}
	f32 lowFactor[4];
	for (int i = 0; i < 4; i++) {
		lowFactor[i] = mCherryScore[i];
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			lowFactor[i] -= mCherryScore[j] / 3;
		}
	}
	f32 factors[4][2] = { {0.4f, 0.6f}, {0.4f, 0.6f}, {0.4f, 0.6f}, {0.4f, 0.6f} };
	bool isUrgent[4] = { false, false, false, false };
	for (int i = 0; i < 4; i++) {
		if (FABS(spawnFactor[i]) < 0.2f) {

		} else if (0.2f <= FABS(spawnFactor[i]) < 0.4f) {
			isUrgent[i]      = true;
			factors[i][0]          = 0.3f;
			factors[i][1]          = 0.5f;
		} else if (0.4f <= FABS(spawnFactor[i]) < 0.8f) {
			maxSpawnCherries[i] = 1;
			isUrgent[i]           = true;
			factors[i][0]          = 0.2f;
			factors[i][1]          = 0.4f;
		} else if (0.8f <= FABS(spawnFactor[i])) {
			maxSpawnCherries[i] = 2;
			isUrgent[i]           = true;
			factors[i][0]          = 0.2f;
			factors[i][1]          = 0.4f;
		}


		if (!isUrgent[i]) {
			f32 absLowFactor = FABS(lowFactor[i] * 0.5f);
			if (absLowFactor <= 0.1f) {

			} else {
				if (absLowFactor < 0.2f) {
					factors[i][0] = 0.4f;
					factors[i][1] = 0.55f;
				} else if (absLowFactor < 0.5f) {
					factors[i][0] = 0.4f;
					factors[i][1] = 0.5f;
				} else if (absLowFactor < 1.0f) {
					factors[i][0] = 0.3f;
					factors[i][1] = 0.5f;
					if (absLowFactor > 0.9f) {
						maxSpawnCherries[i] = 0;
					}
				}
			}
		}
	}

	mCardCount = 0;
	for (int i = 0; i < mMaxCherries; i++) {
		if (mCherryArray[i]->isAlive()) {
			mCardCount++;
		}
	}

	const f32 cardTimerConst[] = {0.5f,  3.0f, 6.0f, 10.0f, 14.0f, 20.0f, 0};
	const f32 cardTimerRand[]  = {0.75f, 1.0f, 2.0f, 3.0f,  4.0f,  6.0f,  0};

	bool hasUrgency = isUrgent[0] || isUrgent[1] || isUrgent[2] || isUrgent[3];
	int spawnCherries = maxSpawnCherries[0] + maxSpawnCherries[1] + maxSpawnCherries[2] + maxSpawnCherries[3] + 5;
	if (spawnCherries > 10) spawnCherries = 10;

	if (mCardCount < 4 || (hasUrgency && mCardCount < spawnCherries) && gConfig[CHERRY_RATE] != ConfigEnums::RATE_NEVER) { // config is never spawn
		f32 ticking = sys->mDeltaTime;
		if (hasUrgency) {
			ticking *= 2.0f;
		}
		mSpawnTimer -= ticking;
		if (mSpawnTimer <= 0.0f) {
			mSpawnTimer = cardTimerRand[gConfig[CHERRY_RATE]] * randFloat() + cardTimerConst[gConfig[CHERRY_RATE]];
			DropCardArg arg;
			for (int i = 0; i < 4; i++) {
			
				arg._00[i] = factors[i][0];
				arg._04[i] = factors[i][1];
			}
			dropCard(arg);
		}
	}
}


} // namespace Game
