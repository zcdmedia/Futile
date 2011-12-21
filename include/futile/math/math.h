/**
	@file		math.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_MATH_H_
#define FUTILE_MATH_MATH_H_

#include <algorithm>

namespace futile {

/**
	common math functions
 */
template<typename T> class Math {
public:
	static inline T clamp(T value, T min, T max) {
		return std::max(min, std::min(value, max));
	}
};

}

#endif
