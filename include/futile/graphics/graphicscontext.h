/**
	@file		graphicscontext.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_GRAPHICSCONTEXT_H_
#define FUTILE_GRAPHICS_GRAPHICSCONTEXT_H_

#include <futile/math/transform.h>
#include <futile/math/matrix4.h>
#include <futile/math/vector2.h>
#include <futile/graphics/graphics.h>

namespace futile {

/**
	graphics environment
 */
class GraphicsContext {
public:
	GraphicsContext();
	GraphicsContext(const Vector2 & dim);
	virtual ~GraphicsContext();

	/* accessors */
	const Vector2 & get_dim() const { return this->dim; }

	/* methods */
	virtual void init();
	virtual void resize(const Vector2 & dim);
	virtual void refresh();

private:
	GraphicsContext(const GraphicsContext &);
	GraphicsContext & operator=(const GraphicsContext &);

	Vector2 dim;
};

}

#endif
