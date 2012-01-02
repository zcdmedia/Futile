#include <futile/graphics/graphicsdevice.h>

namespace futile {

GraphicsDevice::GraphicsDevice() : viewport(Rectangle(0, 0, 1, 1)) { }

GraphicsDevice::~GraphicsDevice() { }

/* interfaces */
bool GraphicsDevice::equals(const GraphicsDevice & gd) const
{
	return this->viewport.equals(gd.viewport);
}

void GraphicsDevice::set(const GraphicsDevice & gd)
{
	this->viewport.set(gd.viewport);
}

}
