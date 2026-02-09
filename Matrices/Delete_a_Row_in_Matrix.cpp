/*Дадена е правоъгълна матрица n×m.
Да се напише програма, която изтрива к-тия ред
на матрицата*/

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    int A[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "A["<< i + 1<< "]["<< j + 1 << "]: = ";
            cin >> A[i][j];
        }
    }
    int k;
    cout << "Enter row to delete (1 - "<< n <<"): ";
    cin >> k;
    k--;
    for (int i = k; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = A[i + 1][j];
        }
    }
    n--;
    cout << "\nResult matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
