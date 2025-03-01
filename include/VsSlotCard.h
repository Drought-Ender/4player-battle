#ifndef _VSSLOTCARD_H_
#define _VSSLOTCARD_H_

#include "Game/VsGame.h"
#include "Game/Stickers.h"
#include "FloatingIconMgr.h"
#include "LifeGaugeMgr.h"

struct JUTTexture;

namespace efx {
struct THdamaSight;
struct TChibiShell;
struct TChibiHit;
} // namespace efx

namespace Game {
namespace VsGame {

enum TargetSpecifier { NONE = 0, TEAM = 1, PLAYER = 2 };

class VsSlotMachineCard {
protected:
	VsSlotMachineCard(const char* texName);

private:
	const char* mTexName;
	int mTexID;

public:
	static int sTexIDGlobal;

	inline const char* GetTexName() { return mTexName; }
	virtual void allocate(VsGameSection* section) { }
	virtual int getBedamaWeight(CardMgr* cardMgr, int user, int total, int baseWeight) { return baseWeight; }
	virtual int getWeight(CardMgr* cardMgr, int teamID) { return 100; }
	virtual void onUseCard(CardMgr* cardMgr, int user, int target) { }
	virtual void onUseCard(CardMgr* cardMgr, int user) { }
	virtual TargetSpecifier useTarget() { return NONE; }

	void updateTexName(const char* texname) { mTexName = texname; }
	virtual bool varibleForward() { return false; }
	virtual bool varibleBackward() { return false; }
	virtual int getVaribleForwardCount() { return 0; }

	virtual int getTexID() { return mTexID; }

	virtual const char* getDescription() = 0;

	void useCard(CardMgr* cardMgr, int user, int target)
	{
		onUseCard(cardMgr, user);
		onUseCard(cardMgr, user, target);
	}

protected:
	JUTTexture* GetTextureFromMgr();
};

static bool isPaused();

enum EntityID { ENTITY_HAZARD, ENTITY_FALL, ENTITY_CALLBACKHOLDER, ENTITY_PLUCKFUE, ENTITY_STUNSTORM };

struct ActionEntity : public CNode {
	virtual bool update() { };
	virtual void draw(Graphics& gfx) { }
	virtual EntityID getEntityID() = 0;
};

class FloatingIconInitializer {
public:
	FloatingIconInitializer(const Vector3f* vecPtr, JUTTexture* tex, f32 offs);
	~FloatingIconInitializer();

	bool show();
	bool hide();

private:
	FloatingIcon* mIcon;
	bool mIsHide;
};

struct TeamEntity : public ActionEntity {
	TeamEntity(int teamID)
	    : mTeamID(teamID)
	{
	}

	const int mTeamID;

	int getTeamID() const { return mTeamID; }
};

struct TeamPositionEntity : public TeamEntity, public TPositionObject {
	TeamPositionEntity(int teamID, Vector3f position)
	    : TeamEntity(teamID)
	    , mPosition(position)
	{
	}

	Vector3f mPosition;

	virtual Vector3f getPosition() { return mPosition; }
};

struct TeamPositionTimerEntity : public TeamPositionEntity {
	TeamPositionTimerEntity(int teamID, Vector3f position, f32 maxtimer)
	    : TeamPositionEntity(teamID, position)
	    , mTimer(maxtimer)
	    , mMaxTimer(maxtimer)
	{
		mLifeGauge.mCurrentSegmentNum = 0;
	}

	f32 mTimer; // counts down
	f32 mMaxTimer;
	LifeGauge mLifeGauge;

	virtual bool update();
	virtual EntityID getEntityID() = 0;

	void drawLifeGauge(Graphics& gfx, f32 height);
};

struct PositionEntity : public ActionEntity, public TPositionObject {
	PositionEntity(Vector3f position)
	    : ActionEntity()
	    , mPosition(position)
	{
	}

	Vector3f mPosition;

	virtual Vector3f getPosition() { return mPosition; }
};

struct PositionTimerEntity : public PositionEntity {
	PositionTimerEntity(Vector3f position, f32 maxtimer)
	    : PositionEntity(position)
	    , mTimer(maxtimer)
	    , mMaxTimer(maxtimer)
	{
		mLifeGauge.mCurrentSegmentNum = 0;
	}
	f32 mTimer; // counts down
	f32 mMaxTimer;
	LifeGauge mLifeGauge;

	virtual bool update();
	virtual EntityID getEntityID() = 0;

	void drawLifeGauge(Graphics& gfx, f32 height);
};

struct HazardBarrier : public TeamPositionTimerEntity {
	HazardBarrier(int, Vector3f);
	~HazardBarrier();

