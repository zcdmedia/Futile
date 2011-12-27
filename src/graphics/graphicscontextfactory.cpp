#include <futile/graphics/graphicscontextfactory.h>

#include "graphicscontext2d.h"
#include "graphicscontext3d.h"

namespace futile {

GraphicsContext * GraphicsContextFactory::create_2D_context()
{
	return new GraphicsContext2D();
}

GraphicsContext * GraphicsContextFactory::create_2D_context(const Vector2 & dim)
{
	return new GraphicsContext2D(dim);
}

GraphicsContext * GraphicsContextFactory::create_3D_context()
{
	return new GraphicsContext3D();
}

GraphicsContext * GraphicsContextFactory::create_3D_context(const Vector2 & dim)
{
	return new GraphicsContext3D(dim);
}

}
