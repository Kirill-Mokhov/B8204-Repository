#include "matrix_lib.h"
#include <conio.h>
#include <ctime>
using namespace std;
using MatrixLib::Matrix;

int main()
{
	srand(time(NULL));
	Matrix a(5,5);
	Matrix b(5,5);
	Matrix c(a);
	cout << (a);
	cout << (b);


	cout << a + b;
	cout << a - b;
	cout << a * b;
	cout << 5 * a;
	cout << a * 5;
	_getch();
}