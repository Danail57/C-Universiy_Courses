/*Едно положително цяло число е съвършено, ако е равно на сумата
от делителите си. Например 6 е съвършено число, защото е сбор
от делителите си, но числото 1 не е съвършено. Да се напише програма, 
намираща всички съвършени числа ненадминаващи дадено положително цяло число n*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	
	do 
	{
		cout << "Enter a number: ";
		cin >> n;
	} while (n <= 0);

	for (int k = 2; k <= n; k++)
	{
		int s = 1;
		
		cout << "Divisors of " << k << ": 1 ";
		for (int i = 2; i <= k / 2; i++)
		{
			if (k % i == 0)
			{
				cout << i << " ";
				s = s + i;
			}
		}
		cout << endl;
		if (s == k)
			cout << k << " is a perfect number.\n";
		
	}
	return 0;
}
