
/*4) Напишете програма, извеждаща вички числа
 *от M - N чиито цифри образуват
 *строго нарастваща последователност
*/

#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the limit (m - n): ";
    cin >> m >> n;

    int a;
    cout << "Enter the number of array: ";
    cin >> a;

    int A[100];
    for (int i = 0; i < a; i++)
    {
        cout << "A["<< i + 1 << "] = ";
        cin >> A[i];
    }
    for (int i = m; i <= n; i++) {
        int number = i;
        int prev = 10;
        bool strictly_increasing = true;

        while (number > 0) {
            int digit = number % 10;
            if (digit >= prev) {
                strictly_increasing = false;
                break;
            }
            prev = digit;
            number /= 10;
        }
        if (strictly_increasing) {
            cout << i << " ";
        }
    }
    cout << endl;
}
