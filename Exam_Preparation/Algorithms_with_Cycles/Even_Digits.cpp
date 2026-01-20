/*  Да се състави алгоритъм, който проверява
дали всичките цифри на зададено цяло число са четни. 
 */

#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Write a number: ";
	cin >> number;

	int temp = number;
	int all_even = 1;

	if (temp < 0)
	{
		temp -= temp;
	}
	if (temp == 0)
	{
		cout << "All digits are even in " << number << endl;
		return 0;
	}
	while (temp > 0)
	{
		int digit = temp % 10;
		if (digit % 2 != 0)
		{
			all_even = 0;
			break;
		}
		temp /= 10;
	}
	if (all_even)
		cout << "All digits are even " << number << endl;
	else
		cout << "Not all digits are even " << number << endl;
	return 0;
}
