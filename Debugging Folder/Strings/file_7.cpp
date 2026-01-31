
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    char k, s[9];
    int i, j;
    strcpy(s,"abcdefgh");
    j = strlen(s);
    for (i = 0; i < j / 3; i++) {
        k = s[i];
        s[i] = s[j - 1 - i];
        s[j - 1- i] = k;
    }
    cout << s << endl;
}

//hgcdefba
