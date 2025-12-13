/* Да се намери най-голямата цифра във
всяко от три зададени цели числа.  */

#include <iostream>
using namespace std;

int biggest_digit_in_number(int n)
{
	n = abs(n);
	int max_digit = 0;

	while (n > 0)
	{
		int digit = n % 10;
		if (digit > max_digit)
			max_digit = digit;
		n /= 10;
	}
	return max_digit;
}

int main()
{
	int a, b, c;
	cout << "Enter three numbers: ";
	cin >> a >> b >> c;

	cout << "The biggest digit in " << a << " is " << biggest_digit_in_number(a) << endl;
	cout << "The biggest digit in " << b << " is " << biggest_digit_in_number(b) << endl;
	cout << "The biggest digit in " << c << " is " << biggest_digit_in_number(c) << endl;
	
	return 0;
}
