#include <futile/graphics/graphicscontext.h>

namespace futile {

GraphicsContext::GraphicsContext() : dim(1, 1) { }

GraphicsContext::GraphicsContext(const Vector2 & dim) : dim(dim.x, dim.y) { }

GraphicsContext::~GraphicsContext() { }

/* methods */
void GraphicsContext::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	this->resize(this->dim);
	glFlush();
}

void GraphicsContext::resize(const Vector2 & dim)
{
	this->dim.set(dim);
	const int width = this->dim.x <= 0.0f ? 1.0f : static_cast<int>(dim.x);
	const int height = this->dim.y <= 0.0f ? 1.0f : static_cast<int>(dim.y);

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	Matrix4 m;
	m.identity();
	Transform::load_matrix(&m);

	const GLfloat y_field_of_view = 45.0f;
	const GLfloat aspect = static_cast<GLfloat>(width)
			       / static_cast<GLfloat>(height);
	const GLfloat znear = 0.1f;
	const GLfloat zfar = 100.0f;

	Transform::perspective(y_field_of_view, aspect, znear, zfar, &m);
	Transform::load_matrix(&m);
	glMatrixMode(GL_MODELVIEW);
	m.identity();
	Transform::load_matrix(&m);
}

void GraphicsContext::refresh() { }

}
