#include <futile/graphics/graphicsenvironmentfactory.h>

#include "openglgraphicsenvironment.h"

namespace futile {

GraphicsEnvironment * GraphicsEnvironmentFactory::get_opengl_environment(
	const Vector2 & dim)
{
	return new OpenGLGraphicsEnvironment(dim);
}

}
