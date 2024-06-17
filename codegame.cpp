#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int randomNumber = rand() % 101;
    int guess;

    cout << "					DOAN SO" << endl;
    do {
        cout << "Ban doan so (tu 0 den 100): ";
        cin >> guess;
        if (guess < 0 || guess > 100) cout<<"Vui long nhap lai so tu 0 den 100.";
        else{
        if (guess < randomNumber) cout << "So ban nhap vao nho hon so can doan. Hay thu lai!" << endl;
		else if (guess > randomNumber) cout << "So ban nhap vao lon hon so can doan. Hay thu lai!" << endl;
		else cout << "Bingo! Do la cau tra loi chinh xac!" << endl;}
    } while (guess != randomNumber);

    return 0;}
