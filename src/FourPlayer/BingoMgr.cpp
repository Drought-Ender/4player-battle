#include "Game/BingoMgr.h"
#include "Game/pelletMgr.h"
#include "Game/pelletConfig.h"
#include "Dolphin/rand.h"
#include "Game/VsGame.h"
#include "Game/generalEnemyMgr.h"
#include "JSystem/JKernel/JKRDvdRipper.h"
#include "DroughtLib.h"
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
    char nameBuffer[64];

    char* objectName = stream.readString(nameBuffer, 64);
    DebugReport("Objname %s\n", objectName);

    mExistCount = stream.readByte();
    mWeight = stream.readFloat();

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

    ReweighCard(key);
}

f32 BingoMgr::ObjectKey::GetTotalWeight() {
    f32 total = 0.0f;
    for (int i = 0; i < mObjectNum; i++) {
        total += mObjectEntries[i].mExistCount * mObjectEntries[i].mWeight;
    }
    return total;
}

void BingoMgr::BingoCard::Swap(int idx1, int idx2) {
    u8 temp = reinterpret_cast<u8*>(mObjects)[idx1];
    reinterpret_cast<u8*>(mObjects)[idx1] = reinterpret_cast<u8*>(mObjects)[idx2];
    reinterpret_cast<u8*>(mObjects)[idx2] = temp;
}

void BingoMgr::BingoCard::ReweighCard(ObjectKey& key) {
    /*
        The Plan:

        SWAP THE MINIMUM CARD IN THE STRONGEST SPOT WITH EVERY OTHER CARD
        KEEP THE SWAP THE HAS THE WORST BEST LINE
    */


    DebugReport("~~~~~~~ New Card! ~~~~~~~\n");

    f32 totalWeight = key.GetTotalWeight();

    // A line takes up 1/4th of the total bingo card
    f32 expectedLineWeight = totalWeight / 4;

    LineWeightReport weightReport = ReportWeightVerbose(key);

    DebugReport("Expected Weight %f\n", expectedLineWeight);

    int minLineIndex = DroughtLib::ArrayFunctions::ArrayMin(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));

    f32 strongestLineWeight = weightReport.mWeight[minLineIndex];

    int attempts = 0;

    while (FABS(strongestLineWeight - expectedLineWeight) > strongestLineWeight * 0.1f && attempts < 30)
    {
        attempts++;
        
        f32 allMinWeights[16][16];

        for (int firstSwapIndex = 0; firstSwapIndex < 16; firstSwapIndex++) {
        

            for (int swapIndex = 0; swapIndex < 16; swapIndex++) {

                Swap(firstSwapIndex, swapIndex);

                LineWeightReport testReport = ReportWeight(key);

                int min2 = DroughtLib::ArrayFunctions::ArrayMin(testReport.mWeight, ARRAY_SIZE(testReport.mWeight));

                allMinWeights[firstSwapIndex][swapIndex] = testReport.mWeight[min2];

                Swap(swapIndex, firstSwapIndex);
            }

        }

        Vector2i bestSwap = DroughtLib::ArrayFunctions::MatrixMax<f32, 16, 16>(allMinWeights);

        DebugReport("Min Index %i | Other Index %i\n", bestSwap.x, bestSwap.y);

        if (bestSwap.x == bestSwap.y) {
            DebugReport("The search has proven fruitless\n");
            break;
        }

        Swap(bestSwap.x, bestSwap.y);


        weightReport = ReportWeightVerbose(key);

        minLineIndex = DroughtLib::ArrayFunctions::ArrayMin(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));

        strongestLineWeight = weightReport.mWeight[minLineIndex];
    
    }

}

