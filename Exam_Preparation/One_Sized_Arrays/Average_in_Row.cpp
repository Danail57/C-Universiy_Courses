/*Да се състави програма, която конструира
двумерен динамичен целочислен масив с 
m реда и n стълба, въвежда елементите му и
създава едномерен масив, съдържащ 
средно-аритметичното на
елементите във всеки ред.*/

#include <iostream>
using namespace std;

int main()
{
	int m;
	cout << "Enter how many rows you want: ";
	cin >> m;

	int n;
	cout << "Enter how many cols you want: ";
	cin >> n;

	int A[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter numbers: ";
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		double sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += A[i][j];
		}
		double average_in_row = sum / n;
		cout << "Average of row " << i + 1 << " = " << average_in_row << endl;
	}
	return 0;
}
