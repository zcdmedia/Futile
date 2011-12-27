/**
	@file		pixelalignment.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_PIXELALIGNMENT_H_
#define FUTILE_GRAPHICS_PIXELALIGNMENT_H_

namespace futile {

/**
	specifies alignment criteria for storing pixels in memory.  used with
	calls to glPixelStorei
 */
class PixelAlignment {
public:
	static const int BYTE = 1;
	static const int EVEN = 2;
	static const int WORD = 4;
	static const int DOUBLE_WORD = 8;
};

}

#endif
