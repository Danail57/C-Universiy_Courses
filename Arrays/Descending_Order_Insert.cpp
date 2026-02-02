
/*31) Дадени са променливата q и едномерният
 *масив a с n елемента, наредени в низходящ ред.
 *Да се създаде нов масив b с още един елемент,
 *т. е. броят на елементите на b да стане m=n+1.
 *Стойността на допълнителния елемент да бъде q,
 *а мястото му да се определи така,
 *че новият масив b също да е нареден в низходящ ред..
 *
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of array: ";
    cin >> n;

    int a[1000];
    cout << "Enter the array elements in descending order: ";
    for (int i = 0; i < n; i++) {
        cout << "a ["<< i + 1 <<"] = ";
        cin >> a[i];
    }

    int q;
    cout << "q = ? - any number you want.";
    cin >> q;

    int b[1000];
    int pos = 0;
    bool found = false;

    while (pos < n && a[pos] > q)
        pos++;
    for (int i = 0; i < pos; i++)
        b[i] = a[i];
    b[pos] = q;

    for (int i = pos; i < n; i++)
        b[i + 1] = a[i];
    cout << "New array b: ";
    for (int i = 0; i <= n; i++)
        cout << b[i] << " ";
    cout << endl;

}
