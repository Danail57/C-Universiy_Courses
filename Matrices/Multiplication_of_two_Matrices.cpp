/*Напишете програма, която умножава две матрици*/

#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
    int n1, m1, n2, m2;
    cout << "Enter rows and columns for the first matrix: ";
    cin >> n1 >> m1;

    cout << "Enter rows and columns for the second matrix: ";
    cin >> n2 >> m2;

    if (m1 != n2)
    {
        cout << "Error: count of first column matrix must be equal to count of rows of second matrix.";
        return 1;
    }
    int A[100][100] = {0};
    int B[100][100] = {0};
    int C[100][100] = {0};
    cout << "Enter the numbers of first matrix:\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cout << "A["<< i + 1 <<"]["<< j + 1 <<"] = ";
            cin >> A[i][j];
        }
    }
    cout << "Enter the numbers of second matrix:\n";
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < m2; j++) {
            cout << "B["<< i + 1 <<"]["<< j + 1 <<"] = ";
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "\nResult matrix:\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            cout << setw(5) << C[i][j];
        }
        cout << endl;
    }
    return 0;
}
