// Да се състави алгоритъм за получаване на 
// масива p1, p2, ..., pk от масива w1, w2, ..., wn.
// Новият масив не трябва да съдържа 
// съседни повтарящи се елементи.

#include <iostream>
using namespace std;

int main()
{
    int n;

    while (true)
    {
        cout << "Enter the number of elements(1 - 1000): ";
        cin >> n;

        if (!cin || n < 1 || n > 1000)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number between 1 and 1000.\n";
            continue;
        }
        break;
    }

    int w[1000];

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "w[" << i << "] = ";
            cin >> w[i];

            if (!cin)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter an integer.\n";
                continue;
            }
            break;
        }
    }

    int p[1000];
    int k = 0;

    // първият елемент влиза винаги
    p[k++] = w[0];

    for (int i = 1; i < n; i++)
    {
        if (w[i] != w[i - 1])
        {
            p[k++] = w[i];
        }
    }

    cout << "Array without adjacent duplicates: ";
    for (int i = 0; i < k; i++)
    {
        cout << p[i] << " ";
    }

    cout << endl;
    return 0;
}
