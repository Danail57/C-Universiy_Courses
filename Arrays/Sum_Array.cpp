// Даден е двумерен масив А с m реда и n стълба. 
// Да се състави програма, която създава нов масив а0, а1,...,аm-1, като стойността на аi 
// е равна на сумата на ненулевите елементи в i-ия ред. 

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, n;
	int sum_positive_elements = 0;
	cout << "Enter a number for m: ";
	cin >> m;

	cout << "Enter a number for n: ";
	cin >> n;

	vector<vector<int>> A(m, vector<int>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	vector<int> row_sums(m, 0);

	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] != 0)
				sum += A[i][j];
		}
		row_sums[i] = sum;
	}
	for (int i = 0; i < m; i++)
		cout << "Row " << i + 1 << " sum of non-zero elements: " << row_sums[i] << endl;
	return 0;
}
