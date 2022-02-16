// Assignment05.cpp : Defines the entry point for the application.
// Eric Miller

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

void menu() {
	cout << "Option 1: Display all items " << endl;
	cout << "Option 2: Display selected item " << endl;
	cout << "Option 3: Mark a task as done " << endl;
	cout << "Option 4: Exit the program " << endl;
}



int main()

 {
	string str;
	string buf;
	

	vector<string> tokens;

	ifstream inf;
	inf.open("Assignment05TestData.txt");
	while (!inf.eof()) {
		inf >> str;
		stringstream ss(str);
		while (ss >> buf) {
			tokens.push_back(buf);
		}

		string taskNumber, taskLetter, task;

		if (!tokens.empty()) {
			taskNumber = tokens.front();
			tokens.erase(tokens.begin());
		}

		if (!tokens.empty()) {
			taskLetter = tokens.front();
			tokens.erase(tokens.begin());
		}

		const char* const delim = " ";

		ostringstream combined;
		copy(tokens.begin(), tokens.end(), ostream_iterator<string>(combined, delim));

		task = combined.str();

		cout << taskNumber << " " << taskLetter << " " << task << endl;

		return 0;
	}
/*	menu();
	switch (option) {
	case 1: // input the function to display all items 
	case 2: // input the function to display selected item
	case 3: // mark a task as being completed
	case 4: // Exit the program 
	}*/
}
