/**
	@file		graphics.h
	@author		Matthew Hinkle
	@brief		platform independent header for the graphics library
 */

#ifndef FUTILE_GRAPHICS_H_
#define FUTILE_GRAPHICS_H_

/* futile configuration */
#include <futile/config.h>

/* opengl headers */
#if Futile_APPLE
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
#elif Futile_WIN32
# include <gl/gl.h>
# include <gl/glu.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glx.h>
#endif

#endif
