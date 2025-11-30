#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cout << "Enter number for m: ";
	cin >> m;

	cout << "Enter nmber for n: ";
	cin >> n;

	int A[1000][1000];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	int negative_sum_numbers[1000];

	for (int i = 0; i < m; i++)
	{
		int  count_negative_sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] < 0) count_negative_sum++;
		}
		negative_sum_numbers[i] = count_negative_sum;
	}

	for (int i = 0; i < m; i++)
	{
		cout << "Row " << i + 1 << " negative count: " << negative_sum_numbers[i] << endl;

	}
	return 0;
}
