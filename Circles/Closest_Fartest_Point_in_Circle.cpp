
/*11) Най-далечна точка вътре в
 *окръжността и най близка*/

#include <iostream>
using namespace std;

int farthest_inside(double xc, double yc, double r, double x[], double y[], int m)
{
    double max_dist = -1;
    int index = -1;
    for (int i = 0; i < m; i++) {
        double dx = x[i] - xc;
        double dy = y[i] - yc;
        double dist = dx * dx + dy * dy;

        if (dist <= r * r && dist > max_dist) {
            max_dist = dist;
            index = i;
        }
    }
    return index;
}

int closest_point(double xc, double yc, double x[], double y[], int m)
{
    double min_dist = 1e18;
    int index = 0;
    for (int i = 0; i < m; i++) {
        double dx = x[i] - xc;
        double dy = y[i] - yc;
        double dist = dx * dx + dy * dy;
        if (dist < min_dist) {
            min_dist = dist;
            index = i;
        }
    }
    return index;
}

int main()
{
    int k, m;
    double xc[1000], yc[1000], r[1000];
    double x[1000], y[1000];

    cout << "Enter number of circles: ";
    cin >> k;
    for (int i = 0; i < k; i++) {
        cout << "Circle " << i + 1 << " (xc yc r): ";
        cin >> xc[i] >> yc[i] >> r[i];
    }

    cout << "Enter number of points: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Point " << i + 1 << " (x y): ";
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < k; i++) {
        int far = farthest_inside(xc[i], yc[i], r[i], x, y, m);
        int closest = closest_point(xc[i], yc[i], x, y, m);
        cout << "Circle " << i + 1 << endl;
        if (far != -1)
            cout << "Farthest inside: Point " << far + 1 << " (" << x[far] << ", " << y[far] << ")\n";
        else
            cout << "No points inside the circle\n";
        cout << "  Closest point: Point " << closest + 1 << " (" << x[closest] << ", " << y[closest] << ")\n";
    }
}
