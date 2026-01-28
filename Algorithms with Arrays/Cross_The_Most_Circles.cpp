/*26) Дадено е множество от n точки и 
множество от m окръжности, лежащи в една 
равнина. Да се намери двойката точки,
образуващи права, която пресича най-много
окръжности.*/

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of points: ";
	cin >> n;

	int x[1000], y[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Point[" << i + 1 << "] (x y) = ";
		cout << "x = " << endl;
		cout << "y = " << endl;
		cin >> x[i] >> y[i];
	}
	int m;
	cout << "Enter the number of circles: ";
	cin >> m;

	double xc[1000], yc[1000], radius[1000];
	for (int i = 0; i < m; i++)
	{
		cout << "Circle[" << i + 1 << "](xc yc radius)= ";
		cin >> xc[i];
		cout << "yc = ";
		cin >> yc[i];
		cout << "radius = ";
		cin >> radius[i];
	}

	int max_count_crossing = 0;
	int best_i = -1, best_j = -1; // point indices

	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double A = y[j] - y[i];
			double B = -(x[j] = x[i]);
			double C = x[j] * y[i] - x[i] * y[j];
			int count = 0;

			for (int k = 0; k < m; k++)
			{
				double distance = abs(A * xc[k] + B * yc[k] + C) / sqrt(A * A + B * B);
				if (distance <= radius[k])
				{
					count++;
				}
			}
			if (count > max_count_crossing)
			{
				max_count_crossing = count;
				best_i = i;
				best_j = j;
			}
		}
	}
	cout << "The pair of points forming the line that crosses the most circles:" << endl;
	cout << "Point " << best_i + 1 << " (" << x[best_i] << ", " << y[best_i] << ")" << endl;
	cout << "Point " << best_j + 1 << " (" << x[best_j] << ", " << y[best_j] << ")" << endl;
	cout << "Number of circles crossed: " << max_count_crossing << endl;
	return 0;
}
