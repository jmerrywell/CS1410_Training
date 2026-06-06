#include <iostream>
#include <string>

using namespace std;

int main() {
    int age;
    string fullName;

    cout << "Enter age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Full Name: ";
    getline(cin, fullName);

    cout << "Hello! you are " << age << " years old, nad your full name is " 
        << fullName << endl;

    return 0;
}