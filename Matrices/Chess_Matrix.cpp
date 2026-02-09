/*Дадена е матрица n×m.
На черните полета (като шахматна дъска)
се намира максималният елемент
На белите полета се намира минималният елемент
Всички останали елементи се заменят с 0
(i+j)%2==0 → бяло поле*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int A[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A["<< i + 1 <<"]["<< j + 1 << "]: = ";
            cin >> A[i][j];
        }
    }
    int min_el = 0;
    int max_el = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] < min_el) min_el = A[i][j];
            if (A[i][j] > max_el) max_el = A[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0)
                A[i][j] = min_el;
            else
                A[i][j] = max_el;
        }
    }
    cout << "\nResult matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
