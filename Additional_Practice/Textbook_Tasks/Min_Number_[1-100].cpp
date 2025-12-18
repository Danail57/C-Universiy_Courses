/*Напишете програма, която въвежда редица от 
n цели числа (1 <= n <= 100) и намира и извежда 
минималното от тях*/


#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

int main()
{
	int n;
	do {
		cout << "Enter a number from 1 to " << MAX_SIZE << ": ";
		cin >> n;
	} while (n < 1 || n > MAX_SIZE);

	int a[MAX_SIZE];
	
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
	
	int min = a[0];
	for (i = 1; i < n; i++)
		if (a[i] < min)
			min = a[i];
	cout << "min {a[0], ..., a[" << n - 1 << "]} = " << min << endl;
	return 0;
}
