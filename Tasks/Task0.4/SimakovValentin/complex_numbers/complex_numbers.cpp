#include <iostream>
#include <math.h>

using namespace std;

struct Complex_Number{
    float Re;
    float Im;

    Complex_Number(float re, float im){
        Re = re;
        Im = im;
    }

    bool operator == (const Complex_Number& a){
        if(this->Re == a.Re && this->Im == a.Im)
            return true;
        return false;
    }

    Complex_Number operator + (const Complex_Number& a){
        Complex_Number result(this->Re + a.Re, this->Im + a.Im);
        return result;
    }

    Complex_Number operator + (const float& a){
        Complex_Number result(this->Re + a, this->Im);
        return result;
    }

    Complex_Number operator - (const Complex_Number& a){
        Complex_Number result(this->Re - a.Re, this->Im - a.Im);
        return result;
    }

    Complex_Number operator - (const float& a){
        Complex_Number result(this->Re - a, this->Im);
        return result;
    }

    Complex_Number operator * (const Complex_Number& a){
        Complex_Number result(this->Re*a.Re-this->Im*a.Im, this->Re*a.Im+this->Im*a.Re);
        return result;
    }

    Complex_Number operator * (const float& a){
        Complex_Number result(this->Re*a, this->Im*a);
        return result;
    }

    Complex_Number operator / (const Complex_Number& a){
        Complex_Number result((this->Re*a.Re+this->Im*a.Re)/(a.Re*a.Re+a.Im*a.Im), (a.Re*this->Im-this->Re*a.Im)/(a.Re*a.Re+a.Im*a.Im));
        return result;
    }

    Complex_Number operator / (const float& a){
        Complex_Number result(this->Re/a, this->Im/a);
        return result;
    }

    friend ostream& operator << (ostream& s, const Complex_Number& a){
        s << a.Re << (a.Im > 0 ? " + " : " - ") << abs(a.Im) << "i";
        return s;
    }

    float absolute(){
        return sqrt(this->Re*this->Re + this->Im*this->Im);
    }

    float argument(){
        return acos(this->Re/this->absolute());
    }

};

int main(){
    Complex_Number a(1, -5);
    Complex_Number b(5, 2);
    cout << "a = " << a << endl;
    cout << "|" << a <<"| = " << a.absolute() << endl;
    cout << "Arg(" << a <<") = " << a.argument() << " rad\n\n";
    cout << "b = " << b << endl;
    cout << "|" << b <<"| = " << b.absolute() << endl;
    cout << "Arg(" << b <<") = " << b.argument() << " rad\n\n";
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "b - a = " << b - a << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "b / a = " << b / a << endl;
    return 0;
}
