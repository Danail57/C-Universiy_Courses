
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    char str1[11];
    char str2[] = "0123456789";
    strncpy(str1, str2 + 5,5);
    str1[5] = '\0';
    cout << str1 << endl;
}

// 56789
