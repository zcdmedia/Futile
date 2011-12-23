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
	fullscreen win32 Window
 */
class FullScreenWindow : public Window {
public:
	FullScreenWindow();
	virtual ~FullScreenWindow();

	virtual void init();
	virtual void reposition(const Vector2 &);
	virtual void resize(const Vector2 &);

protected:
	virtual DWORD get_style() const;
	virtual DWORD get_extended_style() const;

private:
	FullScreenWindow(const FullScreenWindow &);
	FullScreenWindow & operator=(const FullScreenWindow &);
};

}

#endif
