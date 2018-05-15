#pragma once

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>
#include <stdexcept>

using namespace std;

class LoggerInterface {
public:
	virtual void info(int code, string message) = 0;
	virtual void error(int code, string message) = 0;
	virtual void debug(int code, string message) = 0;
	virtual void warning(int code, string message) = 0;
	virtual void notice(int code, string message) = 0;
};

class FileLogger : public LoggerInterface {
protected:
	ofstream fout;

	void sample_log_message(string message_type, int code = 0, string message = "") {
		fout << message_type << ": [" << time(NULL) << "] Code: " << code << " Message: " << message << endl;
	}
public:
	FileLogger(std::string a) {
		fout.open(a +".txt");
	}

	~FileLogger() {
		fout.close();
	}

	void info(int code = 0, string message = "") override { sample_log_message("INFO", code, message); }
	void error(int code = 0, string message = "") override { sample_log_message("ERROR", code, message); }
	void debug(int code = 0, string message = "") override { sample_log_message("DEBUG", code, message); }
	void warning(int code = 0, string message = "") override { sample_log_message("WARNING", code, message); }
	void notice(int code = 0, string message = "") override { sample_log_message("NOTICE", code, message); }
};

class ConsoleLogger : public LoggerInterface {
protected:
	void sample_log_message(string message_type, int code = 0, string message = "") {
		cout << message_type << ": [" << time(NULL) << "] Code: " << code << " Message: " << message << endl;
	}
public:
	ConsoleLogger() = default;
	~ConsoleLogger() = default;
	void info(int code = 0, string message = "") override { sample_log_message("INFO", code, message); }
	void error(int code = 0, string message = "") override { sample_log_message("ERROR", code, message); }
	void debug(int code = 0, string message = "") override { sample_log_message("DEBUG", code, message); }
	void warning(int code = 0, string message = "") override { sample_log_message("WARNING", code, message); }
	void notice(int code = 0, string message = "") override { sample_log_message("NOTICE", code, message); }
};

