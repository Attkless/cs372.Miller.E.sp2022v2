// Implementation of the List class and CircularList class
// to test their functionality.
// Eric Miller


#include "List.h"
#include "CircularList.h"
#include "PriorityList.h"
#include <iostream>

using namespace std;

int main() {
	// Variables
	int num;
	string name;
	int listCount;
	int start;

	// Test of List class
	List l;
	cout << "Please enter a name for the list: ";
	cin >> name;
	l.List(name);
	cout << "How many words do you want in your list? ";
	cin >> listCount;

	for (int count = 0; count < listCount; count++) {
		cout << "Please enter a word to add to the list: ";
		cin >> num;
		if (count == 0) {
			l.push_front(num);
		}
		else {
			l.push_back(num);
		}
	}

	cout << endl << "Your list is: " << endl;
	l.traverse(0);


	// Test of CircularList class
	CircularList cl;
	cout << "Where would you like to start?" << endl;
	cout << "Choose a number from 0-" << listCount << ": ";
	cin >> start;
	cl.circle(start);

	// Test of PriorityList class
	PriorityList pl;


	return 0;
}