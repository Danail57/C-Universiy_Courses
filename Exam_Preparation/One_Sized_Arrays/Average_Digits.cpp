//Зададени са два едномерни целoчислeни масива 
// А0, А1,...,Аn-1 и B0, B1,...,Bn-1. 
// Да се състави рекурсивна програма, 
// която създава нов масив а0, а1,...,аn-1,
// като стойността на аi  е 
// равна на разликата между 
// средноаритметичното на нечетните цифри
// на Аi и средно-аритметичното
// на нечетните цифри на Bi. 


#include <iostream>
using namespace std;

double average_odd_digits(int number, int& sum, int& count)
{
	if (number == 0)
	{
		if (count == 0)
			return 0;
		return (double)sum / count;
	}
	int digit = number % 10;
	if (digit % 2 != 0)
	{
		sum += digit;
		count++;
	}
	return average_odd_digits(number / 10, sum, count);
}

void build_array(int A[], int B[], double C[], int n, int i)
{
	if (i == n)
		return;
	int sum_a = 0, count_a = 0;
	int sum_b = 0, count_b = 0;

	double average_a = average_odd_digits(A[i], sum_a, count_a);
	double average_b = average_odd_digits(B[i], sum_b, count_b);

	C[i] = average_a - average_b;
	build_array(A, B, C, n, i + 1);
}

int main()
{
	int n;
	cout << "Enter size of arrays: ";
	cin >> n;

	int A[1000], B[1000];
	double C[1000];

	cout << "Enter elements of A:\n";
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << "Enter elements of B:\n";
	for (int i = 0; i < n; i++)
		cin >> B[i];

	build_array(A, B, C, n, 0);

	cout << "Resulting array C:\n";
	for (int i = 0; i < n; i++)
		cout << C[i] << " ";
	return 0;
}
