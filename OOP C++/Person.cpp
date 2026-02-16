#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
    string name;
    int age;

    public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void print_info() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    bool is_adult() {
        return age >= 18;
    }
};

int main()
{
    Person p1("Ivan", 20);
    p1.print_info();
    if (p1.is_adult()) {
        cout << "This person is an adult" << endl;
    }
    else {
        cout << "This person is not an adult." << endl;
    }
    return 0;
}
