#include "fullscreenwindow.h"

namespace futile {

FullScreenWindow::FullScreenWindow() : Window() { }

FullScreenWindow::~FullScreenWindow() { }

/* methods */
void FullScreenWindow::reposition(const Vector2 & pos) { }
void FullScreenWindow::resize(const Vector2 & dim) { }

::Window FullScreenWindow::create_window()
{
	assert(this->display);
	XF86VidModeSwitchToMode(this->display, this->screen, &this->mode);
	XF86VidModeSetViewPort(this->display, this->screen, 0, 0);
	this->attr.override_redirect = True;

	this->dim.x = this->mode.hdisplay;
	this->dim.y = this->mode.vdisplay;

	::Window parent = RootWindow(this->display, this->vi->screen);
	::Window window = XCreateWindow(this->display, parent, 0, 0,
                                        this->dim.x, this->dim.y, 0,
                                        this->vi->depth, InputOutput,
                                        this->vi->visual, Window::VALUE_MASK,
                                        &this->attr);
	XWarpPointer(this->display, None, window, 0, 0, 0, 0, 0, 0);
	XMapRaised(this->display, window);

	/* re-direct input for fullscreen */
	XGrabKeyboard(this->display, window, True, GrabModeAsync,
                      GrabModeAsync, CurrentTime);
	XGrabPointer(this->display, window, True, ButtonPressMask,
                     GrabModeAsync, GrabModeAsync, window, None,
                     CurrentTime);

	return window;
}

}
