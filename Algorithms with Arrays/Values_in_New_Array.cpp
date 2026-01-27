/*4) Зададена е областта D с граници a и b. 
Зададени са и стойностите xj, j=1, 2,..., n.
Да се създаде нов масив y, съдържащ стойностите
от масива x, лежащи вътре в областта D.*/

#include <iostream> 
using namespace std;

int main()
{
	int n;
	cout << "What is the number of intervals: ";
	cin >> n;

	int a[10000], b[10000];
	for (int i = 0; i < n; i++)
	{
		cout << "Interval[" << i + 1 << "] = ";
		cout << "a[i] = " << endl;
		cin >> a[i];
		cout << "b[i] = " << endl;
		cin >> b[i];
	}
	int m;
	cout << "Enter the count of values = x: ";
	cin >> m;
	
	int x[10000];
	for (int j = 0; j < m; j++)
	{
		cout << "x[" << j + 1 << "] = ";
		cin >> x[j];
	}
	int y[10000];
	int k = 0; // elements count in y

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] <= x[j] && x[j] <= b[i])
			{
				y[k] = x[j];
				k++;
				break;
			}
		}
	}
	cout << "Values in D: ";
	for (int i = 0; i < k; i++)
	{
		cout << y[i] << " ";
	}
	cout << "\nCount = " << k << endl;
	return 0;
}
