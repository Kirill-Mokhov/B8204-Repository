#include "stdafx.h"

struct Matrix
{
	int n;
	int m;
	double** Mass;
};

Matrix Create_rand(int n, int m);//����� ���������� �������
Matrix Create(int n, int m);//����� ���������� ����������� ������� 
long double determ(Matrix Matr);//����� ���������� ������������
Matrix Summ(Matrix Matr1, Matrix Matr2);//����� ���������� ����� �������
Matrix MultipleByANumber(Matrix Matr1, double a);//����� ��������� ������� �� �����
Matrix Multiple(Matrix Matr1, Matrix Matr2);//����� ���������� ��������� �������
Matrix Inverse(Matrix Matr1);//����� ���������� �������� �������
void Print_Matrix(Matrix matr); //������ �������