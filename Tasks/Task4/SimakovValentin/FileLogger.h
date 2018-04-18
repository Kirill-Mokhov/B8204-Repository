#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include "LoggerInterface.h"

class FileLogger: public LoggerInterface{
protected:
    std::ofstream fout;
public:
    FileLogger(){
        fout.open("log.txt");
    }

    ~FileLogger(){
        fout.close();
    }

    void info(int code = 0, std::string message = "") override {
        fout << "INFO: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

    void error(int code = 0, std::string message = "") override {
        fout << "ERROR: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

    void debug(int code = 0, std::string message = "") override {
        fout << "DEBUG: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

    void warning(int code = 0, std::string message = "") override {
        fout << "WARNING: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

    void notice(int code = 0, std::string message = "") override {
        fout << "NOTICE: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }
};
#endif
