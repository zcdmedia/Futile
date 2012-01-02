/**
	@file		tranform.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_TRANSFORM_H_
#define FUTILE_MATH_TRANSFORM_H_

#include <futile/graphics/graphics.h>
#include <futile/math/matrix4.h>
#include <futile/math/vector3.h>

namespace futile {

/**
	matrix transformations
 */
class Transform {
public:
	/* methods */
	static inline void load_matrix(const Matrix4 & m)
	{
		Matrix4 copy;
		copy.set(m);

		glLoadMatrixf(copy.get_values());
	}

	static void look_at(const Vector3 & eye, const Vector3 & center,
                            const Vector3 & up, Matrix4 * m);

	static void perspective(float fov_deg, float aspect, float znear,
                                float zfar, Matrix4 * m);

	static void frustum(float left, float right, float bottom, float top,
                            float znear, float zfar, Matrix4 * m);

private:
	Transform();
	Transform(const Transform &);
	Transform & operator=(const Transform &);
};

}

#endif
