#include <futile/color.h>

namespace futile {

Color::Color()
{
	this->set(0, 0, 0, 0);
}

Color::Color(int red, int green, int blue)
{
	this->set(red, green, blue, 0);
}

Color::Color(int red, int green, int blue, int alpha)
{
	this->set(red, green, blue, alpha);
}

/* access */
float Color::get_redf() const
{
	return this->red / static_cast<float>((Color::BASE - 1));
}

float Color::get_greenf() const
{
	return this->green / static_cast<float>((Color::BASE - 1));
}

float Color::get_bluef() const
{
	return this->blue / static_cast<float>((Color::BASE - 1));
}

float Color::get_alphaf() const
{
	return this->alpha / static_cast<float>((Color::BASE) - 1);
}

/* mutators */
void Color::set(int red, int green, int blue)
{
	this->set(red, green, blue, 0);
}

void Color::set(int red, int green, int blue, int alpha)
{
	this->set_red(red);
	this->set_green(green);
	this->set_blue(blue);
	this->set_alpha(alpha);
}

void Color::set_red(int red)
{
	assert(red >= 0 && red < Color::BASE);

	this->red = red;
}

void Color::set_green(int green)
{
	assert(green >= 0 && green < Color::BASE);

	this->green = green;
}

void Color::set_blue(int blue)
{
	assert(blue >= 0 && blue < Color::BASE);

	this->blue = blue;
}

void Color::set_alpha(int alpha)
{
	assert(alpha >= 0 && alpha < Color::BASE);

	this->alpha = alpha;
}

void Color::set_redf(float red)
{
	assert(red >= 0.0f && red <= 1.0f);

	this->red = floor(red * (Color::BASE - 1));
}

void Color::set_greenf(float green)
{
	assert(green >= 0.0f && green <= 1.0f);

	this->green = floor(green * (Color::BASE - 1));
}

void Color::set_bluef(float blue)
{
	assert(blue >= 0.0f && blue <= 1.0f);

	this->blue = floor(blue * (Color::BASE - 1));
}

void Color::set_alphaf(float alpha)
{
	assert(alpha >= 0.0f && alpha <= 1.0f);

	this->alpha = floor(alpha * (Color::BASE - 1));
}

/* interfaces */
Color * Color::clone() const
{
	return new Color(this->red, this->blue, this->green, this->alpha);
}

bool Color::equals(const Color & c) const
{
	return this->red == c.red
               && this->blue == c.blue
               && this->green == c.green
               && this->alpha == c.alpha;
}

}
