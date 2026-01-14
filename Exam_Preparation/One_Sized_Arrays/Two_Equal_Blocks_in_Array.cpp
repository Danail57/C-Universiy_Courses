/*Напишете програма, която проверява дали даден едномерен 
масив от цели числа се състои от два еднакви последователни блока.*/

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
	
	if (n % 2 != 0)
	{
		cout << "The array does not consist of two equal blocks" << endl;
		return 0;
	}

	bool is_equal = true;
	for (int i = 0; i < n / 2; i++)
	{
		if (a[i] != a[i + n / 2])
		{
			is_equal = false;
			break;
		}
	}

	if (is_equal)
		cout << "The array consists of two equal blocks" << endl;
	else
		cout << "The array does not consist of two equal blocks" << endl;
	return 0;
}
