#include "window.h"

namespace futile {

Window::~Window() { }

Window::Window() { }

Window::Window(const Dimension2D & dim)
{
	this->dim = dim;
}

}
