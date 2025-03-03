#ifndef _DOLPHIN_RAND_H
#define _DOLPHIN_RAND_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

#define RAND_MAX         (32768.0f)
#define RAND_EBISAWA_MAX (32767.0f)

void srand(u32);
int rand();
inline f32 randEbisawaFloat() { return (f32)rand() / RAND_EBISAWA_MAX; }
inline f32 randFloat() { return (f32)rand() / RAND_MAX; }
inline int randInt(int multiplier) { return multiplier * randFloat(); }
inline f32 randWeightFloat(f32 range) { return (range * (f32)rand()) / RAND_MAX; }


#define RAND_FLOAT_RANGE(origin, deviation) (origin - randFloat() * deviation)
#define RAND_FLOAT_BETWEEN(min, max)        (min + randFloat() * (max - min))

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
