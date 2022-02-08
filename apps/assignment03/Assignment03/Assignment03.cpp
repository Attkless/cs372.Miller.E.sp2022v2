// Implementation of the List class and CircularList class
// to test their functionality.
// Eric Miller


#include "list.h"
#include "circular_list.h"
#include "priority_list.h"
#include <iostream>

using namespace std;

int main() {
	// Variables
	int num;
	int listCount;
	int start;
	struct Node* head = NULL;

	// Test of List class
	List<int> l;
	cout << "How many numbers do you want in your list? ";
	cin >> listCount;

	for (int count = 0; count < listCount; count++) {
		cout << "Please enter a number to add to the list: ";
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
	CircularList<int> cl;
	
	cout << "Where would you like to start?" << endl;
	cout << "Choose a number from 0-" << (listCount - 1) << ": ";
	cin >> start;
	cl.circle(start);

	// Test of PriorityList class
	PriorityList<int> pl;
	int items, listItem, listPriority;
	cout << "How many items do you want in the priority list: ";
	cin >> items;

	for (int count = 0; count < items; count++) {
		cout << "Please enter an item into the list: ";
		cin >> listItem;
		if (count == 0) {
			pl.push_front(listItem);
		}
		else {
			pl.push_back(listItem);
		}
	}

	pl.traverse(0);

	return 0;
}