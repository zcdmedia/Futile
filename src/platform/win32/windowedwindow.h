/**
	@file		windowedwindow.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_WIN32_WINDOWEDWINDOW_H_
#define FUTILE_PLATFORM_WIN32_WINDOWEDWINDOW_H_

#include <cassert>

#include "window.h"

namespace futile {

/**
	win32 windowed Window
 */
class WindowedWindow : public Window {
public:
	WindowedWindow();
	explicit WindowedWindow(const Vector2 & dim);
	WindowedWindow(const Vector2 & dim, const Vector2 & pos);

protected:
	virtual DWORD get_style() const;
	virtual DWORD get_extended_style() const;

private:
	WindowedWindow(const WindowedWindow &);
	WindowedWindow & operator=(const WindowedWindow &);
};

}

#endif
