/**
	@file		graphicscontext2d.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_GRAPHICSCONTEXT2D_H_
#define FUTILE_GRAPHICS_GRAPHICSCONTEXT2D_H_

#include <futile/graphics/graphicscontext.h>

namespace futile {

class GraphicsContext2D : public GraphicsContext {
public:
	GraphicsContext2D();
	GraphicsContext2D(const Vector2 & dim);
	virtual ~GraphicsContext2D();

	/* methods */
	virtual void init();
	virtual void resize(const Vector2 & dim);
	virtual void refresh();

private:
	GraphicsContext2D(const GraphicsContext2D &);
	GraphicsContext2D & operator=(const GraphicsContext2D &);
};

}

#endif
