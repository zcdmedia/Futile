/**
	@file		vector2.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_VECTOR2_H_
#define FUTILE_MATH_VECTOR2_H_

#include <cmath>

#include <futile/math/tuple2.h>

namespace futile {

/**
	2-element vector implementation
 */
class Vector2 : public Tuple2 {
public:
	Vector2();
	Vector2(float x, float y);
	virtual ~Vector2();

	/* methods */
	float angle(const Vector2 & v) const;
	float distance(const Vector2 & v) const;
	float dot(const Vector2 & v) const;
	float length() const;
	float length_squared() const;
	void normalize();

	virtual Tuple2 * clone() const;

private:
	Vector2(const Vector2 &);
	Vector2 & operator=(const Vector2 &);
};

}

#endif
