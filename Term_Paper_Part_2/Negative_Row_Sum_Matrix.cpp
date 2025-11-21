#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n_rows, m_cols;
    int U_array[100][100];
    int T_negative_array[100];

    //  Entering the count for rows
    cout << "Enter number of rows (1 - 100): ";
    cin >> n_rows;
   
    while (cin.fail() || n_rows < 1 || n_rows > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter number of rows (1 - 100): ";
        cin >> n_rows;
    }

    // Entering the count for cols
    cout << "Enter number of columns (1 - 100): ";
    cin >> m_cols;
    
    while (cin.fail() || m_cols < 1 || m_cols > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter number of columns (1 - 100): ";
        cin >> m_cols;
    }

    // Entering elements for the matrix
    cout << "\nEnter the elements of the matrix U:\n";
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            while (true)
            {
                cout << "U[" << i << "][" << j << "]: ";
                cin >> U_array[i][j];
                if (!cin.fail()) break;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Enter number again.\n";
            }
        }
    }

    
    cout << "\nMatrix U:\n";
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            cout << setw(6) << U_array[i][j];
        }
        cout << endl;
    }

    // Sum of negative elements on rows
    for (int i = 0; i < n_rows; i++)
    {
        int negative_sum = 0;
        for (int j = 0; j < m_cols; j++)
        {
            if (U_array[i][j] < 0)
            {
                negative_sum += U_array[i][j];
            }
        }
        T_negative_array[i] = negative_sum;
    }

    // Showing the T array
    cout << "\nArray T (sum of negative numbers by row):\n";
    for (int i = 0; i < n_rows; i++)
    {
        cout << "T[" << i << "] = " << T_negative_array[i] << endl;
    }
    return 0;
}
