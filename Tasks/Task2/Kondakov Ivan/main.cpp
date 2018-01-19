#include "matrix_lib.h"
#include <conio.h>
#include <ctime>
using namespace std;
using MatrixLib::Matrix;

int main()
{
	srand(time(NULL));
	Matrix a(3, 2);
	Matrix b(2, 3);
	cout << (a);
	cout << (b);

	//cout << a + b;
	//cout << a - b;
	cout << a * b;
	cout << 5 * a;
	cout << a * 5;
	Matrix c(3, 3);
	cout << c.getInverse() << endl;
	cout << c.getDeterminant() << endl;
	_getch();
}