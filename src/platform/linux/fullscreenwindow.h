/**
	@file		fullscreenwindow.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_LINUX_FULLSCREENWINDOW_H_
#define FUTILE_PLATFORM_LINUX_FULLSCREENWINDOW_H_

#include <cassert>

#include <futile/graphics/graphicsenvironmentfactory.h>

#include "window.h"

namespace futile {

/**
	fullscreen X11 Window
 */
class FullScreenWindow : public Window {
public:
	explicit FullScreenWindow(GraphicsEnvironment * gfxenv);
	virtual ~FullScreenWindow();

	virtual void reposition(const Vector2 &);
	virtual void resize(const Vector2 &);

protected:
	virtual ::Window create_window();

private:
	FullScreenWindow();
	FullScreenWindow(const FullScreenWindow &);
	FullScreenWindow & operator=(const FullScreenWindow &);
};

}

#endif
