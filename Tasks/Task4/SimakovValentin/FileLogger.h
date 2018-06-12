#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include "LoggerInterface.h"

class FileLogger: public LoggerInterface{
protected:
    std::ofstream out;

    const char* sample_log_message(std::string message_type, int code = 0, std::string message = "") {
        time_t timer = time(NULL);
        char sTime[80];
        strftime(sTime, 80, "%d/%m/%Y %X(%Z)", gmtime(&timer));
        std::string result = message_type + ": [" + sTime + "] Code: " + std::to_string(code) + " Message: " + message;
        out << result << std::endl;
        return result.data();
    }

public:
    FileLogger() {out.open("../log.txt");}

    ~FileLogger() {out.close();}

    const char* info(int code = 0, std::string message = "") override {sample_log_message("INFO", code, message);}

    const char* error(int code = 0, std::string message = "") override {sample_log_message("ERROR", code, message);}

    const char* debug(int code = 0, std::string message = "") override {sample_log_message("DEBUG", code, message);}

    const char* warning(int code = 0, std::string message = "") override {sample_log_message("WARNING", code, message);}

    const char* notice(int code = 0, std::string message = "") override {sample_log_message("NOTICE", code, message);}
};
#endif
