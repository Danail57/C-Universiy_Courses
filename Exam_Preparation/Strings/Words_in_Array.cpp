

/*10) Зададен е едномерният масив от символни низове А0, А1,...,Аn-1. Да
се състави програма, която създава нов масив а0, а1,...,аn-1, като
стойността на аi е равна на броя на символите в низа Аi.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    string A[100];
    int a[100];
    for (int i = 0; i < n; i++) {
        cout << "A["<< i + 1 <<"] = ";
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = A[i].length();
    }
    cout << "New array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "a["<< i + 1 <<"] = " << a[i] << endl;
    }
    return 0;
}
