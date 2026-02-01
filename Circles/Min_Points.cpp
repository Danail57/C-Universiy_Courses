
/*9) Зададени са k окръжности (абсциса и ордината
 *на центъра и радиус) и m точки в равнината
 *(абсциса и ордината). Да се намери коя окръжност
 *съдържа най-малко точки*/

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

    int min_points = m;
    int circle_index = 0;

    for (int i = 0; i < k; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            double dx = x[j] - xc[i];
            double dy = y[j] - yc[i];
            if (dx * dx + dy * dy <= r[i] * r[i])
            {
                count++;
            }
        }
        if (count < min_points)
        {
            min_points = count;
            circle_index = i;
        }
    }
    cout << " Circle " << circle_index + 1 << " contains the least points: " << min_points << endl;
}
