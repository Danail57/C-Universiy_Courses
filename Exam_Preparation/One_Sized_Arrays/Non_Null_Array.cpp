/*Да се образува масив p от едномерния
масив w чрез отстраняване на всички 
нулеви елементи в дадения масив.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;

	int w[100];
	cout << "Enter the numbers: ";
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}

	int p[100];
	int count_elements_in_p = 0;
	for (int i = 0; i < n; i++)
	{
		if (w[i] != 0)
		{
			p[count_elements_in_p] = w[i];
			count_elements_in_p++;
		}
	}
	cout << "Array without zeros: ";
	for (int i = 0; i < count_elements_in_p; i++)
	{
		cout << p[i] << " ";
	}
	return 0;
}
