#include "stdafx.h"
#include "Header.h"


using namespace std;

int complexNumber::getComplexPath()
{
	return this->complexPath;
}

int complexNumber::getPrimaryPath()
{
	return this->primaryPath;
}

bool complexNumber::operator== (const complexNumber &num1) const {
	return ((num1.complexPath == this->complexPath) && (num1.primaryPath == this->primaryPath));
}
complexNumber::complexNumber(const float &pr, const float &comp) {
	primaryPath = pr;
	complexPath = comp;
}
complexNumber::complexNumber(const float &pr) {
	primaryPath = pr;
	complexPath = 0;
}

complexNumber::~complexNumber() {
}

complexNumber complexNumber::operator + (const int num) {
	return complexNumber(primaryPath + num, complexPath);
}

complexNumber complexNumber::operator + (const complexNumber &a) {
	return complexNumber(primaryPath + a.primaryPath, complexPath + a.complexPath);
}

complexNumber complexNumber::operator - (complexNumber &a) {
	return complexNumber(primaryPath - a.primaryPath, complexPath - a.complexPath);
}

complexNumber complexNumber::operator * (complexNumber &a) {
	return complexNumber((primaryPath * a.primaryPath + primaryPath * a.complexPath),
		(-complexPath * a.complexPath + complexPath * a.primaryPath));
}
complexNumber complexNumber::operator / (complexNumber &a) {
	complexNumber div(0);
	double r = a.complexPath * a.complexPath + a.primaryPath * a.primaryPath;
	div.primaryPath = (primaryPath * a.primaryPath + complexPath * a.complexPath) / r;
	div.complexPath = (complexPath*a.primaryPath - primaryPath * a.complexPath) / r;
	return div;
}

ostream& operator << (ostream &out, const complexNumber &a) {
	out << a.primaryPath << " + " << a.complexPath << "i";
	out << endl;
	return out;
};

complexNumber operator + (const int num, const complexNumber &a) {
	return complexNumber(num + a.primaryPath, a.complexPath);
}