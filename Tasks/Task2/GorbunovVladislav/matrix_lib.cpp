#include "matrix_lib.h"

void printMatrix(int* massive, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << *(massive + i*m + j) << " ";
		cout << endl;
	}
	return;
}

bool sumMatrix(int* firstMatrix, int n1, int m1, int* secondMatrix, int n2, int m2, int* resultMatrix)
{
	if ((n1 == n2) && (m1 == m2))
	{
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m1; j++)
				*(resultMatrix + i*m1 + j) = *(firstMatrix + i*m1 + j) + *(secondMatrix + i*m1 + j);
		return true;
	}

	return false;
}

bool multiMatrix(int* firstMatrix, int n1, int m1, int* secondMatrix, int n2, int m2, int* resultMatrix)
{
	if (m1 == n2)
	{
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m2; j++)
				*(resultMatrix + i*m2 + j) = 0;

		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m2; j++)
				for (int k = 0; k < m1; k++)
					*(resultMatrix + i*m2 + j) += *(firstMatrix + i*m1 + k) * *(secondMatrix + k*m2 + j);
		return true;
	}

	return false;
}

void alphaMultiMatrix(int* matrix, int n, int m, int number, int *resultMatrix)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			*(resultMatrix + i*m + j) = *(matrix + i*m + j) * number;
	return;
}
