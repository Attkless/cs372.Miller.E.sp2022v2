// Implementation of the containers to
// test their functionality.
//
// This one uses the STL list class

#include <iostream>
#include "bag.h"
#include <list>

using namespace std;

int main() {
	// Variables
	Bag<float> aBag = new Bag<float>();
	aBag.insert(3.14);
	aBag.insert(100000.0);
	int itemCount = aBag.size();
	float newItem = aBag.pop();

	
	// Test of bag.h
	cout << itemCount << endl;
	return 0;
}