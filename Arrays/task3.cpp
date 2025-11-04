#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int faculty_number;
        int mark;

        cout << "\nStudent " << i << ":\n";
        cout << "Faculty number (positive number): ";
        cin >> faculty_number;
        while (faculty_number <= 0) {
            cout << "Invalid faculty number! Try again: ";
            cin >> faculty_number;
        }

        cout << "Mark (2-6): ";
        cin >> mark;
        while (mark < 2 || mark > 6) {
            cout << "Invalid mark! Try again: ";
            cin >> mark;
        }

        if (mark < 3) {
            cout << "This student is weak!\n";
        }
        else {
            cout << "This student passed.\n";
        }
    }

    return 0;
}
