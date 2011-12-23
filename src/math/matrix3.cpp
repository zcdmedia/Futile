


	inline float get(int row, int col) const
	{
		assert(row >= 0 && row < Matrix3::DIM);
		assert(col >= 0 && col < Matrix3::DIM);

		return this->values[(row * Matrix3::DIM) + col];
	}

	inline Vector3 get_col(int col) const
	{
		assert(col >= 0 && col < Matrix3::DIM);

		float x = this->get(0, col);
		float y = this->get(1, col);
		float z = this->get(2, col);

		return Vector3(x, y, z);
	}

	inline Vector3 get_row(int row) const
	{
		assert(row >= 0 && row < Matrix3::DIM);

		float x = this->get(row, 0);
		float y = this->get(row, 1);
		float z = this->get(row, 2);

		return Vector3(x, y, z);
	}
	void set(int row, int col, float value)
	{
		assert(row >= 0 && row < Matrix3::DIM);
		assert(col >= 0 && col < Matrix3::DIM);

		this->values[(row * Matrix3::DIM) + col] = value;
	}

	void set(const Matrix3 & m)
	{
		memcpy(this->values, m.values, sizeof(this->values));
	}

	void set_col(int col, const Vector3 & v)
	{
		assert(col >= 0 && col <= Matrix3::DIM);

		this->set(0, col, v.x);
		this->set(1, col, v.y);
		this->set(2, col, v.z);
	}

	void set_col(int row, const Vector3 & v)
	{
		assert(row >= 0 && row <= Matrix3::DIM);

		this->set(row, 0, v.x);
		this->set(row, 1, v.y);
		this->set(row, 2, v.z);
	}
