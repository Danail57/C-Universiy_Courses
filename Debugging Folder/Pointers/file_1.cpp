
#include <iostream>
using namespace std;
int main()
{
    float x = 2.5, *p=&x, *q=p;
    *q += x + 3;
    // *q = *q + (x + 3);
    cout << *q << endl;
}
