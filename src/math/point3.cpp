#include <futile/math/point3.h>

namespace futile {

Point3::Point3() : Tuple3() { }

Point3::Point3(float x, float y, float z) : Tuple3(x, y, z) { }

Point3::~Point3() { }

/* methods */
float Point3::distance(const Point3 & p) const
{
	return sqrt(this->distance_squared(p));
}

float Point3::distance_squared(const Point3 & p) const
{
	float x = p.x - this->x;
	float y = p.y - this->y;
	float z = p.z - this->z;

	return (x * x) + (y * y) + (z * z);
}

void Point3::project(const Point4 & p)
{
	assert(p.w != 0);

	this->x = p.x / p.w;
	this->y = p.y / p.w;
	this->z = p.z / p.w;
}

/* interfaces */
Point3 * Point3::clone() const
{
	return new Point3(this->x, this->y, this->z);
}

}
