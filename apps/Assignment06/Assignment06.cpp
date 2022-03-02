#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

list<string> wordList;

class stringContext
{
private:
	string values;
public:
	stringContext()
	{
		values = "";
	}

	string getStringValue()
	{
		return values;
	}

	void setStringValues(string context)
	{
		values = context;
	}

};

int main() {
	string context; 
	string keyword;  
	string line;
	string words[100];
	string word;

	int count;
	int i;
	char ch;

		stringContext strings[30];
		count = 0;

		ifstream inf;
		inf.open("test.txt");

		if (inf) {
			
			cout << "Enter the keyword: ";
			cin >> keyword;
			
			while (!inf.eof()) {
				
				getline(inf, line);
				i = 0;
				
				stringstream ss(line);
				while (ss >> word) {
					
					wordList.push_back(word);
				}
				
				for (int j = 0; j < i; j++) {
					if (words[j].compare(keyword) == 0) {
						context = "";
						context += words[j - 2] + " ";
						context += words[j - 1] + " ";
						context += words[j] + " ";
						context += words[j + 1] + " ";
						context += words[j + 2] + " ";
						strings[count].setStringValues(context);
					}
				}
				count++;
			}
			
			for (int l = 0; l < count; l++) {
				cout << " \"" << strings[l].getStringValue() << "\"" << endl;
			}
		}
		else {
			cout << "\nSorry! Unable to open the file." << endl;
		}
	
		inf.close();
		
	system("pause");
	return 0;
}
