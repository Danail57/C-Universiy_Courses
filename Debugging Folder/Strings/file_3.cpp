
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    const char *s1 = "Gabrovo";
    char s2[20];
    char *d = "Tarnovo";
    if (strcmp(s1, d) > 0)
        strcpy(s2, s1);
    else if (strcmp(s1, d) < 0)
        strcpy(s2, d);
    strcat(s2, s1);
    cout << s2 << endl;
}

// TarnovoGabrovo
