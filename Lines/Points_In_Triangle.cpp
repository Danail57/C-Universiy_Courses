/*30) Дадено е множество от n точки, лежащи
в една равнина. Да се намери тройката от тях,
образуващи триъгълник, който съдържаща 
най-много точки.*/

#include <iostream> 
#include <cmath>
using namespace std;

struct Point {
	int x, y;
};


double area(Point a, Point b, Point c)
{
	return fabs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0;
}

double is_inside_in_triangle(Point a, Point b, Point c, Point p)
{
	double A = area(a, b, c);
	double A1 = area(p, b, c);
	double A2 = area(a, p, c);
	double A3 = area(a, b, p);
	return fabs(A - (A1 + A2 + A3)) < 1e-9;
}

int main()
{
	int n;
	cout << "Enter the number of points: ";
	cin >> n;

	Point points[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Point[" << i + 1 << "] (x y) = ";
		cin >> points[i].x >> points[i].y;
	}
	int max_count = -1;
	int best_i = -1, best_j = -1, best_k = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int count = 0;
				for (int t = 0; t < n; t++)
				{
					if (t == i || t == j || t == k) continue;
					if (is_inside_in_triangle(points[i], points[j], points[k], points[t]))
						count++;
				}
				if (count > max_count)
				{
					max_count = count;
					best_i = i;
					best_j = j;
					best_k = k;
				}
			}
		}
	}
	cout << "Triangle with most points inside:\n";
	cout << "Point 1: (" << points[best_i].x << "," << points[best_i].y << ")\n";
	cout << "Point 2: (" << points[best_j].x << "," << points[best_j].y << ")\n";
	cout << "Point 3: (" << points[best_k].x << "," << points[best_k].y << ")\n";
	cout << "Number of points inside: " << max_count << endl;
}


