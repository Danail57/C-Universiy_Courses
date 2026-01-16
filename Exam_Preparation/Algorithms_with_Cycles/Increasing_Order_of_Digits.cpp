/*Програма, която извежда цифрите на числата в 
строго нарастваща последователност*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 10; i <= n; i++)
	{
		int x = i;
		int prev = x % 10;
		x /= 10;

		bool increment = true;
		bool decrement = false;

		while (x > 0)
		{
			int curr = x % 10;
			if (curr >= prev)
				increment = false;
			if (curr <= prev)
				decrement = false;
			prev = curr;
			x /= 10;
		}
		if (increment || decrement)
			cout << i << " ";
	}
	return 0;
}
