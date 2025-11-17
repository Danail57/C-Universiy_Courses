#include <iostream>
using namespace std;

int main()
{
    int N;

    // Validating the students
    while (true) 
    {
        cout << "Enter the number of students (1 - 1000): ";
        cin >> N;
        if (!cin || N < 1 || N > 1000) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number between 1 and 1000\n";
            continue;
        }
        break;
    }

    int faculty_numbers[1000];
    double marks1[1000], marks2[1000];

    for (int i = 0; i < N; i++) 
    {
        // Validation of the faculty number
        while (true) 
        {
            cout << "Student " << i + 1 << " faculty number (6 digits): ";
            cin >> faculty_numbers[i];
            if (!cin || faculty_numbers[i] < 100000 || faculty_numbers[i] > 999999) 
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid faculty number! Must be 6 digits.\n";
                continue;
            }
            break;
        }

      
        while (true) 
        {
            cout << "Mark for discipline 1 (2.00 - 6.00): ";
            cin >> marks1[i];
            if (!cin || marks1[i] < 2.0 || marks1[i] > 6.0) 
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid mark! Must be between 2.00 and 6.00.\n";
                continue;
            }
            break;
        }

   
        while (true) 
        {
            cout << "Mark for discipline 2 (2.00 - 6.00): ";
            cin >> marks2[i];
            if (!cin || marks2[i] < 2.0 || marks2[i] > 6.0) 
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid mark! Must be between 2.00 and 6.00.\n";
                continue;
            }
            break;
        }
    }

    // Weak students
    int weak_students[1000];
    int weak_count = 0;

    for (int i = 0; i < N; i++) 
    {
        if (marks1[i] < 3.0 && marks2[i] < 3.0) 
        {
            weak_students[weak_count] = faculty_numbers[i];
            weak_count++;
        }
    }

    // showing the result
    if (weak_count > 0) 
    {
        cout << "Students with weak marks in both disciplines: ";
        for (int i = 0; i < weak_count; i++) 
        {
            cout << weak_students[i] << " ";
        }
        cout << endl;
    }
    else 
    {
        cout << "No students with weak marks in both disciplines." << endl;
    }

    return 0;
}
