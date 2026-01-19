/*Да се състави алгоритъм, който
проверява дали зададено цяло число е палиндром.
Например числата 23532 и 356653 са палиндроми.
 */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, reversed = 0, remainder, original;
	printf("Write an integer: ");
	scanf("%d", &n);
	original = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}
	if (original == reversed)
		printf("%d is a palindrome.", original);
	else
		printf("%d is not a palindrome.", original);
	return 0;
}
