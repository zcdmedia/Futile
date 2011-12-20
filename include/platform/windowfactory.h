/**
	@file		windowfactory.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_WINDOWFACTORY_H_
#define FUTILE_WINDOWFACTORY_H_

#include "dimension2d.h"
#include "platform/window.h"

namespace futile {

/**
	factory class for creating windows
 */
class WindowFactory {
public:
	~WindowFactory();

	static Window * create_window(const Dimension2D & dim);

	static Window * create_fullscreen_window();

private:
	WindowFactory(const WindowFactory &);
	WindowFactory & operator=(const WindowFactory &);
};

}

#endif
