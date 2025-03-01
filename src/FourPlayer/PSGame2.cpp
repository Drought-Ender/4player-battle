#include "PSGame/BASARC.h"
#include "PSSystem/PSSystemIF.h"
#include "PSAutoBgm/Cycle.h"
#include "PSGame/CameraMgr.h"
#include "PSGame/EnvSe.h"
#include "PSGame/PikScene.h"
#include "PSGame/SoundCreatureMgr.h"
#include "PSGame/SceneInfo.h"
#include "PSGame/SoundTable.h"
#include "PSGame/SysFactory.h"
#include "PSM/BossSeq.h"
#include "PSSystem/ConductorList.h"
#include "PSGame/SeMgr.h"
#include "PSGame/Global.h"
#include "PSSystem/PSGame.h"
#include "JSystem/JAudio/JALCalc.h"
#include "JSystem/JAudio/JAI/JAInter/SeMgr.h"
#include "Game/gamePlayData.h"
#include "PSAutoBgm/Conductor.h"

#include "Title.h"
#include "ebi/title/TTitle.h"
#include "og/ogLib2D.h"
#include "Pikmin2ARAM.h"
#include "Game/THPPlayer.h"
#include "Screen/Game2DMgr.h"
#include "PSSystem/PSGame.h"
#include "PSSystem/PSSystemIF.h"
#include "JSystem/JFramework/JFWDisplay.h"
#include "PSM/ObjMgr.h"
#include "GameFlow.h"
#include "Game/Data.h"
#include "Game/GameConfig.h"
#include "Game/MemoryCard/Mgr.h"
#include "og/newScreen/ogUtil.h"
#include "TParticle2dMgr.h"
#include "JSystem/JUtility/JUTProcBar.h"
#include "Dolphin/rand.h"
#include "Morimura/HiScore.h"
#include "ebi/E2DGraph.h"
#include "JSystem/JAudio/JAS/JASResArcLoader.h"
#include "nans.h"

#include "Game/AILOD.h"
#include "Game/Creature.h"
#include "Game/GameSystem.h"
#include "Sys/Sphere.h"
#include "Sys/Cylinder.h"
#include "Viewport.h"
#include "PSM/ObjCalc.h"
#include "Iterator.h"
#include "Game/Navi.h"

#include "nans.h"

