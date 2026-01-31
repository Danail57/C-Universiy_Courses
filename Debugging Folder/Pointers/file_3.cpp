
#include <iostream>
using namespace std;
int main()
{
    float x = 4.5;
    float *p = &x;
    float *q = p;
    *q += *p * 2;
    cout << x << endl;
}
