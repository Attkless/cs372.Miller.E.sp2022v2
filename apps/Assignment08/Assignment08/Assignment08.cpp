// Assignment08.cpp : Defines the entry point for the application.
/*
1. (20 points) Using the examples from the lecture as a guide, add a Tree class to your class library. For
interface requirements, implement similar methods to those we discussed in class.
2. (20 points) Implement a binary search function using templates that can be used to search through
an array of any data type that supports the relational operators.
3. (30 points) Implement a structure in C++ that has three fields: (1) a size t that says how many
of elements are in the next two fields, (2) a pointer to a dynamically allocated vector of integers
containing that many elements, and (3) a pointer to a Tree object containing a binary search tree with
the contents of that array. (NOTE: This will be a really big structure in memory.)
Write a function in C++ that returns a pointer to one of these structures with a single parameter:
size of array to be allocated. The function should fill the array in the structure to be returned with
random integers which you then sort and then insert those integers into a binary search tree.
4. (30 points) Now we will write a program that will compare the execution time of binary search vs.
lookup times in a binary search program. You program should generate one of the structures from
the previous questions for sizes 1000, 10000, 100,000 elements. After creating the array it should pick
100 numbers at random and search for each number in structure’s array and then search for the same
number using the BST, keeping track of the times in each case (use the chrono library). Compute
and report the average times for both types of search.
*/

#include "Assignment08.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
