#ifndef PROJECT_MATRIX_LIB_T_H
#define PROJECT_MATRIX_LIB_T_H
template<typename T>
MatrixLib::Matrix MatrixLib::operator*(const MatrixLib::Matrix &a, const T &multiplier) {

	Matrix result(a);
	for (MSIZE_T i(0); i < a.m; i++)
	{
		for (MSIZE_T j(0); j < a.n; j++)
		{
			result[i][j] *= multiplier;
		}
	}
	return result;
}

template<typename T>
MatrixLib::Matrix MatrixLib::operator*(const T &multiplier, const MatrixLib::Matrix &a) {

	Matrix result(a);
	for (MSIZE_T i(0); i < a.m; i++)
	{
		for (MSIZE_T j(0); j < a.n; j++)
		{
			result[i][j] *= multiplier;
		}
	}
	return result;
}
#endif //PROJECT_MATRIX_LIB_T_H