/* Да се състави алгоритъм, който извежда
сумата от квадратните корени на нечетните цифри 
на зададено цяло число. 
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int number;
	double sum = 0;
	cout << "Write an integer: ";
	cin >> number;

	while (number > 0)
	{
		int digit = number % 10;
		if (digit % 2 != 0)
		{
			sum += sqrt(digit);
		}
		number /= 10;
	}
	cout << "Sum of square roots of odd digits = " << sum << endl;
	return 0;
}
