/*Да се намери броят на нулевите елементи в 
масива u с m елементи.*/

#include <iostream> 
using namespace std;

int main()
{
	int m;
	cout << "How many elements you want? ";
	cin >> m;

	int u[1000];
	for (int i = 0; i < m; i++)
	{
		cout << "u[" << i + 1 << "] = ";
		cin >> u[i];
	}

	int count_null_el = 0;
	for (int i = 0; i < m; i++)
	{
		if (u[i] == 0)
		{
			count_null_el++;
		}
	}
	if (count_null_el)
		cout << "Null elements, count = " << count_null_el << endl;
	else
		cout << "No null elements, count = " << count_null_el << endl;
	return 0;
}
