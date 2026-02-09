/*Напишете програма, която намира сумата от елементите
 *от вторичния диагонал кратни на n - тия ред на дадена матрица*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

int main()
{
    cout << "Enter the size of the matrix from 1 to " << MAX_SIZE <<":" << endl;
    int n; cin >> n;

    int a[MAX_SIZE][MAX_SIZE];
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "a["<<i + 1<<"]["<<j + 1<<"]: ";
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for (i = 0; i < n; i++)
        if (a[n - i - 1][i] % n == 0)
            sum += a[n - i - 1][i];
    cout << "Sum = " << sum << endl;
}
