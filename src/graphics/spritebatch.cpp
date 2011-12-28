#include <futile/graphics/spritebatch.h>

namespace futile {

SpriteBatch::SpriteBatch() { }

SpriteBatch::~SpriteBatch() { }

/* methods */
void SpriteBatch::begin()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void SpriteBatch::draw(const Texture2D & texture, const Rectangle & destination)
{
	glBindTexture(GL_TEXTURE_2D, texture.get_texture_name());

	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glTexCoord2d(1, 0);
	glVertex3f(1.0f, 1.0f, 0.0f);

	glTexCoord2d(1, 1);
	glVertex3f(1.0f, 0.0f, 0.0f);

	glTexCoord2d(0, 1);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();
}

void SpriteBatch::end()
{
	glDisable(GL_TEXTURE_2D);
	glFlush();
}

}
