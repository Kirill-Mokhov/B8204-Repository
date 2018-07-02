#include "Logger.h"
int main() {
	Logger log("C:\\vr\\1.txt");
	//try
	log.log("Hello");
	log.log("Hi");
	String smile(":)");
	String massege(":)");
		cout << "u can use some smile, just smile --> :)" << endl;
		cin >> massege;
		if (massege = smile) {
			log.NoticeLog("u use smile");
				}
				else {
					log.WLog("it's not smile dude!");
					log.DebugLog(massege);
					cout << "try again!" << endl;
					cin >> massege;
					if (massege = smile) {
						log.NoticeLog("u use smile");
					}
					else {
						log.ErrorLog("u are so bad");
					}
					
				} 
				cout << "check log" << endl;
	return 0;
}