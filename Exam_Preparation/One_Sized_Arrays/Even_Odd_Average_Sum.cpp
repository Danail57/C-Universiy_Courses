#include <iostream>
using namespace std;

int sum_even_nums(int a[], int n)
{
	int even_sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			even_sum += a[i];
	}
	return even_sum;
}

int sum_odd_nums(int a[], int n)
{
	int odd_sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
			odd_sum += a[i];
	}
	return odd_sum;
}

double average(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return static_cast<double>(sum) / n;
}


int main()
{
	int n;
	cout << "Enter how many numbers you want to write: ";
	cin >> n;

	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a number: ";
		cin >> a[i];
	}
	cout << "Sum of even numbers: " << sum_even_nums(a, n) << endl;
	cout << "Sum of odd numbers: " << sum_odd_nums(a, n) << endl;
	cout << "Average of all writen numbers: " << average(a, n) << endl;
	return 0;
}
