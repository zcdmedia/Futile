/**
	@file		xfullscreenwindow.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_XFULLSCREENWINDOW_H_
#define FUTILE_PLATFORM_XFULLSCREENWINDOW_H_

#include <cassert>

#include "xwindow.h"

namespace futile {

/**
	fullscreen XWindow
 */
class XFullScreenWindow : public XWindow {
public:
	XFullScreenWindow();
	virtual ~XFullScreenWindow();

	virtual void reposition(const Vector2 &);
	virtual void resize(const Vector2 &);

protected:
	virtual ::Window create_window();

private:
	XFullScreenWindow(const XFullScreenWindow &);
	XFullScreenWindow & operator=(const XFullScreenWindow &);
};

}

#endif
