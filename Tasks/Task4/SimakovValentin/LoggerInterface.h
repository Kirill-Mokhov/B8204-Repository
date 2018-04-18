#ifndef LOGGERINTERFACE_H
#define LOGGERINTERFACE_H

#include <string>

class LoggerInterface{
public:
    virtual void info(int code, std::string message) = 0;
    virtual void error(int code, std::string message) = 0;
    virtual void debug(int code, std::string message) = 0;
    virtual void warning(int code, std::string message) = 0;
    virtual void notice(int code, std::string message) = 0;
};
#endif
