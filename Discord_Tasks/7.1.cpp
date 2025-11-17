#include <iostream>
using namespace std;

// Едномерен масив съдържа оценки на група студенти от изпит.
// Да се намери средния успех на студентите,
// които са си взели изпита.

int main()
{
    int N;
    // Валидация на броя студенти 
    while (true)
    {
        cout << "Enter the number of students: ";
        cin >> N;

        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a whole number for students!\n";
            continue;   
        }

        if (N < 1 || N > 1000)
        {
            cout << "Number of students must be between 1 and 1000.\n";
            continue;
        }

        break;  
    }


    float marks[1000];
    cout << "Enter the score marks (from 2.00 to 6.00): " << endl;

    // Валидация на оценките 
    for (int i = 0; i < N; i++)
    {
        float value;
        while (true)
        {
            cout << "Mark[" << i << "]: ";
            cin >> value;

            if (!cin)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter between 2.00 and 6.00!\n";
                continue;
            }

            if (value < 2.0 || value > 6.0)
            {
                cout << "Mark must be between 2.00 and 6.00.\n";
                continue;
            }

            marks[i] = value;
            break;
        }
    }


    float sum = 0;
    int count_passed = 0;

    for (int i = 0; i < N; i++)
    {
        if (marks[i] >= 3.0)
        {
            sum += marks[i];
            count_passed++;
        }
    }

    if (count_passed > 0)
    {
        float average = sum / count_passed;
        cout << "The average from the exam is: " << average << endl;
    }
    else
    {
        cout << "No students passed the exam." << endl;
    }

    return 0;
}

