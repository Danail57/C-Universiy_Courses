#include <iostream>
using namespace std;

struct Circle {
	double x;
	double y;
	double radius;
};


int points_in_circle(double cx, double cy, double radius, double pointsX[], double pointsY[], int m)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		double dx = pointsX[i] - cx;
		double dy = pointsY[i] - cy;
		if (dx * dx + dy * dy <= radius * radius)
		{
			count++;
		}
	}
	return count;
}


int main()
{
	Circle circles[1000];
	int n;
	cout << "Enter a number of circles: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the X coordinate: ";
		cin >> circles[i].x;
		
		cout << "Enter the Y coordinate: ";
		cin >> circles[i].y;

		cout << "Enter the radius: " << i + 1 << ": ";
		cin >> circles[i].radius;
	}


	double pointsX[20], pointsY[20];
	int m;
	
	do {
		cout << "Enter number of points (<= 20): ";
		cin >> m;
	} while (m > 20 || m < 1);


	for (int i = 0; i < m; i++)
	{
		cout << "Enter point " << i + 1 << " X and Y: ";
		cin >> pointsX[i] >> pointsY[i];
	}

	int max_points = 0;
	int max_index = 0;
	for (int i = 0; i < n; i++)
	{
		int count = points_in_circle(circles[i].x, circles[i].y, circles[i].radius, pointsX, pointsY, m);
		if (count > max_points)
		{
			max_points = count;
			max_index = i;
		}
	}
	cout << "Circle with most points in number " << max_index + 1 << " with " << max_points << " points." << endl;
	return 0;
}
