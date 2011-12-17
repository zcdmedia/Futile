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

	/* accessors */
	virtual bool is_fullscreen() const;

	/* methods */
	virtual void init() = 0;
	virtual void destroy() = 0;
	virtual void resize(const Dimension2D & dim) = 0;
	virtual void refresh() const = 0;

	static const int DEFAULT_DIM = 1;

protected:
	Window();
	explicit Window(const Dimension2D & dim);
	Window(const Dimension2D & dim, bool fullscreen);

	Dimension2D dim;

	bool fullscreen;

private:
	Window(const Window &);
	Window & operator=(const Window &);
};

}

#endif
