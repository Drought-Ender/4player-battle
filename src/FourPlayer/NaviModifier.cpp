#include "Game/Navi.h"
#include "Game/NaviState.h"
#include "Game/MoviePlayer.h"
#include "PSM/Navi.h"
#include "Game/NaviParms.h"

namespace Game
{
    void Navi::onKill(CreatureKillArg* arg) {
        killFakePiki();
	    mEffectsObj->killLight();
    }

    void Navi::MakePellet() {
        transit(NSID_Walk, nullptr);
        PelletViewArg carcassArg;
        Vector3f pos          = getPosition();
        carcassArg.mEnemyName = "orima";
        carcassArg.mPosition  = pos;
        carcassArg.mMatrix    = &mObjMatrix;
        carcassArg.mEnemy     = this;
        becomePellet(&carcassArg);
        setAtari(false);
        startMotion(IPikiAnims::DEAD, IPikiAnims::DEAD, this, nullptr);
    }

    void Navi::setDeadLaydown()
    {
        if (mNaviIndex < gNaviNum && isAlive() && gConfig[CAPTAIN_CORPSE] == ConfigEnums::COPRSE_ON) {
            mIsAlive = false;
            MakePellet();
        } else {
            mIsAlive = true;
        }
        setAlive(false);
        naviMgr->informOrimaDead(mNaviIndex);
        mHealth = 0.0f;
        mEffectsObj->killLight();
    }

    void Navi::SetRevive(int color) {
        
        setAlive(true);
        setAtari(true);
        naviMgr->informOrimaLive(mNaviIndex);
        mIsAlive = false;
        mHealth = static_cast<NaviParms*>(mParms)->mNaviParms.mMaxHealth;
        gDrawNavi[mNaviIndex] = true;
        gVsNaviIndexArray[mNaviIndex] = color;

        mEffectsObj->setNaviType((efx::TNaviEffect::enumNaviType)getVsTeam());
        mEffectsObj->createLight();

        transit(NSID_Walk, nullptr);
    }

    void NaviMgr::informOrimaLive(int idx) {
        int naviIdx = 0;
        for (int i = 0; i < mNaviCount; i++) {
            if (mNaviIndexArray[idx] == i) {
                naviIdx = i;
            }
        }

        for (int i = naviIdx + 1; i < mNaviCount; i++) {
            mNaviIndexArray[i - 1] = mNaviIndexArray[i];
        }

        mNaviIndexArray[mNaviCount] = -1;

        mNaviCount--;
    }

    void Navi::doEntry()
    {
        FakePiki::doEntry();
        if (!isAlive() && mIsAlive) {
            RESET_FLAG(mLod.mFlags, 0xF4);
        }

        if (mController1 == nullptr)  {
            return;
        }

        mCursorMatAnim->animate(10.0f);
        mArrowMatAnim->animate(0.0f);

        if (!isControlFlag(NAVICTRL_InMovie)) {
            if (moviePlayer->mFlags & MoviePlayer::IS_ACTIVE) {
                mMarkerModel->hide();
            } else {
                mMarkerModel->show();
            }

            mMarkerModel->mJ3dModel->entry();
        }

        J3DGXColorS10 cursorCols;
        if (mNextThrowPiki) {
            Color4& col  = Piki::pikiColorsCursor[mNextThrowPiki->getKind()];
            cursorCols.r = col.r;
            cursorCols.g = col.g;
            cursorCols.b = col.b;
            cursorCols.a = col.a;
        } else {
            cursorCols.r = 255;
            cursorCols.g = 255;
            cursorCols.b = 255;
            cursorCols.a = 255;
        }

        J3DMaterial* materials = mCursorModel->mJ3dModel->mModelData->mMaterialTable.mMaterials[0];
        if (materials) {
            materials->mTevBlock->setTevColor(0, cursorCols);
            mCursorModel->mJ3dModel->calcMaterial();
            mCursorModel->mJ3dModel->diff();
        }

        if (!isControlFlag(NAVICTRL_InMovie)) {
            if (moviePlayer->mFlags & MoviePlayer::IS_ACTIVE) {
                mCursorModel->hide();
            } else {
                mCursorModel->show();
            }

            mCursorModel->mJ3dModel->entry();
        }
    }
} // namespace Game
