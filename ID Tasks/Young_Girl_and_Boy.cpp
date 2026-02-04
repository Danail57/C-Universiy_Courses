

/*73) Зададен е двумерният масив от ЕГН-та на група лица А с m реда и n
стълба. Да се състави програма, която намира най-младото момче и момиче
в целия двумерен масив
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int m;
    cout << "Enter the number of rows: ";
    cin >> m;

    int n;
    cout << "Enter the number of columns: ";
    cin >> n;
    string A[45][45];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A["<< i + 1 <<"]["<< j + 1 <<"] = ";
            cin >> A[i][j];
        }
    }
    int youngest_boy_year = -1;
    int youngest_girl_year = -1;
    string youngest_boy_EGN = "";
    string youngest_girl_EGN = "";
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            string egn = A[i][j];
            int year = stoi(egn.substr(0, 2));
            int month = stoi(egn.substr(2, 2));
            int gender = (egn[8] - '0') % 2;

            if (month > 40) {
                month -= 40;
                year += 2000;
            } else if (month > 20) {
                month -= 20;
                year += 1800;
            } else {
                year += 1900;
            }
            if (gender == 0) {
                if (youngest_girl_year == -1 || youngest_girl_year < year) {
                    youngest_girl_year = year;
                    youngest_girl_EGN = egn;
                }
            }
            else {
                if (youngest_boy_year == -1 || youngest_boy_year < year) {
                    youngest_boy_year = year;
                    youngest_boy_EGN = egn;
                }
            }
        }
    }
    if (youngest_girl_year != -1)
        cout << "Youngest girl year of birth: " << youngest_girl_year << endl;
    else
        cout << "No girls found" << endl;

    if (youngest_boy_year != -1)
        cout << "Youngest boy year of birth: " << youngest_boy_year << endl;
    else
        cout << "No boys found" << endl;
}
