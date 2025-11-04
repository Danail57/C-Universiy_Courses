#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid number of students!" << endl;
        return 1;
    }

    double marks[100];
    double sum = 0;

    cout << "Enter marks from 2 to 6:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << " mark: ";
        cin >> marks[i];

        while (marks[i] < 2 || marks[i] > 6)
        {
            cout << "Invalid mark! Enter a value between 2 and 6: ";
            cin >> marks[i];
        }

        sum += marks[i];
    }

    double average = sum / n;

    cout << "\nResults:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << " - mark: " << marks[i];
        if (marks[i] >= 3)
            cout << " -> Passed the exam.\n";
        else
            cout << " -> Failed the exam.\n";
    }

    cout << "\nAverage mark: " << average << endl;

    return 0;
}

