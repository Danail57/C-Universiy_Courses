// 2. double sized array - find the value of the max element and the index of the min el.


#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n_rows;
	cout << "Write the number of rows: ";
	cin >> n_rows;

	int m_cols;
	cout << "Write the number of cols: ";
	cin >> m_cols;

	int A[1000][1000];
	for (int i = 0; i < n_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> A[i][j];
		}
	}

	int max_value = A[0][0];
	int min_value = A[0][0];

	int min_row = 0;
	int min_col = 0;

	for (int i = 0; i < n_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			if (A[i][j] > max_value)
			{
				max_value = A[i][j];
			}

			if (A[i][j] < min_value)
			{
				min_value = A[i][j];
				min_row = i;
				min_col = j;
			}
		}
	}
	cout << "Max element value: " << max_value << endl;
	cout << "Min element index: A[" << min_row + 1 << "][" << min_col + 1 << "] (Value: " << min_value << ")" << endl;
}
