#include "Game/BaseGameSection.h"
#include "Game/GameSystem.h"
#include "Game/MapMgr.h"
#include "Game/Entities/ItemOnyon.h"
#include "Game/Navi.h"
#include "Game/NaviState.h"
#include "PSM/Navi.h"
#include "Game/MoviePlayer.h"
#include "PSGame/Global.h"
#include "utilityU.h"
#include "Splitter.h"
#include "Game/CameraMgr.h"
#include "FourPlayer.h"
#include "Game/GameLight.h"
#include "Game/PikiMgr.h"
#include "JSystem/J3D/J3DModelLoader.h"
#include "Dolphin/rand.h"
#include "VsOptions.h"
#include "Game/MapMgr.h"
#include "Game/mapParts.h"
#include "Game/generalEnemyMgr.h"
#include "Screen/Game2DMgr.h"

f32 gFirstViewportHeight = 0.5f;
f32 gOtherViewportHeight = 0.5f;

namespace Game {

bool gSplit4 = false;

Controller* gControllerP3;
Controller* gControllerP4;

PlayCamera* gCameraP3;
PlayCamera* gCameraP4;

void BaseGameSection::initControllers()
{
	gControllerP3 = new Controller((JUTGamePad::EPadPort)2);
	gControllerP4 = new Controller((JUTGamePad::EPadPort)3);
}

bool gFancyCamera;

int gNaviNum = 2;

void BaseGameSection::birthNavis()
{

	gNaviNum = CalcNaviNum();
	for (int i = 0; i < 4; i++) {
		gDrawNavi[i] = true;
	}
	PlayCamera* playCameraPtrArr[4] = { mOlimarCamera, mLouieCamera, gCameraP3, gCameraP4 };
	for (int i = 0; i < 4; i++) {
		Vector3f startVelocity = 0.0f;
		Vector3f startPosition = Vector3f(-40.0f, 0.0f, 2.0f);
		f32 mapRotation        = mapMgr->getMapRotation();
		if (gameSystem->isVersusMode() && i < gNaviNum) {
			Onyon* onyon = ItemOnyon::mgr->getOnyon(gVsNaviIndexArray[i]);
			P2ASSERT(onyon);
			startPosition = onyon->getPosition();
		} else if (!mapMgr->getDemoMatrix()) {
			mapMgr->getStartPosition(startPosition, 0);
			startPosition.y = mapMgr->getMinY(startPosition) + 8.5f;
			startPosition.x += -4.526f;
			startPosition.z += 7.453f;
		} else {
			Matrixf* demoMatrix = mapMgr->getDemoMatrix();
			PSMTXMultVec(demoMatrix->mMatrix.mtxView, (Vec*)&startPosition, (Vec*)&startPosition);
			startPosition.y = mapMgr->getMinY(startPosition);
			startVelocity   = 0.0f;
		}
		Navi* navi = naviMgr->birth();
		P2ASSERT(navi);
		navi->init(nullptr);
		navi->mFaceDir     = roundAng(mapRotation);
		navi->mCamera      = playCameraPtrArr[i];
		navi->mCamera2     = playCameraPtrArr[i];
		navi->mController1 = nullptr;
		navi->mController2 = nullptr;
		navi->setPosition(startPosition, false);
		navi->setVelocity(startVelocity);
		navi->mHealth = playData->mNaviLifeMax[0];
	}

	for (int i = gNaviNum; i < 4; i++) {
		// hacky solution to remove the navis without the game crashing
		naviMgr->getAt(i)->setAlive(false);
		naviMgr->getAt(i)->mIsAlive = true;
		naviMgr->getAt(i)->kill(nullptr);
		naviMgr->informOrimaDead(i);
	}
}

void NaviMgr::informOrimaDead(int idx)
{
	for (int i = 0; i < mNaviCount; i++) {
		if (mNaviIndexArray[idx] == i) {
			return;
		}
	}
	mNaviIndexArray[mNaviCount] = idx;
	mNaviCount++;
	getAt(idx)->releasePikis();
}

Navi* NaviMgr::getDeadOrima(int idx)
{
	if (idx <= mNaviCount) {
		return getAt(mNaviIndexArray[idx]);
	}
	return nullptr;
}

Navi* NaviMgr::getAliveOrima(int idx)
{
	for (int i = 0; i < 4; i++) {
		Navi* navi = getAt(i);
		if (navi->isAlive()) {
			return navi;
		}
	}

	return nullptr;
}

void NaviMgr::loadResources_float()
{
	JKRArchive* pikiArc = JKRArchive::mount("user/Kando/piki/pikis.szs", JKRArchive::EMM_Mem, sys->mSysHeap, JKRArchive::EMD_Head);
	void* models[4];
	u32 renderFlags[4];

	for (int i = 0; i < 4; i++) {
		models[i]      = sCharacters[i].loadModel();
		renderFlags[i] = sCharacters[i].loadRenderFlags();
	}

	J3DModelData* modelData[4];
	for (int i = 0; i < 4; i++) {
		modelData[i] = J3DModelLoaderDataBase::load(models[i], renderFlags[i]);
		for (int j = 0; j < modelData[i]->mShapeTable.mCount; j++) {
			u32& bitfield = modelData[i]->mShapeTable.mItems[j]->mFlags;
			bitfield &= ~0xF000;
			bitfield |= 0x2000;
		}
	}
	mOlimarModel    = modelData[0];
	mLouieModel     = modelData[1];
	mPresidentModel = modelData[2];
	mWifeModel      = modelData[3];
}

SysShape::Model* NaviMgr::createModel(int idx)
{
	J3DModelData* models[] = { mOlimarModel, mLouieModel, mPresidentModel, mWifeModel };
	return new SysShape::Model(models[idx], 0, 2);
}

// Navi* NaviMgr::birth() {
//     Navi* navi = MonoObjectMgr<Navi>::birth();
//     if (navi) {
//         navi->mNaviIndex = mActiveCount - 1;
//         P2ASSERT(navi->mSoundObj);
//         navi->mSoundObj->init(0);
//     }
//     for (int i = 0; i < mNaviCount; i++) {
//         if (mNaviIndexArray[i] == navi->mNaviIndex) {
//             navi->setAlive(false);
//         }
//     }
// }

void NaviMgr::clearDeadCount()
{
	mNaviCount      = 0;
	mNaviIndexArray = new int[4];
	for (int i = 0; i < 4; i++) {
		mNaviIndexArray[i] = -1;
	}
}

void Navi::onInit(Game::CreatureInitArg* arg)
{
	mStick = 0;
	_258   = 0;
	u16 uVar2;

	clearKaisanDisable();
	clearThrowDisable();

	mInvincibleTimer = 0;
	_2F8             = 0.0f;

	mSprayCounts[1] = 0;
	mSprayCounts[0] = 0;

	initFakePiki();
	naviMgr->setupNavi(this);

	mModel->mJ3dModel->mModelData->mJointTree.mJoints[0]->mMtxCalc = nullptr;
	mModel->mJ3dModel->mModelData->mJointTree.mJoints[1]->mMtxCalc = nullptr;

	mNaviControlFlag.clear();
	resetControlFlag(NAVICTRL_InMovie);

	initAnimator();

	mIsAlive = false;
	_308     = 0.0f;

	mWhistle = new NaviWhistle(this);

	_2DE           = 0;
	mNextThrowPiki = nullptr;
	mHoldPikiTimer = 0.0f;
	_2AC           = 0;

	mCollTree->createFromFactory(mModel, naviMgr->_CC, nullptr);
	JUT_ASSERTLINE(838, ((int)mCollTree->mPart) >= 0x80000000,
	               "�U���[�[�i�E�t�E�j??�l��\n"); // 'disappointttttt D: ?? ment' (lol)
	mCollTree->attachModel(mModel);

	mFsm->start(this, NSID_Walk, nullptr);

	getCreatureID();

	mBeaconJoint = mModel->getJoint("happajnt3");

	mEffectsObj->mBeaconMtx = mBeaconJoint->getWorldMatrix();
	mEffectsObj->mNaviPos   = &mWhistle->mPosition;

	SysShape::Joint* headJnt = mModel->getJoint("headjnt");
	mEffectsObj->mHeadMtx    = headJnt->getWorldMatrix();
	mEffectsObj->setNaviType((efx::TNaviEffect::enumNaviType)getVsTeam());

	mEffectsObj->createLight();

	setLifeMax();

	mPluckingCounter = 0;
	_269             = 0;
	Vector3f navi_scale; // navi model scale
	navi_scale = Vector3f(1.3f);

	if (mNaviIndex == 1 || mNaviIndex == 2) { // case for Louie/President scale
		navi_scale = Vector3f(1.5f);
	}

	mScale = navi_scale;
	uVar2  = mNaviIndex;
	mCursorMatAnim->start(&naviMgr->_60[0]);
	mArrowMatAnim->start(&naviMgr->_88[0]);
}

void efx::TNaviEffect::setNaviType(enumNaviType type)
{
	switch (type) {
	case NAVITYPE_Olimar:
		mCursor.mContextNum           = WHISTLE_CONTEXT_NUM;
		mCursor.mAngleSpeed           = TCursor::kAngleSpeed;
		mCursor.mOneEmitter.mEffectID = PID_Cursor_Default;
		mLight.mNaviType              = 0;
		mLightAct.mNaviType           = 0;
		break;
	case NAVITYPE_Louie:
		mCursor.mContextNum           = WHISTLE_CONTEXT_NUM;
		mCursor.mAngleSpeed           = TCursor::kAngleSpeed;
		mCursor.mOneEmitter.mEffectID = PID_Cursor_Default;
		mLight.mNaviType              = 1;
		mLightAct.mNaviType           = 1;
		break;
	case NAVITYPE_President:
		mCursor.mContextNum           = WHISTLE_CONTEXT_NUM;
		mCursor.mAngleSpeed           = TCursor::kAngleSpeed;
		mCursor.mOneEmitter.mEffectID = PID_Cursor_Default;
		mLight.mNaviType              = 2;
		mLightAct.mNaviType           = 2;
		break;
	case 3:
		mCursor.mContextNum           = WHISTLE_CONTEXT_NUM;
		mCursor.mAngleSpeed           = TCursor::kAngleSpeed;
		mCursor.mOneEmitter.mEffectID = PID_Cursor_Default;
		mLight.mNaviType              = 3;
		mLightAct.mNaviType           = 3;
		break;
	}
}

bool efx::TOrimaLight::create(Arg* arg)
{
	switch (mNaviType) {
	case 0:
		mItems[0].mEffectID = PID_OrimaLight_Orima_1;
		mItems[1].mEffectID = PID_OrimaLight_Orima_2;
		break;
	case 1:
		mItems[0].mEffectID = PID_OrimaLight_Loozy_1;
		mItems[1].mEffectID = PID_OrimaLight_Loozy_2;
		break;
	case 2:
		mItems[0].mEffectID = PID_OrimaLight_White_1;
		mItems[1].mEffectID = PID_OrimaLight_White_2;
		break;
	case 3:
		mItems[0].mEffectID = PID_OrimaLight_Purple_1;
		mItems[1].mEffectID = PID_OrimaLight_Purple_2;
		break;
	}
	return TSyncGroup2::create(arg);
}

/*
 * --INFO--
 * Address:	803B69E0
 * Size:	000060
 */
bool efx::TOrimaLightAct::create(Arg* arg)
{
	switch (mNaviType) {
	case 0:
		mItems[0].mEffectID = PID_OrimaLightAct_Orima_1;
		mItems[1].mEffectID = PID_OrimaLightAct_Orima_2;
		break;
	case 1:
		mItems[0].mEffectID = PID_OrimaLightAct_Loozy_1;
		mItems[1].mEffectID = PID_OrimaLightAct_Loozy_2;
		break;
	case 2:
		mItems[0].mEffectID = PID_OrimaLightAct_White_1;
		mItems[1].mEffectID = PID_OrimaLightAct_White_2;
		break;
	case 3:
		mItems[0].mEffectID = PID_OrimaLightAct_Purple_1;
		mItems[1].mEffectID = PID_OrimaLightAct_Purple_2;
		break;
	}
	return TSyncGroup2::create(arg);
}

void BaseGameSection::setCamController()
{
	Navi* navis[4];

	navis[0] = naviMgr->getAt(0);
	navis[1] = naviMgr->getAt(1);
	navis[2] = naviMgr->getAt(2);
	navis[3] = naviMgr->getAt(3);

	if (mPrevNaviIdx > gNaviNum) {
		mPrevNaviIdx = gNaviNum;
	}

	switch (mPrevNaviIdx) {
	case 0: {
		PlayCamera* olimarCam        = mOlimarCamera;
		navis[0]->mCamera            = olimarCam;
		navis[0]->mCamera2           = olimarCam;
		Controller* olimarController = mControllerP1;
		navis[0]->mController1       = olimarController;
		navis[0]->mController2       = olimarController;
		navis[1]->disableController();
		moviePlayer->mTargetNavi   = navis[0];
		moviePlayer->mViewport     = sys->mGfx->getViewport(0);
		moviePlayer->mActingCamera = mOlimarCamera;
		if (!gameSystem->isMultiplayerMode()) {
			PSSetCurCameraNo(0);
			PSPlayerChangeToOrimer();
		}
		break;
	}
	case 1: {
		navis[0]->disableController();
		PlayCamera* louieCam        = mLouieCamera;
		navis[1]->mCamera           = louieCam;
		navis[1]->mCamera2          = louieCam;
		Controller* louieController = mControllerP1;
		navis[1]->mController1      = louieController;
		navis[1]->mController2      = louieController;
		moviePlayer->mTargetNavi    = navis[1];
		moviePlayer->mViewport      = sys->mGfx->getViewport(1);
		moviePlayer->mActingCamera  = mLouieCamera;
		if (!gameSystem->isMultiplayerMode()) {
			PSSetCurCameraNo(1);
			PSPlayerChangeToLugie();
		}
		break;
	}
	case 2: {
		PlayCamera* olimarCam        = mOlimarCamera;
		navis[0]->mCamera            = olimarCam;
		navis[0]->mCamera2           = olimarCam;
		Controller* olimarController = mControllerP1;
		navis[0]->mController1       = olimarController;
		navis[0]->mController2       = olimarController;
		PlayCamera* louieCam         = mLouieCamera;
		navis[1]->mCamera            = louieCam;
		navis[1]->mCamera2           = louieCam;
		Controller* louieController  = mControllerP2;
		navis[1]->mController1       = louieController;
		navis[1]->mController2       = louieController;

		moviePlayer->mTargetNavi   = navis[0];
		moviePlayer->mActingCamera = mOlimarCamera;
		if (gameSystem->mMode == GSM_STORY_MODE) {
			PSSetCurCameraNo(0);
		}
		break;
	}
	case 3: {
		PlayCamera* olimarCam        = mOlimarCamera;
		navis[0]->mCamera            = olimarCam;
		navis[0]->mCamera2           = olimarCam;
		Controller* olimarController = mControllerP1;
		navis[0]->mController1       = olimarController;
		navis[0]->mController2       = olimarController;
		PlayCamera* louieCam         = mLouieCamera;
		navis[1]->mCamera            = louieCam;
		navis[1]->mCamera2           = louieCam;
		Controller* louieController  = mControllerP2;
		navis[1]->mController1       = louieController;
		navis[1]->mController2       = louieController;

		navis[2]->mController1 = gControllerP3;
		navis[2]->mController2 = gControllerP3;
		navis[2]->mCamera      = gCameraP3;
		navis[2]->mCamera2     = gCameraP3;

		moviePlayer->mTargetNavi   = navis[0];
		moviePlayer->mActingCamera = mOlimarCamera;
		if (gameSystem->mMode == GSM_STORY_MODE) {
			PSSetCurCameraNo(0);
		}
		break;
	}
	case 4: {
		PlayCamera* olimarCam        = mOlimarCamera;
		navis[0]->mCamera            = olimarCam;
		navis[0]->mCamera2           = olimarCam;
		Controller* olimarController = mControllerP1;
		navis[0]->mController1       = olimarController;
		navis[0]->mController2       = olimarController;
		PlayCamera* louieCam         = mLouieCamera;
		navis[1]->mCamera            = louieCam;
		navis[1]->mCamera2           = louieCam;
		Controller* louieController  = mControllerP2;
		navis[1]->mController1       = louieController;
		navis[1]->mController2       = louieController;

		navis[2]->mController1 = gControllerP3;
		navis[2]->mController2 = gControllerP3;
		navis[2]->mCamera      = gCameraP3;
		navis[2]->mCamera2     = gCameraP3;

		navis[3]->mController1 = gControllerP4;
		navis[3]->mController2 = gControllerP4;
		navis[3]->mCamera      = gCameraP4;
		navis[3]->mCamera2     = gCameraP4;

		moviePlayer->mTargetNavi   = navis[0];
		moviePlayer->mActingCamera = mOlimarCamera;
		if (gameSystem->mMode == GSM_STORY_MODE) {
			PSSetCurCameraNo(0);
		}
		break;
	}
	}
	on_setCamController(mPrevNaviIdx);
}

static Delegate1<Game::BaseGameSection, Game::CameraArg*>* cameraMgrCallback;

void BaseGameSection::setPlayerMode(int naviIdx)
{
	Navi* fools[4];

	fools[0] = naviMgr->getAt(0);
	fools[1] = naviMgr->getAt(1);
	fools[2] = naviMgr->getAt(2);
	fools[3] = naviMgr->getAt(3);

	fools[0]->disableController();
	fools[1]->disableController();
	fools[2]->disableController();
	fools[3]->disableController();

	switch (naviIdx) {
	case 0: {
		mSecondViewportHeight = 1.0f;
		mSplit                = 0.0f;
		mSplitter->split2(1.0f);
		Matrixf* viewMtx = mLouieCamera->getViewMatrix(false);
		PSMTXCopy((PSQuaternion*)viewMtx, (PSQuaternion*)&mOlimarCamera->mCurViewMatrix);
		mOlimarCamera->update();
		cameraMgr->changePlayerMode(0, cameraMgrCallback);
		if (mPlayerMode == 1) {
			PlayCamera* olimarCamera = mOlimarCamera;
			Graphics* gfx            = sys->mGfx;
			Viewport* olimarViewport = gfx->getViewport(0);
			olimarViewport->mCamera  = olimarCamera;
			olimarViewport->updateCameraAspect();
			PlayCamera* louieCamera = mLouieCamera;
			Viewport* louieViewport = gfx->getViewport(1);
			louieViewport->mCamera  = louieCamera;
			louieViewport->updateCameraAspect();
		}
		Viewport* olimarViewport    = sys->mGfx->getViewport(0);
		sys->mGfx->mCurrentViewport = olimarViewport;
		mLightMgr->updatePosition(sys->mGfx->mCurrentViewport);
		break;
	}
	case 1: {
		if (mPlayerMode == 1) {
			Graphics* gfx            = sys->mGfx;
			PlayCamera* olimarCamera = mLouieCamera;

			Viewport* olimarViewport = gfx->getViewport(0);
			olimarViewport->mCamera  = olimarCamera;
			olimarViewport->updateCameraAspect();

			PlayCamera* louieCamera = mOlimarCamera;
			Viewport* louieViewport = gfx->getViewport(1);
			louieViewport->mCamera  = louieCamera;
			louieViewport->updateCameraAspect();

			mSecondViewportHeight = 1.0f;
			mSplitter->split2(1.0f);
		} else {
			mSecondViewportHeight = 0.0f;
			mSplitter->split2(0.0f);
		}
		mSplit           = 0.0f;
		Matrixf* viewMtx = mOlimarCamera->getViewMatrix(false);
		PSMTXCopy((PSQuaternion*)viewMtx, (PSQuaternion*)&mLouieCamera->mCurViewMatrix);
		mLouieCamera->update();
		cameraMgr->changePlayerMode(1, cameraMgrCallback);
		Viewport* louieViewport     = sys->mGfx->getViewport(1);
		sys->mGfx->mCurrentViewport = louieViewport;
		mLightMgr->updatePosition(sys->mGfx->mCurrentViewport);
		break;
	}
	case 2: {
		mSecondViewportHeight = 0.5f;
		mSplit                = 0.0f;
		mSplitter->split2(0.5f);
		gSplit4 = false;
		cameraMgr->changePlayerMode(2, cameraMgrCallback);
		break;
	}
	case 3:
	case 4: {
		mSecondViewportHeight = 0.5f;
		gOtherViewportHeight  = 0.5f;
		mSplit                = 0.0f;
		gSplit4               = true;
		mSplitter->split4(0.5f, 0.5f);
		cameraMgr->changePlayerMode(4, cameraMgrCallback);
		break;
	}
	}
	mPrevNaviIdx = naviIdx;
}

Vector2f getRectSkew() { return Vector2f(0.0f, -80.0f); }

Vector2f getBottomLeft() { return Vector2f(0.0f, 0.0f); }

void BaseGameSection::initViewports(Graphics& gfx)
{
	mSplitter = new FourSplitter(&gfx);
	// setSplitter(false);

	gCameraP3 = new PlayCamera(naviMgr->getAt(2));
	gCameraP4 = new PlayCamera(naviMgr->getAt(3));

	Viewport* olimarViewport = gfx.getViewport(0);
	olimarViewport->mCamera  = mOlimarCamera;
	olimarViewport->updateCameraAspect();

	Viewport* louieViewport = gfx.getViewport(1);
	louieViewport->mCamera  = mLouieCamera;
	louieViewport->updateCameraAspect();

	Viewport* vp3 = gfx.getViewport(2);
	vp3->mCamera  = gCameraP3;
	vp3->updateCameraAspect();

	Viewport* vp4 = gfx.getViewport(3);
	vp4->mCamera  = gCameraP4;
	vp4->updateCameraAspect();

	shadowMgr->setViewport(gfx.getViewport(0), 0);
	shadowMgr->setViewport(gfx.getViewport(1), 1);
	shadowMgr->setViewport(gfx.getViewport(2), 2);
	shadowMgr->setViewport(gfx.getViewport(3), 3);

	cameraMgr->setViewport(gfx.getViewport(0), 0);
	cameraMgr->setViewport(gfx.getViewport(1), 1);
	cameraMgr->setViewport(gfx.getViewport(2), 2);
	cameraMgr->setViewport(gfx.getViewport(3), 3);

	if (gNaviNum == 3) {
		gFancyCamera = true;
	} else {
		gFancyCamera = false;
	}

	cameraMgr->init(0);
	mTreasureZoomCamera         = new ZoomCamera;
	mTreasureGetViewport        = new Viewport;
	mTreasureGetViewport->mVpId = 4;

	Vector2<u16> screenSize = getScreenSize();
	getScreenSize();
	Vector2f rectSkew   = getRectSkew();
	Vector2f topRight   = Vector2f(rectSkew.x + screenSize.x, rectSkew.y + screenSize.y);
	Vector2f bottomLeft = getBottomLeft() + rectSkew;
	// float moment
	Rectf rect(bottomLeft.x, bottomLeft.y, topRight.x, topRight.y);

	mTreasureGetViewport->setRect(rect);
	mTreasureGetViewport->mCamera = mTreasureZoomCamera;
	mTreasureGetViewport->updateCameraAspect();

	if (gameSystem->isVersusMode()) {
		static_cast<VsGameSection*>(this)->SetupCourseinfo();
	}
}


void BaseGameSection::drawParticle(Graphics& gfx, int viewport)
{
	if (BaseHIOParms::sDrawParticle && gDrawNavi[viewport]) {
		Viewport* port = gfx.getViewport(viewport);
		if (!port || !port->viewable()) {
			return;
		}

		port->setProjection();
		port->setViewport();
		if (!gameSystem->isMultiplayerMode() && mPrevNaviIdx != 2) {
			mLightMgr->mFogMgr->off(gfx);
			particleMgr->draw(port, 0);
			mLightMgr->mFogMgr->set(gfx);
		}
		if (moviePlayer && moviePlayer->mFlags & MoviePlayer::IS_ACTIVE) {
			for (u8 i = 3; i <= 5; i++) {
				particleMgr->draw(port, i);
			}
		}
		particleMgr->draw(port, 1);
		mLightMgr->mFogMgr->off(gfx);
		if (moviePlayer && moviePlayer->mFlags & MoviePlayer::IS_ACTIVE) {
			for (u8 i = 6; i <= 8; i++) {
				particleMgr->draw(port, i);
			}
		}
		particleMgr->draw(port, 2);
	}
}


// hacky as all ass solution
void BaseGameSection::updateSplitter2()
{

	if (mSplitter && gSplit4) {
		mSplitter->split4(mSecondViewportHeight, gOtherViewportHeight);
	} else {
		BaseGameSection::updateSplitter();
	}
}

Navi* NaviMgr::getActiveNavi()
{
	Navi* navis[4];
	navis[0] = getAt(0);
	navis[1] = getAt(1);
	navis[2] = getAt(2);
	navis[3] = getAt(3);
	if (!navis[0] && !navis[1] && !navis[2] && !navis[3]) {
		return nullptr;
	}

	int availableSlots[4];
	availableSlots[0] = 0;

	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (navis[i] && navis[i]->isAlive()) {
			availableSlots[count++] = i;
		}
	}

