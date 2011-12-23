#include <futile/graphics/graphicsenvironment.h>

namespace futile {

GraphicsEnvironment::~GraphicsEnvironment()

GraphicsEnvironment::GraphicsEnvironment(const Vector2 & dim)
	: dim(dim.x, dim.y) { }

}
