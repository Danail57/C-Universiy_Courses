/*Напишете програма, която въвежда цяло положително
число, представено в десетична бройна система и 
го извежда - 
представено в 16-ична позиционна бройна система
представено в 8-ична позиционна бройна система
представено в 2-ична позиционна бройна система*/

#include <iostream>
using namespace std;

void to_binary(int n)
{
	int digits[32];
	int i = 0;

	while (n > 0)
	{
		digits[i++] = n % 2;
		n /= 2;
	}

	for (int j = i - 1; j >= 0; j--)
		cout << digits[j];
	cout << endl;
}

void to_octal(int n)
{
	int digits[32];
	int i = 0;

	while (n > 0)
	{
		digits[i++] = n % 8;
		n /= 8;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << digits[j];
	cout << endl;
}

void to_hex(int n)
{
	char digits[32];
	int i = 0;

	while (n > 0)
	{
		int r = n % 16;
		if (r < 10)
			digits[i++] = '0' + r;
		else
			digits[i++] = 'A' + (r - 10);

		n /= 16;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << digits[j];
	cout << endl;
}

int main()
{
	int n;
	cout << "Enter a positive integer: ";
	cin >> n;

	cout << "Binary: ";
	to_binary(n);

	cout << "Octal: ";
	to_octal(n);

	cout << "Hexadecimal: ";
	to_hex(n);

	return 0;
}
