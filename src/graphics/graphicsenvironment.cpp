#include <futile/graphics/graphicsenvironment.h>

namespace futile {

GraphicsEnvironment::~GraphicsEnvironment() { }

GraphicsEnvironment::GraphicsEnvironment() : dim(1.0f, 1.0f) { }

GraphicsEnvironment::GraphicsEnvironment(const Vector2 & dim)
	: dim(dim.x, dim.y) { }

}
