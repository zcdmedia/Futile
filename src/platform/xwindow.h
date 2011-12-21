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

#include <futile/math/vector2.h>
#include <futile/platform/window.h>

namespace futile {

/**
	X11 Window abstract class
 */
class XWindow : public futile::Window {
public:
	XWindow();
	virtual ~XWindow();

	/* accessors */
	virtual const Vector2 & get_dim() const;
	virtual const Vector2 & get_pos() const;

	/* methods */
	virtual void init();
	virtual void destroy();
	virtual void reposition(const Vector2 & pos);
	virtual void resize(const Vector2 & dim);
	virtual void refresh() const;

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

	Vector2 dim;
	Vector2 pos;
private:
	GLXContext context;

	bool double_buffered;

	XWindow(const XWindow &);
	XWindow & operator=(const XWindow &);
};

}

#endif
