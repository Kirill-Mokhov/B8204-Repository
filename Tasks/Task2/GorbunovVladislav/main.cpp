#include "matrix_lib.h"
#include <conio.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    int *a, *b, *c;

	srand(time(NULL));

    a = new int[4];
    b = new int[4];
    c = new int[4];

    for(int i=0; i<4; i++) {
        a[i] = rand() % 10; 
        b[i] = rand() % 8;
    }

    cout << "A matrix:" << endl;
    printMatrix(a, 2, 2);
    cout << endl;

    cout << "B matrix:" << endl;
    printMatrix(b, 2, 2);
    cout << endl;

    cout << "A + B:" << endl;
    if (sumMatrix(a, 2, 2, b, 2, 2, c))
        printMatrix(c, 2, 2);
    cout << endl;

    cout << "A * 5:" << endl;
    alphaMultiMatrix(a, 2, 2, 5, b);
        printMatrix(b, 2, 2);
    cout << endl;

    delete[] a, b, c;

    a = new int[8];

    b = new int[6];

    c = new int[12];

    for(int i=0; i<8; i++)
        a[i] = rand() % 10;
    for(int i=0; i<6; i++)
        b[i] = rand() % 8;

    cout << "A matrix:" << endl;
    printMatrix(a, 4, 2);
    cout << endl;

    cout << "B matrix:" << endl;
    printMatrix(b, 2, 3);
    cout << endl;

    cout << "A * B:" << endl;
    if (multiMatrix(a, 4, 2, b, 2, 3, c))
        printMatrix(c, 4, 3);
    cout << endl;

    delete[] a, b, c;

	_getch();
}
