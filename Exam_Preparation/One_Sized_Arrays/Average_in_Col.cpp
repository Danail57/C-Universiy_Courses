/*Да се състави програма, която конструира
двумерен динамичен целочислен масив с 
m реда и n стълба, въвежда елементите му и
създава едномерен масив, съдържащ 
средно-аритметичното на
елементите във всяка колона.*/

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
			cin >> A[j][i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += A[i][j];
		}
		double average_in_col = sum / m;
		cout << "Average of col " << i + 1 << " = " << average_in_col << endl;
	}
	return 0;
}