namespace PSGame {

SceneInfo::SceneInfo()
    : mStageFlags(0)
    , mSceneType(0)
    , mCameras(0)
{
	for (int i = 0; i < 4; i++) {
		mCam1Position[i] = nullptr;
		mCam2Position[i] = nullptr;
		mCameraMtx[i]    = nullptr;
	}
}

/**
 * @note Address: 0x803354E8
 * @note Size: 0x78
 */
void SceneInfo::setStageFlag(SceneInfo::FlagDef flag, SceneInfo::FlagBitShift shift)
{
	if (flag == 0) {
		mStageFlags &= ~(1 << shift);
	} else if (flag == 1) {
		mStageFlags |= (1 << shift);
	} else {
		JUT_PANICLINE(906, "flag��0 or1�ł�");
	}
}

/**
 * @note Address: 0x80335560
 * @note Size: 0x10
 */
SceneInfo::FlagDef SceneInfo::getFlag(SceneInfo::FlagBitShift shift) const { return (SceneInfo::FlagDef)(mStageFlags >> shift & 1); }

void SceneInfo::setStageCamera() const
{
	for (u8 i = 0; i < mCameras; i++) {
		JAIBasic::msBasic->setCameraInfo((Vec*)mCam1Position[i], (Vec*)mCam2Position[i], mCameraMtx[i]->mMatrix.mtxView, i);
	}
}

PSSystem::Scene* PSM::SceneMgr::newGameScene(u8 wscene, PSGame::SceneInfo* info)
{
	PSSystem::Scene* scene = nullptr;
	if (info->getSceneType() == PSGame::SceneInfo::CHALLENGE_MODE || info->getSceneType() == PSGame::SceneInfo::TWO_PLAYER_BATTLE) {
		scene = new Scene_Challenge(wscene, info);

	} else {
		if (info->isCaveFloor()) {
			scene = new Scene_Cave(wscene, info);

		} else {
			switch (info->mSceneType) {
			case PSGame::SceneInfo::SCENE_NULL:
				scene = new Scene_Global(wscene, info);
				break;
			}
		}
	}

	if (!scene) {
		scene = new Scene_NoObjects(wscene, info);
	}

	P2ASSERTLINE(468, scene);

	scene->init();

	return scene;
}

PSSystem::Scene* PikSceneMgr::newAndSetGlobalScene()
{
	OSReport("PikSceneMgr::newAndSetGlobalScene()!\n");

	JUT_ASSERTLINE(1002, !mScenes, "2�d�ɃO���[�o���V�[�����쐬���悤�Ƃ���"); // 'I tried to create a global scene twice'
	SceneInfo info;
	info.mSceneType = SceneInfo::SCENE_NULL;
	info.mCameras   = 0;
	info.setStageFlag(SceneInfo::SCENEFLAG_Unk0, SceneInfo::SFBS_1);

	mScenes = newGameScene(0, &info);
	P2ASSERTLINE(1015, mScenes);
	mScenes->adaptTo(&mScenes);
	mEndScene = mScenes;

	PSSystem::SingletonBase<PSSystem::StreamDataList>::newInstance();
	P2ASSERTLINE(1024, PSSystem::SingletonBase<PSSystem::StreamDataList>::getInstance()->onlyLoad("/user/Totaka/StreamList.txt",
	                                                                                              JKRDvdRipper::ALLOC_DIR_TOP));
	PSSystem::SingletonBase<PSSystem::SeqDataList>::newInstance();
	P2ASSERTLINE(1028, PSSystem::SingletonBase<PSSystem::SeqDataList>::getInstance()->onlyLoad("/user/Totaka/BgmList.txt",
	                                                                                           JKRDvdRipper::ALLOC_DIR_TOP));

	JAInter::SoundInfo seInfo = { 0x00001F00, 255, 0, 0, 0x3F800000, 0x7f000000 };
	P2ASSERTLINE(1040, seInfo.mVolume.byteView[0] <= 127);
	PSSystem::SeSeq* seSeq = new PSSystem::SeSeq("se.bms", seInfo);
	P2ASSERTLINE(1043, seSeq);
	OSReport("SE Name: %s\n", seSeq->mBmsFileName);
	seSeq->init();
	OSReport("dead :(\n");
	mScenes->appendSeq(seSeq);
	OSReport("Seq 2\n");

	JAInter::SoundInfo bgmInfo = { 0x00000000, 0x7F, 1, 0, 0x3F800000, 0x32000000 };
	PSSystem::BgmSeq* bgmSeq   = newStreamBgm(P2_STREAM_SOUND_ID(PSSTR_OPTION), bgmInfo);
	OSReport("SE Name: %s\n", bgmSeq->mBmsFileName);
	P2ASSERTLINE(1061, bgmSeq);
	bgmSeq->init();
	OSReport("dead :(\n");
	mScenes->appendSeq(bgmSeq);
	OSReport("Leave!\n");
	return mScenes;
}

void SysFactory::newSoundSystem()
{
	OSReport("SysFactory::newSoundSystem()\n");
	P2ASSERTLINE(715, mHeap);
	P2ASSERTLINE(716, mHeapSize);
	P2ASSERTLINE(717, mAafFile);
	preInitJAI();

	JKRHeap* backupheap = JKRGetCurrentHeap();
	mHeap->becomeCurrentHeap();

	JKRSolidHeap* newheap = makeSolidHeap(mHeap->getFreeSize(), mHeap, false);
	P2ASSERTLINE(741, newheap);
	newheap->becomeCurrentHeap();
	PSSystem::SingletonBase<SoundTable::CategoryMgr>::newInstance();
	P2ASSERTLINE(748, mSolidHeapSize < newheap->getFreeSize());

	mSolidHeap = makeSolidHeap(mSolidHeapSize, newheap, false);
	P2ASSERTLINE(754, mSolidHeap);

	PSSystem::SetupArg arg = { mSolidHeap, mHeapSize, 231, seqCpuSync, mAafFile, "/SeqTest/" };
	P2ASSERTLINE(769, !PSSystem::spSysIF);
	PSSystem::SysIF::sMakeJAISeCallback = mMakeSeFunc;
	PSSystem::SysIF* sysif              = new PSSystem::SysIF(arg);
	P2ASSERTLINE(773, sysif);

	PSSystem::spSceneMgr = (PSSystem::SceneMgr*)newSceneMgr();
	P2ASSERTLINE(776, PSSystem::spSceneMgr);

	postInitJAI();

	PSAutoBgm::ConductorArcMgr::createInstance();
	PSSystem::ArcMgr<BASARC>::createInstance();

	PSSystem::SingletonBase<SeMgr>::newInstance();

	backupheap->becomeCurrentHeap();
	newheap->adjustSize();
	OSLockMutex(&sysif->mChecker.mMutex);
	sysif->mChecker.mIsEnabled = true;
	OSUnlockMutex(&sysif->mChecker.mMutex);
	OSDisableInterrupts();
	PSSystem::spSysIF = sysif;
	OSEnableInterrupts();
	// OSReport("LEave!\n");
}

/**
 * @note Address: 0x80335AA0
 * @note Size: 0x4AC
 */
PSSystem::Scene* PikSceneMgr::newAndSetCurrentScene(SceneInfo& info)
{
	// OSReport("PikSceneMgr::newAndSetCurrentScene()!\n");
	u8 sceneType = info.getSceneType();
	P2ASSERTLINE(1093, sceneType != SceneInfo::SCENE_NULL);
	JUT_ASSERTLINE(1094, sceneType < SceneInfo::SCENE_COUNT, "scene no���s��"); // 'scene no is invalid'

	checkScene();

	JUT_ASSERTLINE(1095, !mScenes->mChild, "�O���mCurrentScene�̌㏈�����s��"); // 'previous mCurrentScene post-processing is invalid

	info.setStageCamera();

	P2ASSERTLINE(1105, mScenes);
	P2ASSERTLINE(1106, !mScenes->mChild);

	u8 wScene                      = 255;
	PSAutoBgm::ConductorMgr::sHeap = JKRGetCurrentHeap();
	PSSystem::BgmSeq* seq          = initMainBgm(info, &wScene);
	P2ASSERTLINE(1132, seq);

	bool needboss              = false;
	PSSystem::SeqBase* bossSeq = nullptr;
	if ((u8)info.mSceneType == SceneInfo::CHALLENGE_MODE || (u8)info.mSceneType == SceneInfo::TWO_PLAYER_BATTLE
	    || u8(info.mSceneType - 1) <= 3 || info.isCaveFloor()) {
		needboss = true;
	}

	// Check for submerged castle theme
	if (info.isCaveFloor() && info.mSceneType == SceneInfo::COURSE_YAKUSHIMA) {
		if (static_cast<CaveFloorInfo&>(info).getCaveNoFromID() == 3 && !static_cast<CaveFloorInfo&>(info).isBossFloor()) {
			needboss = false;
		}
	}

	if (needboss) {
		bossSeq = initBossBgm(info, &wScene);
		P2ASSERTLINE(1163, bossSeq);
	}

	SceneInfo* newinfo;
	if (info.isCaveFloor()) {
		newinfo = new CaveFloorInfo(static_cast<CaveFloorInfo&>(info));
	} else {
		newinfo = new SceneInfo(info);
	}

	PSSystem::Scene* newscene = newGameScene(wScene, newinfo);
	P2ASSERTLINE(1185, seq);
	newscene->appendSeq(seq);

	if (needboss) {
		P2ASSERTLINE(1191, bossSeq);
		newscene->appendSeq(bossSeq);
	}

	initAdditionalBgm(info, newscene);
	P2ASSERTLINE(1214, newscene);
	mScenes->adaptChildScene(newscene);
	return newscene;
}

// /**
//  * @note Address: 0x803365BC
//  * @note Size: 0xD24
//  */
// PSSystem::BgmSeq* PikSceneMgr::initMainBgm(SceneInfo& info, u8* wScene)
// {
// 	P2ASSERTLINE(1378, wScene);
// 	JADUtility::AccessMode mode = (JADUtility::AccessMode)mAccessMode;
// 	PSSystem::BgmSeq* bgm       = nullptr;

// 	JAInter::SoundInfo soundInfo = { 0x1F00, 127, 255, 0, 0x3F800000, 0x32000000 };
// 	soundInfo._05                = 1;

// 	CaveFloorInfo& cinfo = static_cast<CaveFloorInfo&>(info);
// 	P2ASSERTLINE(1393, soundInfo._05 < 5);

// 	if (info.isCaveFloor()) {
// 		// we're in a 'cave' (story mode cave, 2P battle, vs or challenge mode)
// 		switch (info.mSceneType) {
// 		case SceneInfo::CHALLENGE_MODE:
// 			const char* path = "/user/Totaka/ChallengeBgmList.txt";
// 			PSSystem::SingletonBase<ConductorList>::newHeapInstance();

// 			ConductorList* list = PSSystem::SingletonBase<ConductorList>::getInstance();
// 			bool loaded         = list->load(path, JKRDvdRipper::ALLOC_DIR_BOTTOM);
// 			P2ASSERTLINE(1417, loaded);
// 			char* name = list->getInfo(cinfo.mChallengeModeStageNum, cinfo.mFloorNum);
// 			// getInfo might be returning some sort of wacky struct, with all the stack stuff
// 			u8 wScene2;
// 			char* bmsName;
// 			list->getSeqAndWaveFromConductor(name, &wScene2, &bmsName);
// 			*wScene = wScene2;
// 			bgm     = newAutoBgm(name, bmsName, soundInfo, (JADUtility::AccessMode)mode, info, nullptr);
// 			delete PSSystem::SingletonBase<ConductorList>::sInstance;
// 			PSSystem::SingletonBase<ConductorList>::sInstance = nullptr;
// 			break;

// 		case SceneInfo::TWO_PLAYER_BATTLE:
// 			bgm     = newDirectedBgm("battle_t.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE6_2P_Battle;
// 			break;
// 		}

// 		if (!bgm) {
// 			switch (cinfo.mBetaType) {
// 			case CaveFloorInfo::BetaType_Boss: // Floor without music for bosses, apparently it loads caveconc_00 by default
// 				bgm = newAutoBgm("caveconc_00_0.cnd", "caveconc.bms", soundInfo, (JADUtility::AccessMode)mode, info, nullptr);
// 				break;

// 			case CaveFloorInfo::BetaType_Relax: // Rest floor, load rest/relax music
// 				bgm     = newAutoBgm("caverelax.cnd", "caverelax.bms", soundInfo, (JADUtility::AccessMode)mode, info, nullptr);
// 				*wScene = PSSystem::WaveScene::WSCENE28_CaveRestFloor;
// 				break;
// 			}
// 		}

// 		// Check for submerged castle theme
// 		if (info.isCaveFloor() && info.mSceneType == SceneInfo::COURSE_YAKUSHIMA) {
// 			if (cinfo.getCaveNoFromID() == 3 && !cinfo.isBossFloor()) { // cave is submerged castle + not sublevel 5
// 				bgm = newBgmSeq("kuro_pre.bms", soundInfo);             // cue spooky music
// 				P2ASSERTLINE(1566, bgm);
// 				*wScene = PSSystem::WaveScene::WSCENE48_SubmergedCastle;
// 			}
// 		}

// 		// story mode cave bgm settings
// 		if (!bgm) {
// 			P2ASSERTLINE(1574, !cinfo.mBetaType);
// 			char* txtpath = nullptr;
// 			switch (info.mSceneType) {
// 			case SceneInfo::COURSE_TUTORIAL:
// 			case SceneInfo::COURSE_TUTORIALDAY1:
// 				txtpath = "/user/Totaka/BgmList_Tutorial.txt";
// 				break;
// 			case SceneInfo::COURSE_FOREST:
// 				txtpath = "/user/Totaka/BgmList_Forest.txt";
// 				break;
// 			case SceneInfo::COURSE_YAKUSHIMA:
// 				txtpath = "/user/Totaka/BgmList_Yakushima.txt";
// 				break;
// 			case SceneInfo::COURSE_LAST:
// 				txtpath = "/user/Totaka/BgmList_Last.txt";
// 				break;
// 			case SceneInfo::COURSE_TEST:
// 				txtpath = "/user/Totaka/BgmList_BgmTest.txt";
// 				break;
// 			}

// 			PSSystem::SingletonBase<PSGame::ConductorList>::newHeapInstance();
// 			ConductorList* list = PSSystem::SingletonBase<PSGame::ConductorList>::getInstance();
// 			bool loaded         = list->load(txtpath, JKRDvdRipper::ALLOC_DIR_BOTTOM);
// 			P2ASSERTLINE(1601, loaded);
// 			OSReport("caveID==%d\n", cinfo.getCaveNoFromID());
// 			char* name = list->getInfo(cinfo.getCaveNoFromID(), cinfo.mFloorNum);
// 			u8 wScene2;
// 			char* bmsName;
// 			list->getSeqAndWaveFromConductor(name, &wScene2, &bmsName);
// 			*wScene = wScene2;
// 			bgm     = newAutoBgm(name, bmsName, soundInfo, (JADUtility::AccessMode)mode, info, nullptr);
// 			delete PSSystem::SingletonBase<ConductorList>::sInstance;
// 			PSSystem::SingletonBase<ConductorList>::sInstance = nullptr;
// 		}

// 	} else {
// 		// we're in story mode overworld, a menu/title/ending, or piklopedia
// 		switch (info.mSceneType) {
// 		// OVERWORLD
// 		case SceneInfo::COURSE_TUTORIAL:
// 		case SceneInfo::COURSE_TUTORIALDAY1:
// 			bgm     = newMainBgm("n_tutorial.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE15_Valley_of_Repose;
// 			break;

// 		case SceneInfo::COURSE_FOREST:
// 			bgm     = newMainBgm("forest.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE2_Awakening_Wood;
// 			break;

// 		case SceneInfo::COURSE_YAKUSHIMA:
// 			bgm     = newMainBgm("yakushima.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE3_Perplexing_Pool;
// 			P2ASSERTLINE(1640, bgm);
// 			static_cast<PSSystem::DirectedBgm*>(bgm)->assertValidTrack();
// 			static_cast<PSSystem::DirectedBgm*>(bgm)->mRootTrack->mBeatInterval = 30;
// 			break;

// 		case SceneInfo::COURSE_LAST:
// 			bgm     = newMainBgm("last.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE4_Wistful_Wild;
// 			P2ASSERTLINE(1650, bgm);
// 			static_cast<PSSystem::DirectedBgm*>(bgm)->assertValidTrack();
// 			static_cast<PSSystem::DirectedBgm*>(bgm)->mRootTrack->mBeatInterval = 30;
// 			break;

// 		// TITLE
// 		case SceneInfo::TITLE_SCREEN:
// 			bgm     = newStreamBgm(P2_STREAM_SOUND_ID(PSSTR_TITLE), soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE21_HighScores;
// 			break;

// 		// RESULTS
// 		case SceneInfo::CAVE_RESULTS:
// 			bgm = newStreamBgm(P2_STREAM_SOUND_ID(PSSTR_U_RESULT), soundInfo);
// 			break;
// 		case SceneInfo::CHALLENGE_RESULTS:
// 			bgm = newStreamBgm(P2_STREAM_SOUND_ID(PSSTR_C_RESULT), soundInfo);
// 			break;

// 		// FILE SELECT
// 		case SceneInfo::FILE_SELECT:
// 			bgm = newStreamBgm(P2_STREAM_SOUND_ID(PSSTR_FILE_SELECT), soundInfo);
// 			break;

// 		// MAP
// 		case SceneInfo::WORLD_MAP_NORMAL:
// 			bgm     = newBgmSeq("worldmap.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE16_WorldMap;
// 			break;
// 		case SceneInfo::WORLD_MAP_NEWLEVEL:
// 			bgm     = newBgmSeq("worldmap_intro.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE16_WorldMap;
// 			break;

// 		// CM MENU
// 		case SceneInfo::CHALLENGE_MENU:
// 			bgm     = newBgmSeq("c_menu.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE20_ChallengeSelect;
// 			break;

// 		// PIKLOPEDIA
// 		case SceneInfo::PIKLOPEDIA:
// 			bgm     = newBgmSeq("book.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE36_Piklopedia;
// 			break;

// 		// ENDINGS
// 		case SceneInfo::ENDING_COMPLETE:
// 			bgm     = newBgmSeq("comp_result.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE19_Final_Result;
// 			break;
// 		case SceneInfo::ENDING_DEBTRESULT:
// 			bgm     = newBgmSeq("f_result.bms", soundInfo);
// 			*wScene = PSSystem::WaveScene::WSCENE19_Final_Result;
// 			break;

// 		// VS MENU
// 		case SceneInfo::VERSUS_MENU:
// 			bgm = newStreamBgm(P2_STREAM_SOUND_ID(PSSTR_VS_MENU), soundInfo);
// 			break;
// 		default:
// 			JUT_PANICLINE(1745, "P2Assert");
// 		}
// 	}

// 	P2ASSERTLINE(1749, bgm);
// 	P2ASSERTLINE(1750, soundInfo.mVolume.byteView[0] <= 127);

// 	return bgm;
// }

} // namespace PSGame

