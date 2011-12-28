/**
	@file		matrix4.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_MATRIX4_H_
#define FUTILE_MATH_MATRIX4_H_

#include <algorithm>
#include <cassert>

#include <futile/cloneable.h>
#include <futile/equatable.h>
#include <futile/math/mathhelper.h>
#include <futile/math/tuple3.h>
#include <futile/math/tuple4.h>
#include <futile/math/vector3.h>
#include <futile/math/vector4.h>

namespace futile {

/**
	4x4 column-major matrix
 */
class Matrix4 : public Cloneable<Matrix4 *>, public Equatable<const Matrix4 &> {
public:
	Matrix4();
	~Matrix4();

	/* operator overloads */
	float operator()(int row, int col) const;
	float & operator()(int row, int col);

	/* accessors */
	float get(int row, int col) const;
	Vector4 * get_col(int col) const;
	Vector4 * get_row(int row) const;
	inline float * get_values() { return this->values; }

	/* mutators */
	void set(int row, int col, float value);
	void set(const Matrix4 & m);
	void set_col(int col, const Vector3 & v);
	void set_col(int col, const Vector4 & v);
	void set_row(int row, const Vector3 & v);
	void set_row(int row, const Vector4 & v);

	/* methods */
	void add(float scalar);
	void add(const Matrix4 & m);
	float determinant() const;
	float get_scale() const;
	void invert();
	void identity();
	void mul(float scalar);
	void mul(const Matrix4 & m);
	void negate();
	void normalize();
	void rot_x(float angle);
	void rot_y(float angle);
	void rot_z(float angle);
	void scale(const Tuple3 & t);
	void sub(float scalar);
	void sub(const Matrix4 & m);
	void transform(Tuple4 * t);
	void translate(const Tuple3 & t);
	void transpose();
	void zero();

	/* interfaces */
	virtual Matrix4 * clone() const;
	virtual bool equals(const Matrix4 & m) const;

	static const int NUM_COLS = 4;
	static const int SIZE = Matrix4::NUM_COLS * Matrix4::NUM_COLS;

private:
	float values[Matrix4::SIZE];
	float * values_begin;
	float * values_end;

	Matrix4(const Matrix4 &);
	Matrix4 & operator=(const Matrix4 &);
};

}

#endif
