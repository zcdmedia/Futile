/**
	@file		dimension2d.h
	@author		Matthew Hinkle
	@brief		simple 2D geometric measurement
 */

#ifndef __DIMENSION2D_H__
#define __DIMENSION2D_H__

#include <cassert>

namespace futile {

class Dimension2D {
public:
	Dimension2D();
	explicit Dimension2D(int dim);
	Dimension2D(int width, int height);
	Dimension2D(const Dimension2D & dim);
	Dimension2D & operator=(const Dimension2D & dim);
	~Dimension2D();

	/* accessors */
	int get_width() const;
	int get_height() const;

	/* modifiers */
	void set_width(int width);
	void set_height(int height);
private:
	int width;
	int height;
};

}

#endif
