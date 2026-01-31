
/*9) Зададени са k окръжности (абсциса и ордината
 *на центъра и радиус) и m точки в равнината
 *(абсциса и ордината). Да се намери коя окръжност
 *съдържа най-много точки*/

#include <iostream>
using namespace std;
int main()
{

    int k, m;
    double xc[100], yc[100], r[100];
    double x[100], y[100];

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
    int max_points = 0;
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
        if (count > max_points)
        {
            max_points = count;
            circle_index = i;
        }
    }
    cout << "Circle " << circle_index + 1
         << " contains the most points: "
         << max_points << endl;
}
