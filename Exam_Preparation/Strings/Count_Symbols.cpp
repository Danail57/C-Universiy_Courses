/* Да се напише програма, която намира колко пъти
се среща всеки от следните символи 
“!’, ‘?’, ‘,’, ‘.’, ‘:’, ‘;’ в даден низ. */

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    map<char, int> count;
    for (char c : text)
    {
        if (c == '!' || c == '?' || c == ',' ||
            c == '.' || c == ':' || c == ';')
        {
            count[c]++;
        }
    }
    cout << "! -> " << count['!'] << endl;
    cout << "? -> " << count['?'] << endl;
    cout << ", -> " << count[','] << endl;
    cout << ". -> " << count['.'] << endl;
    cout << ": -> " << count[':'] << endl;
    cout << "; -> " << count[';'] << endl;
    return 0;
}
