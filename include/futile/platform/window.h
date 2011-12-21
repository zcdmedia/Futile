/**
	@file		window.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_WINDOW_H_
#define FUTILE_PLATFORM_WINDOW_H_

#include <futile/graphics.h>
#include <futile/math/vector2.h>

namespace futile {

/**
	display window interface
 */
class Window {
public:
	virtual ~Window() { }

	/* access */
	virtual const Vector2 & get_dim() const = 0;
	virtual const Vector2 & get_pos() const = 0;

	/* methods */
	virtual void init() = 0;
	virtual void destroy() = 0;
	virtual void reposition(const Vector2 & pos) = 0;
	virtual void resize(const Vector2 & dim) = 0;
	virtual void refresh() const = 0;

protected:
	Window() { }

private:
	Window(const Window &);
	Window & operator=(const Window &);
};

}

#endif
