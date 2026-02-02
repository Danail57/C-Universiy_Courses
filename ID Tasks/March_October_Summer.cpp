
/*4)
*/

#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    string egn;
};

void parse_EGN(const string& egn, int &year, int &month, int &day) {
    year = stoi(egn.substr(0, 2));
    month = stoi(egn.substr(2, 2));
    day = stoi(egn.substr(4, 2));

    if (month > 40) {
        month -= 40;
        year += 2000;
    }
    else if (month > 20) {
        month -= 20;
        year += 1800;
    }
    else {
        year += 1900;
    }
}

string get_gender(const string& egn) {
    int gender_digit = egn[8] - '0';
    return (gender_digit % 2 == 0) ? "female" : "male";
}

int main()
{
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    Person people[1000];
    for (int i = 0; i < n; i++) {
        cout << "Name of person " << i + 1 << ": ";
        cin >> people[i].name;

        cout << "ID of the person " << i + 1 << ": ";
        cin >> people[i].egn;
    }
    Person oldest = people[0];
    Person youngest = people[0];

    for (int i = 1; i < n; i++) {
        int y, m, d;
        parse_EGN(people[i].egn, y, m, d);

        int oy, om, od;
        parse_EGN(oldest.egn, oy, om, od);

        int yy, ym, yd;
        parse_EGN(youngest.egn, yy, ym, yd);

        if (y < oy || (y == oy && m < om) || (y == oy && m == om && d < od))
            oldest = people[i];

        if (y > yy || (y == yy && m > ym) || (y == yy && m == ym && d > yd))
            youngest = people[i];
    }
    cout << "Oldest: " << oldest.name <<" (" << get_gender(oldest.egn) << ")\n";
    cout << "Youngest: " << youngest.name <<" (" << get_gender(youngest.egn) << ")\n";

    cout << "\nBorn in March:\n";
    for (int i = 0; i < n; i++) {
        int y, m, d;
        parse_EGN(people[i].egn, y, m, d);
        if (m == 3)
            cout << people[i].name << " (" << get_gender(people[i].egn) << ")\n";

    }
    cout << "\nBorn in October:\n";
    for (int i = 0; i < n; i++) {
        int y, m, d;
        parse_EGN(people[i].egn, y, m, d);
        if (m == 10)
            cout << people[i].name << " (" << get_gender(people[i].egn) << ")\n";
    }

    cout << "\nBorn in summer (June-August):\n";
    for (int i = 0; i < n; i++) {
        int y, m, d;
        parse_EGN(people[i].egn, y, m, d);
        if (m >= 6 && m <= 8)
            cout << people[i].name << " (" << get_gender(people[i].egn) << ")\n";
    }

}
