#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
#include <string>
#include "files.h"

class Logger {
    FileWriter *fout;
public:
    Logger(std::string);
    void log(std::string);
    void ErrorLog(std::string);
    void DebugLog(std::string);
    void WLog(std::string);
    void NoticeLog(std::string);
    ~Logger();
};