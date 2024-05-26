template <typename T>
class matrix {
private:
	T** array;
	size_t size_rows;
	size_t size_columns;
public:
	matrix(const size_t row, const size_t column)
	{
		size_rows = row;
		size_columns = column;

		array = new T * [size_rows];
		for (size_t i = 0; i < size_rows; ++i) array[i] = new T[size_columns];
	}

	matrix(matrix<T>& m)
	{
		size_rows = m.rows();
		size_columns = m.ñolumns();

		array = new T * [size_rows];
		for (size_t i = 0; i < size_rows; ++i) array[i] = new T[size_columns];

		for (size_t i = 0; i < size_rows; i++)
			for (size_t j = 0; j < size_columns; j++)
				array[i][j] = m.get(i, j);
	}

	size_t rows(void)
	{
		return size_rows;
	}

	size_t ñolumns(void)
	{
		return size_columns;
	}

	T get(const size_t row, const  size_t col) {
		if ((row < 0) || (col < 0) || (row >= size_rows) || (col >= size_columns))
		{
			throw "matrix.get: invalid index";
		}
		return array[row][col];
	}

	void set(const size_t row, const size_t col, const T value) {
		if ((row < 0) || (col < 0) || (row >= size_rows) || (col >= size_columns))
		{
			throw "matrix.set: invalid index";
		}
		array[row][col] = value;
		return;
	}

	matrix<T>& sum(matrix& m)
	{
		if ((m.rows() != size_rows) || (m.ñolumns() != size_columns))
		{
			throw "matrix.sum: different dimensions";
		}

		for (size_t i = 0; i < size_rows; i++)
			for (size_t j = 0; j < size_columns; j++)
			{
				array[i][j] += m.get(i, j);
			}

		return *this;
	}

	~matrix(void)
	{
		for (size_t i = 0; i < size_rows; ++i) free(array[i]);
		free(array);
	}
};

