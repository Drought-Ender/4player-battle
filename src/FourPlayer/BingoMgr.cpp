#include "Game/BingoMgr.h"
#include "Game/pelletMgr.h"
#include "Game/pelletConfig.h"
#include "Dolphin/rand.h"
#include "Game/VsGame.h"
#include "JSystem/JKernel/JKRDvdRipper.h"

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
    int lastChar = strlen(section->mEditFilename);

	char properCaveName[32];
	int editID = section->mEditNumber;

	strncpy(properCaveName, section->mEditFilename, lastChar - 4);
	properCaveName[lastChar - 4] = nullptr;

    char filepath[64];
	
	sprintf(filepath, "/user/drought/bingo/%s/%i.txt", properCaveName, GetEditNum());

    DebugReport("before archives\n");


    yamashitaArchive = JKRArchive::mount("user/Yamashita/enemytex/arc.szs", JKRArchive::EMM_Mem, nullptr, JKRArchive::EMD_Head);
    matobaArchive    = JKRArchive::mount("user/Matoba/resulttex/us/arc.szs", JKRArchive::EMM_Mem, nullptr, JKRArchive::EMD_Head);

    DebugReport("before load\n");

    loadAndRead(this, filepath);

    DebugReport("Done reading\n");
    if (yamashitaArchive) {
        yamashitaArchive->unmount();
    }
    if (matobaArchive) {
        matobaArchive->unmount();
    }
    DebugReport("All is well\n");
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
    mCards[team].ReceivePellet(mKey, pellet);
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

void BingoMgr::BingoCard::ReceivePellet(ObjectKey& key, Pellet* pellet) {
    u8 kind = pellet->getKind();
    s16 id = pellet->mConfig->mParams.mIndex;

    int configIdx = key.FindPellet(kind, id);

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
}

} // namespace VsGame


} // namespace Game
