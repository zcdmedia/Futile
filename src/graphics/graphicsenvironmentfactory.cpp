#include <futile/graphics/graphicsenvironmentfactory.h>

#include "openglgraphicsenvironment.h"

namespace futile {

GraphicsEnvironment * GraphicsEnvironmentFactory::create_opengl_environment()
{
	return new OpenGLGraphicsEnvironment();
}

GraphicsEnvironment * GraphicsEnvironmentFactory::create_opengl_environment(
	const Vector2 & dim)
{
	return new OpenGLGraphicsEnvironment(dim);
}

}
