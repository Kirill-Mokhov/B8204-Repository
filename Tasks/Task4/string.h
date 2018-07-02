#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Logger.h"
class String {
	size_t len;
	char *str;
public:
	//char *str;
	String(const char*);
	String(const String&);
	String();

	String operator+(const String&);
	String operator+=(const String&);
	String operator=(const String&);
	String operator=(const char*);
	operator char*() const;
	inline size_t getLen();
	friend ostream& operator<<(ostream &,const String&);
	friend istream& operator>>(istream &, const String &);
};
