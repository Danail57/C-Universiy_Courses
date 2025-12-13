/*Да се намери произведението от най-големите четни
цифри в три зададени цели числа. */


#include <iostream>
using namespace std;

int biggest_even_digit(int n)
{
	int product = 1;
	int max_even_digit = -1; 
	// -1 означава, че не сме намерили четна ццифра

	
	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 == 0 && digit > max_even_digit)
			max_even_digit = digit;
		
		n /= 10;
	}
	return max_even_digit;
}

int main()
{
	int a, b, c;
	cout << "Enter three numbers: ";
	cin >> a >> b >> c;

	int a1 = biggest_even_digit(a);
	int b1 = biggest_even_digit(b);
	int c1 = biggest_even_digit(c);

	if (a1 == -1 || b1 == -1 || c1 == -1)
	{
		cout << "At least one number has no even digits." << endl;
	}
	else
	{
		int product = a1 * b1 * c1;
		cout << "Product of biggest even digits = " << product << endl;
	}
	return 0;
}
