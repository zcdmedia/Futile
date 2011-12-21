/**
	@file		xwindowedwindow.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_XWINDOWEDWINDOW_H_
#define FUTILE_PLATFORM_XWINDOWEDWINDOW_H_

#include <cassert>

#include "xwindow.h"

namespace futile {

/**
	windowed XWindow
 */
class XWindowedWindow : public XWindow {
public:
	XWindowedWindow();
	explicit XWindowedWindow(const Vector2 & dim);
	XWindowedWindow(const Vector2 & dim, const Vector2 & pos);

protected:
	virtual ::Window create_window();

private:
	XWindowedWindow(const XWindowedWindow &);
	XWindowedWindow & operator=(const XWindowedWindow &);
};

}

#endif
