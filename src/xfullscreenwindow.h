/**
	@file		xfullscreenwindow.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_XFULLSCREENWINDOW_H_
#define FUTILE_XFULLSCREENWINDOW_H_

#include <cassert>

#include "xwindow.h"

namespace futile {

/**
	Fullscreen XWindow
 */
class XFullScreenWindow : public XWindow {
public:
	XFullScreenWindow();
	virtual ~XFullScreenWindow();

protected:
	virtual ::Window create_window();

private:
	XFullScreenWindow(const XFullScreenWindow & xfswin);
	XFullScreenWindow & operator=(const XFullScreenWindow & xfswin);
};

}

#endif
