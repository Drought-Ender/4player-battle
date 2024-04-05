#include "FloatingIconMgr.h"
#include "Sys/DrawBuffers.h"
#include "Graphics.h"
#include "Game/Navi.h"
#include "Game/GameLight.h"
#include "efx/TOta.h"

#define DEBUG_FILE 0

#if DEBUG_FILE == 0

#define DebugReport(...)


#endif


namespace Game
{

FloatingIconMgr* FloatingIcon::mgr = nullptr;

bool FloatingIconMgr::sDrawOptimize = false;

bool FloatingIconMgr::sIsEnabled = true;

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

void FloatingIconMgr::draw(Graphics& gfx) {
    DebugReport("FloatingIconMgr::draw(Graphics& gfx)\n");
    J2DPerspGraph* graph = &gfx.mPerspGraph;
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
            if (node->satisfy()) {
                node->draw(gfx);
            }
        }
    }
    else {
        int totalCount = getChildCount();

        FloatingIcon** icons = new FloatingIcon*[totalCount];
        f32* distances = new f32[totalCount];
        
        int count = 0;

        FOREACH_NODE(FloatingIcon, mChild, node) {
            if (node->satisfy()) {
                distances[count] = node->calcZ(cam);
                icons[count] = node;
                count++;
            }
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
	
	GXLoadPosMtxImm(graph->mPosMtx, 0);

	
}

void FloatingIconMgr::add(FloatingIcon* icon) {
    DebugReport("FloatingIconMgr::add(FloatingIcon* icon)\n");
    if (FloatingIcon::mgr) {
        FloatingIcon::mgr->CNode::add(icon);
    }
}

void FloatingIconMgr::del(FloatingIcon* icon) {
    DebugReport("FloatingIconMgr::del(FloatingIcon* icon)\n");
    if (FloatingIcon::mgr) {
        icon->del();
    }
}

void FloatingIconMgr::create() {
    DebugReport("FloatingIconMgr::create()\n");
    if (sIsEnabled) {
        FloatingIcon::mgr = new FloatingIconMgr;
    }
}

void FloatingIconMgr::destroy() {
    DebugReport("FloatingIconMgr::destroy()\n");
    if (FloatingIcon::mgr) {
        delete FloatingIcon::mgr;
        FloatingIcon::mgr = nullptr;
    }
}


FloatingIcon::FloatingIcon(JUTTexture* img, Vector3f* chasePos) {
    DebugReport("FloatingIcon::FloatingIcon(JUTTexture* img, Vector3f* chasePos)\n");
    mImg = img;
    mPosition = chasePos;
}

FloatingIcon::~FloatingIcon() {
    DebugReport("FloatingIcon::setupViewMtx(Graphics& gfx)\n");
}

Vector3f FloatingIcon::getPosition() {
    return *mPosition;
}

f32 FloatingIcon::calcZ(Camera* camera) {
    Vector3f position = camera->getPosition();
    Vector3f ourPos = getPosition();
    return sqrDistance(ourPos, position);
}

Matrixf FloatingIcon::setupViewMtx(Graphics& gfx) {
    DebugReport("FloatingIcon::setupViewMtx(Graphics& gfx)\n");
    Viewport* vp = gfx.mCurrentViewport;
    J2DPerspGraph* graph = &gfx.mPerspGraph;
    LookAtCamera* cam = vp->mCamera;

    if (drawOver()) {
        GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
    }
    else {
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    }

    Matrixf ourMtx;
    PSMTXCopy(mgr->mViewMatrix.mMatrix.mtxView, ourMtx.mMatrix.mtxView);

    Vector3f pos = getPosition();

    ourMtx.setTranslation(pos);

    Matrixf outMtx;

    PSMTXConcat(cam->mCurViewMatrix.mMatrix.mtxView, ourMtx.mMatrix.mtxView, outMtx.mMatrix.mtxView);
	GXLoadPosMtxImm(outMtx.mMatrix.mtxView, 0);
    return outMtx;
}

#define ICON_SIZE (40.0f)

f32 FloatingIcon::getSize() {
    return ICON_SIZE;
}

void FloatingIcon::draw(Graphics& gfx) {
    DebugReport("FloatingIcon::draw(Graphics& gfx)\n");
    setupViewMtx(gfx);
    mImg->load(GX_TEXMAP0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 0x4);

    f32 distance = getSize() * 0.5f;

    GXPosition3f32(-distance, -distance, 0.0f);
    GXTexCoord2f32(0.0f, 0.0f);
    
    GXPosition3f32(-distance, distance, 0.0f);
    GXTexCoord2f32(0.0f, 1.0f);

    GXPosition3f32(distance, distance, 0.0f);
    GXTexCoord2f32(1.0f, 1.0f);

    GXPosition3f32(distance, -distance, 0.0f);
    GXTexCoord2f32(1.0f, 0.0f);
}

HoveringFloatingIcon::HoveringFloatingIcon(JUTTexture* tex, Vector3f* vec, f32 yoffs)
    : mYOffset(yoffs), FloatingIcon(tex, vec)
{
}

Vector3f HoveringFloatingIcon::getPosition() {
    return Vector3f(mPosition->x, mPosition->y + mYOffset, mPosition->z);
}

bool OnyonFloatingIcon::satisfy() {
    return true;
    Vector3f naviPos = naviMgr->getAt(sys->mGfx->mCurrentViewport->mVpId)->getPosition();
    return sqrDistanceXZ(naviPos, *mPosition) > SQUARE(100.0f);
}

void OnyonFloatingIcon::draw(Graphics& gfx) {
    Viewport* vp = gfx.mCurrentViewport;
    LookAtCamera* cam = vp->mCamera;
    Vector3f pos = getPosition();
    Sys::Sphere viewSphere (pos, getSize());
    // if (cam->isVisible(viewSphere)) {
    //     HoveringFloatingIcon::draw(gfx);
    //     return;
    // }
    // else {

    {
        if (vp->mVpId != 0) return;

        Vector3f camPos = cam->getPosition();

        // Vector3f oldDelta = camPos - pos;
        

        // // if the icon is behind us, put it infront of us
        // f32 atans = pikmin2_atan2f(oldDelta.x, oldDelta.z);

        // Vector3f targetDelta = camPos - cam->getLookAtPosition();

        // f32 theta = pikmin2_atan2f(targetDelta.x, targetDelta.z);

        // OSReport("theta %f, atans %f\n", theta, atans);

        bool flipAfter = false;
        
        // if (FABS(angDist(theta, atans)) > PI / 2) {
            
        //     flipAfter = true;
        // }

        

        Matrixf ourMtx;
        PSMTXCopy(mgr->mViewMatrix.mMatrix.mtxView, ourMtx.mMatrix.mtxView);


        Vector3f newPos = DroughtLib::ForceIntoCullPlanes(viewSphere, cam, flipAfter);

        efx::TOtaFire fire;
        efx::Arg ag(newPos);

        fire.create(&ag);

        

        Vector3f delta = newPos - camPos;
        delta.normalise();
        // newPos = camPos + delta * 1000.0f;

        if (flipAfter) {
           
        }

        ourMtx.setTranslation(newPos);

        Matrixf outMtx;

        PSMTXConcat(cam->mCurViewMatrix.mMatrix.mtxView, ourMtx.mMatrix.mtxView, outMtx.mMatrix.mtxView);
        

        // Vector3f pureScreenCords = screenCords - Vector3f(vp->mRect2.p2.x, vp->mRect2.p2.y, 0.0f);

        // Vector2f vec2ScreenCords = Vector2f(screenCords.x / vp->mRect2.getWidth(), screenCords.y / vp->mRect2.getHeight());

        // vec2ScreenCords.normalise(); // force onto screen

        // Vector3f newScreenCords = Vector3f(
        //     vec2ScreenCords.x * vp->mRect2.getWidth() + vp->mRect2.p2.x,
        //     vec2ScreenCords.y * vp->mRect2.getHeight() + vp->mRect2.p2.y,
        //     0.0f  
        // );

        // GXSetProjection(gfx.mOrthoGraph.mMtx44, GX_ORTHOGRAPHIC);
        
        GXLoadPosMtxImm(outMtx.mMatrix.mtxView, 0);

        if (drawOver()) {
            GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
        }
        else {
            GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
        }



        mImg->load(GX_TEXMAP0);
        GXBegin(GX_QUADS, GX_VTXFMT0, 0x4);

        f32 distance = getSize() * 0.5f;

        GXPosition3f32(- distance, - distance, 0.0f);
        GXTexCoord2f32(0.0f, 0.0f);
        
        GXPosition3f32(- distance, distance, 0.0f);
        GXTexCoord2f32(0.0f, 1.0f);

        GXPosition3f32( distance, distance, 0.0f);
        GXTexCoord2f32(1.0f, 1.0f);

        GXPosition3f32(distance, - distance, 0.0f);
        GXTexCoord2f32(1.0f, 0.0f);

        // GXSetProjection(gfx.mPerspGraph.mMtx44, GX_PERSPECTIVE);
        // GXLoadPosMtxImm(gfx.mPerspGraph.mPosMtx, 0);
        
    }
}

} // namespace Game
