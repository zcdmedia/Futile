#include "windowedwindow.h"

namespace futile {

WindowedWindow::WindowedWindow() : Window() { }

WindowedWindow::WindowedWindow(const Vector2 & dim) : Window()
{
	this->dim.set(&dim);
}

WindowedWindow::WindowedWindow(const Vector2 & dim, const Vector2 & pos)
	: Window()
{
	this->dim.set(&dim);
	this->pos.set(&pos);
}

DWORD WindowedWindow::get_style() const
{
	return WS_OVERLAPPEDWINDOW;
}

DWORD WindowedWindow::get_extended_style() const
{
	return WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
}

}
