// Key Word In Context 
// Eric Miller

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

string getInputFromFile(const string& filename) {
    ifstream inf;
    inf.open(filename);
    string line;
    string text; 
    while (inf) {
        getline(inf, line);
        text += line;
    }
    return text;
}

vector<string> KWIC(const string& text, const string& key) {
    vector<string> res; 
    vector<string> data; 
    vector<int> idx; 

    stringstream ss(text);

    string token;
    while (getline(ss, token, ' ')) {
        for (auto& c : token) {
            c = toupper(c);
        }
        data.push_back(token);
        if (key == token) {
            idx.push_back(data.size() - 1);
        }
    }

    int n = data.size();
    for (int id : idx) {
        string s;
        for (int j = id - 3; j <= min(n - 1, id + 3); j++) {
            s += data[j] + ' ';
        }
        res.push_back(s);
    }
    sort(begin(res), end(res));
    return res;
}

int main() {
    string keyword;
    string text = getInputFromFile("test.txt");
    cout << "Enter the keyword you want to find: ";
    cin >> keyword;
    vector<string> res = KWIC(text, keyword);
    for (string& s : res) {
        cout << s << endl;
    }
    return 0;
}
