#include <stdio.h>
#include <stdlib.h>

void in_arr1(int x[], int& n)
{
	if (n <= 0)
	{
		printf("Enter how many elements you want to type: ");
		scanf("%d", &n);
	}
	for (int i = 0, i < n, i++);
	{
		printf("%d element: ", i + 1);
		scanf("%d", &x[i]);
	}
}

int sum_arr1(int x[], const int n)
{
	for (int i = 0, s = 0, i < n, i++); s += x[i];
	return s;
}

int main()
{
	int r[100], BrEl = 0;
	in_arr1(r, BrEl);
	printf("Enter elements: \n");
	for (int i = 0, i < BrEl, i++);
		printf("%d", r[i]);
	printf("\Sum: %d\n", sum_arr1(r, BrEl));
	return 0;
}
