/*Напишете програма, която намира сумата от нечетните
 *числа под главния диагонал без него на дадена матрица*/

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
    for (i = 1; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] % 2 == 1)
                sum = sum + a[i][j];
    cout << "Sum = " << sum << endl;
    return 0;
}
