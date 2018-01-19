#include "matrix_lib.h"
#include <cstdlib>


namespace MatrixLib
{

	Matrix::Matrix(const Matrix &a)
	{
		this->m = a.m;
		this->n = a.n;

		v = new MITEM_T*[m];
		for (MSIZE_T k(0); k < m; k++)
		{
			v[k] = new MITEM_T[n];

		}

		for (MSIZE_T i(0); i < m; i++) {
			for (MSIZE_T j(0); j < n; j++) {
				v[i][j] = a.v[i][j];
			}
		}
	}

	Matrix::Matrix(MSIZE_T m, MSIZE_T n)
	{
		this->m = m;
		this->n = n;

		v = new MITEM_T*[m];
		for (MSIZE_T k(0); k < m; k++)
		{
			v[k] = new MITEM_T[n];

		}


		for (MSIZE_T i(0); i<m; i++)
		{
			for (MSIZE_T j(0); j < n; j++)
			{
				v[i][j] = rand() % 100;
			}
		}
	}


	MITEM_T* Matrix::operator[](const MSIZE_T &a) const
	{
		return v[a];
	}

	Matrix minor(const Matrix &v, int l, int k) throw(std::logic_error)
	{
		if ((l > v.m - 1) || (k > v.n - 1)) throw std::logic_error("The minor doesn't exist");

		Matrix result(v.m - 1, v.n - 1);
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < k; j++) result.v[i][j] = v.v[i][j];
			for (int j = k + 1; j < v.n; j++) result.v[i][j - 1] = v.v[i][j];
		}

		for (int i = l + 1; i < v.m; i++)
		{
			for (int j = 0; j < k; j++) result.v[i - 1][j] = v.v[i][j];
			for (int j = k + 1; j < v.n; j++) result.v[i - 1][j - 1] = v.v[i][j];
		}
		return result;
	}

	Matrix uni(const Matrix &v) throw(std::logic_error)
	{
		Matrix result(v.m, v.n);
		for (int i = 0; i < result.m; i++)
			for (int j = 0; j < result.n; j++)
				result.v[i][j] = minor(v, i, j).getDeterminant() * pow(-1, i + j);
		return result;
	}

	Matrix transposed(const Matrix &v)
	{
		Matrix result(v.n, v.m);
		for (int i = 0; i < result.m; i++)
			for (int j = 0; j < result.n; j++)
				result.v[i][j] = v.v[j][i];
		return result;
	}


	MITEM_T Matrix::getDeterminant() const throw(std::logic_error)
	{
		if (this->m != this->n) throw "Wrong matrix for determinant";

		MITEM_T result(0);
		if (this->n == 1) result = this->v[0][0];
		else {
			for (int i = 0; i < this->m; i += 2) result += this->v[0][i] * minor(*this, 0, i).getDeterminant();
			for (int i = 1; i < this->m; i += 2) result -= this->v[0][i] * minor(*this, 0, i).getDeterminant();
		}
		return result;

	}
	Matrix Matrix::getInverse() const throw(std::logic_error)
	{
		MITEM_T determinant = getDeterminant();
		if (determinant == 0) throw std::logic_error("The determinant mustn't be zero");

		Matrix transposed(uni(*this));
		MITEM_T s = 1 / determinant;
		for (int i = 0; i < transposed.m; i++)
			for (int j = 0; j < transposed.n; j++)
				transposed.v[i][j] *= s;

		return transposed;
	}





	std::ostream& operator<<(std::ostream &out, const Matrix &a)
	{
		for (MSIZE_T i(0); i < a.m; i++)
		{
			for (MSIZE_T j(0); j < a.n; j++)
			{
				out << a[i][j] << ' ';
			}
			out << std::endl;
		}
		out << std::endl;
		return out;
	}

	Matrix operator+(const Matrix &a, const Matrix &b)
	{
		if (a.m != b.n || a.n != b.n)
			throw "Invalid size";

		Matrix result(a);
		for (MSIZE_T i(0); i < a.m; i++)
		{
			for (MSIZE_T j(0); j < a.n; j++)
			{
				result[i][j] = a[i][j] + b[i][j];
			}
		}
		return result;
	}
	Matrix MatrixLib::operator-(const Matrix &a, const Matrix &b)
	{
		if (a.m != b.n || a.n != b.n)
			throw "Invalid size";
		Matrix result(a);

		for (MSIZE_T i(0); i < a.m; i++) {
			for (MSIZE_T j(0); j < a.n; j++) {
				result[i][j] = a[i][j] - b[i][j];
			}
		}

		return result;
	}

	Matrix MatrixLib::operator*(const Matrix &a, const Matrix &b)
	{
		if (a.n != b.m)
			throw "Invalid matrix size for multiplication";

		Matrix result(a.m, b.n);
		zero(result);
		for (MSIZE_T i(0); i < a.m; i++) {
			for (MSIZE_T j(0); j < b.n; j++) {
				for (MSIZE_T k(0); k < a.n; k++) {
					result[i][j] += a[i][k] * b[k][j];
				}
			}
		}

		return result;
	}





	void zero(const Matrix &a)
	{
		for (MSIZE_T i(0); i < a.m; i++) {
			for (MSIZE_T j(0); j < a.n; j++) {
				a[i][j] = 0;
			}
		}
	}

	Matrix::~Matrix() {
		for (MSIZE_T i(0); i < n; i++)
		{
			delete[] v[i];
		}
		delete[] v;
	}
}