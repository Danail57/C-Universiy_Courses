#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i = 1, x = 2;
	do {
		x *= i;
		i += 2;

	} while (i <= 7);
	printf("%d", x);
}
