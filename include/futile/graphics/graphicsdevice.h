/**
	@file		graphicsdevice.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_GRAPHICSDEVICE_H_
#define FUTILE_GRAPHICS_GRAPHICSDEVICE_H_

#include <futile/equatable.h>
#include <futile/settable.h>
#include <futile/graphics/viewport.h>

namespace futile {

class GraphicsDevice : public Equatable<const GraphicsDevice &>, public Settable<const GraphicsDevice &> {
public:
	GraphicsDevice();
	~GraphicsDevice();

	/* access */
	inline Viewport * get_viewport() { return &this->viewport; }

	/* mutators */
	void set_viewport(const Viewport & vp);

	/* interfaces */
	virtual bool equals(const GraphicsDevice & gd) const;
	virtual void set(const GraphicsDevice & gd);

private:
	Viewport viewport;

	GraphicsDevice(const GraphicsDevice &);
	GraphicsDevice & operator=(const GraphicsDevice &);
};

}

#endif
