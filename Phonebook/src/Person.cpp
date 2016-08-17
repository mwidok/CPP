/*
 * Person.cpp
 *
 *  Created on: 17.08.2016
 *      Author: Mathias
 */

#include "Person.h"



Person::Person(string name, int number): m_name(name), m_number(number){

}

Person::~Person(){

}

/*
*Returning a person's name.
*/

string Person::getName(){
	return m_name;
}

/*
*Returning a person's phone number.
*/
int Person::getNumber(){
	return m_number;
}
