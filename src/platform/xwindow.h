/**
	@file		xwindow.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_XWINDOW_H_
#define FUTILE_PLATFORM_XWINDOW_H_

#include <X11/Xlib.h>			/* default X11 header */
#include <X11/Xatom.h>			/* protocol message creation */
#include <X11/extensions/xf86vmode.h>	/* XF86 video operations */

#include <cassert>

#include "window.h"

namespace futile {

/**
	X11 Window implementation
 */
class XWindow : public futile::Window {
public:
	XWindow();
	explicit XWindow(const Dimension2D & dim);
	virtual ~XWindow();

	/* accessors */
	inline const Dimension2D & get_dimension() const { return this->dim; }

	/* methods */
	virtual void init();
	virtual void destroy();
	virtual void resize(const Dimension2D & dim);
	virtual void refresh() const;

	static const unsigned long int EVENT_MASK = ExposureMask | KeyPressMask
                                                    | ButtonPressMask
                                                    | StructureNotifyMask;
	static const unsigned long int VALUE_MASK = CWBorderPixel | CWColormap
                                                    | CWEventMask
                                                    | CWOverrideRedirect;

protected:
	virtual ::Window create_window();

	Display * display;
	XVisualInfo * vi;
	::Window window;
	XSetWindowAttributes attr;
	XF86VidModeModeInfo mode;

	int screen;

	Dimension2D dim;
private:
	GLXContext context;

	bool double_buffered;

	XWindow(const XWindow & xwin);
	XWindow & operator=(const XWindow & xwin);
};

}

#endif
