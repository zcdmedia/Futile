/**
	@file		fullscreenwindow.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_LINUX_FULLSCREENWINDOW_H_
#define FUTILE_PLATFORM_LINUX_FULLSCREENWINDOW_H_

#include <cassert>

#include "window.h"

namespace futile {

/**
	fullscreen X11 Window
 */
class FullScreenWindow : public Window {
public:
	FullScreenWindow();
	virtual ~FullScreenWindow();

	/* methods */
	virtual void move(const Rectangle & bounds);

protected:
	virtual ::Window create_window();

private:
	FullScreenWindow(const FullScreenWindow &);
	FullScreenWindow & operator=(const FullScreenWindow &);
};

}

#endif
