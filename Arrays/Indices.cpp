/*В едномерен масив да се въведат 
стойности, естествени числа.
Да се създаде и изведе масив, съдържащ 
индексите на елементите на първия масив, 
които се делят на 3 и 5 без остатък.*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "How many numbers you want? ";
	cin >> n;

	int A[1200];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i + 1 << "] = ";
		cin >> A[i];
	}

	int arr_indices[1200];
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (A[i] % 3 == 0 && A[i] % 5 == 0)
		{
			arr_indices[count] = i + 1;
			count++;
		}
	}
	for (int i = 0; i < count;i++)
	{
		cout << arr_indices[i] << " ";
	}
	return 0;
}
