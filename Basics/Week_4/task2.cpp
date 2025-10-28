#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter how many elements you want to type: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements: \n";

	for (int i = 0; i < n; i++)
	{
		cout << "Element " << i + 1 << ": ";
		cin >> arr[i];
	}

	int max_value = arr[0];
	int max_index = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max_value)
		{
			max_value = arr[i];
			max_index = i;
		}
	}

	cout << "\n The biggest element is: " << max_value << endl;
	cout << "It is on index position: " << max_index << endl;
}

