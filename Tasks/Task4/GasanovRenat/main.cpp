#include "Logger.h"
#include <string>

using namespace std;

int main() {
    Logger log("..//log.txt");
    log.log("Hello there! read for simple math test?");
    string result = "6";
    string inputData;
    cout << "2+2*2=?" << endl;
    cin >> inputData;
    if (inputData == result) {
        log.NoticeLog("Well done! Your mark is 5/5");
    }
    else {
        log.WLog("First mistake! Another try...");
        log.DebugLog(inputData);
        cout << "Try again!" << endl;
        cin >> inputData;
        if (inputData == result) {
            log.NoticeLog("OK! Your mark is 4/5.");
        }
        else {
            log.ErrorLog("...2/5...");
        }
    }
    cout << "Check log.txt for results." << endl;
    return 0;
}