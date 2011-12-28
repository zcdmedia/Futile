/**
	@file		math.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_MATH_H_
#define FUTILE_MATH_MATH_H_

#include <cmath>

#define FUTILE_MATH_PI 3.14159

namespace futile {

/**
	common constants and common functions
 */
class Math {
public:
	/* small value used for comparing floating point values */
	static const float EPSILON = 1e-7;

	/* pi and common uses */
	static const float PI = FUTILE_MATH_PI;
	static const float PI_OVER_2 = FUTILE_MATH_PI / 2.0f;
	static const float PI_OVER_3 = FUTILE_MATH_PI / 3.0f;
	static const float PI_OVER_4 = FUTILE_MATH_PI / 4.0f;
	static const float PI_OVER_6 = FUTILE_MATH_PI / 6.0f;

	static const float PI_OVER_180 = FUTILE_MATH_PI / 180.0f;
	static const float PI_OVER_360 = FUTILE_MATH_PI / 360.0f;

	/* angle conversions */
	static inline float deg2rad(float deg)
	{
		return deg * Math::PI_OVER_180;
	}

	static inline float rad2deg(float rad)
	{
		return rad * 180.0f / Math::PI;
	}

private:
	Math();
	Math(const Math &);
	Math & operator=(const Math &);
};

}

#undef FUTILE_MATH_PI

#endif
