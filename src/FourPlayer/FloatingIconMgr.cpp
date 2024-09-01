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

Vector3f ProjectAsGX(Vector3f in, Mtx44 pm, GXProjectionType type)
{
    f32 wc;

    Vector3f out;

    if (type == GX_ORTHOGRAPHIC) {
        out.x = (in.x * pm[0][0]) + (in.z * pm[0][3]);
        out.y = (in.y * pm[1][1]) + (in.z * pm[1][3]);
        out.z = pm[2][3] + (in.z * pm[2][2]);
        wc = 1.0f / -in.z;
    } else {
        out.x = pm[0][2] + (in.x * pm[0][0]);
        out.y = pm[1][2] + (in.y * pm[1][1]);
        out.z = pm[2][3] + (in.z * pm[2][2]);
        wc = 1.0f;
    }

    out *= wc;
    return out;
}

Vector3f UnProjectAsGX(Vector3f out, Mtx44 pm, GXProjectionType type)
{
    Vector3f in;

    if (type == GX_ORTHOGRAPHIC) {
        

        in.z = -pm[2][3] / (out.z + pm[2][2]);

        out *= -in.z;


        in.x = (out.x - (in.z * pm[0][3])) / pm[0][0];
        in.y = (out.y - (in.z * pm[1][3])) / pm[1][1];

        
    }
    else {
        in.x = (out.x - pm[0][2]) / pm[0][0];
        in.y = (out.y - pm[1][2]) / pm[1][1];
        in.z = (out.z - pm[2][2]) / pm[2][2];
    }

    return in;

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

        
        // cam->mCurViewMatrix;
        // Matrixf viewMtx = setupViewMtx(gfx);


        Matrixf inverseViewMtx;
        PSMTXInverse(cam->mCurViewMatrix.mMatrix.mtxView, inverseViewMtx.mMatrix.mtxView);        

        Vector3f interPos;
        PSMTXMultVec(cam->mCurViewMatrix.mMatrix.mtxView, (Vec*)&pos, (Vec*)&interPos);


        Vector3f screenPos = ProjectAsGX(interPos, cam->mProjectionMtx, GX_ORTHOGRAPHIC);

        if (screenPos.x > 0.95f) {
            screenPos.x = 0.95f;
        }
        else if (screenPos.x < -0.95f) {
            screenPos.x = -0.95f;
        }

        

        if (screenPos.y > 0.9f) {
            screenPos.y = 0.9f;

            screenPos.x *= 0.001f / FABS(screenPos.z);

        }
        else if (screenPos.y < -0.9f) {
            screenPos.y = -0.9f;

            screenPos.x *= 0.001f / FABS(screenPos.z);
        }

        OSReport("old z: %f\n", screenPos.z);

        if (screenPos.z > 0.0f) {
            screenPos.x = -screenPos.x;
            screenPos.y = -screenPos.y;
        }

        screenPos.z = -0.001f;

        
        

        OSReport("Screen Pos : %f %f %f\n", screenPos.x, screenPos.y, screenPos.z);

        OSReport("A : %f %f %f\n", interPos.x, interPos.y, interPos.z);

        interPos = UnProjectAsGX(screenPos, cam->mProjectionMtx, GX_ORTHOGRAPHIC);


        f32 x = interPos.x;
        f32 y = interPos.y;
        f32 z = interPos.z;
        
        // screenPos.y = 0.0f;

        Mtx identity;
        PSMTXIdentity(identity);
        GXLoadPosMtxImm(identity, 0);
        

        OSReport("B : %f %f %f\n", interPos.x, interPos.y, interPos.z);
        
        if (drawOver()) {
            GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
        }
        else {
            GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
        }



        mImg->load(GX_TEXMAP0);
        GXBegin(GX_QUADS, GX_VTXFMT0, 0x4);

        f32 distance = getSize() * 0.5f;

        GXPosition3f32(x + distance, y + distance, z);
        GXTexCoord2f32(0.0f, 0.0f);
        
        GXPosition3f32(x + distance, y - distance, z);
        GXTexCoord2f32(0.0f, 1.0f);

        GXPosition3f32(x - distance, y - distance, z);
        GXTexCoord2f32(1.0f, 1.0f);

        GXPosition3f32(x - distance, y + distance, z);
        GXTexCoord2f32(1.0f, 0.0f);

        GXEnd();

        

        // GXSetProjection(gfx.mPerspGraph.mMtx44, GX_PERSPECTIVE);
        // GXLoadPosMtxImm(gfx.mPerspGraph.mPosMtx, 0);
        
    }
}

} // namespace Game
