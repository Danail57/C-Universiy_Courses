
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    char str1[11];
    char str2[] = "1234567890";
    strncpy (str1, str2, 5); // copying the first 5 symbols
    str1[5] = '\0';
    cout << str1 << endl;;
}

/12345