	static efx::TBase* MakeEfx(TeamID);
	static f32 GetEfxTimer(TeamID);

	efx::TBase* mEfx;
	f32 mEfxTimer;

	virtual bool update();
	virtual void draw(Graphics&);
	virtual EntityID getEntityID() { return ENTITY_HAZARD; }
};

struct WaitEnemySpawn : public PositionTimerEntity {

	EnemyBase* birthFromSky();

	WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime, JUTTexture* tex);
	WaitEnemySpawn(Vector3f position, int entityId, f32 timer, f32 existenceTime);
	~WaitEnemySpawn();

	void init();

	virtual bool update();
	virtual void draw(Graphics& gfx);
	virtual EntityID getEntityID() { return ENTITY_FALL; }

	efx::THdamaSight* mEfx;
	f32 mMaxWaitTimer;
	f32 mExistenceTimer;
	int mEntityID;
	FloatingIcon* mIcon;

	LifeGauge mLifeGauge;
};

struct PluckAllFue : public TeamPositionTimerEntity {
	PluckAllFue(const Navi*, int, Vector3f, JUTTexture* tex);
	~PluckAllFue();

	void init();
	void updateWhistleEffect(f32 scale);
	void pluckPikis(f32 scale);
	virtual Vector3f getPosition() { return const_cast<Navi*>(mNaviPtr)->getPosition(); }

	virtual bool update();
	virtual void draw(Graphics& gfx);
	virtual EntityID getEntityID() { return ENTITY_PLUCKFUE; }

	const Navi* mNaviPtr;
	efx::TCursor* mEfxWhistle;
	FloatingIconInitializer mIconContainer;
	u32 mPluckedPikiCount;
};

struct FloatingIconHolderBase : public PositionEntity {
	FloatingIconHolderBase(Vector3f position, JUTTexture* tex);
	~FloatingIconHolderBase();

	virtual bool update() = 0;

	FloatingIcon* mIcon;
};

struct CallbackArgs { };

typedef bool(BoolCallback(const Vector3f&, const CallbackArgs*));

struct FloatingIconHolderCallback : public FloatingIconHolderBase {
	FloatingIconHolderCallback(Vector3f position, JUTTexture* tex, const BoolCallback* callback, const CallbackArgs* args);

	virtual bool update();
	virtual EntityID getEntityID() { return ENTITY_CALLBACKHOLDER; }

	const BoolCallback* mCallback;
	const CallbackArgs* mArgs;
};

#define STUN_STORM_COUNT         (8)
#define STUN_STORM_WAIT_TIMER    (0.6f)
#define STUN_STORM_FALL_TIMER    (0.6f)
#define STUN_STORM_MAX_LENGTH    (5.0f)
#define STUN_SHELL_ATTACK_RADIUS (30.0f)
#define STUN_SHELL_MAX_HEIGHT    (300.0f)
#define STUN_STORM_BEAT_COUNT    (64)
#define STUN_STORM_STARTUP       (0.4f)

struct StunStorm : public ActionEntity {
	StunStorm(Navi* userNavi, Navi* targetNavi, JUTTexture* tex);
	~StunStorm();

	Navi* mUser;
	Navi* mTarget;

	FloatingIconInitializer mIconContainer;

	struct Shell {
		Shell();
		~Shell();
		f32 mTimer;
		Vector3f mPosition;
		efx::TChibiShell* mShellEfx;

		void init(Vector3f& pos);
		void setTimer(f32);
		bool update(Navi* user, Navi* target);
		void updateFly(Navi* user);
		void updateLand(Navi* target);

		void hit(Vector3f& pos);
	};

	virtual bool update();
	virtual EntityID getEntityID() { return ENTITY_STUNSTORM; }

	Shell mShells[STUN_STORM_COUNT];
};

struct ActionEntityMgr : public CNode {

	void add(ActionEntity* entity);

	void update();
	void draw(Graphics& gfx);
};

struct VsSlotCardMgr {
	VsSlotCardMgr();

	static int sTotalCardCount;
	static VsSlotMachineCard** sAllCards;
	static bool* sUsingCards;
	static void initAllCards();

	void generateCards(VsGameSection*);

	VsSlotMachineCard* getAt(int i) { return mUsingCards[i]; }
	int getCardCount() { return mCardCount; }

	void update();
	void draw(Graphics& gfx);

	ActionEntityMgr* getActionMgr() { return &mActionMgr; };

	int mCardCount;

	VsSlotMachineCard** mUsingCards;

	ActionEntityMgr mActionMgr;
};

extern bool sEnemyXLU;

extern VsSlotCardMgr* vsSlotCardMgr;

} // namespace VsGame
} // namespace Game

#endif