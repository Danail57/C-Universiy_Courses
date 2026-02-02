
/*32) Даден е масивът а0, а1,..., аn-1, подреден в
 *нарастващ ред, и променливата b.
 *Да се разшири масива с един елемент
 *равен на стойността на b, без да се
 *нарушава подреждането на масива
 *
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[1000];
    cout << "Enter the elements in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << "a["<< i + 1 <<"] = ";
        cin >> a[i];
    }
    int b;
    cout << "Enter a random number to insert: ";
    cin >> b;

    int pos = 0;
    while (pos < n && a[pos] < b) {
        pos++;
    }
    // moving the elements right
    for (int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos] = b;
    n++;
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
