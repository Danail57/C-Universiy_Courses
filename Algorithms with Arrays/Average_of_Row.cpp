/*Да се намерят средно аритметичните на елементите
в отделните редове на двумерен масив с m реда
и n стълба*/

#include <iostream> 
using namespace std;

int main()
{
	int m;
	cout << "Enter the number of rows: ";
	cin >> m;

	int n;
	cout << "Enter the number of cols: ";
	cin >> n;

	int A[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> A[i][j];
		}
	}
	double average;
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += A[i][j];
		}
		average = double(sum) / n;
		cout << "Average of row " << i + 1 << " = " << average << endl;
	}
	return 0;
}
