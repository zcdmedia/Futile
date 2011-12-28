/**
	@file		quad.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_QUAD_H_
#define FUTILE_MATH_QUAD_H_

#include <futile/equatable.h>
#include <futile/math/point2.h>

namespace futile {

/**
	4 sided polygon
 */
class Quad : public Equatable<const Quad &> {
public:
	Quad();
	Quad(const Point2 & p1, const Point2 & p2,
             const Point2 & p3, const Point2 & p4);
	~Quad();

	/* interfaces */
	virtual bool equals(const Quad & q) const;

	Point2 p1;
	Point2 p2;
	Point2 p3;
	Point2 p4;

private:
	Quad(const Quad &);
	Quad & operator=(const Quad &);
};

}

#endif
