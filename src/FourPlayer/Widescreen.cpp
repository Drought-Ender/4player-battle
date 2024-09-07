#include "VsOptions.h"
#include "Camera.h"


bool gWidescreenActive = false;

static f32 sWidescreenConstant = 1.333333f; // 4:3 to 16:9

void CullFrustum::updatePlanes()
{
	Matrixf outMat;
	Vec temp;

	Vector3f row1 = getSideVector();
	Vector3f row2 = getUpVector();

	Vector3f posVec = getPosition();

	f32 viewAngle = PI * (mViewAngle / 360.0f);

    f32 aspectRatio = (gWidescreenActive) ? mAspectRatio * sWidescreenConstant : mAspectRatio;

	f32 fovAngle  = (f32)atan(aspectRatio * (f32)tan(viewAngle));

	PSMTXRotAxisRad(outMat.mMatrix.mtxView, (Vec*)&row1, (PI - viewAngle));
	PSMTXMultVec(outMat.mMatrix.mtxView, (Vec*)&row2, &temp);
	mObjects[0].updatePlane(posVec, temp);

	PSMTXRotAxisRad(outMat.mMatrix.mtxView, (Vec*)&row1, (viewAngle));
	PSMTXMultVec(outMat.mMatrix.mtxView, (Vec*)&row2, &temp);
	mObjects[1].updatePlane(posVec, temp);

	PSMTXRotAxisRad(outMat.mMatrix.mtxView, (Vec*)&row2, (-fovAngle));
	PSMTXMultVec(outMat.mMatrix.mtxView, (Vec*)&row1, &temp);
	mObjects[2].updatePlane(posVec, temp);

	PSMTXRotAxisRad(outMat.mMatrix.mtxView, (Vec*)&row2, (PI + fovAngle));
	PSMTXMultVec(outMat.mMatrix.mtxView, (Vec*)&row1, &temp);
	mObjects[3].updatePlane(posVec, temp);
}

void ParticleMgr::draw(Viewport* vp, u8 flag)
{
	f32 x, y;
	y = vp->mCamera->mAspectRatio * (gWidescreenActive) ? sWidescreenConstant : 1.0f;
	x = vp->mCamera->mViewAngle;
	JPADrawInfo info;
	PSMTXCopy(vp->getMatrix(1)->mMatrix.mtxView, info.mtx1);
	C_MTXLightPerspective(info.mtx2, x, y, 0.5f, -0.5f, 0.5f, 0.5f);
	mEmitterManager->draw(&info, flag);
}

void Camera::setProjection()
{
	f32 far       = getFar();
	Mtx44* matrix = &mProjectionMtx;
	f32 near      = getNear();

	C_MTXPerspective(*matrix, mViewAngle, mAspectRatio * (gWidescreenActive) ? sWidescreenConstant : 1.0f, near, far);
	GXSetProjection(mProjectionMtx, GX_PERSPECTIVE);
}

void P2DScreen::Mgr_tuning::draw(Graphics& gfx, J2DGrafContext& context)
{
	u16 frameBufferWidth  = System::getRenderModeObj()->fbWidth;
	u16 frameBufferHeight = System::getRenderModeObj()->efbHeight;

	rotate(frameBufferWidth * 0.5f * (gWidescreenActive) ? sWidescreenConstant : 1.0f, frameBufferHeight * 0.5f, J2DROTATE_Z, 0.0f);
	updateScale(mScreenScaleX, mScreenScaleY);
	setOffset(mSomeX, mSomeY);

	Mgr::draw(gfx, context);
}


