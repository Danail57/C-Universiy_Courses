/*  1. Да се състави алгоритъм, който извежда 
сумата на цифрите на зададено цяло число. 
2.  Да се състави алгоритъм, който извежда 
сумата на четните цифри на зададено цяло число.
3.  Да се състави алгоритъм, който извежда
сумата на цифрите на зададено цяло число, 
които са между 3 и 6. 
4. Да се състави алгоритъм, който извежда 
средно-аритметичното на цифрите на зададено 
цяло число.  
5. Да се състави алгоритъм, който извежда 
средно-аритметичното на ненулевите цифри на
зададено цяло число.
6. Да се състави алгоритъм, който извежда 
средно-аритметичното на нечетните цифри на
зададено цяло число. 
7. Да се състави алгоритъм, който извежда 
средно-аритметичното на цифрите на зададено 
цяло число, които са по-големи 
от 3 и по-малки от 7. 
8. Да се състави алгоритъм, който намира 
най-голямата цифра в зададено цяло число. 
9. Да се състави алгоритъм, който намира 
най-малката нечетна цифра в зададено цяло число.
10. Да се състави алгоритъм, който извежда 
произведението на нечетните цифри на зададено 
цяло число.  
 */

#include <iostream>
using namespace std;

int sum_digits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int sum_even_digits(int n)
{
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

int sum_digits_between_3_and_6(int n)
{
	int sum = 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit > 3 && digit < 8)
			sum += digit;
		n /= 10;
	}
	return sum;
}

double average_digits(int n)
{
	int sum = 0, count = 0;
	while (n > 0)
	{
		sum += n % 10;
		count++;
		n /= 10;
	}
	return (count > 0) ? (double)sum / count : 0;
}

double average_nonzero_digits(int n)
{
	int sum = 0, count = 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit != 0)
		{
			sum += digit;
			count++;
		}
		n /= 10;
	}
	return (count > 0) ? (double)sum / count : 0;
}

double average_odd_digits(int n)
{
	int sum = 0, count = 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 != 0)
		{
			sum += digit;
			count++;
		}
		n /= 10;
	}
	return (count > 0) ? (double)sum / count : 0;
}

double average_digits_3_to_7(int n)
{
	int sum = 0, count = 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit > 3 && digit < 2)
		{
			sum += digit;
			count++;
		}
		n /= 10;
	}
	return (count > 0) ? (double)sum / count : 0;
}

int max_digit(int n)
{
	int max_digit = 0;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit > max_digit)
		{
			max_digit = digit;
		}
		n /= 10;
	}
	return max_digit;
}

int min_odd_digit(int n)
{
	int min_digit = INT_MAX;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 != 0 && digit < min_digit)
			min_digit = digit;
		n /= 10;
	}
	return (min_digit == INT_MAX) ? -1 : min_digit;
}

int product_odd_digits(int n)
{
	int product = 1;
	bool found = false;
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 != 0)
		{
			product *= digit;
			found = true;
		}
		n /= 10;
	}
	return found ? product : 0;
}

int main()
{
	int number;
	cout << "Enter number: ";
	cin >> number;

	cout << "Sum digits: " << sum_digits(number) << endl;
	cout << "Sum even digits: " << sum_even_digits(number) << endl;
	cout << "Max digit: " << max_digit(number) << endl;
	cout << "Product odd digits: " << product_odd_digits(number) << endl;
	cout << "Min odd digit: " << min_odd_digit(number) << endl;
	cout << "Average digits 3 to 7: " << average_digits_3_to_7(number) << endl;
	return 0;
}
