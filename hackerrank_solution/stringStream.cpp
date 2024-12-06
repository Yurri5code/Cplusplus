#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> parseInts(string str) {
    vector<int> result;
    stringstream ss(str);
    char ch;
    int temp;

    // Lire les entiers séparés par des virgules
    while (ss >> temp) {
        result.push_back(temp);
        ss >> ch; // Lire la virgule
    }

    return result;
}

int main() {
    string str;
    getline(cin, str); // Lire la ligne complète

    vector<int> integers = parseInts(str);
    for (int integer : integers) {
        cout << integer << "\n";
    }

    return 0;
}
