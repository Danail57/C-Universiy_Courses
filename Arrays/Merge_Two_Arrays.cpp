
/*33) Дадени са едномерните масиви a с m елемента
 *и b с n елемента. Елементите им са подредени в
 *ненамаляващ на стойностите им ред.
 *Да се слеят двата масива в масив d с m+n елемента,
 *също подреден в ненамаляващ ред.
 *
*/

#include <iostream>
using namespace std;

int main()
{
    int m;
    cout << "Enter the elements SORTED in non-decreasing order:\n ";
    cin >> m;

    int a[100];
    for (int i = 0; i < m; i++) {
        cout << "a["<< i + 1 <<"] = ";
        cin >> a[i];
    }

    int n;
    cout << "Enter the elements SORTED in non-decreasing order:\n ";
    cin >> n;

    int b[100];
    for (int i = 0; i < n; i++) {
        cout << "b["<< i + 1 <<"] = ";
        cin >> b[i];
    }
    int d[200];

    // броячи за масив а, масив b и масив d
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i] <= b[j])
            d[k++] = a[i++];
        else
            d[k++] = b[j++];
    }
    while (i < m)
        d[k++] = a[i++];
    while (j < n)
        d[k++] = b[j++];
    cout << "Merged array d: ";
    for (int i = 0; i < m + n; i++)
        cout << d[i] << " ";
    cout << endl;
}
