/*  Да се състави алгоритъм, който проверява
дали цифрите на зададено цяло число 
образуват нарастваща последователност. 
 */

#include <iostream>
using namespace std;

int main()
{
	int number, digit, last_digit;
	int is_ascending = 1;
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
			is_ascending = 0;
			break;
		}
		last_digit = digit;
		number /= 10;
	}
	if (is_ascending)
		cout << "Digits are in ascending order.\n";
	else
		cout << "Digits are not in ascending order.\n";
	return 0;
}
