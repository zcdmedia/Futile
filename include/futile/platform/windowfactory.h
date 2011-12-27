/**
	@file		windowfactory.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_WINDOWFACTORY_H_
#define FUTILE_WINDOWFACTORY_H_

#include <futile/config.h>
#include <futile/graphics/graphicscontext.h>
#include <futile/math/vector2.h>

namespace futile {

/* Windowable class forward declaration */
class Windowable;

/**
	factory class for creating windows
 */
class WindowFactory {
public:
	~WindowFactory();

	static Windowable * create_window(GraphicsContext * gfxenv);
	static Windowable * create_fullscreen_window(GraphicsContext * gfxenv);

private:
	WindowFactory();
	WindowFactory(const WindowFactory &);
	WindowFactory & operator=(const WindowFactory &);
};

}

#endif
