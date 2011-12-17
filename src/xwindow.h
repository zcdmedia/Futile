/**
	@file		xwindow.h
	@author		Matthew Hinkle
 */

#ifndef __FUTILE_XWINDOW_H__
#define __FUTILE_XWINDOW_H__

#include <X11/Xlib.h>			/* default X11 header */
#include <X11/Xatom.h>			/* protocol message creation */
#include <X11/extensions/xf86vmode.h>

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
	XWindow(const Dimension2D & dim, bool fullscreen);
	XWindow(const XWindow & xwin);
	XWindow & operator=(const XWindow & xwin);
	~XWindow();

	virtual void init();
	virtual void destroy();
	virtual void resize(const Dimension2D & dim);
	virtual void refresh();

private:
	Display * display;
	::Window window;
	XSetWindowAttributes attr;
	XF86VidModeModeInfo mode;
	GLXContext context;

	bool fullscreen;
	bool double_buffered;

	int screen;
	int x;
	int y;
	int depth;
};

}

#endif
