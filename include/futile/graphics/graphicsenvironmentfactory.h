/**
	@file		graphicsenvironmentfactory.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_GRAPHICSENVIRONMENTFACTORY_H_
#define FUTILE_GRAPHICS_GRAPHICSENVIRONMENTFACTORY_H_

#include <futile/graphics/graphicsenvironment.h>
#include <futile/math/vector2.h>

namespace futile {

/**
	factory class for graphical environments
 */
class GraphicsEnvironmentFactory {
public:
	static GraphicsEnvironment * create_opengl_environment(
		const Vector2 & dim);

private:
	GraphicsEnvironmentFactory();
	GraphicsEnvironmentFactory(const GraphicsEnvironmentFactory &);
	GraphicsEnvironmentFactory & operator=(
		const GraphicsEnvironmentFactory &);
}

}

#endif
