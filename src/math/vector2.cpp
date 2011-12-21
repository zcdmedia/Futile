#include <futile/math/vector2.h>

namespace futile {

Vector2::Vector2() : Tuple2() { }

Vector2::Vector2(float x, float y) : Tuple2(x, y) { }

Vector2::~Vector2() { }

/* methods */
float Vector2::angle(const Vector2 & v) const
{
	Vector2 a(this->x, this->y);
	Vector2 b(v.x, v.y);

	a.normalize();
	b.normalize();

	return std::acos(a.dot(b));
}

float Vector2::distance(const Vector2 & v) const
{
	Vector2 u(v.x, v.y);
	u.sub(v);

	return u.length();;
}

float Vector2::dot(const Vector2 & v) const
{
	return (this->x * v.x) + (this->y * v.y);
}

float Vector2::length() const
{
	return std::sqrt(this->dot(*this));
}

float Vector2::length_squared() const
{
	const float length = this->length();

	return length * length;
}

void Vector2::normalize()
{
	const float length = this->length();
	if(length == 0) return;
	this->scale(1.0f / length);
}

/* interfaces */
Tuple2 * Vector2::clone() const
{
	return new Vector2(this->x, this->y);
}

}