namespace PSSystem {

/**
 * @note Address: 0x8033143C
 * @note Size: 0xD4
 */
void SeqHeap::loadSeqAsync(TaskChecker* task)
{
	mTask = task;
	P2ASSERTLINE(247, !mOwner);
	task = mTask; // this is so dumb but necessary for register allocation
	PSAdvanceTask(task);

	OSReport("task\n");

	int size     = ((int*)(mOwnerSeq->getFileEntry()))[3];
	u8* fileData = mFileData;
	int offs     = ((u16*)(mOwnerSeq->getFileEntry()))[0];
	int res
	    = JASResArcLoader::loadResourceAsync(JAInter::SequenceMgr::getArchivePointer(), offs, fileData, size, &loadedCallback, (u32)this);
	JUT_ASSERTLINE(266, res == 1, "SeqBase::loadSeqAsync() fault loading sequence");
}

} // namespace PSSystem

namespace PSM {

Scene_Game::Scene_Game(u8 p1, PSGame::SceneInfo* info)
    : Scene_Objects(p1, info)
    , mEnemyBossList()
    , mEnvSeMgr(nullptr)
    , _48(0)
    , _4C(-1)
    , mBossFaderMgr(nullptr)
    , mPersEnvMgr(nullptr)
{
	mHummingMgr = new PikiHummingMgr();
}

Scene_Cave::Scene_Cave(u8 p1, PSGame::SceneInfo* info)
    : Scene_Game(p1, info)
    , mPollutUpTimer(-1)
    , _5C(false)
{
	PSGame::CaveFloorInfo* floorInfo = static_cast<PSGame::CaveFloorInfo*>(info);
	switch (floorInfo->mAlphaType) {
	case PSGame::CaveFloorInfo::AlphaType_Soil:
	case PSGame::CaveFloorInfo::AlphaType_Metal:
	case PSGame::CaveFloorInfo::AlphaType_Concrete:
	case PSGame::CaveFloorInfo::AlphaType_Tile:
		mSceneFx = 1.0f; // CreaturePrm::cSeFxMix_cave
		break;
	case PSGame::CaveFloorInfo::AlphaType_Garden:
	case PSGame::CaveFloorInfo::AlphaType_Toy:
		mSceneFx = 0.0f;
		break;
	default:
		P2ASSERTLINE(953, false);
	}
}

Scene_Challenge::Scene_Challenge(u8 p1, PSGame::SceneInfo* info)
    : Scene_Cave(p1, info)
{
}

u8 ObjCalc_2PGame::getPlayerNo(Vec& pos)
{
	switch (mMode) {
	case 1:
		return 0;

	case 0:

		f32 minDistance = SQUARE(FLOAT_DIST_MAX);
		s8 minID        = 0;

		Iterator<Game::Navi> it(Game::naviMgr);
		CI_LOOP(it)
		{
			Game::Navi* navi = *it;
			if (!navi->isAlive()) {
				continue;
			}
			Vector3f naviPos = navi->getPosition();

			f32 dist = sqrDistance(naviPos, reinterpret_cast<Vector3f&>(pos));

			if (dist < minDistance) {
				minDistance = dist;
				minID       = navi->mNaviIndex;
			}
		}

		return minID;
	default:
		JUT_PANICLINE(77, "P2Assert");
		return 0;
	}
}

} // namespace PSM

