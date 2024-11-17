#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct record
{
    int roll;
    char name[20];
} rrecord;

int main()
{
    int x = 10;
    float y = 1.2;
    double z = 12.34;

    char ch = 'A';
    int arr[3] = {1, 2, 3};
    rrecord.roll = 3101;

    strcpy(rrecord.name, "moeed");
    fstream ou;
    ou.open("file.txt", ios::binary | ios::out);
    if (!ou.is_open())
    {
        cout << "Cannot open file ..\n";
    }
    else
    {
        ou.write((char *)&x, sizeof(x));
        ou.write((char *)&y, sizeof(y));
        ou.write((char *)&z, sizeof(z));
        ou.write((char *)&arr, sizeof(arr));
        ou.write((char *)&ch, sizeof(ch));
        ou.write((char *)&rrecord.name, sizeof(rrecord.name));
        ou.write((char *)&rrecord.roll, sizeof(rrecord.roll));
    }

    ou.close();
    int X;
    float Y;
    double Z;
    char cH;
    int Arr[3];
    fstream inn;
    inn.open("file.txt", ios::binary | ios::in);
    if (inn.is_open() == 0)
    {
        cout << "Cant open file ..\n";
    }
    else
    {
        inn.read((char *)&X, sizeof(X));
        inn.read((char *)&Y, sizeof(Y));
        inn.read((char *)&Z, sizeof(Z));
        inn.read((char *)&Arr, sizeof(Arr));
        inn.read((char *)&cH, sizeof(cH));
        inn.read((char *)&rrecord.name, sizeof(rrecord.name));
        inn.read((char *)&rrecord.roll, sizeof(rrecord.roll));
    }
    cout << "X = " << X << endl;
    cout << "Y = " << Y << endl;
    cout << "Z = " << Z << endl;
    cout << "CH = " << cH << endl;
    cout << "record.name = " << rrecord.name << endl;
    cout << "record.rollNo = " << rrecord.roll << endl;

    for (int i = 0; i < 3; i++)
    {

        cout << "Arr[" << i << "] = " << Arr[i] << endl;
    }
}