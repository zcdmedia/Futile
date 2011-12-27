#include <futile/config.h>
#include <futile/graphics/graphicscontext.h>
#include <futile/graphics/graphicscontextfactory.h>
#include <futile/graphics/texture2d.h>
#include <futile/platform/windowable.h>
#include <futile/platform/windowfactory.h>
#include <futile/math/matrix4.h>

#include <pngio.h>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace futile;

/* internal prototypes */
static inline void render(futile::Windowable *, const Texture2D & texture);

int main()
{
	futile::GraphicsContext * gfxenv =
		futile::GraphicsContextFactory::create_3D_context(futile::Vector2(800, 600));

	futile::Windowable * window =
		futile::WindowFactory::create_window(gfxenv);
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

	GLfloat rotation_quad = 0.0f;
	while(rotation_quad < 500.0f) {
		render(window, texture);
		rotation_quad += 0.8f;
	}

	delete window;

	return 0;
}

static inline void render(futile::Windowable * window, const Texture2D & texture)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 10.0f,
                  0.0f, 0.0f, 0.0f,
                  0.0f, 1.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture.get_texture_name());

	const Vector2 & dim = texture.dim;
	float x__ = dim.x;
	float y__ = dim.y;

	glBegin(GL_QUADS);
#if 0
	glTexCoord2d(0, 0); glVertex3f(x__, y__, 0.0);
	glTexCoord2d(1, 0); glVertex3f(0.0, y__, 0.0);
	glTexCoord2d(1, 1); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2d(0, 1); glVertex3f(x__, 0.0, 0.0);
#endif

	// upper left
//	glTexCoord2d(0, 0); glVertex3f(0.0, y__ + y__, 0.0);

	// upper right
//	glTexCoord2d(1, 0); glVertex3f(x__, y__ + y__, 0.0);

	// lower right
//	glTexCoord2d(1, 1); glVertex3f(x__, y__, 0.0);

	// lower bottom
//	glTexCoord2d(0, 1); glVertex3f(0.0, y__, 0.0);

	glTexCoord2d(0, 0); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2d(1, 0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2d(1, 1); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2d(0, 1); glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glFlush();

	window->refresh();
}

#if 0
static inline void render(futile::Windowable * window, GLfloat rotation_quad)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation_quad, 1.0f, 0.5f, 0.25f);
	glBegin(GL_QUADS);
	/* top of cube */                              
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	/* bottom of cube */                           
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	/* front of cube */                            
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	/* back of cube */                             
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	/* right side of cube */                       
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	/* left side of cube */                        
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();

	window->refresh();
}
#endif