namespace {
static s8 sSeasonIndex = 255;
} // namespace

namespace Title {

/**
 * @note Address: 0x8044C058
 * @note Size: 0x3C8
 */
void Section::loadResource()
{
	OSReport("Section::loadResource()!\n");
	sys->heapStatusStart("TitleSection::loadResource", nullptr);
	createScreenRootNode();
	PSGame::SceneInfo info;
	info.mSceneType          = PSGame::SceneInfo::TITLE_SCREEN;
	info.mCameras            = 0;
	PSGame::PikSceneMgr* mgr = static_cast<PSGame::PikSceneMgr*>(PSSystem::getSceneMgr());
	mgr->newAndSetCurrentScene(info);

	PSSystem::SceneMgr* mgr2 = PSSystem::getSceneMgr();
	mgr2->checkScene();
	mgr2->mScenes->mChild->scene1stLoadSync();

	sys->heapStatusStart("TParticle2dMgr", nullptr);
	TParticle2dMgr::globalInstance();
	particle2dMgr->createHeap(0x100000);
	particle2dMgr->createMgr("user/Ebisawa/effect/eff2d_game2d.jpc", 2000, 0x80, 0x80);
	sys->heapStatusEnd("TParticle2dMgr");

	sys->heapStatusStart("titleMgr", nullptr);
	int id;
	if (sSeasonIndex == -1) {
		id = randInt(12);
	} else {
		id = 12;
	}

	switch (id) {
	case 0:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Winter;
		break;
	case 1:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Winter;
		break;
	case 2:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Spring;
		break;
	case 3:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Spring;
		break;
	case 4:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Spring;
		break;
	case 5:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Summer;
		break;
	case 6:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Summer;
		break;
	case 7:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Summer;
		break;
	case 8:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Autumn;
		break;
	case 9:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Autumn;
		break;
	case 10:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Autumn;
		break;
	case 11:
		sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Winter;
		break;
	default:
		if ((s8)(++sSeasonIndex) > ebi::title::TTitleMgr::LEVEL_Winter) {
			sSeasonIndex = ebi::title::TTitleMgr::LEVEL_Spring;
		}
	}

	if (Game::gGameConfig.mParms.mKFesVersion.mData) {
		mMainTitleMgr.setMode(ebi::title::TTitleMgr::LEVEL_Summer);
	} else {
		mMainTitleMgr.setMode(sSeasonIndex);
	}
	mMainTitleMgr.loadResource();
	mMainTitleMgr.setController(mController1);
	sys->heapStatusEnd("titleMgr");

	sys->heapStatusStart("optionMgr", nullptr);
	mOptionMgr.loadResource();
	mOptionMgr.setController(mController1);
	sys->heapStatusEnd("optionMgr");

	sys->heapStatusStart("hiscoreTexture", nullptr);
	mHiScoreTex = nullptr;

	const char* name = "res_hiscoreTexture.szs";
	char buf[52];
	og::newScreen::makeLanguageResName(buf, name);

	mHiScoreTex = JKRMountArchive(buf, JKRArchive::EMM_Mem, nullptr, JKRArchive::EMD_Head);
	JUT_ASSERTLINE(1700, mHiScoreTex, "arcName = %s\n", buf);
	sys->heapStatusEnd("hiscoreTexture");

	sys->heapStatusStart("omakeMgr", nullptr);
	mOmakeMgr.newCardEMgrAndTask();
	mOmakeMgr.loadResource();
	mOmakeMgr.setControllers(mController1);
	sys->heapStatusEnd("omakeMgr");

	sys->heapStatusEnd("TitleSection::loadResource");

	sizeof(*this);
}

} // namespace Title

