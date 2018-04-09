//
// Created by macbook on 20.01.2018.
//
#include "ppp.h"
#include <iostream>

using namespace std;

int print(int *ppp, int numm)
{
        cout << "Исходный массив: ";
for(int i = 0; i < numm; ++i)
{
    cout << ppp[i] << " ";
}
cout << endl;
    return 0;
};

int bubble(int *ppp, int numm)
{
    for(int i = 1; i < numm; ++i)
    {
        for(int j = 0; j < numm-i; j++)
        {
            if(ppp[j] > ppp[j+1])
            {
                int temporary = ppp[j];
                ppp[j] = ppp[j+1];
                ppp[j+1] = temporary;
            }
        }
    }
    return 0;
}

int createMass(int *ppp, int numm)
{
    for (int i = 0; i < numm; i++) {
        int readNumM;
        cin >> readNumM;
        ppp[i] = readNumM;
    }
}