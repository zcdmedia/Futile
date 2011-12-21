/**
	@file		windowfactory.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_WINDOWFACTORY_H_
#define FUTILE_WINDOWFACTORY_H_

#include <futile/config.h>
#include <futile/math/vector2.h>

namespace futile {

/* Window class forward declaration */
class Window;

/**
	factory class for creating windows
 */
class WindowFactory {
public:
	~WindowFactory();

	static Window * create_window(const Vector2 & dim);

	static Window * create_fullscreen_window();

private:
	WindowFactory(const WindowFactory &);
	WindowFactory & operator=(const WindowFactory &);
};

}

#endif
