#include "efx/TSimple.h"

namespace efx
{

struct ArgBarrier : public Arg {
	ArgBarrier(Vector3f& position)
	    : Arg(position)
	{
	}

    ArgBarrier(Vector3f& position, int color)
	    : Arg(position)
        , mVsHibaColor(color)
	{
	}

	virtual const char* getName() // _08 (weak)
	{
		return "ArgVsBarrier";
	}

	// _00     = VTBL
	// _00-_10 = Arg
	int mVsHibaColor;    // _28
};

struct TBarrier : public TSimple3 {
	inline TBarrier()
	    : TSimple3(PID_OtaElec_1, PID_OtaElec_2, PID_OtaElec_3)
	{
	}

    virtual bool create(Arg*);
	// _00      = VTBL
	// _00-_18  = TSimple3
};

} // namespace efx
