/*Матрицата се нарича заключена, ако:
- Главният диагонал е строго нарастващ
- Вторичният диагонал е строго намаляващ
- Сумата на елементите над главния диагонал
е равна на сумата на елементите под вторичния диагонал
Да се напише програма, която проверява дали
матрицата е заключена.*/

#include <iostream>
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
    bool locked = true;
    for (int i = 0; i < n - 1; i++) {
        if (A[i][i] >= A[i + 1][i + 1]) {
            locked = false;
            break;
        }
    }
    for (int i = 0; i < n - 1 && locked; i++) {
        if (A[i][n - 1 - i] <= A[i + 1][n - 2 - 1]) {
            locked = false;
            break;
        }
    }
    int sum_above_main = 0;
    int sum_below_secondary = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i)
                sum_above_main += A[i][j];
            if (i + j > n - 1)
                sum_below_secondary += A[i][j];
        }
    }
    if (sum_above_main != sum_below_secondary)
        locked = false;
    if (locked)
        cout << "The matrix is locked" << endl;
    else
        cout << "The matrix is not locked" << endl;
    return 0;
}
