#include <futile/math/vector4.h>

namespace futile {

Vector4::Vector4() : Tuple4() { }

Vector4::Vector4(float x, float y, float z, float w) : Tuple4(x, y, z, w) { }

Vector4::~Vector4() { }

/* methods */
float Vector4::angle(const Vector4 & v) const
{
	Vector4 a(this->x, this->y, this->z, this->w);
	Vector4 b(v.x, v.y, v.z, v.w);

	a.normalize();
	b.normalize();

	return std::acos(a.dot(b));
}

float Vector4::distance(const Vector4 & v) const
{
	Vector4 u(v.x, v.y, v.z, v.w);
	u.sub(v);

	return u.length();;
}

float Vector4::dot(const Vector4 & v) const
{
	return (this->x * v.x) + (this->y * v.y) + (this->z * v.z)
               + (this->w * v.w);
}

float Vector4::length() const
{
	return std::sqrt(this->dot(*this));
}

float Vector4::length_squared() const
{
	const float length = this->length();

	return length * length;
}

void Vector4::normalize()
{
	const float length = this->length();
	if(length == 0) return;
	this->scale(1.0f / length);
}

/* interfaces */
Tuple4 * Vector4::clone() const
{
	return new Vector4(this->x, this->y, this->z, this->w);
}

}
