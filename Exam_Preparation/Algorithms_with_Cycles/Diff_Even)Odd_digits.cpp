/*  Да се състави алгоритъм, който намира 
разликата между сумата на четните цифри и
сумата на нечетните цифри на зададено цяло число.  
 */

#include <iostream>
using namespace std;

int main()
{
	int number;
	int sum_evens = 0, sum_odds = 0;

	cout << "Write an integer: ";
	cin >> number;

	while (number > 0)
	{
		int digit = number % 10;
		if (digit % 2 == 0)
			sum_evens += digit;
		else
			sum_odds += digit;
		number /= 10;
	}
	int diff = sum_evens - sum_odds;
	cout << "Difference = " << diff << endl;
	return 0;
}
