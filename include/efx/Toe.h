#ifndef _EFX_TOE_H
#define _EFX_TOE_H

#include "efx/Context.h"
#include "JSystem/JSupport/JSUList.h"
#include "Vector3.h"

// yes, most of these have size 1 arrays. take it up with the devs.

namespace efx {

// this struct needs to exist for the dtor to generate properly
struct TOEContextBase : public JSUPtrLink
{
	TOEContextBase(void* data) : JSUPtrLink(data) {}
};


struct TOEContextS : public TOEContextBase {
	TOEContextS() : TOEContextBase(this) { }

	~TOEContextS() { };
	
	Vector3f mPosition; // _10

	// _00-_10 = JSUPtrLink
	
};

struct ToeChudoku {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContext;
};

struct ToeDoping {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContext;
};

struct ToeHamonA {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContext;
};

struct ToeHamonB {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContext;
};

struct ToeKourin {

	void create(Vector3f*, long);
	void kill();

	ContextChasePos mContext;
	long mPikiKind;
};

struct ToeMoeBC {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContexts[2];
};

struct ToeMoeSmoke {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContext;
};

struct ToeNagekira {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContext;
};

struct ToeTanekira {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContext;
};

struct ToeWater {

	void create(Vector3f*);
	void kill();

	ContextChasePos mContexts[2];
};

struct ToeSpore {
	void create(Vector3f*);
	void kill();

	ContextChasePos mContext;
};

int size = sizeof(ToeSpore);

} // namespace efx

#endif
