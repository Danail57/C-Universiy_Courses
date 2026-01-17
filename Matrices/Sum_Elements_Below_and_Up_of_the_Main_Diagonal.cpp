// Програма за съставяне на матрица 3 на 3, която да пресмята
// сумата на елементите над и под галвния диагонал
#include <iostream>
using namespace std; 

int main() 
{
	int mat[3][3] = 
	{ 
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9} 
	};
	
	int sum = 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += mat[i][j];
		}
	}
	cout << sum << endl;
	return 0;
}
