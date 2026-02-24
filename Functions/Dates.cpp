// Програма за сравняване на дати

#include <stdio.h>
#include <stdlib.h>

int datcmp(int d1, int m1, int g1, int d2, int m2, int g2)
{
	if (g1 != g2) return g1 - g2;
	if (m1 != m2) return m1 - m2;
	return d1 - d2;
}

void readdat(int* d, int* m, int* g)
{
	printf(" - day: "); scanf("%d", d);
	printf(" - month: "); scanf("%d", m);
	printf(" - year: "); scanf("%d", g);
}

int main()
{
	int D1, M1, G1, D2, M2, G2;
	int n;

	printf("Enter the first date: \n");
	readdat(&D1, &M1, &G1);

	printf("Enter the second date: \n");
	readdat(&D2, &M2, &G2);
	n = datcmp(D1, M1, G1, D2, M2, G2);

	if (n < 0)
		printf("The first date is earlier. \n");

	else if (n == 0)
		printf("The both dates are identical. \n");

	else
		printf("The second date is not earlier. \n");
		
	return 0;
}

