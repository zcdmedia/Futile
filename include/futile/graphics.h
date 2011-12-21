/**
	@file		graphics.h
	@author		Matthew Hinkle
	@brief		platform independent include for the graphics library
 */

#ifndef FUTILE_GRAPHICS_H_
#define FUTILE_GRAPHICS_H_

/* futile configuration */
#include "config.h"

/* opengl headers */
#if Futile_APPLE
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
#elif Futile_WIN32
# include <gl/gl.h>
# include <gl/glu.h>
# include <gl/glaux.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glx.h>
#endif

/* windows headers */
#if Futile_WIN32
# include <windows.h>
#endif

#endif
