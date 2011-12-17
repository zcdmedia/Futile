/**
	@file		graphics.h
	@author		Matthew Hinkle
	@brief		platform independent include for the graphics library
 */

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

/* include opengl header files */
#include <GL/gl.h>	/* opengl */
#include <GL/glu.h>
#include <GL/glx.h>	/* hardware acceleration */

#ifdef WIN32
# include <windows.h>
# include <TCHAR.h>
#endif

#endif
