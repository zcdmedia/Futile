#include <futile/graphics/texture2d.h>

#include "pixelalignment.h"

/* constants */
static const GLsizei SINGLE_TEXTURE = 1;
static const GLint BORDER = 0;

namespace futile {

Texture2D::Texture2D(const std::string & name) : Texture(name) { }

Texture2D::~Texture2D() { }

/* methods */
void Texture2D::init()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, PixelAlignment::BYTE);
	glGenTextures(SINGLE_TEXTURE, &this->texture_name);
	glBindTexture(GL_TEXTURE_2D, this->texture_name);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	const Vector2 & dim = this->get_dim();
	GLsizei width = static_cast<GLsizei>(dim.x);
	GLsizei height = static_cast<GLsizei>(dim.y);

	const std::vector<char> & image_data = this->image_data.get_data();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, BORDER, GL_RGBA,
                     GL_UNSIGNED_BYTE, &image_data[0]);
}

}
