/**
	@file		vector3.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_VECTOR3_H_
#define FUTILE_MATH_VECTOR3_H_

#include <cmath>

#include <futile/math/tuple3.h>

namespace futile {

/**
	3-element vector implementation
 */
class Vector3 : public Tuple3 {
public:
	Vector3();
	Vector3(float x, float y, float z);
	virtual ~Vector3();

	/* methods */
	float angle(const Vector3 & v) const;
	void cross(const Vector3 & v1, const Vector3 & v2);
	float distance(const Vector3 & v) const;
	float dot(const Vector3 & v) const;
	float length() const;
	float length_squared() const;
	void normalize();

	/* interfaces */
	virtual Tuple3 * clone() const;

private:
	Vector3(const Vector3 &);
	Vector3 & operator=(const Vector3 &);
};

}

#endif
