#include <iostream>
using namespace std;

void reversed_numbers(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[1000];
	int n;
	cout << "Enter how many numbers you want to write: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter a number: ";
		cin >> a[i];
	}
	cout << "Numbers in reversed row: ";
	reversed_numbers(a, n);
	return 0;
}
