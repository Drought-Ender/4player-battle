#ifndef _DOLPHIN_MATH_H
#define _DOLPHIN_MATH_H

#include "types.h"
#include "fdlibm.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

#ifndef __MWERKS__
// Get clangd to shut up about __fabs being undefined.
#define __fabs(x)    (x)
#define __frsqrte(x) (x)
#endif

#define FABS(x) (float)__fabs(x)
#define fabs(x) __fabs(x)
// #define __frsqrtes opword

#define SQUARE(v)                      ((v) * (v))
#define IS_WITHIN_CIRCLE(x, z, radius) ((SQUARE(x) + SQUARE(z)) < SQUARE(radius))

#define VECTOR_SQUARE_MAG(v) (SQUARE(v.x) + SQUARE(v.y) + SQUARE(v.z))

#define LONG_TAU   6.2831854820251465
#define TAU        6.2831855f
#define PI         3.1415927f
#define HALF_PI    1.5707964f
#define THIRD_PI   1.0471976f
#define QUARTER_PI 0.7853982f

#define SIN_2_5 0.43633234f

#define DEG2RAD (1.0f / 180.0f)
#define RAD2DEG (180.0f / PI)

#define TORADIANS(degrees) (PI * (DEG2RAD * degrees))
#define TODEGREES(radians) (RAD2DEG * radians)

f64 cos(f64);
f32 cosf(f32);
f64 sin(f64);
f32 sinf(f32);
f64 tan(f64);
f32 tanf(f32);
f64 atan(f64);
f64 atan2(f64, f64);

/**
 * kludges for emulating inlined f versions of funcs.
 * Replace these with tanf/sinf/cosf once we have library support in the build chain.
 * If my theory is correct, those functions will become inlined by code using libDolphin as a library.
 */
inline f32 tanf_kludge(f32 __x) { return tan((f64)__x); }
inline f32 sinf_kludge(f32 __x) { return sin((f64)__x); }
inline f32 cosf_kludge(f32 __x) { return cos((f64)__x); }

f64 ceil(f64);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

inline int __fpclassifyf(f32 x)
{
	switch ((*(s32*)&x) & 0x7f800000) {
	case 0x7f800000: {
		if ((*(s32*)&x) & 0x007fffff)
			return 1;
		else
			return 2;
		break;
	}
	case 0: {
		if ((*(s32*)&x) & 0x007fffff)
			return 5;
		else
			return 3;
		break;
	}
	}
	return 4;
}
inline int __fpclassifyd(f64 x)
{
	switch (__HI(x) & 0x7ff00000) {
	case 0x7ff00000: {
		if ((__HI(x) & 0x000fffff) || (__LO(x) & 0xffffffff))
			return 1;
		else
			return 2;
		break;
	}
	case 0: {
		if ((__HI(x) & 0x000fffff) || (__LO(x) & 0xffffffff))
			return 5;
		else
			return 3;
		break;
	}
	}
	return 4;
}

#define fpclassify(x) ((sizeof(x) == sizeof(f32)) ? __fpclassifyf((f32)(x)) : __fpclassifyd((f64)(x)))

#define isfinite(x) ((fpclassify(x) > 2))

static inline f32 dolsqrtf(f32 x)
{
	static const double _half  = .5;
	static const double _three = 3.0;
	volatile float y;
	if (x > 0.0f) {

		double guess = __frsqrte((double)x);                         // returns an approximation to
		guess        = _half * guess * (_three - guess * guess * x); // now have 12 sig bits
		guess        = _half * guess * (_three - guess * guess * x); // now have 24 sig bits
		guess        = _half * guess * (_three - guess * guess * x); // now have 32 sig bits
		y            = (float)(x * guess);
		return y;
	}
	return x;
}

#define ispositive(x) ((((u8*)&x)[0] & 0x80) != 0)

static inline f32 scaleValue(f32 scale, f32 value) { return scale * value; }

#endif
