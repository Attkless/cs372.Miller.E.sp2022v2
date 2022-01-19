//
// File:   assignment1.cpp
// Author: Eric Miller
// Purpose:
// Illustrate some of the bad things that can happen with
// pointers
//
#include <iostream>
using namespace std;

class object {
private:
	string s1;
};

// First function that allocates a large array of integers in the heap and has a second pointer that points to the same location in memory. Deletes the first pointer and prints out the first 10 integers pointed by the second pointer.
void PtrHeap1()
{
	int* array = new int[400];
	int* ptr;
	// Small loop that initializes the contents of the array in a sequence starting from 0 and going to size of array
	array[0] = 0;
	for (int i = 0; i < 100; i++) {
		array[i] = i;
		// Initialize a second pointer to the same location in memory
		ptr = &array[i];
	}
	// Array delete of the first pointer
	delete[] array;
	// Print the first ten integers pointed to by the second pointer
	for (int i = 0; i < 10; ++i) {
		cout << *ptr << endl;
		ptr++;
	}
}
// Second function that also allocates a large array of integers in the heap and both pointers point to the location of the array. Then do an array delete of the first pointer and print out the first ten elements pointed to by the 
// second pointer.
void PtrHeap2() {
	int* array = new int[400];
	int* ptr1 = array;
	int* ptr2 = array;
	delete[] ptr1;
	cout << *ptr2 << endl; // this is the address of the second pointer
	for (int i = 0; i < 10; i++) {
		cout << ptr2++ << endl;
	}
}
/*You will write two functions in this case. Write a function that defines a pointer to a
C++ string object and then uses new to create a new string on the stack (i.e., a local variables).
Initialize this string to a value, say “abcdefghijkl”. In the return for the function, use the dereference operator (*) to return the string just allocated on the heap. Now write a second function
that define a string object, set to be whatever is returned from the helper function and then print
the string. Call this function from your main() function*/
string stringFunc() {
	string *string1 = new string("abcdefghijkl");
	return *string1;
}

void callerFunc(string s1) {
	cout << s1 << endl;
}

int main() {
  // Put your code here.
	PtrHeap1();
	PtrHeap2();
	callerFunc(stringFunc());
  return 0;
}
