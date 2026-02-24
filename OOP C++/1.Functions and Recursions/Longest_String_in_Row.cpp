/*  Зададен е двумерният масив от
 *  символни низове А с m реда и n стълба.
 *  Да се състави програма с функции,
 *  която намира най-големия низ във всеки ред.
 *  Дължината на низовете е ограничена до 10 знака.
 */

#include <iostream>
#include <cstring>
using namespace std;


const int MAX_SIZE_STRING = 11;


void type_strings(char array[][MAX_SIZE_STRING], int n)
{
    for (int j = 0; j < n; j++)
    {
            cout << "Write string ["<< j + 1 << "]: ";
            cin >> array[j];
    }
}

int find_the_longest_string_in_row(char row[][MAX_SIZE_STRING], int n)
{
    int longest_index = 0;
    size_t max_length = strlen(row[0]);

    for (int j = 0; j < n; j++)
    {
        size_t current_len = strlen(row[j]);
        if (current_len > max_length)
        {
            max_length = current_len;
            longest_index = j;
        }
    }
    return longest_index;
}

int main()
{
    cout << "NOTE: Write up to 10 char strings." << endl;
    int m, n;
    cout << "Enter rows (m) and columns (n): ";
    cin >> m >> n;
    char A[m][n][MAX_SIZE_STRING];

    for (int i = 0; i < m; i++)
    {
        cout << "Enter data string: " << i + 1 << ": " << endl;
        type_strings(A[i], n);
    }
    cout << "\nResult: " << endl;
    for (int i = 0; i < m; i++)
    {
        int longest_index = find_the_longest_string_in_row(A[i], n);
cout << "Longest string in row " << i + 1 << " is: " << A[i][longest_index] << endl;    }

}
