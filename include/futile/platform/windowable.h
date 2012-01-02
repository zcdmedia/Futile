/**
	@file		windowable.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_WINDOWABLE_H_
#define FUTILE_PLATFORM_WINDOWABLE_H_

#include <futile/graphics/graphics.h>
#include <futile/math/rectangle.h>

namespace futile {

/**
	display window interface
 */
class Windowable {
public:
	Windowable() { }
	virtual ~Windowable() { }

	/* methods */
	virtual void init() = 0;
	virtual void destroy() = 0;
	virtual void move(const Rectangle & bounds) = 0;
	virtual void refresh() = 0;

private:
	Windowable(const Windowable &);
	Windowable & operator=(const Windowable &);
};

}

#endif
