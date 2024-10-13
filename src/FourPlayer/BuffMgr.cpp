#include "Game/BuffMgr.h"
#include "Graphics.h"
#include "VsOptions.h"
#include "FourPlayer.h"

namespace Game
{

BuffMgr* naviBuffMgr = nullptr;

void BuffMgr::init() {
    naviBuffMgr = new BuffMgr;
    naviBuffMgr->setupResources();
    naviBuffMgr->setInitialBuff();
}

void BuffMgr::setupResources() {
    JKRArchive* rarc = JKRArchive::mount("/user/Drought/vstex/buffTex.szs", JKRArchive::EMM_Mem, nullptr, JKRArchive::EMD_Head);
    JUT_ASSERT(rarc, "BuffTex Missing!\n");
    PluckSpeedBuff::load(rarc);
}

void BuffMgr::setInitialBuff() {

    if (gConfig[AUTO_BALENECE] == ConfigEnums::AUTOBALANCE_OFF) {
        return;
    }

    u8 teamCounts[4] = { 0, 0, 0, 0 };

    for (int i = 0; i < gNaviNum; i++) {
        teamCounts[getVsTeam(i)]++;
    }


    int highest = 0;
    for (int i = 0; i < gNaviNum; i++) {
        if (teamCounts[i] > teamCounts[highest]) {
            highest = i;
        }
    }



    for (u8 team = 0; team < 4; team++) {
        u8 discrepency = teamCounts[highest] - teamCounts[team];

        if (discrepency > 0) {
            u8 buffID = gConfig[AUTO_BALENECE] + discrepency - 2;

            for (u8 naviID = 0; naviID < gNaviNum; naviID++) {
                if (getVsTeam(naviID) == team) {
                    addBuff(new PluckSpeedBuff(buffID), naviID);
                }
            }
        }
    }


}

void BuffMgr::addBuff(NaviBuffBase* buff, u8 naviID) {
    mBuffData[naviID].mContainer.add(buff);
}


void BuffMgr::draw(Graphics& gfx) {
    for (u8 vp = 0; vp < 4; vp++) {
        if (gDrawNavi[vp]) {
            mBuffData[vp].draw(vp, gfx);
        }
    }
}

void NaviBuffData::draw(u8 vp, Graphics& gfx) {
    u32 slotID = 0;
    FOREACH_NODE(NaviBuffBase, mContainer.mChild, node) {
        node->setupDraw(gfx);
        Matrixf mtx = node->setupMtx(vp, gfx, slotID);
        GXLoadPosMtxImm(mtx.mMatrix.mtxView, 0);
        node->draw(gfx);
    }
}

void NaviBuffBase::setupDraw(Graphics& gfx) {
    gfx.initPrimDraw(nullptr);
    gfx.mOrthoGraph.setPort();

    GXSetCullMode(GX_CULL_NONE);
    GXClearVtxDesc();
    GXSetColorUpdate(GX_TRUE);
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_F32, 0);

    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);

    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEXCOORD0, 0x3c, 0, 0x7d);

    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
	GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
	GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1, GX_TEVPREV);
	GXSetTevAlphaIn(GX_TEVSTAGE0, GX_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_ZERO);
	GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1, GX_TEVPREV);

    GXSetChanAmbColor(GX_COLOR0A0, (GXColor) { 0x14, 0x14, 0x14, 0x80 });
	GXSetChanMatColor(GX_COLOR0A0, (GXColor) { 0xff, 0xff, 0xff, 0xca });
}


Matrixf NaviBuffBase::setupMtx(u8 vpidx, Graphics& gfx, u32 slotID) {
    Matrixf mtx = gfx.mOrthoGraph.mPosMtx;
    Viewport* vp = gfx.getViewport(vpidx);

    f32 x = vp->mRect1.p2.x - 20.0f - 20.0f * slotID;
    f32 y = vp->mRect1.p1.y + 20.0f;

    // Matrixf* matrix = vp->getMatrix(true);

    Vector3f pos (x, y, 0.0f);

    mtx.setTranslation(pos);

    return mtx;

}

