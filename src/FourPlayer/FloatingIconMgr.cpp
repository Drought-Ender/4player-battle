#include "FloatingIconMgr.h"
#include "Sys/DrawBuffers.h"
#include "Graphics.h"
#include "Game/Navi.h"
#include "Game/GameLight.h"

#define DEBUG_FILE 0

#if DEBUG_FILE == 0

#define DebugReport(...)


#endif


namespace Game
{

FloatingIconMgr* FloatingIcon::mgr = nullptr;;

FloatingIcon::FloatingIcon(ResTIMG* img, Vector3f* chasePos) {
    DebugReport("FloatingIcon::FloatingIcon(ResTIMG* img, Vector3f* chasePos)\n");
    mImg = new JUTTexture(img);
    mPosition = chasePos;
    mTextureOwner = true;
}

FloatingIcon::FloatingIcon(JUTTexture* img, Vector3f* chasePos) {
    DebugReport("FloatingIcon::FloatingIcon(JUTTexture* img, Vector3f* chasePos)\n");
    mImg = img;
    mPosition = chasePos;
    mTextureOwner = false;
}

FloatingIcon::~FloatingIcon() {
    DebugReport("FloatingIcon::setupViewMtx(Graphics& gfx)\n");
    if (mTextureOwner) {
        delete mImg;
    }
}

f32 FloatingIcon::calcZ(Camera* camera) {
    Vector3f position = camera->getPosition();
    return sqrDistance(*mPosition, position);
}

void FloatingIcon::setupViewMtx(Graphics& gfx) {
    DebugReport("FloatingIcon::setupViewMtx(Graphics& gfx)\n");
    Viewport* vp = gfx.mCurrentViewport;
    J2DPerspGraph* graph = &gfx.mPerspGraph;
    LookAtCamera* cam = vp->mCamera;

    Matrixf ourMtx;
    PSMTXCopy(mgr->mViewMatrix.mMatrix.mtxView, ourMtx.mMatrix.mtxView);

    ourMtx.setTranslation(*mPosition);

    PSMTXConcat(cam->mCurViewMatrix.mMatrix.mtxView, ourMtx.mMatrix.mtxView, graph->mPosMtx);
	GXLoadPosMtxImm(graph->mPosMtx, 0);
}

#define ICON_SIZE (40.0f)

void FloatingIcon::draw(Graphics& gfx) {
    DebugReport("FloatingIcon::draw(Graphics& gfx)\n");
    setupViewMtx(gfx);
    mImg->load(GX_TEXMAP0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 0x4);

    f32 distance = ICON_SIZE / 2;

    GXPosition3f32(-distance, -distance, 0.0f);
    GXTexCoord2f32(0.0f, 0.0f);
    
    GXPosition3f32(-distance, distance, 0.0f);
    GXTexCoord2f32(0.0f, 1.0f);

    GXPosition3f32(distance, distance, 0.0f);
    GXTexCoord2f32(1.0f, 1.0f);

    GXPosition3f32(distance, -distance, 0.0f);
    GXTexCoord2f32(1.0f, 0.0f);
}

void FloatingIconMgr::setupViewMtx(Graphics& gfx) {
    DebugReport("FloatingIconMgr::setupViewMtx(Graphics& gfx)\n");
	LookAtCamera* cam = gfx.mCurrentViewport->mCamera;

	PSMTXIdentity(mViewMatrix.mMatrix.mtxView);
	float magnitude = 0.8f;

	Mtx& mtxTo = mViewMatrix.mMatrix.mtxView;

	Mtx& mtxFrom = cam->mCurViewMatrix.mMatrix.mtxView;


	mtxTo[0][0] = mtxFrom[0][0] * magnitude;
	mtxTo[1][0] = mtxFrom[0][1] * magnitude;
	mtxTo[2][0] = mtxFrom[0][2] * magnitude;

	mtxTo[0][1] = mtxFrom[1][0] * -magnitude;
	mtxTo[1][1] = mtxFrom[1][1] * -magnitude;
	mtxTo[2][1] = mtxFrom[1][2] * -magnitude;

	mtxTo[0][2] = mtxFrom[2][0] * magnitude;
	mtxTo[1][2] = mtxFrom[2][1] * magnitude;
	mtxTo[2][2] = mtxFrom[2][2] * magnitude;
}

bool FloatingIconMgr::sDrawOptimize = false;

void FloatingIconMgr::draw(Graphics& gfx) {
    DebugReport("FloatingIconMgr::draw(Graphics& gfx)\n");
    J2DPerspGraph* graph = &gfx.mPerspGraph;
	Matrixf mtxBackup = graph->mPosMtx;
    LookAtCamera* cam = gfx.mCurrentViewport->mCamera;

    // gameSystem->mSection->mLightMgr->mFogMgr->set(gfx);

    GXSetCullMode(GX_CULL_NONE);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_F32, 0);

    // goofy tevcolor
    

    // magic perspective sauce
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
	GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetColorUpdate(GX_TRUE);
    
	// GXSetZCompLoc(GX_TRUE);


    setupViewMtx(gfx);

    if (sDrawOptimize) {
        FOREACH_NODE(FloatingIcon, mChild, node) {
            node->draw(gfx);
        }
    }
    else {
        int count = getChildCount();

        FloatingIcon** icons = new FloatingIcon*[count];
        f32* distances = new f32[count];
        
        int idx = 0;

        FOREACH_NODE(FloatingIcon, mChild, node) {
            distances[idx] = node->calcZ(cam);
            icons[idx] = node;
            idx++;
        }

        for (int i = 0; i < count; i++) {
            int minIdx = 0;
            f32 maxDistance = 0;

            for (int j = 0; j < count; j++) {
                if (icons[j] && distances[j] > maxDistance) {
                    minIdx = j;
                    maxDistance = distances[j];
                }
            }

            icons[minIdx]->draw(gfx);
            icons[minIdx] = nullptr;
        }


        delete[] icons;
        delete[] distances;
    }

    // gameSystem->mSection->mLightMgr->mFogMgr->off(gfx);
	
    PSMTXCopy(mtxBackup.mMatrix.mtxView, graph->mPosMtx);
	GXLoadPosMtxImm(graph->mPosMtx, 0);
	
}

void FloatingIconMgr::add(FloatingIcon* icon) {
    DebugReport("FloatingIconMgr::add(FloatingIcon* icon)\n");
    FloatingIcon::mgr->CNode::add(icon);
}

void FloatingIconMgr::del(FloatingIcon* icon) {
    DebugReport("FloatingIconMgr::del(FloatingIcon* icon)\n");
    icon->del();
}

void FloatingIconMgr::create() {
    DebugReport("FloatingIconMgr::create()\n");
    FloatingIcon::mgr = new FloatingIconMgr;
}

void FloatingIconMgr::destroy() {
    DebugReport("FloatingIconMgr::destroy()\n");
    if (FloatingIcon::mgr) {
        delete FloatingIcon::mgr;
        FloatingIcon::mgr = nullptr;
    }
}

} // namespace Game
