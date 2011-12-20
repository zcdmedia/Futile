/**
	@file		window.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_WINDOW_H_
#define FUTILE_PLATFORM_WINDOW_H_

#include "dimension2d.h"
#include "graphics.h"

namespace futile {

/**
	display window interface
 */
class Window {
public:
	virtual ~Window() { }

	/* methods */
	virtual void init() = 0;
	virtual void destroy() = 0;
	virtual void resize(const Dimension2D & dim) = 0;
	virtual void refresh() const = 0;

protected:
	Window() { }

private:
	Window(const Window &);
	Window & operator=(const Window &);
};

}

#endif
