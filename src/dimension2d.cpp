#include "dimension2d.h"

namespace futile {

Dimension2D::Dimension2D()
{
	this->set_width(0);
	this->set_height(0);
}

Dimension2D::Dimension2D(int dim)
{
	this->set_width(dim);
	this->set_height(dim);
}

Dimension2D::Dimension2D(int width, int height)
{
	this->set_width(width);
	this->set_height(height);
}

Dimension2D::Dimension2D(const Dimension2D & dim)
{
	this->set_width(dim.width);
	this->set_height(dim.height);
}

Dimension2D & Dimension2D::operator=(const Dimension2D & dim)
{
	this->set_width(dim.width);
	this->set_height(dim.height);
}

Dimension2D::~Dimension2D() { }

/* accessors */
int Dimension2D::get_width() const
{
	return this->width;
}

int Dimension2D::get_height() const
{
	return this->height;
}

/* modifiers */
void Dimension2D::set_width(int width)
{
	assert(width >= 0);

	this->width = width;
}

void Dimension2D::set_height(int height)
{
	assert(height >= 0);

	this->height = height;
}

}
