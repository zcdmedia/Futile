#include <futile/math/tuple4.h>

namespace futile {

Tuple4::Tuple4()
{
	this->set(0, 0, 0, 0);
}

Tuple4::Tuple4(float x, float y, float z, float w)
{
	this->set(x, y, z, w);
}

Tuple4::~Tuple4() { }

/* modifiers */
void Tuple4::set(float x, float y, float z, float w)
{
        this->x = x;
        this->y = y;
	this->z = z;
	this->w = w;
}

/* methods */
void Tuple4::absolute()
{
        this->x = abs(this->x);
        this->y = abs(this->y);
	this->z = abs(this->z);
	this->w = abs(this->w);
}

void Tuple4::add(const Tuple4 & t)
{
        this->x += t.x;
        this->y += t.y;
	this->z += t.z;
	this->w += t.w;
}

void Tuple4::clamp(float min, float max)
{
        this->x = Math<float>::clamp(this->x, min, max);
        this->y = Math<float>::clamp(this->y, min, max);
	this->z = Math<float>::clamp(this->z, min, max);
	this->w = Math<float>::clamp(this->w, min, max);
}

void Tuple4::clamp_max(float max)
{
        this->x = std::min(this->x, max);
        this->y = std::min(this->y, max);
	this->z = std::min(this->z, max);
	this->w = std::min(this->w, max);
}

void Tuple4::clamp_min(float min)
{
        this->x = std::max(this->x, min);
        this->y = std::max(this->y, min);
	this->z = std::max(this->z, min);
	this->w = std::max(this->w, min);
}

void Tuple4::interpolate(const Tuple4 & t, float alpha)
{
        const float s = 1 - alpha;
        this->scale(s);
        Tuple4 * tcpy = t.clone();
        tcpy->scale(alpha);
        this->add(*tcpy);

	delete tcpy;
}

void Tuple4::negate()
{
        this->x = 0 - this->x;
        this->y = 0 - this->y;
	this->z = 0 - this->z;
	this->w = 0 - this->w;
}

void Tuple4::scale(float s)
{
        this->x *= s;
        this->y *= s;
	this->z *= s;
	this->w *= s;
}

void Tuple4::sub(const Tuple4 & t)
{
        this->x -= t.x;
        this->y -= t.y;
	this->z -= t.z;
	this->w -= t.w;
}

/* interface */
bool Tuple4::equals(const Tuple4 * t) const
{
	return t && this->x == t->x && this->y == t->y && this->z == t->z
               && this->w == t->w;
}

}
