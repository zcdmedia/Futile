/**
	@file		point3.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_POINT3_H_
#define FUTILE_MATH_POINT3_H_

#include <cassert>
#include <cmath>

#include <futile/math/tuple3.h>
#include <futile/math/point4.h>

namespace futile {

/**
	3 element point
 */
class Point3 : public Tuple3 {
public:
	Point3();
	Point3(float x, float y, float z);
	virtual ~Point3();

	/* methods */
	float distance(const Point3 & p) const;
	float distance_squared(const Point3 & p) const;
	void project(const Point4 & p);

	/* interfaces */
	virtual Point3 * clone() const;

private:
	Point3(const Point3 &);
	Point3 & operator=(const Point3 &);
};

}

#endif
