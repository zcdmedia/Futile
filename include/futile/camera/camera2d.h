/**
	@file		camera2d.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_CAMERA_CAMERA2D_H_
#define FUTILE_CAMERA_CAMERA2D_H_

#include <cmath>

#include <futile/updateable.h>
#include <futile/graphics/graphicsdevice.h>
#include <futile/math/math.h>
#include <futile/math/matrix4.h>
#include <futile/math/point2.h>
#include <futile/math/rectangle.h>
#include <futile/math/vector3.h>
#include <futile/math/vector2.h>

namespace futile {

class Camera2D : public Updateable {
public:
	Camera2D(GraphicsDevice * graphicsDevice);
	~Camera2D();

	/* accessors */
	inline const Vector3 & get_pos() const { return this->pos; }
	inline float get_rot() const { return this->rot; }
	inline float get_zoom() const { return this->zoom; }
	inline const Matrix4 & get_transform() { return this->transform; }

	/* mutators */
	void set_pos(const Vector2 & pos);
	void set_rot(float rot);
	void set_zoom(float zoom);

	/* methods */
	Vector2 * get_view_pos();
	Rectangle * get_view_area();
	Point2 * get_view_center();

	/* interfaces */
	virtual void update(const GameTime & gt);

	static const float EYE_Z;
	static const float MIN_ZOOM;

private:
	void update_transform();

	GraphicsDevice * graphics_device;

	Vector3 pos;

	float rot;
	float zoom;

	Matrix4 transform;

	Camera2D(const Camera2D &);
	Camera2D & operator=(const Camera2D &);
};

}

#endif
