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

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "BinaryTree.h"
using namespace std;
using namespace std::chrono;
const int NUM_NODES = 100000;

int main() {
	const int SIZE1 = 1000, SIZE2 = 10000,  SIZE3 = 100000; 
	int num1000, num10000, num100000;
	srand(time(0));
	// Create the binary tree for the first size of 1000 elements.
	BinaryTree<int> tree1000;
	
	// Insert some integers
	for (int count = 0; count < SIZE1; count++) {
		num1000 = rand() % SIZE1;
		tree1000.insertNode(num1000);
	}
	std::chrono::time_point<std::chrono::system_clock> start, end;
	// Search for 100 elements in the binary tree 
	int num = 0; 
	start = std::chrono::system_clock::now();									// Num is going to be used as the RNG 
	for(int i = 0; i < 100; i++) {
		num = rand() % SIZE1;
		tree1000.search(num);
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	cout << "\nelapsed time: " << elapsed_seconds.count() << "s\n";
	// Display the values.
//  cout << "\nHere are the values in the tree:\n";
//	tree1000.displayInOrder();
	system("pause");

	// **** new area **** 

	// Create the binary tree for the second size of 10,000 elements.
	BinaryTree<int> tree10000;
	
	// Insert some integers into size 10,000.
	for(int count = 0; count < 10000; count++) {
		num10000 = rand() % 10000;
		tree10000.insertNode(num10000);
	}
	
	// Search for 100 elements in the binary tree 
	std::chrono::time_point<std::chrono::system_clock> start1, end1;
	int num1 = 0; 
	
	start1 = std::chrono::system_clock::now();
	for(int i = 0; i < 100; i++) {
		num1 = rand() % SIZE2; 
		tree10000.search(num1);
	}
	end1 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
	cout << "\nElapsed Time: " << elapsed_seconds1.count() << "s\n";

	// Display the values within the tree of 10,000 elements.
//	cout << "\nHere are the values in the tree of size 10,000 elements:\n";
//	tree10000.displayInOrder();
	
	system("pause");
	
	// *** new area ***
	
	// Create the binary tree for the third size of 100,000 elements.
	BinaryTree<int> tree100000;
	
	// Insert some integers into size 100,000.
	for(int count = 0; count < 100000; count++) {
		num100000 = rand() % 100000;
		tree100000.insertNode(num100000);
	}
	
	std::chrono::time_point<std::chrono::system_clock> start2, end2; 
	
	int num2 = 0;
	start2 = std::chrono::system_clock::now();
	for(int i = 0; i < 100; i++) {
		num2 = rand() % SIZE3; 
		tree100000.search(num2);
	}
	end2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
	cout << "\nElapsed Time: " << elapsed_seconds2.count() << "s\n";
//	cout << "\nHere are the values in the tree of size 100,000 elements:\n";
//	tree100000.displayInOrder();
	
	return 0;
}