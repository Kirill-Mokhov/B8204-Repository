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