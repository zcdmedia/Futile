/**
	@file		vector4.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_VECTOR4_H_
#define FUTILE_MATH_VECTOR4_H_

#include <cmath>

#include <futile/math/tuple4.h>

namespace futile {

/**
	4-element vector implementation
 */
class Vector4 : public Tuple4 {
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	virtual ~Vector4();

	/* methods */
	float angle(const Vector4 & v) const;
	float distance(const Vector4 & v) const;
	float dot(const Vector4 & v) const;
	float length() const;
	float length_squared() const;
	void normalize();

	virtual Vector4 * clone() const;

private:
	Vector4(const Vector4 &);
	Vector4 & operator=(const Vector4 &);
};

}

#endif