void BingoMgr::BingoCard::ReweighCardByObjLineCompare(ObjectKey& key) {
    /*
        The Plan:
        Find the minimum valued line, from that line, find the least value object
        Find the maximum valued line, from that line, find the maximum value object

        swap the two objects, repeat until a reasonable card is constructed
    
    */

    DebugReport("~~~~~~~ New Card! ~~~~~~~\n");

    f32 totalWeight = key.GetTotalWeight();

    // A line takes up 1/4th of the total bingo card
    f32 expectedLineWeight = totalWeight / 4;

    DebugReport("Expected Weight %f\n", expectedLineWeight);

    LineWeightReport weightReport = ReportWeight(key);

    int attempts = 0;

    

    int minIdx = DroughtLib::ArrayFunctions::ArrayMin(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));
    int maxIdx = DroughtLib::ArrayFunctions::ArrayMax(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));

    f32 strongestLineWeight = weightReport.mWeight[minIdx];
    
    while (FABS(strongestLineWeight - expectedLineWeight) > 0.4f && attempts < 10) {

        DroughtLib::StaticSizedArray<16, f32> weightsForMins = CalcPlacementWeights(key, weightReport);
        DroughtLib::StaticSizedArray<16, f32> weightsForMaxs = CalcPlacementWeights(key, weightReport, true);

        attempts++;

        f32 minWeightArray[4];
        f32 maxWeightArray[4];

        LineData& minLine = weightReport.mLines[minIdx];
        LineData& maxLine = weightReport.mLines[maxIdx];

        u8 minIdxs[4];
        u8 maxIdxs[4];

        for (int i = 0; i < 4; i++) {
            u8 minX = minLine.mXValues[i];
            u8 minY = minLine.mYValues[i];

            minIdxs[i] = minX * 4 + minY;

            minWeightArray[i] = weightsForMins[minIdxs[i]];

            u8 maxX = maxLine.mXValues[i];
            u8 maxY = maxLine.mYValues[i];

            maxIdxs[i] = maxX * 4 + maxY;

            maxWeightArray[i] = weightsForMaxs[maxIdxs[i]];
        }

        int minMinIdx = DroughtLib::ArrayFunctions::ArrayMin(minWeightArray, ARRAY_SIZE(minWeightArray));

        int trueMinIdx = minIdxs[minMinIdx];

        DebugReport("Min Idx %i\n", trueMinIdx);

        int maxMaxIdx = DroughtLib::ArrayFunctions::ArrayMax(maxWeightArray, ARRAY_SIZE(maxWeightArray));

        int trueMaxIdx = maxIdxs[maxMaxIdx];

        DebugReport("Max Idx %i\n", trueMaxIdx);

        u8 holdThisPlease = reinterpret_cast<u8*>(mObjects)[trueMaxIdx];

        reinterpret_cast<u8*>(mObjects)[trueMaxIdx] = reinterpret_cast<u8*>(mObjects)[trueMinIdx];

        reinterpret_cast<u8*>(mObjects)[trueMinIdx] = holdThisPlease;


        // reevaluate everything
        weightReport = ReportWeight(key);

        minIdx = DroughtLib::ArrayFunctions::ArrayMin(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));
        maxIdx = DroughtLib::ArrayFunctions::ArrayMax(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));

        strongestLineWeight = weightReport.mWeight[minIdx];
    }
}


void BingoMgr::BingoCard::ReweighCardByObjShuffle(ObjectKey& key) {

    DebugReport("~~~~~~~ New Card! ~~~~~~~\n");

    f32 totalWeight = key.GetTotalWeight();

    // A line takes up 1/4th of the total bingo card
    f32 expectedLineWeight = totalWeight / 4;

    LineWeightReport weightReport = ReportWeight(key);

    DebugReport("Expected Weight %f\n", expectedLineWeight);

    int minLineIndex = DroughtLib::ArrayFunctions::ArrayMin(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));

    f32 strongestLineWeight = weightReport.mWeight[minLineIndex];

    int attempts = 0;

    while (FABS(strongestLineWeight - expectedLineWeight) > 0.4f && attempts < 10)
    {
        attempts++;

        DroughtLib::StaticSizedArray<16, f32> weights = CalcPlacementWeights(key, weightReport);

        int maxIdx = weights.MaxIdx();
        int minIdx = weights.MinIdx();

        DebugReport("Max Idx %i\n", maxIdx);
        DebugReport("Min Idx %i\n", minIdx);

        u8 holdThisPlease = reinterpret_cast<u8*>(mObjects)[minIdx];
        reinterpret_cast<u8*>(mObjects)[minIdx] = reinterpret_cast<u8*>(mObjects)[maxIdx];
        reinterpret_cast<u8*>(mObjects)[maxIdx] = holdThisPlease;

        weightReport = ReportWeight(key);

        minLineIndex = DroughtLib::ArrayFunctions::ArrayMin(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));

        strongestLineWeight = weightReport.mWeight[minLineIndex];


    }

    

}


