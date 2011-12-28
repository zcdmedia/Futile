#include <futile/config.h>
#include <futile/graphics/graphicscontext.h>
#include <futile/graphics/spritebatch.h>
#include <futile/graphics/texture2d.h>
#include <futile/math/matrix4.h>
#include <futile/math/vector2.h>
#include <futile/math/vector3.h>
#include <futile/platform/windowable.h>
#include <futile/platform/windowfactory.h>

#include <pngio.h>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace futile;

/* internal prototypes */
static inline void render(futile::Windowable *, const Texture2D & texture, SpriteBatch * sb);

int main()
{
	GraphicsContext * gfxenv = new GraphicsContext(futile::Vector2(800, 600));
	Windowable * window = futile::WindowFactory::create_window(gfxenv);
	window->init();

	struct pngio_t p;
	pngio_init(&p);
	int i = pngio_read(&p, "omg.png");

	char * data = NULL;
	pngio_image_data(&p, (png_byte **) &data);

	int size = pngio_size(&p);

	stringstream ss(std::ios_base::binary | std::ios_base::in | std::ios_base::out);
	ss.write(data, size);

	Texture2D texture("first");
	texture.image_data.read(ss);
	texture.dim.x = p.width;
	texture.dim.y = p.height;
	texture.init();

	SpriteBatch sb;
	GLfloat rotation_quad = 0.0f;
	while(rotation_quad < 500.0f) {
		render(window, texture, &sb);
		rotation_quad += 0.8f;
	}

	delete window;

	return 0;
}

static inline void render(futile::Windowable * window, const Texture2D & texture, SpriteBatch * sb)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Matrix4 m;
	m.identity();
	Transform::load_matrix(&m);

	Vector3 eye(0.0f, 0.0f, 10.0f);
	Vector3 center(0.0f, 0.0f, 0.0f);
	Vector3 up(0.0f, 1.0f, 0.0f);
	Transform::look_at(eye, center, up, &m);
	Transform::load_matrix(&m);

	sb->begin();
	sb->draw(texture, Rectangle());
	sb->end();
	window->refresh();
}
