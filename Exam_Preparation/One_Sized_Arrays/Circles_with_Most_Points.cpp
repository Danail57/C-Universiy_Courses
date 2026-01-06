/*Зададени са k окръжности 
(абсциса и ордината на центъра и радиус)
и m точки в равнината (абсциса и ордината).
Да се намери коя окръжност съдържа най-много точки. */

#include <iostream>
#include <cmath>
using namespace std;

int count_points_in_circle(double cx, double cy, double r, double px[], double py[], int m)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		double distance = (px[i] - cx) * (px[i] - cx) + (py[i] - cy) * (py[i] - cy);
		if (distance <= r * r)
		{
			count++;
		}
	}
	return count;
}

// double cx, double cy - coordinates of x and y
// double r - radius
// double px[] - array of the coordinates of x
// double py[] - array of the coordinates of y
// int m - counter of the points

int main()
{
	int k;
	cout << "Enter how many circles you want to write: ";
	cin >> k;

	double cx[100];
	double cy[100];
	double r[100];

	for (int i = 0; i < k; i++)
	{
		cout << "Circle " << i + 1 << " (x y r): ";
		cin >> cx[i] >> cy[i] >> r[i];
	}
	
	int m;
	cout << "Enter the number of points: ";
	cin >> m;
	double px[100];
	double py[100];
	for (int i = 0; i < m; i++)
	{
		cout << "Point " << i + 1 << " (x y): ";
		cin >> px[i] >> py[i];
	}

	int max_points = 0;
	int best_circle = 0;
	for (int i = 0; i < k; i++)
	{
		int points = count_points_in_circle(cx[i], cy[i], r[i], px, py, m);
		if (points > max_points)
		{
			max_points = points;
			best_circle = i;
		}
	}
	cout << "Circle with the most points: #" << best_circle + 1 << endl;
	cout << "Points inside: " << max_points << endl;
	return 0;
}
