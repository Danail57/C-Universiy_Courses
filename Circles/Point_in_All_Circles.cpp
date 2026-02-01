
/*19) Зададени са k окръжности
 *(абсциса и ордината на центъра и радиус)
 *и m точки (абсциса и ордината).
 *Да се определи дали има точка,
 *която лежи във всички окръжности
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int k, m;
    double x[1000], y[1000];
    double xc[1000], yc[1000], r[1000];

    cout << "Enter the number of circles: ";
    cin >> k;
    for (int i = 0; i < k; i++) {
        cout << "Circle " << i + 1 << " (xc yc r): ";
        cin >> xc[i] >> yc[i] >> r[i];
    }

    cout << "Enter the number of points: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Point " << i + 1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
    bool found = false;
    for (int i = 0; i < m; i++) {
        bool inside_all = true;
        for (int j = 0; j < k; j++) {
            double dx = x[i] - xc[j];
            double dy = y[i] - yc[j];
            double dist = dx * dx + dy * dy;
            if (dist > r[j] * r[i]) {
                inside_all = false;
                break;
            }
        }
        if (inside_all) {
            cout << "Point " << i + 1 << " (" << x[i] << ", " << y[i] << ") lies in all circles.\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No point lies in all circles.\n";
    }
}
