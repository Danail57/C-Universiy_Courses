/*Да се намери при кое от две зададени цели числа
средноаритметичното на ненулевите цифри е по-голяма.  .*/

#include <iostream>
using namespace std;

double average_sum_of_nonnull_digits(int n)
{
	int average_sum_nonull = 0;
	int count = 0;
	n = abs(n);

	while (n > 0)
	{
		int digit = n % 10;
		if (digit != 0)
		{
			average_sum_nonull += digit;
			count++;
		}
		n /= 10;
	}
	if (count == 0)
		return 0;
	return static_cast<double> (average_sum_nonull) / count;
}


int main()
{
	int a, b;
	cout << "Enter the first number: ";
	cin >> a;
	
	cout << "Enter the second number: ";
	cin >> b;

	double avg_a = average_sum_of_nonnull_digits(a);
	double avg_b = average_sum_of_nonnull_digits(b);

	if (avg_a > avg_b)
		cout << a << " has the larger average of non zero digits: " << avg_a << endl;
	else if (avg_b > avg_a)
		cout << b << " has the larger average of non zero digits: " << avg_b << endl;
	else
		cout << "Both number have the same average of non zero digits: " << avg_a << endl;
	return 0;
}
