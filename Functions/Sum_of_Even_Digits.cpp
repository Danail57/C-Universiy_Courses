/*Да се намери при кое от две зададени цели числа
сумата на четните цифрите е по-голяма.  */

#include <iostream>
using namespace std;

int sum_of_even_digits(int n)
{
	int sum = 0;
	n = abs(n);
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 == 0)
			sum += digit;
		n /= 10;
		
	}
	return sum;
}

int main()
{
	int a;
	cout << "Enter the first number: ";
	cin >> a;

	int b;
	cout << "Enter the second number: ";
	cin >> b;

	int sum_a = sum_of_even_digits(a);
	int sum_b = sum_of_even_digits(b);

	if (sum_a > sum_b)
		cout << a << " has the larger sum of digits: " << sum_a << endl;
	else if (sum_b > sum_a)
		cout << b << " has the larger sum of digits: " << sum_b << endl;
	else
		cout << "Both numbers have the same sum of digits: " << sum_a << endl;

	return 0;
}
