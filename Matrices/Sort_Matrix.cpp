/*Да се напише програма, която:

въвежда матрица
четните редове (0, 2, 4, …) се сортират в нарастващ ред
нечетните редове (1, 3, 5, …) се сортират в намаляващ ред*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 20;
void sort(int arr[], int n, bool asc)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((asc && arr[i] > arr[j]) || (!asc && arr[i] < arr[j]))
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int rows, cols;
	int matrix[MAX_SIZE][MAX_SIZE];

	cout << "Enter rows and columns: ";
	cin >> rows >> cols;
	
	cout << "Enter matrix elements:\n";
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> matrix[i][j];

	for (int i = 0; i < rows; i++)
	{
		if (i % 2 == 0)
			sort(matrix[i], cols, true);
		else
			sort(matrix[i], cols, false);
	}
	
	cout << "\nResult matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
	}
}
