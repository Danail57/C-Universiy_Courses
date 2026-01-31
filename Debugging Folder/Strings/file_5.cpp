
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    char str1[11];
    char str2[] = "0123456789";
    strncpy(str1, str2 + 4,5);
    cout << str1 << endl;
}

// 45678
