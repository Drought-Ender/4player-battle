#ifndef _EFX_THIBAFIRE_H
#define _EFX_THIBAFIRE_H

#include "efx/TForever.h"

namespace efx {
struct THibaFire : public TForever4 {
	inline THibaFire()
	    : TForever4(PID_HibaFire_1, PID_HibaFire_2, PID_HibaFire_3, PID_HibaFire_4)
	{
	}

	void setRateLOD(int);

	// _00      = VTBL
	// _00-_44  = TForever4
};

struct THibaWater : public TForever4 {
	inline THibaWater()
	    : TForever4(PID_Geyser_UNK_4, PID_Geyser_UNK_5, PID_UNK_89, PID_UNK_8A)
	{
	}

	// _00      = VTBL
	// _00-_44  = TForever4
};

struct THibaLineGas : public TForever4 {
	inline THibaLineGas()
	    : TForever4(PID_GasuHiba_2, PID_GasuHiba_4, PID_GasuHiba_2, PID_GasuHiba_4)
	{
	}


	// _00      = VTBL
	// _00-_44  = TForever4
};

struct THibaSpore : public TForever4 {
	inline THibaSpore()
	    : TForever4(PID_SporeHiba, PID_SporeHiba, PID_SporeHiba, PID_SporeHiba)
	{
	}


	// _00      = VTBL
	// _00-_44  = TForever4
};

} // namespace efx

#endif
