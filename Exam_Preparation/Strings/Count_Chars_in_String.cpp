

/*11) Зададен е едномерният масив от символни низове А0, А1,...,Аn-1. Да
се състави програма, която създава нов масив а0, а1,...,аn-1, като
стойността на аi показва колко пъти се среща зададен символ в
низа Аi.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "How many strings you want to write? ";
    cin >> n;

    string A[200];
    for (int i = 0; i < n; i++) {
        cout << "Write a string: ";
        cin >> A[i];
    }

    char ch;
    cout << "Enter the symbol to search: ";
    cin >> ch;

    int a[200];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < A[i].length(); j++) {
            if (A[i][j] == ch) {
                count++;
            }
        }
        a[i] = count;
    }
    for (int i = 0; i < n; i++) {
        cout << "a["<< i + 1 <<"] = " << a[i] << endl;
    }
    return 0;
}
