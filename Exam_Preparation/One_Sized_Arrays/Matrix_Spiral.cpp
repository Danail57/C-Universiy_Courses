//спирално запълване на квадратна матрица наобратно

#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int a[10][10];

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right)
    {
        for (int i = bottom; i >= top; i--)
            a[i][left] = num++;
        left++;

        for (int j = left; j <= right; j++)
            a[top][j] = num++;
        top++;

        for (int i = top; i <= bottom; i++)
            a[i][right] = num++;
        right--;

        for (int j = right; j >= left; j--)
            a[bottom][j] = num++;
        bottom--;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
