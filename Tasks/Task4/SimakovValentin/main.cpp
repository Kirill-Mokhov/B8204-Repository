#include <iostream>
#include "Logger.h"

using namespace std;

class DivideByZeroException : public logic_error {
public:
    DivideByZeroException() : logic_error("DivideByZeroException") {}
};

class DivOperator {
public:
    float div(float a, float b) throw(DivideByZeroException) {
        if (b == 0) {
            throw DivideByZeroException();
        }
        return a / b;
    }
};

int main(){
    LoggerInterface* consoleLogger = new ConsoleLogger();
    DivOperator d;
    try {
        int a = 120;
        for(int i = 5; i >= 0; i--) {
            a = d.div(a, i);
            consoleLogger->info(0, "a = " + to_string(a));
        }
        a /= 0;
    }
    catch(exception& e){
        consoleLogger->error(-1, e.what());
    }

};