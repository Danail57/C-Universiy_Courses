/*Да се намери при кое от две зададени цели 
числа сумата от цифрите е по-голяма. */

#include <iostream>
using namespace std;

int sum_of_digits(int n)
{
	int sum = 0;
	n = abs(n);
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int a, b;
	cout << "Enter two numbers: ";
	cin >> a >> b;

	int sum_a = sum_of_digits(a);
	int sum_b = sum_of_digits(b);

	if (sum_a > sum_b)
		cout << a << " has the larger sum of digits: " << sum_a << endl;
	else if (sum_b > sum_a)
		cout << b << " has the larger sum of digits: " << sum_b << endl;
	else
		cout << "Both numbers have the ame sum of digits: " << sum_a << endl;
	
	return 0;
}
