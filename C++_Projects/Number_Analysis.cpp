/*Анализ на цифри - (Цифрови данни)
Програмата приема масви от цели числа 
и извършва различни анализи върху тях:

Намира най-голямата цифра на всяко число
Намира най-малката цифра на всяко число
Намира най-голямата четна и нечетна цифра на всяко число
Намира най-малката четна и нечетна цифра на всяко числок
Изчислява сумата на четните цифри на всяко число
Изчислява сумата на нечетните цифри на всяко число
Изчислява произведението на ненулевите цифри на всяко число
Изчислява средноаритметичното*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int biggest_digit(int n)
{
	n = abs(n);
	int max_digit = 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit > max_digit)
			max_digit = digit;
		n /= 10;
	}
	return max_digit;
}


int smallest_digit(int n)
{
	n = abs(n);
	int min_digit = 9;
	if (n == 0)
		return 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit < min_digit)
			min_digit = digit;
		n /= 10;
	}
	return min_digit;
}


int max_even_digit(int n)
{
	n = abs(n);
	int max_even = -1;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 == 0 && digit > max_even)
			max_even = digit;
		n /= 10;
	}
	return max_even;
}

int max_odd_digit(int n)
{
	n = abs(n);
	int max_odd = -1;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 == 1 && digit > max_odd)
			max_odd = digit;
		n /= 10;
	}
	return max_odd;
}

int min_even_digit(int n)
{
	n = abs(n);
	int min_even = 10;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 == 0 && digit < min_even)
			min_even = digit;
		n /= 10;
	}
	if (min_even == 10)
		return -1;
	return min_even;	
}

int min_odd_digit(int n)
{
	n = abs(n);
	int min_odd = 10;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 == 1 && digit < min_odd)
			min_odd = digit;
		n /= 10;
	}
	if (min_odd == 10)
		return -1;
	return min_odd;
}


int sum_even_digits(int n)
{
	n = abs(n);
	int sum = 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 == 0)
			sum += digit;
		n /= 10;
	}
	return sum;
}

int sum_odd_digits(int n)
{
	n = abs(n);
	int sum = 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 == 1)
			sum += digit;
		n /= 10;
	}
	return sum;
}

int product_nonzero_digits(int n)
{
	n = abs(n);
	int product = 1;
	if (n == 0)
		return 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit != 0)
			product *= digit;
		n /= 10;
	}
	return product;
}

double average_digits(int n)
{
	n = abs(n);
	int sum = 0, count = 0;
	if (n == 0)
		return 0;
	while (n > 0)
	{
		int digit = n % 10;
		sum += digit;
		count++;
		n /= 10;
	}
	return static_cast<double> (sum) / count;
}


int main()
{
	int size;
	cout << "Enter how many numbers you want to write: ";
	cin >> size;

	vector<int> numbers(size);
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> numbers[i];
	}

	for (int i = 0; i < size; i++)
	{
		int num = numbers[i];
		cout << "Analysis for number " << num << ":\n";
		cout << "Biggest digit: " << biggest_digit(num) << endl;
		cout << "Smallest digit: " << smallest_digit(num) << endl;
		cout << "Max even digit: " << max_even_digit(num) << endl;
		cout << "Min even digit: " << min_even_digit(num) << endl;
		cout << "Max odd digit: " << max_odd_digit(num) << endl;
		cout << "Min odd digit: " << min_odd_digit(num) << endl;
		cout << "Sum of even digits: " << sum_even_digits(num) << endl;
		cout << "Sum of odd digits: " << sum_odd_digits(num) << endl;
		cout << "Product of nonzero digits: " << product_nonzero_digits(num) << endl;
		cout << "Average of digits: " << average_digits(num) << endl;
		cout << "-------------------------\n";
	}
	return 0;
}
