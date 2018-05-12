#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "FileLogger.h"
#include <iostream>


class ConsoleLogger: public FileLogger{
protected:
    void sample_log_message(std::string message_type, int code = 0, std::string message = "") {
        std::cout << message_type << ": [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

public:
    ConsoleLogger() = default; //хз почему нельзя сделать так: out = std::cout;

    ~ConsoleLogger() = default;

    void info(int code = 0, std::string message = "") override {sample_log_message("INFO", code, message);}

    void error(int code = 0, std::string message = "") override {sample_log_message("ERROR", code, message);}

    void debug(int code = 0, std::string message = "") override {sample_log_message("DEBUG", code, message);}

    void warning(int code = 0, std::string message = "") override {sample_log_message("WARNING", code, message);}

    void notice(int code = 0, std::string message = "") override {sample_log_message("NOTICE", code, message);}
};
#endif
