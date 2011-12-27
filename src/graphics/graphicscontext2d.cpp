#include "graphicscontext2d.h"

namespace futile {

GraphicsContext2D::GraphicsContext2D() : GraphicsContext() { }

GraphicsContext2D::GraphicsContext2D(const Vector2 & dim)
	: GraphicsContext(dim) { }

GraphicsContext2D::~GraphicsContext2D() { }

/* methods */
void GraphicsContext2D::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	this->resize(this->dim);
	glFlush();
}

void GraphicsContext2D::resize(const Vector2 & dim)
{
	this->dim.set(dim);
	GLdouble left = 0.0;
	GLdouble right = static_cast<GLdouble>(dim.x);
	GLdouble top = 0.0;
	GLdouble bottom = static_cast<GLdouble>(dim.y);
	gluOrtho2D(left, right, top, bottom);
}

void GraphicsContext2D::refresh() { }

}
