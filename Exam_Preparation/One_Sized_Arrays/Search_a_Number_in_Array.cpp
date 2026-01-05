/*Да се намери номера на първия елемент
от масива a[n] равен на дадена стойност b. */

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;

	int a[100];
	cout << "Enter the elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int b;
	cout << "Enter the value to find: ";
	cin >> b;

	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
		cout << "First element equal to " << b << " is at position " << index + 1 << endl;
	else
		cout << "Value not found in the array." << endl;
	return 0;
}
