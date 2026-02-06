/*Даден е масив с m реда и n стълба. Намерете
 *произведението на редовете на числата
 *и средноаритметичното на всяка колона
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

    int A[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }
    cout << "Product of each row: " << endl;
    for (int i = 0; i < m; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            product *= A[i][j];
        }
        cout << "Row " << i + 1 << ": " << product << endl;
    }

    cout << "Average of each column: " << endl;
    for (int j = 0; j < n; j++) {
        double sum = 0;
        for (int i = 0; i < m; i++) {
            sum += A[i][j];
        }
        double average = sum / m;
        cout << "Column " << j + 1 << ": " << average << endl;
    }
}
