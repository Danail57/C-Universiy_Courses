/*Да се състави алгоритъм, 
който намира номера на 
най-малката цифра в зададено цяло число. */

#include <iostream>
using namespace std;


int main()
{
	int number;
	cin >> number;
	int position = 1;
	int min_position = 1;

	int digit = number % 10;
	int min_digit = digit;
	number /= 10;

	while (number > 0)
	{
		position++;
		digit = number % 10;

		if (digit < min_digit)
		{
			min_digit = digit;
			min_position = position;
		}
		number /= 10;
	}
	cout << "Position of the smallest digit: " << min_position << endl;
	return 0;
}
