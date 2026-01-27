/*9) Зададени са k окръжности 
(абсциса и ордината на центъра и радиус) и
m точки в равнината (абсциса и ордината).
Да се намери коя окръжност съдържа 
най-много точки.*/

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int k;
	cout << "Enter the number of circles: ";
	cin >> k;
	int a[1000];
	double xc[1000], yc[1000], r[1000];

	for (int i = 0; i < k; i++)
	{
		cout << "Circle[" << i + 1 << "] (xc yc r): ";
		cin >> xc[i] >> yc[i] >> r[i];
	}

	int m;
	cout << "Enter the count of points: ";
	cin >> m;
	double x[1000], y[1000];

	for (int j = 0; j < m; j++)
	{
		cout << "Point[" << j + 1 << "] (x y): ";
		cin >> x[j] >> y[j];
	}
	int max_count_points = 0;
	int circle_index = -1;

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
		if (count > max_count_points)
		{
			max_count_points = count;
			circle_index = i;
		}
	}
	if (circle_index != -1)
	{
		cout << "Circle with most points is number: " << circle_index + 1 << endl;
		cout << "It contains " << max_count_points << " points." << endl;
	}
	else
	{
		cout << "No points inside any circle." << endl;
	}
}
