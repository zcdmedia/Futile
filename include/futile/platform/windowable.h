/**
	@file		windowable.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_PLATFORM_WINDOWABLE_H_
#define FUTILE_PLATFORM_WINDOWABLE_H_

#include <futile/graphics/graphics.h>
#include <futile/math/vector2.h>

namespace futile {

/**
	display window interface
 */
class Windowable {
public:
	virtual ~Windowable() { }

	/* access */
	virtual const Vector2 & get_dim() const = 0;
	virtual const Vector2 & get_pos() const = 0;

	/* methods */
	virtual void init() = 0;
	virtual void destroy() = 0;
	virtual void reposition(const Vector2 & pos) = 0;
	virtual void resize(const Vector2 & dim) = 0;
	virtual void refresh() = 0;

protected:
	Windowable() { }

private:
	Windowable(const Windowable &);
	Windowable & operator=(const Windowable &);
};

}

#endif
