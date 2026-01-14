/*Напишете програма,, която проверява дали даден едномерен масив
от цели числа съществува период. Примерно ако масивът е с 
елементи 1, 2, 3, 1, 2, 3, 1, 2, 3, периодът е 3.*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

int main()
{
	cout << "Enter n - from 1 to " << MAX_SIZE << ": ";
	int n;
	cin >> n;
	int a[MAX_SIZE];
	int i;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1<< "] = ";
		cin >> a[i];
	}
	int t = 0;
	int matched = 0;

	while (t <= n / 2 && matched < n)
	{
		t++;
		matched = t;
		while (matched < n && a[matched - t] == a[matched])
			matched++;
	}
	if (t <= n / 2)
		cout << "The period is: " << t << endl;
	else
		cout << "No period in the array" << endl;
	return 0;
}
