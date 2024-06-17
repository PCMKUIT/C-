#include <bits/stdc++.h>
using namespace std;

string decryptROT2(const string &text) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += (c - base - 2 + 26) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

string encryptROT2(const string &text) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += (c - base + 2) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string inputText;
    int choice;

    while (true) {
	    cout << "Enter string: ";
		getline(cin, inputText);
        cout << "Menu:\n";
        cout << "1. DecryptROT2\n";
        cout << "2. EncryptROT2\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            string decryptedText = decryptROT2(inputText);
            cout << "Decrypted string: " << decryptedText << endl;
        } else if (choice == 2) {
            string encryptedText = encryptROT2(inputText);
            cout << "Encrypted string: " << encryptedText << endl;
        } else {
            cout << "Invalid command" << endl;
        }

        char cont;
        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') {
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
