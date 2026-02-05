

/*24) Write a C++ program to count the number
 *of duplicate characters in a given string.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Write a string: ";
    getline (cin, s);

    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        bool already_found = false;

        for (int k = 0; k < i; k++) {
            if (s[i] == s[k]) {
                already_found = true;
                break;
            }
        }
        if (already_found)
            continue;
        int occurrences = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[i] == s[j]) {
                occurrences++;
            }
        }
        if (occurrences > 1) {
            count++;
            cout << s[i] << " -> " << occurrences << endl;
        }
    }
    cout << "Number of duplicate chars: " << count << endl;
}
