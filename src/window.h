/**
	@file		window.h
	@author		Matthew Hinkle
 */

#ifndef __FUTILE_WINDOW_H__
#define __FUTILE_WINDOW_H__

#include "dimension2d.h"
#include "graphics.h"

namespace futile {

/**
	platform independent window abstract class
 */
class Window {
public:
	~Window();

	virtual void init() = 0;
	virtual void destroy() = 0;
	virtual void resize(const Dimension2D & dim) = 0;
	virtual void refresh() = 0;

protected:
	Window();
	Window(const Dimension2D & dim);

	Dimension2D dim;

private:
	Window(const Window &);
	Window & operator=(const Window &);
};

}

#endif
