#ifndef _VIEWPORT_H
#define _VIEWPORT_H

#include "Rect.h"
#include "types.h"
#include "CNode.h"

struct Camera;
struct LookAtCamera;
struct J2DGrafContext;
struct J2DOrthoGraph;
struct Matrixf;
struct CNode;

namespace SysShape {
struct Model;
} // namespace SysShape

struct Viewport : CNode {
	Viewport();

	virtual ~Viewport(); // _08 (weak)

	void draw2dframe(J2DGrafContext&);
	void getAspect();
	Matrixf* getMatrix(bool);
	void refresh();
	SysShape::Model* setJ3DViewMtx(bool);
	void setOrthoGraph2d(J2DOrthoGraph&);
	void setProjection();
	void setRect(Rectf&);
	void setViewport();
	void updateCameraAspect();
	bool viewable();

	u16 mVpId;             // _18
	u8 _1A;                // _1A
	u8 _1B;                // _1B
	Rectf mRect1;          // _1C
	Rectf mRect2;          // _1C
	s8 mFlags;             // _3C
	Matrixf* mViewMat;     // _40
	LookAtCamera* mCamera; // _44
	Rectf mViewportScale;  // _48
};

#endif
