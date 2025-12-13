/* Да се намери произведението на
ненулевите цифри на три зададени числа. */

#include <iostream>
using namespace std;

int product_of_nonzero_digits(int n)
{
	int product = 1;
	n = abs(n);
	while (n > 0)
	{
		int digit = n % 10;
		if (digit != 0)
			product *= digit;
		n /= 10;
	}
	return product;
}

int main()
{
	int a, b, c;
	cout << "Enter three numbers: ";
	cin >> a;
	cin >> b;
	cin >> c;
	
int result =
		product_of_nonzero_digits(a) *
		product_of_nonzero_digits(b) *
		product_of_nonzero_digits(c);
	
cout << "Product of non-zero digits = " << result << endl;
	return 0;
}
