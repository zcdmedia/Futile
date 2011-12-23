#include "openglgraphicsenvironment.h"

namespace futile {

OpenGLGraphicsEnvironment::OpenGLGraphicsEnvironment(const Vector2 & dim)
	: GraphicsEnvironment(dim) { }

OpenGLGraphicsEnvironment::~OpenGLGraphicsEnvironment() { }

/* methods */
void OpenGLGraphicsEnvironment::init()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	this->resize(this->dim);
	glFlush();
}

void OpenGLGraphicsEnvironment::resize
{
	const int width = dim.x <= 0 ? 1 : dim.x;
	const int height = dim.y <= 0 ? 1 : dim.y;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	const GLfloat y_field_of_view = 45.0f;
	const GLfloat aspect = static_cast<GLfloat>(width)
			       / static_cast<GLfloat>(height);
	const GLfloat z_near = 0.1f;
	const GLfloat z_far = 100.0f;
	gluPerspective(y_field_of_view, aspect, z_near, z_far);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
