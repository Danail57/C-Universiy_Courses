/*11) Да се намери сумата от елементите в 
отделните стълбове на двумерен масив с
m реда и n стълба.*/

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

	int A[1000][1000];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> A[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		int sum_rows = 0;
		for (int i = 0; i < m; i++)
		{
			sum_rows += A[i][j];
		}
		cout << "Sum of column " << j + 1 << " = " << sum << endl;
	}
}
