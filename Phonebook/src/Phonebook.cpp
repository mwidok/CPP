/*
 * Phonebook.cpp

 *
 *  Created on: 17.08.2016
 *      Author: Mathias
 */

#include "Phonebook.h"
#include "Person.h"
#include <iostream>

//using namespace std;

Phonebook::Phonebook(){

}

/*
*Adding a person to the phone book.
*/

void Phonebook::add(Person* person){
	database.insert(*person);
}

/*
*Deleting a person from the phone book
*/
void Phonebook::del(Person* person){
	database.erase(*person);
}

/*
*Displays a certain person of the phone book.
*/
void Phonebook::output(Person* p){
	cout << "Name: " << p->getName() << " phone: " << p->getNumber() << endl;
}

/*
*Searches the phone book for a person or a number.
*/

Person* Phonebook::search(string name){

	for(auto p : database){
		if(p.getName() == name)
		{
		Person* p_ret = &p;
		return p_ret;
		}

	}
	return nullptr;
}

Person* Phonebook::search(int number){

	for(auto p : database){
		if(p.getNumber() == number)
		{
		Person* p_ret = &p;
		return p_ret;
		}

	}
	return nullptr;
}

Phonebook::~Phonebook(){

}

void Phonebook::getEntries(){
	for(auto p : database){
	cout << p.getName() << "  " << p.getNumber() << "" << endl;
	}
}


