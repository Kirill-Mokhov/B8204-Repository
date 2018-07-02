#include "Logger.h"

String::String(const char* source) {
	len = sizeof(source);
	str = new char[len + 1];
	strcpy(str, source);
}

String::String(const String& source) {
	len = source.len;
	str = new char[len + 1];
	strcpy(str, source.str);
}

String::String() :String("") {};

inline size_t String::getLen() {
	return len;
}

String String::operator=(const String& source){
	delete[] this->str;
	this->len = source.len;
	this->str = new char[this->len + 1];
	strcpy(str, source.str);
	return *this;
}

String String::operator=(const char* source) {
	delete[] str;
	len = sizeof(source);
	str = new char[len + 1];
	strcpy(str, source);
	return *this;
}
String String::operator+(const String& right) {
	char *s = new char[this->len + right.len + 1];
    strcpy(s,this->str);
	strcat(s, right.str);
	String s1(s);
	delete[] s;
	return s1;
}
String String::operator+=(const String& right) {
	char *old = this->str;
	size_t old_len = this->len;
	this->len = old_len + right.len;
	this->str = new char[this->len + 1];

	strcpy(this->str,old);
	strcat(this->str, right.str);
	
	delete[] old;
	return *this;
}


ostream& operator<<(ostream &stream, const String &str) {
	stream << str.str;
	return stream;

}
istream& operator >>(istream &stream, const String &str) {
	stream >> str.str;
	return stream;

}
String::operator char*() const {
	return this->str;
}