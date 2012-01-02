#include <futile/graphics/spritebatch.h>

/* internal prototypes */
static void draw_texture(const futile::Vector2 & destpos,
                         const futile::Vector2 & destdim,
                         const futile::Vector2 & srcpos,
                         const futile::Vector2 & srcdim);

namespace futile {

SpriteBatch::SpriteBatch() { }

SpriteBatch::~SpriteBatch() { }

/* methods */
void SpriteBatch::begin()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void SpriteBatch::begin(const Matrix4 & transform)
{
	this->begin();
	Transform::load_matrix(transform);
}

void SpriteBatch::draw(const Texture2D & texture, const Vector2 & pos)
{
	const Vector2 & dim = texture.get_dim();
	assert(dim.x != 0.0f && dim.y != 0.0f);

	Vector2 destpos(pos.x / dim.x, pos.y / dim.y);
	Vector2 destdim(dim.x / dim.y, dim.y / dim.x);
	Vector2 srcpos(0.0f, 0.0f);
	Vector2 srcdim(1.0f, 1.0f);

	glBindTexture(GL_TEXTURE_2D, texture.get_texture_name());
	draw_texture(destpos, destdim, srcpos, srcdim);
}

void SpriteBatch::draw(const Texture2D & texture, const Rectangle & destination)
{
	const Vector2 & dim = texture.get_dim();
	assert(dim.x != 0.0f && dim.y != 0.0f);

	Vector2 destpos(destination.x / dim.x, destination.y / dim.y);
	Vector2 destdim(destination.width / dim.x, destination.y / dim.y);
	Vector2 srcpos(0.0f, 0.0f);
	Vector2 srcdim(1.0f, 1.0f);

	glBindTexture(GL_TEXTURE_2D, texture.get_texture_name());
	draw_texture(destpos, destdim, srcpos, srcdim);
}

void SpriteBatch::draw(const Texture2D & texture, const Rectangle & destination,
                       const Rectangle & source)
{
	const Vector2 & dim = texture.get_dim();
	assert(dim.x != 0.0f && dim.y != 0.0f);

	Vector2 destpos(destination.x / dim.x, destination.y / dim.y);
	Vector2 destdim(destination.width / dim.x, destination.y / dim.y);
	Vector2 srcpos(source.x / dim.x, source.y / dim.y);
	Vector2 srcdim(source.width / dim.x, source.height / dim.y);

	glBindTexture(GL_TEXTURE_2D, texture.get_texture_name());
	draw_texture(destpos, destdim, srcpos, srcdim);
}

void SpriteBatch::end()
{
	glDisable(GL_TEXTURE_2D);
	glFlush();
	Matrix4 m;
	m.identity();
	Transform::load_matrix(m);
}

}

/* internal */
static void draw_texture(const futile::Vector2 & destpos,
                         const futile::Vector2 & destdim,
                         const futile::Vector2 & srcpos,
                         const futile::Vector2 & srcdim)
{
	glBegin(GL_QUADS);
	/* top-left */
	glTexCoord2d(srcpos.x, srcpos.y);
	float vertex_top = destpos.y + destdim.y;
	glVertex3f(destpos.x, vertex_top, 0.0f);

	/* top-right */
	float texture_right = srcpos.x + srcdim.x;
	glTexCoord2d(texture_right, srcpos.y);
	float vertex_left = destpos.x + destdim.x;
	glVertex3f(vertex_left, vertex_top, 0.0f);

	/* bottom-right */
	float texture_bottom = srcpos.y + srcdim.y;
	glTexCoord2d(texture_right, texture_bottom);
	glVertex3f(vertex_left, destpos.y, 0.0f);

	/* bottom-left */
	glTexCoord2d(srcpos.x, texture_bottom);
	glVertex3f(destpos.x, destpos.y, 0.0f);
	glEnd();
}
