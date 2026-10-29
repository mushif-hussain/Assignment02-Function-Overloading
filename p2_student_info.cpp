#include <iostream>
#include <string>
using namespace std;

// 1: char B me B ki value ASCII me convert hojati ha isliye (string,int wala code chalta ha)

// 2: Function overloading me sirf return type change krskty hein is wajah se agar hum printInfo me (char grade)
// yani return type change kartay hein to call ambiguos hojayegi

//  3: 1) void printInfo(string name, int rollNo)
//     2) void printInfo(int rollNo, string name)


void printInfo(string name)
{
    cout << "name: " << name << endl;
}

void printInfo(string name, int rollNo)
{
    cout << "name: " << name << " | Roll No: " << rollNo << endl;
}

void printInfo(int rollNo, string name) 
{
    cout << "Roll No: " << rollNo << "  name: " << name << endl;
}

void printInfo(string name, double cgpa) 
{
    cout << "name: " << name << " | CGPA: " << cgpa << endl;
}

void printInfo(char grade)
{
    cout << "Grade: " << grade << endl;
}

int main() 
{
    printInfo("Ali");
    printInfo("Ali", 12);
    printInfo(12, "Ali");
    printInfo("Ali", 3.5);
    printInfo('A');
    printInfo("Sara", 'B');
    return 0;
}