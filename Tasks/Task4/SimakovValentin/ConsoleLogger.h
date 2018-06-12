#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "FileLogger.h"
#include <iostream>

class ConsoleLogger: public FileLogger{
protected:
    const char* sample_log_message(std::string message_type, int code = 0, std::string message = "") {
        time_t timer = time(NULL);
        char sTime[80];
        strftime(sTime, 80, "%d/%m/%Y %X(%Z)", gmtime(&timer));
        std::string result;
        result = message_type + ": [" + sTime + "] Code: " + std::to_string(code) + " Message: " + message;
        std::cout << result << std::endl;
        return result.data();
    }

public:
    ConsoleLogger() = default;

    ~ConsoleLogger() = default;

    const char* info(int code = 0, std::string message = "") override {sample_log_message("INFO", code, message);}

    const char* error(int code = 0, std::string message = "") override {sample_log_message("ERROR", code, message);}

    const char* debug(int code = 0, std::string message = "") override {sample_log_message("DEBUG", code, message);}

    const char* warning(int code = 0, std::string message = "") override {sample_log_message("WARNING", code, message);}

    const char* notice(int code = 0, std::string message = "") override {sample_log_message("NOTICE", code, message);}
};
#endif
