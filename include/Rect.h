#ifndef _RECT_H
#define _RECT_H

#include "types.h"
#include "Vector2.h"

template <typename T>
struct Rect {

	inline Rect<T>() {};

	inline Rect<T> (T a, T b, T c, T d) {
		p1.x = a;
		p1.y = b;
		p2.x = c;
		p2.y = d;
	}

	Vector2<T> p1; // _00 /* topLeft */
	Vector2<T> p2; // _08 /* bottomRight */
};

typedef Rect<int> Recti;
typedef Rect<float> Rectf;

#endif
