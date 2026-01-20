/* Да се състави алгоритъм, който намира разликата
между сумата от третите степени на четните цифри 
и сумата от вторите степени на
нечетните цифри на зададено цяло число. 
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int number;
	double sum_evens = 0;
	double sum_odds = 0;

	cout << "Enter a number: ";
	cin >> number;

	while (number > 0)
	{
		int digit = number % 10;
		if (digit % 2 == 0)
			sum_evens += pow(digit, 3);
		else
			sum_odds += pow(digit, 2);
		number /= 10;
	}
	double difference = sum_evens - sum_odds;
	cout << "Difference = " << difference << endl;
	return 0;
}
