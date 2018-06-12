#ifndef LOGGERINTERFACE_H
#define LOGGERINTERFACE_H

#include <string>

class LoggerInterface{
public:
    virtual const char* info(int code, std::string message) = 0;
    virtual const char* error(int code, std::string message) = 0;
    virtual const char* debug(int code, std::string message) = 0;
    virtual const char* warning(int code, std::string message) = 0;
    virtual const char* notice(int code, std::string message) = 0;
};
#endif
