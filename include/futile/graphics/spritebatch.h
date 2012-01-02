/**
	@file		spritebatch.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_SPRITEBATCH_H_
#define FUTILE_GRAPHICS_SPRITEBATCH_H_

#include <cassert>

#include <futile/color.h>
#include <futile/graphics/graphics.h>
#include <futile/graphics/texture2d.h>
#include <futile/math/math.h>
#include <futile/math/matrix4.h>
#include <futile/math/rectangle.h>
#include <futile/math/transform.h>
#include <futile/math/vector2.h>
#include <futile/math/vector4.h>

namespace futile {

class SpriteBatch {
public:
	SpriteBatch();
	~SpriteBatch();

	/* methods */
	void begin();
	void begin(const Matrix4 & transform);
	void draw(const Texture2D & texture, const Vector2 & pos);
	void draw(const Texture2D & texture, const Rectangle & destination);
	void draw(const Texture2D & texture, const Rectangle & destination,
                  const Rectangle & source);
	void end();
};

}

#endif
