#include <futile/graphics/viewport.h>

namespace futile {

Viewport::Viewport(const Rectangle & bounds)
{
	this->init();
	this->yfield_of_view = 90.0f;
	this->min_depth = 0.1f;
	this->max_depth = 100.0f;
	this->set_bounds(bounds);
}

Viewport::~Viewport() { }

/* mutators */
void Viewport::set_bounds(const Rectangle & bounds)
{
	this->bounds.set(bounds);
	this->update();
}

void Viewport::set_max_depth(float max_depth)
{
	this->max_depth = max_depth;
	this->update();
}

void Viewport::set_min_depth(float min_depth)
{
	this->min_depth = min_depth;
	this->update();
}

void Viewport::set_yfield_of_view(float yfield_of_view)
{
	this->yfield_of_view = yfield_of_view;
	this->update();
}

/* interfaces */
bool Viewport::equals(const Viewport & vp) const
{
	return this->bounds.equals(vp.bounds)
               && this->aspect_ratio == vp.aspect_ratio
               && this->max_depth == vp.max_depth
               && this->min_depth == vp.min_depth
               && this->yfield_of_view == vp.yfield_of_view;
}

void Viewport::set(const Viewport & vp)
{
	this->bounds.set(vp.bounds);
	this->aspect_ratio = vp.aspect_ratio;
	this->max_depth = vp.max_depth;
	this->min_depth = vp.min_depth;
	this->yfield_of_view = vp.yfield_of_view;
}

void Viewport::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Viewport::update()
{
	assert(this->bounds.width > 0 && this->bounds.height > 0);

	glViewport(this->bounds.x, this->bounds.y,
                   this->bounds.width, this->bounds.height);
	glMatrixMode(GL_PROJECTION);

	Matrix4 m;
	m.identity();
	Transform::load_matrix(m);

	this->aspect_ratio = static_cast<float>(this->bounds.width)
                             / static_cast<float>(this->bounds.height);
	Transform::perspective(this->yfield_of_view, this->aspect_ratio,
                               this->min_depth, this->max_depth, &m);
	Transform::load_matrix(m);
	glMatrixMode(GL_MODELVIEW);
	m.identity();
	Transform::load_matrix(m);

	this->update_title_safe_area();
}

void Viewport::update_title_safe_area()
{
	Rectangle title_safe_area (
		Viewport::TITLE_SAFE_X,
		Viewport::TITLE_SAFE_Y,
		this->bounds.width - Viewport::TITLE_SAFE_X,
		this->bounds.height - Viewport::TITLE_SAFE_Y
	);

	this->title_safe_area.set(title_safe_area);
}

}