namespace Game {

void Creature::updateLOD(Game::AILODParm& parm)
{
	Sys::Sphere lodSphere;
	Sys::Cylinder lodCylinder;
	getLODSphere(lodSphere);
	if (parm.mIsCylinder) {
		getLODCylinder(lodCylinder);
	}

	int vpStats[4];
	mLod.mFlags       = AILOD_NULL;
	Graphics* gfx     = sys->mGfx;
	int viewportCount = gfx->mViewportCount;
	bool shouldCull   = true; // set to false if visible on any viewport
	int currFlag      = AILOD_IsFar;

	for (int i = 0; i < viewportCount; i++) {
		Viewport* vp = gfx->getViewport(i);
		if (!vp->viewable()) {
			vpStats[i] = AILOD_IsFar;
			continue;
		}

		Camera* camera = vp->mCamera;
		if (parm.mIsCylinder) {
			if (camera->isCylinderVisible(lodCylinder)) {
				shouldCull = false;
				mLod.setVPVisible(i);
			}
		} else if (camera->isVisible(lodSphere)) {
			shouldCull = false;
			mLod.setVPVisible(i);
		}

		f32 screenSize = camera->calcScreenSize(lodSphere);
		if (screenSize > parm.mFar) {
			vpStats[i] = AILOD_NULL;
		} else if (screenSize > parm.mClose) {
			vpStats[i] = AILOD_IsMid;
		} else {
			vpStats[i] = AILOD_IsFar;
		}

		if (vpStats[i] < currFlag) {
			currFlag = vpStats[i];
		}
	}

	if (!(gameSystem->isMultiplayerMode() && (2 <= viewportCount))) {
		mLod.mSoundVPID = 0;
	} else {

		f32 minDistance = SQUARE(FLOAT_DIST_MAX);
		s8 minID        = 0;

		for (s8 i = 0; i < viewportCount; i++) {
			Viewport* vp = gfx->getViewport(i);

			if (!vp->viewable()) {
				continue;
			}
			Vector3f pos = *vp->mCamera->getSoundPositionPtr();

			f32 dist = sqrDistance(pos, lodSphere.mPosition);

			if (dist < minDistance) {
				minDistance = dist;
				minID       = i;
			}
		}

		mLod.mSoundVPID = minID;
	}

	for (int i = 0; i < viewportCount; i++) {
		gfx->getViewport(i)->viewable();
	}

	mLod.setFlag((u8)currFlag);

	if (!shouldCull) {
		mLod.setFlag(AILOD_IsVisible);
	} else {
		mLod.mFlags = (AILOD_IsFar);
	}

	if (0 < getCellPikiCount()) {
		mLod.setFlag(AILOD_PikiInCell);
	}
}

} // namespace Game
