/**
	@file		windowedwindow.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_LINUX_WINDOWEDWINDOW_H_
#define FUTILE_PLATFORM_LINUX_WINDOWEDWINDOW_H_

#include <cassert>

#include "window.h"

namespace futile {

/**
	windowed XWindow
 */
class WindowedWindow : public Window {
public:
	WindowedWindow(const Rectangle & bounds);
	virtual ~WindowedWindow();

	/* methods */
	virtual void move(const Rectangle & bounds);

protected:
	virtual ::Window create_window();

private:
	Rectangle bounds;

	WindowedWindow(const WindowedWindow &);
	WindowedWindow & operator=(const WindowedWindow &);
};

}

#endif
