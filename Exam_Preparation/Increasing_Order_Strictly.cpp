

/*17)Да се състави програма, която от цифрите на числата
 *образува строго нарастваща последователност
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of array: ";
    cin >> n;
    int A[100];
    for (int i = 0; i < n; i++) {
        cout << "A["<< i + 1 <<"] = ";
        cin >> A[i];
    }
    cout << "Numbers with strictly increasing digits:" << endl;
    for (int i = 0; i < n; i++) {
        int x = A[i];
        bool increasing = true;
        x = abs(x);

        int last_digit = 10;
        while (x > 0) {
            int digit = x % 10;
            if (digit >= last_digit) {
                increasing = false;
                break;
            }
            last_digit = digit;
            x = x / 10;
        }
        if (increasing) {
            cout << A[i] << endl;
        }
    }
    return 0;
}
