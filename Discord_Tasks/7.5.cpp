// Да се състави алгоритъм за намиране 
// броя на нулевите елементи 
// в масива u1, u2, ..., um.

#include <iostream>
using namespace std;

int main()
{
	int m;
	cout << "Enter the number of elements: ";
	cin >> m;

	int arr[1000];
	cout << "Enter the elements: ";
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}

	int zero_count = 0;
	for (int i = 0; i < m; i++)
	{
		if (arr[i] == 0)
		{
			zero_count++;
		}
	}
	cout << "Number of zeros in the array: " << zero_count << endl;
	return 0;
}
