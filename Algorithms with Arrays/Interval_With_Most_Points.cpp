/*Зададена областта D, като обединение на n 
затворени интервала с граници съответно ai и bi,
i=0,1, 2, ... , n-1. Зададени са и стойностите
xj, j=0,1, 2, ... , m-1. Да се намери номера на
интервала, съдържащ най-много от 
зададените точки.*/

#include <iostream> 
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of intervals: ";
	cin >> n;

	int a[1000], b[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Interval[" << i + 1 << "] = ";
		cout << "a[i] = " << endl;
		cin >> a[i];
		cout << "b[i] = " << endl;
		cin >> b[i];
	}

	int m;
	cout << "Enter the count values = x: ";
	cin >> m;
	int x[1000];

	for (int j = 0; j < m; j++)
	{
		cout << "x[" << j + 1 << "] = ";
		cin >> x[j];
	}

	int count_points_in_interval[1000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] <= x[j] && x[j] <= b[i])
			{
				count_points_in_interval[i]++;
			}
		}
	}
	int max_count_points = count_points_in_interval[0];
	int max_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (count_points_in_interval[i] > max_count_points)
		{
			max_count_points = count_points_in_interval[i];
			max_index = i;
		}
	}
	cout << "Interval with most points: " << max_index + 1 << endl;
	cout << "Number of points in it: " << max_count_points << endl;
	return 0;
}
