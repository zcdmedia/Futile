#include <futile/math/tuple3.h>

namespace futile {

Tuple3::Tuple3()
{
	this->set(0, 0, 0);
}

Tuple3::Tuple3(float x, float y, float z)
{
	this->set(x, y, z);
}

Tuple3::~Tuple3() { }

/* modifiers */
void Tuple3::set(float x, float y, float z)
{
        this->x = x;
        this->y = y;
	this->z = z;
}

/* methods */
void Tuple3::absolute()
{
        this->x = abs(this->x);
        this->y = abs(this->y);
	this->z = abs(this->z);
}

void Tuple3::add(const Tuple3 & t)
{
        this->x += t.x;
        this->y += t.y;
	this->z += t.z;
}

void Tuple3::clamp(float min, float max)
{
        this->x = Math<float>::clamp(this->x, min, max);
        this->y = Math<float>::clamp(this->y, min, max);
	this->z = Math<float>::clamp(this->z, min, max);
}

void Tuple3::clamp_max(float max)
{
        this->x = std::min(this->x, max);
        this->y = std::min(this->y, max);
	this->z = std::min(this->z, max);
}

void Tuple3::clamp_min(float min)
{
        this->x = std::max(this->x, min);
        this->y = std::max(this->y, min);
	this->z = std::max(this->z, min);
}

void Tuple3::interpolate(const Tuple3 & t, float alpha)
{
        const float s = 1 - alpha;
        this->scale(s);
        Tuple3 * tcpy = t.clone();
        tcpy->scale(alpha);
        this->add(*tcpy);

	delete tcpy;
}

void Tuple3::negate()
{
        this->x = 0 - this->x;
        this->y = 0 - this->y;
	this->z = 0 - this->z;
}

void Tuple3::scale(float s)
{
        this->x *= s;
        this->y *= s;
	this->z *= s;
}

void Tuple3::sub(const Tuple3 & t)
{
        this->x -= t.x;
        this->y -= t.y;
	this->z -= t.z;
}

}
