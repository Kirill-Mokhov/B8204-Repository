#include <iostream>

class complexNumber {
public:
	int getPrimaryPath();
	int getComplexPath();
	bool complexNumber::operator==(const complexNumber & num1) const;
	complexNumber(const float &pr, const float &comp);
	complexNumber(const float &pr);
	~complexNumber();
	complexNumber operator + (const int num);
	friend complexNumber operator + (const int num, const complexNumber &a);
	complexNumber operator + (const complexNumber &a);
	complexNumber operator - (complexNumber &a);
	complexNumber operator * (complexNumber &a);
	complexNumber operator / (complexNumber &a);
	friend std::ostream& operator << (std::ostream &out, const complexNumber &a);

private:
	float primaryPath;
	float complexPath;
};

std::ostream& operator << (std::ostream &out, const complexNumber &a);