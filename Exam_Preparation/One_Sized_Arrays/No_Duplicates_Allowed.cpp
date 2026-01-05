/*Да се образува нов масив p[k] от масива w[n]. 
Новият масив не трябва да съдържа
съседни повтарящи се елементи.
.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;

	int w[100];
	cout << "Enter the elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}

	int p[100];
	int k = 0;

	if (n > 0)
	{
		p[k++] = w[0];
	}

	for (int i = 1; i < n; i++)
	{
		if (w[i] != w[i - 1])
		{
			p[k++] = w[i];
		}
	}
	cout << "New array without consecutive duplicates: ";
	for (int i = 0; i < k; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	return 0;
}
