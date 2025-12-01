
// Даден е двумерен масив А с m реда и n стълба. 
// Да се състави програма, която създава нов масив
// а0, а1,...,аm-1, като стойността на аi  е равна
// на СРЕДНО-АРИТМЕТИЧНОТО на елементите в i-ия ред,
// които са в интервала [p,q], където p и q са зададени.   

#include <iostream>
using namespace std;

int main()
{
	int p, q;
	cout << "Enter the interval [p, q]: ";
	cin >> p >> q;

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
			cout << "Enter element[" << i << "][" << j << "]:";
			cin >> A[i][j];
		}
	}

	double average[1000];
	for (int i = 0; i < m_rows; i++)
	{
		double sum = 0;
		int count = 0;
		for (int j = 0; j < n_cols; j++)
		{
			if (A[i][j] >= p && A[i][j] <= q)
			{
				sum += A[i][j];
				count++;
			}
		}
		if (count > 0)
			average[i] = sum / count;
		else
		{
			average[i] = 0;
		}
	}
	cout << "\nAverage per row in interval ["<< p <<","<< q <<"]\n";
	for (int i = 0; i < m_rows; i++)
	{
    cout << "Row " << i + 1 << ": " << average[i] << endl;
	}
}
