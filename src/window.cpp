#include "window.h"

namespace futile {

Window::~Window() { }

Window::Window() : dim(Window::DEFAULT_DIM)
{
	this->fullscreen = false;
}

Window::Window(const Dimension2D & dim) : dim(dim)
{
	this->fullscreen = false;
}

Window::Window(const Dimension2D & dim, bool fullscreen) : dim(dim)
{
	this->fullscreen = fullscreen;
}

/* accessors */
bool Window::is_fullscreen() const
{
	return this->fullscreen;
}

}
