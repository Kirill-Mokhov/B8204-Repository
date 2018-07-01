#include "Logger.h"
#include <string>
Logger::Logger(std::string path) {
	this->fout = new FileWriter(path);
}
void Logger::log(std::string s) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%Y-%m-%d %H:%M:%S",cur_t);
	*fout << tmp << " - " << s << "\n";
}
void Logger :: ErrorLog(std::string er) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%H:%M:%S", cur_t);
	*fout << tmp << " - " <<"Error:" << er <<"\n";
}
void Logger::DebugLog(std::string s) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%H:%M:%S", cur_t);
	*fout << tmp << " - " << "Debug:" << " - "<< s <<  " - " << "\n";
}

void Logger::WLog(std::string er) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%H:%M:%S", cur_t);
	*fout << tmp << " - " << "Warning:" << er << "\n";
}
void Logger::NoticeLog(std::string er) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%H:%M:%S", cur_t);
	*fout << tmp << " - " << "Notice:" << er << "\n";
}

Logger::~Logger() {
	delete this->fout;
}