
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    const char s1[] = "Silistra";
    char s2[9];
    char d[] = "Rousse";
    strcpy(s2, d);
    cout << strlen(s2) << " and " << strlen(s1) << endl;
}

// 6 and 8
