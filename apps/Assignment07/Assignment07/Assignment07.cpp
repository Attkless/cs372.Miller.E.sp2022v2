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

void generateArrayTen() {
	int a[10];
	auto start = high_resolution_clock::now();

	for (int i = 0; i < 10; i++)
		a[i] = i;
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "Time taken by function: " << duration.count() << endl; 
}

int main() { 
	generateArrayTen();
}
