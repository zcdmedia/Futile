#include <futile/camera/camera2d.h>

namespace futile {

/* member constants */
const float Camera2D::EYE_Z = 4.0f;
const float Camera2D::MIN_ZOOM = 0.01;

Camera2D::Camera2D(GraphicsDevice * graphics_device)
{
	assert(graphics_device);
	this->graphics_device = graphics_device;

	this->pos.set(0.0f, 0.0f, Camera2D::EYE_Z);
	this->rot = 0.0f;
	this->zoom = 1.0f;
}

Camera2D::~Camera2D() { }

/* mutators */
void Camera2D::set_pos(const Vector2 & pos)
{
	this->pos.set(pos.x, pos.y, Camera2D::EYE_Z);
}

void Camera2D::set_rot(float rot)
{
	this->rot = Math::wrap_angle(rot);
}

void Camera2D::set_zoom(float zoom)
{
	this->zoom = std::max(zoom, Camera2D::MIN_ZOOM);
}

/* methods */
Vector2 * Camera2D::get_view_pos()
{
	assert(this->graphics_device);
	const Rectangle & bounds =
		this->graphics_device->get_viewport()->get_bounds();
	Point2 * center = bounds.center();

	Vector2 * pos = new Vector2(center->x, center->y);

	delete center;

	return pos;
}

Rectangle * Camera2D::get_view_area()
{
	assert(this->graphics_device);
	const Rectangle & bounds =
		this->graphics_device->get_viewport()->get_bounds();

	Vector2 * pos = this->get_view_pos();

	Rectangle * view_area = new Rectangle(
		static_cast<int>(pos->x),
		static_cast<int>(pos->y),
		bounds.width,
		bounds.height
	);

	delete pos;

	return view_area;
}

Point2 * Camera2D::get_view_center()
{
	assert(this->graphics_device);
	const Rectangle & bounds =
		this->graphics_device->get_viewport()->get_bounds();

	Point2 * center = bounds.center();
	center->x += this->pos.x;
	center->y += this->pos.y;

	return center;
}

/* interfaces */
void Camera2D::update(const GameTime & gt)
{
	this->update_transform();
}

void Camera2D::update_transform()
{
	Vector3 neg_pos;
	neg_pos.set(this->pos);
	neg_pos.negate();

	Matrix4 pos;
	pos.translate(neg_pos);

	Matrix4 rot;
	rot.rot_z(this->rot);

	Matrix4 scale;
	scale.scale((Vector3(this->zoom, this->zoom, 0.0f)));

	Point2 * center = this->get_view_center();
	Matrix4 xlate;

	assert(this->graphics_device);
	const Rectangle & bounds =
		this->graphics_device->get_viewport()->get_bounds();
	assert(bounds.width > 0 && bounds.height > 0);
	Vector3 c(center->x / bounds.width, center->y / bounds.height, 0.0f);
	c.negate();
	xlate.translate(c);
	delete center;

	this->transform.identity();
	this->transform.mul(pos);
	this->transform.mul(rot);
	this->transform.mul(scale);
	this->transform.mul(xlate);
}

}
