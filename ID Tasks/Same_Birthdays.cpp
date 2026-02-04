

/*13) Зададен е едномерният масив от ЕГН-та E0, E1,..., En-1 Да се състави
програма, която определя дали има лица с рожденни дни в един и
същи ден.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    string EGN[200];
    for (int i = 0; i < n; i++) {
        cout << "Person["<< i + 1 <<"] = ";
        cin >> EGN[i];
    }
    bool duplicate = false;
    for (int i = 0; i < n; i++) {
        string day_month_i = EGN[i].substr(2, 4);
        for (int j = i + 1; j < n; j++) {
            string day_month_j = EGN[j].substr(2, 4);
            if (day_month_i == day_month_j) {
                duplicate = true;
                cout << "Persons " << i + 1 << " and " << j + 1 << " have the same birthdays" << endl;
            }
        }
    }
    if (!duplicate) {
        cout << "No persons with the same birthdays" << endl;
    }
    return 0;
}
