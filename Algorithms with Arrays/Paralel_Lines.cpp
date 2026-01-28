/*27) Дадено е множество от n точки и множество
от m прави, лежащи в една равнина.
Да се намери двойката точки, образуващи права,
която е успоредна на най-много прави.*/

#include <iostream> 
#include <cmath>
using namespace std;

struct Line {
	double A, B, C;
	// Ax + By + C = 0 - права
};

int main()
{
	int n;
	cout << "Enter the count of points: ";
	cin >> n;

	double x[1000], y[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Point[" << i + 1 << "] (x y)= ";
		cin >> x[i] >> y[i];
	}
	
	int m;
	cout << "Enter the count of lines: ";
	cin >> m;

	Line lines[1000];
	for (int i = 0; i < m; i++)
	{
		cout << "Line[" << i + 1 << "](A B C) = ";
		cin >> lines[i].A >> lines[i].B >> lines[i].C;
	}

	int max_count = 0;
	int best_i = -1, best_j = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double slope1;
			if (x[j] - x[i] == 0) slope1 = 1e9;
			else slope1 = (y[j] - y[i]) / (x[j] - x[i]);

			int count = 0;

			for (int k = 0; k < m; k++)
			{
				double slope2;
				if (lines[k].B == 0) slope2 = 1e9; 
				else slope2 = -lines[k].A / lines[k].B;

				if (fabs(slope1 - slope2) < 1e-9)
				{
					count++;
				}
			}
			if (count > max_count)
			{
				max_count = count;
				best_i = i;
				best_j = j;
			}
		}
	}

	cout << "The pair of points forming the line parallel to most lines:" << endl;
	cout << "Point " << best_i + 1 << " (" << x[best_i] << ", " << y[best_i] << ")" << endl;
	cout << "Point " << best_j + 1 << " (" << x[best_j] << ", " << y[best_j] << ")" << endl;
	cout << "Number of lines parallel: " << max_count << endl;
}
