
#include <iostream>
using namespace std;
int main()
{
    int x = 20, *p = &x;
    *p += *p + 3;
    cout << "x = " << x << endl;
}
