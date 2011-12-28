/**
	@file		point2.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_POINT2_H_
#define FUTILE_MATH_POINT2_H_

#include <cmath>

#include <futile/math/tuple2.h>

namespace futile {

/**
	2 element point
 */
class Point2 : public Tuple2 {
public:
	Point2();
	Point2(float x, float y);
	virtual ~Point2();

	/* methods */
	float distance(const Point2 & p) const;
	float distance_squared(const Point2 & p) const;

	/* interfaces */
	virtual Point2 * clone() const;

private:
	Point2(const Point2 &);
	Point2 & operator=(const Point2 &);
};

}

#endif
