#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "LoggerInterface.h"
#include <iostream>

class ConsoleLogger: public LoggerInterface{
public:
    ConsoleLogger() = default;

    ~ConsoleLogger() = default;

    void info(int code = 0, std::string message = "") override {
        std::cout << "INFO: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

    void error(int code = 0, std::string message = "") override {
        std::cout << "ERROR: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

    void debug(int code = 0, std::string message = "") override {
        std::cout << "DEBUG: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

    void warning(int code = 0, std::string message = "") override {
        std::cout << "WARNING: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

    void notice(int code = 0, std::string message = "") override {
        std::cout << "NOTICE: [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }
};
#endif
