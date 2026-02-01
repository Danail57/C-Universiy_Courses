
/*19) Зададени са k окръжности
 *(абсциса и ордината на центъра и радиус)
 *и m точки (абсциса и ордината).
 *Да намери в колко окръжности лежи всяка точка
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

    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < k; j++) {
            double dx = x[i] - xc[j];
            double dy = y[i] - yc[j];
            double dist = dx * dx + dy * dy;
            if (dist <= r[j] * r[j]) {
                count++;
            }
        }
        cout << "Point " << i + 1
             << " (" << x[i] << ", " << y[i] << ") "
             << "lies in " << count << " circle";
        if (count != 1) cout << "s";
        cout << endl;
    }
}
