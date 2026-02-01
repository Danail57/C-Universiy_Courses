
/*11) 13) Зададени са k окръжности
 *(абсциса и ордината на центъра и радиус).
 *Да се намерят всички двойки окръжности,
 *които се пресичат.*/

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
    for (int i = 0; i < k; i++)
    {
        cout << "Circle " << i + 1 << " (xc yc r): ";
        cin >> xc[i] >> yc[i] >> r[i];
    }

    cout << "Enter the number of points: ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "Point " << i + 1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
    cout << "Intersecting circles:\n";
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < m; j++) {
            double dx = xc[i] - xc[j];
            double dy = yc[i] - yc[j];
            double dist = sqrt(dx * dx + dy * dy);

            if (dist <= r[i] + r[j] && dist >= fabs(r[i] - r[j])) {
                cout << "Circle " << i + 1 << " intersects with circle " << j + 1 << endl;
            }
        }
    }
    return 0;
}
