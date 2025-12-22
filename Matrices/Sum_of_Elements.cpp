/*Условие:
Дадена е квадратна матрица A с размер n × n.

Да се намерят:

1️ Сумата на елементите по главния диагонал
2️ Сумата на елементите по вторичния диагонал
3️ Броят на елементите над главния диагонал
4️ Броят на отрицателните елементи
под вторичния диагонал*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the size of the square matrix: ";
	cin >> n;

	int A[100][100];

	cout << "Enter the elements of the matrix:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	int sum_main_diagonal = 0;
	int sum_second_diagonal = 0;
	int count_above_main_diag = 0;
	int count_below_sec_diag = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				sum_main_diagonal += A[i][j];
			if (i + j == n - 1)
				sum_second_diagonal += A[i][j];
			if (j > i)
				count_above_main_diag++;
			if (i + j > n - 1 && A[i][j] < 0)
				count_below_sec_diag++;
		}
	}
	cout << "Sum of main diagonal: " << sum_main_diagonal << endl;
	cout << "Sum of secondary diagonal: " << sum_second_diagonal << endl;
	cout << "Number of elements above main diagonal: " << count_above_main_diag << endl;
	cout << "Number of negative elements below secondary diagonal: " << count_below_sec_diag << endl;
	return 0;
}
