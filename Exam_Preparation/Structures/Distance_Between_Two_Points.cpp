#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	int x;
	int y;
};

float distance_between_two_points(Point p1, Point p2)
{
	float d;
	d = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	return d;
}

int main()
{
	Point p1, p2;
	cout << "Enter x and y for first point: ";
	cin >> p1.x >> p1.y;

	cout << "Enter x and y for second point: ";
	cin >> p2.x >> p2.y;

	float distance = distance_between_two_points(p1, p2);
	cout << "Distance between points: " << distance << endl;
	return 0;
}
