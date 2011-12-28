#include <futile/math/transform.h>

/**
	GLU replacement code was snagged from www.opengl.org/wiki
 */

namespace futile {

void Transform::look_at(const Vector3 & eye, const Vector3 & center,
                        const Vector3 & up, Matrix4 * m)
{
	Vector3 forward;
	forward.set(center);
	forward.sub(eye);
	forward.normalize();

	Vector3 side;
	side.cross(forward, up);
	side.normalize();

	Vector3 upvec;
	upvec.cross(side, forward);

	Matrix4 xform;
	xform.identity();
	xform.set_row(0, side);
	xform.set_row(1, upvec);

	forward.negate();
	xform.set_row(2, forward);

	m->mul(xform);

	Vector3 neg_eye;
	neg_eye.set(eye);
	neg_eye.negate();

	Matrix4 xlate;
	xlate.translate(neg_eye);
	m->mul(xlate);
}

void Transform::perspective(float fov_deg, float aspect, float znear,
                            float zfar, Matrix4 * m)
{
	float ymax = znear * std::tan(fov_deg * Math::PI_OVER_360);
	float xmax = ymax * aspect;

	Transform::frustum(-xmax, xmax, -ymax, ymax, znear, zfar, m);
}

void Transform::frustum(float left, float right, float bottom, float top,
                        float znear, float zfar, Matrix4 * m)
{
	m->zero();
	float znear2 = 2.0 * znear;
	float zdist = zfar - znear;
	float width = right - left;
	float height = top - bottom;

	float * values = m->get_values();
	values[0] = znear2 / width;
	values[5] = znear2 / height;
	values[8] = (right + left) / width;
	values[9] = (top + bottom) / height;
	values[10] = (-zfar - znear) / zdist;
	values[11] = -1.0f;
	values[14] = (-znear2 * zfar) / zdist;
}

}
