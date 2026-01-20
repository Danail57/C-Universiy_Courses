/* Да се състави алгоритъм, който проверява 
дали всичките цифри на зададено 
цяло число са еднакви. 
 */

#include <iostream>
using namespace std;

int all_digits_same(int n)
{
	if (n < 0) n = -n;
	if (n < 10) return 1;

	int last_digit = n % 10;
	n /= 10;

	while (n > 0)
	{
		int current_digit = n % 10;
		if (current_digit != last_digit)
		{
			return 0;
		}
		n /= 10;
	}
	return 1;
}

int main()
{
	int num;
	cout << "Enter a number: ";
	cin >> num;

	if (all_digits_same(num))
	{
		cout << "All digits are the same.\n", num;
	}
	else
	{
		cout << "Not all digits are the same.\n", num;
	}
	return 0;
}
