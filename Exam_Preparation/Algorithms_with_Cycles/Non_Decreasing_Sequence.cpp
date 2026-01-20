/*  Да се състави алгоритъм, който проверява
дали цифрите на зададено цяло число 
образуват ненамаляваща последователност. 
 */

#include <iostream>
using namespace std;

int main()
{
	int number, digit, last_digit;
	int is_non_decreasing = 1;
	
	cout << "Write a number: ";
	cin >> number;

	if (number < 0)
	{
		number = -number;
	}
	last_digit = number % 10;
	number /= 10;

	while (number > 0)
	{
		digit = number % 10;
		if (digit > last_digit)
		{
			is_non_decreasing = 0;
			break;
		}
		last_digit = digit;
		number /= 10;
	}
	if (is_non_decreasing)
		cout << "Digits form a non-decreasing sequence.\n";
	else
		cout << "Digits do not form a non-decreasing sequence.\n";
	return 0;
}
