/**
	@file		windowfactory.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_WINDOWFACTORY_H_
#define FUTILE_PLATFORM_WINDOWFACTORY_H_

#include <futile/config.h>
#include <futile/math/rectangle.h>

namespace futile {

/* Windowable class forward declaration */
class Windowable;

/**
	factory class for creating windows
 */
class WindowFactory {
public:
	~WindowFactory();

	static Windowable * create_window(const Rectangle & bounds);
	static Windowable * create_fullscreen_window();

private:
	WindowFactory();
	WindowFactory(const WindowFactory &);
	WindowFactory & operator=(const WindowFactory &);
};

}

#endif
