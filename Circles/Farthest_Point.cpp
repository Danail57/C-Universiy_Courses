
/*11) Зададени са k окръжности
 *(абсциса и ордината на центъра и радиус)
 *и m точки в равнината (абсциса и ордината).
 *Да се намери най-отдалечена точка от
 *центъра на всяка окръжност.*/

// Най-отдалечената точка е тази, за която
// разстоянието до центъра е най-голямо.

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

    for (int i = 0; i < k; i++) {
        double max_dist = -1;
        int index = 0;

        for (int j = 0; j < m; j++) {
            double dx = x[j] - xc[i];
            double dy = y[j] - yc[i];
            double dist = dx * dx + dy * dy;
            if (dist > max_dist) {
                max_dist = dist;
                index = j;
            }
        }
        cout << "For circle " << i + 1 << " the farthest point is: " << index + 1 << " (" << x[index] << ", " << y[index] << ")" << endl;
    }
    return 0;
}
