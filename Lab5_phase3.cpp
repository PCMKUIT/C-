#include <bits/stdc++.h>
using namespace std;

void printLine(int index) {
    switch (index) {
        case 0:
            cout << "0 704";
            break;
        case 1:
            cout << "1 94";
            break;
        case 2:
            cout << "2 500";
            break;
        case 3:
            cout << "3 409";
            break;
        case 4:
            cout << "4 145";
            break;
        case 5:
            cout << "5 177";
            break;
        case 6:
            cout << "6 829";
            break;
        case 7:
            cout << "7 913";
            break;
        default:
            cout << "BOMB!!!!\nThe bomb has blown up. Try again." << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % 8;
    printLine(randomIndex);
    return 0;
}
