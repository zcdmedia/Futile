/**
	@file		tuple2.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_TUPLE2_H_
#define FUTILE_MATH_TUPLE2_H_

#include <cstdlib>

#include <futile/cloneable.h>
#include <futile/equatable.h>
#include <futile/settable.h>
#include <futile/math/mathhelper.h>

namespace futile {

/**
	2-element tuple abstract class
 */
class Tuple2 : public Cloneable<Tuple2 *>, public Equatable<const Tuple2 &>, public Settable<const Tuple2 &> {
public:
	Tuple2();
	Tuple2(float x, float y);
	virtual ~Tuple2();

	/* mutators */
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
	virtual Tuple2 * clone() const = 0;
	virtual bool equals(const Tuple2 & t) const;
	virtual void set(const Tuple2 & t);

	float x;
	float y;

private:
	Tuple2(const Tuple2 &);
	Tuple2 & operator=(const Tuple2 &);
};

}

#endif
