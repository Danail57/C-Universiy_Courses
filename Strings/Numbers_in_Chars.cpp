/*Дадени са две цели неотрицателни числа,
 *представени с масиви от символи, представящи
 *десетичните им цифри. Да се напише програма
 * която установява дали първото от двете числа
  е по-голямо от второто*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

int main()
{
    cout << "Enter the number of digits from 1 to " << MAX_SIZE << endl;
    int n;
    cin >> n;

    char s1[MAX_SIZE];
    int i;
    for (i = 0; i < n; i++) {
        cout << "s1["<< i <<"] = ";
        cin >> s1[i];
    }

    cout << "Enter the second number of digits from 1 to " << MAX_SIZE << endl;
    int m;
    cin >> m;
    char s2[MAX_SIZE];
    for (i = 0; i < m; i++) {
        cout << "s2["<< i <<"] = ";
        cin >> s2[i];
    }
    bool flag;
    if (n > m)
        flag = true;
    else
        if (n < m)
            flag = false;
    else {
        i = n - 1;
        while (s1[i] == s2[i] && i > 0)
            i--;
        if (s1[i] != s2[i])
            flag = s1[i] > s2[i];
        else
            flag = false;
    }
    if (flag)
        cout << "First number is greater than second number." << endl;
    else
        cout << "Second number is greater than second number." << endl;
}
