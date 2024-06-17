#include <bits/stdc++.h>
using namespace std;
const string baseString = "maduiersnfotvbyl";

void getValidString(string &input) {
	cout << "Enter string: ";
    while (true) {
        getline(cin, input);
        if (input.length() == 6) break;
        cout << "Invalid string, enter string again: ";
    }
}

string getHexPositions(const string &input) {
    string hexPositions = "";
    for (char c : input) {
        size_t pos = baseString.find(c);
        if (pos != string::npos) {
            if (pos < 10) hexPositions += to_string(pos) + " ";
            else hexPositions += char('A' + (pos - 10)) + string(" ");
        }
    }
    return hexPositions;
}

string getRandomHexString(const string &hexPositions) {
    srand(static_cast<unsigned int>(time(0)));
    string randomHexString = "";
    for (char c : hexPositions) {
        if (c == ' ') continue;
        char randomChar;
        do {
            randomChar = rand() % 16;
        } while (c == 'F' && randomChar == 7); 
        if (randomChar < 10) randomHexString += to_string(randomChar);
        else randomHexString += char('A' + (randomChar - 10));
        randomHexString += c;
    }
    return randomHexString;
}

int main() {
    string input;
    getValidString(input);
    string hexPositions = getHexPositions(input);
    cout << "The array position of array_3854 is obtained after processing: " << hexPositions << endl;
    string randomHexString = getRandomHexString(hexPositions);
    cout << "ASCII code of possible answer string: ";
    for (size_t i = 0; i < randomHexString.length(); i += 2) {
        cout << randomHexString.substr(i, 2) << " ";}
    return 0;
}
