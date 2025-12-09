/*Да се намери произведението от ненулевите елементи
във всяка колона на двумерен масив 
с m реда и n стълба.*/

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    int a[100][100];

    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nProduct of non-zero elements in each column:\n";

    for (int col = 0; col < n; col++) {
        int product = 1;
        bool hasNonZero = false;

        for (int row = 0; row < m; row++) {
            if (a[row][col] != 0) {
                product *= a[row][col];
                hasNonZero = true;
            }
        }

        if (hasNonZero)
            cout << "Column " << col + 1 << ": " << product << endl;
        else
            cout << "Column " << col + 1 << ": no non-zero elements" << endl;
    }

    return 0;
}
