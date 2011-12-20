/**
	@file		graphics.h
	@author		Matthew Hinkle
	@brief		platform independent include for the graphics library
 */

#ifndef FUTILE_GRAPHICS_H_
#define FUTILE_GRAPHICS_H_

/* include opengl header files */
#include <GL/gl.h>	/* opengl */
#include <GL/glu.h>
#include <GL/glx.h>	/* hardware acceleration */

#ifdef WIN32
# include <windows.h>
# include <TCHAR.h>
#endif

#endif
