/**
	@file		graphicscontext3d.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_GRAPHICSCONTEXT3D_H_
#define FUTILE_GRAPHICS_GRAPHICSCONTEXT3D_H_

#include <futile/graphics/graphicscontext.h>

namespace futile {

class GraphicsContext3D : public GraphicsContext {
public:
	GraphicsContext3D();
	GraphicsContext3D(const Vector2 & dim);
	virtual ~GraphicsContext3D();

	/* methods */
	virtual void init();
	virtual void resize(const Vector2 & dim);
	virtual void refresh();
private:
	GraphicsContext3D(const GraphicsContext3D &);
	GraphicsContext3D & operator=(const GraphicsContext3D &);
};

}

#endif