	return navis[availableSlots[randInt(count)]];
}


// getNearestNavi__Q24Game7NaviMgrFR10Vector3<f>
Navi* NaviMgr::getNearestNavi(Vector3f& pos)
{
	Navi* navis[4];
	navis[0] = getAt(0);
	navis[1] = getAt(1);
	navis[2] = getAt(2);
	navis[3] = getAt(3);
	if (!navis[0] && !navis[1] && !navis[2] && !navis[3]) {
		return nullptr;
	}

	f32 minDist = FLOAT_DIST_MAX;

	int availableSlots[4];

	Navi* navi = nullptr;
	for (int i = 0; i < 4; i++) {
		if (navis[i] && navis[i]->isAlive()) {
			f32 d = sqrDistanceXZ(pos, navis[i]->mPosition3);
			if (d < minDist) {
				minDist = d;
				navi    = navis[i];
			}
		}
	}
	return navi;
}

void ModelEffect::doEntry()
{
	if (mViewportVisibleFlag[0] != 0 || mViewportVisibleFlag[1] != 0 || mViewportVisibleFlag[2] != 0 || mViewportVisibleFlag[3] != 0) {
		mModel->show();
	} else {
		mModel->hide();
	}
	changeMaterial();
	mModel->getJ3DModel()->entry();
}

