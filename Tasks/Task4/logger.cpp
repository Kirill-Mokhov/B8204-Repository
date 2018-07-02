#include "Logger.h"
Logger::Logger(String path) {
	this->fout = new FileWriter(path);
}
void Logger::log(String s) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%Y-%m-%d %H:%M:%S",cur_t);
	*fout << tmp << " - " << s << "\n";
	}
void Logger :: ErrorLog(String er) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%H:%M:%S", cur_t);
	*fout << tmp << " - " <<"Error:" << er <<"\n";
}
void Logger::DebugLog(String s) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%H:%M:%S", cur_t);
	*fout << tmp << " - " << "Debug:" << " - "<< s <<  " - " << "\n";
}

void Logger::WLog(String er) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%H:%M:%S", cur_t);
	*fout << tmp << " - " << "Warning:" << er << "\n";
}
void Logger::NoticeLog(String er) {
	time_t t = time(NULL);
	tm *cur_t = localtime(&t);
	char tmp[100];
	strftime(tmp, 99, "%H:%M:%S", cur_t);
	*fout << tmp << " - " << "Notice:" << er << "\n";
}

Logger::~Logger() {
	delete this->fout;
	}