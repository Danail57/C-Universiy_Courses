
/*5) Даден е двумерен масив А с m реда и n стълба. Да се състави
програма, която създава нов масив а0, а1,...,аm-1, като стойността на
аi е равна на сумата на положителните елементи в i-ия ред.
*/

#include <iostream>
using namespace std;

int main()
{
    int m;
    cout << "Enter the number of rows: ";
    cin >> m;

    int n;
    cout << "Enter the number of columns: ";
    cin >> n;

    int A[80][80];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A["<< i + 1 <<"]["<< j + 1 << "]: ";
            cin >> A[i][j];
        }
    }
    int new_array[100];
    for (int i = 0; i < m; i++) {
        int sum_positive = 0;
        for (int j = 0; j < n; j++) {
            if (A[i][j] > 0) {
                sum_positive += A[i][j];
            }
        }
        new_array[i] = sum_positive;
    }
    cout << "New sum positive array: " << endl;
    for (int i = 0; i < m; i++) {
        cout << "New array[" << i + 1 << "]: " << new_array[i] << endl;
    }
    return 0;
}
