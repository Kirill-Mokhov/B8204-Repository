#ifndef LOGGERINTERFACE_H
#define LOGGERINTERFACE_H

#include <string>

class LoggerInterface{
public:
    virtual std::string info(int code, std::string message) = 0;
    virtual std::string error(int code, std::string message) = 0;
    virtual std::string debug(int code, std::string message) = 0;
    virtual std::string warning(int code, std::string message) = 0;
    virtual std::string notice(int code, std::string message) = 0;
};
#endif
