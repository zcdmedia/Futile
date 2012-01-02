/**
	@file		window.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_LINUX_WINDOW_H_
#define FUTILE_PLATFORM_LINUX_WINDOW_H_

#include <X11/Xlib.h>			/* default X11 header */
#include <X11/Xatom.h>			/* protocol message creation */
#include <X11/extensions/xf86vmode.h>	/* XF86 video operations */

#include <cassert>

#include <futile/math/rectangle.h>
#include <futile/platform/windowable.h>

namespace futile {

/**
	X11 Window abstract class
 */
class Window : public Windowable {
public:
	Window();
	virtual ~Window();

	/* methods */
	virtual void init();
	virtual void destroy();
	virtual void move(const Rectangle & bounds);
	virtual void refresh();

	static const unsigned long int EVENT_MASK = ExposureMask
                                                  | KeyPressMask
                                                  | ButtonPressMask
                                                  | StructureNotifyMask;
	static const unsigned long int VALUE_MASK = CWBorderPixel
                                                  | CWColormap
                                                  | CWEventMask
                                                  | CWOverrideRedirect;

protected:
	virtual ::Window create_window() = 0;

	Display * display;
	XVisualInfo * vi;
	::Window window;
	XSetWindowAttributes attr;
	XF86VidModeModeInfo mode;

	int screen;

private:
	GLXContext context;

	bool double_buffered;

	Window(const Window &);
	Window & operator=(const Window &);
};

}

#endif
