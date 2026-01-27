/*1) Зададена е областта D, като обединение на
n затворени интервала с граници съответно ai и bi,
i=0,1, 2,..., n-1 и стойността x. Да се намери 
номера на интервала, в който лежи x.*/

#include <iostream> 
using namespace std;

int main()
{
	int n;
	cout << "Enter the count of intervals [a:b]: ";
	cin >> n;

	int a[1000], b[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Interval[" << i + 1 << "] = ";
		cin >> a[i] >> b[i];
	}

	int x;
	cout << "Type x = ";
	cin >> x;
	bool found = false;

	for (int i = 0; i < n; i++)
	{
		if (a[i] <= x && x <= b[i])
		{
			cout << "x belongs to interval number: " << i + 1 << endl;
			found = true;
			break;
		}
	}
	if (!found)
		cout << "x does not belong to any interval" << endl;
	return 0;
}
