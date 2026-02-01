
/*23) Зададени са k окръжности
 *(абсциса и ордината на центъра и радиус)
 *и m прави в равнината (абсциса и ордината на две точки).
 *Да се намерят всички двойки окръжност - \
 *непресичаща я права.
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int m, k;
    double x1[1000], y1[1000], x2[1000], y2[1000];
    double xc[1000], yc[1000], r[1000];

    cout << "Enter the number of circles: ";
    cin >> k;
    for (int i = 0; i < k; i++) {
        cout << "Circle " << i + 1 << " (xc yc r): ";
        cin >> xc[i] >> yc[i] >> r[i];
    }

    cout << "Enter the number for lines: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Line " << i + 1 << " (x1 y1 x2 y2): ";
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    cout << "Circle-line pairs that do NOT intersect:\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            double A = y2[j] - y1[j];
            double B = x1[j] - x2[i];
            double C = x2[j] * y1[j] - x1[j] * y2[j];
            double dist = fabs(A * xc[i] + B * yc[i] + C) / sqrt(A * A + B * B);
            if (dist > r[i]) {
                cout << "Circle " << i+1 << " does not intersect Line " << j+1 << endl;
            }
        }
    }
}
