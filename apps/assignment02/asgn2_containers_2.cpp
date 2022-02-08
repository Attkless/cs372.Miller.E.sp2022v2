// Implementation of the containers to
// test their functionality.
//
// This one uses the list.h

#include <iostream>
#include "bag_2.h"

using namespace std;

int main() {
	// Variables
	Bag<float> aBag = new Bag<float>();
	aBag.insert(3.14);
	aBag.insert(100000.0);
	int itemCount = aBag.size();
	float newItem = aBag.pop();

	// Test of bag_2.h
	cout << itemCount << endl;
	return 0;
}