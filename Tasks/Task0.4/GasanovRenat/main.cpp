#include <iostream>

using namespace std;

class Complex
{
private:
    int X;
    int i;

public:
    void PrintComplex(){
        if (i > 0) { cout << X << ' ' << '+' << ' ' << i << 'i' << '\n'; };
        if (i < 0) { cout << X << ' ' << '-' << ' ' << abs(i) << 'i' << '\n'; };

    }
    Complex(const int &z, const int &c){
        X = z;
        i = c;
    }
    Complex(const int &z){
        X = z;
        i = z;
    }

    Complex operator + (const Complex &a)
    {
        return Complex(this->X += a.X, this->i += a.i);
    }
    Complex operator - (const Complex &a)
    {
        return Complex(this->X -= a.X, this->i -= a.i);
    }
    Complex operator * (const Complex &a)
    {
        int x1, x2, x3, x4;
        x1 = this->X * a.X;
        x2 = this->X * a.i;
        x3 = this->i * a.X;
        x4 = this->i * a.i;
        return Complex(this->X = x1 - x4, this->i = x2 + x3);
    }
    Complex operator / (const Complex &a)
    {
        int x1, x2,x4,x5;
        float x3, x6;
        x1 = (this->X * a.X) + (this->i * a.i);
        x2 = (a.X*a.X) + (a.i*a.i);
        x3 = x1 / x2;
        x4 = (a.X*this->i) - (this->X*a.i);
        x5 = (a.X*a.X) + (a.i*a.i);
        x6 = x4 / x5;
        return Complex(this->X = x3, this->i = x6);
    }
    Complex operator + (const int &LLL)
    {
        return Complex(this->X += LLL);
    }
    Complex operator - (const int &LLL)
    {
        return Complex(this->X -= LLL);
    }
};

void IntAddComplex(const int &i, Complex &C){
    C+i;
}

int main()
{
    Complex C(4, 5);
    Complex CC(3, 6);

    C.PrintComplex();
    C+CC;
    C.PrintComplex();
    C-CC;
    C.PrintComplex();
    C*CC;
    C.PrintComplex();
    C/CC;
    C.PrintComplex();
    C+10;
    C.PrintComplex();
    C-10;
    C.PrintComplex();

    IntAddComplex(10, C);
    C.PrintComplex();
    return 0;
}

