#include <iostream>
#include "ppp.h"

using namespace std;

int main()
{
    int num;
    cout << "INT=";
    cin >> num;
    cout << endl;

    int *ppp = new int[num];

    createMass(ppp, num);
    print(ppp, num);
    bubble(ppp, num);
    print(ppp, num);

    return 0;
}
