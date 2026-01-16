//спирално запълване на квадратна матрица

#include <iostream>
using namespace std;

int main()
{
	int n = 4;
	int a[10][10];

	int top = 0, bottom = n - 1;
	int left = 0, right = n - 1;
	int num = 1;

	while (top <= bottom && left <= right)
	{
		for (int i = left; i <= right; i++)
			a[top][i] = num++;
		top++;

		for (int i = top; i <= bottom; i++)
			a[i][right] = num++;
		right--;

		for (int i = right; i >= left; i--)
			a[bottom][i] = num++;
		bottom--;

		for (int i = bottom; i >= top; i--)
			a[i][left] = num++;
		left++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
