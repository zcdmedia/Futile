/**
	@file		matrix3.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_MATH_MATRIX_H_
#define FUTILE_MATH_MATRIX_H_

#include <algorithm>
#include <cassert>

#include <futile/cloneable.h>
#include <futile/equatable.h>
#include <futile/math/math.h>
#include <futile/math/vector3.h>

namespace futile {

/**
	3x3 square matrix
 */
class Matrix3 : public Cloneable<Matrix3 *>, public Equatable<const Matrix3 *> {
public:
	Matrix3();
	~Matrix3();

	/* accessors */
	float get(int row, int col) const;
	Vector3 * get_col(int col) const;
	Vector3 * get_row(int row) const;

	/* mutators */
	void set(int row, int col, float value);
	void set(const Matrix3 & m);
	void set_col(int col, const Vector3 & v);
	void set_row(int row, const Vector3 & v);

	/* methods */
	void add(float scalar);
	void add(const Matrix3 & m);
	float determinant() const;
	float get_scale() const;
	void invert();
	void identity();
	void mul(float scalar);
	void mul(const Matrix3 & m);
	void negate();
	void normalize();
	void rot_x(float angle);
	void rot_y(float angle);
	void rot_z(float angle);
	void sub(float scalar);
	void sub(const Matrix3 & m);
	void transform(const Tuple3 * t);
	void transpose();
	void zero();

	/* interfaces */
	virtual Matrix3 * clone() const;
	virtual bool equals(const Matrix3 * m) const;

	static const int DIM = 3;
	static const int SIZE = Matrix3::DIM * Matrix3::DIM;

private:
	float values[Matrix3::SIZE];
	float * values_begin;
	float * values_end;
};

}

#endif