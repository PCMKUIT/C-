#include <iostream>
#include <string>
using namespace std;
class Malware {
protected:
    string name;
    string file;
    double detection_rate;

public:
    Malware() {}

    Malware(const string& name, const string& file, double detection_rate)
        : name(name), file(file), detection_rate(detection_rate) {}

    void Xuat() const {
        cout << "Name: " << name << std::endl;
        cout << "File: " << file << std::endl;
        cout << "Detection Rate: " << detection_rate << "%" << std::endl;
    }

    void Nhap() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter file: ";
        cin >> file;
        cout << "Enter detection rate: ";
        cin >> detection_rate;
    }
};

class Virus : public Malware {
private:
    string signature;
    string behavior;

public:
    Virus() {}

    Virus(const string& name, const string& file, const string& signature, const string& behavior)
        : Malware(name, file, determine_detection_rate(signature)), signature(signature), behavior(behavior) {}

    static double determine_detection_rate(const string& signature) {
        if (signature == "ILoveYou") {
            return 99.99;
        }
        else {
            return 0.01;
        }
    }

    void Xuat() const {
        Malware::Xuat();
        cout << "Signature: " << signature << std::endl;
        cout << "Behavior: " << behavior << std::endl;
    }

    void Nhap() {
        Malware::Nhap();
        cout << "Enter signature: ";
        cin >> signature;
        cout << "Enter behavior: ";
        cin >> behavior;
    }
};

class Ransomware : public Malware {
private:
    string encryptKey;
    int ransomAmount;

public:
    Ransomware() {}

    Ransomware(const string& name, const string& file, const string& encryptKey, int ransomAmount)
        : Malware(name, file, determine_detection_rate(encryptKey)), encryptKey(encryptKey), ransomAmount(ransomAmount) {}

    static double determine_detection_rate(const string& encryptKey) {
        if (encryptKey.length() < 8) {
            return 96.69;
        }
        else {
            return 3.31;
        }
    }

    void Xuat() const {
        Malware::Xuat();
        cout << "Encrypt Key: " << encryptKey << std::endl;
        cout << "Ransom Amount: " << ransomAmount << std::endl;
    }

    void Nhap() {
        Malware::Nhap();
        cout << "Enter encrypt key: ";
        cin >> encryptKey;
        cout << "Enter ransom amount: ";
        cin >> ransomAmount;
    }
};

int main() {
    Virus virus;
    cout << "Nhap thong tin virus:" << endl;
    virus.Nhap();
    cout << std::endl;

    Ransomware ransomware;
    cout << "Nhap thong tin ransomware:" << endl;
    ransomware.Nhap();
    cout << std::endl;

    cout << "Thong tin virus:" << endl;
    virus.Xuat();
    cout << std::endl;

    cout << "Thong tin ransomware:" << endl;
    ransomware.Xuat();

    return 0;
}