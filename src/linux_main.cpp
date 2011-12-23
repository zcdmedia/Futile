#include <futile/config.h>
#include <futile/graphics/graphicsenvironment.h>
#include <futile/graphics/graphicsenvironmentfactory.h>
#include <futile/platform/windowable.h>
#include <futile/platform/windowfactory.h>

/* internal prototypes */
static inline void render(futile::Windowable *, GLfloat);

int main()
{
	futile::GraphicsEnvironment * gfxenv =
		futile::GraphicsEnvironmentFactory::create_opengl_environment();

	futile::Windowable * window =
		futile::WindowFactory::create_fullscreen_window(gfxenv);
	window->init();

	GLfloat rotation_quad = 0.0f;
	while(rotation_quad < 500.0f) {
		render(window, rotation_quad);
		rotation_quad += 0.8f;
	}

	delete window;

	return 0;
}


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