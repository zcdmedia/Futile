/**
	@file		graphicscontextfactory.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_GRAPHICSCONTEXTFACTORY_H_
#define FUTILE_GRAPHICS_GRAPHICSCONTEXTFACTORY_H_

#include <futile/graphics/graphicscontext.h>
#include <futile/math/vector2.h>

namespace futile {

/**
	factory class for graphics contexts
 */
class GraphicsContextFactory {
public:
	static GraphicsContext * create_2D_context();
	static GraphicsContext * create_2D_context(const Vector2 & dim);
	static GraphicsContext * create_3D_context();
	static GraphicsContext * create_3D_context(const Vector2 & dim);

private:
	GraphicsContextFactory();
	GraphicsContextFactory(const GraphicsContextFactory &);
	GraphicsContextFactory & operator=(const GraphicsContextFactory &);
};

}

#endif
