#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include "LoggerInterface.h"

class FileLogger: public LoggerInterface{
protected:
    std::ofstream out;

    void sample_log_message(std::string message_type, int code = 0, std::string message = "") {
        out << message_type << ": [" << time(NULL) << "] Code: " << code << " Message: " << message << std::endl;
    }

public:
    FileLogger() {out.open("../log.txt");}

    ~FileLogger() {out.close();}

    void info(int code = 0, std::string message = "") override {sample_log_message("INFO", code, message);}

    void error(int code = 0, std::string message = "") override {sample_log_message("ERROR", code, message);}

    void debug(int code = 0, std::string message = "") override {sample_log_message("DEBUG", code, message);}

    void warning(int code = 0, std::string message = "") override {sample_log_message("WARNING", code, message);}

    void notice(int code = 0, std::string message = "") override {sample_log_message("NOTICE", code, message);}
};
#endif
