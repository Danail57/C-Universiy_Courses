/*Да се образува масив p от едномерния 
масив w чрез отстраняване на
всички нулеви елементи в дадения масив.*/

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
	for (int i = 0; i < n; i++)
	{
		if (w[i] != 0)
		{
			p[k] = w[i];
			k++;
		}
	}
	cout << "New array without zeros:\n";
	for (int i = 0; i < k; i++)
	{
		cout << p[i] << " ";
	}
	return 0;
}
