/*  Да се състави алгоритъм, който намира 
средно-аритметичнто на вторите степени на
четните цифри на зададено цяло число.  
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int number;
	int sum = 0;
	int count = 0;
	double average;

	cout << "Write an integer: ";
	cin >> number;

	while (number > 0)
	{
		int digit = number % 10;
		if (digit % 2 == 0)
		{
			sum += digit * digit;
			count++;
		}
		number /= 10;
	}
	if (count > 0)
	{
		average = double(sum) / count;
		cout << "Average = " << average << endl;
	}
	else
	{
		cout << "No even digits" << endl;
	}
	return 0;
}
