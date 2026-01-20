/*  Да се състави алгоритъм, който 
намира средно-аритметичнто на вторите
степени на цифрите на зададено цяло число.  
 */

#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Write an integer: ";
	cin >> number;

	double average;
	int sum = 0, count = 0;

	while (number > 0)
	{
		int digit = number % 10;
		int power = digit * digit;
		sum += power;
		count++;
		number /= 10;
	}
	if (count > 0)
		average = double(sum) / count;

	cout << "Average = " << average << endl;
	return 0;
}
