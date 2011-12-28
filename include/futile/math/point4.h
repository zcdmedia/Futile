/**
	@file		point4.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_POINT4_H_
#define FUTILE_MATH_POINT4_H_

#include <cassert>
#include <cmath>

#include <futile/math/tuple4.h>

namespace futile {

/**
	4 element point
 */
class Point4 : public Tuple4 {
public:
	Point4();
	Point4(float x, float y, float z, float w);
	virtual ~Point4();

	/* methods */
	float distance(const Point4 & p) const;
	float distance_squared(const Point4 & p) const;
	void project(const Point4 & p);

	/* interfaces */
	virtual Point4 * clone() const;

private:
	Point4(const Point4 &);
	Point4 & operator=(const Point4 &);
};

}

#endif
