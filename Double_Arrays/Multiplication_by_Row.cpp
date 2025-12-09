//Да се намери произведението от ненулевите елементи
//във всеки ред на двумерен масив с m реда и n стълба. 

#include <iostream>
using namespace std;

int main()
{
	int m;
	cout << "Enter the number for rows: ";
	cin >> m;

	int n;
	cout << "Enter the number for cols: ";
	cin >> n;

	int A[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter element [" << i + 1 << "][" << j + 1 <<"]: ";
			cin >> A[i][j];
		}
	}

	int product = 1;
	

	for (int i = 0; i < m; i++)
	{
		product = 1;
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] != 0)
			{
				product *= A[i][j];
			}
		}
		cout << "Product of non-zero elements in row " << i + 1 << ": " << product << endl;
	}
}
