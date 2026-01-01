#include <iostream>
using namespace std;



int max_number(int a[] , int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int min_number(int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}


int main()
{
	int n;
	cout << "Enter how many numbers you want to write: ";
	cin >> n;
	
	int a[10000];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter a number: ";
		cin >> a[i];
	}
	cout << "Max number: " << max_number(a, n) << endl;
	cout << "Min number: " << min_number(a, n) << endl;
	return 0;
}
