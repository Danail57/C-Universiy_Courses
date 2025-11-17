// Да се състави алгоритъм за намиране
// средно - аритметичната стойност
// на положителните елементи

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

	int sum = 0;
	int positive_count = 0;

	for (int i = 0; i < m; i++)
	{
		if (arr[i] > 0)
		{
			sum += arr[i];
			positive_count++;
		}
	}

	if (positive_count > 0)
	{
		double average = double(sum) / positive_count;
		cout << "Average of positive elements: " << average << endl;
	}
	else 
	{
		cout << "There are no positive elements in the array." << endl;
	}

	return 0;

}
