

/*18) Зададени са два едномерни масива от символни низове А0, А1,...,Аn-1
и E0, E1,..., En-1, където Аi и Ei са съответно името и ЕГН на i-тото
лице. Да се състави програма, която извежда името и датата
нараждане на най-младата жена.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    string name[200], EGN[200];
    for (int i = 0; i < n; i++) {
        cout << "Name[" << i + 1 << "]: ";
        cin >> name[i];
        cout << "EGN[" << i + 1 << "]: ";
        cin >> EGN[i];
    }

    int youngest_index = -1;

    for (int i = 0; i < n; i++) {
        int gender_digit = EGN[i][8] - '0';
        if (gender_digit % 2 == 0) { // жена
            if (youngest_index == -1) {
                youngest_index = i;
            } else {
                string egn1 = EGN[i].substr(0, 6);
                string egn2 = EGN[youngest_index].substr(0, 6);
                if (egn1 > egn2) {
                    youngest_index = i;
                }
            }
        }
    }

    if (youngest_index != -1) {
        string egn = EGN[youngest_index];
        int year = stoi(egn.substr(0, 2));
        int month = stoi(egn.substr(2, 2));
        int day = stoi(egn.substr(4, 2));

        
        if (month > 40) {
            month -= 40;
            year += 2000; 
        } else {
            year += 1900; 
        }

        cout << "Youngest woman: " << name[youngest_index]
             << ", birth date: " << year << "-"
             << (month < 10 ? "0" : "") << month << "-"
             << (day < 10 ? "0" : "") << day << endl;
    } else {
        cout << "No women in the list" << endl;
    }
}
