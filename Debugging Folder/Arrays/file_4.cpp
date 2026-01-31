
#include <iostream>
using namespace std;
int main()
{
    int k = 1, s = 0,m,
    B[2][3] = {
        {1, 8, 0},
        {4, 1, 2}
    };
    for (m = 0; m < 2; m++)
        s += B[m][k];
    cout << s << endl;
}
