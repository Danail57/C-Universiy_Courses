/*24) Дадено е множество от n точки, лежащи 
в една равнина. Да се намери двойката точки,
образуващи права, която разделя дадените точки
на две групи с най-малка разлика в броя им.*/

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of points: ";
	cin >> n;

	double x[1000], y[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Point[" << i + 1 << "] = ";
		cin >> x[i] >> y[i];
	}

	int best_i = -1, best_j = -1;
	int min_diff = n;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int left = 0, right = 0;
			for (int k = 0; k < n; k++)
			{
				if (k == i || k == j) continue;
				double value = (y[j] - y[i]) * (x[k] - x[i]) - (x[j] - x[i]) * (y[k] - y[i]);
				if (value > 0)
					left++;
				else if (value < 0)
					right++;
			}
			int diff = abs(left - right);
			if (diff < min_diff)
			{
				min_diff = diff;
				best_i = i;
				best_j = j;
			}
		}
	}
	cout << "Best line: points " << best_i + 1 << " and " << best_j + 1 << endl;
	cout << "Minimum difference = " << min_diff << endl;
	return 0;
}
