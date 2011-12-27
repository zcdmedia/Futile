/**
	@file		texture.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_TEXTURE_H_
#define FUTILE_GRAPHICS_TEXTURE_H_

#include <string>

#include <futile/asset.h>
#include <futile/rawbuffer.h>
#include <futile/math/vector2.h>

namespace futile {

/**
	texture asset abstract class
 */
class Texture : public Asset {
public:
	explicit Texture(const std::string & name);
	~Texture();

	/* accessors */
	inline const Vector2 & get_dim() const { return this->dim; }

	/* methods */
	virtual void init() = 0;

	/* interfaces */
	virtual RawBuffer * serialize() const { return NULL; }
	virtual Asset * deserialize(const RawBuffer & data) { return NULL; }

public:
	RawBuffer image_data;
	Vector2 dim;

private:

	Texture(const Texture &);
	Texture & operator=(const Texture &);
};

}

#endif
