// Assignment07.cpp : Defines the entry point for the application.
//
/*(40 Points) Here's an interesting algorithm: 
	int anyEqual(int n, A[][])
	{
		int i, j, k, m;
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				for(k = 1; k <= n; k++)
					for(m = 1; m <= n; m++)
						if(A[i][j] == A[k][m] && !(i == k && j == m)
							return 1;
		return 0;
	}
	
	Write a function in C++ that implements this algorithm.
	
	(50 Points) Let's test the behavior of the performance behavior of this algorithm. Write a program
	that loops for array sizes of the 10, 20, 30, 40, 50, 100, 500, and 1000 that for each array size will loop
	20 times to randomly fill an array of that size, execute the function from the previous question, and 
	compute the average time the function used to do whatever it's doing. Print a table with array sizes
	and the average for each array size.
	
	(10 Points) Based on the data you collected, what do you suspect the Big-Oh of the algorithm to be?
	Can you explain what this algorithm is telling you about the array? 
*/

#include <iostream>
#include <algorithm>
#include <chrono> 
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std::chrono;
using namespace std;

int anyEqual(int n, int A[][1000]) {
	int i, j, k, m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				for (int m = 1; m <= n; m++)
					if (A[i][j] == A[k][m] && !(i == k && j ==m ))
						return 1;
	return 0;
}

void generateArray(int a[], int size) {
	double average = 0;
	double sum = 0;
	auto start = steady_clock::now();
	int random = 20;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < random; j++)
			a[i] = (rand() % random);
	auto end = steady_clock::now();
	duration<double> elapsed_seconds = end - start;
	sum = sum + elapsed_seconds.count();
	cout << "Time taken by function: " << size << " " << (sum / random) << endl;
}

int main() { 
	const int SIZE1 = 10; 
	const int SIZE2 = 20;
	const int SIZE3 = 30;
	const int SIZE4 = 40; 
	const int SIZE5 = 50;
	const int SIZE6 = 100;
	const int SIZE7 = 500;
	const int SIZE8 = 1000;
	int myList1[SIZE1];
	int myList2[SIZE2];
	int myList3[SIZE3];
	int myList4[SIZE4];
	int myList5[SIZE5];
	int myList6[SIZE6];
	int myList7[SIZE7];
	int myList8[SIZE8];
	generateArray(myList1, SIZE1);
	generateArray(myList2, SIZE2);
	generateArray(myList3, SIZE3);
	generateArray(myList4, SIZE4);
	generateArray(myList5, SIZE5);
	generateArray(myList6, SIZE6);
	generateArray(myList7, SIZE7);
	generateArray(myList8, SIZE8);
}
