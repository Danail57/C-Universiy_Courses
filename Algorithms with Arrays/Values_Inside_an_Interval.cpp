/*2) Зададена е областта D, като обединение на n 
затворени интервала с граници съответно ai и bi, 
i=0,1, 2, ... , n-1. Зададени са и стойностите xj,
j=0,1, 2, ... , m-1. Да се намерят стойностите, 
лежащи вътре в областта D и техния брой. 
Предполага се, че интервалите не се застъпват.*/

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
		cout << "a[i] = "; cin >> a[i];
		cout << "b[i] = "; cin >> b[i];
	}

	int m;
	cout << "Enter the number of values x: ";
	cin >> m;

	int x[1000];
	for (int j = 0; j < m; j++)
	{
		cout << "x[" << j + 1 << "] = ";
		cin >> x[j];
	}

	int count = 0;
	cout << "Values inside D: ";
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] <= x[j] && x[j] <= b[i])
			{
				cout << x[j] << " ";
				count++;
				break;
			}
		}
	}
	cout << endl;
	cout << "Count = " << count << endl;
	return 0;
}
