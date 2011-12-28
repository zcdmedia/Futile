/**
	@file		rectangle.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_RECTANLGE_H_
#define FUTILE_MATH_RECTANLGE_H_

#include <futile/equatable.h>
#include <futile/math/point2.h>

namespace futile {

/**
	rectangular quadrilateral
 */
class Rectangle : public Equatable<const Rectangle &> {
public:
	Rectangle();
	Rectangle(int x, int y, int width, int height);
	~Rectangle();

	/* methods */
	inline Point2 * center() const
	{
		return new Point2(this->width / 2.0f, this->height / 2.0f);
	}

	inline bool empty() const
	{
		return this->width == 0 && this->height == 0;
	}

	inline int bottom() const { return this->y + this->height; }
	inline int left() const { return this->x; }
	inline int right() const { return this->x + this->width; }
	inline int top() const { return this->y; }

	/* interfaces */
	virtual bool equals(const Rectangle & r) const;

	int x;
	int y;
	int width;
	int height;

private:
	Rectangle(const Rectangle &);
	Rectangle & operator=(const Rectangle &);
};

}

#endif
