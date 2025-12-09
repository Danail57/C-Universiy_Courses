/*.Зададен е едномерният масив от ЕГН-та 
E0, E1,..., En-1  Да се състави програма, която 
създава нов масив а0, а1,...,аn-1, като 
стойността на аi  е 0, ако Ei  е ЕГН на мъж,
или 1, ако Ei  е ЕГН на жена.  */


#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter number of IDs: ";
    cin >> n;

    char ID[100][11]; 
    int gender[100];  

    for (int i = 0; i < n; i++) 
    {
        cout << "Enter ID[" << i + 1 << "]: ";
        cin >> ID[i];
    }

    // Определяне на пола
    for (int i = 0; i < n; i++) 
    {
        char last4[5];
        for (int j = 0; j < 4; j++)
        {
            last4[j] = ID[i][6 + j]; 
        }
        last4[4] = '\0';

        int check_digit = last4[1] - '0'; 
        if (check_digit % 2 == 0)
            gender[i] = 1; 
        else
            gender[i] = 0; 
    }

    for (int i = 0; i < n; i++) 
    {
        cout << "ID[" << i + 1 << "] is " 
             << (gender[i] == 0 ? "male" : "female") << endl;
    }

    return 0;
}

