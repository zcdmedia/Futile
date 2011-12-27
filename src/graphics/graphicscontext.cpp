#include <futile/graphics/graphicscontext.h>

namespace futile {

GraphicsContext::~GraphicsContext() { }

GraphicsContext::GraphicsContext() : dim(1.0f, 1.0f) { }

GraphicsContext::GraphicsContext(const Vector2 & dim) : dim(dim.x, dim.y) { }

}
