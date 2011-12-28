#include <futile/math/point4.h>

namespace futile {

Point4::Point4() : Tuple4() { }

Point4::Point4(float x, float y, float z, float w) : Tuple4(x, y, z, w) { }

Point4::~Point4() { }

/* methods */
float Point4::distance(const Point4 & p) const
{
	return sqrt(this->distance_squared(p));
}

float Point4::distance_squared(const Point4 & p) const
{
	float x = p.x - this->x;
	float y = p.y - this->y;
	float z = p.z - this->z;
	float w = p.w - this->w;

	return (x * x) + (y * y) + (z * z) + (w * w);
}

void Point4::project(const Point4 & p)
{
	assert(p.w != 0);

	this->x = p.x / p.w;
	this->y = p.y / p.w;
	this->z = p.z / p.w;
	this->w = 0;
}

/* interfaces */
Point4 * Point4::clone() const
{
	return new Point4(this->x, this->y, this->z, this->w);
}

}
