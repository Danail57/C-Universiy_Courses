#include <iostream>
using namespace std;

// Въвеждане на масив
void in_arr1(int x[], int& n)
{
    if (n <= 0)
    {
        cout << "Enter how many elements you want to type: ";
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " element: ";
        cin >> x[i];
    }
}

// Сумиране на елементите
int sum_arr1(int x[], const int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += x[i];
    return s;
}

int main()
{
    int r[100], BrEl = 0;
    in_arr1(r, BrEl);

    cout << "Entered elements: ";
    for (int i = 0; i < BrEl; i++)
        cout << r[i] << " ";
    
    cout << "\nSum: " << sum_arr1(r, BrEl) << endl;

    return 0;
}
