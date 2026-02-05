#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "My name is " << name << " and I am " << age << " years old" << endl;
    }
};

int main() {
    Student student;
    student.name = "Ivan";
    student.age = 18;
    student.display();
}

