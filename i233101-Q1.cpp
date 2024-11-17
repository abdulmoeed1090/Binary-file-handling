#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student
{

    char name[50];
    int regNo;
    char program[50];
    int contactNo;
};

int main()
{

    Student s[10];
    Student S[10];
    cout << "Abdul Moeed..\n";

    fstream file;
    file.open("Record.txt", ios::binary | ios::out);
    if (!file.is_open())
    {
        cout << "File is not open...⚠️⚠️\n";
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Student " << i + 1 << ":\n";
        cout << "Reg No: ";
        cin >> s[i].regNo;
        cout << "Name: ";
        cin.ignore();
        cin.getline(s[i].name, 50);
        cout << "Program: ";
        cin.getline(s[i].program, 50);
        cout << "Contact: ";
        cin >> s[i].contactNo;
        cout << endl;
    }
    file.write((char *)&s, sizeof(s));
    file.close();
    fstream inn;

    inn.open("Record.txt", ios::binary | ios::in);
    if (!inn.is_open())
    {
        cout << "Cannot open file...\n";
        return 1;
    }

    inn.read((char *)&S, sizeof(S));
    inn.close();

    cout << "\nStudent Records from file:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Student " << i + 1 << ":\n";
        cout << "Reg No: " << S[i].regNo << "\n";
        cout << "Name: " << S[i].name << "\n";
        cout << "Program: " << S[i].program << "\n";
        cout << "Contact: " << S[i].contactNo << "\n\n";
    }

    return 0;
}
