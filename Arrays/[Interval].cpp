#include <iostream>
using namespace std;

// Даден е двумерен масив А с m реда и n стълба. 
// Да се състави програма, която създава 
// нов масив а0, а1,...,аm-1, 
// като стойността на аi  е равна на БРОЯ на 
// елементите в i-ия ред, които са в 
// интервала [p,q], където p и q са зададени.  

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
			cout << "Enter element [" << i << "]["<< j <<"]: ";
			cin >> A[i][j];
		}
	}
	int count_elements[1000];
	for (int i = 0; i < m_rows; i++)
	{
		int counter_elements = 0;
		for (int j = 0; j < n_cols; j++)
		{
			if (A[i][j] >= p && A[i][j] <= q)
			{
				counter_elements++;
			}
		}
		count_elements[i] = counter_elements;
	}
	cout << "\nCount of elements in [" << p << "," << q << "] per row:\n";
	for (int i = 0; i < m_rows; i++)
	{
		cout << "Row " << i << ": " << count_elements[i] << endl;
	}
}
