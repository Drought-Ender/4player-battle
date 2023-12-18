#include "Game/BingoMgr.h"
#include "Game/pelletMgr.h"
#include "Game/pelletConfig.h"
#include "Dolphin/rand.h"
#include "Game/VsGame.h"
#include "Game/generalEnemyMgr.h"
#include "JSystem/JKernel/JKRDvdRipper.h"
#include "utilityU.h"

namespace Game
{

namespace VsGame
{

BingoMgr::BingoMgr() {
    mCards = new BingoCard[4];
}

BingoMgr::~BingoMgr() {
    delete[] mCards;
}

JKRArchive* yamashitaArchive = nullptr;
JKRArchive* matobaArchive = nullptr;

void BingoMgr::init(VsGameSection* section) {
    mWinner = -1;
    mBedamaSound[0] = false;
    mBedamaSound[1] = false;

    int lastChar = strlen(section->mEditFilename);

	char properCaveName[32];
	int editID = section->mEditNumber;

	strncpy(properCaveName, section->mEditFilename, lastChar - 4);
	properCaveName[lastChar - 4] = nullptr;

    char filepath[64];
	
	sprintf(filepath, "/user/drought/bingocard/%s/%i.txt", properCaveName, GetEditNum());

    DebugReport("before archives\n");


    yamashitaArchive = JKRArchive::mount("user/Yamashita/enemytex/arc.szs", JKRArchive::EMM_Mem, nullptr, JKRArchive::EMD_Head);
    matobaArchive    = JKRArchive::mount("user/Matoba/resulttex/us/arc.szs", JKRArchive::EMM_Mem, nullptr, JKRArchive::EMD_Head);

    DebugReport("before load\n");

    bool success = loadAndRead(this, filepath);
    if (!success) {
        JUT_PANIC("%s missing!\n", filepath);
    }

    DebugReport("Done reading\n");
    if (yamashitaArchive) {
        yamashitaArchive->unmount();
    }
    if (matobaArchive) {
        matobaArchive->unmount();
    }
    DebugReport("All is well\n");
}

bool BingoMgr::BingoCard::CheckLine(const int min, bool disp) {
    
    int rowMajorCount[4] = { 0, 0, 0, 0 };
    int colMajorCount[4] = { 0, 0, 0, 0 };
    int XequYCornerCount = 0;
    int XnotYCornerCount = 0;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {

            if ((disp) ? mDisp[row][col] : mActive[row][col]) {
                rowMajorCount[row]++;
                colMajorCount[col]++;
                if (row == col) {
                    XequYCornerCount++;
                }
                if (row == 3 - col) {
                    XnotYCornerCount++;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (rowMajorCount[i] >= min || colMajorCount[i] >= min) {
            return true;
        }
    }

    if (XequYCornerCount >= min || XnotYCornerCount >= min) {
        return true;
    }
    
    return false;
}

bool BingoMgr::BingoCard::CheckLine(const int min, LineData& line, bool disp) {    
    int rowMajorCount[4] = { 0, 0, 0, 0 };
    int colMajorCount[4] = { 0, 0, 0, 0 };
    int XequYCornerCount = 0;
    int XnotYCornerCount = 0;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {

            if ((disp) ? mDisp[row][col] : mActive[row][col]) {
                rowMajorCount[row]++;
                colMajorCount[col]++;
                if (row == col) {
                    XequYCornerCount++;
                }
                if (row == 3 - col) {
                    XnotYCornerCount++;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (rowMajorCount[i] >= min) {
            for (int row = 0; row < 4; row++) {
                line.mXValues[row] = i;
                line.mYValues[row] = row;
            }
            return true;
        }
        if (colMajorCount[i] >= min) {
            for (int col = 0; col < 4; col++) {
                line.mXValues[col] = col;
                line.mYValues[col] = i;
            }
            return true;
        }
    }

    if (XequYCornerCount >= min) {
        for (int i = 0; i < 4; i++) {
            line.mXValues[i] = i;
            line.mYValues[i] = i;
        }
        return true;
    }

    if (XnotYCornerCount >= min) {
        for (int i = 0; i < 4; i++) {
            line.mXValues[i] = 3 - i;
            line.mYValues[i] = i;
        }
        return true;
    }
    
    return false;
}

int BingoMgr::BingoCard::CheckLine(const int min, LineData* lines, int arraySize, bool disp) {
    int lineCount = 0;
    
    int rowMajorCount[4] = { 0, 0, 0, 0 };
    int colMajorCount[4] = { 0, 0, 0, 0 };
    int XequYCornerCount = 0;
    int XnotYCornerCount = 0;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {

            if ((disp) ? mDisp[row][col] : mActive[row][col]) {
                rowMajorCount[row]++;
                colMajorCount[col]++;
                if (row == col) {
                    XequYCornerCount++;
                }
                if (row == 3 - col) {
                    XnotYCornerCount++;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (rowMajorCount[i] >= min) {
            for (int row = 0; row < 4; row++) {
                lines[lineCount].mXValues[row] = i;
                lines[lineCount].mYValues[row] = row;
            }
            lineCount++;
            if (arraySize == lineCount) return lineCount;
        }
        if (colMajorCount[i] >= min) {
            for (int col = 0; col < 4; col++) {
                lines[lineCount].mXValues[col] = col;
                lines[lineCount].mYValues[col] = i;
            }
            lineCount++;
            if (arraySize == lineCount) return lineCount;
        }
    }

    if (XequYCornerCount >= min) {
        for (int i = 0; i < 4; i++) {
            lines[lineCount].mXValues[i] = i;
            lines[lineCount].mYValues[i] = i;
        }
        lineCount++;
        if (arraySize == lineCount) return lineCount;
    }

    if (XnotYCornerCount >= min) {
        for (int i = 0; i < 4; i++) {
            lines[lineCount].mXValues[i] = 3 - i;
            lines[lineCount].mYValues[i] = i;
        }
        lineCount++;
        if (arraySize == lineCount) return lineCount;
    }
    
    return lineCount;
}

void BingoMgr::read(Stream& stream) {
    mKey.read(stream);
}

void BingoMgr::ObjectKey::read(Stream& stream) {
    DebugReport("Test\n");
    mObjectNum = stream.readInt();
    DebugReport("Object Num %i\n", mObjectNum);
    mObjectEntries = new Object[mObjectNum];
    for (int i = 0; i < mObjectNum; i++) {
        mObjectEntries[i].read(stream);
    }
}

void BingoMgr::ObjectKey::Object::read(Stream& stream) {
    DebugReport("again?\n");
    char nameBuffer[64];

    char* objectName = stream.readString(nameBuffer, 64);
    DebugReport("Objname %s\n", objectName);

    mExistCount = stream.readByte();

    PelletInitArg initArg;
    PelletList::cKind cKind;

    PelletConfig* pelletConfig = PelletList::Mgr::getConfigAndKind(objectName, cKind);

    if (!pelletConfig) {
        JUT_ASSERT("no such pellet %s\n", objectName);
    }

    mPelType = cKind;
    mPelletID = pelletConfig->mParams.mIndex;
    
    DebugReport("Exist count %i\n", mExistCount);


    if (cKind == PelletList::CARCASS) {
        char buffer[64];
        sprintf(buffer, "%s/texture.bti", objectName);
        mObjectTexture = (ResTIMG*)yamashitaArchive->getResource(buffer);
        DebugReport("Made texture!\n");
    }
    else {
        char buffer[64];
        sprintf(buffer, "%s/texture.bti", objectName);
        mObjectTexture = (ResTIMG*)matobaArchive->getResource(buffer);
    }
}

void BingoMgr::BingoCard::Generate(ObjectKey& key) {
    ObjectKey ourCopy = key;

    int totalEntries = 0;


    for (int i = 0; i < ourCopy.mObjectNum; i++) {
        totalEntries += ourCopy.mObjectEntries[i].mExistCount;
    }

    int* entryArray = new int[totalEntries];

    int count = 0;
    for (int i = 0; i < ourCopy.mObjectNum; i++) {
        for (int j = 0; j < ourCopy.mObjectEntries[i].mExistCount; j++) {
            entryArray[count] = i;
            count++;
        }
    }

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {

            int randIdx = (int)(totalEntries * randFloat());
            

            mObjects[x][y] = entryArray[randIdx];
            mActive[x][y]  = false;
            mDisp[x][y] = false;

            totalEntries--;

            for (int i = randIdx; i < totalEntries; i++) {
                entryArray[i] = entryArray[i + 1];
            }

        }
    }

    delete[] entryArray;

}

void BingoMgr::GenerateCards() {
    for (int i = 0; i < 4; i++) {
        mCards[i].Generate(mKey);
    }
}

void BingoMgr::TeamReceivePellet(int team, Pellet* pellet) {
    int idx = mCards[team].ReceiveDispPellet(mKey, pellet);
    if (idx == -1) {
        mCards[team].ReceivePellet(mKey, pellet);
        mCards[team].ReceiveDispPellet(mKey, pellet);
        
        
    }

    bool isOlimar = !isTeamLouie(team);

    if (mWinner != -1) {
        PSSetLastBeedamaDirection(isOlimar, false);
    }
    else if (!mBedamaSound[isOlimar] && mCards[team].CheckLine(3, true)) {
        DebugReport("BEDAMA!\n");
        mBedamaSound[isOlimar] = true;
        PSSetLastBeedamaDirection(isOlimar, true);
    }
}

int BingoMgr::ObjectKey::FindPellet(Pellet* pellet) {
    return FindPellet(pellet->getKind(), pellet->mConfig->mParams.mIndex);
}

int BingoMgr::ObjectKey::FindPellet(u8 kind, s16 id) {
    for (int i = 0; i < mObjectNum; i++) {
        Object& obj = mObjectEntries[i];
        if (obj.mPelType == kind && obj.mPelletID == id) {
            return i;
        }
    }
    return -1;
}

int BingoMgr::ObjectKey::FindEnemy(int enemyID) {
    const char* enemyName = EnemyInfoFunc::getEnemyName(enemyID, 0xffff);;
    for (int i = 0; i < mObjectNum; i++) {
        Object& obj = mObjectEntries[i];
        if (obj.mPelType != PelletList::CARCASS) {
            continue;
        }

        const char* peltName = PelletList::Mgr::getConfigList(PelletList::CARCASS)->getPelletConfig(obj.mPelletID)->mParams.mName.mData;

        if (!strcmp(enemyName, peltName)) {
            return i;
        }
    }
    return -1;
}

int BingoMgr::ObjectKey::FindEnemy(EnemyBase* enemy) {
    return FindEnemy(enemy->getEnemyTypeID());
}

/// @brief Updates bingo card for recieving a pellet
/// @param key ObjectKey from the bingoMgr
/// @param pellet The Pellet Recieved
/// @return The changed id from 0 to 15
int BingoMgr::BingoCard::ReceivePellet(ObjectKey& key, Pellet* pellet) {

    int configIdx = key.FindPellet(pellet);

    if (configIdx == -1) return;

    int matchingIDs[16];
    int count = 0;
    for (int i = 0; i < 4 * 4; i++) {
        if (reinterpret_cast<u8*>(mObjects)[i] == configIdx && !reinterpret_cast<bool*>(mActive)[i]) {
            matchingIDs[count++] = i;
        }
    }

    if (count == 0) return;

    int selectedID = matchingIDs[(int)(count * randFloat())];

    DebugReport("Updating %i %i!\n", selectedID / 4, selectedID % 4);

    reinterpret_cast<bool*>(mActive)[selectedID] = true;

    return selectedID;
}

int BingoMgr::BingoCard::ReceiveDispPellet(ObjectKey& key, Pellet* pellet) {

    int configIdx = key.FindPellet(pellet);

    for (int i = 0; i < 4 * 4; i++) {
        if (reinterpret_cast<u8*>(mObjects)[i] == configIdx && reinterpret_cast<bool*>(mActive)[i] && !reinterpret_cast<bool*>(mDisp)[i]) {
            reinterpret_cast<bool*>(mDisp)[i] = true;
            return i;
        }
    }
    DebugReport("Bingo disp not found, This is a little concerning\n");
    return -1;
}

bool BingoMgr::BingoCard::PelletSuckProcedure(ObjectKey& key, Pellet* pellet) {
    int changedID = ReceivePellet(key, pellet);
    DebugReport("Changed id %i\n", changedID);
    bool success = CheckLine(4);

    return success;
}

void BingoMgr::CountExists() {
    mKey.CountExists();
}

void BingoMgr::ObjectKey::CountExists() {
    for (int i = 0; i < mObjectNum; i++) {
        mObjectEntries[i].mExistCount = 0;
    }

    PelletIterator iPellet;
    CI_LOOP(iPellet) {
        Pellet* pellet = *iPellet;

        int idx = FindPellet(pellet);
        if (idx != -1) {
            mObjectEntries[idx].mExistCount++;
        }
    }

    FOREACH_NODE(EnemyMgrNode, generalEnemyMgr->mEnemyMgrNode.mChild, enemyNode) {

        int idx = FindEnemy(enemyNode->mEnemyID);

        if (idx != -1) {
            mObjectEntries[idx].mExistCount = enemyNode->mMgr->mNumObjects;
        }

    }

    for (int idx = 0; idx < mObjectNum; idx++) {
        const char* peltName = PelletList::Mgr::getConfigList((PelletList::cKind)mObjectEntries[idx].mPelType)->getPelletConfig(mObjectEntries[idx].mPelletID)->mParams.mName.mData;
        DebugReport("Found %i of %s\n", mObjectEntries[idx].mExistCount, peltName);
    }

    
    
}

void BingoMgr::ObjectKey::Object::CountExists() {
    mExistCount = 0;

    PelletIterator iPellet;
    CI_LOOP(iPellet) {
        Pellet* pellet = *iPellet;

        u8 kind = pellet->getKind();
        s16 id = pellet->mConfig->mParams.mIndex;

        if (mPelType == kind && mPelletID == id) {
            mExistCount++;
        }
    }

    

    const char* peltName = PelletList::Mgr::getConfigList((PelletList::cKind)mPelType)->getPelletConfig(mPelletID)->mParams.mName.mData;
    DebugReport("Found %i of %s\n", mExistCount, peltName);

}

void BingoMgr::informDeath(Pellet* pelt) {
    mKey.informDeath(pelt);
}

void BingoMgr::informDeath(EnemyBase* enemy) {
    mKey.informDeath(enemy);
}

void BingoMgr::ObjectKey::informDeath(Pellet* pelt) {
    int idx = FindPellet(pelt);
    mObjectEntries[idx].mExistCount--;
}

void BingoMgr::ObjectKey::informDeath(EnemyBase* enemy) {
    int idx = FindEnemy(enemy);
    mObjectEntries[idx].mExistCount--;
}

bool BingoMgr::BingoCard::isImpossible(ObjectKey& key, int x, int y) {
    u8 idx = mObjects[x][y];
    return !mActive[x][y] && key.mObjectEntries[idx].mExistCount <= 0;
}

} // namespace VsGame


} // namespace Game
