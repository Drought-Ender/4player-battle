#ifndef _VIEWPORT_H
#define _VIEWPORT_H

#include "Rect.h"
#include "types.h"

struct Camera;
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

	u16 m_vpId;         // _18
	u8 _1A;             // _1A
	u8 _1B;             // _1B
	Rectf m_vpRect1;	// _1C
	Rectf m_vpRect2;	// _2C
	s8 m_flags;         // _3C
	Matrixf* m_viewMat; // _40
	Camera* m_camera;   // _44
	Rectf m_vpScale;	// _48
};

#endif
