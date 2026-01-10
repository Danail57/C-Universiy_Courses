//Зададени са два едномерни целoчислeни 
// масива А0, А1,...,Аn-1 и B0, B1,...,Bn-1. 
// 
// чрез рекурсия:
// Да се създаде нов масив  а0, а1,...,аn-1, 
// като стойността на аi  е равна на частното 
// на последните цифри на Аi и Bi. 
// 
// Да се създаде нов масив а0, а1,...,аn-1, 
// като стойността на аi  е равна на сумата от 
// първите цифри на Аi и Bi. 
//
// Да се създаде нов масив а0, а1,...,аn-1, 
// като стойността на аi  е равна на сумата от 
// броя на ненулевите цифри на Аi и Bi. 
//
// Да се състави програма, която създава нов масив
// а0, а1,...,аn-1, като стойността на аi  е 
// равна на произведението на 
// средноаритметичното на цифрите на 
// Аi и средно-аритметичното на цифрите на Bi. 

#include <iostream>
using namespace std;

int last_digit(int x)
{
	if (x < 0)
		x = -x;
	return x % 10;
}

int first_digit(int x)
{
	if (x < 0)
		x = -x;
	if (x < 10)
		return x;
	return first_digit(x / 10);
}

int count_non_zero_digits(int x)
{
	if (x == 0)
		return 0;
	int digit = x % 10;
	if(digit != 0)
		return 1 + count_non_zero_digits(x / 10);
	return count_non_zero_digits(x / 10);
}

double average_digits(int x, int& sum, int& count)
{
	if (x < 0)
		x = -x;
	if (x == 0)
	{
		if (count == 0)
			return 0;
		return (double)sum / count;
	}
	sum += x % 10;
	count++;
	return average_digits(x / 10, sum, count);
}

void build_quotient(int A[], int B[], double C[], int n, int i)
{
	if (i == n) return;
	int dA = last_digit(A[i]);
	int dB = last_digit(B[i]);

	if (dB != 0)
		C[i] = (double)dA / dB;
	else
		C[i] = 0;
	build_quotient(A, B, C, n, i + 1);
}

void build_first_digit_sum(int A[], int B[], int C[], int n, int i)
{
	if (i == n) return;
	C[i] = first_digit(A[i]) + first_digit(B[i]);
	build_first_digit_sum(A, B, C, n, i + 1);
}

void build_non_zero_count_sum(int A[], int B[], int C[], int n, int i)
{
	if (i == n) return;
	C[i] = count_non_zero_digits(A[i]) + count_non_zero_digits(B[i]);
	build_non_zero_count_sum(A, B, C, n, i + 1);
}

void build_average_product(int A[], int B[], double C[], int n, int i)
{
	if (i == n) return;

	int sum_a = 0, count_a = 0;
	int sum_b = 0, count_b = 0;

	double average_a = average_digits(A[i], sum_a, count_a);
	double average_b = average_digits(B[i], sum_b, count_b);

	C[i] = average_a * average_b;
	build_average_product(A, B, C, n, i + 1);
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	int A[100], B[100];
	double C1[100], C4[100];
	int C2[100], C3[100];

	cout << "Enter elements of A:\n";
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << "Enter elements of B:\n";
	for (int i = 0; i < n; i++)
		cin >> B[i];

	build_quotient(A, B, C1, n, 0);
	build_first_digit_sum(A, B, C2, n, 0);
	build_non_zero_count_sum(A, B, C3, n, 0);
	build_average_product(A, B, C4, n, 0);

	cout << "\nQuotient of last digits:\n";
	for (int i = 0; i < n; i++)
		cout << C1[i] << " ";

	cout << "\nSum of first digits:\n";
	for (int i = 0; i < n; i++)
		cout << C2[i] << " ";

	cout << "\nSum of non-zero digits count:\n";
	for (int i = 0; i < n; i++)
		cout << C3[i] << " ";

	cout << "\nProduct of digit averages:\n";
	for (int i = 0; i < n; i++)
		cout << C4[i] << " ";

	return 0;
}
