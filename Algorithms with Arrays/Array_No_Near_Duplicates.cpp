/*Да се образува нов масив p[k] от масива w[n]. 
Новият масив не трябва да съдържа съседни 
повтарящи се елементи*/

#include <iostream> 
using namespace std;

int main()
{
	int n;
	cout << "How many numbers you want? ";
	cin >> n;

	int w[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "w[" << i + 1 << "] = ";
		cin >> w[i];
	}
	int p[1000];
	int k = 0;

	p[k] = w[0];
	k++;

	for (int i = 1; i < n; i++)
	{
		if (w[i] != w[i - 1])
		{
			p[k] = w[i];
			k++;
		}
	}
	cout << "New array without near duplicates:\n";
	for (int i = 0; i < k; i++)
	{
		cout << p[i] << " ";
	}
	return 0;
}
