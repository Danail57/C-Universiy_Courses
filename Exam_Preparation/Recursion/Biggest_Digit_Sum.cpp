// Да се намери при кое от две зададени цели числа
// сумата от цифрите е по-голяма. 

#include <iostream>
using namespace std;

int digit_sum(int n)
{
	if (n == 0)
		return 0;
	return n % 10 + digit_sum(n / 10);
}


void print_digits(int n)
{
	if (n < 0)
		n = -n;
	if (n == 0)
		return;
	cout << n % 10 << " ";
	print_digits(n / 10);
}

void print_biggest_digit_sum(int a, int b)
{
	cout << "Digits of the first number: ";
	print_digits(a);
	cout << endl;

	cout << "Digits of the second number: ";
	print_digits(b);
	cout << endl;

	int sum_a = digit_sum(a);
	int sum_b = digit_sum(b);

	if (sum_a > sum_b)
		cout << a << " has bigger digit sum.";
	else if (sum_b > sum_a)
		cout << b << " has bigger digit sum.";
	else
		cout << "Digit sum of both numbers is equal.";
}

int main()
{
	int a, b;
	cin >> a >> b;
	print_biggest_digit_sum(a, b);
	return 0;
}
