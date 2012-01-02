#include <futile/math/rectangle.h>

namespace futile {

Rectangle::Rectangle()
{
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Rectangle::~Rectangle() { }

/* interfaces */
bool Rectangle::equals(const Rectangle & r) const
{
	return this->x == r.x && this->y == r.y
               && this->width == r.width && this->height == r.height;
}

void Rectangle::set(const Rectangle & r)
{
	this->x = r.x;
	this->y = r.y;
	this->width = r.width;
	this->height = r.height;
}

}
