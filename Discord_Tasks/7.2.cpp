// Да се намери номерът на най-големия елемент в едномерен масив от цели числа.

#include <iostream>
using namespace std;

int main()
{
    int N_elements;

    
    while (true)
    {
        cout << "Enter how many elements you want to type (1-1000): ";
        cin >> N_elements;

        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a whole number.\n";
            continue;
        }

        if (N_elements < 1 || N_elements > 1000)
        {
            cout << "Number must be between 1 and 1000.\n";
            continue;
        }
        break; 
    }

    int N_arr[1000];

    // Entering the elements
    for (int i = 0; i < N_elements; i++)
    {
        cout << "Element[" << i << "]: ";
        cin >> N_arr[i];
    }

    // Finding the max element
    int max_index = 0;
    for (int i = 1; i < N_elements; i++)
    {
        if (N_arr[i] > N_arr[max_index])
        {
            max_index = i;
        }
    }

    cout << "The largest element is " << N_arr[max_index]
        << " at index " << max_index << endl;

    return 0;
}
