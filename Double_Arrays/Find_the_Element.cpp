#include <iostream>
using namespace std;


int main()
{
	int n;
	cout << "Enter how many numbers you want to type: ";
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int searched_value;
	cout << "Enter the value to search: ";
	cin >> searched_value;
	int found_index = -1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == searched_value)
		{
			found_index = i;
			break;
		}
	}
	if (found_index != -1)
		cout << "The first element equal to " << searched_value << " is at index " << found_index << endl;
	else
		cout << "Element not found" << endl;
	delete[] a;
	return 0;
}
