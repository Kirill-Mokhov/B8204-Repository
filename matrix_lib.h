#ifndef PROJECT_MATRIX_LIB_H
#define PROJECT_MATRIX_LIB_H

#include <iostream>

namespace MatrixLib {
	typedef unsigned short int MSIZE_T;
	typedef float MITEM_T;

	
	struct Matrix {
		MSIZE_T m, n;
		MITEM_T **v;

		/* Copy constructor */
		Matrix(const Matrix &a);
		/* Constructor for Matrix with dimensions MxN */
		Matrix(MSIZE_T m, MSIZE_T n);
		~Matrix();
		MITEM_T* operator[](const MSIZE_T &a) const;
		Matrix getInverse() const throw(std::logic_error);
		MITEM_T getDeterminant() const throw(std::logic_error);
	};
	void zero(const Matrix &a);
	template<typename T>
	Matrix operator*(const Matrix &a, const T &multiplier);
	template<typename T>
	Matrix operator*(const T &multiplier, const Matrix &a);
	Matrix operator*(const Matrix &a, const Matrix &b);
	Matrix operator+(const Matrix &a, const Matrix &b);
	Matrix operator-(const Matrix &a, const Matrix &b);
	std::ostream& operator<<(std::ostream &out, const Matrix &a);
}

#include "matrix_lib_t.hpp"
#endif //PROJECT_MATRIX_LIB_H