/* Да се състави алгоритъм, който намира първата
цифра в зададено цяло число. 
 */

#include <iostream>
using namespace std;

int main()
{
	int number, first_digit;
	cout << "Enter a number: ";
	cin >> number;

	if (number < 0)
	{
		number = -number;
	}
	first_digit = number;
	while (first_digit >= 10)
	{
		first_digit /= 10;
	}
	cout << "The first digit is: " << first_digit << endl;
	return 0;
}
