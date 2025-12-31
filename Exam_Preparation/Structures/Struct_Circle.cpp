#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const float pi_number = 3.14;

struct Circle {
	double radius;
	string color;
};

double area_circle(double radius)
{
	double S;
	S = pi_number * (radius * radius);
	return S;
}

double perimeter_circle(double radius)
{
	double P;
	P = 2 * (pi_number * radius);
	return P;
}

int main()
{
	int n;
	cout << "Enter a number for circles: ";
	cin >> n;

	Circle circles[1000];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter radius for the circle " << i + 1 << ": ";
		cin >> circles[i].radius;

		cin.ignore();
		cout << "Enter color " << i + 1 << ": ";
		getline(cin, circles[i].color);
	}

	for (int i = 0; i < n; i++)
	{
		double area = area_circle(circles[i].radius);
		double perimeter = perimeter_circle(circles[i].radius);
		cout << "Circle " << i + 1 << ": area = " << area << ", perimeter = " << perimeter << ", color = " << circles[i].color << endl;
	}
	return 0;
}
