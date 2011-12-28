#include <futile/math/tuple2.h>

namespace futile {

Tuple2::Tuple2()
{
	this->set(0, 0);
}

Tuple2::Tuple2(float x, float y)
{
	this->set(x, y);
}

Tuple2::~Tuple2() { }

/* modifiers */
void Tuple2::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Tuple2::set(const Tuple2 & t)
{
	this->x = t.x;
	this->y = t.y;
}

/* methods */
void Tuple2::absolute()
{
	this->x = abs(this->x);
	this->y = abs(this->y);
}

void Tuple2::add(const Tuple2 & t)
{
	this->x += t.x;
	this->y += t.y;
}

void Tuple2::clamp(float min, float max)
{
	this->x = MathHelper<float>::clamp(this->x, min, max);
	this->y = MathHelper<float>::clamp(this->y, min, max);
}

void Tuple2::clamp_max(float max)
{
	this->x = std::min(this->x, max);
	this->y = std::min(this->y, max);
}

void Tuple2::clamp_min(float min)
{
	this->x = std::max(this->x, min);
	this->y = std::max(this->y, min);
}

void Tuple2::interpolate(const Tuple2 & t, float alpha)
{
	const float s = 1 - alpha;
	this->scale(s);

	Tuple2 * tcpy = t.clone();
	tcpy->scale(alpha);
	this->add(*tcpy);

	delete tcpy;
}

void Tuple2::negate()
{
	this->x = 0 - this->x;
	this->y = 0 - this->y;
}

void Tuple2::scale(float s)
{
	this->x *= s;
	this->y *= s;
}

void Tuple2::sub(const Tuple2 & t)
{
	this->x -= t.x;
	this->y -= t.y;
}

/* interface */
bool Tuple2::equals(const Tuple2 & t) const
{
	return MathHelper<float>::epsilon_equals(this->x, t.x)
               && MathHelper<float>::epsilon_equals(this->y, t.y);
}

}
