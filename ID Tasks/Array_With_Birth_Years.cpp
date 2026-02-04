

/*24) Зададен е двумерен масив А с m реда n стълба, съдържащ ЕГН-та
на група лица. Да се състави програма, която създава нов двумерен
масив а с m реда n стълба, като стойността на аij е равна на
годината на раждане на лицето с ЕГН Аij.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m;
    cout << "Enter the number of rows: ";
    cin >> m;

    int n;
    cout << "Enter the number of columns: ";
    cin >> n;

    string A[100][100];
    int a[45][45];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int year = stoi(A[i][j].substr(0, 2));
            int month = stoi(A[i][j].substr(2, 2));

            if (month > 40) {
                month -= 40;
                year += 2000;
            }
            else if (month > 20) {
                month -= 20;
                year += 1800;
            }
            else {
                year += 1900;
            }
            a[i][j] = year;
        }
    }
    cout << "Array of birth years: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
