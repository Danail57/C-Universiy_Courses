#include <iostream>
#include <stdio.h>


using namespace std;

int main()
{
	int n, fact = 1;
	printf("Enter a number: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}
	printf("Factorial: %d\n", fact);
	return 0;
}
