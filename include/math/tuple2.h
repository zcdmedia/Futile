/**
	@file		tuple2.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_TUPLE2_H_
#define FUTILE_MATH_TUPLE2_H_

#include <cstdlib>

#include "common/cloneable.h"
#include "math/math.h"

namespace futile {

/**
	2-element tuple abstract class
 */
class Tuple2 : Cloneable<Tuple2 *> {
public:
	Tuple2();
	Tuple2(float x, float y);
	virtual ~Tuple2();

	/* modifiers */
	void set(float x, float y);

	/* methods */
	void absolute();
	void add(const Tuple2 & t);
	void clamp(float min, float max);
	void clamp_max(float max);
	void clamp_min(float min);
	void interpolate(const Tuple2 & t, float alpha);
	void negate();
	void scale(float s);
	void sub(const Tuple2 & t);

	/* interfaces */
	Tuple2 * clone() const;

	float x;
	float y;

private:
	Tuple2(const Tuple2 &);
	Tuple2 & operator=(const Tuple2 &);
};

}

#endif
