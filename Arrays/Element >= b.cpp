
/*31) Масивът a0, a1,..., am-1 е нареден във възходящ ред,
 *т.е. за всяко i<m. Да се определи номера на първия
 *срещнат елемент, който е по-голям или
 *равен на дадена стойност b.
 *
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int a[100];
    cout << "Write the elements in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << "a["<< i + 1 <<"] = ";
        cin >> a[i];
    }

    int pos = -1;
    bool found = false;

    int b;
    cout << "b = ? - write any number: ";
    cin >> b;

    for (int i = 0; i < n; i++) {
        if (a[i] >= b) {
            found = true;
            pos = i;
            break;
        }
    }
    if (found)
    {
        cout << "The first element >= " << b << " is at position a[" << pos + 1 << "] = " << a[pos] << endl;
    }
    else
    {
        cout << "No element is >= " << b << endl;
    }

}
