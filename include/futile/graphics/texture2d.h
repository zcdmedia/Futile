/**
	@file		texture2d.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_TEXTURE2D_H_
#define FUTILE_GRAPHICS_TEXTURE2D_H_

#include <string>

#include <futile/rawbuffer.h>
#include <futile/graphics/graphics.h>
#include <futile/graphics/texture.h>

namespace futile {

/**
	2-dimensional image that may be drawn to screen
 */
class Texture2D : public Texture {
public:
	explicit Texture2D(const std::string & name);
	~Texture2D();

	/* access */
	inline GLuint get_texture_name() const { return this->texture_name; }

	/* methods */
	virtual void init();

	/* interfaces */
	virtual RawBuffer * serialize() const { }
	virtual Asset * deserialize(const RawBuffer & data) { }

private:
	GLuint texture_name;

	Texture2D(const Texture2D &);
	Texture2D & operator=(const Texture2D &);
};

}

#endif
