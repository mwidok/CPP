/*
 * Person.h
 *
 *  Created on: 17.08.2016
 *      Author: Mathias
 */

#ifndef PERSON_H_
#define PERSON_H_


using namespace std;

class Person {
	private:
		string m_name;
		int m_number;
	public:
		string getName();
		int getNumber();
		Person(string name, int number);
		virtual ~Person();
};

#endif