DroughtLib::StaticSizedArray<16, f32> BingoMgr::BingoCard::CalcPlacementWeights(ObjectKey& key, LineWeightReport& weightReport, bool evalSelf) {

    DroughtLib::StaticSizedArray<16, f32> itemSums = 0.0f;
    DroughtLib::StaticSizedArray<16, int> itemCounts = 0;

    for (int i = 0; i < ARRAY_SIZE(weightReport.mLines); i++) {
        LineData& line = weightReport.mLines[i];

        for (int v = 0; v < 4; v++) {
            int idx = line.mXValues[v] * 4 + line.mYValues[v];
            if (evalSelf) {
                itemSums[idx] += weightReport.mWeight[i] * key.mObjectEntries[reinterpret_cast<u8*>(mObjects)[idx]].mWeight;
            }
            else {
                itemSums[idx] += weightReport.mWeight[i];
            }
            itemCounts[idx]++;
        }

    }

    return itemSums;
}

DroughtLib::StaticSizedArray<16, f32> BingoMgr::BingoCard::CalcPlacementWeights(ObjectKey& key, bool evalSelf) {
    LineWeightReport weightReport = ReportWeight(key);

    return CalcPlacementWeights(key, weightReport, evalSelf);
}


void BingoMgr::BingoCard::ReweighCardByLineShuffle(ObjectKey& key) {

    DebugReport("~~~~~~~ New Card! ~~~~~~~\n");

    f32 totalWeight = key.GetTotalWeight();

    // A line takes up 1/4th of the total bingo card
    f32 expectedLineWeight = totalWeight / 4;

    DebugReport("Expected Weight %f\n", expectedLineWeight);

    LineWeightReport weightReport = ReportWeight(key);

    int minIndex = DroughtLib::ArrayFunctions::ArrayMin(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));

    f32 strongestLineWeight = weightReport.mWeight[minIndex];

    int attempts = 0;

    while (FABS(strongestLineWeight - expectedLineWeight) > 0.4f && attempts < 100)
    {
        DebugReport("Evaluated Min Index %i\n", minIndex);

        attempts++;

        const int ArrSize = ARRAY_SIZE(weightReport.mWeight);

        // make an array of the weakest lines to strongest lines
        DroughtLib::StaticSizedArray<ArrSize, int> indexList = DroughtLib::ArrayFunctions::MakeSortedIndexList<ArrSize>(weightReport.mWeight);

        DebugReport("Index Array: ");
        for (int i = 0; i < ArrSize; i++) {
            DebugReport("%i ", indexList[i]);
        }
        DebugReport("\n");

        Vector2i weakestPoint(0, 0);
        Vector2i strongestPoint(0, 0);

        bool success = false;


        // find the next intersecting line with the strongest line
        for (int i = 1; i < indexList.GetSize(); i++) {

            LineData& compareLine = weightReport.mLines[indexList[i]];
            LineData& ourLine = weightReport.mLines[minIndex];

            for (int v = 0; v < 4; v++) {
                for (int v2 = 0; v2 < 4; v2++) {
                    if (compareLine.mXValues[v] == ourLine.mXValues[v2] && compareLine.mYValues[v] == ourLine.mYValues[v2]) {
                        strongestPoint.x = compareLine.mXValues[v];
                        strongestPoint.y = compareLine.mYValues[v];
                        success = true;
                        break;
                    }
                }
                if (success) break;
            }
            if (success) break;
        }

        if (!success) {
            DebugReport("not good 1\n");
            break;
        }

        bool success2 = false;

        int maxIndex = indexList[indexList.GetSize() - 1];

        // find the next intersecting line with the weakest line
        for (int i = indexList.GetSize() - 2; i >= 0; i--) {

            LineData& compareLine = weightReport.mLines[indexList[i]];
            LineData& ourLine = weightReport.mLines[maxIndex];

            for (int v = 0; v < 4; v++) {
                for (int v2 = 0; v2 < 4; v2++) {
                    if (compareLine.mXValues[v] == ourLine.mXValues[v2] && compareLine.mYValues[v] == ourLine.mYValues[v2]) {
                        weakestPoint.x = compareLine.mXValues[v];
                        weakestPoint.y = compareLine.mYValues[v];
                        if (mObjects[weakestPoint.x][weakestPoint.y] != mObjects[strongestPoint.x][strongestPoint.y]) {
                            success2 = true;
                        }
                        break;
                    }
                }
                if (success2) break;
            }

            if (success2) break;
        }

        if (!success2) {
            DebugReport("Not good 2!\n");
            break;
        }


        // now we have to the strongest point and the weakest point, to maximize ballence, we will swap them
        u8 holdThisPlease = mObjects[weakestPoint.x][weakestPoint.y];
        mObjects[weakestPoint.x][weakestPoint.y] = mObjects[strongestPoint.x][strongestPoint.y];
        mObjects[strongestPoint.x][strongestPoint.y] = holdThisPlease;


        // reevaluate everything
        weightReport = ReportWeight(key);

        minIndex = DroughtLib::ArrayFunctions::ArrayMin(weightReport.mWeight, ARRAY_SIZE(weightReport.mWeight));

        strongestLineWeight = weightReport.mWeight[minIndex];


    }
    



}

