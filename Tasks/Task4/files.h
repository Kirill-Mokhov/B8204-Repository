#pragma once
#include "Logger.h"
class FileReader {
	FILE *file;
public:
	FileReader(String path) {
		file = fopen(path,"r");
	}
	FileReader&  operator>>(String& str) {
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
	FileWriter(String path) {
		file = fopen(path, "a");
	}
	FileWriter&  operator<<(const String& str) {
		fputs(str, file);
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