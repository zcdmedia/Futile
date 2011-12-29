/**
	@file		tuple4.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_TUPLE4_H_
#define FUTILE_MATH_TUPLE4_H_

#include <cstdlib>

#include <futile/cloneable.h>
#include <futile/equatable.h>
#include <futile/settable.h>
#include <futile/math/mathhelper.h>

namespace futile {

/**
	4-element tuple abstract class
 */
class Tuple4 : public Cloneable<Tuple4 *>, public Equatable<const Tuple4 &>, public Settable<const Tuple4 &> {
public:
	Tuple4();
	Tuple4(float x, float y, float z, float w);
	virtual ~Tuple4();

	/* mutators */
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
	virtual Tuple4 * clone() const = 0;
	virtual bool equals(const Tuple4 & t) const;
	virtual void set(const Tuple4 & t);

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
