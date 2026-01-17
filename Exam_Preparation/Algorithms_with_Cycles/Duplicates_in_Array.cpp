//Имаме едномерен масив A[10] с 
// цели числа .
// Напишете алгоритъм за намиране на 
// всички дубликати в масива и 
// броя на всяко дублирано число.

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

int main()
{
	int n;
	cout << "Enter how many numbers you want to write between 1 and " << MAX_SIZE << endl;
	cin >> n;

	int A[MAX_SIZE];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]: ";
		cin >> A[i];
	}
	bool visited[MAX_SIZE] = { false };
	cout << "Duplicates and their count: " << endl;

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		int count_dublicates = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] == A[j])
			{
				count_dublicates++;
				visited[j] = true;
			}
		}
		if (count_dublicates > 1)
		{
			cout << A[i] << " -> " << count_dublicates << " times" << endl;
		}
	}
	return 0;
}
