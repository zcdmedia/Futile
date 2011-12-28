/**
	@file		spritebatch.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_SPRITEBATCH_H_
#define FUTILE_GRAPHICS_SPRITEBATCH_H_

#include <futile/graphics/graphics.h>
#include <futile/graphics/texture2d.h>
#include <futile/math/matrix4.h>
#include <futile/math/rectangle.h>

namespace futile {

class SpriteBatch {
public:
	SpriteBatch();
	~SpriteBatch();

	/* methods */
	void begin();
	void draw(const Texture2D & texture, const Rectangle & destination);
	void end();
};

}

#endif
