// Зададени са к окръжности - Ох, Оу и радиус и m (m <= 20) точки.
// Съставете алгоритм и програма за определяна в коя или кои окръжности 
// лежат най-много точки

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k_circles;
    int m_points;

    // Entering the count of the circles
    while (true)
    {
        cout << "Enter the number of circles (1-100): ";
        cin >> k_circles;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (k_circles < 1 || k_circles > 100)
        {
            cout << "Number out of range! Enter a number between 1 and 100.\n";
            continue;
        }

        break; // валидно число
    }

    double x_center[100], y_center[100], radius[100];

    // Entering the data for the circles
    for (int i = 0; i < k_circles; i++)
    {
        while (true)
        {
            cout << "Enter center X of circle " << i + 1 << ": ";
            cin >> x_center[i];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input!\n";
                continue;
            }

            cout << "Enter center Y of circle " << i + 1 << ": ";
            cin >> y_center[i];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input!\n";
                continue;
            }

            cout << "Enter the radius of circle " << i + 1 << ": ";
            cin >> radius[i];
            if (cin.fail() || radius[i] <= 0)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid radius! Must be greater than 0.\n";
                continue;
            }

            break; 
        }
    }

    // Entering the count of the points
    while (true)
    {
        cout << "Enter how many points you want (1-20): ";
        cin >> m_points;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input!\n";
            continue;
        }

        if (m_points < 1 || m_points > 20)
        {
            cout << "Number out of range! Enter 1-20.\n";
            continue;
        }

        break; 
    }

    double x_point[20], y_point[20];

    // Entering the coordinates
    for (int i = 0; i < m_points; i++)
    {
        while (true)
        {
            cout << "Enter X for point " << i + 1 << ": ";
            cin >> x_point[i];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input!\n";
                continue;
            }

            cout << "Enter Y for point " << i + 1 << ": ";
            cin >> y_point[i];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input!\n";
                continue;
            }

            break; 
        }
    }

    int count_points[100] = { 0 };

    // Checking which points are in a circle
    for (int i = 0; i < m_points; i++)
    {
        for (int k = 0; k < k_circles; k++)
        {
            double dx = x_point[i] - x_center[k];
            double dy = y_point[i] - y_center[k];
            double distance = sqrt(dx * dx + dy * dy);

            if (distance <= radius[k])
            {
                count_points[k]++;
            }
        }
    }

    int max_points = 0;

    // Finding the maximum count of points
    for (int k = 0; k < k_circles; k++)
    {
        if (count_points[k] > max_points)
        {
            max_points = count_points[k];
        }
    }

    if (max_points == 0)
    {
        cout << "\nNo points lie inside any circle.\n";
    }
    else
    {
        cout << "\nPoints in each circle:\n";
        for (int k = 0; k < k_circles; k++)
        {
            cout << "Circle " << k + 1 << ": " << count_points[k] << " points\n";
        }

        cout << "\nCircles with max points (" << max_points << "): ";
        for (int k = 0; k < k_circles; k++)
        {
            if (count_points[k] == max_points)
            {
                cout << k + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
