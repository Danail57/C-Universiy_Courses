/*  Да се състави алгоритъм, който намира
разликата между сумата на  цифрите, 
по големи от 5, и сумата на цифрите, 
по-малки от 5, на зададено цяло число.  
 */

#include <iostream>
using namespace std;

int difference_sums(int number)
{
	int sum_greater = 0;
	int sum_smaller = 0;

	number = abs(number);
	while (number > 0)
	{
		int digit = number % 10;
		if (digit > 5)
			sum_greater += digit;
		else if (digit < 5)
			sum_smaller += digit;
		number /= 10;
	}
	return sum_greater - sum_smaller;
}

int main()
{
	int number;
	cout << "Enter an integer: ";
	cin >> number;

	int result = difference_sums(number);
	cout << "Difference = " << result << endl;
	return 0;
}
