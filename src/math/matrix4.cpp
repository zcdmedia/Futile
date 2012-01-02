#include <futile/math/matrix4.h>

/* access macros */
#define m00 values[0]
#define m01 values[4]
#define m02 values[8]
#define m03 values[12]

#define m10 values[1]
#define m11 values[5]
#define m12 values[9]
#define m13 values[13]

#define m20 values[2]
#define m21 values[6]
#define m22 values[10]
#define m23 values[14]

#define m30 values[3]
#define m31 values[7]
#define m32 values[11]
#define m33 values[15]

namespace futile {

Matrix4::Matrix4()
{
	this->values_begin = this->values;
	this->values_end = this->values + Matrix4::SIZE;
	this->zero();
}

Matrix4::~Matrix4() { }

/* accessors */
float Matrix4::get(int row, int col) const
{
	assert(row >= 0 && row < Matrix4::NUM_COLS);
	assert(col >= 0 && col < Matrix4::NUM_COLS);

	return this->values[row + (col * Matrix4::NUM_COLS)];
}

Vector4 * Matrix4::get_col(int col) const
{
	assert(col >= 0 && col < Matrix4::NUM_COLS);

	float x = this->get(0, col);
	float y = this->get(1, col);
	float z = this->get(2, col);
	float w = this->get(3, col);

	return new Vector4(x, y, z, w);
}

Vector4 * Matrix4::get_row(int row) const
{
	assert(row >= 0 && row < Matrix4::NUM_COLS);

	float x = this->get(row, 0);
	float y = this->get(row, 1);
	float z = this->get(row, 2);
	float w = this->get(row, 3);

	return new Vector4(x, y, z, w);
}

/* mutators */
void Matrix4::set(int row, int col, float value)
{
	assert(row >= 0 && row < Matrix4::NUM_COLS);
	assert(col >= 0 && col < Matrix4::NUM_COLS);

	this->values[(row * Matrix4::NUM_COLS) + col] = value;
}

void Matrix4::set_col(int col, const Vector3 & v)
{
	assert(col >= 0 && col <= Matrix4::NUM_COLS);

	this->set(0, col, v.x);
	this->set(1, col, v.y);
	this->set(2, col, v.z);
	this->set(3, col, 0.0f);
}

void Matrix4::set_col(int col, const Vector4 & v)
{
	assert(col >= 0 && col <= Matrix4::NUM_COLS);

	this->set(0, col, v.x);
	this->set(1, col, v.y);
	this->set(2, col, v.z);
	this->set(3, col, v.w);
}

void Matrix4::set_row(int row, const Vector3 & v)
{
	assert(row >= 0 && row <= Matrix4::NUM_COLS);

	this->set(row, 0, v.x);
	this->set(row, 1, v.y);
	this->set(row, 2, v.z);
	this->set(row, 3, 0.0f);
}

void Matrix4::set_row(int row, const Vector4 & v)
{
	assert(row >= 0 && row <= Matrix4::NUM_COLS);

	this->set(row, 0, v.x);
	this->set(row, 1, v.y);
	this->set(row, 2, v.z);
	this->set(row, 3, v.w);
}

/* methods */
void Matrix4::add(float scalar)
{
	for(int i = 0; i < Matrix4::SIZE; i++) {
		this->values[i] += scalar;
	}
}

void Matrix4::add(const Matrix4 & m)
{
	for(int i = 0; i < Matrix4::SIZE; i++) {
		this->values[i] += m.values[i];
	}
}

float Matrix4::determinant() const
{
	float a = m03 * m12 * m21 * m30;
	float b = m02 * m13 * m21 * m30;
	float c = m03 * m11 * m22 * m30;
	float d = m01 * m13 * m22 * m30;
	float e = m02 * m11 * m23 * m30;
	float f = m01 * m12 * m23 * m30;

	float g = m03 * m12 * m20 * m31;
	float h = m02 * m13 * m20 * m31;
	float i = m03 * m10 * m22 * m31;
	float j = m00 * m13 * m22 * m31;
	float k = m02 * m10 * m23 * m31;
	float l = m00 * m12 * m23 * m31;

	float m = m03 * m11 * m20 * m32;
	float n = m01 * m13 * m20 * m32;
	float o = m03 * m10 * m21 * m32;
	float p = m00 * m13 * m21 * m32;
	float q = m01 * m10 * m23 * m32;
	float r = m11 * m11 * m23 * m32;

	float s = m02 * m11 * m20 * m33;
	float t = m01 * m12 * m20 * m33;
	float u = m02 * m10 * m21 * m33;
	float v = m00 * m12 * m21 * m33;
	float w = m01 * m10 * m22 * m33;
	float x = m00 * m11 * m22 * m33;

	return a - b - c + d + e - f
               - g + h + i - j - k + l
               + m - n - o + p + q - r
               - s + t + u - v - w + x;
}

float Matrix4::get_scale() const
{
}

void Matrix4::invert()
{
	float determinant = this->determinant();
	if(determinant == 0) return;

	float a = m12 * m23 * m31 - m13 * m22 * m31 + m13 * m21 * m32
                - m11 * m23 * m32 - m12 * m21 * m33 + m11 * m22 * m33;

	float b = m03 * m22 * m31 - m02 * m23 * m31 - m03 * m21 * m32
                + m01 * m23 * m32 + m02 * m21 * m33 - m01 * m22 * m33;

	float c = m02 * m13 * m31 - m03 * m12 * m31 + m03 * m11 * m32
                - m01 * m13 * m32 - m02 * m11 * m33 + m01 * m12 * m33;

	float d = m03 * m12 * m21 - m02 * m13 * m21 - m03 * m11 * m22
                + m01 * m13 * m22 + m02 * m11 * m23 - m01 * m12 * m23;

	float e = m13 * m22 * m30 - m12 * m23 * m30 - m13 * m20 * m32
                + m10 * m23 * m32 + m12 * m20 * m33 - m10 * m22 * m33;

	float f = m02 * m23 * m30 - m03 * m22 * m30 + m03 * m20 * m32
                - m00 * m23 * m32 - m02 * m20 * m33 + m00 * m22 * m33;

	float g = m03 * m12 * m30 - m02 * m13 * m30 - m03 * m10 * m32
                + m00 * m13 * m32 + m02 * m10 * m33 - m00 * m12 * m33;

	float h = m02 * m13 * m20 - m03 * m12 * m20 + m03 * m10 * m22
                - m00 * m13 * m22 - m02 * m10 * m23 + m00 * m12 * m23;

	float i = m11 * m23 * m30 - m13 * m21 * m30 + m13 * m20 * m31
                - m10 * m23 * m31 - m11 * m20 * m33 + m10 * m21 * m33;

	float j = m03 * m21 * m30 - m01 * m23 * m30 - m03 * m20 * m31
                + m00 * m23 * m31 + m01 * m20 * m33 - m00 * m21 * m33;

	float k = m01 * m13 * m30 - m03 * m11 * m30 + m03 * m10 * m31
                - m00 * m13 * m31 - m01 * m10 * m33 + m00 * m11 * m33;

	float l = m03 * m11 * m20 - m01 * m13 * m20 - m03 * m10 * m21
                + m00 * m13 * m21 + m01 * m10 * m23 - m00 * m11 * m23;

	float m = m12 * m21 * m30 - m11 * m22 * m30 - m12 * m20 * m31
                + m10 * m22 * m31 + m11 * m20 * m32 - m10 * m21 * m32;

	float n = m01 * m22 * m30 - m02 * m21 * m30 + m02 * m20 * m31
                - m00 * m22 * m31 - m01 * m20 * m32 + m00 * m21 * m32;

	float o = m02 * m11 * m30 - m01 * m12 * m30 - m02 * m10 * m31
                + m00 * m12 * m31 + m01 * m10 * m32 - m00 * m11 * m32;

	float p = m01 * m12 * m20 - m02 * m11 * m20 + m02 * m10 * m21
                - m00 * m12 * m21 - m01 * m10 * m22 + m00 * m11 * m22;

	this->m00 = a;
	this->m01 = b;
	this->m02 = c;
	this->m03 = d;

	this->m10 = e;
	this->m11 = f;
	this->m12 = g;
	this->m13 = h;

	this->m20 = i;
	this->m21 = j;
	this->m22 = k;
	this->m23 = l;

	this->m30 = m;
	this->m31 = n;
	this->m32 = o;
	this->m33 = p;

	this->mul(1.0f / determinant);
}

void Matrix4::identity()
{
	this->zero();
	this->m00 = 1.0f;
	this->m11 = 1.0f;
	this->m22 = 1.0f;
	this->m33 = 1.0f;
}

void Matrix4::mul(float scalar)
{
	for(int i = 0; i < Matrix4::SIZE; i++) {
		this->values[i] *= scalar;
	}
}

void Matrix4::mul(const Matrix4 & m)
{
	const Vector4 * r1 = this->get_row(0);
	const Vector4 * r2 = this->get_row(1);
	const Vector4 * r3 = this->get_row(2);
	const Vector4 * r4 = this->get_row(3);

	const Vector4 * c1 = m.get_col(0);
	const Vector4 * c2 = m.get_col(1);
	const Vector4 * c3 = m.get_col(2);
	const Vector4 * c4 = m.get_col(3);

	this->m00 = r1->dot(*c1);
	this->m01 = r1->dot(*c2);
	this->m02 = r1->dot(*c3);
	this->m03 = r1->dot(*c4);
	delete r1;

	this->m10 = r2->dot(*c1);
	this->m11 = r2->dot(*c2);
	this->m12 = r2->dot(*c3);
	this->m13 = r2->dot(*c4);
	delete r2;

	this->m20 = r3->dot(*c1);
	this->m21 = r3->dot(*c2);
	this->m22 = r3->dot(*c3);
	this->m23 = r3->dot(*c4);
	delete r3;

	this->m30 = r4->dot(*c1);
	this->m31 = r4->dot(*c2);
	this->m32 = r4->dot(*c3);
	this->m33 = r4->dot(*c4);
	delete r4;

	delete c1;
	delete c2;
	delete c3;
	delete c4;
}

void Matrix4::normalize()
{
	float determinant = this->determinant();
	if(determinant == 0) return;

	this->mul(1.0f / determinant);
}

void Matrix4::rot_x(float angle)
{
	this->identity();
	float cosine = std::cos(angle);
	float sine = std::sin(angle);

	this->m11 = cosine;
	this->m12 = 0 - sine;
	this->m21 = sine;
	this->m22 = cosine;
}

void Matrix4::rot_y(float angle)
{
	this->identity();
	float cosine = std::cos(angle);
	float sine = std::sin(angle);

	this->m00 = cosine;
	this->m02 = sine;
	this->m20 = 0 - sine;
	this->m22 = cosine;
}

void Matrix4::rot_z(float angle)
{
	this->identity();
	float cosine = std::cos(angle);
	float sine = std::sin(angle);

	this->m00 = cosine;
	this->m01 = 0 - sine;
	this->m10 = sine;
	this->m11 = cosine;
}

void Matrix4::scale(const Tuple3 & t)
{
	this->identity();
	this->m00 = t.x;
	this->m11 = t.y;
	this->m22 = t.z;
}

void Matrix4::sub(float scalar)
{
	for(int i = 0; i < Matrix4::NUM_COLS; i++) {
		this->values[i] -= scalar;
	}
}

void Matrix4::sub(const Matrix4 & m)
{
	for(int i = 0; i < Matrix4::NUM_COLS; i++) {
		this->values[i] -= m.values[i];
	}
}

void Matrix4::transform(Tuple4 * t)
{
	if(!(t)) return;

	float x = this->m00 * t->x + this->m01 * t->y + this->m02 * t->z
                + this->m03 * t->w;

	float y = this->m10 * t->x + this->m11 * t->y + this->m12 * t->z
                + this->m13 * t->w;

	float z = this->m20 * t->x + this->m21 * t->y + this->m22 * t->z
                + this->m23 * t->w;

	float w = this->m30 * t->x + this->m31 * t->y + this->m32 * t->z
                + this->m33 * t->w;

	t->set(x, y, z, w);
}

void Matrix4::translate(const Tuple3 & t)
{
	this->identity();
	this->m03 = t.x;
	this->m13 = t.y;
	this->m23 = t.z;
}

void Matrix4::transpose()
{
	const Vector4 * c1 = this->get_col(0);
	this->set_row(0, *c1);
	delete c1;

	const Vector4 * c2 = this->get_col(1);
	this->set_row(1, *c2);
	delete c2;

	const Vector4 * c3 = this->get_col(2);
	this->set_row(2, *c3);
	delete c3;

	const Vector4 * c4 = this->get_col(3);
	this->set_row(3, *c4);
	delete c4;
}

void Matrix4::zero()
{
	std::fill(this->values_begin, this->values_end, 0.0f);
}

/* interfaces */
Matrix4 * Matrix4::clone() const
{
	Matrix4 * copy = new Matrix4();
	copy->set(*this);

	return copy;
}

bool Matrix4::equals(const Matrix4 & m) const
{
	for(int i = 0; i < Matrix4::SIZE; i++) {
		bool equal = MathHelper<float>::epsilon_equals(this->values[i],
                                                               m.values[i]);
		if(!(equal)) return false;
	}

	return true;
}

void Matrix4::set(const Matrix4 & m)
{
	std::copy(m.values_begin, m.values_end, this->values_begin);
}

}

#undef m00
#undef m01
#undef m02
#undef m03

#undef m10
#undef m11
#undef m12
#undef m13

#undef m20
#undef m21
#undef m22
#undef m23

#undef m30
#undef m31
#undef m32
#undef m33
