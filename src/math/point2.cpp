#include <futile/math/point2.h>

namespace futile {

Point2::Point2() : Tuple2() { }

Point2::Point2(float x, float y) : Tuple2(x, y) { }

Point2::~Point2() { }

/* methods */
float Point2::distance(const Point2 & p) const
{
	return sqrt(this->distance_squared(p));
}

float Point2::distance_squared(const Point2 & p) const
{
	float x = p.x - this->x;
	float y = p.y - this->y;

	return (x * x) + (y * y);
}

/* interfaces */
Point2 * Point2::clone() const
{
	return new Point2(this->x, this->y);
}

}
