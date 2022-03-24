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
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

// int n = the size of the array being passed in 
/*int anyEqualTen(int n, int A[][10]) {
    int i, j, k, m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            for (k = 1; k <= n; k++)
                for (m = 1; m <= n; m++)
                     if (A[i][j] == A[k][m] && !(i == k && j == m))
                        return 1;
    return 0;
}
*/
void generateArrayTen(int array[][10], int size) {
    double average = 0; 
    double sum = 0; 
    auto start = steady_clock::now(); 
    int count = 0; 
    int random = 20;
    while (count < 20) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                array[i][j] = (rand() % random);
                cout << array[i][j] << endl;
            }
        }
        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        sum = sum + elapsed_seconds.count();
        count++;
    }
    cout << "Time taken by function: " << size << " " << (sum / size) << endl;
}

void generateArrayTwenty(int array[][20], int size) {
    double average = 0;
    double sum = 0;
    auto start = steady_clock::now();
    int count = 0;
    int random = 20;
    while (count < 20) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                array[i][j] = (rand() % random);
            }
        }
        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        sum = sum + elapsed_seconds.count();
        count++;
    }
    cout << "Time taken by function: " << size << " " << (sum / size) << endl;

}

void generateArrayThirty(int array[][30], int size) {
    double average = 0;
    double sum = 0;
    auto start = steady_clock::now();
    int count = 0;
    int random = 20;
    while (count < 20) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                array[i][j] = (rand() % random);
            }
        }
        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        sum = sum + elapsed_seconds.count();
        count++;
    }
    cout << "Time taken by function: " << size << " " << (sum / size) << endl;
}

void generateArrayFourty(int array[][40], int size) {
    double average = 0;
    double sum = 0;
    auto start = steady_clock::now();
    int count = 0;
    int random = 20;
    while (count < 20) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                array[i][j] = (rand() % random);
            }
        }
        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        sum = sum + elapsed_seconds.count();
        count++;
    }
    cout << "Time taken by function: " << size << " " << (sum / size) << endl;
}

void generateArrayFifty(int array[][50], int size) {
    double average = 0;
    double sum = 0;
    auto start = steady_clock::now();
    int count = 0;
    int random = 20;
    while (count < 20) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                array[i][j] = (rand() % random);
            }
        }
        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        sum = sum + elapsed_seconds.count();
        count++;
    }
    cout << "Time taken by function: " << size << " " << (sum / size) << endl;
}

void generateArrayOneHundred(int array[][100], int size) {
    double average = 0;
    double sum = 0;
    auto start = steady_clock::now();
    int count = 0;
    int random = 20;
    while (count < 20) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                array[i][j] = (rand() % random);
            }
        }
        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        sum = sum + elapsed_seconds.count();
        count++;
    }
    cout << "Time taken by function: " << size << " " << (sum / size) << endl;
}

void generateArrayFiveHundred(int array[][500], int size) {
    double average = 0;
    double sum = 0;
    auto start = steady_clock::now();
    int count = 0;
    int random = 20;
    while (count < 20) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                array[i][j] = (rand() % random);
            }
        }
        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        sum = sum + elapsed_seconds.count();
        count++;
    }
    cout << "Time taken by function: " << size << " " << (sum / size) << endl;
}

void generateArrayOneThousand(int array[][1000], int size) {
    double average = 0;
    double sum = 0;
    auto start = steady_clock::now();
    int count = 0;
    int random = 20;
    while (count < 20) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                array[i][j] = (rand() % random);
            }
        }
        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        sum = sum + elapsed_seconds.count();
        count++;
    }
    cout << "Time taken by function: " << size << " " << (sum / size) << endl;
}


int main()
{
    const int SIZE1 = 10;
    const int SIZE2 = 20;
    const int SIZE3 = 30;
    const int SIZE4 = 40; 
    const int SIZE5 = 50;
    const int SIZE6 = 100;
    const int SIZE7 = 500;
    const int SIZE8 = 1000;
    int array[10][10];
    int array2[SIZE2][SIZE2];
    int array3[SIZE3][SIZE3];
    int array4[SIZE4][SIZE4];
    int array5[SIZE5][SIZE5];
    int array6[SIZE6][SIZE6];
    int array7[SIZE7][SIZE7];
    int array8[SIZE8][SIZE8]; 
    generateArrayTen(array, 10);
    generateArrayTwenty(array2, SIZE2);
    generateArrayThirty(array3, SIZE3);
    generateArrayFourty(array4, SIZE4);
    generateArrayFifty(array5, SIZE5);
    generateArrayOneHundred(array6, SIZE6);
    generateArrayFiveHundred(array7, SIZE7);
    generateArrayOneThousand(array8, SIZE8);
}
