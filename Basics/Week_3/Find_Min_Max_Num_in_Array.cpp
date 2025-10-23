#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter how many numbers you want to type: ";
    cin >> n;

    double num, min, max;

    cout << "Enter your first number: ";
    cin >> num;

    min = num;
    max = num;

    for (int i= 2; i <= n; i++)
    {
        cout << "Enter number " << i << ": ";
        cin >> num;

        if (num < min)
            min = num;

        if (num > max)
            max = num;
    }

    cout << "The smallest number is: " << min << endl;
    cout << "The largest number is: " << max << endl;

    return 0;
}
