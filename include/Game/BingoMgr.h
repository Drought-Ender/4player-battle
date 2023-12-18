#ifndef BINGO_MGR
#define BINGO_MGR

#include "types.h"

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

        void CountExists();
        

        int mObjectNum;
        Object* mObjectEntries;
        
    };

    struct LineData {
        u8 mXValues[4];
        u8 mYValues[4];
    };

    struct BingoCard
    {
        u8 mObjects[4][4];
        bool mActive[4][4];
        bool mDisp[4][4];

        void Generate(ObjectKey& key);
        int ReceiveDispPellet(ObjectKey& key, Pellet* pellet);
        int ReceivePellet(ObjectKey& key, Pellet* pellet);
        bool CheckLine(int min, bool disp=false);
        bool CheckLine(int min, LineData& data, bool disp=false);
        int CheckLine(int min, LineData* data, int arraySize, bool disp=false);
        bool PelletSuckProcedure(ObjectKey& key, Pellet* pellet);

        bool isImpossible(ObjectKey& key, int x, int y);
    };

    void GenerateCards();

    void TeamReceivePellet(int team, Pellet* pellet);

    void CountExists();

    void read(Stream&);
    void informDeath(Pellet*);
    void informDeath(EnemyBase*);
    void init(VsGameSection*);

    ObjectKey mKey;
    BingoCard* mCards; // array
    int mWinner;
    bool mBedamaSound[2];
};


} // namespace VsGame


} // namespace Game

#endif