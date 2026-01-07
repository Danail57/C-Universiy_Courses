/*Масивът a0, a1,..., am-1 е нареден
във възходящ ред, т.е. за всяко i<m ai+1ai
. Да се определи номера на първия срещнат елемент,
който е по-голям или равен на дадена стойност b.
 */

#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "Enter how many elements you want to write: ";
	cin >> a;

	int A[100];
	for (int i = 0; i < a; i++)
	{
		cout << "Enter element: ";
		cin >> A[i];
	}

	int b;
	cout << "Enbter a number to search for: ";
	cin >> b;

	int index = -1;

	for (int i = 0; i < a; i++)
	{
		if (A[i] >= b)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	
		cout << "First element greater than or equal to " << b << " is at index:" << index << endl;
	else
		cout << "No element is greater than or equal to " << b << endl;
	return 0;
}
