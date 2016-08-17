/*
 * Logger.cpp
 *
 *  Created on: 09.08.2016
 *      Author: Mathias
 */

#include "Logger.h"
#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;

Logger::Logger(string filename) {
	file = filename;

}

Logger::~Logger() {

}

/*
*Writes the logged data into a logfile.
*/

void Logger::log(const string& data){


	os.open(file.c_str(), ios::app);
	if(!os)
	{
	cerr << "Couldn't open file!" << endl;
	}
	os << data;
	os.close();

}

/*
*Retrieves the existing logfile.
*/

void Logger::getLogfile(){
	while(os)
	{
	output();
	}
}

/*
*Prints the logfile.
*/

void Logger::output(){
	string out;
	ifstream is;
	getline(is, out);
	cout << out << endl;
}