BingoMgr::LineWeightReport BingoMgr::BingoCard::ReportWeight(ObjectKey& key) {
    LineWeightReport report;

    int lineCount = 0;

    for (int i = 0; i < 4; i++) {
        for (int row = 0; row < 4; row++) {
            report.mLines[lineCount].mXValues[row] = i;
            report.mLines[lineCount].mYValues[row] = row;

            report.mWeight[lineCount] += key.mObjectEntries[mObjects[i][row]].mWeight;
        }
        lineCount++;
    }

    for (int i = 0; i < 4; i++) {
        for (int col = 0; col < 4; col++) {
            report.mLines[lineCount].mXValues[col] = col;
            report.mLines[lineCount].mYValues[col] = i;

            report.mWeight[lineCount] += key.mObjectEntries[mObjects[col][i]].mWeight;
        }
        lineCount++;
    }

    for (int i = 0; i < 4; i++) {
        report.mLines[lineCount].mXValues[i] = i;
        report.mLines[lineCount].mYValues[i] = i;

        report.mWeight[lineCount] += key.mObjectEntries[mObjects[i][i]].mWeight;
    }
    lineCount++;
    

    for (int i = 0; i < 4; i++) {
        report.mLines[lineCount].mXValues[i] = 3 - i;
        report.mLines[lineCount].mYValues[i] = i;

        report.mWeight[lineCount] += key.mObjectEntries[mObjects[3 - i][i]].mWeight;
    }
    lineCount++;


    
    return report;
}

BingoMgr::LineWeightReport BingoMgr::BingoCard::ReportWeightVerbose(ObjectKey& key) {
    LineWeightReport report = ReportWeight(key);

    DebugReport("Weight Report Summary:\n");
    for (int i = 0; i < 10; i++) {
        DebugReport("Line %i | Weight %f\n", i, report.mWeight[i]); 
    }

    DebugReport("Bingo Card Report:\n");
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (key.mObjectEntries[mObjects[x][y]].mPelType == 1) {
                DebugReport("[x]");
            }
            else {
                DebugReport("[o]");
            }
        }
        DebugReport("\n");
    }
    return report;
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

        for (int i = 0; i < enemyNode->mMgr->mNumObjects; i++) {
            EnemyBase* enemy = enemyNode->mMgr->getEnemy(i);
            if (enemy->mPelletDropCode) {
                s16 dropCode  = enemy->mPelletDropCode;
                u8 pelType = (u8)(dropCode >> 8);
                int idx = FindPellet(pelType, dropCode);
                if (idx != -1) {
                    mObjectEntries[idx].mExistCount++;
                }
            }
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
