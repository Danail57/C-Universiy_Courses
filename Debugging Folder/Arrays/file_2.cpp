
#include <iostream>
using namespace std;
int main()
{
    int A[] = {3, 5, -1, 6, -7, 2}, b = 0, k = 0, m;
    for (m = 0; m < 6; m++)
        if (A[m] >= 0)
            b += A[m];
    else k += A[m];
    if (b > -k)
        cout << b + k << endl;
    else
        cout << b << endl;
}
