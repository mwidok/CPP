//============================================================================
// Name        : Phonebook.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Phonebook.h"
#include "Person.h"
using namespace std;

/*
*Starts the interaction with the user.
*/
void action(){

	Phonebook* p_book;
	int number;
	cin >> number;
	string n_name;
	int n_number;
	switch(number)
	{

		case 1: cout << "Please enter the person's name: " << endl;
			cin >> n_name;
			cout << "Please enter the person's phone number: " << endl;
			cin >> n_number;
			Person person(n_name, n_number);
			p_book->add(&person);
			cout << "New entry added to your phone book: " << p_book->output(&person) << endl;
			break;

		case 2: cout << "Please enter the name of the person you would like to delete: ";
			cin >> n_name;
			if(cin.fail())
			{
			cout << "Error! Wrong input!" << endl;
			break;
			}
			if(p_book->search(n_name) != nullptr)
			{
			Person found = *(p_book->search(n_name));
			p_book->del(&found);
			cout << "The person has been deleted!" << endl;
			}
			else
			{
			cout << "Person not found!" << endl;
			}
			break;

		case 3: cout << "Please enter the person's name you would like to search for: " << endl;
			cin >> n_name;

			if(p_book->search(n_name) != nullptr)
			{
			Person persondel = *(p_book->search(n_name));
			p_book->output(&persondel);
			}
			else
			{
			cout << "Person not found" << endl;
			}
			break;

		case 4: cout << "Please enter the phone number you would like to search for: " << endl;
			cin >> n_number;
			if(p_book->search(n_number) != nullptr)
			{
			Person person = *(p_book->search(n_number));
			p_book->output(&person);
			}
			else
			{
			cout << "No person with such a number was found" << endl;
			}
			break;

		case 5:
			Person a("James", 12345);
			Person b("Leyla", 98765);
			Person c("Roger", 24689);
			p_book->add(&a);
			p_book->add(&b);
			break;

		case 6:
			p_book->getEntries();
			break;
	}

}

int main() {

	while(1){

		cout << "Phone book - Main menu" << endl << endl;
		cout << "Press 1 for adding a person to your phone book " << endl;
		cout << "Press 2 for deleting a person from your phone book " << endl;
		cout << "Press 3 for searching a person by name in your phone book " << endl;
		cout << "Press 4 for searching a phone number in your phone book " << endl;
		cout << "Press 5 for adding default persons " << endl;
		cout << "Press 6 for displaying the whole phone book " << endl;

		action();

		}
	return 0;
}
