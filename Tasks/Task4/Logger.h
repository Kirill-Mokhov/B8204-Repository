#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
#include "string.h"
#include "files.h"

class Logger {
	FileWriter *fout;
public:
	Logger(String);
	void log(String);
	void ErrorLog(String);
	void DebugLog(String);
	void WLog(String);
	void NoticeLog(String);
	~Logger();
};