/*Дадена е матрица A с размери n × m (1 ≤ n, m ≤ 100).
Да се напише програма, която:
1️. Въвежда елементите на матрицата
2️. Извежда матрицата на екрана
3️. Намира сумата на всички елементи
4️. Намира минималния и максималния елемент
5️. Намира средното аритметично на елементите
*/

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	int A[100][100];

	do
	{
		cout << "Enter number of rows (n): ";
		cin >> n;
		cout << "Enter number of cols (m): ";
		cin >> m;
	} while (n < 1 || n > 100 || m < 1 || m > 100);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
		}
	}
	cout << "\nMatrix A:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	int sum = 0;
	int min_element = A[0][0];
	int max_element = A[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += A[i][j];
			if (A[i][j] < min_element)
				min_element = A[i][j];
			if (A[i][j] > max_element)
				max_element = A[i][j];
		}
	}
	double average = (double)sum / (n * m);
	cout << "\nSum of elements: " << sum << endl;
	cout << "Minimum element: " << min_element << endl;
	cout << "Maximum element: " << max_element << endl;
	cout << "Average value: " << average << endl;
	return 0;
}
