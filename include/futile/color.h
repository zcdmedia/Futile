/**
	@file		color.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_COLOR_H_
#define FUTILE_COLOR_H_

#include <cassert>
#include <cmath>

#include <futile/cloneable.h>
#include <futile/equatable.h>

namespace futile {

/**
	4 component color represented by red, green, blue, and alpha.
	Color values are base 256 (in range [0, 255])
 */
class Color : public Cloneable<Color *>, public Equatable<const Color &> {
public:
	Color();
	Color(int red, int green, int blue);
	Color(int red, int green, int blue, int alpha);
	~Color();

	/* access */
	inline int get_red() const { return this->red; }
	inline int get_green() const { return this->green; }
	inline int get_blue() const { return this->blue; }
	inline int get_alpha() const { return this->alpha; }

	float get_redf() const;
	float get_greenf() const;
	float get_bluef() const;
	float get_alphaf() const;

	/* mutators */
	void set(int red, int green, int blue);
	void set(int red, int green, int blue, int alpha);
	void set_red(int red);
	void set_green(int green);
	void set_blue(int blue);
	void set_alpha(int alpha);

	void set_redf(float red);
	void set_greenf(float green);
	void set_bluef(float blue);
	void set_alphaf(float alpha);

	/* interfaces */
	virtual Color * clone() const;
	virtual bool equals(const Color & c) const;

	static const int BASE = 256;

private:
	int red;
	int green;
	int blue;
	int alpha;

	Color(const Color &);
	Color & operator=(const Color &);
};

}

#endif
