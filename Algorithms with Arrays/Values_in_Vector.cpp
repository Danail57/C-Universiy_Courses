/*5) Зададена е областта D, като обединение на n 
затворени интервала с граници съответно ai и bi, 
i=0,1, 2, ... , n-1. Зададени са и стойнос-тите xj,
j=0,1, 2, ... , m-1. Да се създаде нов масив y,
съдържащ стойностите от масива x, лежащи
вътре в областта D.*/

#include <iostream> 
#include <vector>
using namespace std;

int main()
{
	int n;
	cout << "What is the number of intervals: ";
	cin >> n;

	// int a[1000], b[1000]
	vector<int> a(n), b(n);
	
	for (int i = 0; i < n; i++)
	{
		cout << "Interval[" << i + 1 << "] = ";
		cout << "a = " << endl;
		cin >> a[i];
		cout << "b[i] = " << endl;
		cin >> b[i];
	}

	int m;
	cout << "Enter the count of values = x: ";
	cin >> m;
	
	//int x[10000];
	vector<int>x(m);

	for (int j = 0; j < m; j++)
	{
		cout << "x[" << j + 1 << "] = ";
		cin >> x[j];
	}
	//int y[10000];
	vector<int>y;
	int k = 0; // elements count in y

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] <= x[j] && x[j] <= b[i])
			{
				//y[k] = x[j];
				//k++;
				y.push_back(x[j]);
				break;
			}
		}
	}
	cout << "Values in D: ";
	//for (int i = 0; i < k; i++)
	for (int value : y)
	{
		cout << y[i] << " ";
	}
	//cout << "\nCount = " << k << endl;
	cout << "\nCount = " << y.size() << endl;
	return 0;
}
