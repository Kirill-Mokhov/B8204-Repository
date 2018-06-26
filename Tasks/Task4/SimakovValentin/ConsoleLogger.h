#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "FileLogger.h"
#include <iostream>

class ConsoleLogger: public FileLogger{
protected:
    std::string sample_log_message(std::string message_type, int code = 0, std::string message = "") {
        time_t timer = time(NULL);
        char sTime[80];
        strftime(sTime, 80, "%d/%m/%Y %X(%Z)", gmtime(&timer));
        //std::string result = ;
        return message_type + ": [" + sTime + "] Code: " + std::to_string(code) + " Message: " + message;
    }

public:
    ConsoleLogger() = default;

    ~ConsoleLogger() = default;

    std::string info(int code = 0, std::string message = "") override {sample_log_message("INFO", code, message);}

    std::string error(int code = 0, std::string message = "") override {sample_log_message("ERROR", code, message);}

    std::string debug(int code = 0, std::string message = "") override {sample_log_message("DEBUG", code, message);}

    std::string warning(int code = 0, std::string message = "") override {sample_log_message("WARNING", code, message);}

    std::string notice(int code = 0, std::string message = "") override {sample_log_message("NOTICE", code, message);}
};
#endif
