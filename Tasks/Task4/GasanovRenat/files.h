#pragma once
#include "Logger.h"
#include <string>
class FileReader {
	FILE *file;
public:
	FileReader(std::string path) {
		const char* c = path.c_str();
		file = fopen(c,"r");
	}
	FileReader&  operator>>(std::string& str) {
		char x[1024];
		fgets(x, 1024, file);
		str = x;
		return *this;
	}
	FileReader&  operator>>(int &a) {
		char x[1024];
		fscanf(file, "%d", &a);
		return *this;
	}
	~FileReader() {
		fclose(file);
	}
};



class FileWriter {
	FILE *file;
public:
	FileWriter(std::string path) {
		const char* c = path.c_str();
		file = fopen(c, "a");
	}
	FileWriter&  operator<<(const std::string& str) {
		const char* c = str.c_str();
		fputs(c, file);
		return *this;
	}
	FileWriter&  operator<<(const char* str) {
		fputs(str, file);
		return *this;
	}
	FileWriter&  operator<<(int &a) {
		char x[1024];
		fprintf(file, "%d", &a);
		return *this;
	}
	~FileWriter() {
		fclose(file);
	}
};