void ModelEffect::doAnimation()
{
	PSMTXCopy(mMtx.mMatrix.mtxView, mModel->mJ3dModel->mPosMtx);
	mModel->mJ3dModel->calc();

	if (mCulled) {
		for (int i = 0; i < sys->mGfx->mViewportCount; i++) {
			mViewportVisibleFlag[i] = 0;
		}
	} else {
		Sys::Sphere bounds;
		getLODSphere(bounds);

		Graphics* gfx = sys->mGfx;
		for (int i = 0; i < gfx->mViewportCount; i++) {
			Viewport* vp = gfx->getViewport(i);

			if (!vp->viewable()) {
				mViewportVisibleFlag[i] = false;
			} else {
				Camera* cam = vp->mCamera;
				if (useCylinderLOD()) {
					Sys::Cylinder cylinder;
					getLODCylinder(cylinder);
					if (cam->isCylinderVisible(cylinder)) {
						mViewportVisibleFlag[i] = true;
					} else {
						mViewportVisibleFlag[i] = false;
					}
				} else {
					if (cam->isVisible(bounds)) {
						mViewportVisibleFlag[i] = true;
					} else {
						mViewportVisibleFlag[i] = false;
					}
				}
			}
		}
	}
}

void BaseGameSection::setDefaultPSSceneInfo(PSGame::SceneInfo& sceneInfo)
{
	P2ASSERTLINE(3197, mOlimarCamera);
	P2ASSERTLINE(3198, mLouieCamera);
	P2ASSERT(gCameraP3);
	P2ASSERT(gCameraP4);

	sceneInfo.mCameras                     = 4;
	sceneInfo.mCam1Position[NAVIID_Olimar] = mOlimarCamera->getSoundPositionPtr();
	sceneInfo.mCam2Position[NAVIID_Olimar] = mOlimarCamera->getSoundPositionPtr();
	sceneInfo.mCameraMtx[NAVIID_Olimar]    = mOlimarCamera->getSoundMatrixPtr();
	sceneInfo.mCam1Position[NAVIID_Louie]  = mLouieCamera->getSoundPositionPtr();
	sceneInfo.mCam2Position[NAVIID_Louie]  = mLouieCamera->getSoundPositionPtr();
	sceneInfo.mCameraMtx[NAVIID_Louie]     = mLouieCamera->getSoundMatrixPtr();

	if (gCameraP3) {
		sceneInfo.mCam1Position[2] = gCameraP3->getSoundPositionPtr();
		sceneInfo.mCam2Position[2] = gCameraP3->getSoundPositionPtr();
		sceneInfo.mCameraMtx[2]    = gCameraP3->getSoundMatrixPtr();
	}

	if (gCameraP4) {
		sceneInfo.mCam1Position[3] = gCameraP4->getSoundPositionPtr();
		sceneInfo.mCam2Position[3] = gCameraP4->getSoundPositionPtr();
		sceneInfo.mCameraMtx[3]    = gCameraP4->getSoundMatrixPtr();
	}

	BoundBox box;

	mapMgr->getBoundBox(box);

	Vector3f min = box.mMin;
	Vector3f max = box.mMax;

	sceneInfo.mBounds.mMin.x = min.x;
	sceneInfo.mBounds.mMin.y = min.y;
	sceneInfo.mBounds.mMin.z = min.z;
	sceneInfo.mBounds.mMax.x = max.x;
	sceneInfo.mBounds.mMax.y = max.y;
	sceneInfo.mBounds.mMax.z = max.z;
}

void BaseGameSection::doDraw(Graphics& gfx)
{
	captureRadarmap(gfx);
	if (gameSystem->paused()) {
		if (cameraMgr) {
			cameraMgr->controllerLock(CAMNAVI_Both);
			cameraMgr->update();
			cameraMgr->controllerUnLock(CAMNAVI_Both);
		}

	} else if (cameraMgr) {
		cameraMgr->update();
	}

	sys->mTimers->_start("_draw3D_", true);
	draw3D(gfx);
	sys->mTimers->_stop("_draw3D_");
	if (moviePlayer && !gameSystem->mIsMoviePause) {
		moviePlayer->drawLoading(gfx);
	}
	pre2dDraw(gfx);
	gfx.setToken("2d");
	draw2D(gfx);
	if (mDraw2DCreature) {
		drawOtakaraWindow(gfx);
	}
	Screen::gGame2DMgr->drawKanteiMsg(gfx);
	if (moviePlayer && !gameSystem->mIsMoviePause) {
		moviePlayer->draw(gfx);
	}
}


} // namespace Game
