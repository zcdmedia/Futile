/**
	@file		mathhelper.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_MATHHELPER_H_
#define FUTILE_MATH_MATHHELPER_H_

#include <algorithm>

#include <futile/math/math.h>

namespace futile {

/**
	generic math functions
 */
template<typename T> class MathHelper {
public:
	static inline T clamp(T value, T min, T max)
	{
		return std::max(min, std::min(value, max));
	}

	static inline bool epsilon_equals(T a, T b)
	{
		return abs(a - b) < static_cast<T>(Math::EPSILON);
	}

	static inline bool epsilon_equals(T a, T b, T epsilon)
	{
		return abs(a - b) < epsilon;
	}

private:
	MathHelper();
	MathHelper(const MathHelper &);
	MathHelper & operator=(const MathHelper &);
};

}

#endif
