/*Напишете програма, която намира дължината
на най-късата повтаряща се последователност 
в масив.*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

int main()
{
	int n;
	cout << "Enter the size of the array from 1 to " << MAX_SIZE << endl;

	do {
		cin >> n;
	} while (n < 1 || n > 20);

	int a[MAX_SIZE];

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
	
	int period = n;
	for (int t = 1; t <= n; t++)
	{
		bool is_good = true;
		for (int i = t; i < n; i++)
		{
			if (a[i] != a[i - t])
			{
				is_good = false;
				break;
			}
		}
		if (is_good)
		{
			period = t;
			break;
		}
	}
	cout << "The shortest repeating sequence length is: " << period << endl;
	return 0;
}
