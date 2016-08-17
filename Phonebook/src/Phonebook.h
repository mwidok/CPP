/*
 * Phonebook.h
 *
 *  Created on: 17.08.2016
 *      Author: Mathias
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
#include <set>
#include "Person.h"

using namespace std;

class Phonebook {
private:
	set<Person> database;
public:
	Phonebook();
	virtual ~Phonebook();
	void add(Person* person);
	void del(Person* person);
	Person* search(string name);
	Person* search(int number);
	void output(Person* p);
	void getEntries();
	void action();
};

#endif
