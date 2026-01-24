/*Дадено е естествено число.
Да се генерира палиндром, който има същата сума
на цифрите като даденото число.*/

int digit_sum(int x)
{
	int s = 0;
	while (x > 0)
	{
		s += x % 10;
		x /= 10;
	}
	return s;
}

int generate_palindrome(int sum)
{
	if (sum < 10)
		return sum;
	int left = sum / 2;
	int middle = sum % 2;
	int palindrome = left * 10 + middle;
	palindrome = palindrome * 10 + left;
	return palindrome;
}

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int s = digit_sum(n);
	int p = generate_palindrome(s);
	cout << p << endl;
	return 0;
}
