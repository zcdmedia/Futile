#include "fullscreenwindow.h"

/* internal prototypes */
static inline void redirect_input(Display *, ::Window);

namespace futile {

FullScreenWindow::FullScreenWindow() : Window() { }

FullScreenWindow::~FullScreenWindow() { }

/* methods */
void FullScreenWindow::move(const Rectangle & bounds) { }

::Window FullScreenWindow::create_window()
{
	assert(this->display);
	XF86VidModeSwitchToMode(this->display, this->screen, &this->mode);
	XF86VidModeSetViewPort(this->display, this->screen, 0, 0);
	this->attr.override_redirect = True;

	int width = this->mode.hdisplay;
	int height = this->mode.vdisplay;

	::Window parent = RootWindow(this->display, this->vi->screen);
	::Window window = XCreateWindow(this->display, parent,
                                        0, 0, width, height, 0,
                                        this->vi->depth, InputOutput,
                                        this->vi->visual, Window::VALUE_MASK,
                                        &this->attr);
	XWarpPointer(this->display, None, window, 0, 0, 0, 0, 0, 0);
	XMapRaised(this->display, window);

	redirect_input(this->display, window);

	return window;
}

}

/* internal */
static inline void redirect_input(Display * display, ::Window window)
{
	XGrabKeyboard(display, window, True, GrabModeAsync, GrabModeAsync,
                      CurrentTime);
	XGrabPointer(display, window, True, ButtonPressMask, GrabModeAsync,
                     GrabModeAsync, window, None, CurrentTime);
}
