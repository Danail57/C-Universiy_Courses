

/*17)Да се състави програма, която от цифрите на числата
 *образува намаляваща нестрого последователност
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << " n = ";
    cin >> n;

    int A[100];
    for (int i = 0; i < n; i++) {
        cout << "A[" << i + 1 << "] = ";
        cin >> A[i];
    }
    cout << "Decreasing digits: " << endl;
    for (int i = 0; i < n; i++) {

        int x = abs(A[i]);
        bool decreasing = true;
        int last_digit = -1;

        while (x > 0) {
            int digit = x % 10;
            if (digit < last_digit) {
                decreasing = false;
                break;
            }
            last_digit = digit;
            x /= 10;
        }
        if (decreasing) {
            cout << A[i] << endl;
        }
    }
}
