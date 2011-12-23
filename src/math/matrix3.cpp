#include <futile/math/matrix3.h>

namespace futile {

Matrix3::Matrix3()
{
	this->values_begin = this->values;
	this->values_end = this->values + Matrix3::SIZE;
	this->zero();
}

Matrix3::~Matrix3() { }

/* accessors */
float Matrix3::get(int row, int col) const
{
	assert(row >= 0 && row < Matrix3::DIM);
	assert(col >= 0 && col < Matrix3::DIM);

	return this->values[(row * Matrix3::DIM) + col];
}

Vector3 * Matrix3::get_col(int col) const
{
	assert(col >= 0 && col < Matrix3::DIM);

	float x = this->get(0, col);
	float y = this->get(1, col);
	float z = this->get(2, col);

	return new Vector3(x, y, z);
}

Vector3 * Matrix3::get_row(int row) const
{
	assert(row >= 0 && row < Matrix3::DIM);

	float x = this->get(row, 0);
	float y = this->get(row, 1);
	float z = this->get(row, 2);

	return new Vector3(x, y, z);
}

/* mutators */
void Matrix3::set(int row, int col, float value)
{
	assert(row >= 0 && row < Matrix3::DIM);
	assert(col >= 0 && col < Matrix3::DIM);

	this->values[(row * Matrix3::DIM) + col] = value;
}

void Matrix3::set(const Matrix3 & m)
{
	std::copy(m.values_begin, m.values_end, this->values_begin);
}

void Matrix3::set_col(int col, const Vector3 & v)
{
	assert(col >= 0 && col <= Matrix3::DIM);

	this->set(0, col, v.x);
	this->set(1, col, v.y);
	this->set(2, col, v.z);
}

void Matrix3::set_row(int row, const Vector3 & v)
{
	assert(row >= 0 && row <= Matrix3::DIM);

	this->set(row, 0, v.x);
	this->set(row, 1, v.y);
	this->set(row, 2, v.z);
}

void Matrix3::add(float scalar)
{
	for(int i = 0; i < Matrix3::SIZE; i++) {
		this->values[i] += scalar;
	}
}

void Matrix3::add(const Matrix3 & m)
{
	for(int i = 0; i < Matrix3::SIZE; i++) {
		this->values[i] += m.values[i];
	}
}

float Matrix3::determinant() const
{
	float a = this->get(0, 0) * this->get(1, 1) * this->get(2, 2);
	float b = this->get(0, 1) * this->get(1, 2) * this->get(2, 0);
	float c = this->get(0, 2) * this->get(1, 0) * this->get(2, 1);

	float d = this->get(2, 0) * this->get(1, 1) * this->get(0, 2);
	float e = this->get(0, 1) * this->get(1, 0) * this->get(2, 2);
	float f = this->get(0, 0) * this->get(1, 2) * this->get(2, 1);

	return a + b + c - d - e - f;
}

float Matrix3::get_scale() const
{
}

void Matrix3::invert()
{
	float determinant = this->determinant();
	if(determinant == 0) return;

	Matrix3 * t = this->clone();

	float a = t->get(0, 0) * t->get(2, 2) - t->get(1, 2) * t->get(2, 1);
	float b = t->get(1, 2) * t->get(2, 0) - t->get(1, 0) * t->get(2, 2);
	float c = t->get(1, 0) * t->get(2, 1) - t->get(1, 1) * t->get(2, 0);

	float d = t->get(0, 2) * t->get(2, 1) - t->get(0, 1) * t->get(2, 2);
	float e = t->get(0, 0) * t->get(2, 2) - t->get(0, 2) * t->get(2, 0);
	float f = t->get(2, 0) * t->get(0, 1) - t->get(0, 0) * t->get(2, 1);

	float g = t->get(0, 1) * t->get(1, 2) - t->get(0, 2) * t->get(1, 1);
	float h = t->get(0, 2) * t->get(1, 0) - t->get(0, 0) * t->get(1, 2);
	float k = t->get(0, 0) * t->get(1, 1) - t->get(0, 1) * t->get(1, 0);

	this->values[0] = a;
	this->values[1] = d;
	this->values[2] = g;
	this->values[3] = b;
	this->values[4] = e;
	this->values[5] = h;
	this->values[6] = c;
	this->values[7] = f;
	this->values[8] = k;

	this->mul(1.0f / determinant);
}

void Matrix3::identity()
{
	this->zero();
	this->values[0] = 1.0f;
	this->values[3] = 1.0f;
	this->values[6] = 1.0f;
}

void Matrix3::mul(float scalar)
{
	for(int i = 0; i < Matrix3::SIZE; i++) {
		this->values[i] *= scalar;
	}
}

void Matrix3::mul(const Matrix3 & m)
{
	const Vector3 * c1 = m.get_col(0);
	const Vector3 * c2 = m.get_col(1);
	const Vector3 * c3 = m.get_col(2);

	const Vector3 * r1 = this->get_row(0);
	this->values[0] = r1->dot(*c1);
	this->values[1] = r1->dot(*c2);
	this->values[2] = r1->dot(*c3);
	delete r1;

	const Vector3 * r2 = this->get_row(1);
	this->values[3] = r2->dot(*c1);
	this->values[4] = r2->dot(*c2);
	this->values[5] = r2->dot(*c3);
	delete r2;

	const Vector3 * r3 = this->get_row(2);
	this->values[6] = r3->dot(*c1);
	this->values[7] = r3->dot(*c2);
	this->values[8] = r3->dot(*c3);
	delete r3;

	delete c1;
	delete c2;
	delete c3;
}

void Matrix3::normalize()
{
	float determinant = this->determinant();
	if(determinant == 0) return;

	this->mul(1.0f / determinant);
}

void Matrix3::rot_x(float angle)
{
}

void Matrix3::rot_y(float angle)
{
}

void Matrix3::rot_z(float angle)
{
}

void Matrix3::sub(float scalar)
{
	for(int i = 0; i < Matrix3::DIM; i++) {
		this->values[i] -= scalar;
	}
}

void Matrix3::sub(const Matrix3 & m)
{
	for(int i = 0; i < Matrix3::DIM; i++) {
		this->values[i] -= m.values[i];
	}
}

void Matrix3::transform(const Tuple3 * t)
{
}

void Matrix3::transpose()
{
}

void Matrix3::zero()
{
	std::fill(this->values_begin, this->values_end, 0.0f);
}

/* interfaces */
Matrix3 * Matrix3::clone() const
{
	Matrix3 * copy = new Matrix3();
	std::copy(this->values_begin, this->values_end, copy->values_begin);

	return copy;
}

bool Matrix3::equals(const Matrix3 * m) const
{
	if(!(m)) return false;

	for(int i = 0; i < Matrix3::SIZE; i++) {
		bool equal = Math<float>::epsilon_equals(this->values[i],
                                                         m->values[i]);
		if(!(equal)) {
			return false;
		}
	}

	return true;
}

}
