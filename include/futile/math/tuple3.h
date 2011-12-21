/**
	@file		tuple3.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_TUPLE3_H_
#define FUTILE_MATH_TUPLE3_H_

#include <cstdlib>

#include <futile/cloneable.h>
#include <futile/math/math.h>

namespace futile {

/**
	3-element tuple abstract class
 */
class Tuple3 : public Cloneable<Tuple3 *> {
public:
	Tuple3();
	Tuple3(float x, float y, float z);
	virtual ~Tuple3();

	/* mutators */
	void set(float x, float y, float z);

	/* methods */
	void absolute();
	void add(const Tuple3 & t);
	void clamp(float min, float max);
	void clamp_max(float max);
	void clamp_min(float min);
	void interpolate(const Tuple3 & t, float alpha);
	void negate();
	void scale(float s);
	void sub(const Tuple3 & t);

	/* interfaces */
	virtual Tuple3 * clone() const = 0;

	float x;
	float y;
	float z;

private:
	Tuple3(const Tuple3 &);
	Tuple3 & operator=(const Tuple3 &);
};

}

#endif
