
/*4) Да се образува нов масив p[k] от масива w[n].
 *Новият масив не трябва да съдържа съседни повтарящи
 *се елементи.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int w[1000];
    for (int i = 0; i < n; i++) {
        cout << "w["<< i + 1 <<"] = ";
        cin >> w[i];
    }
    int p[1000];
    int k = 0; // брояч за новия масив
    for (int i = 0; i < n; i++) {
        if (i == 0 || w[i] != w[i - 1]) {
            p[k] = w[i];
            k++;
        }
    }
    cout << "New array p (without consecutive duplicates): ";
    for (int i = 0; i < k; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}
