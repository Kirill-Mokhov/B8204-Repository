#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include "LoggerInterface.h"

class FileLogger: public LoggerInterface{
protected:
    std::ofstream out;

    std::string sample_log_message(std::string message_type, int code = 0, std::string message = "") {
        time_t timer = time(NULL);
        char sTime[80];
        strftime(sTime, 80, "%d/%m/%Y %X(%Z)", gmtime(&timer));
        std::string result = message_type + ": [" + sTime + "] Code: " + std::to_string(code) + " Message: " + message;
        out << result << std::endl;
        return result;
    }

public:
    FileLogger() {out.open("../log.txt", std::ios::app);}

    ~FileLogger() {out.close();}

    std::string info(int code = 0, std::string message = "") override {sample_log_message("INFO", code, message);}

    std::string error(int code = 0, std::string message = "") override {sample_log_message("ERROR", code, message);}

    std::string debug(int code = 0, std::string message = "") override {sample_log_message("DEBUG", code, message);}

    std::string warning(int code = 0, std::string message = "") override {sample_log_message("WARNING", code, message);}

    std::string notice(int code = 0, std::string message = "") override {sample_log_message("NOTICE", code, message);}
};
#endif
