#include <futile/math/matrix3.h>

/* access macros */
#define m00 values[0]
#define m01 values[3]
#define m02 values[6]

#define m10 values[1]
#define m11 values[4]
#define m12 values[7]

#define m20 values[2]
#define m21 values[5]
#define m22 values[8]

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
	assert(row >= 0 && row < Matrix3::NUM_COLS);
	assert(col >= 0 && col < Matrix3::NUM_COLS);


	return this->values[row + (col * Matrix3::NUM_COLS)];
}

Vector3 * Matrix3::get_col(int col) const
{
	assert(col >= 0 && col < Matrix3::NUM_COLS);

	float x = this->get(0, col);
	float y = this->get(1, col);
	float z = this->get(2, col);

	return new Vector3(x, y, z);
}

Vector3 * Matrix3::get_row(int row) const
{
	assert(row >= 0 && row < Matrix3::NUM_COLS);

	float x = this->get(row, 0);
	float y = this->get(row, 1);
	float z = this->get(row, 2);

	return new Vector3(x, y, z);
}

/* mutators */
void Matrix3::set(int row, int col, float value)
{
	assert(row >= 0 && row < Matrix3::NUM_COLS);
	assert(col >= 0 && col < Matrix3::NUM_COLS);

	this->values[(col * Matrix3::NUM_COLS) + row] = value;
}

void Matrix3::set(const Matrix3 & m)
{
	std::copy(m.values_begin, m.values_end, this->values_begin);
}

void Matrix3::set_col(int col, const Vector3 & v)
{
	assert(col >= 0 && col <= Matrix3::NUM_COLS);

	this->set(0, col, v.x);
	this->set(1, col, v.y);
	this->set(2, col, v.z);
}

void Matrix3::set_row(int row, const Vector3 & v)
{
	assert(row >= 0 && row <= Matrix3::NUM_COLS);

	this->set(row, 0, v.x);
	this->set(row, 1, v.y);
	this->set(row, 2, v.z);
}

/* methods */
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
	float a = m00 * m11 * m22;
	float b = m01 * m12 * m20;
	float c = m02 * m10 * m21;

	float d = m20 * m11 * m02;
	float e = m01 * m10 * m22;
	float f = m00 * m12 * m21;

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

	float a = m00 * m22 - m12 * m21;
	float b = m12 * m20 - m10 * m22;
	float c = m10 * m21 - m11 * m20;

	float d = m02 * m21 - m01 * m22;
	float e = m00 * m22 - m02 * m20;
	float f = m20 * m01 - m00 * m21;

	float g = m01 * m12 - m02 * m11;
	float h = m02 * m10 - m00 * m12;
	float k = m00 * m11 - m01 * m10;

	delete t;

	this->m00 = a;
	this->m01 = d;
	this->m02 = g;
	this->m10 = b;
	this->m11 = e;
	this->m12 = h;
	this->m20 = c;
	this->m21 = f;
	this->m22 = k;

	this->mul(1.0f / determinant);
}

void Matrix3::identity()
{
	this->zero();
	this->m00 = 1.0f;
	this->m11 = 1.0f;
	this->m22 = 1.0f;
}

void Matrix3::mul(float scalar)
{
	for(int i = 0; i < Matrix3::SIZE; i++) {
		this->values[i] *= scalar;
	}
}

void Matrix3::mul(const Matrix3 & m)
{
	const Vector3 * r1 = this->get_row(0);
	const Vector3 * r2 = this->get_row(1);
	const Vector3 * r3 = this->get_row(2);

	const Vector3 * c1 = m.get_col(0);
	const Vector3 * c2 = m.get_col(1);
	const Vector3 * c3 = m.get_col(2);

	this->m00 = r1->dot(*c1);
	this->m01 = r1->dot(*c2);
	this->m02 = r1->dot(*c3);
	delete r1;

	this->m10 = r2->dot(*c1);
	this->m11 = r2->dot(*c2);
	this->m12 = r2->dot(*c3);
	delete r2;

	this->m20 = r3->dot(*c1);
	this->m21 = r3->dot(*c2);
	this->m22 = r3->dot(*c3);
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
	this->identity();
	float cosine = cos(angle);
	float sine = sin(angle);

	this->m11 = cosine;
	this->m12 = 0 - sine;
	this->m21 = sine;
	this->m22 = cosine;
}

void Matrix3::rot_y(float angle)
{
	this->identity();
	float cosine = cos(angle);
	float sine = sin(angle);

	this->m00 = cosine;
	this->m02 = sine;
	this->m20 = 0 - sine;
	this->m22 = cosine;
}

void Matrix3::rot_z(float angle)
{
	this->identity();
	float cosine = cos(angle);
	float sine = sin(angle);

	this->m00 = cosine;
	this->m01 = 0 - sine;
	this->m10 = sine;
	this->m11 = cosine;
}

void Matrix3::scale(const Tuple2 & t)
{
	this->zero();
	this->m00 = t.x;
	this->m11 = t.y;
}

void Matrix3::sub(float scalar)
{
	for(int i = 0; i < Matrix3::NUM_COLS; i++) {
		this->values[i] -= scalar;
	}
}

void Matrix3::sub(const Matrix3 & m)
{
	for(int i = 0; i < Matrix3::NUM_COLS; i++) {
		this->values[i] -= m.values[i];
	}
}

void Matrix3::transform(Tuple3 * t)
{
	if(!(t)) return;

	float x = this->m00 * t->x + this->m01 * t->y + this->m02 * t->z;
	float y = this->m10 * t->x + this->m11 * t->y + this->m12 * t->z;
	float z = this->m20 * t->x + this->m21 * t->y + this->m22 * t->z;

	t->set(x, y, z);
}

void Matrix3::translate(const Tuple2 & t)
{
	this->identity();
	this->m20 = t.x;
	this->m21 = t.y;	
}

void Matrix3::transpose()
{
	const Vector3 * c1 = this->get_col(0);
	this->set_row(0, *c1);
	delete c1;

	const Vector3 * c2 = this->get_col(1);
	this->set_row(1, *c2);
	delete c2;

	const Vector3 * c3 = this->get_col(2);
	this->set_row(2, *c3);
	delete c3;
}

void Matrix3::zero()
{
	std::fill(this->values_begin, this->values_end, 0.0f);
}

/* interfaces */
Matrix3 * Matrix3::clone() const
{
	Matrix3 * copy = new Matrix3();
	copy->set(*this);

	return copy;
}

bool Matrix3::equals(const Matrix3 & m) const
{
	for(int i = 0; i < Matrix3::SIZE; i++) {
		bool equal = MathHelper<float>::epsilon_equals(this->values[i],
                                                               m.values[i]);
		if(!(equal)) return false;
	}

	return true;
}

}

#undef m00
#undef m01
#undef m02

#undef m10
#undef m11
#undef m12

#undef m20
#undef m21
#undef m22
