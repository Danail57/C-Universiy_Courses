/*Програма, която извежда числата между M и N
 като (M < N), които не съдържат нула в цифрите си*/

#include <iostream>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		int x = i;
		bool has_zero = false;

		if (x == 0)
			has_zero = true;
		if (x < 0)
			x = -x;

		while (x > 0)
		{
			if (x % 10 == 0)
			{
				has_zero = true;
				break;
			}
			x /= 10;
		}
		if (!has_zero)
			cout << i << " ";
	}
	return 0;
}
