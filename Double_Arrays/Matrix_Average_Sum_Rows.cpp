#include <iostream>
using namespace std;

int main()
{
	int m_rows, n_cols;
	cout << "Enter a number for rows: ";
	cin >> m_rows;

	cout << "Enter a number for cols: ";
	cin >> n_cols;

	int** new_matrix = new int* [m_rows];
	
	for (int i = 0; i < m_rows; i++)
	{
		new_matrix[i] = new int[n_cols];
	}

	cout << "Enter matrix elements:\n";
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < n_cols; j++)
		{
			cin >> new_matrix[i][j];
		}
	}
	
	double* average = new double[m_rows];
	
	for (int i = 0; i < m_rows; i++)
	{
		int sum = 0;
		for (int j = 0; j < n_cols; j++)
		{
			sum += new_matrix[i][j];
		}
		average[i] = (double)sum / n_cols;
	}
	cout << "\nAverages for each row:\n";
	for (int i = 0; i < m_rows; i++)
		cout << "Row " << i + 1 << ": " << average[i] << endl;

		for (int i = 0; i < m_rows; i++)
			delete[] new_matrix[i];
		delete[] new_matrix;
		delete[] average;
		
		return 0;
	
}

