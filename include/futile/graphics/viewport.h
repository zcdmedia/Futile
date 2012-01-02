/**
	@file		viewport.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_GRAPHICS_VIEWPORT_H_
#define FUTILE_GRAPHICS_VIEWPORT_H_

#include <futile/equatable.h>
#include <futile/settable.h>
#include <futile/graphics/graphics.h>
#include <futile/math/rectangle.h>
#include <futile/math/transform.h>

namespace futile {

/**
	rendered area containing content
 */
class Viewport : public Equatable<const Viewport &>, public Settable<const Viewport &>{
public:
	Viewport();
	explicit Viewport(const Rectangle & bounds);
	~Viewport();

	/* accessors */
	inline float get_aspect_ratio() const { return this->aspect_ratio; }
	inline const Rectangle & get_bounds() const { return this->bounds; }
	inline float get_max_depth() const { return this->max_depth; }
	inline float get_min_depth() const { return this->min_depth; }
	inline const Rectangle & get_title_safe_area() const
	{
		return this->title_safe_area;
	}

	inline float get_yfield_of_view() const { return this->yfield_of_view; }

	/* mutators */
	void set_bounds(const Rectangle & bounds);
	void set_max_depth(float max_depth);
	void set_min_depth(float min_depth);
	void set_yfield_of_view(float yfield_of_view);

	/* interfaces */
	virtual bool equals(const Viewport & vp) const;
	virtual void set(const Viewport & vp);

	static const int TITLE_SAFE_X = 128;	/* pixels */
	static const int TITLE_SAFE_Y = 72;	/* pixels */

private:
	void init();
	void update();
	void update_title_safe_area();

	float aspect_ratio;
	float max_depth;			/* z far value */
	float min_depth;			/* z near value */
	float yfield_of_view;

	Rectangle bounds;
	Rectangle title_safe_area;

	Viewport(const Viewport &);
	Viewport & operator=(const Viewport &);
};

}

#endif
