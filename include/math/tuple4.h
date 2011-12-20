/**
	@file		tuple4.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_TUPLE4_H_
#define FUTILE_MATH_TUPLE4_H_

#include <cstdlib>

#include "common/cloneable.h"
#include "math/math.h"

namespace futile {

/**
	4-element tuple abstract class
 */
class Tuple4 : Cloneable<Tuple4> {
public:
	Tuple4();
	Tuple4(float x, float y, float z, float w);
	virtual ~Tuple4();

	/* modifiers */
	void set(float x, float y, float z, float w);

	/* methods */
	void absolute();
	void add(const Tuple4 & t);
	void clamp(float min, float max);
	void clamp_max(float max);
	void clamp_min(float min);
	void interpolate(const Tuple4 & t, float alpha);
	void negate();
	void scale(float s);
	void sub(const Tuple4 & t);

	/* interfaces */
	Tuple4 clone() const;

	float x;
	float y;
	float z;
	float w;

private:
	Tuple4(const Tuple4 & t);
	Tuple4 & operator=(const Tuple4 &);
};

}

#endif