void NaviBuffBase::draw(Graphics& gfx) {

    OSReport("Draw Buff %s\n", getName());

    JUTTexture* tex = getTexture();
    P2ASSERT(tex);
    tex->load(GX_TEXMAP0);
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, 0x4);

    GXPosition3f32(-10.0f, -10.0f, 0.0f);
    GXTexCoord2f32(0.0f, 0.0f);
    
    GXPosition3f32(10.0f, -10.0f, 0.0f);
    GXTexCoord2f32(1.0f, 0.0f);

    GXPosition3f32(-10.0f, 10.0f, 0.0f);
    GXTexCoord2f32(0.0f, 1.0f);

    GXPosition3f32(10.0f, 10.0f, 0.0f);
    GXTexCoord2f32(1.0f, 1.0f);
    GXEnd();
}

PluckSpeedBuff::PluckSpeedBuff(u8 v) : mType(v) {
    P2ASSERT(0 <= mType && mType < 3);
    mAnimationTimer = 0.0f;
}


JUTTexture* PluckSpeedBuff::sTextureOnePointFive;
JUTTexture* PluckSpeedBuff::sTextureTwo;
JUTTexture* PluckSpeedBuff::sTextureThree;

JUTTexture* PluckSpeedBuff::getTexture() {
    switch (mType)
    {
    case WEAK:
        return sTextureOnePointFive;
    case MED:
        return sTextureTwo;
    case STRONG:
        return sTextureThree;
    }
}


void PluckSpeedBuff::load(JKRArchive* rarc) {
    sTextureOnePointFive = new JUTTexture((ResTIMG*)rarc->getResource("pluck_15.bti"));
    sTextureTwo          = new JUTTexture((ResTIMG*)rarc->getResource("pluck_20.bti"));
    sTextureThree        = new JUTTexture((ResTIMG*)rarc->getResource("pluck_30.bti"));
}

void BuffMgr::update() {
    for (int i = 0; i < 4; i++) {
        mBuffData[i].update();
    }
}

void NaviBuffData::update() {
    FOREACH_NODE(NaviBuffBase, mContainer.mChild, node) {
        node->update();
    }
}

f32 PluckSpeedBuff::getSpeedBuff() {
    switch (mType)
    {
    case WEAK:
        return 1.5f;
    case MED:
        return 2.0f;
    case STRONG:
        return 3.0f;
    }
    return 1.0f;
}

void PluckSpeedBuff::update() {
    mAnimationTimer += getSpeedBuff() * sys->mDeltaTime * 0.5f;
}

#define SQUASH_FACTOR (1.2f)

void PluckSpeedBuff::draw(Graphics& gfx) {
    

    const f32 sinCoefficent = (SQUASH_FACTOR - 1 / SQUASH_FACTOR) / 2;
    const f32 sinIntercept  = (SQUASH_FACTOR + 1 / SQUASH_FACTOR) / 2;

    f32 stretch = sinCoefficent * sinf(TAU * mAnimationTimer) + sinIntercept;

    JUTTexture* tex = getTexture();
    P2ASSERT(tex);
    tex->load(GX_TEXMAP0);
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, 0x4);

    GXPosition3f32(-10.0f * stretch, -10.0f / stretch, 0.0f);
    GXTexCoord2f32(0.0f, 0.0f);
    
    GXPosition3f32(10.0f * stretch, -10.0f / stretch, 0.0f);
    GXTexCoord2f32(1.0f, 0.0f);

    GXPosition3f32(-10.0f * stretch, 10.0f / stretch, 0.0f);
    GXTexCoord2f32(0.0f, 1.0f);

    GXPosition3f32(10.0f * stretch, 10.0f / stretch, 0.0f);
    GXTexCoord2f32(1.0f, 1.0f);
    GXEnd();

}

} // namespace Game
