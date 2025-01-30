#ifndef BINGO_MGR
#define BINGO_MGR

#include "types.h"
#include "DroughtLib.h"

struct Stream;
struct ResTIMG;

namespace Game
{

struct VsGameSection;
struct Pellet;
struct EnemyBase;

namespace VsGame
{



struct BingoMgr
{
    BingoMgr();
    ~BingoMgr();

    struct ObjectKey
    {
        struct Object
        {
            u8 mPelType;
            s16 mPelletID;
            u8 mExistCount;
            f32 mWeight;

            ResTIMG* mObjectTexture;

            void read(Stream&);

            void CountExists();

        };

        void read(Stream&);
        
        int FindPellet(Pellet* pelt);
        int FindPellet(u8 peltype, s16 pelid);
        int FindEnemy(int enemyID);
        int FindEnemy(EnemyBase*);

        void informDeath(Pellet*);
        void informDeath(EnemyBase*);

        f32 GetTotalWeight();

        void CountExists();
        

        int mObjectNum;
        Object* mObjectEntries;
        
    };

    struct LineData {
        u8 mXValues[4];
        u8 mYValues[4];
    };
    struct LineWeightReport {
        LineWeightReport() {
            for (int i = 0; i < ARRAY_SIZE(mWeight); i++) {
                mWeight[i] = 0.0f;
            }
        }

        LineData mLines[10];
        f32 mWeight[10];
    };

    struct BingoCard
    {
        u8 mObjects[4][4];
        bool mActive[4][4];
        bool mDisp[4][4];

        s8 mSlotQueue[5]; // exists because there's no nice way of figuring out the random marbles' value

        void Generate(ObjectKey& key);
        void ReweighCardByLineShuffle(ObjectKey& key); // depricated
        void ReweighCardByObjShuffle(ObjectKey& key); // depricated
        void ReweighCardByObjLineCompare(ObjectKey& key); // depricated
        void ReweighCard(ObjectKey& key);
        int ReceiveDispPellet(ObjectKey& key, Pellet* pellet);
        int ReceivePellet(ObjectKey& key, Pellet* pellet);
        bool CheckLine(int min, bool disp=false);
        bool CheckLine(int min, LineData& data, bool disp=false);
        int CheckLine(int min, LineData* data, int arraySize, bool disp=false);
        bool PelletSuckProcedure(ObjectKey& key, Pellet* pellet);
        bool isImpossible(ObjectKey& key, int x, int y);

        void Swap(int idx1, int idx2);

        void addSlotQueue(s8);
        s8 popSlotQuque();

        LineWeightReport ReportWeight(ObjectKey& key);
        LineWeightReport ReportWeightVerbose(ObjectKey& key);
        DroughtLib::StaticSizedArray<16, f32> CalcPlacementWeights(ObjectKey& key, bool evalSelf=false);
        DroughtLib::StaticSizedArray<16, f32> CalcPlacementWeights(ObjectKey& key, LineWeightReport& report, bool evalSelf=false);
    };

    void GenerateCards();

    void TeamReceivePellet(int team, Pellet* pellet);

    void CountExists();

    void read(Stream&);
    void informDeath(Pellet*);
    void informDeath(EnemyBase*);
    void init(VsGameSection*);
    void exec(VsGameSection*);

    void createBingoPellets();
    Pellet* dropBingoChanceItem();
    Pellet* createBingoChanceItem();

    enum BingoState {
        BINGOSTATE_NORMAL,
        BINGOSTATE_BINGOITEM
    };

    ObjectKey mKey;
    BingoCard* mCards; // array
    int mWinner;
    bool mDeathInformed;
    bool mBedamaSound[2];
    f32 mBingoTimer; // always counts down
    BingoState mBingoState;
    const static size_t sBingoItemSize;
    Pellet** mBingoItems;
};


} // namespace VsGame


} // namespace Game

#endif