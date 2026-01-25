/*Да се намери номерът на първия елемент
от масива a[n] равен на
дадена стойност b.*/

#include <iostream> 
using namespace std;

int main()
{
	int a;
	cout << "How many elements you want? ";
	cin >> a;

	//int b;
	//cout << "Enter the searched number: ";
	//cin >> b;
	
	int u[1000];
	for (int i = 0; i < a; i++)
	{
		cout << "u[" << i + 1 << "] = ";
		cin >> u[i];
	}

	int b;
	cout << "Enter the searched number: ";
	cin >> b;

	int index = -1;
	for (int i = 0; i < a; i++)
	{
		if (u[i] == b)
		{
			index = i + 1;
			break;
		}
	}
	if (index == -1)
		cout << "Searched element not found." << endl;
	else
		cout << "Searched element found at position " << index << endl;
	return 0;
}
