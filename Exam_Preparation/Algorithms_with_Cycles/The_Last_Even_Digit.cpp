/* Да се състави алгоритъм, който намира
последната четна цифра в зададено цяло число. 
 */

#include <iostream>
using namespace std;

int find_last_even_digit(int number)
{
	number = abs(number);
	while (number > 0)
	{
		int digit = number % 10;
		if (digit % 2 == 0)
		{
			return digit;
		}
		number /= 10;
	}
	return -1;
}


int main()
{
	int number;
	cout << "Write a number: ";
	cin >> number;

	int result = find_last_even_digit(number);
	if (result != -1)
		cout << "The last even digit writen is: " << result << endl;
	else
		cout << "There is no even digit." << endl;

}
