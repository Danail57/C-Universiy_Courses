#include <iostream>
using namespace std;

// Да се състави програма, която създава
// Даден е двумерен масив А с m реда и n стълба.
// нов масив а0, а1, ..., аm - 1, 
// като стойността на аi  е равна
// на средно - аритметичното
// на положителните елементи в i - ия ред.

int main()
{
	int m_rows, n_cols;
	cout << "Enter a number for rows: ";
	cin >> m_rows;

	cout << "Enter a number for cols: ";
	cin >> n_cols;

	int A[1000][1000];

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < n_cols; j++)
		{
			cin >> A[i][j];
		}
	}

	float average_positive[1000];

	for (int i = 0; i < m_rows; i++)
	{
		int count = 0;
		int positive_elements_sum = 0;
		
		for (int j = 0; j < n_cols; j++)
		{
			if (A[i][j] > 0)
			{
				count++;
				positive_elements_sum += A[i][j];
			}
		}
		if (count > 0)
			average_positive[i] = (float)positive_elements_sum / count;
		else
			average_positive[i] = 0;
	}

	cout << "\nThe average of positive elements: \n";
	float average = 0;
	for (int i = 0; i < m_rows; i++)
	{
		cout << average_positive[i] << endl;
	}
	return 0;
}
