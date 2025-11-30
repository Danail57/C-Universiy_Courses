#include <iostream>
using namespace std;

int main()
{
    int m, n;

    cout << "Enter number for m: ";
    cin >> m;

    cout << "Enter number for n: ";
    cin >> n;

    int A[1000][1000];

    // Input for the matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    int non_null_elements[1000];

    for (int i = 0; i < m; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
                count++;
        }

        non_null_elements[i] = count;
    }

    cout << "The array of non null elements: ";
    for (int i = 0; i < m; i++)
    {
        cout << non_null_elements[i] << " ";
    }

    return 0;
}
