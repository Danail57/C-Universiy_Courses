
#include <iostream>
using namespace std;
int main()
{
    int i, j, s[2];
    int A[2][7] = {
        {3, 5, -4, 2, 0, -3, 3},
        {1, 4, -1, 2, 0, -7, 3}
    };
    for (i = 0; i < 2; i++)
    {
        s[i] = 0;
        for (j = 0; j < 7; j++) {
            if (A[i][j] <= 0) continue;
            s[i] += A[i][j];
        }
    }
    for (i = 0; i < 2; i++)
        cout << s[i] << " ";
    cout << endl;
}
