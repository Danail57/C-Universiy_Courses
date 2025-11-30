// Даден е двумерен масив А с m реда и n стълба.
// Да се състави програма, която създава нов масив а0, а1,...,аm-1, 
// като стойността на аi  е равна на сумата на отрицателните елементи в i-ия ред. 

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int m_rows, n_cols;
    cout << "Enter a number for rows: ";
    cin >> m_rows;

    cout << "Enter a number for cols: ";
    cin >> n_cols;

    vector<vector<int>> A(m_rows, vector<int>(n_cols));

    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < n_cols; j++)
            cin >> A[i][j];

    vector<int> row_sum_negative(m_rows, 0);

    for (int i = 0; i < m_rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < n_cols; j++)
        {
            if (A[i][j] < 0)
            {
                sum += A[i][j]; 
            }
        }
        row_sum_negative[i] = sum;
    }

    cout << "\nMatrix A:\n";
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
            cout << setw(6) << A[i][j];

        cout << "  | Sum of negatives: " << setw(6) << row_sum_negative[i] << endl;
    }
    return 0;
}
