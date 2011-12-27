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
	WindowedWindow(GraphicsContext * gfxctx);
	WindowedWindow(GraphicsContext * gfxctx, const Vector2 & pos);

protected:
	virtual ::Window create_window();

private:
	WindowedWindow();
	WindowedWindow(const WindowedWindow &);
	WindowedWindow & operator=(const WindowedWindow &);
};

}

#endif
