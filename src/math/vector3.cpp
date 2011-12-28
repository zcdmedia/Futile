#include <futile/math/vector3.h>

namespace futile {

Vector3::Vector3() : Tuple3() { }

Vector3::Vector3(float x, float y, float z) : Tuple3(x, y, z) { }

Vector3::~Vector3() { }

/* methods */
float Vector3::angle(const Vector3 & v) const
{
	Vector3 a(this->x, this->y, this->z);
	Vector3 b(v.x, v.y, v.z);

	a.normalize();
	b.normalize();

	return std::acos(a.dot(b));
}

void Vector3::cross(const Vector3 & v1, const Vector3 & v2)
{
	this->x = v1.y * v2.z - v1.z * v2.y;
	this->y = v1.z * v2.x - v1.x * v2.z;
	this->z = v1.x * v2.y - v1.y * v2.x;
}

float Vector3::distance(const Vector3 & v) const
{
	Vector3 u(v.x, v.y, v.z);
	u.sub(v);

	return u.length();;
}

float Vector3::dot(const Vector3 & v) const
{
	return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
}

float Vector3::length() const
{
	return std::sqrt(this->dot(*this));
}

float Vector3::length_squared() const
{
	const float length = this->length();

	return length * length;
}

void Vector3::normalize()
{
	const float length = this->length();
	if(length == 0) return;
	this->scale(1.0f / length);
}

/* interfaces */
Vector3 * Vector3::clone() const
{
	return new Vector3(this->x, this->y, this->z);
}

}
