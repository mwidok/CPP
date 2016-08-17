/*
 * Logger.h

 *
 *  This class is concerned with logging the processed matrices.
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include "string.h"
#include <fstream>
#include <iostream>

using namespace std;

class Logger {
private:
	ofstream os;
	string file;
	void output();
public:
	Logger(string filename);
	virtual ~Logger();
	void log(const string& data);
	void getLogfile();
};

#endif
