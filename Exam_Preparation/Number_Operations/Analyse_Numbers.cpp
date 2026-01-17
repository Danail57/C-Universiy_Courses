/*Дадено е цяло положително число.
Да се изведат цифрите му, 
сортирани във възходящ ред, намира
минималната и максимална цифра, средно
аритметичното на цифрите, граница за по-големи от 5
и произведението им.*/

#include <iostream>
using namespace std;

void analyse_number(int n, int digits[], int &count)
{
	count = 0;
	while (n > 0)
	{
		digits[count] = n % 10;
		count++;
		n /= 10;
	}
}

void sort_digits_ascending(int digits[], int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (digits[i] > digits[j])
			{
				int temp = digits[i];
				digits[i] = digits[j];
				digits[j] = temp;
			}
		}
	}
}

int sum_digits(int digits[], int count)
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += digits[i];
	return sum;
}

int product_digits(int digits[], int count)
{
	int product = 1;
	for (int i = 0; i < count; i++)
		product *= digits[i];
	return product;
}

int min_digit(int digits[], int count)
{
	int min = digits[0];
	for (int i = 1; i < count;i++)
		if (digits[i] < min)
			min = digits[i];
	return min;
}

int max_digit(int digits[], int count)
{
	int max = digits[0];
	for (int i = 1; i < count;i++)
		if (digits[i] > max)
			max = digits[i];
	return max;
}

void print_even_odd(int digits[], int count)
{
	cout << "Even digits: ";
	for (int i = 0; i < count; i++)
		if (digits[i] % 2 == 0)
			cout << digits[i] << " ";
	cout << endl;

	cout << "Odd digits: ";
	for (int i = 0; i < count; i++)
		if (digits[i] % 2 != 0)
			cout << digits[i] << " ";
	cout << endl;
}

void print_less_than(int digits[], int count, int limit)
{
	cout << "Digits less than " << limit << ": ";
	for (int i = 0; i < count; i++)
		if (digits[i] < limit)
			cout << digits[i] << " ";
	cout << endl;
}

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;

	int digits[1000];
	int count;

	analyse_number(n, digits, count);
	sort_digits_ascending(digits, count);

	cout << "Sum of digits: " << sum_digits(digits, count) << endl;
	cout << "Product of digits: " << product_digits(digits, count) << endl;
	cout << "Minimum digit: " << min_digit(digits, count) << endl;
	cout << "Maximum digit: " << max_digit(digits, count) << endl;
	cout << "Average digit: " << (double)sum_digits(digits, count) / count << endl;

	print_even_odd(digits, count);
	print_less_than(digits, count, 5);
	return 0;
}
