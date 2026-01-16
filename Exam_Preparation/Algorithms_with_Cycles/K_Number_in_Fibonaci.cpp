/*k-то число от редицата на Фибоначи*/

#include <iostream>
using namespace std;

int main()
{
	int k;
	cin >> k;

	if (k == 0)
	{
		cout << 0;
		return 0;
	}
	if (k == 1)
	{
		cout << 1;
		return 0;
	}
	int a = 0, b = 1, c;
	for (int i = 2; i <= k; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	cout << b;
	return 0;
}
