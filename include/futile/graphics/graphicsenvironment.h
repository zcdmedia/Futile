/**
	@file		graphicsenvironment.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_GRAPHICSENVIRONMENT_H_
#define FUTILE_GRAPHICS_GRAPHICSENVIRONMENT_H_

#include <futile/math/vector2.h>
#include <futile/graphics/graphics.h>

namespace futile {

/**
	graphics environment abstract class
 */
class GraphicsEnvironment {
public:
	virtual ~GraphicsEnvironment();

	/* accessors */
	const Vector2 & get_dim() const { return this->dim; }

	/* methods */
	virtual void init() = 0;
	virtual void resize(const Vector2 & dim) = 0;
	virtual void refresh() = 0;

protected:
	GraphicsEnvironment();
	GraphicsEnvironment(const Vector2 & dim);

	Vector2 dim;
};

}

#endif
