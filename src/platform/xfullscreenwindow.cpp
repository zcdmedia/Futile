#include "xfullscreenwindow.h"

namespace futile {

XFullScreenWindow::XFullScreenWindow() : XWindow() { }

XFullScreenWindow::~XFullScreenWindow() { }

::Window XFullScreenWindow::create_window()
{
	assert(this->display);
	XF86VidModeSwitchToMode(this->display, this->screen, &this->mode);
	XF86VidModeSetViewPort(this->display, this->screen, 0, 0);
	this->attr.override_redirect = True;

	this->dim.set_width(this->mode.hdisplay);
	this->dim.set_height(this->mode.vdisplay);

	::Window parent = RootWindow(this->display, this->vi->screen);
	::Window window = XCreateWindow(this->display, parent, 0, 0,
                                        this->dim.get_width(),
                                        this->dim.get_height(), 0,
                                        this->vi->depth, InputOutput,
                                        this->vi->visual, XWindow::VALUE_MASK,
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
