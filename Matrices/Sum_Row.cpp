
/*17) Задена е матрица A с размер n x m.
Да се намери сумата на елементите във
всеки ред и резултатът да се запише в едномерен масив
*/

#include <cmath>
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

    int sum[100];
    int A[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A["<< i+1 <<"]["<< j+1 <<"] = ";
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        sum[i] = 0;
        for (int j = 0; j < m; j++) {
            sum[i] += A[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << "Sum of row " << i + 1 << " = " << sum[i] << endl;
    }
}
